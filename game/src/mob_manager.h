#ifndef __INC_METIN_II_MOB_MANAGER_H__
#define __INC_METIN_II_MOB_MANAGER_H__

typedef struct SMobSplashAttackInfo
{
	uint32_t dwTiming;
	uint32_t dwHitDistance;

	SMobSplashAttackInfo(uint32_t dwTiming, uint32_t dwHitDistance)
		: dwTiming(dwTiming)
		, dwHitDistance(dwHitDistance)
	{}
} TMobSplashAttackInfo;

typedef struct SMobSkillInfo
{
	uint32_t dwSkillVnum;
	uint8_t bSkillLevel;
	std::vector<TMobSplashAttackInfo> vecSplashAttack;
} TMobSkillInfo;

class CMob
{
public:
	CMob();

	~CMob();

	TMobTable m_table;
	TMobSkillInfo m_mobSkillInfo[MOB_SKILL_MAX_NUM];

	void AddSkillSplash(int iIndex, uint32_t dwTiming, uint32_t dwHitDistance);
};

class CMobInstance
{
public:
	CMobInstance();

	PIXEL_POSITION m_posLastAttacked;
	uint32_t m_dwLastAttackedTime;
	uint32_t m_dwLastWarpTime;

	bool m_IsBerserk;
	bool m_IsGodSpeed;
	bool m_IsRevive;
};

class CMobGroupGroup
{
public:
	CMobGroupGroup(uint32_t dwVnum)
	{
		m_dwVnum = dwVnum;
	}

	// ADD_MOB_GROUP_GROUP_PROB
	void AddMember(uint32_t dwVnum, int prob = 1)
	{
		if (prob == 0)
			return;

		if (!m_vec_iProbs.empty())
			prob += m_vec_iProbs.back();

		m_vec_iProbs.emplace_back(prob);
		m_vec_dwMemberVnum.emplace_back(dwVnum);
	}
	// END_OF_ADD_MOB_GROUP_GROUP_PROB

	uint32_t GetMember()
	{
		if (m_vec_dwMemberVnum.empty())
			return 0;

		// ADD_MOB_GROUP_GROUP_PROB
		int n = number(1, m_vec_iProbs.back());
		itertype(m_vec_iProbs) it = lower_bound(m_vec_iProbs.begin(), m_vec_iProbs.end(), n);

		return m_vec_dwMemberVnum[std::distance(m_vec_iProbs.begin(), it)];
		// END_OF_ADD_MOB_GROUP_GROUP_PROB
		//return m_vec_dwMemberVnum[number(1, m_vec_dwMemberVnum.size())-1];
	}

	uint32_t m_dwVnum;
	std::vector<uint32_t> m_vec_dwMemberVnum;

	// ADD_MOB_GROUP_GROUP_PROB
	std::vector<int> m_vec_iProbs;
	// END_OF_ADD_MOB_GROUP_GROUP_PROB
};

class CMobGroup
{
public:
	void Create(uint32_t dwVnum, std::string& r_stName)
	{
		m_dwVnum = dwVnum;
		m_stName = r_stName;
	}

	const std::vector<uint32_t>& GetMemberVector()
	{
		return m_vec_dwMemberVnum;
	}

	int GetMemberCount()
	{
		return m_vec_dwMemberVnum.size();
	}

	void AddMember(uint32_t dwVnum)
	{
		m_vec_dwMemberVnum.emplace_back(dwVnum);
	}

protected:
	uint32_t m_dwVnum;
	std::string m_stName;
	std::vector<uint32_t> m_vec_dwMemberVnum;
};

class CMobManager : public singleton<CMobManager>
{
public:
	typedef std::map<uint32_t, CMob*>::iterator iterator;

	CMobManager();
	virtual ~CMobManager();

	bool Initialize(TMobTable* table, int size);
	void Destroy();

	bool LoadGroup(const char* c_pszFileName);
	bool LoadGroupGroup(const char* c_pszFileName);
	CMobGroup* GetGroup(uint32_t dwVnum);
	uint32_t GetGroupFromGroupGroup(uint32_t dwVnum);

	const CMob* Get(uint32_t dwVnum);
	const CMob* Get(const char* c_pszName, bool bIsAbbrev);

	const iterator begin() { return m_map_pkMobByVnum.begin(); }
	const iterator end() { return m_map_pkMobByVnum.end(); }

	void RebindMobProto(LPCHARACTER ch);

#ifdef ENABLE_INGAME_WIKI
	typedef std::vector<TWikiMobDropInfo> TMobWikiInfoVector;
	typedef std::map<uint32_t, TMobWikiInfoVector> TMobWikiInfoMap;

	TMobWikiInfoMap& GetMobWikiInfoMap() { return m_wikiInfoMap; }
	TMobWikiInfoVector& GetMobWikiInfo(uint32_t vnum) { return m_wikiInfoMap[vnum]; }
#endif

	void IncRegenCount(uint8_t bRegenType, uint32_t dwVnum, int iCount, int iTime);
	void DumpRegenCount(const char* c_szFilename);

private:
	std::map<uint32_t, CMob*> m_map_pkMobByVnum;
	std::map<std::string, CMob*> m_map_pkMobByName;
	std::map<uint32_t, CMobGroup*> m_map_pkMobGroup;
	std::map<uint32_t, CMobGroupGroup*> m_map_pkMobGroupGroup;
#ifdef ENABLE_INGAME_WIKI
	TMobWikiInfoMap	m_wikiInfoMap;
#endif

	std::map<uint32_t, double> m_mapRegenCount;
};

#endif
