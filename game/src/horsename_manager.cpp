
#include "stdafx.h"
#include "horsename_manager.h"
#include "desc_client.h"
#include "char_manager.h"
#include "char.h"
#include "affect.h"
#include "utils.h"

CHorseNameManager::CHorseNameManager()
{
	m_mapHorseNames.clear();
}

const char* CHorseNameManager::GetHorseName(uint32_t dwPlayerID)
{
	std::map<uint32_t, std::string>::iterator iter;

	iter = m_mapHorseNames.find(dwPlayerID);

	if ( iter != m_mapHorseNames.end() )
	{
		return iter->second.c_str();
	}
	else
	{
		return nullptr;
	}
}

void CHorseNameManager::UpdateHorseName(uint32_t dwPlayerID, const char* szHorseName, bool broadcast)
{
	if ( szHorseName == nullptr )
	{
		sys_err("HORSE_NAME: nullptr NAME (%u)", dwPlayerID);
		szHorseName = "";
	}

	sys_log(0, "HORSENAME: update %u %s", dwPlayerID, szHorseName);

	m_mapHorseNames[dwPlayerID] = szHorseName;

	if ( broadcast == true )
	{
		BroadcastHorseName(dwPlayerID, szHorseName);
	}
}

void CHorseNameManager::BroadcastHorseName(uint32_t dwPlayerID, const char* szHorseName)
{
	TPacketUpdateHorseName packet;
	packet.dwPlayerID = dwPlayerID;
	strlcpy(packet.szHorseName, szHorseName, sizeof(packet.szHorseName));

	db_clientdesc->DBPacket(HEADER_GD_UPDATE_HORSE_NAME, 0, &packet, sizeof(TPacketUpdateHorseName));
}

void CHorseNameManager::Validate(LPCHARACTER pChar)
{
	CAffect *pkAff = pChar->FindAffect(AFFECT_HORSE_NAME);

	if ( pkAff != nullptr )
	{
		if ( pChar->GetQuestFlag("horse_name.valid_till") < get_global_time() )
		{
			pChar->HorseSummon(false, true);
			pChar->RemoveAffect(pkAff);
			UpdateHorseName(pChar->GetPlayerID(), "", true);
			pChar->HorseSummon(true, true);
		}
		else
		{
			++(pkAff->lDuration);
		}
	}
}

