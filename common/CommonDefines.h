/*
Author: BestStudio
Filename: CommonDefines.hpp
Project Name: Tuyobi2 SF Project
Last Revision: 01.11.2024
*/
#ifndef __INC_METIN2_COMMON_DEFINES_H__
#define __INC_METIN2_COMMON_DEFINES_H__

enum eCommonDefines {
	//DEFINES						//VALUE				//AÇIKLAMA											// VARSAYILAN
	EVENT_MOB_RATE_LIMIT			= 1000,				// Etkinlikteki canavar oraný limiti				// 1000
	MAP_ALLOW_LIMIT					= 45,				// Harita sýnýr limiti								// 32
	PRIV_EMPIRE_RATE_LIMIT			= 200,				// Ýmparatorluk oraný limiti						// 200
	PRIV_EMPIRE_TIME_LIMIT			= 60*60*24*7,		// Ýmparatorluk oraný süresi (saniye cinsinden 1 hafta)	// 60*60*24*7 [1 hafta]
	PRIV_GUILD_RATE_LIMIT			= 50,				// Lonca oraný limiti								// 50
	PRIV_GUILD_TIME_LIMIT			= 60*60*24*7,		// Lonca oraný süresi (saniye cinsinden 1 hafta)	// 60*60*24*7 [1 hafta]
	PRIV_PLAYER_RATE_LIMIT			= 100,				// Oyuncu oraný limiti								// 100
	GUILD_GRADE_NAME_MAXLEN			= 8,				// Lonca rütbe adý maksimum uzunluðu				// 8
	GUILD_GRADECOUNT				= 15,				// Lonca rütbe sayýsý								// 15
	GUILD_COMMENT_MAXCOUNT			= 12,				// Lonca yorum maksimum sayýsý						// 12
	GUILD_COMMENT_MAXLEN			= 50,				// Lonca yorum maksimum uzunluðu					// 50
	GUILD_BASEPOWER					= 400,				// Lonca temel gücü									// 400
	GUILD_POWER_PER_SKILL_LEVEL_	= 200,				// Lonca beceri baþýna güç							// 200
	GUILD_POWER_PER_LEVEL_			= 100,				// Lonca seviye baþýna güç							// 100
	GUILD_MINIMUM_LEADERSHIP_		= 40,				// Lonca minimum liderlik puaný						// 40
	GUILDWAR_MIN_MEMBER_COUNT		= 1,				// Bir GK için minimum oyuncu sayýsý				// 8
	GUILD_LADDERPOINT_PER_LEVEL		= 1000,				// Lonca seviye baþýna merdiven puaný				// 1000
	GUILD_CREATE_ITEMVNUM			= 70101,			// Lonca oluþturmak için gereken eþya numarasý		// 70101
	PARTY_CAN_JOIN_MAX_LEVEL		= 30,				// Parti katýlma için maksimum seviye				// 30
	DISAPPEARANCE_KILLED_MONSTER	= 10,				// Öldürülen canavarýn yok olma süresi				// 10
	REVIVEINVISIBLE_TIME			= 5,				// Yeniden canlanma görünmezlik süresi				// 5
	STONE_FAILURE0					= 80,				// Taþ yükseltme baþarý oraný						// 80
	STONE_FAILURE1					= 70,				// Taþ yükseltme baþarý oraný						// 70
	STONE_FAILURE2					= 60,				// Taþ yükseltme baþarý oraný						// 60
	STONE_FAILURE3					= 50,				// Taþ yükseltme baþarý oraný						// 50
	STONE_FAILURE4					= 40,				// Taþ yükseltme baþarý oraný						// 40
	SB_NEED_EXP						= 20000,			// Becerikitabý için gereken deneyim				// 20000
	SB_C_NEED_EXP					= 20000,			// 9. beceriler için gereken deneyim				// 20000
	OWNERSHIP_EVENT_TIME			= 300,				// Etkinlik sahiplilik süresi						// 300
	MIN_ADDON_FKS					= -30,				// Minimum FKS deðeri								// -30
	MAX_ADDON_FKS					= 30,				// Maksimum FKS deðeri								// 30
	MIN_ADDON_DSS					= 32767,			// Minimum DSS deðeri								// 32767
	MAX_ADDON_DSS					= 32767,			// Maksimum DSS deðeri								// 32767
	SERVER_STATE_CACHE_EXPIRATION	= 5*60,				// Kanal durumu güncelleme süresi					// 5*60 [5 dakika]
	PC_MOVE_SPEED					= 100,				// Oyuncu hareket hýzý								// 100
	PC_ATT_SPEED					= 100,				// Oyuncu saldýrý hýzý								// 100
	PC_CAST_SPEED					= 100,				// Oyuncu büyü hýzý									// 100
	PC_MAX_ATT_SPEED				= 170,				// Maksimum oyuncu saldýrý hýzý						// 170
	MOB_MAX_ATT_SPEED				= 250,				// Maksimum canavar saldýrý hýzý					// 250
	PC_MAX_MOVE_SPEED				= 200,				// Maksimum oyuncu hareket hýzý						// 200
	MOB_MAX_MOVE_SPEED				= 250,				// Maksimum canavar hareket hýzý					// 250
	ITEM_FLOOR_TIME					= 30,				// Eþyalarýn yerde kalma süresi						// 30
	ITEM_DEST_TIME_AUTOITEM			= 300,				// Otomatik verilen eþyanýn yok olma süresi			// 300
	ITEM_DEST_TIME_DROPITEM			= 150,				// Düþürülen eþyanýn yok olma süresi				// 150
	ITEM_DEST_TIME_DROPGOLD			= 300,				// Düþürülen altýnýn yok olma süresi				// 300

	MAX_RANK_POINTS					= 20000,			// Maksimum sýralama puaný							// 20000
	START_LEVEL						= 1,				// Baþlangýç seviyesi								// 1
	START_GOLD						= 0,				// Baþlangýç altýný									// 0
	START_WON						= 0,				// Baþlangýç won									// 0		[ENABLE_CHEQUE_SYSTEM]
	START_GEM						= 0,				// Baþlangýç gaya									// 0		[ENABLE_GEM_SYSTEM]
	DROPABLE_GOLD_LIMIT				= 100000,			// Düþürülebilir altýn limiti						// 1000
	ITEM_COUNT_LIMIT				= 250,				// Maks. yýðýn eþyasý sayýsý						// 200
	ITEM_BONUS_CHANGE_TIME			= 60,				// Eþya bonus deðiþiklik süresi						// 60
	STATUSPOINT_GET_LEVELLIMIT		= 90,				// Seviye sýnýrýnda alýnan stat puaný				// 90
	STATUSPOINT_SET_MAXVALUE		= 90,				// Stat puaný maksimum deðeri						// 90
	SHOUT_LIMIT_LEVEL				= 15,				// Shout yapabilmek için gerekli minimum seviye		// 15
	PLAYER_MAX_LEVEL				= 120,				// Maksimum oyuncu seviyesi							// 99
	CONQUEROR_MAX_LEVEL				= 30,				// Maksimum fetih seviyesi							// 30		[ENABLE_YOHARA_SYSTEM]
	SKILLBOOK_NEXT_READ_MIN			= 28800,			// Beceri kitabý için gereken minimum deneyim		// 28800
	SKILLBOOK_NEXT_READ_MAX			= 43200,			// Beceri kitabý için gereken maksimum deneyim		// 43200
	RANGE_PICK						= 600,				// Eþya alma menzili								// 300
	SUNGMA_ATTR_PROB				= 40,				// Sungma eþyalarýnýn deðiþme olasýlýðý				// 40
	PREMIUM_PRIVATE_SHOP_DEFAULT_TIME = 60 * 24,		// Offline dükkân açma süresi [1 gün]				// 60 * 24

	CL_TRANSMUTATION_PRICE			= 15000000,			// Transmutasyon maliyeti							// 15000000	[ENABLE_CHANGE_LOOK_SYSTEM]
	PET_INCUBATRICE_COST			= 100000,			// Kuluçka maliyeti									// 100000	[ENABLE_GROWTH_PET_SYSTEM]
	IMMUNE_PCT						= 90,				// Savunma aktifken baðýþýklýk oraný				// 90		[ENABLE_IMMUNE_PERC]
	SHAM_ASSA_ATT_BONUS				= 15,				// PvE için % saldýrý bonusu						// 15		[ENABLE_SHAM_ASSA_ATT_BONUS]
	KK_ATT_BONUS_AGAINST_NH			= 10,				// PvP için % saldýrý bonusu						// 10		[ENABLE_KK_ATT_BONUS_AGAINST_NH]
	ANNOUNCEMENT_REFINE_SUCCES_MIN_LEVEL	= 9,		// Kaçýncý seviyede duyuru yapýlacaðý				// 9		[ENABLE_ANNOUNCEMENT_REFINE_SUCCES]
	ITEM_LEVEL_LIMIT				= 64,				// Gösterilmeyen seviye sýnýrý						// 64		[ENABLE_ANNOUNCEMENT_REFINE_SUCCES]
	MEMBER_COUNT_BONUS				= 6,				// Lonca üye sayýsýna göre bonus					// 6		[ENABLE_GUILDRENEWAL_SYSTEM]
	AFK_TIME_LIMIT					= 3,				// AFK modu süresi (dakika cinsinden)				// 3		[ENABLE_AFK_MODE_SYSTEM]
	SOULUNBIND_TIME					= 72,				// Ruh çözme süresi [saat cinsinden]				// 72		[ENABLE_SEALBIND_SYSTEM]
	AFTERDEATH_SHIELD_DURATION		= 3,				// Ölüm sonrasý koruma süresi (saniye cinsinden)	// 15		[ENABLE_AFTERDEATH_SHIELD]
	OFFLINESHOP_OPEN_TIME			= 10,				// Offline dükkânýn açýk kalma süresi				// 60*24*3	[ENABLE_PREMIUM_PRIVATE_SHOP]
	MAX_FARMING_ACCOUTS				= 2,				// HWID baþýna maksimum hesap sayýsý				// 2		[ENABLE_MULTI_FARM_BLOCK]
	BATTLE_FIELD_KILL_TIME			= 60,				// Savaþ alanýnda öldürme süresi (saniye)			// 600		[ENABLE_BATTLE_FIELD]
	DS_ATTR_CHANGE_PRICE			= 500000,			// DS nitelik deðiþtirme maliyeti					// 500000	[ENABLE_DS_CHANGE_ATTR]
	PERCENT_ADD_BONUS_ELEMENTS_SPELL = 25,				// Element baþarý oraný								// 50		[ENABLE_REFINE_ELEMENT]
	SOUL_COLLECT_PERC				= 10,				// Ruh toplama oraný								// 10		[ENABLE_SUMMER_EVENT_ROULETTE]
	FISHING_NEED_CATCH				= 3,				// Balýk tutma için gereken yakalama sayýsý			// 3

	// Zindan Ayarlarý
	MELEY_MIN_LVL					= 3,				// Meley zindaný için minimum seviye				// 3		[ENABLE_GUILD_DRAGONLAIR_SYSTEM]
	MELEY_LADDER_POINTS_COST		= 600,				// Meley zindaný giriþ puaný maliyeti				// 600		[ENABLE_GUILD_DRAGONLAIR_SYSTEM]
	MELEY_LADDER_POINTS_RETURN		= 300,				// Meley zindaný puaný geri iadesi					// 300		[ENABLE_GUILD_DRAGONLAIR_SYSTEM]
	MELEY_COOLDOWN_DUNGEON			= 10800,			// Meley zindaný bekleme süresi						// 10800	[ENABLE_GUILD_DRAGONLAIR_SYSTEM]
	WEATHER_REFRESH_TIMER			= 60,				// Hava durumu güncelleme süresi [saniye]			// 60 * 5	[ENABLE_WEATHER_INFO]
	WEATHER_RAIN_PERC				= 5,				// Yaðmur olasýlýðý									// 1		[ENABLE_WEATHER_INFO]
	RAIN_SNOW_ACTIVE_TIME			= 30,				// Yaðmur/snow aktif kalma süresi [dakika]			// 30		[ENABLE_WEATHER_INFO]

