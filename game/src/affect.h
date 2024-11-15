#ifndef __INC_AFFECT_H
#define __INC_AFFECT_H

class CAffect
{
public:
	uint32_t dwType;
	uint16_t wApplyOn; //@fixme532
	long lApplyValue;
	uint32_t dwFlag;
	long lDuration;
	long lSPCost;
#ifdef ENABLE_NINETH_SKILL
	uint8_t bShieldDuration;
#endif
#ifdef ENABLE_AFFECT_RENEWAL
	uint32_t dwExpireTime;
#endif

	static CAffect* Acquire();
	static void Release(CAffect* p);
};

enum EAffectTypes
{
	AFFECT_NONE,
	AFFECT_MOV_SPEED = 200,
	AFFECT_ATT_SPEED,
	AFFECT_ATT_GRADE,
	AFFECT_INVISIBILITY,
	AFFECT_STR,
	AFFECT_DEX, // 205
	AFFECT_CON,
	AFFECT_INT,
	AFFECT_FISH_MIND_PILL,
	AFFECT_POISON,
	AFFECT_STUN, // 210
	AFFECT_SLOW,
	AFFECT_DUNGEON_READY,
	AFFECT_DUNGEON_UNIQUE,
	AFFECT_BUILDING,
	AFFECT_REVIVE_INVISIBLE, // 215
	AFFECT_FIRE,
	AFFECT_CAST_SPEED,
	AFFECT_HP_RECOVER_CONTINUE,
	AFFECT_SP_RECOVER_CONTINUE,
	AFFECT_POLYMORPH, // 220
	AFFECT_MOUNT,
	AFFECT_WAR_FLAG, // 222
	AFFECT_BLOCK_CHAT, // 223
	AFFECT_CHINA_FIREWORK,
	AFFECT_BOW_DISTANCE, // 225
	AFFECT_DEF_GRADE, // 226
#ifdef ENABLE_WOLFMAN_CHARACTER
	AFFECT_BLEEDING, // 227
#endif
	AFFECT_RAMADAN_ABILITY = 300,
	AFFECT_RAMADAN_RING = 301,
	AFFECT_NOG_ABILITY = 302,
	AFFECT_POTION_1 = 303,
	AFFECT_POTION_2 = 304,
	AFFECT_POTION_3 = 305,
	AFFECT_POTION_4 = 306,
	AFFECT_POTION_5 = 307,
	AFFECT_POTION_6 = 308,
	AFFECT_HOLLY_STONE_POWER = 309,

	AFFECT_PREMIUM_START = 500,
	AFFECT_EXP_BONUS = 500,
	AFFECT_ITEM_BONUS = 501,
	AFFECT_SAFEBOX = 502, // PREMIUM_SAFEBOX,
	AFFECT_AUTOLOOT = 503, // PREMIUM_AUTOLOOT,
	AFFECT_FISH_MIND = 504, // PREMIUM_FISH_MIND,
	AFFECT_MARRIAGE_FAST = 505,
	AFFECT_GOLD_BONUS = 506,
#ifdef ENABLE_AUTO_SYSTEM
	AFFECT_AUTO_USE = 507,
#endif
#ifdef ENABLE_YOHARA_SYSTEM
	AFFECT_SUNGMA_BONUS = 508,
#endif
	AFFECT_PREMIUM_END = 509,//whats teh affect id

	AFFECT_MALL = 510,
	AFFECT_NO_DEATH_PENALTY = 511,
	AFFECT_SKILL_BOOK_BONUS = 512,
	AFFECT_SKILL_NO_BOOK_DELAY = 513,
	AFFECT_HAIR = 514,
	AFFECT_COLLECT = 515,
	AFFECT_EXP_BONUS_EURO_FREE = 516,
	AFFECT_EXP_BONUS_EURO_FREE_UNDER_15 = 517,
	AFFECT_UNIQUE_ABILITY = 518,

	AFFECT_CUBE_1,
	AFFECT_CUBE_2,
	AFFECT_CUBE_3,
	AFFECT_CUBE_4,
	AFFECT_CUBE_5,
	AFFECT_CUBE_6,
	AFFECT_CUBE_7,
	AFFECT_CUBE_8,
	AFFECT_CUBE_9,
	AFFECT_CUBE_10,
	AFFECT_CUBE_11,
	AFFECT_CUBE_12,

