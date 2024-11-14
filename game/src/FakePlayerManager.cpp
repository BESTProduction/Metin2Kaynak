#include "stdafx.h"
#ifdef __FAKE_PLAYER__
#include "FakePlayerManager.h"
#include "guild_manager.h"
#include "packet.h"
#include "guild.h"
#include "locale_service.h"
#include "char.h"
#include "char_manager.h"
#include "sectree.h"
#include "sectree_manager.h"
#include "item.h"
#include "item_manager.h"
#include "desc.h"
#include "desc_manager.h"
#include "desc_client.h"
#include "buffer_manager.h"
#include "vector.h"
#include "motion.h"
#include "entity.h"
#include "typedef.h"
#include "event.h"
#include "../../common/singleton.h"
#include "../../common/length.h"
#include <boost/lexical_cast.hpp>
#include <nlohmann/json.hpp>
using json = nlohmann::json;
#include <fstream>
#include <cstdlib>
#include <boost/algorithm/string.hpp>


// Singleton template implementation
template<> CFakePlayerManager* singleton<CFakePlayerManager>::ms_singleton = nullptr;

// Constructor
CFakePlayerManager::CFakePlayerManager()
    : m_pkUpdateEvent(nullptr)
    , m_dwLastSummonTime(0)
    , m_pkMovementEvent(nullptr)
    , m_nextGuildID(1000)
{
    m_fakeGuilds.resize(3);
}

CFakePlayerManager::~CFakePlayerManager()
{
    StopUpdateSystem();
}

bool IsEnemyEmpire(BYTE fakePlayerEmpire, BYTE targetEmpire) {
    return fakePlayerEmpire != targetEmpire && targetEmpire >= 1 && targetEmpire <= 3;
}

// Regular update event
EVENTFUNC(fake_player_update_event)
{
    FAKE_PLAYER_EVENT_INFO* info = dynamic_cast<FAKE_PLAYER_EVENT_INFO*>(event->info);
    if (!info)
        return 0;

    CFakePlayerManager::instance().UpdateFakePlayers();
    return PASSES_PER_SEC(1);
}

// Movement event
EVENTFUNC(fake_player_move_event)
{
    char_event_info* info = dynamic_cast<char_event_info*>(event->info);
    if (!info)
    {
        sys_err("fake_player_move_event> Null pointer");
        return 0;
    }

    CFakePlayerManager::Instance().MoveAllFakePlayers();
    return PASSES_PER_SEC(1);
}

// Revive event
EVENTFUNC(fake_player_revive_event)
{
    char_event_info* info = dynamic_cast<char_event_info*>(event->info);
    if (!info)
    {
        sys_err("fake_player_revive_event> Null pointer");
        return 0;
    }

    LPCHARACTER ch = info->ch;
    if (!ch)
        return 0;

    ch->SetPosition(POS_STANDING);
    ch->Show(ch->GetMapIndex(), ch->GetX(), ch->GetY(), 0);
    ch->PointChange(POINT_HP, ch->GetMaxHP() - ch->GetHP());
    ch->StartRecoveryEvent();

    return 0;
}

// CFakePlayer class implementation
CFakePlayer::CFakePlayer(TFakePlayerLoginData* fakePlayerLoginData)
{
    if (!fakePlayerLoginData)
    {
        sys_err("CFakePlayer: fakePlayerLoginData is NULL");
        return;
    }

    m_dwLastMotionTime = 0;

    Login(fakePlayerLoginData);
}

CFakePlayer::~CFakePlayer()
{
    if (m_pFakePlayer)
        M2_DESTROY_CHARACTER(m_pFakePlayer);
}

// Custom namelist for each costume type
const std::map<int, std::vector<int>> CFakePlayerManager::costume_namelist = {
    { COSTUME_ACCE, {85004, 85008, 85014, 85018, 85024, 86004, 86008, 86014, 86018, 86024} },
    { COSTUME_AURA, {49001, 49002, 49003, 49004, 49005, 49006} },
    { COSTUME_MOUNT, {71220, 71222, 71223, 71224, 71225, 71226, 71227, 71228, 71229, 71230} }
};

// CFakePlayer::Login fonksiyonunda değişiklikler
void CFakePlayer::Login(TFakePlayerLoginData* fakePlayerLoginData)
{
    // Login implementation
    long lMapIndex = fakePlayerLoginData->lMapIndex;
    long lX = fakePlayerLoginData->lX;
    long lY = fakePlayerLoginData->lY;

    LPSECTREE sectree = SECTREE_MANAGER::instance().Get(lMapIndex, lX, lY);
    if (!sectree)
    {
        CFakePlayerManager::Instance().FakePlayerLogout(fakePlayerLoginData->szName);
        return;
    }

    LPCHARACTER pFakePlayer = CHARACTER_MANAGER::instance().CreateCharacter("Fake");
    if (!pFakePlayer)
    {
        CFakePlayerManager::Instance().FakePlayerLogout(fakePlayerLoginData->szName);
        return;
    }

    m_pFakePlayer = pFakePlayer;
    m_pFakePlayer->SetFakePlayer(true);

    // Basic setup
    m_pFakePlayer->SetRotation(fakePlayerLoginData->iRotation);
    m_pFakePlayer->SetXYZ(lX, lY, 0);
    m_pFakePlayer->SetMapIndex(lMapIndex);
    m_pFakePlayer->SetName(fakePlayerLoginData->szName);

    if (!LoadFakePlayer())
    {
        sys_err("Cannot load fake player %s", fakePlayerLoginData->szName);
        CFakePlayerManager::Instance().FakePlayerLogout(fakePlayerLoginData->szName);
        return;
    }

    // Additional setup
    m_pFakePlayer->SetCharType(CHAR_TYPE_PC);
    m_pFakePlayer->SetPKMode(PK_MODE_PEACE);

    if (!m_pFakePlayer->Show(lMapIndex, lX, lY, 0))
    {
        CFakePlayerManager::Instance().FakePlayerLogout(fakePlayerLoginData->szName);
        return;
    }

    ApplyEfsunBonuses();
}

bool CFakePlayer::IsBlocked(long destX, long destY) const
{
    LPSECTREE_MAP pSecMap = SECTREE_MANAGER::instance().GetMap(m_pFakePlayer->GetMapIndex());
    if (!pSecMap)
        return true;

    int iCurrentX = m_pFakePlayer->GetX();
    int iCurrentY = m_pFakePlayer->GetY();

    // Her 50 birimde bir kontrol için nokta hesapla
    float fDist = DISTANCE_SQRT(destX - iCurrentX, destY - iCurrentY);
    int iSteps = static_cast<int>(fDist / 50.0f);

    if (iSteps > 0)
    {
        for (int i = 1; i <= iSteps; ++i)
        {
            float fRatio = static_cast<float>(i) / iSteps;
            long checkX = iCurrentX + static_cast<long>((destX - iCurrentX) * fRatio);
            long checkY = iCurrentY + static_cast<long>((destY - iCurrentY) * fRatio);

            LPSECTREE tree = pSecMap->Find(checkX, checkY);
            if (!tree)
                return true;

            if (tree->IsAttr(checkX, checkY, ATTR_BLOCK))
                return true;

            if (tree->IsAttr(checkX, checkY, ATTR_WATER))
                return true;

            if (tree->IsAttr(checkX, checkY, ATTR_BANPK))
                return true;

            if (tree->IsAttr(checkX, checkY, ATTR_OBJECT))
                return true;
        }
    }

    return false;
}

void CFakePlayer::Move()
{
    if (!m_pFakePlayer)
        return;

    // Karakter ölü mü kontrol et
    if (m_pFakePlayer->IsDead())
    {
        if (!m_bIsDead)
        {
            m_dwDeadTime = get_dword_time();
            m_bIsDead = true;
            sys_log(0, "FakePlayer %s died. Will respawn in 10 seconds.", m_pFakePlayer->GetName());
        }

        if (m_bIsDead && get_dword_time() - m_dwDeadTime >= 10000)
        {
            ReviveCharacter();
            return;
        }
        return;
    }

    // Hareket zamanı kontrolü
    if (get_dword_time() - m_dwLastMoveTime < 3000)
        return;

    // Zaten hareket halindeyse kontrol et
    if (m_pFakePlayer->IsStateMove())
        return;

    int iCurrentX = m_pFakePlayer->GetX();
    int iCurrentY = m_pFakePlayer->GetY();

    // Yeni hedef arama
    bool bFoundValidPos = false;
    int iTryCount = 0;
    const int MAX_TRY = 20;

    while (!bFoundValidPos && iTryCount < MAX_TRY)
    {
        iTryCount++;

        // Rastgele hedef seç
        m_iDestX = number(iCurrentX - 1000, iCurrentX + 1000);
        m_iDestY = number(iCurrentY - 1000, iCurrentY + 1000);

        // Pozisyon kontrolü
        if (!IsBlocked(m_iDestX, m_iDestY))
        {
            float fDist = DISTANCE_SQRT(m_iDestX - iCurrentX, m_iDestY - iCurrentY);
            if (fDist <= 1000.0f)
            {
                bFoundValidPos = true;
                break;
            }
        }
    }

    if (!bFoundValidPos)
    {
        sys_log(1, "FakePlayer %s couldn't find valid position after %d tries",
                m_pFakePlayer->GetName(), MAX_TRY);
        return;
    }

    // Rotasyon ayarla
    float fDegree = GetDegreeFromPositionXY(iCurrentX, iCurrentY, m_iDestX, m_iDestY);
    m_pFakePlayer->SetRotation(static_cast<int>(fDegree));

    // Hareket et
    if (m_pFakePlayer->Goto(m_iDestX, m_iDestY))
    {
        m_dwLastMoveTime = get_dword_time();
        m_pFakePlayer->SendMovePacket(FUNC_WAIT, 0, m_iDestX, m_iDestY, 0,
                                     get_dword_time(), m_pFakePlayer->GetRotation());
    }
}

