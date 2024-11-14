#include "stdafx.h"
#include "config.h"

#include "threeway_war.h"

#include "../../common/length.h"
#include "../../common/tables.h"
#include "p2p.h"
#include "locale_service.h"
#include "packet.h"
#include "char.h"
#include "questmanager.h"
#include "questlua.h"
#include "start_position.h"
#include "char_manager.h"
#include "sectree_manager.h"
#include "regen.h"
#include "log.h"

EVENTINFO(regen_mob_event_info)
{
	uint32_t dwMapIndex;

	regen_mob_event_info()
	: dwMapIndex( 0 )
	{
	}
};

EVENTFUNC(regen_mob_event)
{
	regen_mob_event_info * info = dynamic_cast<regen_mob_event_info *>(event->info);

	if ( info == nullptr )
	{
		sys_err( "regen_mob_event> <Factor> Null pointer" );
		return 0;
	}

	int iMapIndex = info->dwMapIndex;

	char filename[128];
	std::string szFilename(GetSungziMapPath());


	int choice = quest::CQuestManager::Instance().GetEventFlag("threeway_war_choice");
	if (0 == choice)
		sprintf (filename, "%sregen00.txt", GetSungziMapPath());
	else
	{
		sprintf (filename, "%sregen00_%d.txt", GetSungziMapPath(), choice);
	}

	LPSECTREE_MAP pkMap = SECTREE_MANAGER::Instance().GetMap(iMapIndex);

	if (nullptr != pkMap)
	{
		if (0 != choice)
			if (regen_load_in_file(filename, iMapIndex, pkMap->m_setting.iBaseX, pkMap->m_setting.iBaseY))
			{
				sprintf (filename, "%sregen00.txt", GetSungziMapPath());
				regen_load_in_file(filename, iMapIndex, pkMap->m_setting.iBaseX, pkMap->m_setting.iBaseY);
			}
	}

	return 0;
}

CThreeWayWar::CThreeWayWar()
{
	Initialize();
}

CThreeWayWar::~CThreeWayWar()
{
	RegisterUserMap_.clear();
	ReviveTokenMap_.clear();
}

void CThreeWayWar::Initialize()
{
	RegenFlag_ = 0;

	memset( KillScore_, 0, sizeof(KillScore_) );

	RegisterUserMap_.clear();
	ReviveTokenMap_.clear();
}

int CThreeWayWar::GetKillScore( uint8_t empire ) const
{
	if( empire <= 0 || empire >= EMPIRE_MAX_NUM )
	{
		sys_err("ThreeWayWar::GetKillScore Wrong Empire variable");
		return 0;
	}

	return KillScore_[empire-1];
}

void CThreeWayWar::SetKillScore( uint8_t empire, int count )
{
	if( empire <= 0 || empire >= EMPIRE_MAX_NUM )
	{
		sys_err("ThreeWayWar::SetKillScore Wrong Empire variable");
		return;
	}

	KillScore_[empire-1] = count;
}

void CThreeWayWar::SetReviveTokenForPlayer(uint32_t PlayerID, int count)
{
	if (0 == PlayerID)
		return;

	ReviveTokenMap_[PlayerID] = count;
}

int CThreeWayWar::GetReviveTokenForPlayer(uint32_t PlayerID)
{
	if (0 == PlayerID)
		return 0;

	return ReviveTokenMap_[PlayerID];
}

void CThreeWayWar::DecreaseReviveTokenForPlayer(uint32_t PlayerID)
{
	if (0 == PlayerID)
		return;

	ReviveTokenMap_[PlayerID] = ReviveTokenMap_[PlayerID] - 1;
}