	AFFECT_BLEND,

	AFFECT_HORSE_NAME,
	AFFECT_MOUNT_BONUS,

	AFFECT_AUTO_HP_RECOVERY = 534,
	AFFECT_AUTO_SP_RECOVERY = 535,
#ifdef ENABLE_PREMIUM_PRIVATE_SHOP
	AFFECT_PREMIUM_PRIVATE_SHOP = 536,
#endif

	AFFECT_DRAGON_SOUL_QUALIFIED = 540,
	AFFECT_DRAGON_SOUL_DECK_0 = 541,
	AFFECT_DRAGON_SOUL_DECK_1 = 542,

#ifdef ENABLE_SET_ITEM
	AFFECT_SET_ITEM = 550,
#endif

#ifdef ENABLE_AFK_MODE_SYSTEM
	AFFECT_AFK = 555,
#endif
#ifdef ENABLE_BATTLE_FIELD
	AFFECT_TARGET_VICTIM = 556,
	AFFECT_BATTLE_POTION = 557,
#endif

#ifdef ENABLE_GROWTH_PET_SYSTEM
	AFFECT_GROWTH_PET = 569,
	AFFECT_IMPOSSIBLE_ATTACK = 570,
#endif

#ifdef ENABLE_DS_SET
	NEW_AFFECT_DS_SET = 571,
#endif

#ifdef ENABLE_DEFENSE_WAVE
	AFFECT_DEFENSEWAVE_LASER = 573,
#endif

#ifdef ENABLE_FLOWER_EVENT
	AFFECT_FLOWER_EVENT = 576,
#endif

#ifdef ENABLE_SUMMER_EVENT_ROULETTE
	AFFECT_LATE_SUMMER_EVENT_BUFF = 583,
	AFFECT_LATE_SUMMER_EVENT_PRIMIUM_BUFF = 584,
#endif

#ifdef ENABLE_PASSIVE_SYSTEM
	AFFECT_PASSIVE_JOB_DECK = 593,
	//reserviert 594
#endif

#ifdef ENABLE_12ZI
	AFFECT_CZ_UNLIMIT_ENTER = 600,
#endif

#ifdef ENABLE_SET_ITEM
	AFFECT_SET_ITEM_SET_VALUE_1 = 601,
	AFFECT_SET_ITEM_SET_VALUE_2 = 602,
	AFFECT_SET_ITEM_SET_VALUE_3 = 603,
	AFFECT_SET_ITEM_SET_VALUE_4 = 604,
	AFFECT_SET_ITEM_SET_VALUE_5 = 605,
#endif

#ifdef ENABLE_MONSTER_BACK
	AFFECT_EXP_BONUS_EVENT = 610,
	AFFECT_ATT_SPEED_SLOW = 611,
#endif

#ifdef ENABLE_YOHARA_SYSTEM
	AFFECT_SUNGMA_HP = 624,
	AFFECT_SUNGMA_IMMUNE = 626,
	AFFECT_SUNGMA_MOVE = 625,
	AFFECT_SUNGMA_STR = 623,
#endif

#ifdef ENABLE_ELEMENTAL_WORLD
	AFFECT_PROTECTION_OF_ELEMENTAL = 595,
#endif

#ifdef ENABLE_ANTI_EXP_RING
	AFFECT_EXPRING = 700,
#endif
#ifdef ENABLE_GUILD_DRAGONLAIR_SYSTEM
	AFFECT_STATUE = 701,
#endif

#ifdef ENABLE_SUNG_MAHI_TOWER
	AFFECT_SUNG_MAHI_BP = 702,
	AFFECT_SUNG_MAHI_CURSE = 703,
#endif

#ifdef ENABLE_RESEARCHER_ELIXIR_FIX
	AFFECT_RESEARCHER_ELIXIR = 705,
#endif

#ifdef ENABLE_SOUL_SYSTEM
	AFFECT_SOUL_RED = 720,
	AFFECT_SOUL_BLUE = 721,
	AFFECT_SOUL_MIX = 723,
#endif

#ifdef ENABLE_ATTR_6TH_7TH_EXTEND
	AFFECT_HIT_BUFF_ENCHANT_FIRE,
	AFFECT_HIT_BUFF_ENCHANT_ICE,
	AFFECT_HIT_BUFF_ENCHANT_ELEC,
	AFFECT_HIT_BUFF_ENCHANT_WIND,
	AFFECT_HIT_BUFF_ENCHANT_DARK,
	AFFECT_HIT_BUFF_ENCHANT_EARTH,