	CHECK_PICKUP_HACK				= 10,				// Eþya alým hilesini kontrol etme					// 10
	PICKUP_RANGE					= 150,				// Eþya alým mesafesi								// 300		[ENABLE_CHECK_PICKUP_HACK]
	PICKUP_RANGE_TOLERANCE			= 100,				// Eþya alým toleransý								// 150		[ENABLE_CHECK_PICKUP_HACK]
};

/*
//------Sunucu Komutlarý------>
ENABLE_EVENT_BANNER_FLAG							// /banner 1 easter — Paskalya etkinliði için banner etkinleþtirme komutu
ENABLE_BATTLE_FIELD									// /e battlefield_status 1 — Savaþ alaný durumu komutu
*/

#define __FAKE_PLAYER__

//------TAMAMLANMAMIÞ------>
#define ENABLE_PULSE_MANAGER						// Olaylarýn zamanlanmýþ kontrolünü yöneten yapý (tamamlanmamýþ)
#define ENABLE_SKILL_TABLE_RENEWAL					// Skill (beceri) tablosunun güncellenmesi (tamamlanmamýþ)


//////////////////////////////////////////////////[SADECE OYUN KAYNAÐI]//////////////////////////////////////////////////
#define ENABLE_MEMORY_LEAK_FIX						// Bellek sýzýntýsýný önlemek için düzeltme etkin
//#define ENABLE_HAND_SHAKE_LIMIT					// El sýkýþma komut sýnýrý
#define ENABLE_PROXY_IP								// Proxy IP desteðini etkinleþtirir
/* 
BIND_IP: <Özel IPv4 IP> (Özel IP sýnýfýnda, "ifconfig" komutuyla makinenin IP'sini kontrol edebilirsiniz)
PROXY_IP: <Genel IPv4 IP> (IP'nizi öðrenmek için https://www.whatismyip.com gibi bir site kullanýn)
*/

//------GÜVENLÝK------>
#define ENABLE_PORT_SECURITY							// db_port, p2p_port ve uzaktan yönetim sayfasý açýklarýný engeller
#define ENABLE_MAIN_HACK								// Ana hack korumasý
//#define ENABLE_CSHIELD								// CShield korumasýný etkinleþtir
	#ifdef ENABLE_CSHIELD								// CShield korumasýný etkinleþtir
		#define ENABLE_CHECK_GHOSTMODE					// Oyuncunun hayalet mod kullanýp kullanmadýðýný kontrol eder
		#define ENABLE_CHECK_WALLHACK					// Oyuncu konumunu duvar hilesi için kontrol eder
		#define ENABLE_CHECK_PICKUP_HACK PICKUP_RANGE+PICKUP_RANGE_TOLERANCE // Oyuncunun eþya toplama hilesi kullanýp kullanmadýðýný kontrol eder. // Önemli: CPythonPlayer::SendClickItemPacket’teki toplama süresini kontrol edin. Eðer bu özellik yoksa, bu tanýmý devre dýþý býrakýn.
		#define ENABLE_CHECK_ATTACKSPEED_HACK			// Oyuncunun çok hýzlý saldýrýp saldýrmadýðýný kontrol eder
		#define ENABLE_CHECK_MOVESPEED_HACK				// Oyuncunun çok hýzlý hareket edip etmediðini kontrol eder
		#define ENABLE_CHECK_WAIT_HACK					// Oyuncunun bekleme hilesi kullanýp kullanmadýðýný kontrol eder
		#define ENABLE_CHECK_VALID_FISH_POSITION		// Balýk tutma pozisyonunun geçerliliðini kontrol eder
		#define ENABLE_CHECK_ANTI_SAFEZONE				// Güvenli bölgeye karþý koruma kontrolü
		#define ENABLE_CHECK_SKILL_HACK					// Oyuncunun yetenek hilesi kullanýp kullanmadýðýný kontrol eder
	#endif
#define FLUSH_AT_SHUTDOWN								// Kapanýþta önbelleði temizler
//#define ENABLE_SYSLOG_PACKET_SENT						// Gönderilen Paket Baþlýðýný Syslog’a gönderir


//--------SÝSTEMLER------->


//--------SEÇENEKLER------->
#define ENABLE_REVERSED_FUNCTIONS					// Resmi fonksiyonlar etkin
#define ENABLE_SYNCPOSITION_DISCONNECT_FIX			// Pozisyon senkronizasyonu baðlantý kesme hatasýný giderir
#define ENABLE_EXTENDED_RELOAD						// Geniþletilmiþ yeniden yükleme komutlarý
#define ENABLE_CMS_ITEMSHOP							// Oyun içi eþya maðazasý
#define ENABLE_GM_BLOCK								// GM (Yönetici) engelleme sistemi
#define ENABLE_CHECK_WINDOW_RENEWAL					// Pencere yenileme kontrolü
#define ENABLE_PVP_BALANCE							// PvP dengesi, resmi oyun gibi
#define ENABLE_AFFECT_RENEWAL						// Etki yenileme sistemi
#define ENABLE_REFINE_ABILITY_SKILL					// Yetenek geliþtirme sistemi (Schmiedeskill)
#define ENABLE_ATTRIBUTE_CHANGE_ON_START_ITEM		// Baþlangýç eþyasýnda özellik deðiþikliði
#define ENABLE_ANNOUNCEMENT_REFINE_SUCCES			// Baþarýlý geliþtirmeleri duyurma
#define ENABLE_ANNOUNCEMENT_LEVELUP					// Seviye atlama duyurularý
#define ENABLE_AGGROMOB_SAFEZONE_SKIP				// Safezone (güvenli bölge) içindeki düþmanlarý atlama
#define ENABLE_GUILDLAND_INACTIVITY_DELETE			// Lonca topraklarýnýn hareketsizlikte silinmesi
#define ENABLE_EFFECT_FOR_TRADE						// Tamamlanan takas sonrasý efekt
#define ENABLE_BLOCK_SKILL_OXEVENT					// OX etkinliðinde yetenek kullanýmý engelleme
#define ENABLE_BLOCK_BUFF_IN_MAP					// Belirli haritalarda buff (güçlendirme) kullanýmýný engelleme
#define ENABLE_HORSESKILLS_ON_MOUNTS				// Bineklerde at yeteneklerinin kullanýmý
#define DISABLE_RIDE_ON_SPECIAL_MAP					// Özel haritalarda binme kýsýtlamasý
#define ENABLE_RITUAL_STONE							// Ritüel taþý etkinliði
#define ENABLE_SEAL_OF_GOD							// Tanrýlarýn mührü sistemi
#define ENABLE_SHAMAN_PARTY_BUFF_SYSTEM				// Þaman 1 týklama grup buff’ý ve kendine buff
#define ENABLE_SHAM_ASSA_ATT_BONUS					// Þaman ve suikastçýlara PvE'de % saldýrý bonusu
//#define ENABLE_KK_ATT_BONUS_AGAINST_NH			// PvP sistemi: KK'nin NH'ye karþý ekstra hasarý
#define ENABLE_DROP_GOLD							// Altýn düþürme sistemi
#define ENABLE_GOLD_MULTIPLIER						// Altýn çarpan sistemi
#define ENABLE_GOLD10_PCT							// Altýn %10 çarpaný
#define ENABLE_BLOCK_CHEST_INVENTORY_FULL			// Envanter dolu olduðunda sandýk açmayý engelleme
//#define ENABLE_CANT_CREATE_SHOPS_IN_OTHER_EMPIRE	// Diðer imparatorluklarda dükkân açmayý engeller
#define ENABLE_ARENA_FORBIDDEN_ITEMS_LIST			// Almanya klasöründen yasaklý eþya listesi
#define ENABLE_HORSE_APPEARANCE						// Veritabanýnda saklanan at görünümleri
//#define ENABLE_MOUNT_ENTITY_REFRESH				// Binilen varlýklarýn yenilenmesi
#define ENABLE_EXTEND_ITEM_AWARD					// Maðaza eþyalarýna bonus eklenebilir
//#define MOB_DROP_ITEM_RENEWAL						// Haritaya göre eþya düþürme sistemi etkin
//#define ENABLE_CUBE_COPY_ATTR						// Küpte özellik kopyalamayý etkinleþtirir
#define ENABLE_PORTAL_NAMES							// Portal isimlerini gösterir
#define ENABLE_MAP_NAME_INFO						// Harita isimleri sohbet ekranýnda görüntülenir
//#define ENABLE_CLEAN_BANNED_PLAYER_DATA			// Yasaklanan oyuncu verilerini temizleme
#define ENABLE_SET_STATES							// Durumlarý komutla ayarlama
	#ifdef ENABLE_SET_STATES
		#define SET_STATES_PRIVILEGES GM_PLAYER		// Yetkiler: GM_PLAYER, GM_LOW_WIZARD
	#endif
#define ENABLE_DUNGEON_MUSIC_FIX					// Zindan müziði düzeltmesi
#define ENABLE_POISON_FIX							// Zehir etkisi düzeltmesi
//#define DISABLE_STONE_LV20_DROP					// 20. seviyede taþ düþürmeyi engeller
//#define DISABLE_BOSS_LV25_DROP					// 25. seviyede patron düþürmeyi engeller



//////////////////////////////////////////////////[OYUN KAYNAÐI VE ÝKÝLÝ DOSYALAR]//////////////////////////////////////////////////
//-----GENEL_KONULAR---->
//#define ENABLE_SEQUENCE_SYSTEM						//@fixme426
#define ENABLE_HWID_BAN									// HWID Yöneticisi (donaným kimliði ile ban sistemi)
	#ifdef ENABLE_HWID_BAN
		//#define ENABLE_HWID_BAN_EXTENDED				// Baþka bir HWID ile giriþ yapýlmaya çalýþýldýðýnda engeller; ekstra sýfýrlama fonksiyonu gerektirir
		#define ENABLE_MULTI_FARM_BLOCK					// Çift hesapla farm yapmayý engelleme
		#define GM_UNBAN_RIGHT 4						// Yasak kaldýrma yetkisi seviyesi
		#define GM_BAN_RIGHT 4							// Yasaklama yetkisi seviyesi
		#define GM_HWID_BAN_RIGHT 4						// HWID ile yasaklama yetkisi seviyesi
		#define GM_DELETE_HWID_BAN_RIGHT 4				// HWID yasaðýný kaldýrma yetkisi seviyesi
		#define GM_TOTAL_HWID_BAN_RIGHT 4				// Genel HWID yasaklama yetkisi seviyesi
	#endif


//-----PROTO_YAPISI---->
#define ENABLE_PROTO_RENEWAL							// Resmi Proto Yapýsý
#define ENABLE_PROTO_RENEWAL_CUSTOM						// Özel sistemler için Proto deðiþiklikleri
#define ENABLE_NEW_DISTANCE_CALC						// Mesafe hesaplama yenilemesi


//------KARAKTERLER------>
#define ENABLE_PLAYER_PER_ACCOUNT5						// Bir hesapta 5 karaktere izin verir
#define ENABLE_WOLFMAN_CHARACTER						// Kurt Adam karakteri
	#ifdef ENABLE_WOLFMAN_CHARACTER
		//#	define USE_MOB_BLEEDING_AS_POISON			// Kanama etkisi devre dýþý býrakýlýr ve zehir olarak iþlev görür
		//#	define USE_MOB_CLAW_AS_DAGGER				// Pençe saldýrýsý devre dýþý býrakýlýr ve hançer olarak iþlev görür
		//#	define USE_ITEM_BLEEDING_AS_POISON			// Zehir bonusu kanama etkisini savunabilir (kanama devre dýþý býrakýlýr)
		//#	define USE_ITEM_CLAW_AS_DAGGER				// Hançer savunmasý pençe saldýrýsýný savunabilir (pençe devre dýþý býrakýlýr)
		#define USE_WOLFMAN_STONES						// Kurt adam taþlarý metin taþlarýndan düþebilir
		#define USE_WOLFMAN_BOOKS						// Kurt adam beceri kitaplarý düþebilir
		#define USE_LYCAN_CREATE_POSITION				// Etkinleþtirilirse, kurt adam karakter oluþturma sýrasýnda kendi köyüne taþýnýr
	#endif