bool CThreeWayWar::LoadSetting(const char* szFileName)
{
	char szPath[1024];
	snprintf( szPath, sizeof(szPath), "%s/%s", LocaleService_GetBasePath().c_str(), szFileName);

	FILE* pf = fopen( szPath, "r" );

	if (nullptr == pf)
	{
		sys_err("[INIT_FORKED] Do not open file (%s)", szPath );
		return false;
	}

	char szLine[256];
	char szSungziName[128];
	char szPassName[3][128];

	while( nullptr != fgets(szLine, 256, pf) )
	{
		if (0 == strncmp(szLine, "sungzi:", 7))
		{
			struct ForkedSungziMapInfo sungziinfo;

			sscanf( szLine+7, "%d %d %d %d %d %d %d %s %d",
					&sungziinfo.m_iForkedSung,
					&sungziinfo.m_iForkedSungziStartPosition[0][0], &sungziinfo.m_iForkedSungziStartPosition[0][1],
					&sungziinfo.m_iForkedSungziStartPosition[1][0], &sungziinfo.m_iForkedSungziStartPosition[1][1],
					&sungziinfo.m_iForkedSungziStartPosition[2][0], &sungziinfo.m_iForkedSungziStartPosition[2][1],
					szSungziName, &sungziinfo.m_iBossMobVnum);

			sungziinfo.m_stMapName = static_cast<std::string>(szSungziName);

			SungZiInfoMap_.emplace_back( sungziinfo );

			MapIndexSet_.insert( sungziinfo.m_iForkedSung );
		}
		else if (0 == strncmp(szLine, "pass:", 5))
		{
			struct ForkedPassMapInfo passinfo;

			sscanf( szLine+5, "%d %d %d %s %d %d %d %s %d %d %d %s",
					&passinfo.m_iForkedPass[0],
					&passinfo.m_iForkedPassStartPosition[0][0], &passinfo.m_iForkedPassStartPosition[0][1], szPassName[0],
					&passinfo.m_iForkedPass[1],
					&passinfo.m_iForkedPassStartPosition[1][0], &passinfo.m_iForkedPassStartPosition[1][1], szPassName[1],
					&passinfo.m_iForkedPass[2],
					&passinfo.m_iForkedPassStartPosition[2][0], &passinfo.m_iForkedPassStartPosition[2][1], szPassName[2] );

			passinfo.m_stMapName[0] = static_cast<std::string>(szPassName[0]);
			passinfo.m_stMapName[1] = static_cast<std::string>(szPassName[1]);
			passinfo.m_stMapName[2] = static_cast<std::string>(szPassName[2]);

			PassInfoMap_.emplace_back( passinfo );

			MapIndexSet_.insert( passinfo.m_iForkedPass[0] );
			MapIndexSet_.insert( passinfo.m_iForkedPass[1] );
			MapIndexSet_.insert( passinfo.m_iForkedPass[2] );
		}
	}

	fclose(pf);

	return true;
}

const ForkedPassMapInfo& CThreeWayWar::GetEventPassMapInfo() const
{
	const size_t idx = quest::CQuestManager::Instance().GetEventFlag( "threeway_war_pass_idx" );

	return PassInfoMap_[idx];
}

const ForkedSungziMapInfo& CThreeWayWar::GetEventSungZiMapInfo() const
{
	const size_t idx = quest::CQuestManager::Instance().GetEventFlag( "threeway_war_sungzi_idx" );

	return SungZiInfoMap_[idx];
}

bool CThreeWayWar::IsThreeWayWarMapIndex(int iMapIndex) const
{
	return MapIndexSet_.find(iMapIndex) != MapIndexSet_.end();
}

bool CThreeWayWar::IsSungZiMapIndex(int iMapIndex) const
{
	std::vector<ForkedSungziMapInfo>::const_iterator it = SungZiInfoMap_.begin();

	for( ; it != SungZiInfoMap_.end() ; ++it )
	{
		if (iMapIndex == it->m_iForkedSung)
		{
			return true;
		}
	}

	return false;
}