	AFFECT_HIT_BUFF_RESIST_FIRE,
	AFFECT_HIT_BUFF_RESIST_ICE,
	AFFECT_HIT_BUFF_RESIST_ELEC,
	AFFECT_HIT_BUFF_RESIST_WIND,
	AFFECT_HIT_BUFF_RESIST_DARK,
	AFFECT_HIT_BUFF_RESIST_EARTH,

	AFFECT_HIT_BUFF_SUNGMA_STR,
	AFFECT_HIT_BUFF_SUNGMA_MOVE,
	AFFECT_HIT_BUFF_SUNGMA_HP,
	AFFECT_HIT_BUFF_SUNGMA_IMMUNE,
#endif

#ifdef ENABLE_YOHARA_SYSTEM
	AFFECT_SUNGMA_MAP_INFO = 800,
#endif
#ifdef ENABLE_QUEEN_NETHIS
	AFFECT_SUNGMA_MOVE_DEBUFF,
	AFFECT_SUNGMA_STR_DEBUFF,
#endif
#ifdef ENABLE_MULTI_FARM_BLOCK
	AFFECT_MULTI_FARM_PREMIUM = 998,
#endif
#ifdef ENABLE_AUTO_SYSTEM
	AFFECT_AUTO = 999,
#endif

	AFFECT_QUEST_START_IDX = 1000
};