void CFakePlayer::StopMoving()
{
    if (m_pFakePlayer)
    {
        // Botun durmasını sağlayacak pozisyon ve durum güncellemesi
        m_pFakePlayer->UpdatePacket();
    }
}

void CFakePlayer::ReviveCharacter()
{
    if (!m_pFakePlayer)
        return;

    m_bIsDead = false;
    m_pFakePlayer->SetPosition(POS_STANDING);
    m_pFakePlayer->Show(m_pFakePlayer->GetMapIndex(), m_pFakePlayer->GetX(), m_pFakePlayer->GetY(), 0);
    m_pFakePlayer->PointChange(POINT_HP, m_pFakePlayer->GetMaxHP() - m_pFakePlayer->GetHP());
    m_pFakePlayer->StartRecoveryEvent();
}

bool CFakePlayer::LoadFakePlayer()
{
    if (!m_pFakePlayer)
    {
        sys_err("LoadFakePlayer: m_pFakePlayer is NULL");
        return false;
    }

    // JSON dosyasından bot verisini okuma işlemi
    char file_name[256 + 1];
    snprintf(file_name, sizeof(file_name), "%s/json/fake_players.json", LocaleService_GetBasePath().c_str());
    std::ifstream ifs(file_name);
    if (!ifs.is_open())
    {
        sys_err("Unable to open fake_players.json");
        return false;
    }

    try
    {
        json jf = json::parse(ifs);
        if (!jf.contains("fake_players") || jf["fake_players"].empty())
        {
            sys_err("Invalid JSON format: missing or empty fake_players array");
            return false;
        }

        // Rastgele bir şablon seç
        const auto& templates = jf["fake_players"];
        size_t randomIndex = rand() % templates.size();
        const json& row = templates[randomIndex];

        // Empire ve Guild ayarlamaları
        if (row.contains("empire"))
        {
            BYTE byEmpire = row["empire"].get<BYTE>();
            sys_log(0, "FakePlayer %s - Empire: %d", m_pFakePlayer->GetName(), byEmpire);

            if (byEmpire >= 1 && byEmpire <= 3)
            {
                m_pFakePlayer->SetEmpire(byEmpire);

                // Sahte lonca ata
                const auto* fakeGuild = CFakePlayerManager::Instance().GetRandomFakeGuild(byEmpire);
                if (fakeGuild)
                {
                    // Sahte lonca nesnesini alalım
                    CGuild* pGuild = CGuildManager::instance().TouchGuild(fakeGuild->id); // Lonca var ise alır, yoksa oluşturur
                    if (pGuild)
                    {
                        m_pFakePlayer->SetGuild(pGuild);  // Lonca ataması

                        // Guild bilgilerinin güncellenmesi
                        m_pFakePlayer->SendGuildName(pGuild);
                        m_pFakePlayer->UpdatePacket();

                        sys_log(0, "Assigned fake guild to player %s: %s (ID: %d)",
                            m_pFakePlayer->GetName(), fakeGuild->name.c_str(), fakeGuild->id);
                    }
                    else
                    {
                        sys_err("Failed to assign guild. Guild ID %d could not be loaded.", fakeGuild->id);
                    }
                }
                else
                {
                    sys_err("No fake guild found for empire %d.", byEmpire);
                }
            }
            else
            {
                sys_err("Invalid empire value: %d (must be between 1-3)", byEmpire);
            }
        }
        else
        {
            sys_err("No empire information available in JSON for FakePlayer %s.", m_pFakePlayer->GetName());
        }

        // Kostüm atamaları
        int randomAcce = CFakePlayerManager::Instance().GetRandomCostumeItem(COSTUME_ACCE);
        if (randomAcce) {
            m_pFakePlayer->SetPart(PART_ACCE, randomAcce);
        }

        int randomAura = CFakePlayerManager::Instance().GetRandomCostumeItem(COSTUME_AURA);
        if (randomAura) {
            m_pFakePlayer->SetPart(PART_AURA, randomAura);
        }

        int randomMount = CFakePlayerManager::Instance().GetRandomCostumeItem(COSTUME_MOUNT);
        if (randomMount) {
            m_pFakePlayer->SetPart(COSTUME_MOUNT, randomMount);
        }

        // Temel özellikleri ayarla
        BYTE byRace = row["race"].get<BYTE>();
        BYTE bySex = row["sex"].get<BYTE>();

        switch (byRace)
        {
            case JOB_WARRIOR:
                byRace = (bySex == SEX_MALE) ? MAIN_RACE_WARRIOR_M : MAIN_RACE_WARRIOR_W;
                break;
            case JOB_ASSASSIN:
                byRace = (bySex == SEX_MALE) ? MAIN_RACE_ASSASSIN_M : MAIN_RACE_ASSASSIN_W;
                break;
            case JOB_SURA:
                byRace = (bySex == SEX_MALE) ? MAIN_RACE_SURA_M : MAIN_RACE_SURA_W;
                break;
            case JOB_SHAMAN:
                byRace = (bySex == SEX_MALE) ? MAIN_RACE_SHAMAN_M : MAIN_RACE_SHAMAN_W;
                break;
#ifdef ENABLE_WOLFMAN_CHARACTER
            case JOB_WOLFMAN:
                byRace = MAIN_RACE_WOLFMAN_M;
                break;
#endif
        }

        m_pFakePlayer->SetRace(byRace);
        m_pFakePlayer->SetLevel(row["level"].get<BYTE>());

        // Saç kontrolü
        if (row.contains("hair") && row["hair"].is_number())
        {
            BYTE byHair = row["hair"].get<BYTE>();
            SetHair(byHair);
        }

        // Statları ayarla
        m_pFakePlayer->SetPoint(POINT_ST, row["st"].get<int>());
        m_pFakePlayer->SetPoint(POINT_HT, row["ht"].get<int>());
        m_pFakePlayer->SetPoint(POINT_DX, row["dx"].get<int>());
        m_pFakePlayer->SetPoint(POINT_IQ, row["iq"].get<int>());

        // Rastgele bir alignment değeri belirle (-200,000 ile 200,000 arasında)
        int randomAlignment = rand() % 400001 - 200000;
        m_pFakePlayer->UpdateAlignment(randomAlignment);

        // Ekipmanları ayarla
        if (row.contains("item_weapon") && row["item_weapon"].get<DWORD>() > 0)
            m_pFakePlayer->SetPart(PART_WEAPON, row["item_weapon"].get<DWORD>());

        if (row.contains("item_armor") && row["item_armor"].get<DWORD>() > 0)
            m_pFakePlayer->SetPart(PART_MAIN, row["item_armor"].get<DWORD>());

        if (row.contains("item_hair") && row["item_hair"].get<DWORD>() > 0)
            m_pFakePlayer->SetPart(PART_HAIR, row["item_hair"].get<DWORD>());

        // Blok bilgileri
        m_pFakePlayer->SetFakePlayerBlockEQ(row["block_eq"].get<DWORD>());

        // Hareket ve HP ayarla
        m_pFakePlayer->SetPoint(POINT_MOV_SPEED, EFakePlayer::FAKE_PLAYER_MOV_SPEED);
        m_pFakePlayer->ComputePoints();
        m_pFakePlayer->PointChange(POINT_HP, m_pFakePlayer->GetMaxHP() - m_pFakePlayer->GetHP());
        m_pFakePlayer->StartRecoveryEvent();

        // Pet sistemi
        m_pFakePlayer->FakePlayerCreatePetSystem();

        return true;
    }
    catch (json::parse_error& e)
    {
        sys_err("CFakePlayer -> JSON parse error: %s", e.what());
        return false;
    }
    catch (const std::exception& e)
    {
        sys_err("Unexpected error in LoadFakePlayer: %s", e.what());
        return false;
    }
}

void CFakePlayerManager::DestroyFakePlayer(TFakePlayerLogoutData* fakePlayerLogoutData)
{
    if (!fakePlayerLogoutData)
    {
        sys_err("DestroyFakePlayer: Invalid data");
        return;
    }

    const auto it = m_mapFakePlayer.find(fakePlayerLogoutData->szName);
    if (it == m_mapFakePlayer.end())
    {
        sys_err("DestroyFakePlayer: Player %s not found", fakePlayerLogoutData->szName);
        return;
    }

    m_mapFakePlayer.erase(it);
}

CFakePlayer* CFakePlayerManager::FindFakePlayer(const std::string& stName)
{
    const auto it = m_mapFakePlayer.find(stName);
    if (it == m_mapFakePlayer.end())
        return nullptr;

    return it->second.get();
}

void CFakePlayerManager::StartUpdateSystem()
{
    if (m_pkUpdateEvent)
        return;

    FAKE_PLAYER_EVENT_INFO* info = AllocEventInfo<FAKE_PLAYER_EVENT_INFO>();
    info->dwLastUpdateTime = get_dword_time();
    m_pkUpdateEvent = event_create(fake_player_update_event, (event_info_data*)info, PASSES_PER_SEC(1));
}

void CFakePlayerManager::StopUpdateSystem()
{
    if (m_pkUpdateEvent)
    {
        event_cancel(&m_pkUpdateEvent);
        m_pkUpdateEvent = nullptr;
    }
}
void CFakePlayer::UpdateCombat()
{
    if (!m_pFakePlayer || m_pFakePlayer->IsDead())
        return;

    DWORD currentTime = get_dword_time();

    // Her 2 saniyede bir hedef ara
    if (currentTime - m_dwLastAttackTime > 2000)
    {
        SearchTarget();
        m_dwLastAttackTime = currentTime;
    }

    // Eğer savaşta isek
    if (m_bInCombat && m_iCurrentTarget)
    {
        ProcessCombat();
    }
}

