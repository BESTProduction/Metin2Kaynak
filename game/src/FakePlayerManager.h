#ifdef __FAKE_PLAYER__
#pragma once
#include "typedef.h"
#include "../../common/singleton.h"
#include "../../common/length.h"
#include "../../common/tables.h"
#include "packet.h"
#include "char.h"
#include "sectree.h"
#include "motion.h"
#include "entity.h"
#include <nlohmann/json.hpp>
using json = nlohmann::json;
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <map>

#define CHECK_VISIBILITY(ch, target) (true)
#define DEFAULT_ATTACK_SPEED 1000

// Combat event info yapısı
typedef struct fake_player_event_info : event_info_data
{
    DWORD dwLastUpdateTime;
} FAKE_PLAYER_EVENT_INFO;

enum EFakePlayer
{
    FAKE_PLAYER_LIVE_TIME = 10 * 60 * 1000,
    FAKE_PLAYER_MOV_SPEED = 300,
};

// JSON dosya yolları için sabitler
constexpr const char* FAKE_PLAYER_JSON_PATH = "json/fake_players.json";
constexpr const char* FAKE_PLAYER_GUILD_JSON_PATH = "json/fake_guild.json";
constexpr const char* FAKE_PLAYER_NAMELIST_PATH = "json/namelist.txt";

// Reload işlemi için yapı
struct TFakePlayerReloadResult
{
    bool success;
    std::string errorMessage;
    int reloadedBotCount;
    TFakePlayerReloadResult() : success(false), reloadedBotCount(0) {}
};

class CFakePlayer
{
public:
    CFakePlayer(TFakePlayerLoginData* fakePlayerLoginData);
    ~CFakePlayer();

    // Temel fonksiyonlar
    void Login(TFakePlayerLoginData* fakePlayerLoginData);
    bool LoadFakePlayer();
    void Move();
    void StopMoving();
    void ReviveCharacter();
    void UpdateCombat();
    void SetInCombat(bool bInCombat) { m_bInCombat = bInCombat; }
    bool IsInCombat() const { return m_bInCombat; }

    // Appearance fonksiyonları
    void InitializeAppearance();
    void SetHair(BYTE byHair);
    void SetEmpireFlag(BYTE byEmpire);

    // Bonus ve özellik fonksiyonları
    void ApplyEfsunBonuses();
    void SetRandomBonuses();
    void InitializeAttributes();
    void OnDeath(LPCHARACTER killer);

    // Getter/Setter fonksiyonları
    BYTE GetHair() const { return m_byHair; }
    BYTE GetEmpire() const { return m_byEmpire; }
    LPCHARACTER GetFakePlayer() const { return m_pFakePlayer; }

private:
    LPCHARACTER m_pFakePlayer;
    DWORD m_dwLastMotionTime;
    DWORD m_dwLastMoveTime;
    DWORD m_dwLastAttackTime;
    DWORD m_dwLastSkillTime;
    int m_iCurrentTarget;
    bool m_bInCombat;
    float m_fAttackRange;
    
    // Saldırı fonksiyonları
    void SearchTarget();
    bool IsValidTarget(LPCHARACTER target) const;
    void ProcessCombat();
    void PerformAttack(LPCHARACTER target);
    void UseSkill(LPCHARACTER target);
    bool IsInAttackRange(LPCHARACTER target) const;

    // Diğer özellikler
    bool m_bIsDead;
    DWORD m_dwDeadTime;
    int m_iDestX;
    int m_iDestY;
    BYTE m_byHair;
    BYTE m_byEmpire;

    bool IsBlocked(long x, long y) const;
};

class CFakePlayerManager : public singleton<CFakePlayerManager>
{
public:
    struct FakeGuild {
        std::string name;
        DWORD id;
        BYTE empire;
        BYTE level;
        int memberCount;
    };
    CFakePlayerManager();
    ~CFakePlayerManager();

    // Temel yönetim fonksiyonları
    void Initialize();
    void Destroy();

    // Bot yönetimi
    void FakePlayerLogin(LPCHARACTER ch, const TFakePlayerLoginData* fakePlayerLoginData);
    void FakePlayerLogout(const char* szName, LPCHARACTER ch = nullptr);
    void DestroyFakePlayer(TFakePlayerLogoutData* fakePlayerLogoutData);
    bool SpawnFakePlayer(const TFakePlayerLoginData* fakePlayerLoginData);

    // Update sistemi
    void StartUpdateSystem();
    void StopUpdateSystem();
    void UpdateFakePlayers();

    bool IsEnemyEmpire(BYTE empire1, BYTE empire2) const;

    // Guild ve kostüm sistemi
    const FakeGuild* GetRandomFakeGuild(BYTE empire);
    int GetRandomCostumeItem(int costumeType);
    static const std::map<int, std::vector<int>> costume_namelist;

    // Yardımcı fonksiyonlar
    CFakePlayer* FindFakePlayer(const std::string& stName);
    void GetActiveFakePlayerNames(std::vector<std::string>& nameList);
    std::string GetRandomName();

    // Load/Save fonksiyonları
    bool LoadFakePlayerConfig();
    bool LoadFakePlayerItems();
    bool LoadNameList();
    bool LoadGuildConfigurations();
    bool LoadFakeGuilds();

    // Event yönetimi
    void OnFakePlayerKilled(LPCHARACTER killer, LPCHARACTER fakePlayer);
    void DGFakePlayer(uint32_t dwHandle, const char* c_pData);

    // Reload sistemi
    TFakePlayerReloadResult ReloadConfigurations();
    void SaveActiveFakePlayersData(std::vector<TFakePlayerLoginData>& outData);
    bool RestoreFakePlayers(const std::vector<TFakePlayerLoginData>& savedData);
    void LogReloadError(const char* format, ...);

    // İsim yönetimi
    void RemoveUsedName(const std::string& name);
    void AddNameBackToList(const std::string& name);

    // Hareket sistemi
    void StartMovementSystem();
    void StopMovementSystem();
    void MoveAllFakePlayers();
    void DismountAllFakePlayers();

private:
    typedef std::map<std::string, std::unique_ptr<CFakePlayer>> TFakePlayerMap;
    TFakePlayerMap m_mapFakePlayer;

    // Guild yönetimi
    std::vector<std::vector<FakeGuild>> m_fakeGuilds;
    DWORD m_nextGuildID;

    // Event yönetimi
    LPEVENT m_pkUpdateEvent;
    LPEVENT m_pkMovementEvent;

    // Yardımcı değişkenler
    json m_itemConfigurations;
    bool m_isReloading;
    std::string m_lastReloadError;
    std::vector<std::string> m_vecNameList;
    uint32_t m_dwLastSummonTime;
};

#endif