enum EAffectBits
{
	AFF_NONE,						// 0	- Binary
	AFF_YMIR,						// 1	- 0
	AFF_INVISIBILITY,				// 2	- 1
	AFF_SPAWN,						// 3	- 2
	AFF_POISON,						// 4	- 3
	AFF_SLOW,						// 5	- 4
	AFF_STUN,						// 6	- 5
	AFF_DUNGEON_READY,				// 7	- 6
	AFF_DUNGEON_UNIQUE,				// 8	- 7
	AFF_BUILDING_CONSTRUCTION_SMALL,// 9	- 8
	AFF_BUILDING_CONSTRUCTION_LARGE,// 10	- 9
	AFF_BUILDING_UPGRADE,			// 11	- 10
	AFF_MOV_SPEED_POTION,			// 12	- 11
	AFF_ATT_SPEED_POTION,			// 13	- 12
	AFF_FISH_MIND,					// 14	- 13
	AFF_JEONGWIHON,					// 15	- 14
	AFF_GEOMGYEONG,					// 16	- 15
	AFF_CHEONGEUN,					// 17	- 16
	AFF_GYEONGGONG,					// 18	- 17
	AFF_EUNHYUNG,					// 19	- 18
	AFF_GWIGUM,						// 20	- 19
	AFF_TERROR,						// 21	- 20
	AFF_JUMAGAP,					// 22	- 21
	AFF_HOSIN,						// 23	- 22
	AFF_BOHO,						// 24	- 23
	AFF_KWAESOK,					// 25	- 24
	AFF_MANASHIELD,					// 26	- 25
	AFF_MUYEONG,					// 27	- 26
	AFF_REVIVE_INVISIBLE,			// 28	- 27
	AFF_FIRE,						// 29	- 28
	AFF_GICHEON,					// 30	- 29
	AFF_JEUNGRYEOK,					// 31	- 30
	AFF_TANHWAN_DASH,				// 32	- 31
	AFF_PABEOP,						// 33	- 32
	AFF_CHEONGEUN_WITH_FALL,		// 34	- 33
	AFF_POLYMORPH,					// 35	- 34
	AFF_WAR_FLAG1,					// 36	- 35
	AFF_WAR_FLAG2,					// 37	- 36
	AFF_WAR_FLAG3,					// 38	- 37
	AFF_CHINA_FIREWORK,				// 39	- 38
	AFF_HAIR,						// 40	- 39
	AFF_GERMANY,					// 41	- 40
	AFF_RAMADAN_RING,				// 42	- 41
#ifdef ENABLE_WOLFMAN_CHARACTER
	AFF_BLEEDING,					// 43	- 42
	AFF_RED_POSSESSION,				// 44	- 43
	AFF_BLUE_POSSESSION,			// 45	- 44
#endif
	AFF_DS,							// 46	- 45
#ifdef ENABLE_VIP_SYSTEM
	AFF_VIP,						// 47	- 46
#endif
#ifdef ENABLE_MONARCH_AFFECT
	AFF_KING,						// 48	- 47
#endif
#ifdef ENABLE_GUILD_DRAGONLAIR_SYSTEM
	AFF_DRAGONLAIR_STONE_UNBEATABLE_1,// 49	- 48
	AFF_DRAGONLAIR_STONE_UNBEATABLE_2,// 50	- 49
	AFF_DRAGONLAIR_STONE_UNBEATABLE_3,// 51	- 50
#endif
#ifdef ENABLE_SOUL_SYSTEM
	AFF_SOUL_RED,					// 52	- 51
	AFF_SOUL_BLUE,					// 53	- 52
	AFF_SOUL_MIX,					// 54	- 53
#endif
#ifdef ENABLE_12ZI
	AFF_CZ_UNLIMIT_ENTER,			// 55	- 54
#endif
#ifdef ENABLE_AFK_MODE_SYSTEM
	AFF_AFK,						// 56	- 55
#endif
#ifdef ENABLE_AFTERDEATH_SHIELD
	AFF_AFTERDEATH_SHIELD,			// 57	- 56
#endif
#ifdef ENABLE_BATTLE_FIELD
	AFF_BATTLE_RANKER_1,			// 58	- 57
	AFF_BATTLE_RANKER_2,			// 59	- 58
	AFF_BATTLE_RANKER_3,			// 60	- 59
	AFF_TARGET_VICTIM,				// 61	- 60
#endif
#ifdef ENABLE_NINETH_SKILL
	AFF_CHEONUN,					// 62	- 61
	AFF_CHUNWOON_MOOJUK,			// 63	- 62
#endif
#ifdef ENABLE_AUTO_SYSTEM
	AFF_AUTO_USE,					// 64	- 63
#endif

	AFF_BITS_MAX
};

#ifdef ENABLE_TARGET_AFFECT_SHOWER
enum ETargetAffects
{
	TARGET_AFFECT_POISON,
	TARGET_AFFECT_FIRE,
	TARGET_AFFECT_STUN,
	TARGET_AFFECT_SLOW,
#ifdef ENABLE_PROTO_RENEWAL
	TARGET_AFFECT_BLEEDING,
#endif
	TARGET_AFFECT_MAX_NUM,
};

const uint32_t g_arTargetAffects[TARGET_AFFECT_MAX_NUM][2] =
{
{ AFFECT_POISON, AFF_POISON },
{ AFFECT_FIRE, AFF_FIRE },
{ AFFECT_STUN, AFF_STUN },
{ AFFECT_SLOW, AFF_SLOW },
#ifdef ENABLE_PROTO_RENEWAL
{ AFFECT_BLEEDING, AFF_BLEEDING },
#endif
};
#endif

extern void SendAffectAddPacket(LPDESC d, CAffect* pkAff);

// AFFECT_DURATION_BUG_FIX
enum AffectVariable
{
	// Use when Affect needs to be infinity.
	// Emulate infinity with a very large value because it keeps reducing time.
	//// 24 bits are small, so 25 bits are used.
	// ... It is said that 25-bit is used, but 29-bit is used as a huge comment...
	// Since we are using infinite time as 60 years in the collect quest, let's make it 60 years here as well.

	INFINITE_AFFECT_DURATION = 60 * 365 * 24 * 60 * 60
};
// END_AFFECT_DURATION_BUG_FIX

#endif
