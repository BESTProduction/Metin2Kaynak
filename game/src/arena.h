#ifndef __CLASS_ARENA_MANAGER__
#define __CLASS_ARENA_MANAGER__

#include <lua.h>

enum MEMBER_IDENTITY
{
	MEMBER_NO,
	MEMBER_DUELIST,
	MEMBER_OBSERVER,

	MEMBER_MAX
};

// #ifdef ENABLE_NEWSTUFF
extern bool IsAllowedPotionOnPVP(uint32_t dwVnum);
extern bool IsLimitedPotionOnPVP(uint32_t dwVnum);
extern bool IsLimitedPotion(uint32_t dwVnum);
// #endif

class CArena
{
	friend class CArenaMap;

private:
	uint32_t m_dwPIDA;
	uint32_t m_dwPIDB;

	LPEVENT m_pEvent;
	LPEVENT m_pTimeOutEvent;

	PIXEL_POSITION m_StartPointA;
	PIXEL_POSITION m_StartPointB;
	PIXEL_POSITION m_ObserverPoint;

	uint32_t m_dwSetCount;
	uint32_t m_dwSetPointOfA;
	uint32_t m_dwSetPointOfB;

	std::map<uint32_t, LPCHARACTER> m_mapObserver;

protected:
	CArena(uint16_t startA_X, uint16_t startA_Y, uint16_t startB_X, uint16_t startB_Y);

	bool StartDuel(LPCHARACTER pCharFrom, LPCHARACTER pCharTo, int nSetPoint, int nMinute = 5);

	bool IsEmpty() const noexcept { return ((m_dwPIDA == 0) && (m_dwPIDB == 0)); }
	bool IsMember(uint32_t dwPID) const noexcept { return ((m_dwPIDA == dwPID) || (m_dwPIDB == dwPID)); }

	bool CheckArea(uint16_t startA_X, uint16_t startA_Y, uint16_t startB_X, uint16_t startB_Y);
	void Clear();

	bool CanAttack(uint32_t dwPIDA, uint32_t dwPIDB);
	bool OnDead(uint32_t dwPIDA, uint32_t dwPIDB);

	bool IsObserver(uint32_t pid);
	bool IsMyObserver(uint16_t ObserverX, uint16_t ObserverY);
	bool AddObserver(LPCHARACTER pChar);
	bool RegisterObserverPtr(LPCHARACTER pChar);

public:
	uint32_t GetPlayerAPID() noexcept { return m_dwPIDA; }
	uint32_t GetPlayerBPID() noexcept { return m_dwPIDB; }

	LPCHARACTER GetPlayerA() { return CHARACTER_MANAGER::Instance().FindByPID(m_dwPIDA); }
	LPCHARACTER GetPlayerB() { return CHARACTER_MANAGER::Instance().FindByPID(m_dwPIDB); }

	PIXEL_POSITION GetStartPointA() noexcept { return m_StartPointA; }
	PIXEL_POSITION GetStartPointB() noexcept { return m_StartPointB; }

	PIXEL_POSITION GetObserverPoint() noexcept { return m_ObserverPoint; }

	void EndDuel();
	void ClearEvent() { m_pEvent = nullptr; }
	void OnDisconnect(uint32_t pid);
	void RemoveObserver(uint32_t pid);

	void SendPacketToObserver(const void* c_pvData, int iSize);
	void SendChatPacketToObserver(uint8_t type, const char* format, ...);
};

class CArenaMap
{
	friend class CArenaManager;

private:
	uint32_t m_dwMapIndex;
	std::list<CArena*> m_listArena;

protected:
	void Destroy();

	bool AddArena(uint32_t mapIdx, uint16_t startA_X, uint16_t startA_Y, uint16_t startB_X, uint16_t startB_Y);
	void SendArenaMapListTo(LPCHARACTER pChar, uint32_t dwMapIndex);

	bool StartDuel(LPCHARACTER pCharFrom, LPCHARACTER pCharTo, int nSetPoint, int nMinute = 5);
	void EndAllDuel();
	bool EndDuel(uint32_t pid);

	int GetDuelList(lua_State* L, int index);

	bool CanAttack(LPCHARACTER pCharAttacker, LPCHARACTER pCharVictim);
	bool OnDead(LPCHARACTER pCharKiller, LPCHARACTER pCharVictim);

	bool AddObserver(LPCHARACTER pChar, uint16_t ObserverX, uint16_t ObserverY);
	bool RegisterObserverPtr(LPCHARACTER pChar, uint32_t mapIdx, uint16_t ObserverX, uint16_t ObserverY);

	MEMBER_IDENTITY IsMember(uint32_t PID);
};

class CArenaManager : public singleton<CArenaManager>
{
private:
	std::map<uint32_t, CArenaMap*> m_mapArenaMap;
#ifdef ENABLE_ARENA_FORBIDDEN_ITEMS_LIST
	std::vector<int> m_listForbidden;
#endif

public:
	bool Initialize();
	void Destroy();

	bool StartDuel(LPCHARACTER pCharFrom, LPCHARACTER pCharTo, int nSetPoint, int nMinute = 5);

	bool AddArena(uint32_t mapIdx, uint16_t startA_X, uint16_t startA_Y, uint16_t startB_X, uint16_t startB_Y);

	void SendArenaMapListTo(LPCHARACTER pChar);

	void EndAllDuel();
	bool EndDuel(uint32_t pid);

	void GetDuelList(lua_State* L);

	bool CanAttack(LPCHARACTER pCharAttacker, LPCHARACTER pCharVictim);

	bool OnDead(LPCHARACTER pCharKiller, LPCHARACTER pCharVictim);

	bool AddObserver(LPCHARACTER pChar, uint32_t mapIdx, uint16_t ObserverX, uint16_t ObserverY);
	bool RegisterObserverPtr(LPCHARACTER pChar, uint32_t mapIdx, uint16_t ObserverX, uint16_t ObserverY);

	bool IsArenaMap(uint32_t dwMapIndex);
	MEMBER_IDENTITY IsMember(uint32_t dwMapIndex, uint32_t PID);

	bool IsLimitedItem(long lMapIndex, uint32_t dwVnum);
};

#endif /*__CLASS_ARENA_MANAGER__*/