void CFakePlayer::SearchTarget()
{
    if (!m_pFakePlayer)
        return;

    // Mevcut konumu al
    const int searchRange = 300; // 300 birim içindeki hedefleri ara
    LPCHARACTER pTarget = nullptr;
    float closestDistance = searchRange;

    // Çevredeki karakterleri tara
    LPSECTREE_MAP pSecMap = SECTREE_MANAGER::instance().GetMap(m_pFakePlayer->GetMapIndex());
    if (!pSecMap)
        return;

    const int currentX = m_pFakePlayer->GetX();
    const int currentY = m_pFakePlayer->GetY();

    // Çevredeki karakterleri bul
    LPSECTREE tree = pSecMap->Find(currentX, currentY);
    if (!tree)
        return;

    // Sektör içindeki karakterleri kontrol et
    FCollectEntity collector;
    tree->ForEachAround(collector);

    for (auto entity : collector.m_vecEntity)
    {
        if (!entity->IsType(ENTITY_CHARACTER))
            continue;

        LPCHARACTER ch = (LPCHARACTER)entity;
        if (!IsValidTarget(ch))
            continue;

        float distance = DISTANCE_SQRT(currentX - ch->GetX(), currentY - ch->GetY());
        if (distance <= searchRange && distance < closestDistance)
        {
            closestDistance = distance;
            pTarget = ch;
        }
    }

    if (pTarget)
    {
        m_iCurrentTarget = pTarget->GetVID();
        m_bInCombat = true;
        sys_log(0, "FakePlayer %s found target: %s", m_pFakePlayer->GetName(), pTarget->GetName());
    }
}

bool CFakePlayer::IsValidTarget(LPCHARACTER target) const
{
    if (!target || !m_pFakePlayer)
        return false;

    // Hedef geçerlilik kontrolleri
    return target->IsPC() && // Gerçek oyuncu mu?
           !target->IsDead() && // Ölü değil mi?
           target->GetVID() != m_pFakePlayer->GetVID() && // Kendisi değil mi?
           IsEnemyEmpire(m_pFakePlayer->GetEmpire(), target->GetEmpire()) && // Düşman krallık mı?
           target->GetPKMode() == PK_MODE_FREE; // PK modu açık mı?
}

void CFakePlayer::ProcessCombat()
{
    if (!m_pFakePlayer)
        return;

    LPCHARACTER target = CHARACTER_MANAGER::instance().Find(m_iCurrentTarget);
    if (!target || !IsValidTarget(target))
    {
        m_bInCombat = false;
        m_iCurrentTarget = 0;
        return;
    }

    DWORD currentTime = get_dword_time();

    // Hedef menzilde mi kontrol et
    if (!IsInAttackRange(target))
    {
        // Hedefe doğru hareket et
        m_pFakePlayer->SetRotation(GetDegreeFromPositionXY(m_pFakePlayer->GetX(), m_pFakePlayer->GetY(),
                                                          target->GetX(), target->GetY()));
        m_pFakePlayer->Goto(target->GetX(), target->GetY());
        return;
    }

    // Skill kullanma zamanı geldiyse
    if (currentTime - m_dwLastSkillTime > 8000) // 8 saniyede bir skill
    {
        UseSkill(target);
        m_dwLastSkillTime = currentTime;
        return;
    }

    // Normal saldırı zamanı geldiyse
    if (currentTime - m_dwLastAttackTime > 1000) // 1 saniyede bir saldırı
    {
        PerformAttack(target);
        m_dwLastAttackTime = currentTime;
    }
}

void CFakePlayer::PerformAttack(LPCHARACTER target)
{
    if (!m_pFakePlayer || !target)
        return;

    // Hedefe dön
    m_pFakePlayer->SetRotation(GetDegreeFromPositionXY(m_pFakePlayer->GetX(), m_pFakePlayer->GetY(),
                                                      target->GetX(), target->GetY()));

    // Saldırı animasyonu
    m_pFakePlayer->Motion(MOTION_WALK);

    // Hasar hesapla
    int iDam = number(m_pFakePlayer->GetPoint(POINT_MAX_HP), m_pFakePlayer->GetPoint(POINT_MAX_SP));
    
    // Kritik vuruş şansı
    if (number(1, 100) <= m_pFakePlayer->GetPoint(POINT_CRITICAL_PCT))
        iDam *= 2;

    // Hasarı uygula
    target->Damage(m_pFakePlayer, iDam);
}

void CFakePlayer::UseSkill(LPCHARACTER target)
{
    if (!m_pFakePlayer || !target)
        return;

    // Karakterin sınıfına göre rastgele bir skill seç
    BYTE job = m_pFakePlayer->GetJob();
    DWORD skillVnum = 0;

    switch (job)
    {
        case JOB_WARRIOR:
        {
            // Savaşçı becerileri
            int skillChoice = number(1, 3);
            switch(skillChoice) {
                case 1: skillVnum = SKILL_FINISH; break;      // Bitiriş Vuruşu
                case 2: skillVnum = SKILL_PALBANG; break;     // Pala Savurma
                case 3: skillVnum = SKILL_SWAERYUNG; break;   // Ejderha Döndürme
            }
            break;
        }
        case JOB_ASSASSIN:
        {
            // Ninja becerileri
            int skillChoice = number(1, 3);
            switch(skillChoice) {
                case 1: skillVnum = SKILL_AMSEOP; break;      // Karanlık Vuruş
                case 2: skillVnum = SKILL_ILGWANGPYO; break;  // Gölge Darbesi
                case 3: skillVnum = SKILL_PUNGLOEPO; break;   // Rüzgar Vuruşu
            }
            break;
        }
        case JOB_SURA:
        {
            // Sura becerileri
            int skillChoice = number(1, 3);
            switch(skillChoice) {
                case 1: skillVnum = SKILL_YONGBI; break;      // Ejderha Ruhu
                case 2: skillVnum = SKILL_GIGONGCHAM; break;  // Kılıç Ruhu
                case 3: skillVnum = SKILL_GEOMAGGWI; break;   // Şeytan Kılıcı
            }
            break;
        }
        case JOB_SHAMAN:
        {
            // Şaman becerileri
            int skillChoice = number(1, 3);
            switch(skillChoice) {
                case 1: skillVnum = SKILL_MARYUNG; break;     // Ateş Topu
                case 2: skillVnum = SKILL_BYEURAK; break;     // Yıldırım Çarpması
                case 3: skillVnum = SKILL_METEO; break;       // Meteor Yağmuru
            }
            break;
        }
#ifdef ENABLE_WOLFMAN_CHARACTER
        case JOB_WOLFMAN:
        {
            // Kurt Adam becerileri
            int skillChoice = number(1, 2);
            switch(skillChoice) {
                case 1: skillVnum = SKILL_SALPOONG; break;    // Öldürücü Rüzgar
                case 2: skillVnum = SKILL_ILIPUNGU; break;    // Kurtların Saldırısı
            }
            break;
        }
#endif
    }

    if (skillVnum)
    {
        // Skill kullanımı öncesi hedefe dön
        m_pFakePlayer->SetRotation(GetDegreeFromPositionXY(m_pFakePlayer->GetX(), m_pFakePlayer->GetY(),
                                                          target->GetX(), target->GetY()));
                                                          
        // Skill animasyonu ve efektleri
        m_pFakePlayer->Motion(MOTION_MODE_GENERAL);
        
        // Skill'i kullan
        m_pFakePlayer->ComputeSkill(skillVnum, target);
        
        sys_log(0, "FakePlayer %s used skill %u on target %s", 
                m_pFakePlayer->GetName(), skillVnum, target->GetName());
    }
}

bool CFakePlayer::IsInAttackRange(LPCHARACTER target) const
{
    if (!m_pFakePlayer || !target)
        return false;

    // Menzil kontrolü
    float distance = DISTANCE_SQRT(m_pFakePlayer->GetX() - target->GetX(),
                                 m_pFakePlayer->GetY() - target->GetY());
    
    return distance <= m_fAttackRange;
}

void CFakePlayerManager::UpdateFakePlayers()
{
    DWORD dwCurrentTime = get_dword_time();

    for (auto& pair : m_mapFakePlayer)
    {
        if (pair.second && pair.second->GetFakePlayer())
        {
            pair.second->UpdateCombat();
        }
    }
}

void CFakePlayerManager::Destroy()
{
    StopMovementSystem();
    m_mapFakePlayer.clear();
}

void CFakePlayerManager::StartMovementSystem()
{
    if (m_pkMovementEvent)
        return;

    char_event_info* info = AllocEventInfo<char_event_info>();
    info->ch = nullptr;
    m_pkMovementEvent = event_create(fake_player_move_event, info, PASSES_PER_SEC(1));
}

void CFakePlayerManager::StopMovementSystem()
{
    if (m_pkMovementEvent)
    {
        event_cancel(&m_pkMovementEvent);
        m_pkMovementEvent = nullptr;
    }
}

void CFakePlayerManager::MoveAllFakePlayers()
{
    DWORD dwCurTime = get_dword_time();

    for (auto& pair : m_mapFakePlayer)
    {
        if (!pair.second || !pair.second->GetFakePlayer())
            continue;

        sys_log(0, "Attempting to move fake player: %s", pair.second->GetFakePlayer()->GetName());

        // Ölü botları hareket ettirme ama fonksiyonu çalıştır
        pair.second->Move();
    }
}

void CFakePlayer::InitializeAppearance()
{
    if (!m_pFakePlayer)
        return;

    m_byHair = 0;
    m_byEmpire = 0;
}

void CFakePlayer::SetHair(BYTE byHair)
{
    if (!m_pFakePlayer)
        return;

    m_byHair = byHair;
    m_pFakePlayer->SetPart(PART_HAIR, byHair);
    m_pFakePlayer->UpdatePacket();
}

void CFakePlayer::SetEmpireFlag(BYTE byEmpire)
{
    if (!m_pFakePlayer || byEmpire > 3)
        return;

    m_byEmpire = byEmpire;
    m_pFakePlayer->SetEmpire(byEmpire);
    m_pFakePlayer->UpdatePacket();
}