void CThreeWayWar::RandomEventMapSet()
{
	const size_t pass_idx = number( 0, PassInfoMap_.size()-1 );
	const size_t sung_idx = number( 0, SungZiInfoMap_.size()-1 );

	quest::CQuestManager::Instance().RequestSetEventFlag( "threeway_war_sungzi_idx", sung_idx );
	quest::CQuestManager::Instance().RequestSetEventFlag( "threeway_war_pass_idx", pass_idx );
}

bool CThreeWayWar::IsRegisteredUser(uint32_t PlayerID) const
{
	std::unordered_map<uint32_t, uint32_t>::const_iterator iter = RegisterUserMap_.find(PlayerID);

	if (iter == RegisterUserMap_.end())
	{
		return false;
	}

	return true;
}

void CThreeWayWar::RegisterUser(uint32_t PlayerID)
{
	if (0 == PlayerID)
		return;

	RegisterUserMap_.insert( std::make_pair(PlayerID, PlayerID) );
}

int GetKillValue(int level)
{
	int iMinLevelFor1Point, iMaxLevelFor1Point;
	int iMinLevelFor2Point, iMaxLevelFor2Point;
	int iMinLevelFor3Point, iMaxLevelFor3Point;
	int iMinLevelFor4Point, iMaxLevelFor4Point; // @fixme153

	iMinLevelFor1Point = 30; iMaxLevelFor1Point = 39;
	iMinLevelFor2Point = 40; iMaxLevelFor2Point = 49;
	iMinLevelFor3Point = 50; iMaxLevelFor3Point = 99;
	iMinLevelFor4Point = 100; iMaxLevelFor4Point = gPlayerMaxLevel; // @fixme153

	if (iMinLevelFor1Point <= level && level <= iMaxLevelFor1Point)
	{
		return 1;
	}
	else if (iMinLevelFor2Point <= level && level <= iMaxLevelFor2Point)
	{
		return 2;
	}
	else if (iMinLevelFor3Point <= level && level <= iMaxLevelFor3Point)
	{
		return 3;
	}
	else if (iMinLevelFor4Point <= level && level <= iMaxLevelFor4Point)  // @fixme153
	{
		return 4;
	}

	return 0;
}

