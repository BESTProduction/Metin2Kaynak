#include "stdafx.h"
#include "LoginData.h"
#include "ClientManager.h"

CLoginData::CLoginData()
{
	m_dwKey = 0;
	memset(m_adwClientKey, 0, sizeof(m_adwClientKey));
	m_dwConnectedPeerHandle = 0;
	m_dwLogonTime = 0;
	memset(m_szIP, 0, sizeof(m_szIP));
	m_bPlay = false;
	m_bDeleted = false;
	m_lastPlayTime = 0;
	m_dwLastPlayerID = 0;

	memset(&m_data, 0, sizeof(TAccountTable));
}

TAccountTable & CLoginData::GetAccountRef()
{
	return m_data;
}

void CLoginData::SetClientKey(const uint32_t * c_pdwClientKey)
{
	thecore_memcpy(&m_adwClientKey, c_pdwClientKey, sizeof(uint32_t) * 4);
}

const uint32_t * CLoginData::GetClientKey()
{
	return &m_adwClientKey[0];
}

void CLoginData::SetKey(uint32_t dwKey)
{
	m_dwKey = dwKey;
}

uint32_t CLoginData::GetKey()
{
	return m_dwKey;
}

void CLoginData::SetConnectedPeerHandle(uint32_t dwHandle)
{
	m_dwConnectedPeerHandle = dwHandle;
}

uint32_t CLoginData::GetConnectedPeerHandle()
{
	return m_dwConnectedPeerHandle;
}

void CLoginData::SetLogonTime()
{
	m_dwLogonTime = get_dword_time();
}

uint32_t CLoginData::GetLogonTime()
{
	return m_dwLogonTime;
}

void CLoginData::SetIP(const char * c_pszIP)
{
	strlcpy(m_szIP, c_pszIP, sizeof(m_szIP));
}

const char * CLoginData::GetIP()
{
	return m_szIP;
}

void CLoginData::SetPlay(bool bOn)
{
	if (bOn)
	{
		sys_log(0, "SetPlay on %lu %s", GetKey(), m_data.login);
		SetLogonTime();
	}
	else
		sys_log(0, "SetPlay off %lu %s", GetKey(), m_data.login);

	m_bPlay = bOn;
	m_lastPlayTime = CClientManager::Instance().GetCurrentTime();
}

bool CLoginData::IsPlay()
{
	return m_bPlay;
}

void CLoginData::SetDeleted(bool bSet)
{
	m_bDeleted = bSet;
}

bool CLoginData::IsDeleted()
{
	return m_bDeleted;
}

void CLoginData::SetPremium(int * paiPremiumTimes)
{
	thecore_memcpy(m_aiPremiumTimes, paiPremiumTimes, sizeof(m_aiPremiumTimes));
}

int CLoginData::GetPremium(uint8_t type)
{
	if (type >= PREMIUM_MAX_NUM)
		return 0;

	return m_aiPremiumTimes[type];
}

int * CLoginData::GetPremiumPtr()
{
	return &m_aiPremiumTimes[0];
}