bool CFakePlayerManager::LoadNameList()
{
    char namelist_path[256];
    snprintf(namelist_path, sizeof(namelist_path), "%s/json/namelist.txt",
             LocaleService_GetBasePath().c_str());

    // Debug için yolu yazdır
    sys_log(0, "Trying to load namelist from: %s", namelist_path);

    std::ifstream file(namelist_path);
    if (!file.is_open())
    {
        sys_err("Cannot open namelist.txt at path: %s", namelist_path);
        return false;
    }

    m_vecNameList.clear();
    std::string line;

    while (std::getline(file, line))
    {
        if (line.empty() || line[0] == '#')
            continue;

        line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());

        if (!line.empty())
            m_vecNameList.push_back(line);
    }

    sys_log(0, "Loaded %zu names from namelist.txt", m_vecNameList.size());
    return !m_vecNameList.empty();
}

std::string CFakePlayerManager::GetRandomName()
{
    if (m_vecNameList.empty())
    {
        LoadNameList();  // İsimler bittiyse yeniden yükle

        if (m_vecNameList.empty())
        {
            sys_err("Name list is empty!");
            return "";
        }
    }

    size_t index = rand() % m_vecNameList.size();
    std::string name = m_vecNameList[index];
    m_vecNameList.erase(m_vecNameList.begin() + index);

    return name;
}

void CFakePlayerManager::AddNameBackToList(const std::string& name)
{
    // İsmi tekrar kullanılabilir hale getir
    if (std::find(m_vecNameList.begin(), m_vecNameList.end(), name) == m_vecNameList.end())
        m_vecNameList.push_back(name);
}

void CFakePlayerManager::RemoveUsedName(const std::string& name)
{
    auto it = std::find(m_vecNameList.begin(), m_vecNameList.end(), name);
    if (it != m_vecNameList.end())
        m_vecNameList.erase(it);
}

void CFakePlayerManager::GetActiveFakePlayerNames(std::vector<std::string>& nameList)
{
    nameList.clear();
    for (const auto& pair : m_mapFakePlayer)
    {
        if (pair.second && pair.second->GetFakePlayer())
        {
            nameList.push_back(pair.first);
        }
    }
}

void CFakePlayerManager::FakePlayerLogout(const char* szName, LPCHARACTER ch)
{
    if (!szName)
    {
        sys_err("FakePlayerLogout: Invalid name");
        return;
    }

    if (!FindFakePlayer(szName))
    {
        if (ch)
            ch->ChatPacket(CHAT_TYPE_INFO, "Fake player %s doesn't exist.", szName);
        return;
    }

    // İsmi listeye geri ekle
    AddNameBackToList(szName);

    TFakePlayerLogoutData logoutData;
    strlcpy(logoutData.szName, szName, sizeof(logoutData.szName));

    DestroyFakePlayer(&logoutData);

    if (ch)
        ch->ChatPacket(CHAT_TYPE_INFO, "Fake player %s has been removed.", szName);
}

// fullon ve fulloff komutlarını da güncelleyelim
// Initialize fonksiyonunda çağıralım

void CFakePlayerManager::FakePlayerLogin(LPCHARACTER ch, const TFakePlayerLoginData* fakePlayerLoginData)
{
    if (!ch || !fakePlayerLoginData)
    {
        sys_err("FakePlayerLogin: Invalid arguments (ch: %p, data: %p)", ch, fakePlayerLoginData);
        return;
    }

    // Rastgele bir isim al
    std::string randomName = GetRandomName();
    if (randomName.empty())
    {
        ch->ChatPacket(CHAT_TYPE_INFO, "No available names in the name list.");
        return;
    }

    // İsmi TFakePlayerLoginData yapısına kopyala
    TFakePlayerLoginData tempData = *fakePlayerLoginData;  // Yeni geçici yapı
    strncpy(tempData.szName, randomName.c_str(), sizeof(tempData.szName) - 1);
    tempData.szName[sizeof(tempData.szName) - 1] = '\0';

    // Bot oluşturma işlemi
    SpawnFakePlayer(&tempData);
    ch->ChatPacket(CHAT_TYPE_INFO, "Fake player %s spawned.", tempData.szName);

    // Efsun bonuslarını aktive et
    if (CFakePlayer* fakePlayer = FindFakePlayer(tempData.szName))
    {
        fakePlayer->ApplyEfsunBonuses();
    }
}

bool CFakePlayerManager::SpawnFakePlayer(const TFakePlayerLoginData* fakePlayerLoginData)
{
    if (!fakePlayerLoginData)
    {
        sys_err("SpawnFakePlayer: Invalid data");
        return false;
    }

    try
    {
        auto pFakePlayer = std::make_unique<CFakePlayer>(const_cast<TFakePlayerLoginData*>(fakePlayerLoginData));
        m_mapFakePlayer.insert(TFakePlayerMap::value_type(fakePlayerLoginData->szName, std::move(pFakePlayer)));
        return true;
    }
    catch (const std::exception& e)
    {
        sys_err("Failed to spawn fake player: %s", e.what());
        return false;
    }
}

bool CFakePlayerManager::LoadGuildConfigurations()
{
    char file_path[256];
    snprintf(file_path, sizeof(file_path), "%s/json/fake_guild.json", LocaleService_GetBasePath().c_str());

    std::ifstream ifs(file_path);
    if (!ifs.is_open())
    {
        sys_err("Unable to open fake_guild.json at path: %s", file_path);
        return false;
    }

    try
    {
        // Dosya içeriğini okuyun
        std::stringstream buffer;
        buffer << ifs.rdbuf();
        std::string content = buffer.str();

        // Debug için içeriği yazdır
        sys_log(0, "JSON Content: %s", content.c_str());

        // JSON'ı parse et
        json jf = json::parse(content);

        // JSON yapısını kontrol et
        if (!jf.is_object())
        {
            sys_err("JSON root is not an object");
            return false;
        }

        // "fake_guild" anahtarını kontrol et
        if (!jf.contains("fake_guild"))
        {
            sys_err("JSON does not contain 'fake_guild' key");
            return false;
        }

        json fake_guild = jf["fake_guild"];

        // Üç krallık listelerinin olup olmadığını kontrol et
        const std::vector<std::string> guild_lists = {"a_fake_guild_list", "b_fake_guild_list", "c_fake_guild_list"};
        for (const auto& guild_list_key : guild_lists)
        {
            if (!fake_guild.contains(guild_list_key))
            {
                sys_err("JSON does not contain '%s' key", guild_list_key.c_str());
                return false;
            }

            if (!fake_guild[guild_list_key].is_object())
            {
                sys_err("'%s' is not an object", guild_list_key.c_str());
                return false;
            }

            // Guild listesindeki her bir öğeyi işleyin
            for (auto& [key, guild_name] : fake_guild[guild_list_key].items())
            {
                if (!guild_name.is_string())
                {
                    sys_err("Guild name for '%s' is not a string", key.c_str());
                    return false;
                }

                // Guild bilgilerini yükleme
                FakeGuild guild;
                guild.name = guild_name.get<std::string>();
                guild.id = m_nextGuildID++;
                guild.empire = &guild_list_key - &guild_lists[0] + 1;  // 1: kırmızı, 2: sarı, 3: mavi
                guild.level = number(1, 20);
                guild.memberCount = number(10, 50);

                m_fakeGuilds[guild.empire - 1].push_back(guild);
                sys_log(0, "Added fake guild: %s (ID: %d, Empire: %d, Level: %d)",
                    guild.name.c_str(), guild.id, guild.empire, guild.level);
            }
        }

        return true;
    }
    catch (const json::parse_error& e)
    {
        sys_err("JSON parse error: %s at byte %zu", e.what(), e.byte);
        return false;
    }
    catch (const std::exception& e)
    {
        sys_err("Error loading fake_guild.json: %s", e.what());
        return false;
    }
}

void CFakePlayerManager::Initialize()
{
    m_isReloading = false;
    m_lastReloadError.clear();
    m_mapFakePlayer.clear();
    m_dwLastSummonTime = 0;
    m_pkMovementEvent = nullptr;
    m_nextGuildID = 1000;

    // Her bir yükleme işlemi için ayrı hata kontrolü
    if (!LoadNameList())
    {
        sys_err("Failed to load name list!");
    }

    if (!LoadFakeGuilds())
    {
        sys_err("Failed to load fake guilds!");
    }

    if (!LoadFakePlayerConfig())
    {
        sys_err("Failed to load fake player config!");
    }

    sys_log(0, "LocaleService_GetBasePath(): %s", LocaleService_GetBasePath().c_str());

    StartMovementSystem();
}

// İlk ReloadConfigurations() tanımı kaldırıldı ve sadece bu tanım kullanılacak
TFakePlayerReloadResult CFakePlayerManager::ReloadConfigurations()
{
    TFakePlayerReloadResult result;

    if (m_isReloading)
    {
        result.errorMessage = "Reload already in progress";
        return result;
    }

    m_isReloading = true;

    try
    {
        // Konfigürasyonları yeniden yükle
        if (!LoadFakePlayerConfig())
            throw std::runtime_error("Failed to load fake player config");

        if (!LoadFakePlayerItems())
            throw std::runtime_error("Failed to load fake player items");

        if (!LoadGuildConfigurations())
            throw std::runtime_error("Failed to load guild configurations");

        if (!LoadNameList())
            throw std::runtime_error("Failed to load name list");

        result.success = true;
    }
    catch (const std::exception& e)
    {
        result.success = false;
        result.errorMessage = e.what();
        LogReloadError("Reload failed: %s", e.what());
    }

    m_isReloading = false;
    return result;
}

// İlk RestoreFakePlayers() tanımı kaldırıldı ve sadece bu tanım kullanılacak
bool CFakePlayerManager::RestoreFakePlayers(const std::vector<TFakePlayerLoginData>& savedData)
{
    bool success = true;

    for (const auto& data : savedData)
    {
        if (!SpawnFakePlayer(&data))
        {
            LogReloadError("Failed to restore fake player: %s", data.szName);
            success = false;
        }
    }

    return success;
}