void CThreeWayWar::onDead(LPCHARACTER pChar, LPCHARACTER pkKiller)
{
	if (false == pChar->IsPC())
		return;

	if (GM_PLAYER != pChar->GetGMLevel() && !test_server)
		return;

	if (-1 == GetRegenFlag())
		return;

	DecreaseReviveTokenForPlayer( pChar->GetPlayerID() );

	if (false == IsSungZiMapIndex(pChar->GetMapIndex()))
		return;

	if (nullptr == pkKiller || true != pkKiller->IsPC())
		return;

	// ���� ������ ������� ����
	if (pChar->GetEmpire() == pkKiller->GetEmpire())
		return;

	int nKillScore = GetKillScore(pkKiller->GetEmpire());

	// ���� ų ���ھ -1�ϰ��� Ż�������̱⶧���� ���� üũ�� �ϸ� �ȵȴ�.
	if (nKillScore >= 0)
	{
		nKillScore += GetKillValue(pChar->GetLevel());
		SetKillScore(pkKiller->GetEmpire(), nKillScore);
	}

	if (nKillScore != 0 && (test_server || (nKillScore % 5) == 0))
	{
		char szBuf[64 + 1];

		snprintf(szBuf, sizeof(szBuf), LC_TEXT("���� ���ھ� �ż���:%d õ����:%d ���뱹:%d"),
				GetKillScore(1), GetKillScore(2), GetKillScore(3));

		SendNoticeMap(szBuf, GetSungziMapIndex(), false);
	}

	const int nVictoryScore = quest::CQuestManager::Instance().GetEventFlag("threeway_war_kill_count");

	if (0 == GetRegenFlag())
	{
		int nEliminatedEmpireCount = 0;
		uint8_t bLoseEmpire = 0;

		for (int n = 1; n < 4; ++n)
		{
			if (nVictoryScore > GetKillScore(n))
			{
				++nEliminatedEmpireCount;
				bLoseEmpire = n;
			}
		}

		if (1 != nEliminatedEmpireCount)
			return;

		//----------------------
		//ī��Ʈ �ʱ�ȭ
		//----------------------
		SetKillScore(1, 0);
		SetKillScore(2, 0);
		SetKillScore(3, 0);
		SetKillScore(bLoseEmpire, -1);

		quest::warp_all_to_map_my_empire_event_info * info;

		//----------------------
		//Ż������ ���� ��Ű�� : ��������
		//----------------------
		info = AllocEventInfo<quest::warp_all_to_map_my_empire_event_info>();

		info->m_lMapIndexFrom	= GetSungziMapIndex();
		info->m_lMapIndexTo		= EMPIRE_START_MAP(bLoseEmpire);
		info->m_x				= EMPIRE_START_X(bLoseEmpire);
		info->m_y				= EMPIRE_START_Y(bLoseEmpire);
		info->m_bEmpire			= bLoseEmpire;

		event_create(quest::warp_all_to_map_my_empire_event, info, PASSES_PER_SEC(10));

		//----------------------
		//Ż������ ���� ��Ű�� : ��ο���
		//----------------------
		info = AllocEventInfo<quest::warp_all_to_map_my_empire_event_info>();

		info->m_lMapIndexFrom	= GetPassMapIndex(bLoseEmpire);
		info->m_lMapIndexTo		= EMPIRE_START_MAP(bLoseEmpire);
		info->m_x				= EMPIRE_START_X(bLoseEmpire);
		info->m_y				= EMPIRE_START_Y(bLoseEmpire);
		info->m_bEmpire			= bLoseEmpire;

		event_create(quest::warp_all_to_map_my_empire_event, info, PASSES_PER_SEC(10));

		//----------------------
		//������ �ñ�� ������ ���� �̾߱⸦ ������ ��!
		//----------------------
		const std::string Nation(EMPIRE_NAME(bLoseEmpire));
		const std::string Script(
				LC_TEXT("������ ����: ���� ") +
				Nation +
				LC_TEXT("�༮���� �̰� ������ ���� �ڰ��� �Ҿ���. ��� �������� �������Ŷ�~~[ENTER][ENTER] 10�� �Ŀ� ��� ������ �̵��ϰ� �˴ϴ�. ") +
				"[ENTER][DONE]"
				);

		CHARACTER_MANAGER::Instance().SendScriptToMap(pChar->GetMapIndex(), Script);

		//----------------------
		// ���� �ѹ� ������.
		//----------------------
		char szNotice[512+1];
		snprintf(szNotice, sizeof(szNotice), LC_TEXT("��Ÿ� �������� %s ������ ������� Ż���� �Ͽ����ϴ�"), Nation.c_str());
		BroadcastNotice(szNotice);

		snprintf(szNotice, sizeof(szNotice), "First Step: %s exclusion", Nation.c_str());
		LogManager::Instance().CharLog(0, 0, 0, 0, "THREEWAY", szNotice, nullptr);

		//----------------------
		// ���� �����Ѵ�.
		//----------------------
		regen_mob_event_info* regen_info = AllocEventInfo<regen_mob_event_info>();

		regen_info->dwMapIndex = pChar->GetMapIndex();

		event_create(regen_mob_event, regen_info, PASSES_PER_SEC(10));

		SetRegenFlag(1);
	}
	else if (1 == GetRegenFlag())
	{
		int nVictoryEmpireIndex = 0;

		for (int n = 1; n < 4; ++n)
		{
			nKillScore = GetKillScore(n);

			if (nKillScore == -1)
				continue;

			if (nVictoryScore <= nKillScore)
			{
				nVictoryEmpireIndex = n;
				break;
			}
		}

		if (0 == nVictoryEmpireIndex)
			return;

		for (int n = 1; n < 4; ++n)
		{
			if (n != nVictoryEmpireIndex)
			{
				uint8_t bLoseEmpire = n;
				quest::warp_all_to_map_my_empire_event_info * info;

				//----------------------
				//Ż������ ���� ��Ű�� : ��������
				//----------------------
				info = AllocEventInfo<quest::warp_all_to_map_my_empire_event_info>();

				info->m_lMapIndexFrom	= GetSungziMapIndex();
				info->m_lMapIndexTo		= EMPIRE_START_MAP(bLoseEmpire);
				info->m_x				= EMPIRE_START_X(bLoseEmpire);
				info->m_y				= EMPIRE_START_Y(bLoseEmpire);
				info->m_bEmpire			= bLoseEmpire;

				event_create(quest::warp_all_to_map_my_empire_event, info, PASSES_PER_SEC(5));

				//----------------------
				//Ż������ ���� ��Ű�� : ��ο���
				//----------------------
				info = AllocEventInfo<quest::warp_all_to_map_my_empire_event_info>();

				info->m_lMapIndexFrom	= GetPassMapIndex(bLoseEmpire);
				info->m_lMapIndexTo		= EMPIRE_START_MAP(bLoseEmpire);
				info->m_x				= EMPIRE_START_X(bLoseEmpire);
				info->m_y				= EMPIRE_START_Y(bLoseEmpire);
				info->m_bEmpire			= bLoseEmpire;

				event_create(quest::warp_all_to_map_my_empire_event, info, PASSES_PER_SEC(5));
			}
		}

		//------------------------------
		// ���� ���ھ� ǥ��
		//------------------------------
		{
			char szBuf[64 + 1];
			snprintf(szBuf, sizeof(szBuf), LC_TEXT("���� ���ھ� �ż���:%d õ����:%d ���뱹:%d"),
					GetKillScore(1), GetKillScore(2), GetKillScore(3));

			SendNoticeMap(szBuf, GetSungziMapIndex(), false);
		}

		// �޼����� ����ش�.
		LPSECTREE_MAP pSecMap = SECTREE_MANAGER::Instance().GetMap(pChar->GetMapIndex());

		if (nullptr != pSecMap)
		{
			const std::string EmpireName(EMPIRE_NAME(nVictoryEmpireIndex));
			const std::string Script(
					EmpireName +
					LC_TEXT(". ���� ������ ��ȣ�ڸ� ��� �ȴٸ� ����� ������ ������ �ȴ�.[ENTER][ENTER] ") +
					"[ENTER][DONE]");

			TPacketGCScript pack_script{};

			pack_script.header = HEADER_GC_SCRIPT;
			pack_script.skin = 1;
			pack_script.src_size = Script.size();

			quest::FSendPacketToEmpire fSend;
			fSend.bEmpire = nVictoryEmpireIndex;

			pack_script.size = pack_script.src_size + sizeof(TPacketGCScript);
			fSend.buf.write(&pack_script, sizeof(TPacketGCScript));
			fSend.buf.write(&Script[0], Script.size());

			pSecMap->for_each(fSend);

			char szBuf[512];
			snprintf(szBuf, sizeof(szBuf), "Second Step: %s remain", EMPIRE_NAME( nVictoryEmpireIndex ));
			LogManager::Instance().CharLog(0, 0, 0, 0, "THREEWAY", szBuf, nullptr);
		}

		//------------------------------
		// ������ ���� : ������ȣ ��ȯ
		//-----------------------------
		for (int n = 0; n < quest::CQuestManager::Instance().GetEventFlag("threeway_war_boss_count");)
		{
			int x = pChar->GetX();
			int y = pChar->GetY();

			x = (thecore_random() & 1) ? x - number(200, 1000) : x + number(200, 1000);
			y = (thecore_random() & 1) ? y - number(200, 1000) : y + number(200, 1000);

			if (x < 0)
				x = pChar->GetX();

			if (y < 0)
				y = pChar->GetY();

			LPCHARACTER ch = CHARACTER_MANAGER::Instance().SpawnMob(
					GetEventSungZiMapInfo().m_iBossMobVnum,
					pChar->GetMapIndex(),
					x, y, 0, false);

			if (nullptr != ch)
			{
				ch->SetAggressive();
				++n;
			}
		}

		SetRegenFlag(-1);
	}
}