//--------SÝSTEMLER------->
#define ENABLE_MOB_SCALE							// mob_proto.txt üzerinden canavar ölçeklendirmesi
#define NEW_SELECT_CHARACTER						// Son oynanan karakteri seçme
#define WJ_SHOW_MOB_INFO							// Canavar seviyesi/Aggro gösterimi
#define WJ_ENABLE_TRADABLE_ICON						// Ticaret yapýlamayan eþyalarý gösterme
#define ENABLE_SWAP_SYSTEM							// Envanterdeki eþyalarý takas etme sistemi
#define ENABLE_PET_SYSTEM							// Pet sistemi
	#ifdef ENABLE_PET_SYSTEM
		#define PET_AUTO_PICKUP						// Pet otomatik eþya toplama
	#endif
#define ENABLE_GROWTH_PET_SYSTEM					// Geliþen pet sistemi
	#ifdef ENABLE_GROWTH_PET_SYSTEM
		#define ENABLE_PET_ATTR_DETERMINE			// Petin özellik belirleme sistemi
		#define ENABLE_PET_PRIMIUM_FEEDSTUFF		// Pet için premium yem
	#endif
#define ENABLE_ACCE_COSTUME_SYSTEM					// Kemer sistemi
#define ENABLE_AURA_SYSTEM							// Aura sistemi
	#ifdef ENABLE_AURA_SYSTEM
		#define ENABLE_AURA_BOOST					// Aura güçlendirme
	#endif
#define ENABLE_YOHARA_SYSTEM						// Fatih seviyesi + Sungma
	#ifdef ENABLE_YOHARA_SYSTEM
		#define ENABLE_NINETH_SKILL					// 9. beceri
		//#define ENABLE_PASSIVE_SYSTEM				// Kalýntý penceresi [tamamlanmamýþ]
	#endif
#define ENABLE_GLOVE_SYSTEM							// Eldiven eþyasý sistemi
	#ifdef ENABLE_GLOVE_SYSTEM
		#define ENABLE_GLOVE_ITEM_ATTR				// item_attr tablosu
	#endif
#define ENABLE_REFINE_ELEMENT						// Element set sistemi [Worldard]
#define ENABLE_GUILDSTORAGE_SYSTEM					// Lonca deposu
#define ENABLE_SPECIAL_INVENTORY					// Özel envanter [Sanii]
#define ENABLE_DS_GRADE_MYTH						// Mitolojik derece
#define ENABLE_DS_CHANGE_ATTR						// Ejderha Taþý niteliðini deðiþtirme
#define ENABLE_DS_REFINE_WINDOW						// Ejderha Taþý geliþtirme penceresi
#define ENABLE_DS_SET								// Ejderha Taþý set sistemi
#define ENABLE_MOUNT_COSTUME_SYSTEM					// Binek kostüm yuvasýný etkinleþtir
	#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
		#define ENABLE_MOUNT_PROTO_AFFECT_SYSTEM	// Binek prototipi efekt sistemi
		#define ENABLE_CHANGE_LOOK_MOUNT			// Binek görünüm deðiþtirme
		#define ENABLE_MOUNT_CHECK					// Binek kontrol sistemi
	//#	define ENABLE_NO_WAIT_TO_RIDE				// Binmeye bekleme süresini kaldýr
	#endif
#define ENABLE_WEAPON_COSTUME_SYSTEM				// Silah kostüm yuvasýný etkinleþtir
	#ifdef ENABLE_WEAPON_COSTUME_SYSTEM
		#define ENABLE_ITEM_ATTR_COSTUME			// Silah, beden, saç kostümü için nitelik/ender özellikler
	#endif
#define ENABLE_USE_COSTUME_ATTR						// Kostüm için nitelik deðiþtirme bonusunu etkinleþtir
#define ENABLE_MOVE_COSTUME_ATTR					// Kostüm bonus transferi
	#ifdef ENABLE_MOVE_COSTUME_ATTR
		#define ENABLE_MOVE_COSTUME_ACCE_ATTR		// Kostüm aksesuar niteliklerini transfer etme
	#endif
#define ENABLE_HIDE_COSTUME_SYSTEM					// Kostüm tasarýmýný gizleme/gösterme
#define ENABLE_CHANGED_ATTR							// Nitelik deðiþtirme sistemi
#define ENABLE_MAGIC_REDUCTION_SYSTEM				// Büyü direnç azaltma bonusunu etkinleþtir
	#ifdef ENABLE_MAGIC_REDUCTION_SYSTEM
		#define USE_MAGIC_REDUCTION_STONES			// Metin taþlarýndan büyü direnç azaltma taþý düþme
	#endif
#define ENABLE_PENDANT								// Kolye eþya yuvasý
	#ifdef ENABLE_PENDANT
		#define ENABLE_ELEMENT_ADD					// Kolye için element ekleme
		#define ENABLE_PENDANT_ITEM_ATTR				// Kolye için nitelik/ender özellik bonuslarýný etkinleþtir
	#endif
#define ENABLE_MULTI_LANGUAGE_SYSTEM				// Çoklu dil sistemi [Sonitex]
#define ENABLE_SEALBIND_SYSTEM						// Ruh baðlama
#define ENABLE_CHEQUE_SYSTEM						// Won/Çek sistemi
	#ifdef ENABLE_CHEQUE_SYSTEM
		#define ENABLE_CHEQUE_EXCHANGE_WINDOW		// xP3ng3rx Won -> Yang / Yang -> Won deðiþim penceresi
	#endif
#define ENABLE_GACHA_SYSTEM							// Gacha Sistemi
#define ENABLE_BIOLOG_SYSTEM						// Biyolog Sistemi
#define ENABLE_AUTO_SYSTEM							// Otomatik Avlanma
	#ifdef ENABLE_AUTO_SYSTEM
		#define ENABLE_AUTO_RESTART_EVENT			// Otomatik avlanma için yeniden baþlatma etkinliði
	#endif
#define ENABLE_RESEARCHER_ELIXIR_FIX				// Araþtýrmacý iksir düzeltmesi
#define ENABLE_678TH_SKILL							// 6., 7. ve 8. Pasif Beceriler
#define ENABLE_78TH_SKILL							// 7. ve 8. Pasif Beceriler
#define ENABLE_PASSIVE_ATTR							// Pasif nitelikler
	#ifdef ENABLE_PASSIVE_ATTR
		#define ENABLE_PRECISION					// Hassasiyet
		#define ENABLE_CHARISMA						// Karizma
		#define ENABLE_INSPIRATION					// Ýlham
	#endif
#define ENABLE_SWITCHBOT							// Efsunbotu [Sanii]
	#ifdef ENABLE_SWITCHBOT
		//#define ENABLE_IGNORE_TYPE_GREEN_ATTR_ITEM					// Yeþil nitelikli öðeleri yok sayma
		#define ENABLE_SWITCHBOT_PM										// PM'den switcher bitirme bildirimi
	#endif
#define ENABLE_BATTLE_PASS_SYSTEM										// Battle pass sistemi
	#ifdef ENABLE_BATTLE_PASS_SYSTEM
		#define RESTRICT_COMMAND_GET_INFO			GM_LOW_WIZARD		// Bilgi komutu kýsýtlamasý
		#define RESTRICT_COMMAND_SET_MISSION		GM_IMPLEMENTOR		// Görev ayarlama kýsýtlamasý
		#define RESTRICT_COMMAND_PREMIUM_ACTIVATE	GM_IMPLEMENTOR		// Premium etkinleþtirme kýsýtlamasý
	#endif
#define ENABLE_CHANGE_LOOK_SYSTEM						// Görünüm deðiþtirme (Transmutasyon)
#define ENABLE_ATTR_6TH_7TH								// 6. ve 7. Bonus Tablosu
	#ifdef ENABLE_ATTR_6TH_7TH
		#define ENABLE_ATTR_6TH_7TH_EXTEND				// Yeni resmi bonuslar
		#define ENABLE_ATTR_6TH_7TH_ATTR_TABLE			// Nitelik tablosu
	#endif
#define ENABLE_SKILL_COLOR_SYSTEM						// Beceri renk deðiþimi [Owsap]
#define ENABLE_CUBE_RENEWAL								// Küp Yenileme
	#ifdef ENABLE_CUBE_RENEWAL
		#define ENABLE_CUBE_RENEWAL_COPY				// Nitelikleri kopyalama yeteneði
	#endif
#define ENABLE_VIP_SYSTEM								// VIP Sistemi
	#ifdef ENABLE_VIP_SYSTEM
		//#define ENABLE_SWITCHBOT_FOR_VIP					// Sadece VIP'ler Switchbot kullanabilir
		//#define ENABLE_SHAM_ASSA_ATT_BONUS_FOR_VIP		// Sadece VIP'ler Þaman/Ninja PvE bonusu alýr
		//#define ENABLE_KK_ATT_BONUS_AGAINST_NH_FOR_VIP	// Sadece VIP'ler KK_ATT bonusunu NH'ye karþý alýr
		//#define ENABLE_YANG_BOMB_FOR_VIP					// Sadece VIP'ler YangBomb özelliðini kullanabilir
		//#define ENABLE_TRANSMUTATION_FOR_VIP				// Sadece VIP'ler Transmutasyon yapabilir
		//#define ENABLE_DROP_INFO_FOR_VIP					// Sadece VIP'ler düþen eþyalar hakkýnda bilgi alýr
	#endif

#define ENABLE_PREMIUM_PRIVATE_SHOP								// Premium kiþisel dükkan sistemi
	#ifdef ENABLE_PREMIUM_PRIVATE_SHOP
		#define ENABLE_OPEN_SHOP_WITHOUT_BAG					// Çanta olmadan dükkan açma
		#define ENABLE_OPEN_SHOP_ONLY_IN_MARKET					// Sadece pazarda dükkan açma izni
		#define ENABLE_OPEN_SHOP_WITH_PASSWORD					// Þifre ile dükkan açma
		#define ENABLE_PREMIUM_PRIVATE_SHOP_TIME				// Dükkan açýk kalma süresi ayarý [SHOP_ACTIVITY etkin deðilse]
		#define ENABLE_PREMIUM_PRIVATE_SHOP_TEXTTAIL			// Dükkan açýklama baþlýklarý
		#define ENABLE_SHOP_NO_SPEND_MIN_IF_ONLINE				// Çevrimiçiyken dükkan açma süresi harcamaz [Gelecekte tekrar gözden geçirilecek]
		//#define ENABLE_PRIVATESHOP_SYSTEM_ALWAYS_SILK			// Tüm satýþlar Silk olarak
		//#define ENABLE_PRIVATE_SHOP_SEARCH_NEED_ITEM			// Arama sisteminde özel gereksinimler
		//#define ENABLE_PRIVATSHOP_EXTENSIONS					// Ek özellikler
		#define ENABLE_PRIVATESHOP_SEARCH_SYSTEM				// Kiþisel dükkan arama sistemi
		#define ENABLE_PRIVATESHOP_SEARCH_PACKETFLOOD_TEMP_FIX	// Maksimum 800 giriþ sýnýrý [Client çökmesini önlemek için paket yüklemesi azaltýlmýþtýr]
	#endif
#define ENABLE_MYSHOP_DECO							// Dükkan dekorasyon sistemi
	#ifdef ENABLE_MYSHOP_DECO
		#define ENABLE_MYSHOP_DECO_PREMIUM			// Premium dükkan dekorasyonlarý
		//#define ENABLE_MYSHOP_DECO_EXTENSION		// Ek dekorasyon özellikleri
	#endif

#define ENABLE_MAILBOX								// Posta kutusu sistemi
#define ENABLE_DESTROY_SYSTEM						// Eþyalarý yok etme sistemi
//#define ENABLE_GROUP_DAMAGE_WEAPON				// Grup hasar sistemi
#define ENABLE_INGAME_WIKI							// Oyun içi bilgi rehberi
#define ENABLE_QUIVER_SYSTEM						// Ok yeleði sistemi
#define ENABLE_DUNGEON_INFO_SYSTEM					// Zindan bilgi sistemi
#define ENABLE_MOVE_CHANNEL							// Kanal deðiþtirme sistemi
#define ENABLE_QUEST_RENEWAL						// Görev sayfasý yenileme
#define ENABLE_PARTY_MATCH							// Parti eþleþme sistemi
#define ENABLE_FISHING_RENEWAL						// Balýkçýlýk sistemi yenilemesi
#define ENABLE_WEATHER_INFO							// Otomatik hava durumu yükleme