bool CFakePlayerManager::LoadFakePlayerConfig()
{
    char file_path[256];
    snprintf(file_path, sizeof(file_path), "%s/json/fake_players.json", LocaleService_GetBasePath().c_str());

    std::ifstream ifs(file_path);
    if (!ifs.is_open())
    {
        sys_err("Unable to open fake_players.json at path: %s", file_path);
        return false;
    }

    try
    {
        // Önce dosya içeriğini string olarak oku
        std::stringstream buffer;
        buffer << ifs.rdbuf();
        std::string content = buffer.str();

        // Debug için içeriği yazdır
        sys_log(0, "JSON Content: %s", content.c_str());

        // JSON'ı parse et
        json jf = json::parse(content);

        // JSON yapısını kontrol et
        if (!jf.is_object())
        {
            sys_err("JSON root is not an object");
            return false;
        }

        if (!jf.contains("fake_players"))
        {
            sys_err("JSON does not contain 'fake_players' key");
            return false;
        }

        if (!jf["fake_players"].is_array())
        {
            sys_err("'fake_players' is not an array");
            return false;
        }

        if (jf["fake_players"].empty())
        {
            sys_err("'fake_players' array is empty");
            return false;
        }

        return true;
    }
    catch (const json::parse_error& e)
    {
        sys_err("JSON parse error: %s at byte %zu", e.what(), e.byte);
        return false;
    }
    catch (const std::exception& e)
    {
        sys_err("Error loading fake_players.json: %s", e.what());
        return false;
    }
}

bool CFakePlayerManager::LoadFakePlayerItems()
{
    char file_path[256];
    snprintf(file_path, sizeof(file_path), "%s/json/fake_player_item.json", LocaleService_GetBasePath().c_str());

    std::ifstream ifs(file_path);
    if (!ifs.is_open())
    {
        sys_err("Unable to open fake_player_item.json at path: %s", file_path);
        return false;
    }

    try
    {
        // Önce dosya içeriğini string olarak oku
        std::stringstream buffer;
        buffer << ifs.rdbuf();
        std::string content = buffer.str();

        // Debug için içeriği yazdır
        sys_log(0, "JSON Content: %s", content.c_str());

        // JSON'ı parse et
        json jf = json::parse(content);

        // JSON yapısını kontrol et
        if (!jf.is_object())
        {
            sys_err("JSON root is not an object");
            return false;
        }

        if (!jf.contains("fake_player_item"))
        {
            sys_err("JSON does not contain 'fake_player_item' key");
            return false;
        }

        if (!jf["fake_player_item"].is_array())
        {
            sys_err("'fake_player_item' is not an array");
            return false;
        }

        if (jf["fake_player_item"].empty())
        {
            sys_err("'fake_player_item' array is empty");
            return false;
        }

        return true;
    }
    catch (const json::parse_error& e)
    {
        sys_err("JSON parse error: %s at byte %zu", e.what(), e.byte);
        return false;
    }
    catch (const std::exception& e)
    {
        sys_err("Error loading fake_player_item.json: %s", e.what());
        return false;
    }
}

void CFakePlayerManager::SaveActiveFakePlayersData(std::vector<TFakePlayerLoginData>& outData)
{
    outData.clear();

    for (const auto& [name, fakePlayer] : m_mapFakePlayer)
    {
        if (!fakePlayer || !fakePlayer->GetFakePlayer())
            continue;

        LPCHARACTER ch = fakePlayer->GetFakePlayer();
        TFakePlayerLoginData data;

        strlcpy(data.szName, ch->GetName(), sizeof(data.szName));
        data.lMapIndex = ch->GetMapIndex();
        data.lX = ch->GetX();
        data.lY = ch->GetY();
        data.iRotation = ch->GetRotation();

        outData.push_back(data);
    }
}

void CFakePlayerManager::LogReloadError(const char* format, ...)
{
    char szBuf[4096];
    va_list args;

    va_start(args, format);
    vsnprintf(szBuf, sizeof(szBuf), format, args);
    va_end(args);

    sys_err("FakePlayer Reload Error: %s", szBuf);
    m_lastReloadError = szBuf;
}

// CFakePlayerManager'daki DismountAllFakePlayers fonksiyonunu da güncelleyelim
void CFakePlayerManager::DismountAllFakePlayers()
{
    for (const auto& pair : m_mapFakePlayer)
    {
        if (LPCHARACTER ch = pair.second->GetFakePlayer())
        {
#ifdef ENABLE_MOUNT_CHECK
            ch->Unmount(ch);
#endif
            ch->UpdatePacket();
        }
    }
}

void CFakePlayerManager::OnFakePlayerKilled(LPCHARACTER killer, LPCHARACTER fakePlayer)
{
    if (!killer || !fakePlayer)
        return;

    const int alignmentPenalty = 100;
    killer->UpdateAlignment(-alignmentPenalty);

    sys_log(0, "Alignment penalty of %d applied to player %s for killing bot %s. New alignment: %d",
            alignmentPenalty, killer->GetName(), fakePlayer->GetName(), killer->GetAlignment());

    killer->ChatPacket(CHAT_TYPE_INFO, "You killed a bot player and lost %d alignment points.", alignmentPenalty);
}

void CFakePlayer::OnDeath(LPCHARACTER killer)
{
    if (!killer || !m_pFakePlayer)
        return;

    // Bot öldüğünde hareketi durdur
    StopMoving();

    // Eğer öldüren bir gerçek oyuncu ise derece puanlarını düşür
    if (killer->IsPC() && killer->GetPKMode() == PK_MODE_FREE)
    {
        sys_log(0, "FakePlayer %s killed by %s in free mode. Applying alignment penalty.",
                m_pFakePlayer->GetName(), killer->GetName());
        CFakePlayerManager::Instance().OnFakePlayerKilled(killer, m_pFakePlayer);
    }

    // Botu canlandırmak için respawn olayını ayarla
    m_bIsDead = true;
    m_dwDeadTime = get_dword_time();
    sys_log(0, "FakePlayer %s was killed by %s", m_pFakePlayer->GetName(), killer->GetName());
}

// CFakePlayerManager'da guild listelerini yükleme fonksiyonunu güncelleyelim
bool CFakePlayerManager::LoadFakeGuilds()
{
    char guild_path[256];
    const char* empire_files[] = {
        "json/guild_names_red.txt",
        "json/guild_names_yellow.txt",
        "json/guild_names_blue.txt"
    };

    m_fakeGuilds.resize(3);

    for (int empire = 0; empire < 3; ++empire)
    {
        snprintf(guild_path, sizeof(guild_path), "%s/%s",
                LocaleService_GetBasePath().c_str(), empire_files[empire]);

        // Debug için yolu yazdır
        sys_log(0, "Trying to load guild file from: %s", guild_path);

        std::ifstream file(guild_path);
        if (!file.is_open())
        {
            sys_err("Cannot open guild file at path: %s", guild_path);
            continue;
        }

        std::string line;
        while (std::getline(file, line))
        {
            if (line.empty() || line[0] == '#')
                continue;

            line.erase(0, line.find_first_not_of(" \t\r\n"));
            line.erase(line.find_last_not_of(" \t\r\n") + 1);

            if (!line.empty())
            {
                FakeGuild guild;
                guild.name = line;
                guild.id = m_nextGuildID++;
                guild.empire = empire + 1;
                guild.level = number(1, 20);  // Rastgele guild seviyesi
                guild.memberCount = number(10, 50); // Rastgele üye sayısı
                m_fakeGuilds[empire].push_back(guild);

                sys_log(0, "Added fake guild: %s (ID: %d, Empire: %d, Level: %d)",
                    guild.name.c_str(), guild.id, guild.empire, guild.level);
            }
        }
    }

    return true;
}

const CFakePlayerManager::FakeGuild* CFakePlayerManager::GetRandomFakeGuild(BYTE empire)
{
    if (empire < 1 || empire > 3 || m_fakeGuilds[empire-1].empty())
        return nullptr;

    size_t index = number(0, m_fakeGuilds[empire-1].size() - 1);
    return &m_fakeGuilds[empire-1][index];
}


// Rastgele bir kostüm item kodu seçmek için fonksiyon
int CFakePlayerManager::GetRandomCostumeItem(int costumeType) {
    auto it = costume_namelist.find(costumeType);
    if (it != costume_namelist.end() && !it->second.empty()) {
        const auto& items = it->second;
        int randomIndex = rand() % items.size();
        return items[randomIndex];
    }
    return 0;  // Geçerli bir item bulunmazsa 0 döndür
}

