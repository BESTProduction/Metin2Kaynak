#ifndef __INC_METIN_II_DB_QID_H__
#define __INC_METIN_II_DB_QID_H__

enum QID
{
    QID_PLAYER,
    QID_ITEM,
    QID_QUEST,
    QID_AFFECT,
    QID_LOGIN,
    QID_SAFEBOX_LOAD,
    QID_SAFEBOX_CHANGE_SIZE,
    QID_SAFEBOX_CHANGE_PASSWORD,
    QID_SAFEBOX_CHANGE_PASSWORD_SECOND,
    QID_SAFEBOX_SAVE,
    QID_ITEM_SAVE,
    QID_ITEM_DESTROY,
    QID_QUEST_SAVE,
    QID_PLAYER_SAVE,
    QID_HIGHSCORE_REGISTER,
    QID_PLAYER_DELETE,
    QID_LOGIN_BY_KEY,
    QID_PLAYER_INDEX_CREATE,
    QID_ITEM_AWARD_LOAD,
    QID_ITEM_AWARD_TAKEN,
    QID_GUILD_RANKING,

    // MYSHOP_PRICE_LIST
    QID_ITEMPRICE_SAVE,
    QID_ITEMPRICE_DESTROY,
    QID_ITEMPRICE_LOAD_FOR_UPDATE,
    QID_ITEMPRICE_LOAD,
    // END_OF_MYSHOP_PRICE_LIST

#ifdef ENABLE_SKILL_COLOR_SYSTEM
    QID_SKILL_COLOR,
    QID_SKILL_COLOR_SAVE,
#endif
#ifdef ENABLE_GUILDSTORAGE_SYSTEM
    QID_GUILDSTORAGE_CHANGE_SIZE,
#endif
#ifdef ENABLE_PREMIUM_PRIVATE_SHOP
    QID_LOAD_PLAYER_SHOP_ITEMS,
    QID_LOAD_PLAYER_SHOPS,
#endif
#ifdef ENABLE_BATTLE_PASS_SYSTEM
    QID_EXT_BATTLE_PASS,
#endif
};

#endif