/*-----MiniGame*///----->
#define ENABLE_EVENTS										// Oyun içi etkinlikler
	#ifdef ENABLE_EVENTS
		#define ENABLE_EVENT_MANAGER						// Etkinlik Bilgi Panosu
		#define ENABLE_EVENT_BANNER_FLAG					// Etkinlik Banner'ý
		#define ENABLE_MINI_GAME							// Mini Etkinlikler Baþlýðý

		// Resmi Etkinlikler
		//#define ENABLE_LUCKY_EVENT						// kullanýlmýyor
		#define ENABLE_MINI_GAME_OKEY_NORMAL				// Okey Kart Etkinliði
		//#define ENABLE_MINI_GAME_YUTNORI					// Cadýlar Bayramý
		#define ENABLE_MONSTER_BACK							// Boss Avcýsý
			#ifdef ENABLE_MONSTER_BACK
				#define ENABLE_ACCUMULATE_DAMAGE_DISPLAY	// Hasar Toplama Gösterimi
				//#define ENABLE_10TH_EVENT					// 10. Yýl Etkinliði
			#endif
		#define ENABLE_EASTER_EVENT							// Paskalya Etkinliði
		#define ENABLE_SUMMER_EVENT							// kullanýlmýyor
		#define ENABLE_2017_RAMADAN							// Ramazan Etkinliði [Sunucu Tarafý]
		#define ENABLE_NEW_HALLOWEEN_EVENT					// Yeni Cadýlar Bayramý Etkinliði [Sunucu Tarafý]
		#define ENABLE_SOUL_SYSTEM							// Ruh Sistemi [Owsap]
		#define ENABLE_2016_VALENTINE						// Sevgililer Günü Etkinliði
		#define ENABLE_FISH_EVENT							// Balýk Bulmaca Etkinliði
		#define ENABLE_FLOWER_EVENT							// Çiçek Etkinliði
		#define ENABLE_MINI_GAME_CATCH_KING					// Kralý Yakala Etkinliði
		#define ENABLE_GEM_SYSTEM							// Gaya Sistemi
			#ifdef ENABLE_GEM_SYSTEM
				#define ENABLE_GEM_SHOP						// Gaya Maðazasý
			#endif
		#define ENABLE_MINI_GAME_FINDM						// Eþya Bulma Etkinliði
			#ifdef ENABLE_MINI_GAME_FINDM
			#	define ENABLE_MINI_GAME_FINDM_HINT			// Eþya Bulma Ýpuçlarý
			#endif
		#define ENABLE_SUMMER_EVENT_ROULETTE				// Kanlý Ay Etkinliði
		#define ENABLE_MINI_GAME_BNW						// Siyah Beyaz Etkinliði
		//#define ENABLE_BATTLE_ROYALE						// kullanýlmýyor
		#define ENABLE_METINSTONE_RAIN_EVENT				// Metin Taþý Yaðmuru Etkinliði
		#define ENABLE_SOCCER_BALL_EVENT					// Futbol Topu Etkinliði
		#define ENABLE_WORD_GAME_EVENT						// M-E-T-I-N-2 Kelime Oyunu

	#define ENABLE_WORLD_BOSS								// Dünya Boss Etkinliði
		#ifdef ENABLE_WORLD_BOSS
			#define WORLD_BOSS_PHASE 6						// Dünya Boss Etkinliði Evre 6
			#define BATTLE_PHASE 4							// Savaþ Evresi
			#define COOLDOWN_PHASE 2						// Soðuma Evresi

		#define ENABLE_WB_RANKING							// Dünya Boss Sýralamasý
			#ifdef ENABLE_WB_RANKING
				#define WB_MIN_DMG 60000					// Sýralama için Minimum Hasar 60000
			#endif
		#endif

		#define ENABLE_SUPERSTONE_RAIN_EVENT				// Süper Taþ Yaðmuru Etkinliði
		#define ENABLE_MINING_EVENT							// Madencilik Etkinliði
	#endif


/*-----Zindanlar*///----->
#define ENABLE_DUNGEON_RENEWAL							// Yenilenmiþ Zindan Sistemi
#define ENABLE_DUNGEON_DEAD_TIME_RENEWAL				// Zindan Ölüm Zamaný Yenileme
#define ENABLE_ELEMENTAL_WORLD							// Elemental Dünya Etkinleþtirme
	#ifdef ENABLE_ELEMENTAL_WORLD
		#define DROP_PERC_ELEMENT_04 4					// Element %4 Drop Oraný
	#endif
#define ENABLE_DEVIL_TOWER								// Þeytan Kulesi Zindaný
#define ENABLE_DEVIL_CATACOMBS							// Þeytan Yeraltý Mezarý Zindaný
#define ENABLE_SPIDER_DUNGEON							// Örümcek Zindaný
#define ENABLE_FLAME_DUNGEON							// Alev Zindaný
#define ENABLE_SNOW_DUNGEON								// Kar Zindaný
#define ENABLE_RANKING_SYSTEM							// Sýralama Sistemi
#define ENABLE_DAWNMIST_DUNGEON							// Ochao Tapýnaðý
#define ENABLE_GUILD_DRAGONLAIR_SYSTEM					// Gilde Ejderha Maðarasý Sistemi
	#ifdef ENABLE_GUILD_DRAGONLAIR_SYSTEM
		#define ENABLE_GUILD_DRAGONLAIR_PARTY_SYSTEM	// Ejderha Maðarasý Parti Sistemi
		#define ENABLE_BLUEDRAGON_RENEWAL				// Mavi Ejderha Yenileme
	#endif
#define ENABLE_BATTLE_FIELD								// Savaþ Alaný Etkinleþtirme
#define ENABLE_12ZI										// Zodyak Zindaný
	#ifdef ENABLE_12ZI
	#define ENABLE_CHAT_MISSION_ALTERNATIVE				// Sohbet Görev Alternatifi
	#define ENABLE_SERVERTIME_PORTAL_SPAWN				// Sunucu Saati ile Portal Açýlmasý
	//#define ENABLE_12ZI_SHOP_LIMIT					// Zodyak Maðaza Sýnýrý
	//#define ENABLE_12ZI_REWARD_TABLE					// Zodyak Ödül Tablosu
	#endif
#define ENABLE_DEFENSE_WAVE								// Gemi Savunma Zindaný
	#ifdef ENABLE_DEFENSE_WAVE
		#define ENABLE_NEW_CHAT_DUNGEON					// Yeni Sohbet Zindaný
		#define ENABLE_PARTY_FEATURES					// Parti Özellikleri
	#endif
#define ENABLE_QUEEN_NETHIS								// Yýlan Tapýnaðý Kraliçesi Nethis
#define ENABLE_WHITE_DRAGON								// Beyaz Ejderha Alastor
#define ENABLE_SUNG_MAHI_TOWER							// Sungmahi Kulesi


//--------SEÇENEKLER------->
#define ENABLE_EXTEND_INVEN_SYSTEM								// Geniþletilmiþ Envanter Sistemi
	#ifdef ENABLE_EXTEND_INVEN_SYSTEM
		#define ENABLE_EXTEND_INVEN_ITEM_UPGRADE				// Envanter geniþletme için eþya yükseltme
		#define ENABLE_EXTEND_INVEN_ITEM_UPGRADE_SPECIAL_INV	// Özel Envanter Kilidini Açma Uzantýsý
		#define ENABLE_BELT_INVENTORY							// Kemer Envanteri
		#else
		#define ENABLE_EXTEND_INVEN_PAGE_SYSTEM					// Geniþletilmiþ Envanter Sayfa Sistemi
	#endif
#define ENABLE_BELT_INVENTORY_RENEWAL							// Resmi Kemer Geniþletme
#define ENABLE_ADDITIONAL_EQUIPMENT_PAGE						// Resmi Envanter Yeniden Yapýlandýrma
#define WJ_NEW_USER_CARE										// Yeni Kullanýcý Desteði
#define ENABLE_AFTERDEATH_SHIELD								// Ölümden Sonra Kalkan
	#ifdef ENABLE_AFTERDEATH_SHIELD	
	#	define AFTERDEATH_SHIELD_ONLY_WARMAP					// Sadece savaþ haritasýnda kalkan etkin
	#endif
#define ENABLE_EXPRESSING_EMOTION								// Yeni Duygu Ýfadeleri
#define ENABLE_CHAT_SETTINGS									// Sohbet Ayarlarý
#define ENABLE_SHOW_GUILD_LEADER								// Lonca Lideri ve Yardýmcýsýný Gösterme
#define ENABLE_GUILDRENEWAL_SYSTEM								// Resmi Lonca Geniþletme Sistemi

#ifdef ENABLE_GUILDRENEWAL_SYSTEM				// Lonca Sistemi
	#define ENABLE_USE_MONEY_FROM_GUILD			// Lonca Parasý ile ödeme yapma
	#define ENABLE_NEW_WAR_OPTIONS				// Yeni Lonca Savaþý Seçenekleri (Tur, Puan, Süre)
	#define ENABLE_EXTENDED_GUILD_LEVEL			// Lonca seviyesini 30'a kadar geniþletme

	#define ENABLE_MEDAL_OF_HONOR				// Yeni lonca para birimi
	#define ENABLE_GUILD_DONATE_ATTENDANCE		// Günlük Baðýþ

	#define ENABLE_GUILD_WAR_SCORE				// Savaþ Sayfasý
	#define ENABLE_GUILD_LAND_INFO				// Arazi Bilgisi Sayfasý
	#define ENABLE_GUILDBANK_LOG				// Lonca Günlükleri

	#define ENABLE_GUILDBANK_EXTENDED_LOGS		// Geniþletilmiþ günlükler için Log.cpp baðlantýsý
	#define ENABLE_EXTENDED_RENEWAL_FEATURES	// Lonca Liderini Deðiþtirme | Arazi Silme
	#define ENABLE_COLEADER_WAR_PRIVILEGES		// Lider çevrimdýþý olduðunda, Yardýmcý Lider lider ile ayný yetkilere sahip
	#define ENABLE_GUILDWAR_BUTTON				// Lonca Savaþý oluþturma -> Oyun içinde düðme etkinleþiyor
//	#define ENABLE_GUILD_RANKING				// bitmemiþ lonca sýralamasý
#endif

#define ENABLE_HUNTING_SYSTEM						// Av Görevleri Sistemi
	#ifdef ENABLE_HUNTING_SYSTEM
		#define HUNTING_MISSION_COUNT 90			// Toplam av görevi sayýsý
		#define HUNTING_MONEY_TABLE_SIZE 9			// Para ödül tablosu boyutu
		#define HUNTING_EXP_TABLE_SIZE 9			// Deneyim puaný ödül tablosu boyutu
	#endif

#define ENABLE_SET_ITEM								// Eþya Set Sistemi
#define ENABLE_SAFEBOX_IMPROVING					// Geliþtirilmiþ Sandýk Sistemi
//#define ENABLE_SAFEBOX_MONEY						// Sandýkta Para Depolama Sistemi
#define ENABLE_REFINE_MSG_ADD						// Eþya Yükseltme Mesajlarý
#define ENABLE_PORTAL_LEVEL_LIMIT					// Portal Kullanýmý için Seviye Sýnýrý
#define WJ_SHOW_PARTY_ON_MINIMAP					// Partideki üyeleri harita üzerinde göster
#define ENABLE_AFK_MODE_SYSTEM						// AFK Modu Sistemi
#define ENABLE_VIEW_EQUIP_RENEWAL					// Ekipman Görüntüleme Yenileme
#define ENABLE_LOADING_TIP							// Yükleme Ýpuçlarý
#define ENABLE_TARGET_AFFECT_SHOWER					// Hedef Durum Etkisi Gösterici [Sanii]
#define ENABLE_VIEW_TARGET_DECIMAL_HP				// Can Deðerini Tam Sayý Olarak Göster @Monster
#define ENABLE_SEND_TARGET_INFO						// Canavar Hedef Düþüþ Bilgisi
#ifdef ENABLE_SEND_TARGET_INFO
	#define ENABLE_COMMON_DROP_INFO					// common_drop_item.txt Dosyasýný Yükler