void CFakePlayer::ApplyEfsunBonuses()
{
    // Saldırı ve savunma bonusları
    m_pFakePlayer->SetPoint(POINT_ATT_SPEED, m_pFakePlayer->GetPoint(POINT_ATT_SPEED) + APPLY_ATT_SPEED);
    m_pFakePlayer->SetPoint(POINT_MOV_SPEED, m_pFakePlayer->GetPoint(POINT_MOV_SPEED) + APPLY_MOV_SPEED);
    m_pFakePlayer->SetPoint(POINT_CRITICAL_PCT, m_pFakePlayer->GetPoint(POINT_CRITICAL_PCT) + APPLY_CRITICAL_PCT);

    // Elemental bonuslar
    m_pFakePlayer->SetPoint(POINT_RESIST_FIRE, m_pFakePlayer->GetPoint(POINT_RESIST_FIRE) + APPLY_RESIST_FIRE);
    m_pFakePlayer->SetPoint(POINT_RESIST_ELEC, m_pFakePlayer->GetPoint(POINT_RESIST_ELEC) + APPLY_RESIST_ELEC);
    m_pFakePlayer->SetPoint(POINT_RESIST_MAGIC, m_pFakePlayer->GetPoint(POINT_RESIST_MAGIC) + APPLY_RESIST_MAGIC);

    // Hedef tipi bonuslar
    m_pFakePlayer->SetPoint(POINT_ATTBONUS_HUMAN, m_pFakePlayer->GetPoint(POINT_ATTBONUS_HUMAN) + APPLY_ATTBONUS_HUMAN);
    m_pFakePlayer->SetPoint(POINT_ATTBONUS_ANIMAL, m_pFakePlayer->GetPoint(POINT_ATTBONUS_ANIMAL) + APPLY_ATTBONUS_ANIMAL);
    m_pFakePlayer->SetPoint(POINT_ATTBONUS_MONSTER, m_pFakePlayer->GetPoint(POINT_ATTBONUS_MONSTER) + APPLY_ATTBONUS_MONSTER);

    // Özel yetenek bonusları
    m_pFakePlayer->SetPoint(POINT_SKILL_DAMAGE_BONUS, m_pFakePlayer->GetPoint(POINT_SKILL_DAMAGE_BONUS) + APPLY_SKILL_DAMAGE_BONUS);
    m_pFakePlayer->SetPoint(POINT_SKILL_DEFEND_BONUS, m_pFakePlayer->GetPoint(POINT_SKILL_DEFEND_BONUS) + APPLY_SKILL_DEFEND_BONUS);

    // Diğer bonuslar
    m_pFakePlayer->SetPoint(POINT_HP_REGEN, m_pFakePlayer->GetPoint(POINT_HP_REGEN) + APPLY_HP_REGEN);
    m_pFakePlayer->SetPoint(POINT_SP_REGEN, m_pFakePlayer->GetPoint(POINT_SP_REGEN) + APPLY_SP_REGEN);
    m_pFakePlayer->SetPoint(POINT_GOLD_DOUBLE_BONUS, m_pFakePlayer->GetPoint(POINT_GOLD_DOUBLE_BONUS) + APPLY_GOLD_DOUBLE_BONUS);
}