struct FDestroyAllEntity
{
	void operator() (LPENTITY ent)
	{
		if (true == ent->IsType(ENTITY_CHARACTER))
		{
			LPCHARACTER ch = static_cast<LPCHARACTER>(ent);
			if (!ch->IsPC())
				ch->DeadNoReward(); // @fixme188 from Dead()
		}
	}
};

void CThreeWayWar::RemoveAllMonstersInThreeWay() const
{
	std::set<int>::const_iterator iter = MapIndexSet_.begin();

	while( iter != MapIndexSet_.end() )
	{
		LPSECTREE_MAP pSecMap = SECTREE_MANAGER::Instance().GetMap( *iter );

		if (nullptr != pSecMap)
		{
			FDestroyAllEntity f;

			pSecMap->for_each( f );
		}

		++iter;
	}
}

//
// C functions
//
const char* GetSungziMapPath()
{
	static char s_szMapPath[128];

	snprintf(s_szMapPath, sizeof(s_szMapPath), "%s/map/%s/",
		   	LocaleService_GetBasePath().c_str(),
		   	CThreeWayWar::Instance().GetEventSungZiMapInfo().m_stMapName.c_str());

	return s_szMapPath;
}

const char* GetPassMapPath( uint8_t bEmpire )
{
	if (bEmpire > 0 && bEmpire < EMPIRE_MAX_NUM)
	{
		static char s_szMapPath[128];

		snprintf(s_szMapPath, sizeof(s_szMapPath), "%s/map/%s/",
				LocaleService_GetBasePath().c_str(),
				CThreeWayWar::Instance().GetEventPassMapInfo().m_stMapName[bEmpire-1].c_str());

		return s_szMapPath;
	}

	return nullptr;
}