#endif
#define ENABLE_DELETE_FAILURE_TYPE					// Baþarýsýz Eþya Silme Türü
#define ENABLE_GIVE_BASIC_ITEM						// Temel Eþyalar Verme
	#ifdef ENABLE_GIVE_BASIC_ITEM
	#define GIVE_BASIC_SKILLS						// Temel Yetenekler: At[11], Dil[P]
	//#define GIVE_BASIC_EXTENDED_ITEMS				// Geliþmiþ Ekipman Verme

	#define BLOCK_ADDCHANGE_ATTR_ON_BASIC			// Etkin: Eþyalarýn bonuslarý deðiþtirilemez
	//#define BLOCK_DESTRY_ATTR_ON_BASIC			// Etkin: Eþyalar yok edilemez
	//#define BLOCK_REFINE_ON_BASIC					// Etkin: Eþyalar yükseltilemez
	#endif
#define ENABLE_DICE_SYSTEM							// Zar Sistemi: Eðer canavar kral veya boss ise, partideyseniz düþen eþyalar rastgele daðýtýlýr
#define ENABLE_PARTY_EXP_DISTRIBUTION_EQUAL			// Eþit Grup Deneyim Daðýlýmý
#define ENABLE_RENEWAL_SHOPEX						// Geliþmiþ Maðaza Sistemi [Ekipman, Deneyim]
#define ENABLE_ANTI_EXP_RING						// Anti-EXP Yüzüðü
#define ENABLE_INVENTORY_SORT						// Envanter Sýralama Butonu
#define ENABLE_CUBE_PERCENT_INFO					// Küp Penceresinde Yüzde Bilgisi
#define ENABLE_AFFECT_POLYMORPH_REMOVE				// Sol Üst Ýkonda Polimorf Týklayýnca Kaldýrýlýr
#define ENABLE_AFFECT_BUFF_REMOVE					// Sol Üst Ýkonda Buff Týklayýnca Kaldýrýlýr
#define ENABLE_SKILL_COOLTIME_UPDATE				// Oyuncu öldüðünde yetenek soðuma süreleri sýfýrlanýr
//#define ENABLE_COLORED_GUILD_RANKS				// Lonca Rütbeleri Renkli Görünür
//#define ENABLE_GROUPLOOT_ONLY_FOR_ATTACKERS		// Yalnýzca Saldýrý Yapan Oyuncular Eþya Alabilir
#define ENABLE_OX_RENEWAL							// OX Etkinliði Yenilenmesi
//#define OX_REWARD_UPDATE							// OX Güncellemesi [Mali] (Daha Ýyi Görev)
//#define ENABLE_UNMOUNT_WHEN_DEAD					// Ölümde Binekten Ýndirme
#define ENABLE_EXTENDED_ITEMNAME_ON_GROUND			// Yerdeki Eþya Ýsimlerini Göster
#define ENABLE_EMPIRE_FLAG							// Global Sohbette Ýmparatorluk Bayraklarý
#define ENABLE_MESSENGER_BLOCK 						// Mesajlaþma Engelleme
#define ENABLE_GM_MESSENGER_LIST					// GameMaster Çevrimiçi/Çevrimdýþý Listesi
#define ENABLE_MONARCH_AFFECT						// Monark Oyun Ýçi Etkisi



//////////////////////////////////////////////////[STANDART TANIMLAR]//////////////////////////////////////////////////
/*<-----VERÝTABANI (DB)----->*/
#define ENABLE_DEFAULT_PRIV							//	[ClientManager.cpp]			common.priv_settings dosyasýndan varsayýlan yetkilerin yüklenmesini etkinleþtirir
#define ENABLE_ITEMAWARD_REFRESH					//	[ClientManager.cpp]			player.item_award tablosunda her 5 saniyede bir sorgu yapýlmasýný etkinleþtirir
#define ENABLE_PROTO_FROM_DB						//	[ClientManager.h]			conf.txt içinde "PROTO_FROM_DB = 1" olarak belirtildiðinde protolarý veritabanýndan okur
													//								conf.txt içinde "MIRROR2DB = 1" olarak belirtildiðinde protolarý veritabanýna yansýtýr
#define ENABLE_AUTODETECT_VNUMRANGE					//	[ClientManagerBoot.cpp]		protolar veritabanýndan yüklenirse, ds eþyalarý için otomatik olarak vnum aralýðýný algýlar


//////////////////////////////////////////////////[SADECE OYUN ÝÇÝN TANIMLAR]//////////////////////////////////////////////////
/*<-----OYUN----->*/
#define NEW_ICEDAMAGE_SYSTEM						//	[char.h]					Nemere zindaný gibi yerler için yeni hasar sistemi ekler
#define ENABLE_ANTI_CMD_FLOOD						//	[char.h]					Komut spamýný önler; saniyede 10'dan fazla komut gönderen oyuncu baðlantýsý kesilir
#define ENABLE_OPEN_SHOP_WITH_ARMOR					//	[char.h]					Zýrh giyiliyken de kiþisel dükkan açýlmasýný saðlar
#define ENABLE_GOHOME_IF_MAP_NOT_ALLOWED			//	[char.cpp]					Girilmesine izin verilmeyen bir haritada oyuncuyu köyüne geri gönderir
#define ENABLE_GM_FLAG_IF_TEST_SERVER				//	[char.cpp]					Test sunucu modunda GM bayraðýný gösterir
#define ENABLE_GM_FLAG_FOR_LOW_WIZARD				//	[char.cpp]					Düþük seviyeli sihirbazlar için de GM sembolü saðlar
// #define ENABLE_POTIONS_LEVELUP					//	[char.cpp]					Seviye atlandýðýnda iksir düþüþünü etkinleþtirir
#define ENABLE_NEWEXP_CALCULATION					//	[char_battle.cpp]			Rastgele negatif tecrübe/marriage puaný hatalarýný önlemek için tecrübe oranýný yeniden hesaplar
#define ENABLE_EFFECT_PENETRATE						//	[char_battle.cpp]			Penetrasyon yapýlýrken efekt görünür
#define ENABLE_KILL_EVENT_FIX						//	[char_battle.cpp]			Öldürme olayý sýrasýnda sýfýr tecrübe hatasýný giderir (önerilir)
// #define ENABLE_FIREWORK_STUN						//	[char_item.cpp]				Havai fiþek kullanýldýðýnda sersemletme etkisini etkinleþtirir
#define ENABLE_ADDSTONE_FAILURE						//	[char_item.cpp]				Spirit taþlarýnýn baþarýsýz eklenmesi
#define ENABLE_ADDSTONE_FAILURE_CUSTOM				//	[char_item.cpp]				Spirit taþý baþarýsýzlýðý +0, +1, +2, +3, +4 seçeneklerini etkinleþtirir
#define ENABLE_EFFECT_EXTRAPOT						//	[char_item.cpp]				Yeþil/mor iksirler kullanýldýðýnda ekstra pot efekti
#define ENABLE_BOOKS_STACKFIX						//	[char_item.cpp]				Kitaplarýn yýðýlýp yýðýlmamasýný seçebilir
#define ENABLE_STACKABLES_STONES					//	[char_item.cpp]				Spirit taþlarýnýn yýðýnlanabilir olmasýný saðlar
#define ENABLE_FORCE2MASTERSKILL					//	[char_skill.cpp]			Skill seviyesi her zaman m1'e yükselir (örneðin b17'de)
// #define ENABLE_MOUNTSKILL_CHECK					//	[char_skill.cpp]			At binme kontrolü yapýlmalý mý, skilling sýrasýnda kontrol saðlar
// #define ENABLE_NULLIFYAFFECT_LIMIT				//	[char_skill.cpp]			Sura skill 66, oyunculardan < veya > seviyesinde olanlarý etkisiz hale getirmez
// #define ENABLE_MASTER_SKILLBOOK_NO_STEPS			//	[char_skill.cpp]			Yalnýzca bir kitapla ana skill artýrabilir
#define ENABLE_CMD_PLAYER							//	[config.cpp]				CMD içinde PLAYER derecesini etkinleþtirir
#define ENABLE_EXPTABLE_FROMDB						//	[config.cpp]				Exp tablosunu veritabanýndan okur
#define ENABLE_AUTODETECT_INTERNAL_IP				//	[config.cpp]				Halka açýk bir IP yoksa iç IP'yi otomatik algýlar
// #define ENABLE_GENERAL_CMD						//	[config.cpp]				"locale/%s/conf/GENERAL_CMD" gibi genel CMD okur
// #define ENABLE_GENERAL_CONFIG					//	[config.cpp]				Genel bir CONFIG okur ve geçerli seçenekleri günceller
													//								Geçerli olmayan seçenekler: HOSTNAME, CHANNEL, PLAYER_SQL vb.
// #define ENABLE_BLOCK_CMD_SHORTCUT				//	[cmd.cpp]					Kýsaltýlmýþ komutlarý devre dýþý býrakýr
// #define ENABLE_STATPLUS_NOLIMIT					//	[cmd_gm.cpp]				con+/int+/str+/dex+ komutlarý için 90 puan sýnýrýný kaldýrýr
#define ENABLE_SET_STATE_WITH_TARGET				//	[cmd_gm.cpp]				Komut hedefi olarak 3. argümaný kullanýr
#define ENABLE_CMD_IPURGE_EX						//	[cmd_gm.cpp]				/ipurge ikinci argümaný belirli bir pencereden eþyalarý kaldýrýr (inv/equip/ds/belt/all)
// #define ENABLE_SPAMDB_REFRESH					//	[db.cpp]					common.spam_db içinde her 10 dakikada bir sorgu yapýlmasýný saðlar
#define ENABLE_FISHINGROD_RENEWAL					//	[fishing.cpp]				Balýk oltasý yükseltmesi baþarýsýz olursa, sadece %10 ana puan kaybeder
#define ENABLE_NEWGUILDMAKE							//	[guild.h]					pc.make_guild0 iþlevini etkinleþtirir
#define ENABLE_INFINITE_HORSE_HEALTH_STAMINA		//	[horse_rider.h]				At saðlýðý veya dayanýklýlýðý kaybetmez
// #define ENABLE_ACCOUNT_W_SPECIALCHARS			//	[input_auth.cpp]			Hesap adlarýnda özel karakterlerin kullanýlmasýný saðlar
#define ENABLE_GOHOME_IF_MAP_NOT_EXIST				//	[input_db.cpp]				Harita mevcut deðilse oyuncuyu köyüne geri gönderir
#define ENABLE_CHAT_COLOR_SYSTEM					//	[input_main.cpp]			GM olup olmadýðýna göre sohbet renklerini etkinleþtirir
#define ENABLE_CHAT_SPAMLIMIT						//	[input_main.cpp]			Sohbet spam sýnýrý; 5 saniyede 4 mesajý aþarsa baðlantý kesilir
#define ENABLE_WHISPER_CHAT_SPAMLIMIT				//	[input_main.cpp]			Özel mesajlarda 5 saniyede 10 mesaj sýnýrý; aksi takdirde baðlantý kesilir
#define ENABLE_CHAT_LOGGING							//	[input_main.cpp]			Sohbet kaydýný etkinleþtirir (tüm GM sohbetlerini kaydeder)
#define ENABLE_IMMUNE_FIX							//	[item.cpp]					Ýmmün bugunu düzeltir; kalkan son olarak donatýldýðýnda çalýþýr
#define ENABLE_FIX_READ_ETC_DROP_ITEM_FILE_BY_VNUM	//	[item_manager_read_tables]	EtcDropItemFile okuma: Mevcut olmayan bir öðe (Korece isimler nedeniyle)
#define ENABLE_PICKAXE_RENEWAL						//	[mining.cpp]				Kazma yükseltmesi baþarýsýz olursa sadece %10 ana puan kaybeder
#define ENABLE_QUEST_DIE_EVENT						//	[quest.h]					"die" görev etkinliðini ekler
#define ENABLE_QUEST_BOOT_EVENT						//	[quest.h]					Oyun baþladýðýnda etkinlik baþlatýlýr
#define ENABLE_QUEST_DND_EVENT						//	[quest.h]					quest üzerinden kaydýrma yaratmak için etkinlik baþlatýr
#define ENABLE_TRANSLATE_LUA						//	[questlua.cpp]				translate.lua dosyasýnýn yüklenmesini saðlar
// #define ENABLE_LOCALECHECK_CHANGENAME			//	[questlua_pc.cpp]			Avrupa yerellerinde ad deðiþikliðine izin vermez
// #define ENABLE_PC_OPENSHOP						//	[questlua_pc.cpp]			pc.open_shop0(idshop) iþlevini etkinleþtirir ancak alým/satým çalýþmaz
#define D_JOIN_AS_JUMP_PARTY						//	[questlua_dungeon.cpp]		x
#define ENABLE_QUESTLIB_EXTRA_LUA					//	[questlua.cpp]				x
#define ENABLE_PARTYKILL							//	[questmanager.cpp]			PartyKill'i yeniden etkinleþtirir
// #define ENABLE_SHOP_BLACKLIST					//	[shop.cpp]					Blessing Marble ve Magic Copper Ore gibi ürünleri engeller
#define ENABLE_NEW_RETARDED_GF_START_POSITION		//	[start_position.cpp]		Yeni Gameforge baþlangýç pozisyonu
#define ENABLE_D_NJGUILD							//	[general]					d.new_jump_all_guild+cpp ile ilgili iþlevleri etkinleþtirir
#define ENABLE_FULL_NOTICE							//	[general]					Geniþletilmiþ bildirim özelliklerini etkinleþtirir
#define ENABLE_NEWSTUFF								//	[general]					Yeni özellikler (yeni lua iþlevleri, yeni CONFIG seçenekleri vb.) ekler
#define ENABLE_NEWSTUFF_2017						//	2017 yýlýndaki yeni özellikler
#define ENABLE_NEWSTUFF_2019						//	2019 yýlýndaki yeni özellikler
#define ENABLE_CMD_WARP_IN_DUNGEON					//	[general]					/warp komutu zindandaki bir oyuncuya ulaþabilir