// 3. Efsun (Bonus) Ayarları
void CFakePlayer::SetRandomBonuses()
{
    // 0  Karakterin vücut zırhı
    LPITEM bodyItem = m_pFakePlayer->GetWear(WEAR_BODY);
    if (bodyItem)
    {
        bodyItem->ClearAttribute();
        bodyItem->SetForceAttribute(0, APPLY_MAX_HP, 200000); 			// 1: Maksimum HP
        bodyItem->SetForceAttribute(1, APPLY_RESIST_SWORD, 15);			// 30: Çift el savunması
        bodyItem->SetForceAttribute(2, APPLY_RESIST_TWOHAND, 15);   	// 31: Hançer savunması
        bodyItem->SetForceAttribute(3, APPLY_RESIST_DAGGER, 15);   	 	// 32: Çan savunması
        bodyItem->SetForceAttribute(4, APPLY_RESIST_BELL, 15);      	// 32: Çan savunması
        bodyItem->SetForceAttribute(5, APPLY_RESIST_FAN, 15);       	// 33: Yelpaze savunması
        bodyItem->SetForceAttribute(6, APPLY_RESIST_BOW, 15);			// 34: Ok savunması
        bodyItem->SetForceAttribute(7, APPLY_RESIST_CLAW, 15);			// 96: Pençe Savunması
        bodyItem->SetForceAttribute(8, APPLY_CAST_SPEED, 20);			// 9: Büyü hızını artırır
        bodyItem->SetForceAttribute(9, APPLY_RESIST_FIRE, 15);			// 35: Ateş direnci
        bodyItem->SetForceAttribute(10, APPLY_RESIST_ELEC, 15);			// 36: Şimşek direnci
        bodyItem->SetForceAttribute(11, APPLY_RESIST_MAGIC, 15);		// 37: Büyü direnci
        bodyItem->SetForceAttribute(12, APPLY_RESIST_ELEC, 15);			// 38: Rüzgar direnci
    }

    // 1  Kask ekipmanı
    LPITEM headItem = m_pFakePlayer->GetWear(WEAR_HEAD);
    if (headItem)
    {
        headItem->ClearAttribute();
        headItem->SetForceAttribute(0, APPLY_RESIST_HUMAN, 10); 		// 17: İnsanlara karşı saldırı gücü artışı
        headItem->SetForceAttribute(1, APPLY_POISON_PCT, 8); 			// 12: Zehirleme olasılığı artışı
        headItem->SetForceAttribute(2, APPLY_MAGIC_DEF_GRADE, 15); 		// 56: Büyü savunması artışı
        headItem->SetForceAttribute(3, APPLY_STEAL_HP, 15); 			// 23: HB Absorbe (saldırı başına)
        headItem->SetForceAttribute(4, APPLY_BLOCK, 15); 				// 27: Yakın dövüş saldırıları bloklama şansı
        headItem->SetForceAttribute(5, APPLY_CAST_SPEED, 20);			// 9: Büyü hızını artırır
        headItem->SetForceAttribute(6, APPLY_POISON_PCT, 8);			// 12: Zehirleme olasılığı artışı
        headItem->SetForceAttribute(7, APPLY_STEAL_SP, 30);				// 24: Mana çalma (saldırı başına)
        headItem->SetForceAttribute(8, APPLY_DODGE, 15);				// 28: Oklardan korunma şansı
        headItem->SetForceAttribute(9, APPLY_RESIST_FIRE, 15);			// 35: Ateş direnci
        headItem->SetForceAttribute(10, APPLY_RESIST_ELEC, 15);			// 36: Şimşek direnci
        headItem->SetForceAttribute(11, APPLY_RESIST_MAGIC, 15);		// 37: Büyü direnci
        headItem->SetForceAttribute(12, APPLY_RESIST_ELEC, 15);			// 38: Rüzgar direnci
    }

    // 2  Ayakkabılar veya botlar
    LPITEM footsItem = m_pFakePlayer->GetWear(WEAR_FOOTS);
    if (footsItem)
    {
        footsItem->ClearAttribute();
        footsItem->SetForceAttribute(0, APPLY_MAX_HP, 2000); 			// 1: Maksimum HP
        footsItem->SetForceAttribute(1, APPLY_RESIST_SWORD, 15);		// 30: Çift el savunması
        footsItem->SetForceAttribute(2, APPLY_RESIST_TWOHAND, 15);   	// 31: Hançer savunması
        footsItem->SetForceAttribute(3, APPLY_RESIST_DAGGER, 15);    	// 32: Çan savunması
        footsItem->SetForceAttribute(4, APPLY_RESIST_BELL, 15);      	// 32: Çan savunması
        footsItem->SetForceAttribute(5, APPLY_RESIST_FAN, 15);  		// 33: Yelpaze savunması
        footsItem->SetForceAttribute(6, APPLY_RESIST_BOW, 15);			// 34: Ok savunması
        footsItem->SetForceAttribute(7, APPLY_RESIST_CLAW, 15);			// 96: Pençe Savunması
        footsItem->SetForceAttribute(8, APPLY_STUN_PCT, 8);				// 13: Sersemletme olasılığı artışı
        footsItem->SetForceAttribute(9, APPLY_SLOW_PCT, 8);				// 14: Yavaşlatma olasılığı artışı
    }

     // 3  Bileklik veya bilezik
    LPITEM wristItem = m_pFakePlayer->GetWear(WEAR_WRIST);
    if (wristItem)
    {
        wristItem->ClearAttribute();
        wristItem->SetForceAttribute(0, APPLY_RESIST_HUMAN, 10); 		// 17: İnsanlara karşı saldırı gücü artışı
        wristItem->SetForceAttribute(1, APPLY_MAX_HP, 2000); 			// 1: Maksimum HP
        wristItem->SetForceAttribute(2, APPLY_MAGIC_DEF_GRADE, 15); 	// 56: Büyü savunması artışı
        wristItem->SetForceAttribute(3, APPLY_PENETRATE_PCT, 15); 		// 16: Delici vuruş olasılığı artışı
        wristItem->SetForceAttribute(4, APPLY_STEAL_HP, 15); 			// 23: HB Absorbe (saldırı başına)
        wristItem->SetForceAttribute(5, APPLY_RESIST_FIRE, 15);			// 35: Ateş direnci
        wristItem->SetForceAttribute(6, APPLY_RESIST_ELEC, 15);			// 36: Şimşek direnci
        wristItem->SetForceAttribute(7, APPLY_RESIST_MAGIC, 15);		// 37: Büyü direnci
        wristItem->SetForceAttribute(8, APPLY_RESIST_ELEC, 15);			// 38: Rüzgar direnci
    }

    // 4  Ana silah (kılıç, yay vb.)
    LPITEM weaponItem = m_pFakePlayer->GetWear(WEAR_WEAPON);
    if (weaponItem)
    {
		weaponItem->ClearAttribute();
        weaponItem->SetForceAttribute(0, APPLY_RESIST_HUMAN, 10); 		// 17: İnsanlara karşı saldırı gücü artışı
        weaponItem->SetForceAttribute(1, APPLY_INT, 12);				// 4: Zeka (INT) artışı
        weaponItem->SetForceAttribute(2, APPLY_STR, 12);				// 5: Güç (STR) artışı
        weaponItem->SetForceAttribute(3, APPLY_DEX, 12);				// 6: Çeviklik (DEX) artışı
        weaponItem->SetForceAttribute(4, APPLY_CRITICAL_PCT, 15);		// 15: Kritik vuruş olasılığı artışı
        weaponItem->SetForceAttribute(5, APPLY_PENETRATE_PCT, 15);		// 16: Delici vuruş olasılığı artışı
        weaponItem->SetForceAttribute(6, APPLY_CAST_SPEED, 20);			// 9: Büyü hızını artırır
        weaponItem->SetForceAttribute(7, APPLY_POISON_PCT, 8);			// 12: Zehirleme olasılığı artışı
        weaponItem->SetForceAttribute(8, APPLY_STUN_PCT, 8);			// 13: Sersemletme olasılığı artışı
        weaponItem->SetForceAttribute(9, APPLY_SLOW_PCT, 8);			// 14: Yavaşlatma olasılığı artışı
    }

    // 5  Kolye veya gerdanlık
    LPITEM neckItem = m_pFakePlayer->GetWear(WEAR_NECK);
    if (neckItem)
    {
        neckItem->ClearAttribute();
        neckItem->SetForceAttribute(0, APPLY_MAX_HP, 2000); 			// 1: Maksimum HP
        neckItem->SetForceAttribute(1, APPLY_RESIST_SWORD, 15);			// 30: Çift el savunması
        neckItem->SetForceAttribute(2, APPLY_RESIST_TWOHAND, 15);   	// 31: Hançer savunması
        neckItem->SetForceAttribute(3, APPLY_RESIST_DAGGER, 15);    	// 32: Çan savunması
        neckItem->SetForceAttribute(4, APPLY_RESIST_BELL, 15);      	// 32: Çan savunması
        neckItem->SetForceAttribute(5, APPLY_RESIST_FAN, 15);       	// 33: Yelpaze savunması
        neckItem->SetForceAttribute(6, APPLY_RESIST_BOW, 15);			// 34: Ok savunması
        neckItem->SetForceAttribute(7, APPLY_RESIST_CLAW, 15);			// 96: Pençe Savunması
    }

    // 6  Küpe ekipmanı
    LPITEM earItem = m_pFakePlayer->GetWear(WEAR_EAR);
    if (earItem)
    {
        earItem->ClearAttribute();
        earItem->SetForceAttribute(0, APPLY_RESIST_HUMAN, 10); 			// 17: İnsanlara karşı saldırı gücü artışı
        earItem->SetForceAttribute(1, APPLY_RESIST_SWORD, 15);			// 30: Çift el savunması
        earItem->SetForceAttribute(2, APPLY_RESIST_TWOHAND, 15);   		// 31: Hançer savunması
        earItem->SetForceAttribute(3, APPLY_RESIST_DAGGER, 15);    		// 32: Çan savunması
        earItem->SetForceAttribute(4, APPLY_RESIST_BELL, 15); 			// 32: Çan savunması
        earItem->SetForceAttribute(5, APPLY_RESIST_FAN, 15);       		// 33: Yelpaze savunması
        earItem->SetForceAttribute(6, APPLY_RESIST_BOW, 15);			// 34: Ok savunması
        earItem->SetForceAttribute(7, APPLY_RESIST_CLAW, 15);			// 96: Pençe Savunması
    }

     // 10 Kalkan ekipmanı
    LPITEM shieldItem = m_pFakePlayer->GetWear(WEAR_SHIELD);
    if (shieldItem)
    {
        shieldItem->ClearAttribute();
        shieldItem->SetForceAttribute(0, APPLY_ATTBONUS_HUMAN, 15);		// 17: Yarı İnsanlara karşı saldırı gücü artışı
        shieldItem->SetForceAttribute(1, APPLY_INT, 12);				// 4: Zeka (INT) artışı
        shieldItem->SetForceAttribute(2, APPLY_STR, 12);				// 5: Güç (STR) artışı
        shieldItem->SetForceAttribute(3, APPLY_DEX, 12);				// 6: Çeviklik (DEX) artışı
        shieldItem->SetForceAttribute(4, APPLY_BLOCK, 15);				// 27: Bloklama şansı artışı
        shieldItem->SetForceAttribute(5, APPLY_IMMUNE_STUN, 1);			// 48: Sersemletme bağışıklığı
        shieldItem->SetForceAttribute(6, APPLY_IMMUNE_SLOW, 1);			// 49: Yavaşlatma bağışıklığı
    }

    /*// 19 Kostüm vücut zırhı
    LPITEM earItem = m_pFakePlayer->GetWear(WEAR_COSTUME_BODY);
    if (earItem)
    {
        earItem->ClearAttribute();
        earItem->SetForceAttribute(0, APPLY_RESIST_HUMAN, 10); 			// 17: İnsanlara karşı saldırı gücü artışı
        earItem->SetForceAttribute(1, APPLY_RESIST_SWORD, 15);			// 30: Çift el savunması
        earItem->SetForceAttribute(2, APPLY_RESIST_TWOHAND, 15);   		// 31: Hançer savunması
        earItem->SetForceAttribute(3, APPLY_RESIST_DAGGER, 15);    	 	// 32: Çan savunması
        earItem->SetForceAttribute(4, APPLY_RESIST_BELL, 15);      	// 32: Çan savunması
        earItem->SetForceAttribute(5, APPLY_RESIST_FAN, 15);       	// 33: Yelpaze savunması
        earItem->SetForceAttribute(6, APPLY_RESIST_BOW, 15);			// 34: Ok savunması
        earItem->SetForceAttribute(7, APPLY_RESIST_CLAW, 15);			// 96: Pençe Savunması
    }

    // 20 Kostüm saç aksesuarı
    LPITEM earItem = m_pFakePlayer->GetWear(WEAR_COSTUME_HAIR);
    if (earItem)
    {
		bodyItem->ClearAttribute();
        bodyItem->SetForceAttribute(0, APPLY_MAX_HP, 2000); 			// 1: Maksimum HP
        bodyItem->SetForceAttribute(1, APPLY_RESIST_SWORD, 15);			// 30: Çift el savunması
        bodyItem->SetForceAttribute(2, APPLY_RESIST_TWOHAND, 15);   	// 31: Hançer savunması
        bodyItem->SetForceAttribute(3, APPLY_RESIST_DAGGER, 15);    	 	// 32: Çan savunması
        bodyItem->SetForceAttribute(4, APPLY_RESIST_BELL, 15);      	// 32: Çan savunması
        bodyItem->SetForceAttribute(5, APPLY_RESIST_FAN, 15);       	// 33: Yelpaze savunması
        bodyItem->SetForceAttribute(6, APPLY_RESIST_BOW, 15);			// 34: Ok savunması
        bodyItem->SetForceAttribute(7, APPLY_RESIST_CLAW, 15);			// 96: Pençe Savunması
        bodyItem->SetForceAttribute(8, APPLY_CAST_SPEED, 20);			// 9: Büyü hızını artırır
        bodyItem->SetForceAttribute(9, APPLY_RESIST_FIRE, 15);			// 35: Ateş direnci
        bodyItem->SetForceAttribute(10, APPLY_RESIST_ELEC, 15);			// 36: Şimşek direnci
        bodyItem->SetForceAttribute(11, APPLY_RESIST_MAGIC, 15);		// 37: Büyü direnci
        bodyItem->SetForceAttribute(12, APPLY_RESIST_ELEC, 15);			// 38: Rüzgar direnci
    }

    // 21 Kostüm bineği (Eğer etkinse, ENABLE_MOUNT_COSTUME_SYSTEM)
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
    LPITEM earItem = m_pFakePlayer->GetWear(WEAR_COSTUME_MOUNT);
    if (earItem)
    {
        earItem->ClearAttribute();
        earItem->SetForceAttribute(0, APPLY_RESIST_HUMAN, 10); 	// 17: İnsanlara karşı saldırı gücü artışı
        earItem->SetForceAttribute(1, APPLY_RESIST_SWORD, 15);		// 30: Çift el savunması
        earItem->SetForceAttribute(2, APPLY_RESIST_TWOHAND, 15);   // 31: Hançer savunması
        earItem->SetForceAttribute(3, APPLY_RESIST_DAGGER, 15);    // 32: Çan savunması
        earItem->SetForceAttribute(4, APPLY_RESIST_BELL, 15);      // 32: Çan savunması
        earItem->SetForceAttribute(5, APPLY_RESIST_FAN, 15);       // 33: Yelpaze savunması
        earItem->SetForceAttribute(6, APPLY_RESIST_BOW, 15);		// 34: Ok savunması
        earItem->SetForceAttribute(7, APPLY_RESIST_CLAW, 15);		// 96: Pençe Savunması
    }
#endif

    // 22 Kostüm aksesuar (Eğer etkinse, ENABLE_ACCE_COSTUME_SYSTEM)
#ifdef ENABLE_ACCE_COSTUME_SYSTEM
    LPITEM earItem = m_pFakePlayer->GetWear(WEAR_COSTUME_ACCE);
    if (earItem)
    {
        earItem->ClearAttribute();
        earItem->SetForceAttribute(0, APPLY_RESIST_HUMAN, 10); 		// 17: İnsanlara karşı saldırı gücü artışı
        earItem->SetForceAttribute(1, APPLY_RESIST_SWORD, 15);		// 30: Çift el savunması
        earItem->SetForceAttribute(2, APPLY_RESIST_TWOHAND, 15);	// 31: Hançer savunması
        earItem->SetForceAttribute(3, APPLY_RESIST_DAGGER, 15);		// 32: Çan savunması
        earItem->SetForceAttribute(4, APPLY_RESIST_BELL, 15); 		// 32: Çan savunması
        earItem->SetForceAttribute(5, APPLY_RESIST_FAN, 15);		// 33: Yelpaze savunması
        earItem->SetForceAttribute(6, APPLY_RESIST_BOW, 15);		// 34: Ok savunması
        earItem->SetForceAttribute(7, APPLY_RESIST_CLAW, 15);		// 96: Pençe Savunması
    }
#endif

    // 23 Kostüm silah (Eğer etkinse, ENABLE_WEAPON_COSTUME_SYSTEM)
#ifdef ENABLE_WEAPON_COSTUME_SYSTEM
    LPITEM earItem = m_pFakePlayer->GetWear(WEAR_COSTUME_WEAPON);
    if (earItem)
    {
        earItem->ClearAttribute();
        earItem->SetForceAttribute(0, APPLY_RESIST_HUMAN, 10); 	// 17: İnsanlara karşı saldırı gücü artışı
        earItem->SetForceAttribute(1, APPLY_RESIST_SWORD, 15);		// 30: Çift el savunması
        earItem->SetForceAttribute(2, APPLY_RESIST_TWOHAND, 15);   // 31: Hançer savunması
        earItem->SetForceAttribute(3, APPLY_RESIST_DAGGER, 15);    // 32: Çan savunması
        earItem->SetForceAttribute(4, APPLY_RESIST_BELL, 15);      // 32: Çan savunması
        earItem->SetForceAttribute(5, APPLY_RESIST_FAN, 15);       // 33: Yelpaze savunması
        earItem->SetForceAttribute(6, APPLY_RESIST_BOW, 15);		// 34: Ok savunması
        earItem->SetForceAttribute(7, APPLY_RESIST_CLAW, 15);		// 96: Pençe Savunması
    }
#endif

    // 24 Kostüm aura (Eğer etkinse, ENABLE_AURA_SYSTEM)
#ifdef ENABLE_AURA_SYSTEM
    LPITEM earItem = m_pFakePlayer->GetWear(WEAR_COSTUME_AURA);
    if (earItem)
    {
        earItem->ClearAttribute();
        earItem->SetForceAttribute(0, APPLY_RESIST_HUMAN, 10); 		// 17: İnsanlara karşı saldırı gücü artışı
        earItem->SetForceAttribute(1, APPLY_RESIST_SWORD, 15);		// 30: Çift el savunması
        earItem->SetForceAttribute(2, APPLY_RESIST_TWOHAND, 15);   // 31: Hançer savunması
        earItem->SetForceAttribute(3, APPLY_RESIST_DAGGER, 15);    // 32: Çan savunması
        earItem->SetForceAttribute(4, APPLY_RESIST_BELL, 15);      // 32: Çan savunması
        earItem->SetForceAttribute(5, APPLY_RESIST_FAN, 15);       // 33: Yelpaze savunması
        earItem->SetForceAttribute(6, APPLY_RESIST_BOW, 15);		// 34: Ok savunması
        earItem->SetForceAttribute(7, APPLY_RESIST_CLAW, 15);		// 96: Pençe Savunması
    }
#endif

    // 25 Yüzük pozisyonu 1
    LPITEM earItem = m_pFakePlayer->GetWear(WEAR_RING1);
    if (earItem)
    {
        earItem->ClearAttribute();
        earItem->SetForceAttribute(0, APPLY_RESIST_HUMAN, 10); 	// 17: İnsanlara karşı saldırı gücü artışı
        earItem->SetForceAttribute(1, APPLY_RESIST_SWORD, 15);		// 30: Çift el savunması
        earItem->SetForceAttribute(2, APPLY_RESIST_TWOHAND, 15);   	// 31: Hançer savunması
        earItem->SetForceAttribute(3, APPLY_RESIST_DAGGER, 15);    	// 32: Çan savunması
        earItem->SetForceAttribute(4, APPLY_RESIST_BELL, 15);      	// 32: Çan savunması
        earItem->SetForceAttribute(5, APPLY_RESIST_FAN, 15);       	// 33: Yelpaze savunması
        earItem->SetForceAttribute(6, APPLY_RESIST_BOW, 15);		// 34: Ok savunması
        earItem->SetForceAttribute(7, APPLY_RESIST_CLAW, 15);		// 96: Pençe Savunması
    }

    // 26 Yüzük pozisyonu 2
    LPITEM earItem = m_pFakePlayer->GetWear(WEAR_RING2);
    if (earItem)
    {
        earItem->ClearAttribute();
        earItem->SetForceAttribute(0, APPLY_RESIST_HUMAN, 10); 	// 17: İnsanlara karşı saldırı gücü artışı
        earItem->SetForceAttribute(1, APPLY_RESIST_SWORD, 15);		// 30: Çift el savunması
        earItem->SetForceAttribute(2, APPLY_RESIST_TWOHAND, 15);   	// 31: Hançer savunması
        earItem->SetForceAttribute(3, APPLY_RESIST_DAGGER, 15);    	// 32: Çan savunması
        earItem->SetForceAttribute(4, APPLY_RESIST_BELL, 15);      	// 32: Çan savunması
        earItem->SetForceAttribute(5, APPLY_RESIST_FAN, 15);       	// 33: Yelpaze savunması
        earItem->SetForceAttribute(6, APPLY_RESIST_BOW, 15);		// 34: Ok savunması
        earItem->SetForceAttribute(7, APPLY_RESIST_CLAW, 15);		// 96: Pençe Savunması
    }

    // 27 Kemer
    LPITEM earItem = m_pFakePlayer->GetWear(WEAR_BELT);
    if (earItem)
    {
        earItem->ClearAttribute();
        earItem->SetForceAttribute(0, APPLY_RESIST_HUMAN, 10); 	// 17: İnsanlara karşı saldırı gücü artışı
        earItem->SetForceAttribute(1, APPLY_RESIST_SWORD, 15);		// 30: Çift el savunması
        earItem->SetForceAttribute(2, APPLY_RESIST_TWOHAND, 15);   	// 31: Hançer savunması
        earItem->SetForceAttribute(3, APPLY_RESIST_DAGGER, 15);    	// 32: Çan savunması
        earItem->SetForceAttribute(4, APPLY_RESIST_BELL, 15);      	// 32: Çan savunması
        earItem->SetForceAttribute(5, APPLY_RESIST_FAN, 15);       	// 33: Yelpaze savunması
        earItem->SetForceAttribute(6, APPLY_RESIST_BOW, 15);		// 34: Ok savunması
        earItem->SetForceAttribute(7, APPLY_RESIST_CLAW, 15);		// 96: Pençe Savunması
    }

    // 28 Kolye veya madalyon (Eğer etkinse, ENABLE_PENDANT)
#ifdef ENABLE_PENDANT
    LPITEM earItem = m_pFakePlayer->GetWear(WEAR_PENDANT);
    if (earItem)
    {
        earItem->ClearAttribute();
        earItem->SetForceAttribute(0, APPLY_RESIST_HUMAN, 10); 	// 17: İnsanlara karşı saldırı gücü artışı
        earItem->SetForceAttribute(1, APPLY_RESIST_SWORD, 15);		// 30: Çift el savunması
        earItem->SetForceAttribute(2, APPLY_RESIST_TWOHAND, 15);   	// 31: Hançer savunması
        earItem->SetForceAttribute(3, APPLY_RESIST_DAGGER, 15);    	// 32: Çan savunması
        earItem->SetForceAttribute(4, APPLY_RESIST_BELL, 15);      	// 32: Çan savunması
        earItem->SetForceAttribute(5, APPLY_RESIST_FAN, 15);       	// 33: Yelpaze savunması
        earItem->SetForceAttribute(6, APPLY_RESIST_BOW, 15);		// 34: Ok savunması
        earItem->SetForceAttribute(7, APPLY_RESIST_CLAW, 15);		// 96: Pençe Savunması
    }
#endif

    // 29 Eldiven (Eğer etkinse)
#ifdef ENABLE_GLOVE_SYSTEM
    LPITEM earItem = m_pFakePlayer->GetWear(WEAR_GLOVE);
    if (earItem)
    {
        earItem->ClearAttribute();
        earItem->SetForceAttribute(0, APPLY_RESIST_HUMAN, 10); 	// 17: İnsanlara karşı saldırı gücü artışı
        earItem->SetForceAttribute(1, APPLY_RESIST_SWORD, 15);		// 30: Çift el savunması
        earItem->SetForceAttribute(2, APPLY_RESIST_TWOHAND, 15);   	// 31: Hançer savunması
        earItem->SetForceAttribute(3, APPLY_RESIST_DAGGER, 15);    	// 32: Çan savunması
        earItem->SetForceAttribute(4, APPLY_RESIST_BELL, 15);      	// 32: Çan savunması
        earItem->SetForceAttribute(5, APPLY_RESIST_FAN, 15);       	// 33: Yelpaze savunması
        earItem->SetForceAttribute(6, APPLY_RESIST_BOW, 15);		// 34: Ok savunması
        earItem->SetForceAttribute(7, APPLY_RESIST_CLAW, 15);		// 96: Pençe Savunması
    }
#endif

    // Evcil hayvan pozisyonu (Eğer etkinse)
#if defined(ENABLE_PROTO_RENEWAL_CUSTOM) && defined(ENABLE_PET_SYSTEM)
    LPITEM earItem = m_pFakePlayer->GetWear(WEAR_PET);
    if (earItem)
    {
        earItem->ClearAttribute();
        earItem->SetForceAttribute(0, APPLY_RESIST_HUMAN, 10); 	// 17: İnsanlara karşı saldırı gücü artışı
        earItem->SetForceAttribute(1, APPLY_RESIST_SWORD, 15);		// 30: Çift el savunması
        earItem->SetForceAttribute(2, APPLY_RESIST_TWOHAND, 15);   	// 31: Hançer savunması
        earItem->SetForceAttribute(3, APPLY_RESIST_DAGGER, 15);    	// 32: Çan savunması
        earItem->SetForceAttribute(4, APPLY_RESIST_BELL, 15);      	// 32: Çan savunması
        earItem->SetForceAttribute(5, APPLY_RESIST_FAN, 15);       	// 33: Yelpaze savunması
        earItem->SetForceAttribute(6, APPLY_RESIST_BOW, 15);		// 34: Ok savunması
        earItem->SetForceAttribute(7, APPLY_RESIST_CLAW, 15);		// 96: Pençe Savunması
    }
#endif*/
}


// Bu fonksiyonu bot karakter yaratıldıktan sonra çağırarak tüm bonusları ekleyebilirsiniz
void CFakePlayer::InitializeAttributes()
{
    if (!m_pFakePlayer)
        return;

    // Temel combat özelliklerini ayarla
    m_dwLastMotionTime = 0;

    // Combat özelliklerini uygula
    m_pFakePlayer->SetPoint(POINT_MOV_SPEED, FAKE_PLAYER_MOV_SPEED);

    // Efsun bonuslarını uygula
    ApplyEfsunBonuses();
}
#endif