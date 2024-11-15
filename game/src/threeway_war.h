
#ifndef THREE_WAY_WAR_EVENT_
#define THREE_WAY_WAR_EVENT_

#include <unordered_map>

#include "../../common/stl.h"

struct ForkedSungziMapInfo
{
	int m_iForkedSung;
	int m_iForkedSungziStartPosition[3][2];
	std::string m_stMapName;
	int m_iBossMobVnum;
};

struct ForkedPassMapInfo
{
	int m_iForkedPass[3];
	int m_iForkedPassStartPosition[3][2];
	std::string m_stMapName[3];
};

class CThreeWayWar : public singleton<CThreeWayWar>
{
public:
	CThreeWayWar();
	virtual ~CThreeWayWar();

	void Initialize();
	bool LoadSetting(const char* szFileName);

	int GetKillScore(uint8_t empire) const;
	void SetKillScore(uint8_t empire, int count);

	void SetReviveTokenForPlayer(uint32_t PlayerID, int count);
	int GetReviveTokenForPlayer(uint32_t PlayerID);
	void DecreaseReviveTokenForPlayer(uint32_t PlayerID);

	const ForkedPassMapInfo& GetEventPassMapInfo() const;
	const ForkedSungziMapInfo& GetEventSungZiMapInfo() const;

	bool IsThreeWayWarMapIndex(int iMapIndex) const;
	bool IsSungZiMapIndex(int iMapIndex) const;

	void RandomEventMapSet();

	void RegisterUser(uint32_t PlayerID);
	bool IsRegisteredUser(uint32_t PlayerID) const;

	void onDead(LPCHARACTER pChar, LPCHARACTER pKiller);

	void SetRegenFlag(int flag) { RegenFlag_ = flag; }
	int GetRegenFlag() const { return RegenFlag_; }

	void RemoveAllMonstersInThreeWay() const;

private:
	int KillScore_[3];
	int RegenFlag_;

	std::set<int> MapIndexSet_;
	std::vector<ForkedPassMapInfo> PassInfoMap_;
	std::vector<ForkedSungziMapInfo> SungZiInfoMap_;

	std::unordered_map<uint32_t, uint32_t> RegisterUserMap_;
	std::unordered_map<uint32_t, int> ReviveTokenMap_;
};

const char* GetSungziMapPath();
const char* GetPassMapPath(uint8_t bEmpire);
int GetPassMapIndex(uint8_t bEmpire);
int GetSungziMapIndex();

int GetSungziStartX(uint8_t bEmpire);
int GetSungziStartY(uint8_t bEmpire);
int GetPassStartX(uint8_t bEmpire);
int GetPassStartY(uint8_t bEmpire);

#endif /* THREE_WAY_WAR_EVENT_ */
