#ifndef __MINING_H
#define __MINING_H

namespace mining
{
	LPEVENT CreateMiningEvent(LPCHARACTER ch, LPCHARACTER load, int count);
	uint32_t GetRawOreFromLoad(uint32_t dwLoadVnum);
	bool OreRefine(LPCHARACTER ch, LPCHARACTER npc, LPITEM item, int cost, int pct, LPITEM metinstone_item);
	int GetFractionCount();

	// REFINE_PICK
	int RealRefinePick(LPCHARACTER ch, LPITEM item);
	void CHEAT_MAX_PICK(LPCHARACTER ch, LPITEM item);
	// END_OF_REFINE_PICK

	bool IsVeinOfOre (uint32_t vnum);
}

#endif