int GetPassMapIndex( uint8_t bEmpire )
{
	if (bEmpire > 0 && bEmpire < EMPIRE_MAX_NUM)
	{
		return CThreeWayWar::Instance().GetEventPassMapInfo().m_iForkedPass[bEmpire-1];
	}

	return 0;
}

int GetPassStartX( uint8_t bEmpire )
{
	if (bEmpire > 0 && bEmpire < EMPIRE_MAX_NUM)
	{
		return CThreeWayWar::Instance().GetEventPassMapInfo().m_iForkedPassStartPosition[bEmpire-1][0];
	}

	return 0;
}

int GetPassStartY( uint8_t bEmpire )
{
	if (bEmpire > 0 && bEmpire < EMPIRE_MAX_NUM)
	{
		return CThreeWayWar::Instance().GetEventPassMapInfo().m_iForkedPassStartPosition[bEmpire-1][1];
	}

	return 0;
}

int GetSungziMapIndex()
{
	return CThreeWayWar::Instance().GetEventSungZiMapInfo().m_iForkedSung;
}

int GetSungziStartX( uint8_t bEmpire )
{
	if (bEmpire > 0 && bEmpire < EMPIRE_MAX_NUM)
	{
		return CThreeWayWar::Instance().GetEventSungZiMapInfo().m_iForkedSungziStartPosition[bEmpire-1][0];
	}

	return 0;
}

int GetSungziStartY( uint8_t bEmpire )
{
	if (bEmpire > 0 && bEmpire < EMPIRE_MAX_NUM)
	{
		return CThreeWayWar::Instance().GetEventSungZiMapInfo().m_iForkedSungziStartPosition[bEmpire-1][1];
	}

	return 0;
}