/*
@#GENEL MAKROLAR
#define __UNIMPLEMENTED__				// Uygulanacak yeni þeylerin taslaklarý
*/


/*
#@GENEL
@warme001: PLAYER_MAX_LEVEL_CONST (common/length.h) ve gPlayerMaxLevel (game/config.h) hakkýnda dikkatli olun
@warme002: ITEM_MAX_COUNT (common/item_length.h) ve g_bItemCountLimit (game/config.h) hakkýnda dikkatli olun
@warme003: do_click_safebox her haritada PLAYER tarafýndan kullanýlabilir!
@warme004: `when vnum.kill begin` ve `when kill begin` her ikisi de tetiklenir
@warme005: farklý yerel (locale) ayarlar
@warme007: db/src/ClientManager.cpp üzerinde; ./close ve ./start sýrasýnda anlamsýzlýðý ve hatalý çalýþmasýndan dolayý common.locale setini yorum satýrý yapýldý
			yeniden iþlem baþlatýlmadan önce aþýrý yükleme varsa, bu null pointer mysql baðlantýsýný iþler (ymir iþ parçacýðý)
@warme008: char_item.cpp üzerinde; þimdi 27996 (zehir þiþesi) zehir etkisi verebilir
@warme009: char_resist.cpp üzerinde; eðer kanama zehir olarak kullanýlýrsa, kanama eklentisi zehir eklentisi/50'dir (bu sayede yaratýklar oyuncularý kanatabilir)
@warme010: char_state.cpp üzerinde; test_server "BOOL g_test_server" olarak kullanýlýr
@warme011: dungeon.cpp üzerinde; d.join yerine d.new_jump_party kullanmalýsýnýz çünkü parti hash kontrolündeki yanlýþ bir uygulama nedeniyle rastgele çökme sorunlarýna neden olur
@warme012: önemsiz hatalar artýk basit loglar olarak kabul ediliyor
@warme013: gereksiz hatalar artýk yalnýzca yorum satýrý yapýlýyor

#@common
@fixme301: tables.h üzerinde; TPlayerTable hp/mp int16_t'den int'e deðiþtirildi (hp/mp >32767 olmalý)

#@db/src
@fixme201: ProtoReader.cpp üzerinde; 'SAMLL' 'SMALL' olarak deðiþtirildi
@fixme202: ClientManagerGuild.cpp üzerinde; eðer oyuncu çevrimdýþý ise lonca üyesi çýkarma zamaný sorunu düzeltildi 
			(withdraw_time -> new_withdraw_time)
@fixme203: ClientManagerPlayer.cpp üzerinde; "command" için boþta kalan gösterici (dangling pointer)
@fixme204: Cache.cpp üzerinde; kiþisel dükkanda ayný vnum’a sahip çok fazla eþya varsa, myshop_pricelist birincil anahtar çoðaltma hatasý


#@game/src
@fixme101: log.cpp üzerinde, invalid_server_log için '%s' hatasý düzeltildi.
@fixme102: cmd_general.cpp üzerinde ACMD(do_war) içinde unsigned hatasý düzeltildi.
@fixme103: config, input_login, input_main.cpp dosyalarýnda clientcheckversion (sürüm > tarih) ifadesi (sürüm != tarih) ve gecikme süresi 10’dan 0’a olarak deðiþtirildi.
@fixme104: char.cpp, questlua_pc.cpp dosyalarýnda lv90'dan sonra statü puaný alma düzeltildi; 90 deðeri gPlayerMaxLevel ile deðiþtirildi.
@fixme105: cmd.cpp dosyasýnda tüm Korece komutlar devre dýþý býrakýldý.
@fixme106: input_main.cpp dosyasýnda, yüksek hýzdaki bir oyuncu binekteyken (örneðin, aslan) mesafe sýnýrý nedeniyle geri getirilecektir.
@fixme107: char_battle.cpp dosyasýnda, ölen karakter (oyuncu veya yaratýk) negatif hp deðerine sahip olduðunda, sura&co, hp/mp kaybeder.
@fixme108: char.cpp dosyasýnda, mevcut binek 0 deðilken bineði deðiþtirdiðinizde, yalnýzca oyuncunun ekranýndaki tüm nesneler (npc vb.) kaybolur.
@fixme109: questmanager.cpp dosyasýnda, bir oyuncu öldürüldüðünde (savaþ m), `when kill begin` iki kez tetiklenir.
@fixme110: char_affect.cpp dosyasýnda, yarý saydamken (yeniden canlanmýþ, ninja yeteneði veya beyaz bayrak) saldýrý yaptýðýnýzda hala yarý saydam kalýrsýnýz.
@fixme111: test.cpp dosyasýnda, ConvertAttribute2'de x ve y ekseni ters çevrildi (önce y->x, sonra x->y).
@fixme112: char_item.cpp dosyasýnda, tekrar giriþ yapýlana kadar ekipman üzerindeki bonuslar deðiþtirilebilir.
@fixme113: char_item.cpp dosyasýnda taþlarý çýkarýrken, bonus kaybý olmadan çýkarýlabilir.
@fixme114: char_item.cpp dosyasýnda, #111, #112 ve diðer birkaç hata bir araya getirildi.
@fixme115: char_item.cpp dosyasýnda, partideyseniz ve eþyalarýn sahibi siz deðilse, yerdeki tüm eþyalar alýnabilir.
@fixme116: char_skill.cpp dosyasýnda, normal at binme yetenekleri hasar veremez.
@fixme117: char_item.cpp dosyasýnda, envanter doluyken ekipman deðiþtirilemez ve boþ olmadýðýnda gereksiz kemer deðiþimleri engellenir.
@fixme118: char.cpp dosyasýnda ComputePoints çaðrýldýðýnda, ekipman bonuslarý kadar hp/mp kazanýrsýnýz.
@fixme119: input_main.cpp dosyasýnda, kasadaki/alýþveriþ merkezindeki eþyalar kemer envanterine tür kontrolü olmadan yerleþtirilebilir.
@fixme120: input_login.cpp dosyasýnda, bazý paket kimlikleri kontrol edilmedi.
@fixme121: char_item.cpp dosyasýnda, büyü taþý deðerlerinden kaynaklanan gereksiz sistem hatalarý oluþturuyordu.
@fixme122: arena.cpp dosyasýnda, arenada bazý iksirler kontrol edilmedi.
@fixme123: char_item.cpp dosyasýnda USE_CHANGE_ATTRIBUTE2 (24) alt tür kontrol hatasý (koþul hiçbir zaman doðru olamaz).
@fixme124: char_item.cpp dosyasýnda 6-7 ekleme/deðiþtirme kostüm eþyalarýnda kontrol edilmedi.
@fixme125: char.cpp dosyasýnda, zindan yenilenmesi sarkan bir iþaretçiye iþaret ediyordu (gereksiz olduðu için kaldýrýldý).
@fixme126: marriage.cpp dosyasýnda sevgi puanlarý taþma hatasý düzeltildi.
@fixme127: cube.cpp dosyasýnda /cube r_info exploit düzeltildi; kontrolsüz bir küp npc vnumlarý nedeniyle çökmeye yol açabiliyordu.
@fixme128: char.cpp dosyasýnda madencilik hacki düzeltildi; karakter haritadaki herhangi bir konumdan maden çýkarabiliyordu.
@fixme129: PetSystem.cpp dosyasýnda, Azrael evcil hayvanlarý zindanda deðilse buff vermiyor ve çaðrýldýðýnda da kaldýrýlýyor.
@fixme130: messenger_manager.cpp ve cmd_general.cpp dosyalarýnda, bir flood paketi gönderildiðinde maðdur baðlantýsý kesilecek veya en fazla gecikmeye maruz kalabilir.
@fixme131: char.cpp dosyasýnda, dövüþülemeyen npc/oyuncu nesnelerine dahi eþzamanlama paketlerinin gönderilmesi sorunu düzeltildi.
@fixme132: shop.cpp dosyasýnda, iki kiþi ayný anda ayný ürünü satýn aldýðýnda, yavaþ olan kullanýcý yanlýþ bir dönüþ paketi alýr.
@fixme133: input_main.cpp dosyasýnda, küfür filtresi ve baðlantýlý metin özelliði son metni deðil ham metni iþliyordu.
@fixme134: questlua_pc.cpp dosyasýnda, binek bonusu binek çaðrýlmamýþ olsa bile eklenebilirdi (sadece /unmount pc.unmount kaldýrabilir).
@fixme135: char.cpp dosyasýnda, eþzamanlama bir hareket paketinden önce yapýlýrsa çökme oluþabilir (sorunlu -> kaldýrýldý).
@fixme136: char.cpp dosyasýnda, sýfýra bölme istisnalarýna dair kontroller yoktu; örneðin, bir yaratýðýn maksimum hp'sini 0 olarak ayarlarsanýz rastgele çökmeler meydana gelir.
@fixme137: char_battle.cpp dosyasýnda, bir oyuncu öldüðünde HP negatif bir deðer alabilir. Þimdi 0 olacak þekilde güncellendi.
@fixme138: db.cpp, input_auth.cpp dosyalarýnda, hesabýn þifresi her giriþ denemesinde mysql sorgu geçmiþinde düz metin olarak görünüyordu (þimdi hashlenmiþ).
@fixme139: shop.h dosyasýnda, CShop sýnýfýnýn yýkýcýsý sanal deðildi. CShopEx gibi bir türetilmiþ sýnýf silindiðinde bellek sýzýntýsý oluþuyordu.
@fixme140: input_main.cpp dosyasýnda, kemer doluyken kasa envanterine koyulabiliyordu.
@fixme141: char_item.cpp dosyasýnda, kemer envanterinde kullanýlabilir olmayan yuvalarda dahi eþyalar kullanýlabiliyordu.
@fixme142: messenger_manager.cpp dosyasýnda, net.SendMessengerRemovePacket için SQL enjeksiyon düzeltmesi.
@fixme143: guild_manager.cpp dosyasýnda, net.SendAnswerMakeGuildPacket için SQL enjeksiyon düzeltmesi.
@fixme144: sectree_manager.cpp dosyasýnda, map/index yeni satýrla bitmezse oyun çöker.
@fixme145: input_main.cpp dosyasýnda, guild_add_member her vid’i lonca üyesi olarak ekleyebilir (bir yaratýk veya npc olsa bile).
@fixme147: char_item.cpp dosyasýnda, ramazan þekeri etkisi halen aktif olsa dahi kullanýlabilir.
@fixme148: item_manager_read_tables.cpp dosyasýnda, ConvSpecialDropItemFile içinde görev, özel ve nitelik türleri iþlenmedi.
@fixme149: char.cpp dosyasýnda, eþyalar deðiþtirildiðinde malzeme atlama exploit'i düzeltildi.
@fixme150: exchange.cpp, char_item.cpp dosyalarýnda, görev askýya alýnmýþsa eþya modülü deðiþtirilemez.
@fixme152: questlua_pc.cpp dosyasýnda, pc.get_special_ride_vnum socket0 yerine socket2'yi kontrol ediyordu.
@fixme153: threeway_war.cpp dosyasýnda, 99. seviyenin üzerindeki öldürme sayýsý kaydedilmiyordu.
@fixme154: cmd_gm.cpp dosyasýnda, /all_skill_master komutu artýk alt becerilere doðru puan sayýsýný ayarlayacak.
@fixme156: char_affect.cpp dosyasýnda, etki deðerlerinin yüklenmeden önce ikiye katlanmasýný engelle (örneðin giriþte binek bonusu gibi).
@fixme157: OxEvent.cpp dosyasýnda, ox etkinliði durdurulduktan sonra katýlýmcý listesi temizlenmiyordu.
@fixme158: input_main.cpp dosyasýnda, deviltower rafineri para olmadýðý takdirde sýfýrlanmayacak ve bayrak 1 azaltýlacak.
@fixme159: exchange.cpp dosyasýnda, takas yapýlýrken ds eþyalarýnda yanlýþ kontrol nedeniyle ilk ds alt envanter yuvasý boþ deðilse takas yapýlamýyordu.
@fixme160: DragonSoul.cpp dosyasýnda, bir ds taþý kaldýrýlýrken hedef yuva boþ deðilse ds eþyasý deðiþtirilecek ve kaybolacaktýr.
@fixme168: questevent.cpp dosyasýnda, görevin bilgi adý zaten null ise std::string oluþturucu bir istisna fýrlatacaktýr.
@fixme169: char_item.cpp dosyasýnda, efsanevi þeftali alternatif vnum.
@fixme170: item.cpp dosyasýnda, bonuslarýn özel mineral yuvalarýnda uygulanma düzeltmesi.
@fixme171: dungeon.cpp dosyasýnda, daha önce (!ch->IsPC()).
@fixme172: dungeon.cpp dosyasýnda, gönderilmeden önce ch->IsPC() eklendi.
@fixme173: item.cpp dosyasýnda Range_pick 300'den 600'e geniþletildi.
@fixme174: questmanager.cpp dosyasýnda ch kontrolü.
@fixme177: cmd_gm.cpp dosyasýnda, doðru mesaj içeri aktarýldý.
@fixme180: cmd_general.cpp dosyasýnda, /costume komutu iliþkili kostüm bonus kimlikleri fn_string içinde mevcut deðilse oyun çekirdek çökmesine neden olur.
@fixme182: input_login.cpp dosyasýnda.
@fixme183: input_main.cpp, messenger_manager.cpp dosyalarýnda arkadaþ listesinden kaldýrma -> arkadaþlýktan çýkarýldý.

@fixme185: ClientManagerBoot.cpp dosyasýnda, material_count deðeri nullptr ise eklendi.
@fixme186: item.cpp dosyasýnda ch kontrolü.
@fixme188: char.h dosyasýnda, öldüðünde ödül verilmez.
@fixme189: item_manager.cpp dosyasýnda, out of range (sýnýr dýþý) hatasý düzeltildi.

@fixme400: item_manager.cpp dosyasýnda, yüzüklere bonus görünürlük eklendi.
@fixme401: char_item.cpp dosyasýnda, ayný vnum’a sahip iki yüzük düzeltildi.
@fixme402: cmd_gm.cpp dosyasýnda, rang puan hesaplamasý (ch->tch) düzeltildi.
@fixme403: input_main.cpp dosyasýnda, deneyim (EXP) daðýtýmý sadece grup liderine yapýlacak þekilde düzenlendi.
@fixme404: char_item.cpp dosyasýnda, ayný iksirlerin birden fazla kez kullanýlmasý engellendi.
@fixme405: char.cpp dosyasýnda, Max Level’den sonra %50’ye kadar daha deneyim (EXP) kazanýlabilir.
@fixme406: char_affect.cpp dosyasýnda, düþük seviyeli bufflar yok sayýlýr.
@fixme407: char.cpp dosyasýnda, maðaza paketleri maðazada yer almayacak þekilde düzenlendi.
@fixme408: cmd_general.cpp dosyasýnda, GM_IMPLEMENTOR kullanýcýlarý anýnda kasabaya geri dönebilir ve yeniden baþlayabilir.
@fixme409: char_item.cpp dosyasýnda, ölü olsanýz bile eþya toplama iþlemi engellendi.
@fixme410: char_item.cpp dosyasýnda, mesafe kontrolüyle silah demircisi düzeltildi.
@fixme411: item_length.h dosyasýnda, geniþletilmiþ ad uzunluðu eklendi.
@fixme412: length.h dosyasýnda, geniþletilmiþ karakter maksimum uzunluðu eklendi.
@fixme413: length.h dosyasýnda, ValidItemPosition’da eksik pencere türü düzeltildi.
@fixme414: char_item.cpp dosyasýnda, iksirler doðrudan kemer envanterine yýðýlarak eklenir.
@fixme415: input_login.cpp dosyasýnda yanlýþ map_index (2) düzeltildi.
@fixme416: input_main.cpp dosyasýnda, ekipmanlý eþyalar kasa envanterine konulamaz.
@fixme417:
@fixme418: char.cpp dosyasýnda, yere býrakýlan eþyalar grubunuzdaki diðer oyuncular için yýðýnlanýr.
@fixme419: desc_manager.cpp dosyasýnda, doðru PC bulunmasý saðlandý.
@fixme420: config.cpp dosyasýnda, interpreter_set_privilege[CMD yetkilerini yükle] devre dýþý býrakýldý.
@fixme421: input_login.cpp dosyasýnda, GM ve görünmez olan oyuncular gözlemci olarak ayarlandý.
@fixme422: char_item.cpp dosyasýnda eksik MonkeyDungeon düzeltmesi.
@fixme423: char_battle.cpp dosyasýnda, silahsýzken bufflar devre dýþý býrakýldý (VZK, AURA).
@fixme424: char_item.cpp dosyasýnda, ekipmanlý eþyalarda özellik deðiþikliði yapýlamaz.
@fixme425: char.cpp dosyasýnda, zindan çekirdek çökmesi düzeltildi.
@fixme426: char_battle.cpp dosyasýnda, doðru hizalama hesaplamasý yapýldý.
@fixme427: belt_inventory_helper.h dosyasýnda, kemer envanterinde karýþýmlarýn kullanýmýna izin verildi.
@fixme428: questlua_pc.cpp dosyasýnda, yetenek grubu deðiþtiðinde etkiler kaldýrýlýr.
@fixme429: input_main.cpp dosyasýnda, comboattackhack ile ilgili null deðeri sorunu düzeltildi.
@fixme430: PetSystem.cpp dosyasýnda SetSummonItem Socket düzeltmesi.
@fixme431: char.cpp dosyasýnda Ghostwalker düzeltildi.
@fixme432: char.cpp dosyasýnda Madencilik Botu düzeltildi.
@fixme433: char_affect.cpp dosyasýnda, Weaponry Sura’nýn Dispel ve Healing Power Shaman’ýn þifa gecikmesi hatasý düzeltildi.
@fixme434: char_dragonsoul.cpp dosyasýnda, AddAffect ile Dragon Soul aktif etkisi eklendi.
@fixme435: char_battle.cpp dosyasýnda, zehir canavarlarý artýk agresifleþtirmeyecek.
@fixme436: char_item.cpp dosyasýnda, Glückstasche eksik -> yeni protolar eklendi.
@fixme437: char_item.cpp dosyasýnda, taþ menzili geniþletme - eksik: Lykaner, Magiebruch.
@fixme438: char_item.cpp dosyasýnda, yeniden baðlanma/sýralý geçiþlerde evcil hayvan çaðrýlabilir durumda.
@fixme439: char_change_empire.cpp dosyasýnda, diðer imparatorluktaki lonca ile Ýmparatorluk Deðiþimi düzeltildi (UpdatePacket).
@fixme440: questlua_pc.cpp dosyasýnda VIP - sistem; GameMaster VIP olamaz.
@fixme441: cmd_general.cpp dosyasýnda, lonca savaþýnda negatif çekirdek çökme hatasý düzeltildi.
@fixme442: questlua_pc.cpp dosyasýnda Ýmparatorluk Deðiþikliðinden sonra otomatik baðlantý kesme.
@fixme443: char_battle.cpp dosyasýnda, saldýrý sýrasýnda maðazaya eriþim engellendi.
@fixme444: char_item.cpp dosyasýnda eksik IsExchanging.
@fixme445: char_item.cpp dosyasýnda, eski saçlarda özellik deðiþtirme kullanýlamaz.
@fixme446: char_item.cpp dosyasýnda, Lonca demircisinin doðru hesaplama ve oyun içi bilgi gösterimi (ingame) düzenlendi.
@fixme447: char_horse.cpp dosyasýnda, StartRiding sýrasýnda at biniyor olsanýz bile yeniden baþlatamazsýnýz.
@fixme448: dungeon.cpp dosyasýnda, zindandaki canavar sayýmý (yalnýzca NPC'leri içermeyecek þekilde) düzeltildi.
@fixme449: dungeon.cpp dosyasýnda, zindanýn tüm varlýklar için bildirimle daha fazla bellek kullanmasýný önleyen düzeltme.
@fixme450: char_item.cpp dosyasýnda, evlilik eþyalarýnýn binekteyken kullanýmý engellendi.
@fixme451: questlua_global.cpp dosyasýnda, küçük önlemler.
@fixme452: battle.cpp dosyasýnda, savaþta IsObserverMode eklendi.
@fixme453: char_battle.cpp dosyasýnda IsObserverMode eklendi.
@fixme454: PetSystem.cpp dosyasýnda, evcil hayvan teleport/yeniden giriþ sonrasýnda kaybolmuyordu.
@fixme455: char_battle.cpp dosyasýnda moblock/bravery cape hack düzeltildi.
@fixme456: db.cpp dosyasýnda SQL enjeksiyon düzeltmesi.
@fixme457: input_main.cpp dosyasýnda, Wolfman ComboHack - Kick hatasý düzeltildi.
@fixme458: char_skill.cpp dosyasýnda, düþmaný duvarlara iten beceri hatasý düzeltildi.
@fixme459: char_skill.cpp dosyasýnda, silahsýzken aura ve vzk yetenekleri devre dýþý.
@fixme460: char_item.cpp dosyasýnda, yýðýlan taþlar her biri -1 olacak þekilde düzenlendi.
@fixme461: char_skill.cpp dosyasýnda SK no fall (1-m10) == AFF_CHEONGEUN_WITH_FALL -> AFF_CHEONGEUN.
@fixme462: char.cpp dosyasýnda görev bayraðý düzeltmesi, örneðin kostüm saklama.
@fixme463: input_main.cpp dosyasýnda, 40. seviyenin altýnda lonca kurulamýyor.
@fixme464: cmd_gm.cpp dosyasýnda evcil hayvanýn silinme düzeltmesi.
@fixme465: char_skill.cpp dosyasýnda, büyü saldýrýsý doðru bonusu verir.
@fixme466: char.cpp dosyasýnda, binekteki hata geçici olarak düzeltildi (biniþ sonrasýnda kick hatasý) - Belki.msa veya proto doðru deðil!
@fixme467: char_item.cpp dosyasýnda, efsunlama baþarý oraný düzeltildi.
@fixme468: item.cpp dosyasýnda, zaman aþýmý süresinden sonra silah kostümü envantere döner.
@fixme469: char_battle.cpp dosyasýnda, arena haritasýnda hiçbir þey býrakýlamaz.
@fixme470: char.cpp dosyasýnda maðaza adý kontrolü - izin verilip verilmediði.
@fixme471: char_item.cpp dosyasýnda, "pick" tetikleyicisinin doðru çalýþmasý saðlandý.
@fixme472: char_item.cpp dosyasýnda, bellek sýzýntýsý düzeltildi.
@fixme473: input_login.cpp dosyasýnda, login aþamasýnda iþlenmeyen paket düzeltildi (header 100).
@fixme474: char_battle.cpp dosyasýnda, "Shooting Dragon" hatasý düzeltildi.
@fixme475: Main.cpp dosyasýnda, DBManager.Quit() yoruma alýndý.
@fixme476: char_battle.cpp dosyasýnda, oyuncular kaydýrma pozisyonlarýný kaydedemez (dd haritalarýnda engellenir).
@fixme477: party.cpp dosyasýnda ölü oyunculara teleport yapýlamaz.
@fixme478: questpc.cpp dosyasýnda, diðer görev durumlarýnda "hatýrlanan" eþyalar.
@fixme479: char.h dosyasýnda, uint16_t -> uint32_t (Acce-Fix).
@fixme480: char.cpp dosyasýnda, pozisyon ayarlama IsDoor().
@fixme481: char_item.cpp dosyasýnda, bineðin zaten donatýlýp donatýlmadýðý kontrol edilir (KULLANILMIYOR).
@fixme482: char_item.cpp dosyasýnda, Polimorf (Dönüþüm) olduðunda bufflar kaldýrýlýr.
@fixme483: dragon_soul_table.cpp dosyasýnda, DRAGON_SOUL_GRADE_MAX -> DRAGON_SOUL_STEP_MAX.
@fixme484: DragonSoul.cpp dosyasýnda, DRAGON_SOUL_STEP_MAX -> DRAGON_SOUL_GRADE_MAX.

@fixme485:
@fixme486: char_battle.cpp dosyasýnda yansýtma hatasý kötüye kullanýmýný önleme.
@fixme487: char_battle.cpp dosyasýnda yeni MANASHIELD % olarak hesaplandý.
@fixme488: cmd_general.cpp dosyasýnda monarþiyi warp etmeyi engelleme.
@fixme489: char_item.cpp dosyasýnda envanter doluysa sandýk açmayý engelle.
@fixme490: char_item.cpp dosyasýnda envanteri sýralama engellendi.
@fixme491: char_item.cpp dosyasýnda ayný malzeme ile rafinasyon çökme hatasý düzeltildi.
@fixme492: New_PetSystem.cpp dosyasýnda null pointer hatasý düzeltildi.
@fixme493: char_skill.cpp dosyasýnda SKILL_FLAG_STUN hatasý düzeltildi (Grup Buffer nedeniyle - Yetenek süresi/hesaplamasý genelde hatalýydý). Test edilmeli.
@fixme494: questlua_pc.cpp dosyasýnda imparatorluk deðiþimi yapýldýðýnda grup varsa öncelikle gruptan ayrýl.
@fixme495:
@fixme496: questlua_global.cpp dosyasýnda Warp_all_to_village fonksiyonu çalýþanlarý da dýþarýda býrakýyordu.
@fixme497: questlua_global.cpp dosyasýnda Syserr hatalarýnýn LUA içinde etkinleþtirilmesi saðlandý.
@fixme498:
@fixme499: battle.cpp dosyasýnda saldýrý mesafesi düzeltildi.
@fixme500: char.cpp dosyasýnda düzeltme yapýldý.
@fixme501: cmd_gm.cpp ve cube.cpp dosyalarýnda yang hatasý düzeltildi; uint32_t yerine int kullanýldý.
@fixme502: char_item.cpp dosyasýnda kamp ateþi düzeltmesi.
@fixme503: battle.cpp ve pvp.cpp dosyalarýnda bekleme hack düzeltmesi.
@fixme504: char_battle.cpp dosyasýnda düzeltme yapýldý.
@fixme505: cmd_emotion.cpp dosyasýnda saldýrý veya hareket esnasýnda duygu (emotion) kullanýlamaz.
@fixme506: char_skill.cpp dosyasýnda eksik beceriler eklendi.
@fixme507: char_item.cpp dosyasýnda anti-sonlandýrma efekti.
@fixme508: char.h dosyasýnda POINT_MAX 255'in üzerinde (KULLANILMIYOR).
@fixme509: questmanager.cpp dosyasýnda reload q düzeltmesi.
@fixme510: char_battle.cpp dosyasýnda pelerin etkisi birleþtirildi.
@fixme511: char_skill.cpp dosyasýnda GDF düzeltmesi.
@fixme512: char_skill.cpp dosyasýnda ninja görünmezken saldýrýyý göz ardý et.
@fixme513: cmd_general.cpp dosyasýnda düzeltme yapýldý.
@fixme514: dungeon.cpp dosyasýnda düzeltme yapýldý.
@fixme515: Kod genelinde (it++ -> ++it || nullptr -> nullptr) optimizasyonu.
@fixme516: item.h dosyasýnda (virtual void to void || &override).
@fixme517: char_battle.cpp dosyasýnda DeathBlow - savaþçý dýþýndaki üç sýnýf için daha fazla hasar.
@fixme518: cube.cpp dosyasýnda reload düzeltmesi.
@fixme519: ---; uint8_t türünün uint16_t olarak rafine edilmesi düzeltildi.
@fixme520: char.cpp dosyasýnda evcil hayvan çift bonus hatasý düzeltildi.
@fixme521: cube.cpp dosyasýnda çekirdek çökme düzeltmesi.
@fixme522: char_battle.cpp ve char_item.cpp dosyalarýnda farklý haritalarda Grup Exp/Yang/Düþüþ Paylaþýmý düzeltildi.
@fixme523: ClientManager.cpp ve safebox.cpp dosyalarýnda kasa bellek sýzýntýsý düzeltildi.
@fixme524: questlua_npc.cpp dosyasýnda nadir çekirdek çökme hatasý düzeltildi.
@fixme525: shop_manager.cpp dosyasýnda bellek sýzýntýsý düzeltildi.
@fixme526: cmd_gm.cpp dosyasýnda ch -> tch olarak güncellendi.
@fixme527: item_manager.cpp dosyasýnda çekirdek çökmesini önleme.
@fixme528: input_main.cpp dosyasýnda hýzlý slot düzeltmesi.
@fixme529: cmd_gm.cpp dosyasýnda lonca yapýsý eþyalarýnýn kullanýlabilirliði saðlandý.
@fixme530: char.cpp dosyasýnda cinsiyet deðiþtirme, yeniden yükleme olmadan mümkün.
@fixme531: char.cpp dosyasýnda kanal deðiþtirirken tekrar düzeltme.
@fixme532: x; 255 bonus uzantýsý.
@fixme533: marriage.cpp ve questlua_marriage.cpp dosyalarýnda düðün düzeltmeleri.
@fixme534: char_battle.cpp dosyasýnda direnç etkinliði çökme düzeltmesi.
@fixme535: char_item.cpp dosyasýnda otomatik eþya verme düzeltmesi.
@fixme536: questlua_pc.cpp dosyasýnda Durum Sýfýrlama - -1 Durum puaný geçersizdir.
@fixme537: length.h dosyasýnda SHOP_TAB_COUNT_MAX 2 olarak ayarlandý -> çünkü ShopEx 3 ile hata veriyor.
@fixme538: mining.cpp dosyasýnda maksimum EXP alýmý rafinasyonu yok sayar.
@fixme539: dungeon.cpp dosyasýnda yalnýzca canavarlar ve taþlar silinir.
@fixme540: libthecore - utils.c dosyasýnda rastgele-fix düzeltmesi.
@fixme541: Performans düzenlemesi [Önek ++/-- operatörleri, ilkel olmayan türler için tercih edilmelidir.]
@fixme542: item_attribute.cpp dosyasýnda nadir çekirdek çökme hatasý düzeltmesi.
@fixme543: char_item.cpp dosyasýnda çökme düzeltmesi - ölü iken eþya alýnamaz!
@fixme544: input_main.cpp dosyasýnda hasar/menzil hack düzeltmesi.

@custom001: char_affect.cpp dosyasýnda iksirler için gösterim.
@custom002: polymorph.cpp, char_affect.cpp, char_item.cpp dosyalarýnda Polimorf (þekil deðiþtirme) harita kara listesi.
@custom003: char_battle.cpp dosyasýnda Ekstra EXP Yüzüðü Bonusu eklendi.
@custom004: (Açýklama yok)
@custom005: char_horse.cpp dosyasýnda IS_MOUNTABLE_ZONE (Binilebilir Alan).
@custom006: char_item.cpp dosyasýnda belirli haritalarda standart evcil hayvan kullanýmý engellendi [IS_BLOCKED_PET_SUMMON_MAP].
@custom007: char_item.cpp dosyasýnda özellikleri deðiþtirme/ekleme engellendi [Jungheld düzeltmesi].
@custom008: char_item.cpp dosyasýnda MoveItem -> DestCell iþlemi.
@custom009: char_item.cpp dosyasýnda kemerde tüm öðelere izin verme.
@custom010: char_skill.cpp dosyasýnda PAERYONG becerisi düþman merkezinde.
@custom011: cmd_gm.cpp dosyasýnda kullanýcý koordinatlarý listelendi.
@custom012: char_item.cpp dosyasýnda Üçlü Savaþ sýrasýnda binek kullanýmý devre dýþý býrakýldý.
@custom013: char_manager.cpp dosyasýnda fýsýltý (whisper) sayacý sýfýrlandý.
@custom014: char_state.cpp dosyasýnda yeni doðma (respawn) ayarlarý.
@custom015: cmd_emotion.cpp dosyasýnda ayný cinsiyete sahip karakterler arasýnda duygu (emotion) kullanýmý.
@custom016: cmd_emotion.cpp dosyasýnda maske olmadan duygu (emotion) kullanýmý.
@custom017: cmd_general.cpp dosyasýnda at kontrolcüsü.
@custom018: (Açýklama yok)
@custom019: desc_client.cpp dosyasýnda kanal durumu güncelleme süresi.
@custom020: exchange.cpp ve shop.cpp dosyalarýnda takas efekti.
@custom021: char_item.cpp ve fishing.h dosyalarýnda yeni inciler.
@custom022: input_main.cpp dosyasýnda donmuþ sohbet (frozen Chat).
@custom023: input_main.cpp dosyasýnda belirli haritalarda dükkan açmaya izin verilmedi (CanOpenShopHere).
@custom024: item_attribute.cpp dosyasýnda çift özellik deðiþtirme.
@custom025: questlua_pc.cpp dosyasýnda GM yetkilerinin komuta göre sýnýrlandýrýlmasý [/strip].
@custom026: char_item.cpp dosyasýnda nadir bonuslar etkinleþtirildi.
@custom027: char_item.cpp dosyasýnda Vnum[27874] üzerinde kötü etkiler (BadAffect) kaldýrýldý.
@custom028: char_item.cpp dosyasýnda tüm "zýrh öðeleri" deðiþtirilebilir.
@custom029: char_item.cpp dosyasýnda attr_always_add => (belirtilmemiþ)
@custom030: char_item.cpp dosyasýnda attr_always_5_add => (belirtilmemiþ)
@custom031: char_item.cpp dosyasýnda %4 bonus.
@custom032: char_item.cpp dosyasýnda su ve harman öðeleri ayný anda kullanýlamaz.
@custom033: input_login dosyasýnda OX-Event Giriþ Yok.
@custom034: (Açýklama yok)
@custom035: (Açýklama yok)
@custom036: shop.cpp dosyasýnda satýldýktan sonra otomatik kapanma.
@custom037: (Açýklama yok)
@custom038: cmd_general.cpp dosyasýnda bekleme süresi sýralamasý.
@custom039: char_item.cpp dosyasýnda otomatik iksir etkisi.

@infome000: Ýlginç olabilecek bir þey.
@infome001: char_item.cpp dosyasýnda Weihnachtstruhe TEST.
*/
#endif

