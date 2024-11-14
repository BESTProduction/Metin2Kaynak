/*
Author: BestStudio
Filename: CommonDefines.hpp
Project Name: Tuyobi2 SF Project
Last Revision: 01.11.2024
*/
#ifndef __INC_METIN2_COMMON_DEFINES_H__
#define __INC_METIN2_COMMON_DEFINES_H__

enum eCommonDefines {
	//DEFINES						//VALUE				//A�IKLAMA											// VARSAYILAN
	EVENT_MOB_RATE_LIMIT			= 1000,				// Etkinlikteki canavar oran� limiti				// 1000
	MAP_ALLOW_LIMIT					= 45,				// Harita s�n�r limiti								// 32
	PRIV_EMPIRE_RATE_LIMIT			= 200,				// �mparatorluk oran� limiti						// 200
	PRIV_EMPIRE_TIME_LIMIT			= 60*60*24*7,		// �mparatorluk oran� s�resi (saniye cinsinden 1 hafta)	// 60*60*24*7 [1 hafta]
	PRIV_GUILD_RATE_LIMIT			= 50,				// Lonca oran� limiti								// 50
	PRIV_GUILD_TIME_LIMIT			= 60*60*24*7,		// Lonca oran� s�resi (saniye cinsinden 1 hafta)	// 60*60*24*7 [1 hafta]
	PRIV_PLAYER_RATE_LIMIT			= 100,				// Oyuncu oran� limiti								// 100
	GUILD_GRADE_NAME_MAXLEN			= 8,				// Lonca r�tbe ad� maksimum uzunlu�u				// 8
	GUILD_GRADECOUNT				= 15,				// Lonca r�tbe say�s�								// 15
	GUILD_COMMENT_MAXCOUNT			= 12,				// Lonca yorum maksimum say�s�						// 12
	GUILD_COMMENT_MAXLEN			= 50,				// Lonca yorum maksimum uzunlu�u					// 50
	GUILD_BASEPOWER					= 400,				// Lonca temel g�c�									// 400
	GUILD_POWER_PER_SKILL_LEVEL_	= 200,				// Lonca beceri ba��na g��							// 200
	GUILD_POWER_PER_LEVEL_			= 100,				// Lonca seviye ba��na g��							// 100
	GUILD_MINIMUM_LEADERSHIP_		= 40,				// Lonca minimum liderlik puan�						// 40
	GUILDWAR_MIN_MEMBER_COUNT		= 1,				// Bir GK i�in minimum oyuncu say�s�				// 8
	GUILD_LADDERPOINT_PER_LEVEL		= 1000,				// Lonca seviye ba��na merdiven puan�				// 1000
	GUILD_CREATE_ITEMVNUM			= 70101,			// Lonca olu�turmak i�in gereken e�ya numaras�		// 70101
	PARTY_CAN_JOIN_MAX_LEVEL		= 30,				// Parti kat�lma i�in maksimum seviye				// 30
	DISAPPEARANCE_KILLED_MONSTER	= 10,				// �ld�r�len canavar�n yok olma s�resi				// 10
	REVIVEINVISIBLE_TIME			= 5,				// Yeniden canlanma g�r�nmezlik s�resi				// 5
	STONE_FAILURE0					= 80,				// Ta� y�kseltme ba�ar� oran�						// 80
	STONE_FAILURE1					= 70,				// Ta� y�kseltme ba�ar� oran�						// 70
	STONE_FAILURE2					= 60,				// Ta� y�kseltme ba�ar� oran�						// 60
	STONE_FAILURE3					= 50,				// Ta� y�kseltme ba�ar� oran�						// 50
	STONE_FAILURE4					= 40,				// Ta� y�kseltme ba�ar� oran�						// 40
	SB_NEED_EXP						= 20000,			// Becerikitab� i�in gereken deneyim				// 20000
	SB_C_NEED_EXP					= 20000,			// 9. beceriler i�in gereken deneyim				// 20000
	OWNERSHIP_EVENT_TIME			= 300,				// Etkinlik sahiplilik s�resi						// 300
	MIN_ADDON_FKS					= -30,				// Minimum FKS de�eri								// -30
	MAX_ADDON_FKS					= 30,				// Maksimum FKS de�eri								// 30
	MIN_ADDON_DSS					= 32767,			// Minimum DSS de�eri								// 32767
	MAX_ADDON_DSS					= 32767,			// Maksimum DSS de�eri								// 32767
	SERVER_STATE_CACHE_EXPIRATION	= 5*60,				// Kanal durumu g�ncelleme s�resi					// 5*60 [5 dakika]
	PC_MOVE_SPEED					= 100,				// Oyuncu hareket h�z�								// 100
	PC_ATT_SPEED					= 100,				// Oyuncu sald�r� h�z�								// 100
	PC_CAST_SPEED					= 100,				// Oyuncu b�y� h�z�									// 100
	PC_MAX_ATT_SPEED				= 170,				// Maksimum oyuncu sald�r� h�z�						// 170
	MOB_MAX_ATT_SPEED				= 250,				// Maksimum canavar sald�r� h�z�					// 250
	PC_MAX_MOVE_SPEED				= 200,				// Maksimum oyuncu hareket h�z�						// 200
	MOB_MAX_MOVE_SPEED				= 250,				// Maksimum canavar hareket h�z�					// 250
	ITEM_FLOOR_TIME					= 30,				// E�yalar�n yerde kalma s�resi						// 30
	ITEM_DEST_TIME_AUTOITEM			= 300,				// Otomatik verilen e�yan�n yok olma s�resi			// 300
	ITEM_DEST_TIME_DROPITEM			= 150,				// D���r�len e�yan�n yok olma s�resi				// 150
	ITEM_DEST_TIME_DROPGOLD			= 300,				// D���r�len alt�n�n yok olma s�resi				// 300

	MAX_RANK_POINTS					= 20000,			// Maksimum s�ralama puan�							// 20000
	START_LEVEL						= 1,				// Ba�lang�� seviyesi								// 1
	START_GOLD						= 0,				// Ba�lang�� alt�n�									// 0
	START_WON						= 0,				// Ba�lang�� won									// 0		[ENABLE_CHEQUE_SYSTEM]
	START_GEM						= 0,				// Ba�lang�� gaya									// 0		[ENABLE_GEM_SYSTEM]
	DROPABLE_GOLD_LIMIT				= 100000,			// D���r�lebilir alt�n limiti						// 1000
	ITEM_COUNT_LIMIT				= 250,				// Maks. y���n e�yas� say�s�						// 200
	ITEM_BONUS_CHANGE_TIME			= 60,				// E�ya bonus de�i�iklik s�resi						// 60
	STATUSPOINT_GET_LEVELLIMIT		= 90,				// Seviye s�n�r�nda al�nan stat puan�				// 90
	STATUSPOINT_SET_MAXVALUE		= 90,				// Stat puan� maksimum de�eri						// 90
	SHOUT_LIMIT_LEVEL				= 15,				// Shout yapabilmek i�in gerekli minimum seviye		// 15
	PLAYER_MAX_LEVEL				= 120,				// Maksimum oyuncu seviyesi							// 99
	CONQUEROR_MAX_LEVEL				= 30,				// Maksimum fetih seviyesi							// 30		[ENABLE_YOHARA_SYSTEM]
	SKILLBOOK_NEXT_READ_MIN			= 28800,			// Beceri kitab� i�in gereken minimum deneyim		// 28800
	SKILLBOOK_NEXT_READ_MAX			= 43200,			// Beceri kitab� i�in gereken maksimum deneyim		// 43200
	RANGE_PICK						= 600,				// E�ya alma menzili								// 300
	SUNGMA_ATTR_PROB				= 40,				// Sungma e�yalar�n�n de�i�me olas�l���				// 40
	PREMIUM_PRIVATE_SHOP_DEFAULT_TIME = 60 * 24,		// Offline d�kk�n a�ma s�resi [1 g�n]				// 60 * 24

	CL_TRANSMUTATION_PRICE			= 15000000,			// Transmutasyon maliyeti							// 15000000	[ENABLE_CHANGE_LOOK_SYSTEM]
	PET_INCUBATRICE_COST			= 100000,			// Kulu�ka maliyeti									// 100000	[ENABLE_GROWTH_PET_SYSTEM]
	IMMUNE_PCT						= 90,				// Savunma aktifken ba����kl�k oran�				// 90		[ENABLE_IMMUNE_PERC]
	SHAM_ASSA_ATT_BONUS				= 15,				// PvE i�in % sald�r� bonusu						// 15		[ENABLE_SHAM_ASSA_ATT_BONUS]
	KK_ATT_BONUS_AGAINST_NH			= 10,				// PvP i�in % sald�r� bonusu						// 10		[ENABLE_KK_ATT_BONUS_AGAINST_NH]
	ANNOUNCEMENT_REFINE_SUCCES_MIN_LEVEL	= 9,		// Ka��nc� seviyede duyuru yap�laca��				// 9		[ENABLE_ANNOUNCEMENT_REFINE_SUCCES]
	ITEM_LEVEL_LIMIT				= 64,				// G�sterilmeyen seviye s�n�r�						// 64		[ENABLE_ANNOUNCEMENT_REFINE_SUCCES]
	MEMBER_COUNT_BONUS				= 6,				// Lonca �ye say�s�na g�re bonus					// 6		[ENABLE_GUILDRENEWAL_SYSTEM]
	AFK_TIME_LIMIT					= 3,				// AFK modu s�resi (dakika cinsinden)				// 3		[ENABLE_AFK_MODE_SYSTEM]
	SOULUNBIND_TIME					= 72,				// Ruh ��zme s�resi [saat cinsinden]				// 72		[ENABLE_SEALBIND_SYSTEM]
	AFTERDEATH_SHIELD_DURATION		= 3,				// �l�m sonras� koruma s�resi (saniye cinsinden)	// 15		[ENABLE_AFTERDEATH_SHIELD]
	OFFLINESHOP_OPEN_TIME			= 10,				// Offline d�kk�n�n a��k kalma s�resi				// 60*24*3	[ENABLE_PREMIUM_PRIVATE_SHOP]
	MAX_FARMING_ACCOUTS				= 2,				// HWID ba��na maksimum hesap say�s�				// 2		[ENABLE_MULTI_FARM_BLOCK]
	BATTLE_FIELD_KILL_TIME			= 60,				// Sava� alan�nda �ld�rme s�resi (saniye)			// 600		[ENABLE_BATTLE_FIELD]
	DS_ATTR_CHANGE_PRICE			= 500000,			// DS nitelik de�i�tirme maliyeti					// 500000	[ENABLE_DS_CHANGE_ATTR]
	PERCENT_ADD_BONUS_ELEMENTS_SPELL = 25,				// Element ba�ar� oran�								// 50		[ENABLE_REFINE_ELEMENT]
	SOUL_COLLECT_PERC				= 10,				// Ruh toplama oran�								// 10		[ENABLE_SUMMER_EVENT_ROULETTE]
	FISHING_NEED_CATCH				= 3,				// Bal�k tutma i�in gereken yakalama say�s�			// 3

	// Zindan Ayarlar�
	MELEY_MIN_LVL					= 3,				// Meley zindan� i�in minimum seviye				// 3		[ENABLE_GUILD_DRAGONLAIR_SYSTEM]
	MELEY_LADDER_POINTS_COST		= 600,				// Meley zindan� giri� puan� maliyeti				// 600		[ENABLE_GUILD_DRAGONLAIR_SYSTEM]
	MELEY_LADDER_POINTS_RETURN		= 300,				// Meley zindan� puan� geri iadesi					// 300		[ENABLE_GUILD_DRAGONLAIR_SYSTEM]
	MELEY_COOLDOWN_DUNGEON			= 10800,			// Meley zindan� bekleme s�resi						// 10800	[ENABLE_GUILD_DRAGONLAIR_SYSTEM]
	WEATHER_REFRESH_TIMER			= 60,				// Hava durumu g�ncelleme s�resi [saniye]			// 60 * 5	[ENABLE_WEATHER_INFO]
	WEATHER_RAIN_PERC				= 5,				// Ya�mur olas�l���									// 1		[ENABLE_WEATHER_INFO]
	RAIN_SNOW_ACTIVE_TIME			= 30,				// Ya�mur/snow aktif kalma s�resi [dakika]			// 30		[ENABLE_WEATHER_INFO]

	CHECK_PICKUP_HACK				= 10,				// E�ya al�m hilesini kontrol etme					// 10
	PICKUP_RANGE					= 150,				// E�ya al�m mesafesi								// 300		[ENABLE_CHECK_PICKUP_HACK]
	PICKUP_RANGE_TOLERANCE			= 100,				// E�ya al�m tolerans�								// 150		[ENABLE_CHECK_PICKUP_HACK]
};

/*
//------Sunucu Komutlar�------>
ENABLE_EVENT_BANNER_FLAG							// /banner 1 easter � Paskalya etkinli�i i�in banner etkinle�tirme komutu
ENABLE_BATTLE_FIELD									// /e battlefield_status 1 � Sava� alan� durumu komutu
*/

#define __FAKE_PLAYER__

//------TAMAMLANMAMI�------>
#define ENABLE_PULSE_MANAGER						// Olaylar�n zamanlanm�� kontrol�n� y�neten yap� (tamamlanmam��)
#define ENABLE_SKILL_TABLE_RENEWAL					// Skill (beceri) tablosunun g�ncellenmesi (tamamlanmam��)


//////////////////////////////////////////////////[SADECE OYUN KAYNA�I]//////////////////////////////////////////////////
#define ENABLE_MEMORY_LEAK_FIX						// Bellek s�z�nt�s�n� �nlemek i�in d�zeltme etkin
//#define ENABLE_HAND_SHAKE_LIMIT					// El s�k��ma komut s�n�r�
#define ENABLE_PROXY_IP								// Proxy IP deste�ini etkinle�tirir
/* 
BIND_IP: <�zel IPv4 IP> (�zel IP s�n�f�nda, "ifconfig" komutuyla makinenin IP'sini kontrol edebilirsiniz)
PROXY_IP: <Genel IPv4 IP> (IP'nizi ��renmek i�in https://www.whatismyip.com gibi bir site kullan�n)
*/

//------G�VENL�K------>
#define ENABLE_PORT_SECURITY							// db_port, p2p_port ve uzaktan y�netim sayfas� a��klar�n� engeller
#define ENABLE_MAIN_HACK								// Ana hack korumas�
//#define ENABLE_CSHIELD								// CShield korumas�n� etkinle�tir
	#ifdef ENABLE_CSHIELD								// CShield korumas�n� etkinle�tir
		#define ENABLE_CHECK_GHOSTMODE					// Oyuncunun hayalet mod kullan�p kullanmad���n� kontrol eder
		#define ENABLE_CHECK_WALLHACK					// Oyuncu konumunu duvar hilesi i�in kontrol eder
		#define ENABLE_CHECK_PICKUP_HACK PICKUP_RANGE+PICKUP_RANGE_TOLERANCE // Oyuncunun e�ya toplama hilesi kullan�p kullanmad���n� kontrol eder. // �nemli: CPythonPlayer::SendClickItemPacket�teki toplama s�resini kontrol edin. E�er bu �zellik yoksa, bu tan�m� devre d��� b�rak�n.
		#define ENABLE_CHECK_ATTACKSPEED_HACK			// Oyuncunun �ok h�zl� sald�r�p sald�rmad���n� kontrol eder
		#define ENABLE_CHECK_MOVESPEED_HACK				// Oyuncunun �ok h�zl� hareket edip etmedi�ini kontrol eder
		#define ENABLE_CHECK_WAIT_HACK					// Oyuncunun bekleme hilesi kullan�p kullanmad���n� kontrol eder
		#define ENABLE_CHECK_VALID_FISH_POSITION		// Bal�k tutma pozisyonunun ge�erlili�ini kontrol eder
		#define ENABLE_CHECK_ANTI_SAFEZONE				// G�venli b�lgeye kar�� koruma kontrol�
		#define ENABLE_CHECK_SKILL_HACK					// Oyuncunun yetenek hilesi kullan�p kullanmad���n� kontrol eder
	#endif
#define FLUSH_AT_SHUTDOWN								// Kapan��ta �nbelle�i temizler
//#define ENABLE_SYSLOG_PACKET_SENT						// G�nderilen Paket Ba�l���n� Syslog�a g�nderir


//--------S�STEMLER------->


//--------SE�ENEKLER------->
#define ENABLE_REVERSED_FUNCTIONS					// Resmi fonksiyonlar etkin
#define ENABLE_SYNCPOSITION_DISCONNECT_FIX			// Pozisyon senkronizasyonu ba�lant� kesme hatas�n� giderir
#define ENABLE_EXTENDED_RELOAD						// Geni�letilmi� yeniden y�kleme komutlar�
#define ENABLE_CMS_ITEMSHOP							// Oyun i�i e�ya ma�azas�
#define ENABLE_GM_BLOCK								// GM (Y�netici) engelleme sistemi
#define ENABLE_CHECK_WINDOW_RENEWAL					// Pencere yenileme kontrol�
#define ENABLE_PVP_BALANCE							// PvP dengesi, resmi oyun gibi
#define ENABLE_AFFECT_RENEWAL						// Etki yenileme sistemi
#define ENABLE_REFINE_ABILITY_SKILL					// Yetenek geli�tirme sistemi (Schmiedeskill)
#define ENABLE_ATTRIBUTE_CHANGE_ON_START_ITEM		// Ba�lang�� e�yas�nda �zellik de�i�ikli�i
#define ENABLE_ANNOUNCEMENT_REFINE_SUCCES			// Ba�ar�l� geli�tirmeleri duyurma
#define ENABLE_ANNOUNCEMENT_LEVELUP					// Seviye atlama duyurular�
#define ENABLE_AGGROMOB_SAFEZONE_SKIP				// Safezone (g�venli b�lge) i�indeki d��manlar� atlama
#define ENABLE_GUILDLAND_INACTIVITY_DELETE			// Lonca topraklar�n�n hareketsizlikte silinmesi
#define ENABLE_EFFECT_FOR_TRADE						// Tamamlanan takas sonras� efekt
#define ENABLE_BLOCK_SKILL_OXEVENT					// OX etkinli�inde yetenek kullan�m� engelleme
#define ENABLE_BLOCK_BUFF_IN_MAP					// Belirli haritalarda buff (g��lendirme) kullan�m�n� engelleme
#define ENABLE_HORSESKILLS_ON_MOUNTS				// Bineklerde at yeteneklerinin kullan�m�
#define DISABLE_RIDE_ON_SPECIAL_MAP					// �zel haritalarda binme k�s�tlamas�
#define ENABLE_RITUAL_STONE							// Rit�el ta�� etkinli�i
#define ENABLE_SEAL_OF_GOD							// Tanr�lar�n m�hr� sistemi
#define ENABLE_SHAMAN_PARTY_BUFF_SYSTEM				// �aman 1 t�klama grup buff�� ve kendine buff
#define ENABLE_SHAM_ASSA_ATT_BONUS					// �aman ve suikast��lara PvE'de % sald�r� bonusu
//#define ENABLE_KK_ATT_BONUS_AGAINST_NH			// PvP sistemi: KK'nin NH'ye kar�� ekstra hasar�
#define ENABLE_DROP_GOLD							// Alt�n d���rme sistemi
#define ENABLE_GOLD_MULTIPLIER						// Alt�n �arpan sistemi
#define ENABLE_GOLD10_PCT							// Alt�n %10 �arpan�
#define ENABLE_BLOCK_CHEST_INVENTORY_FULL			// Envanter dolu oldu�unda sand�k a�may� engelleme
//#define ENABLE_CANT_CREATE_SHOPS_IN_OTHER_EMPIRE	// Di�er imparatorluklarda d�kk�n a�may� engeller
#define ENABLE_ARENA_FORBIDDEN_ITEMS_LIST			// Almanya klas�r�nden yasakl� e�ya listesi
#define ENABLE_HORSE_APPEARANCE						// Veritaban�nda saklanan at g�r�n�mleri
//#define ENABLE_MOUNT_ENTITY_REFRESH				// Binilen varl�klar�n yenilenmesi
#define ENABLE_EXTEND_ITEM_AWARD					// Ma�aza e�yalar�na bonus eklenebilir
//#define MOB_DROP_ITEM_RENEWAL						// Haritaya g�re e�ya d���rme sistemi etkin
//#define ENABLE_CUBE_COPY_ATTR						// K�pte �zellik kopyalamay� etkinle�tirir
#define ENABLE_PORTAL_NAMES							// Portal isimlerini g�sterir
#define ENABLE_MAP_NAME_INFO						// Harita isimleri sohbet ekran�nda g�r�nt�lenir
//#define ENABLE_CLEAN_BANNED_PLAYER_DATA			// Yasaklanan oyuncu verilerini temizleme
#define ENABLE_SET_STATES							// Durumlar� komutla ayarlama
	#ifdef ENABLE_SET_STATES
		#define SET_STATES_PRIVILEGES GM_PLAYER		// Yetkiler: GM_PLAYER, GM_LOW_WIZARD
	#endif
#define ENABLE_DUNGEON_MUSIC_FIX					// Zindan m�zi�i d�zeltmesi
#define ENABLE_POISON_FIX							// Zehir etkisi d�zeltmesi
//#define DISABLE_STONE_LV20_DROP					// 20. seviyede ta� d���rmeyi engeller
//#define DISABLE_BOSS_LV25_DROP					// 25. seviyede patron d���rmeyi engeller



//////////////////////////////////////////////////[OYUN KAYNA�I VE �K�L� DOSYALAR]//////////////////////////////////////////////////
//-----GENEL_KONULAR---->
//#define ENABLE_SEQUENCE_SYSTEM						//@fixme426
#define ENABLE_HWID_BAN									// HWID Y�neticisi (donan�m kimli�i ile ban sistemi)
	#ifdef ENABLE_HWID_BAN
		//#define ENABLE_HWID_BAN_EXTENDED				// Ba�ka bir HWID ile giri� yap�lmaya �al���ld���nda engeller; ekstra s�f�rlama fonksiyonu gerektirir
		#define ENABLE_MULTI_FARM_BLOCK					// �ift hesapla farm yapmay� engelleme
		#define GM_UNBAN_RIGHT 4						// Yasak kald�rma yetkisi seviyesi
		#define GM_BAN_RIGHT 4							// Yasaklama yetkisi seviyesi
		#define GM_HWID_BAN_RIGHT 4						// HWID ile yasaklama yetkisi seviyesi
		#define GM_DELETE_HWID_BAN_RIGHT 4				// HWID yasa��n� kald�rma yetkisi seviyesi
		#define GM_TOTAL_HWID_BAN_RIGHT 4				// Genel HWID yasaklama yetkisi seviyesi
	#endif


//-----PROTO_YAPISI---->
#define ENABLE_PROTO_RENEWAL							// Resmi Proto Yap�s�
#define ENABLE_PROTO_RENEWAL_CUSTOM						// �zel sistemler i�in Proto de�i�iklikleri
#define ENABLE_NEW_DISTANCE_CALC						// Mesafe hesaplama yenilemesi


//------KARAKTERLER------>
#define ENABLE_PLAYER_PER_ACCOUNT5						// Bir hesapta 5 karaktere izin verir
#define ENABLE_WOLFMAN_CHARACTER						// Kurt Adam karakteri
	#ifdef ENABLE_WOLFMAN_CHARACTER
		//#	define USE_MOB_BLEEDING_AS_POISON			// Kanama etkisi devre d��� b�rak�l�r ve zehir olarak i�lev g�r�r
		//#	define USE_MOB_CLAW_AS_DAGGER				// Pen�e sald�r�s� devre d��� b�rak�l�r ve han�er olarak i�lev g�r�r
		//#	define USE_ITEM_BLEEDING_AS_POISON			// Zehir bonusu kanama etkisini savunabilir (kanama devre d��� b�rak�l�r)
		//#	define USE_ITEM_CLAW_AS_DAGGER				// Han�er savunmas� pen�e sald�r�s�n� savunabilir (pen�e devre d��� b�rak�l�r)
		#define USE_WOLFMAN_STONES						// Kurt adam ta�lar� metin ta�lar�ndan d��ebilir
		#define USE_WOLFMAN_BOOKS						// Kurt adam beceri kitaplar� d��ebilir
		#define USE_LYCAN_CREATE_POSITION				// Etkinle�tirilirse, kurt adam karakter olu�turma s�ras�nda kendi k�y�ne ta��n�r
	#endif


//--------S�STEMLER------->
#define ENABLE_MOB_SCALE							// mob_proto.txt �zerinden canavar �l�eklendirmesi
#define NEW_SELECT_CHARACTER						// Son oynanan karakteri se�me
#define WJ_SHOW_MOB_INFO							// Canavar seviyesi/Aggro g�sterimi
#define WJ_ENABLE_TRADABLE_ICON						// Ticaret yap�lamayan e�yalar� g�sterme
#define ENABLE_SWAP_SYSTEM							// Envanterdeki e�yalar� takas etme sistemi
#define ENABLE_PET_SYSTEM							// Pet sistemi
	#ifdef ENABLE_PET_SYSTEM
		#define PET_AUTO_PICKUP						// Pet otomatik e�ya toplama
	#endif
#define ENABLE_GROWTH_PET_SYSTEM					// Geli�en pet sistemi
	#ifdef ENABLE_GROWTH_PET_SYSTEM
		#define ENABLE_PET_ATTR_DETERMINE			// Petin �zellik belirleme sistemi
		#define ENABLE_PET_PRIMIUM_FEEDSTUFF		// Pet i�in premium yem
	#endif
#define ENABLE_ACCE_COSTUME_SYSTEM					// Kemer sistemi
#define ENABLE_AURA_SYSTEM							// Aura sistemi
	#ifdef ENABLE_AURA_SYSTEM
		#define ENABLE_AURA_BOOST					// Aura g��lendirme
	#endif
#define ENABLE_YOHARA_SYSTEM						// Fatih seviyesi + Sungma
	#ifdef ENABLE_YOHARA_SYSTEM
		#define ENABLE_NINETH_SKILL					// 9. beceri
		//#define ENABLE_PASSIVE_SYSTEM				// Kal�nt� penceresi [tamamlanmam��]
	#endif
#define ENABLE_GLOVE_SYSTEM							// Eldiven e�yas� sistemi
	#ifdef ENABLE_GLOVE_SYSTEM
		#define ENABLE_GLOVE_ITEM_ATTR				// item_attr tablosu
	#endif
#define ENABLE_REFINE_ELEMENT						// Element set sistemi [Worldard]
#define ENABLE_GUILDSTORAGE_SYSTEM					// Lonca deposu
#define ENABLE_SPECIAL_INVENTORY					// �zel envanter [Sanii]
#define ENABLE_DS_GRADE_MYTH						// Mitolojik derece
#define ENABLE_DS_CHANGE_ATTR						// Ejderha Ta�� niteli�ini de�i�tirme
#define ENABLE_DS_REFINE_WINDOW						// Ejderha Ta�� geli�tirme penceresi
#define ENABLE_DS_SET								// Ejderha Ta�� set sistemi
#define ENABLE_MOUNT_COSTUME_SYSTEM					// Binek kost�m yuvas�n� etkinle�tir
	#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
		#define ENABLE_MOUNT_PROTO_AFFECT_SYSTEM	// Binek prototipi efekt sistemi
		#define ENABLE_CHANGE_LOOK_MOUNT			// Binek g�r�n�m de�i�tirme
		#define ENABLE_MOUNT_CHECK					// Binek kontrol sistemi
	//#	define ENABLE_NO_WAIT_TO_RIDE				// Binmeye bekleme s�resini kald�r
	#endif
#define ENABLE_WEAPON_COSTUME_SYSTEM				// Silah kost�m yuvas�n� etkinle�tir
	#ifdef ENABLE_WEAPON_COSTUME_SYSTEM
		#define ENABLE_ITEM_ATTR_COSTUME			// Silah, beden, sa� kost�m� i�in nitelik/ender �zellikler
	#endif
#define ENABLE_USE_COSTUME_ATTR						// Kost�m i�in nitelik de�i�tirme bonusunu etkinle�tir
#define ENABLE_MOVE_COSTUME_ATTR					// Kost�m bonus transferi
	#ifdef ENABLE_MOVE_COSTUME_ATTR
		#define ENABLE_MOVE_COSTUME_ACCE_ATTR		// Kost�m aksesuar niteliklerini transfer etme
	#endif
#define ENABLE_HIDE_COSTUME_SYSTEM					// Kost�m tasar�m�n� gizleme/g�sterme
#define ENABLE_CHANGED_ATTR							// Nitelik de�i�tirme sistemi
#define ENABLE_MAGIC_REDUCTION_SYSTEM				// B�y� diren� azaltma bonusunu etkinle�tir
	#ifdef ENABLE_MAGIC_REDUCTION_SYSTEM
		#define USE_MAGIC_REDUCTION_STONES			// Metin ta�lar�ndan b�y� diren� azaltma ta�� d��me
	#endif
#define ENABLE_PENDANT								// Kolye e�ya yuvas�
	#ifdef ENABLE_PENDANT
		#define ENABLE_ELEMENT_ADD					// Kolye i�in element ekleme
		#define ENABLE_PENDANT_ITEM_ATTR				// Kolye i�in nitelik/ender �zellik bonuslar�n� etkinle�tir
	#endif
#define ENABLE_MULTI_LANGUAGE_SYSTEM				// �oklu dil sistemi [Sonitex]
#define ENABLE_SEALBIND_SYSTEM						// Ruh ba�lama
#define ENABLE_CHEQUE_SYSTEM						// Won/�ek sistemi
	#ifdef ENABLE_CHEQUE_SYSTEM
		#define ENABLE_CHEQUE_EXCHANGE_WINDOW		// xP3ng3rx Won -> Yang / Yang -> Won de�i�im penceresi
	#endif
#define ENABLE_GACHA_SYSTEM							// Gacha Sistemi
#define ENABLE_BIOLOG_SYSTEM						// Biyolog Sistemi
#define ENABLE_AUTO_SYSTEM							// Otomatik Avlanma
	#ifdef ENABLE_AUTO_SYSTEM
		#define ENABLE_AUTO_RESTART_EVENT			// Otomatik avlanma i�in yeniden ba�latma etkinli�i
	#endif
#define ENABLE_RESEARCHER_ELIXIR_FIX				// Ara�t�rmac� iksir d�zeltmesi
#define ENABLE_678TH_SKILL							// 6., 7. ve 8. Pasif Beceriler
#define ENABLE_78TH_SKILL							// 7. ve 8. Pasif Beceriler
#define ENABLE_PASSIVE_ATTR							// Pasif nitelikler
	#ifdef ENABLE_PASSIVE_ATTR
		#define ENABLE_PRECISION					// Hassasiyet
		#define ENABLE_CHARISMA						// Karizma
		#define ENABLE_INSPIRATION					// �lham
	#endif
#define ENABLE_SWITCHBOT							// Efsunbotu [Sanii]
	#ifdef ENABLE_SWITCHBOT
		//#define ENABLE_IGNORE_TYPE_GREEN_ATTR_ITEM					// Ye�il nitelikli ��eleri yok sayma
		#define ENABLE_SWITCHBOT_PM										// PM'den switcher bitirme bildirimi
	#endif
#define ENABLE_BATTLE_PASS_SYSTEM										// Battle pass sistemi
	#ifdef ENABLE_BATTLE_PASS_SYSTEM
		#define RESTRICT_COMMAND_GET_INFO			GM_LOW_WIZARD		// Bilgi komutu k�s�tlamas�
		#define RESTRICT_COMMAND_SET_MISSION		GM_IMPLEMENTOR		// G�rev ayarlama k�s�tlamas�
		#define RESTRICT_COMMAND_PREMIUM_ACTIVATE	GM_IMPLEMENTOR		// Premium etkinle�tirme k�s�tlamas�
	#endif
#define ENABLE_CHANGE_LOOK_SYSTEM						// G�r�n�m de�i�tirme (Transmutasyon)
#define ENABLE_ATTR_6TH_7TH								// 6. ve 7. Bonus Tablosu
	#ifdef ENABLE_ATTR_6TH_7TH
		#define ENABLE_ATTR_6TH_7TH_EXTEND				// Yeni resmi bonuslar
		#define ENABLE_ATTR_6TH_7TH_ATTR_TABLE			// Nitelik tablosu
	#endif
#define ENABLE_SKILL_COLOR_SYSTEM						// Beceri renk de�i�imi [Owsap]
#define ENABLE_CUBE_RENEWAL								// K�p Yenileme
	#ifdef ENABLE_CUBE_RENEWAL
		#define ENABLE_CUBE_RENEWAL_COPY				// Nitelikleri kopyalama yetene�i
	#endif
#define ENABLE_VIP_SYSTEM								// VIP Sistemi
	#ifdef ENABLE_VIP_SYSTEM
		//#define ENABLE_SWITCHBOT_FOR_VIP					// Sadece VIP'ler Switchbot kullanabilir
		//#define ENABLE_SHAM_ASSA_ATT_BONUS_FOR_VIP		// Sadece VIP'ler �aman/Ninja PvE bonusu al�r
		//#define ENABLE_KK_ATT_BONUS_AGAINST_NH_FOR_VIP	// Sadece VIP'ler KK_ATT bonusunu NH'ye kar�� al�r
		//#define ENABLE_YANG_BOMB_FOR_VIP					// Sadece VIP'ler YangBomb �zelli�ini kullanabilir
		//#define ENABLE_TRANSMUTATION_FOR_VIP				// Sadece VIP'ler Transmutasyon yapabilir
		//#define ENABLE_DROP_INFO_FOR_VIP					// Sadece VIP'ler d��en e�yalar hakk�nda bilgi al�r
	#endif

#define ENABLE_PREMIUM_PRIVATE_SHOP								// Premium ki�isel d�kkan sistemi
	#ifdef ENABLE_PREMIUM_PRIVATE_SHOP
		#define ENABLE_OPEN_SHOP_WITHOUT_BAG					// �anta olmadan d�kkan a�ma
		#define ENABLE_OPEN_SHOP_ONLY_IN_MARKET					// Sadece pazarda d�kkan a�ma izni
		#define ENABLE_OPEN_SHOP_WITH_PASSWORD					// �ifre ile d�kkan a�ma
		#define ENABLE_PREMIUM_PRIVATE_SHOP_TIME				// D�kkan a��k kalma s�resi ayar� [SHOP_ACTIVITY etkin de�ilse]
		#define ENABLE_PREMIUM_PRIVATE_SHOP_TEXTTAIL			// D�kkan a��klama ba�l�klar�
		#define ENABLE_SHOP_NO_SPEND_MIN_IF_ONLINE				// �evrimi�iyken d�kkan a�ma s�resi harcamaz [Gelecekte tekrar g�zden ge�irilecek]
		//#define ENABLE_PRIVATESHOP_SYSTEM_ALWAYS_SILK			// T�m sat��lar Silk olarak
		//#define ENABLE_PRIVATE_SHOP_SEARCH_NEED_ITEM			// Arama sisteminde �zel gereksinimler
		//#define ENABLE_PRIVATSHOP_EXTENSIONS					// Ek �zellikler
		#define ENABLE_PRIVATESHOP_SEARCH_SYSTEM				// Ki�isel d�kkan arama sistemi
		#define ENABLE_PRIVATESHOP_SEARCH_PACKETFLOOD_TEMP_FIX	// Maksimum 800 giri� s�n�r� [Client ��kmesini �nlemek i�in paket y�klemesi azalt�lm��t�r]
	#endif
#define ENABLE_MYSHOP_DECO							// D�kkan dekorasyon sistemi
	#ifdef ENABLE_MYSHOP_DECO
		#define ENABLE_MYSHOP_DECO_PREMIUM			// Premium d�kkan dekorasyonlar�
		//#define ENABLE_MYSHOP_DECO_EXTENSION		// Ek dekorasyon �zellikleri
	#endif

#define ENABLE_MAILBOX								// Posta kutusu sistemi
#define ENABLE_DESTROY_SYSTEM						// E�yalar� yok etme sistemi
//#define ENABLE_GROUP_DAMAGE_WEAPON				// Grup hasar sistemi
#define ENABLE_INGAME_WIKI							// Oyun i�i bilgi rehberi
#define ENABLE_QUIVER_SYSTEM						// Ok yele�i sistemi
#define ENABLE_DUNGEON_INFO_SYSTEM					// Zindan bilgi sistemi
#define ENABLE_MOVE_CHANNEL							// Kanal de�i�tirme sistemi
#define ENABLE_QUEST_RENEWAL						// G�rev sayfas� yenileme
#define ENABLE_PARTY_MATCH							// Parti e�le�me sistemi
#define ENABLE_FISHING_RENEWAL						// Bal�k��l�k sistemi yenilemesi
#define ENABLE_WEATHER_INFO							// Otomatik hava durumu y�kleme


/*-----MiniGame*///----->
#define ENABLE_EVENTS										// Oyun i�i etkinlikler
	#ifdef ENABLE_EVENTS
		#define ENABLE_EVENT_MANAGER						// Etkinlik Bilgi Panosu
		#define ENABLE_EVENT_BANNER_FLAG					// Etkinlik Banner'�
		#define ENABLE_MINI_GAME							// Mini Etkinlikler Ba�l���

		// Resmi Etkinlikler
		//#define ENABLE_LUCKY_EVENT						// kullan�lm�yor
		#define ENABLE_MINI_GAME_OKEY_NORMAL				// Okey Kart Etkinli�i
		//#define ENABLE_MINI_GAME_YUTNORI					// Cad�lar Bayram�
		#define ENABLE_MONSTER_BACK							// Boss Avc�s�
			#ifdef ENABLE_MONSTER_BACK
				#define ENABLE_ACCUMULATE_DAMAGE_DISPLAY	// Hasar Toplama G�sterimi
				//#define ENABLE_10TH_EVENT					// 10. Y�l Etkinli�i
			#endif
		#define ENABLE_EASTER_EVENT							// Paskalya Etkinli�i
		#define ENABLE_SUMMER_EVENT							// kullan�lm�yor
		#define ENABLE_2017_RAMADAN							// Ramazan Etkinli�i [Sunucu Taraf�]
		#define ENABLE_NEW_HALLOWEEN_EVENT					// Yeni Cad�lar Bayram� Etkinli�i [Sunucu Taraf�]
		#define ENABLE_SOUL_SYSTEM							// Ruh Sistemi [Owsap]
		#define ENABLE_2016_VALENTINE						// Sevgililer G�n� Etkinli�i
		#define ENABLE_FISH_EVENT							// Bal�k Bulmaca Etkinli�i
		#define ENABLE_FLOWER_EVENT							// �i�ek Etkinli�i
		#define ENABLE_MINI_GAME_CATCH_KING					// Kral� Yakala Etkinli�i
		#define ENABLE_GEM_SYSTEM							// Gaya Sistemi
			#ifdef ENABLE_GEM_SYSTEM
				#define ENABLE_GEM_SHOP						// Gaya Ma�azas�
			#endif
		#define ENABLE_MINI_GAME_FINDM						// E�ya Bulma Etkinli�i
			#ifdef ENABLE_MINI_GAME_FINDM
			#	define ENABLE_MINI_GAME_FINDM_HINT			// E�ya Bulma �pu�lar�
			#endif
		#define ENABLE_SUMMER_EVENT_ROULETTE				// Kanl� Ay Etkinli�i
		#define ENABLE_MINI_GAME_BNW						// Siyah Beyaz Etkinli�i
		//#define ENABLE_BATTLE_ROYALE						// kullan�lm�yor
		#define ENABLE_METINSTONE_RAIN_EVENT				// Metin Ta�� Ya�muru Etkinli�i
		#define ENABLE_SOCCER_BALL_EVENT					// Futbol Topu Etkinli�i
		#define ENABLE_WORD_GAME_EVENT						// M-E-T-I-N-2 Kelime Oyunu

	#define ENABLE_WORLD_BOSS								// D�nya Boss Etkinli�i
		#ifdef ENABLE_WORLD_BOSS
			#define WORLD_BOSS_PHASE 6						// D�nya Boss Etkinli�i Evre 6
			#define BATTLE_PHASE 4							// Sava� Evresi
			#define COOLDOWN_PHASE 2						// So�uma Evresi

		#define ENABLE_WB_RANKING							// D�nya Boss S�ralamas�
			#ifdef ENABLE_WB_RANKING
				#define WB_MIN_DMG 60000					// S�ralama i�in Minimum Hasar 60000
			#endif
		#endif

		#define ENABLE_SUPERSTONE_RAIN_EVENT				// S�per Ta� Ya�muru Etkinli�i
		#define ENABLE_MINING_EVENT							// Madencilik Etkinli�i
	#endif


/*-----Zindanlar*///----->
#define ENABLE_DUNGEON_RENEWAL							// Yenilenmi� Zindan Sistemi
#define ENABLE_DUNGEON_DEAD_TIME_RENEWAL				// Zindan �l�m Zaman� Yenileme
#define ENABLE_ELEMENTAL_WORLD							// Elemental D�nya Etkinle�tirme
	#ifdef ENABLE_ELEMENTAL_WORLD
		#define DROP_PERC_ELEMENT_04 4					// Element %4 Drop Oran�
	#endif
#define ENABLE_DEVIL_TOWER								// �eytan Kulesi Zindan�
#define ENABLE_DEVIL_CATACOMBS							// �eytan Yeralt� Mezar� Zindan�
#define ENABLE_SPIDER_DUNGEON							// �r�mcek Zindan�
#define ENABLE_FLAME_DUNGEON							// Alev Zindan�
#define ENABLE_SNOW_DUNGEON								// Kar Zindan�
#define ENABLE_RANKING_SYSTEM							// S�ralama Sistemi
#define ENABLE_DAWNMIST_DUNGEON							// Ochao Tap�na��
#define ENABLE_GUILD_DRAGONLAIR_SYSTEM					// Gilde Ejderha Ma�aras� Sistemi
	#ifdef ENABLE_GUILD_DRAGONLAIR_SYSTEM
		#define ENABLE_GUILD_DRAGONLAIR_PARTY_SYSTEM	// Ejderha Ma�aras� Parti Sistemi
		#define ENABLE_BLUEDRAGON_RENEWAL				// Mavi Ejderha Yenileme
	#endif
#define ENABLE_BATTLE_FIELD								// Sava� Alan� Etkinle�tirme
#define ENABLE_12ZI										// Zodyak Zindan�
	#ifdef ENABLE_12ZI
	#define ENABLE_CHAT_MISSION_ALTERNATIVE				// Sohbet G�rev Alternatifi
	#define ENABLE_SERVERTIME_PORTAL_SPAWN				// Sunucu Saati ile Portal A��lmas�
	//#define ENABLE_12ZI_SHOP_LIMIT					// Zodyak Ma�aza S�n�r�
	//#define ENABLE_12ZI_REWARD_TABLE					// Zodyak �d�l Tablosu
	#endif
#define ENABLE_DEFENSE_WAVE								// Gemi Savunma Zindan�
	#ifdef ENABLE_DEFENSE_WAVE
		#define ENABLE_NEW_CHAT_DUNGEON					// Yeni Sohbet Zindan�
		#define ENABLE_PARTY_FEATURES					// Parti �zellikleri
	#endif
#define ENABLE_QUEEN_NETHIS								// Y�lan Tap�na�� Krali�esi Nethis
#define ENABLE_WHITE_DRAGON								// Beyaz Ejderha Alastor
#define ENABLE_SUNG_MAHI_TOWER							// Sungmahi Kulesi


//--------SE�ENEKLER------->
#define ENABLE_EXTEND_INVEN_SYSTEM								// Geni�letilmi� Envanter Sistemi
	#ifdef ENABLE_EXTEND_INVEN_SYSTEM
		#define ENABLE_EXTEND_INVEN_ITEM_UPGRADE				// Envanter geni�letme i�in e�ya y�kseltme
		#define ENABLE_EXTEND_INVEN_ITEM_UPGRADE_SPECIAL_INV	// �zel Envanter Kilidini A�ma Uzant�s�
		#define ENABLE_BELT_INVENTORY							// Kemer Envanteri
		#else
		#define ENABLE_EXTEND_INVEN_PAGE_SYSTEM					// Geni�letilmi� Envanter Sayfa Sistemi
	#endif
#define ENABLE_BELT_INVENTORY_RENEWAL							// Resmi Kemer Geni�letme
#define ENABLE_ADDITIONAL_EQUIPMENT_PAGE						// Resmi Envanter Yeniden Yap�land�rma
#define WJ_NEW_USER_CARE										// Yeni Kullan�c� Deste�i
#define ENABLE_AFTERDEATH_SHIELD								// �l�mden Sonra Kalkan
	#ifdef ENABLE_AFTERDEATH_SHIELD	
	#	define AFTERDEATH_SHIELD_ONLY_WARMAP					// Sadece sava� haritas�nda kalkan etkin
	#endif
#define ENABLE_EXPRESSING_EMOTION								// Yeni Duygu �fadeleri
#define ENABLE_CHAT_SETTINGS									// Sohbet Ayarlar�
#define ENABLE_SHOW_GUILD_LEADER								// Lonca Lideri ve Yard�mc�s�n� G�sterme
#define ENABLE_GUILDRENEWAL_SYSTEM								// Resmi Lonca Geni�letme Sistemi

#ifdef ENABLE_GUILDRENEWAL_SYSTEM				// Lonca Sistemi
	#define ENABLE_USE_MONEY_FROM_GUILD			// Lonca Paras� ile �deme yapma
	#define ENABLE_NEW_WAR_OPTIONS				// Yeni Lonca Sava�� Se�enekleri (Tur, Puan, S�re)
	#define ENABLE_EXTENDED_GUILD_LEVEL			// Lonca seviyesini 30'a kadar geni�letme

	#define ENABLE_MEDAL_OF_HONOR				// Yeni lonca para birimi
	#define ENABLE_GUILD_DONATE_ATTENDANCE		// G�nl�k Ba���

	#define ENABLE_GUILD_WAR_SCORE				// Sava� Sayfas�
	#define ENABLE_GUILD_LAND_INFO				// Arazi Bilgisi Sayfas�
	#define ENABLE_GUILDBANK_LOG				// Lonca G�nl�kleri

	#define ENABLE_GUILDBANK_EXTENDED_LOGS		// Geni�letilmi� g�nl�kler i�in Log.cpp ba�lant�s�
	#define ENABLE_EXTENDED_RENEWAL_FEATURES	// Lonca Liderini De�i�tirme | Arazi Silme
	#define ENABLE_COLEADER_WAR_PRIVILEGES		// Lider �evrimd��� oldu�unda, Yard�mc� Lider lider ile ayn� yetkilere sahip
	#define ENABLE_GUILDWAR_BUTTON				// Lonca Sava�� olu�turma -> Oyun i�inde d��me etkinle�iyor
//	#define ENABLE_GUILD_RANKING				// bitmemi� lonca s�ralamas�
#endif

#define ENABLE_HUNTING_SYSTEM						// Av G�revleri Sistemi
	#ifdef ENABLE_HUNTING_SYSTEM
		#define HUNTING_MISSION_COUNT 90			// Toplam av g�revi say�s�
		#define HUNTING_MONEY_TABLE_SIZE 9			// Para �d�l tablosu boyutu
		#define HUNTING_EXP_TABLE_SIZE 9			// Deneyim puan� �d�l tablosu boyutu
	#endif

#define ENABLE_SET_ITEM								// E�ya Set Sistemi
#define ENABLE_SAFEBOX_IMPROVING					// Geli�tirilmi� Sand�k Sistemi
//#define ENABLE_SAFEBOX_MONEY						// Sand�kta Para Depolama Sistemi
#define ENABLE_REFINE_MSG_ADD						// E�ya Y�kseltme Mesajlar�
#define ENABLE_PORTAL_LEVEL_LIMIT					// Portal Kullan�m� i�in Seviye S�n�r�
#define WJ_SHOW_PARTY_ON_MINIMAP					// Partideki �yeleri harita �zerinde g�ster
#define ENABLE_AFK_MODE_SYSTEM						// AFK Modu Sistemi
#define ENABLE_VIEW_EQUIP_RENEWAL					// Ekipman G�r�nt�leme Yenileme
#define ENABLE_LOADING_TIP							// Y�kleme �pu�lar�
#define ENABLE_TARGET_AFFECT_SHOWER					// Hedef Durum Etkisi G�sterici [Sanii]
#define ENABLE_VIEW_TARGET_DECIMAL_HP				// Can De�erini Tam Say� Olarak G�ster @Monster
#define ENABLE_SEND_TARGET_INFO						// Canavar Hedef D���� Bilgisi
#ifdef ENABLE_SEND_TARGET_INFO
	#define ENABLE_COMMON_DROP_INFO					// common_drop_item.txt Dosyas�n� Y�kler
#endif
#define ENABLE_DELETE_FAILURE_TYPE					// Ba�ar�s�z E�ya Silme T�r�
#define ENABLE_GIVE_BASIC_ITEM						// Temel E�yalar Verme
	#ifdef ENABLE_GIVE_BASIC_ITEM
	#define GIVE_BASIC_SKILLS						// Temel Yetenekler: At[11], Dil[P]
	//#define GIVE_BASIC_EXTENDED_ITEMS				// Geli�mi� Ekipman Verme

	#define BLOCK_ADDCHANGE_ATTR_ON_BASIC			// Etkin: E�yalar�n bonuslar� de�i�tirilemez
	//#define BLOCK_DESTRY_ATTR_ON_BASIC			// Etkin: E�yalar yok edilemez
	//#define BLOCK_REFINE_ON_BASIC					// Etkin: E�yalar y�kseltilemez
	#endif
#define ENABLE_DICE_SYSTEM							// Zar Sistemi: E�er canavar kral veya boss ise, partideyseniz d��en e�yalar rastgele da��t�l�r
#define ENABLE_PARTY_EXP_DISTRIBUTION_EQUAL			// E�it Grup Deneyim Da��l�m�
#define ENABLE_RENEWAL_SHOPEX						// Geli�mi� Ma�aza Sistemi [Ekipman, Deneyim]
#define ENABLE_ANTI_EXP_RING						// Anti-EXP Y�z���
#define ENABLE_INVENTORY_SORT						// Envanter S�ralama Butonu
#define ENABLE_CUBE_PERCENT_INFO					// K�p Penceresinde Y�zde Bilgisi
#define ENABLE_AFFECT_POLYMORPH_REMOVE				// Sol �st �konda Polimorf T�klay�nca Kald�r�l�r
#define ENABLE_AFFECT_BUFF_REMOVE					// Sol �st �konda Buff T�klay�nca Kald�r�l�r
#define ENABLE_SKILL_COOLTIME_UPDATE				// Oyuncu �ld���nde yetenek so�uma s�releri s�f�rlan�r
//#define ENABLE_COLORED_GUILD_RANKS				// Lonca R�tbeleri Renkli G�r�n�r
//#define ENABLE_GROUPLOOT_ONLY_FOR_ATTACKERS		// Yaln�zca Sald�r� Yapan Oyuncular E�ya Alabilir
#define ENABLE_OX_RENEWAL							// OX Etkinli�i Yenilenmesi
//#define OX_REWARD_UPDATE							// OX G�ncellemesi [Mali] (Daha �yi G�rev)
//#define ENABLE_UNMOUNT_WHEN_DEAD					// �l�mde Binekten �ndirme
#define ENABLE_EXTENDED_ITEMNAME_ON_GROUND			// Yerdeki E�ya �simlerini G�ster
#define ENABLE_EMPIRE_FLAG							// Global Sohbette �mparatorluk Bayraklar�
#define ENABLE_MESSENGER_BLOCK 						// Mesajla�ma Engelleme
#define ENABLE_GM_MESSENGER_LIST					// GameMaster �evrimi�i/�evrimd��� Listesi
#define ENABLE_MONARCH_AFFECT						// Monark Oyun ��i Etkisi



//////////////////////////////////////////////////[STANDART TANIMLAR]//////////////////////////////////////////////////
/*<-----VER�TABANI (DB)----->*/
#define ENABLE_DEFAULT_PRIV							//	[ClientManager.cpp]			common.priv_settings dosyas�ndan varsay�lan yetkilerin y�klenmesini etkinle�tirir
#define ENABLE_ITEMAWARD_REFRESH					//	[ClientManager.cpp]			player.item_award tablosunda her 5 saniyede bir sorgu yap�lmas�n� etkinle�tirir
#define ENABLE_PROTO_FROM_DB						//	[ClientManager.h]			conf.txt i�inde "PROTO_FROM_DB = 1" olarak belirtildi�inde protolar� veritaban�ndan okur
													//								conf.txt i�inde "MIRROR2DB = 1" olarak belirtildi�inde protolar� veritaban�na yans�t�r
#define ENABLE_AUTODETECT_VNUMRANGE					//	[ClientManagerBoot.cpp]		protolar veritaban�ndan y�klenirse, ds e�yalar� i�in otomatik olarak vnum aral���n� alg�lar


//////////////////////////////////////////////////[SADECE OYUN ���N TANIMLAR]//////////////////////////////////////////////////
/*<-----OYUN----->*/
#define NEW_ICEDAMAGE_SYSTEM						//	[char.h]					Nemere zindan� gibi yerler i�in yeni hasar sistemi ekler
#define ENABLE_ANTI_CMD_FLOOD						//	[char.h]					Komut spam�n� �nler; saniyede 10'dan fazla komut g�nderen oyuncu ba�lant�s� kesilir
#define ENABLE_OPEN_SHOP_WITH_ARMOR					//	[char.h]					Z�rh giyiliyken de ki�isel d�kkan a��lmas�n� sa�lar
#define ENABLE_GOHOME_IF_MAP_NOT_ALLOWED			//	[char.cpp]					Girilmesine izin verilmeyen bir haritada oyuncuyu k�y�ne geri g�nderir
#define ENABLE_GM_FLAG_IF_TEST_SERVER				//	[char.cpp]					Test sunucu modunda GM bayra��n� g�sterir
#define ENABLE_GM_FLAG_FOR_LOW_WIZARD				//	[char.cpp]					D���k seviyeli sihirbazlar i�in de GM sembol� sa�lar
// #define ENABLE_POTIONS_LEVELUP					//	[char.cpp]					Seviye atland���nda iksir d�����n� etkinle�tirir
#define ENABLE_NEWEXP_CALCULATION					//	[char_battle.cpp]			Rastgele negatif tecr�be/marriage puan� hatalar�n� �nlemek i�in tecr�be oran�n� yeniden hesaplar
#define ENABLE_EFFECT_PENETRATE						//	[char_battle.cpp]			Penetrasyon yap�l�rken efekt g�r�n�r
#define ENABLE_KILL_EVENT_FIX						//	[char_battle.cpp]			�ld�rme olay� s�ras�nda s�f�r tecr�be hatas�n� giderir (�nerilir)
// #define ENABLE_FIREWORK_STUN						//	[char_item.cpp]				Havai fi�ek kullan�ld���nda sersemletme etkisini etkinle�tirir
#define ENABLE_ADDSTONE_FAILURE						//	[char_item.cpp]				Spirit ta�lar�n�n ba�ar�s�z eklenmesi
#define ENABLE_ADDSTONE_FAILURE_CUSTOM				//	[char_item.cpp]				Spirit ta�� ba�ar�s�zl��� +0, +1, +2, +3, +4 se�eneklerini etkinle�tirir
#define ENABLE_EFFECT_EXTRAPOT						//	[char_item.cpp]				Ye�il/mor iksirler kullan�ld���nda ekstra pot efekti
#define ENABLE_BOOKS_STACKFIX						//	[char_item.cpp]				Kitaplar�n y���l�p y���lmamas�n� se�ebilir
#define ENABLE_STACKABLES_STONES					//	[char_item.cpp]				Spirit ta�lar�n�n y���nlanabilir olmas�n� sa�lar
#define ENABLE_FORCE2MASTERSKILL					//	[char_skill.cpp]			Skill seviyesi her zaman m1'e y�kselir (�rne�in b17'de)
// #define ENABLE_MOUNTSKILL_CHECK					//	[char_skill.cpp]			At binme kontrol� yap�lmal� m�, skilling s�ras�nda kontrol sa�lar
// #define ENABLE_NULLIFYAFFECT_LIMIT				//	[char_skill.cpp]			Sura skill 66, oyunculardan < veya > seviyesinde olanlar� etkisiz hale getirmez
// #define ENABLE_MASTER_SKILLBOOK_NO_STEPS			//	[char_skill.cpp]			Yaln�zca bir kitapla ana skill art�rabilir
#define ENABLE_CMD_PLAYER							//	[config.cpp]				CMD i�inde PLAYER derecesini etkinle�tirir
#define ENABLE_EXPTABLE_FROMDB						//	[config.cpp]				Exp tablosunu veritaban�ndan okur
#define ENABLE_AUTODETECT_INTERNAL_IP				//	[config.cpp]				Halka a��k bir IP yoksa i� IP'yi otomatik alg�lar
// #define ENABLE_GENERAL_CMD						//	[config.cpp]				"locale/%s/conf/GENERAL_CMD" gibi genel CMD okur
// #define ENABLE_GENERAL_CONFIG					//	[config.cpp]				Genel bir CONFIG okur ve ge�erli se�enekleri g�nceller
													//								Ge�erli olmayan se�enekler: HOSTNAME, CHANNEL, PLAYER_SQL vb.
// #define ENABLE_BLOCK_CMD_SHORTCUT				//	[cmd.cpp]					K�salt�lm�� komutlar� devre d��� b�rak�r
// #define ENABLE_STATPLUS_NOLIMIT					//	[cmd_gm.cpp]				con+/int+/str+/dex+ komutlar� i�in 90 puan s�n�r�n� kald�r�r
#define ENABLE_SET_STATE_WITH_TARGET				//	[cmd_gm.cpp]				Komut hedefi olarak 3. arg�man� kullan�r
#define ENABLE_CMD_IPURGE_EX						//	[cmd_gm.cpp]				/ipurge ikinci arg�man� belirli bir pencereden e�yalar� kald�r�r (inv/equip/ds/belt/all)
// #define ENABLE_SPAMDB_REFRESH					//	[db.cpp]					common.spam_db i�inde her 10 dakikada bir sorgu yap�lmas�n� sa�lar
#define ENABLE_FISHINGROD_RENEWAL					//	[fishing.cpp]				Bal�k oltas� y�kseltmesi ba�ar�s�z olursa, sadece %10 ana puan kaybeder
#define ENABLE_NEWGUILDMAKE							//	[guild.h]					pc.make_guild0 i�levini etkinle�tirir
#define ENABLE_INFINITE_HORSE_HEALTH_STAMINA		//	[horse_rider.h]				At sa�l��� veya dayan�kl�l��� kaybetmez
// #define ENABLE_ACCOUNT_W_SPECIALCHARS			//	[input_auth.cpp]			Hesap adlar�nda �zel karakterlerin kullan�lmas�n� sa�lar
#define ENABLE_GOHOME_IF_MAP_NOT_EXIST				//	[input_db.cpp]				Harita mevcut de�ilse oyuncuyu k�y�ne geri g�nderir
#define ENABLE_CHAT_COLOR_SYSTEM					//	[input_main.cpp]			GM olup olmad���na g�re sohbet renklerini etkinle�tirir
#define ENABLE_CHAT_SPAMLIMIT						//	[input_main.cpp]			Sohbet spam s�n�r�; 5 saniyede 4 mesaj� a�arsa ba�lant� kesilir
#define ENABLE_WHISPER_CHAT_SPAMLIMIT				//	[input_main.cpp]			�zel mesajlarda 5 saniyede 10 mesaj s�n�r�; aksi takdirde ba�lant� kesilir
#define ENABLE_CHAT_LOGGING							//	[input_main.cpp]			Sohbet kayd�n� etkinle�tirir (t�m GM sohbetlerini kaydeder)
#define ENABLE_IMMUNE_FIX							//	[item.cpp]					�mm�n bugunu d�zeltir; kalkan son olarak donat�ld���nda �al���r
#define ENABLE_FIX_READ_ETC_DROP_ITEM_FILE_BY_VNUM	//	[item_manager_read_tables]	EtcDropItemFile okuma: Mevcut olmayan bir ��e (Korece isimler nedeniyle)
#define ENABLE_PICKAXE_RENEWAL						//	[mining.cpp]				Kazma y�kseltmesi ba�ar�s�z olursa sadece %10 ana puan kaybeder
#define ENABLE_QUEST_DIE_EVENT						//	[quest.h]					"die" g�rev etkinli�ini ekler
#define ENABLE_QUEST_BOOT_EVENT						//	[quest.h]					Oyun ba�lad���nda etkinlik ba�lat�l�r
#define ENABLE_QUEST_DND_EVENT						//	[quest.h]					quest �zerinden kayd�rma yaratmak i�in etkinlik ba�lat�r
#define ENABLE_TRANSLATE_LUA						//	[questlua.cpp]				translate.lua dosyas�n�n y�klenmesini sa�lar
// #define ENABLE_LOCALECHECK_CHANGENAME			//	[questlua_pc.cpp]			Avrupa yerellerinde ad de�i�ikli�ine izin vermez
// #define ENABLE_PC_OPENSHOP						//	[questlua_pc.cpp]			pc.open_shop0(idshop) i�levini etkinle�tirir ancak al�m/sat�m �al��maz
#define D_JOIN_AS_JUMP_PARTY						//	[questlua_dungeon.cpp]		x
#define ENABLE_QUESTLIB_EXTRA_LUA					//	[questlua.cpp]				x
#define ENABLE_PARTYKILL							//	[questmanager.cpp]			PartyKill'i yeniden etkinle�tirir
// #define ENABLE_SHOP_BLACKLIST					//	[shop.cpp]					Blessing Marble ve Magic Copper Ore gibi �r�nleri engeller
#define ENABLE_NEW_RETARDED_GF_START_POSITION		//	[start_position.cpp]		Yeni Gameforge ba�lang�� pozisyonu
#define ENABLE_D_NJGUILD							//	[general]					d.new_jump_all_guild+cpp ile ilgili i�levleri etkinle�tirir
#define ENABLE_FULL_NOTICE							//	[general]					Geni�letilmi� bildirim �zelliklerini etkinle�tirir
#define ENABLE_NEWSTUFF								//	[general]					Yeni �zellikler (yeni lua i�levleri, yeni CONFIG se�enekleri vb.) ekler
#define ENABLE_NEWSTUFF_2017						//	2017 y�l�ndaki yeni �zellikler
#define ENABLE_NEWSTUFF_2019						//	2019 y�l�ndaki yeni �zellikler
#define ENABLE_CMD_WARP_IN_DUNGEON					//	[general]					/warp komutu zindandaki bir oyuncuya ula�abilir

/*
@#GENEL MAKROLAR
#define __UNIMPLEMENTED__				// Uygulanacak yeni �eylerin taslaklar�
*/


/*
#@GENEL
@warme001: PLAYER_MAX_LEVEL_CONST (common/length.h) ve gPlayerMaxLevel (game/config.h) hakk�nda dikkatli olun
@warme002: ITEM_MAX_COUNT (common/item_length.h) ve g_bItemCountLimit (game/config.h) hakk�nda dikkatli olun
@warme003: do_click_safebox her haritada PLAYER taraf�ndan kullan�labilir!
@warme004: `when vnum.kill begin` ve `when kill begin` her ikisi de tetiklenir
@warme005: farkl� yerel (locale) ayarlar
@warme007: db/src/ClientManager.cpp �zerinde; ./close ve ./start s�ras�nda anlams�zl��� ve hatal� �al��mas�ndan dolay� common.locale setini yorum sat�r� yap�ld�
			yeniden i�lem ba�lat�lmadan �nce a��r� y�kleme varsa, bu null pointer mysql ba�lant�s�n� i�ler (ymir i� par�ac���)
@warme008: char_item.cpp �zerinde; �imdi 27996 (zehir �i�esi) zehir etkisi verebilir
@warme009: char_resist.cpp �zerinde; e�er kanama zehir olarak kullan�l�rsa, kanama eklentisi zehir eklentisi/50'dir (bu sayede yarat�klar oyuncular� kanatabilir)
@warme010: char_state.cpp �zerinde; test_server "BOOL g_test_server" olarak kullan�l�r
@warme011: dungeon.cpp �zerinde; d.join yerine d.new_jump_party kullanmal�s�n�z ��nk� parti hash kontrol�ndeki yanl�� bir uygulama nedeniyle rastgele ��kme sorunlar�na neden olur
@warme012: �nemsiz hatalar art�k basit loglar olarak kabul ediliyor
@warme013: gereksiz hatalar art�k yaln�zca yorum sat�r� yap�l�yor

#@common
@fixme301: tables.h �zerinde; TPlayerTable hp/mp int16_t'den int'e de�i�tirildi (hp/mp >32767 olmal�)

#@db/src
@fixme201: ProtoReader.cpp �zerinde; 'SAMLL' 'SMALL' olarak de�i�tirildi
@fixme202: ClientManagerGuild.cpp �zerinde; e�er oyuncu �evrimd��� ise lonca �yesi ��karma zaman� sorunu d�zeltildi 
			(withdraw_time -> new_withdraw_time)
@fixme203: ClientManagerPlayer.cpp �zerinde; "command" i�in bo�ta kalan g�sterici (dangling pointer)
@fixme204: Cache.cpp �zerinde; ki�isel d�kkanda ayn� vnum�a sahip �ok fazla e�ya varsa, myshop_pricelist birincil anahtar �o�altma hatas�


#@game/src
@fixme101: log.cpp �zerinde, invalid_server_log i�in '%s' hatas� d�zeltildi.
@fixme102: cmd_general.cpp �zerinde ACMD(do_war) i�inde unsigned hatas� d�zeltildi.
@fixme103: config, input_login, input_main.cpp dosyalar�nda clientcheckversion (s�r�m > tarih) ifadesi (s�r�m != tarih) ve gecikme s�resi 10�dan 0�a olarak de�i�tirildi.
@fixme104: char.cpp, questlua_pc.cpp dosyalar�nda lv90'dan sonra stat� puan� alma d�zeltildi; 90 de�eri gPlayerMaxLevel ile de�i�tirildi.
@fixme105: cmd.cpp dosyas�nda t�m Korece komutlar devre d��� b�rak�ld�.
@fixme106: input_main.cpp dosyas�nda, y�ksek h�zdaki bir oyuncu binekteyken (�rne�in, aslan) mesafe s�n�r� nedeniyle geri getirilecektir.
@fixme107: char_battle.cpp dosyas�nda, �len karakter (oyuncu veya yarat�k) negatif hp de�erine sahip oldu�unda, sura&co, hp/mp kaybeder.
@fixme108: char.cpp dosyas�nda, mevcut binek 0 de�ilken bine�i de�i�tirdi�inizde, yaln�zca oyuncunun ekran�ndaki t�m nesneler (npc vb.) kaybolur.
@fixme109: questmanager.cpp dosyas�nda, bir oyuncu �ld�r�ld���nde (sava� m), `when kill begin` iki kez tetiklenir.
@fixme110: char_affect.cpp dosyas�nda, yar� saydamken (yeniden canlanm��, ninja yetene�i veya beyaz bayrak) sald�r� yapt���n�zda hala yar� saydam kal�rs�n�z.
@fixme111: test.cpp dosyas�nda, ConvertAttribute2'de x ve y ekseni ters �evrildi (�nce y->x, sonra x->y).
@fixme112: char_item.cpp dosyas�nda, tekrar giri� yap�lana kadar ekipman �zerindeki bonuslar de�i�tirilebilir.
@fixme113: char_item.cpp dosyas�nda ta�lar� ��kar�rken, bonus kayb� olmadan ��kar�labilir.
@fixme114: char_item.cpp dosyas�nda, #111, #112 ve di�er birka� hata bir araya getirildi.
@fixme115: char_item.cpp dosyas�nda, partideyseniz ve e�yalar�n sahibi siz de�ilse, yerdeki t�m e�yalar al�nabilir.
@fixme116: char_skill.cpp dosyas�nda, normal at binme yetenekleri hasar veremez.
@fixme117: char_item.cpp dosyas�nda, envanter doluyken ekipman de�i�tirilemez ve bo� olmad���nda gereksiz kemer de�i�imleri engellenir.
@fixme118: char.cpp dosyas�nda ComputePoints �a�r�ld���nda, ekipman bonuslar� kadar hp/mp kazan�rs�n�z.
@fixme119: input_main.cpp dosyas�nda, kasadaki/al��veri� merkezindeki e�yalar kemer envanterine t�r kontrol� olmadan yerle�tirilebilir.
@fixme120: input_login.cpp dosyas�nda, baz� paket kimlikleri kontrol edilmedi.
@fixme121: char_item.cpp dosyas�nda, b�y� ta�� de�erlerinden kaynaklanan gereksiz sistem hatalar� olu�turuyordu.
@fixme122: arena.cpp dosyas�nda, arenada baz� iksirler kontrol edilmedi.
@fixme123: char_item.cpp dosyas�nda USE_CHANGE_ATTRIBUTE2 (24) alt t�r kontrol hatas� (ko�ul hi�bir zaman do�ru olamaz).
@fixme124: char_item.cpp dosyas�nda 6-7 ekleme/de�i�tirme kost�m e�yalar�nda kontrol edilmedi.
@fixme125: char.cpp dosyas�nda, zindan yenilenmesi sarkan bir i�aret�iye i�aret ediyordu (gereksiz oldu�u i�in kald�r�ld�).
@fixme126: marriage.cpp dosyas�nda sevgi puanlar� ta�ma hatas� d�zeltildi.
@fixme127: cube.cpp dosyas�nda /cube r_info exploit d�zeltildi; kontrols�z bir k�p npc vnumlar� nedeniyle ��kmeye yol a�abiliyordu.
@fixme128: char.cpp dosyas�nda madencilik hacki d�zeltildi; karakter haritadaki herhangi bir konumdan maden ��karabiliyordu.
@fixme129: PetSystem.cpp dosyas�nda, Azrael evcil hayvanlar� zindanda de�ilse buff vermiyor ve �a�r�ld���nda da kald�r�l�yor.
@fixme130: messenger_manager.cpp ve cmd_general.cpp dosyalar�nda, bir flood paketi g�nderildi�inde ma�dur ba�lant�s� kesilecek veya en fazla gecikmeye maruz kalabilir.
@fixme131: char.cpp dosyas�nda, d�v���lemeyen npc/oyuncu nesnelerine dahi e�zamanlama paketlerinin g�nderilmesi sorunu d�zeltildi.
@fixme132: shop.cpp dosyas�nda, iki ki�i ayn� anda ayn� �r�n� sat�n ald���nda, yava� olan kullan�c� yanl�� bir d�n�� paketi al�r.
@fixme133: input_main.cpp dosyas�nda, k�f�r filtresi ve ba�lant�l� metin �zelli�i son metni de�il ham metni i�liyordu.
@fixme134: questlua_pc.cpp dosyas�nda, binek bonusu binek �a�r�lmam�� olsa bile eklenebilirdi (sadece /unmount pc.unmount kald�rabilir).
@fixme135: char.cpp dosyas�nda, e�zamanlama bir hareket paketinden �nce yap�l�rsa ��kme olu�abilir (sorunlu -> kald�r�ld�).
@fixme136: char.cpp dosyas�nda, s�f�ra b�lme istisnalar�na dair kontroller yoktu; �rne�in, bir yarat���n maksimum hp'sini 0 olarak ayarlarsan�z rastgele ��kmeler meydana gelir.
@fixme137: char_battle.cpp dosyas�nda, bir oyuncu �ld���nde HP negatif bir de�er alabilir. �imdi 0 olacak �ekilde g�ncellendi.
@fixme138: db.cpp, input_auth.cpp dosyalar�nda, hesab�n �ifresi her giri� denemesinde mysql sorgu ge�mi�inde d�z metin olarak g�r�n�yordu (�imdi hashlenmi�).
@fixme139: shop.h dosyas�nda, CShop s�n�f�n�n y�k�c�s� sanal de�ildi. CShopEx gibi bir t�retilmi� s�n�f silindi�inde bellek s�z�nt�s� olu�uyordu.
@fixme140: input_main.cpp dosyas�nda, kemer doluyken kasa envanterine koyulabiliyordu.
@fixme141: char_item.cpp dosyas�nda, kemer envanterinde kullan�labilir olmayan yuvalarda dahi e�yalar kullan�labiliyordu.
@fixme142: messenger_manager.cpp dosyas�nda, net.SendMessengerRemovePacket i�in SQL enjeksiyon d�zeltmesi.
@fixme143: guild_manager.cpp dosyas�nda, net.SendAnswerMakeGuildPacket i�in SQL enjeksiyon d�zeltmesi.
@fixme144: sectree_manager.cpp dosyas�nda, map/index yeni sat�rla bitmezse oyun ��ker.
@fixme145: input_main.cpp dosyas�nda, guild_add_member her vid�i lonca �yesi olarak ekleyebilir (bir yarat�k veya npc olsa bile).
@fixme147: char_item.cpp dosyas�nda, ramazan �ekeri etkisi halen aktif olsa dahi kullan�labilir.
@fixme148: item_manager_read_tables.cpp dosyas�nda, ConvSpecialDropItemFile i�inde g�rev, �zel ve nitelik t�rleri i�lenmedi.
@fixme149: char.cpp dosyas�nda, e�yalar de�i�tirildi�inde malzeme atlama exploit'i d�zeltildi.
@fixme150: exchange.cpp, char_item.cpp dosyalar�nda, g�rev ask�ya al�nm��sa e�ya mod�l� de�i�tirilemez.
@fixme152: questlua_pc.cpp dosyas�nda, pc.get_special_ride_vnum socket0 yerine socket2'yi kontrol ediyordu.
@fixme153: threeway_war.cpp dosyas�nda, 99. seviyenin �zerindeki �ld�rme say�s� kaydedilmiyordu.
@fixme154: cmd_gm.cpp dosyas�nda, /all_skill_master komutu art�k alt becerilere do�ru puan say�s�n� ayarlayacak.
@fixme156: char_affect.cpp dosyas�nda, etki de�erlerinin y�klenmeden �nce ikiye katlanmas�n� engelle (�rne�in giri�te binek bonusu gibi).
@fixme157: OxEvent.cpp dosyas�nda, ox etkinli�i durdurulduktan sonra kat�l�mc� listesi temizlenmiyordu.
@fixme158: input_main.cpp dosyas�nda, deviltower rafineri para olmad��� takdirde s�f�rlanmayacak ve bayrak 1 azalt�lacak.
@fixme159: exchange.cpp dosyas�nda, takas yap�l�rken ds e�yalar�nda yanl�� kontrol nedeniyle ilk ds alt envanter yuvas� bo� de�ilse takas yap�lam�yordu.
@fixme160: DragonSoul.cpp dosyas�nda, bir ds ta�� kald�r�l�rken hedef yuva bo� de�ilse ds e�yas� de�i�tirilecek ve kaybolacakt�r.
@fixme168: questevent.cpp dosyas�nda, g�revin bilgi ad� zaten null ise std::string olu�turucu bir istisna f�rlatacakt�r.
@fixme169: char_item.cpp dosyas�nda, efsanevi �eftali alternatif vnum.
@fixme170: item.cpp dosyas�nda, bonuslar�n �zel mineral yuvalar�nda uygulanma d�zeltmesi.
@fixme171: dungeon.cpp dosyas�nda, daha �nce (!ch->IsPC()).
@fixme172: dungeon.cpp dosyas�nda, g�nderilmeden �nce ch->IsPC() eklendi.
@fixme173: item.cpp dosyas�nda Range_pick 300'den 600'e geni�letildi.
@fixme174: questmanager.cpp dosyas�nda ch kontrol�.
@fixme177: cmd_gm.cpp dosyas�nda, do�ru mesaj i�eri aktar�ld�.
@fixme180: cmd_general.cpp dosyas�nda, /costume komutu ili�kili kost�m bonus kimlikleri fn_string i�inde mevcut de�ilse oyun �ekirdek ��kmesine neden olur.
@fixme182: input_login.cpp dosyas�nda.
@fixme183: input_main.cpp, messenger_manager.cpp dosyalar�nda arkada� listesinden kald�rma -> arkada�l�ktan ��kar�ld�.

@fixme185: ClientManagerBoot.cpp dosyas�nda, material_count de�eri nullptr ise eklendi.
@fixme186: item.cpp dosyas�nda ch kontrol�.
@fixme188: char.h dosyas�nda, �ld���nde �d�l verilmez.
@fixme189: item_manager.cpp dosyas�nda, out of range (s�n�r d���) hatas� d�zeltildi.

@fixme400: item_manager.cpp dosyas�nda, y�z�klere bonus g�r�n�rl�k eklendi.
@fixme401: char_item.cpp dosyas�nda, ayn� vnum�a sahip iki y�z�k d�zeltildi.
@fixme402: cmd_gm.cpp dosyas�nda, rang puan hesaplamas� (ch->tch) d�zeltildi.
@fixme403: input_main.cpp dosyas�nda, deneyim (EXP) da��t�m� sadece grup liderine yap�lacak �ekilde d�zenlendi.
@fixme404: char_item.cpp dosyas�nda, ayn� iksirlerin birden fazla kez kullan�lmas� engellendi.
@fixme405: char.cpp dosyas�nda, Max Level�den sonra %50�ye kadar daha deneyim (EXP) kazan�labilir.
@fixme406: char_affect.cpp dosyas�nda, d���k seviyeli bufflar yok say�l�r.
@fixme407: char.cpp dosyas�nda, ma�aza paketleri ma�azada yer almayacak �ekilde d�zenlendi.
@fixme408: cmd_general.cpp dosyas�nda, GM_IMPLEMENTOR kullan�c�lar� an�nda kasabaya geri d�nebilir ve yeniden ba�layabilir.
@fixme409: char_item.cpp dosyas�nda, �l� olsan�z bile e�ya toplama i�lemi engellendi.
@fixme410: char_item.cpp dosyas�nda, mesafe kontrol�yle silah demircisi d�zeltildi.
@fixme411: item_length.h dosyas�nda, geni�letilmi� ad uzunlu�u eklendi.
@fixme412: length.h dosyas�nda, geni�letilmi� karakter maksimum uzunlu�u eklendi.
@fixme413: length.h dosyas�nda, ValidItemPosition�da eksik pencere t�r� d�zeltildi.
@fixme414: char_item.cpp dosyas�nda, iksirler do�rudan kemer envanterine y���larak eklenir.
@fixme415: input_login.cpp dosyas�nda yanl�� map_index (2) d�zeltildi.
@fixme416: input_main.cpp dosyas�nda, ekipmanl� e�yalar kasa envanterine konulamaz.
@fixme417:
@fixme418: char.cpp dosyas�nda, yere b�rak�lan e�yalar grubunuzdaki di�er oyuncular i�in y���nlan�r.
@fixme419: desc_manager.cpp dosyas�nda, do�ru PC bulunmas� sa�land�.
@fixme420: config.cpp dosyas�nda, interpreter_set_privilege[CMD yetkilerini y�kle] devre d��� b�rak�ld�.
@fixme421: input_login.cpp dosyas�nda, GM ve g�r�nmez olan oyuncular g�zlemci olarak ayarland�.
@fixme422: char_item.cpp dosyas�nda eksik MonkeyDungeon d�zeltmesi.
@fixme423: char_battle.cpp dosyas�nda, silahs�zken bufflar devre d��� b�rak�ld� (VZK, AURA).
@fixme424: char_item.cpp dosyas�nda, ekipmanl� e�yalarda �zellik de�i�ikli�i yap�lamaz.
@fixme425: char.cpp dosyas�nda, zindan �ekirdek ��kmesi d�zeltildi.
@fixme426: char_battle.cpp dosyas�nda, do�ru hizalama hesaplamas� yap�ld�.
@fixme427: belt_inventory_helper.h dosyas�nda, kemer envanterinde kar���mlar�n kullan�m�na izin verildi.
@fixme428: questlua_pc.cpp dosyas�nda, yetenek grubu de�i�ti�inde etkiler kald�r�l�r.
@fixme429: input_main.cpp dosyas�nda, comboattackhack ile ilgili null de�eri sorunu d�zeltildi.
@fixme430: PetSystem.cpp dosyas�nda SetSummonItem Socket d�zeltmesi.
@fixme431: char.cpp dosyas�nda Ghostwalker d�zeltildi.
@fixme432: char.cpp dosyas�nda Madencilik Botu d�zeltildi.
@fixme433: char_affect.cpp dosyas�nda, Weaponry Sura�n�n Dispel ve Healing Power Shaman��n �ifa gecikmesi hatas� d�zeltildi.
@fixme434: char_dragonsoul.cpp dosyas�nda, AddAffect ile Dragon Soul aktif etkisi eklendi.
@fixme435: char_battle.cpp dosyas�nda, zehir canavarlar� art�k agresifle�tirmeyecek.
@fixme436: char_item.cpp dosyas�nda, Gl�ckstasche eksik -> yeni protolar eklendi.
@fixme437: char_item.cpp dosyas�nda, ta� menzili geni�letme - eksik: Lykaner, Magiebruch.
@fixme438: char_item.cpp dosyas�nda, yeniden ba�lanma/s�ral� ge�i�lerde evcil hayvan �a�r�labilir durumda.
@fixme439: char_change_empire.cpp dosyas�nda, di�er imparatorluktaki lonca ile �mparatorluk De�i�imi d�zeltildi (UpdatePacket).
@fixme440: questlua_pc.cpp dosyas�nda VIP - sistem; GameMaster VIP olamaz.
@fixme441: cmd_general.cpp dosyas�nda, lonca sava��nda negatif �ekirdek ��kme hatas� d�zeltildi.
@fixme442: questlua_pc.cpp dosyas�nda �mparatorluk De�i�ikli�inden sonra otomatik ba�lant� kesme.
@fixme443: char_battle.cpp dosyas�nda, sald�r� s�ras�nda ma�azaya eri�im engellendi.
@fixme444: char_item.cpp dosyas�nda eksik IsExchanging.
@fixme445: char_item.cpp dosyas�nda, eski sa�larda �zellik de�i�tirme kullan�lamaz.
@fixme446: char_item.cpp dosyas�nda, Lonca demircisinin do�ru hesaplama ve oyun i�i bilgi g�sterimi (ingame) d�zenlendi.
@fixme447: char_horse.cpp dosyas�nda, StartRiding s�ras�nda at biniyor olsan�z bile yeniden ba�latamazs�n�z.
@fixme448: dungeon.cpp dosyas�nda, zindandaki canavar say�m� (yaln�zca NPC'leri i�ermeyecek �ekilde) d�zeltildi.
@fixme449: dungeon.cpp dosyas�nda, zindan�n t�m varl�klar i�in bildirimle daha fazla bellek kullanmas�n� �nleyen d�zeltme.
@fixme450: char_item.cpp dosyas�nda, evlilik e�yalar�n�n binekteyken kullan�m� engellendi.
@fixme451: questlua_global.cpp dosyas�nda, k���k �nlemler.
@fixme452: battle.cpp dosyas�nda, sava�ta IsObserverMode eklendi.
@fixme453: char_battle.cpp dosyas�nda IsObserverMode eklendi.
@fixme454: PetSystem.cpp dosyas�nda, evcil hayvan teleport/yeniden giri� sonras�nda kaybolmuyordu.
@fixme455: char_battle.cpp dosyas�nda moblock/bravery cape hack d�zeltildi.
@fixme456: db.cpp dosyas�nda SQL enjeksiyon d�zeltmesi.
@fixme457: input_main.cpp dosyas�nda, Wolfman ComboHack - Kick hatas� d�zeltildi.
@fixme458: char_skill.cpp dosyas�nda, d��man� duvarlara iten beceri hatas� d�zeltildi.
@fixme459: char_skill.cpp dosyas�nda, silahs�zken aura ve vzk yetenekleri devre d���.
@fixme460: char_item.cpp dosyas�nda, y���lan ta�lar her biri -1 olacak �ekilde d�zenlendi.
@fixme461: char_skill.cpp dosyas�nda SK no fall (1-m10) == AFF_CHEONGEUN_WITH_FALL -> AFF_CHEONGEUN.
@fixme462: char.cpp dosyas�nda g�rev bayra�� d�zeltmesi, �rne�in kost�m saklama.
@fixme463: input_main.cpp dosyas�nda, 40. seviyenin alt�nda lonca kurulam�yor.
@fixme464: cmd_gm.cpp dosyas�nda evcil hayvan�n silinme d�zeltmesi.
@fixme465: char_skill.cpp dosyas�nda, b�y� sald�r�s� do�ru bonusu verir.
@fixme466: char.cpp dosyas�nda, binekteki hata ge�ici olarak d�zeltildi (bini� sonras�nda kick hatas�) - Belki.msa veya proto do�ru de�il!
@fixme467: char_item.cpp dosyas�nda, efsunlama ba�ar� oran� d�zeltildi.
@fixme468: item.cpp dosyas�nda, zaman a��m� s�resinden sonra silah kost�m� envantere d�ner.
@fixme469: char_battle.cpp dosyas�nda, arena haritas�nda hi�bir �ey b�rak�lamaz.
@fixme470: char.cpp dosyas�nda ma�aza ad� kontrol� - izin verilip verilmedi�i.
@fixme471: char_item.cpp dosyas�nda, "pick" tetikleyicisinin do�ru �al��mas� sa�land�.
@fixme472: char_item.cpp dosyas�nda, bellek s�z�nt�s� d�zeltildi.
@fixme473: input_login.cpp dosyas�nda, login a�amas�nda i�lenmeyen paket d�zeltildi (header 100).
@fixme474: char_battle.cpp dosyas�nda, "Shooting Dragon" hatas� d�zeltildi.
@fixme475: Main.cpp dosyas�nda, DBManager.Quit() yoruma al�nd�.
@fixme476: char_battle.cpp dosyas�nda, oyuncular kayd�rma pozisyonlar�n� kaydedemez (dd haritalar�nda engellenir).
@fixme477: party.cpp dosyas�nda �l� oyunculara teleport yap�lamaz.
@fixme478: questpc.cpp dosyas�nda, di�er g�rev durumlar�nda "hat�rlanan" e�yalar.
@fixme479: char.h dosyas�nda, uint16_t -> uint32_t (Acce-Fix).
@fixme480: char.cpp dosyas�nda, pozisyon ayarlama IsDoor().
@fixme481: char_item.cpp dosyas�nda, bine�in zaten donat�l�p donat�lmad��� kontrol edilir (KULLANILMIYOR).
@fixme482: char_item.cpp dosyas�nda, Polimorf (D�n���m) oldu�unda bufflar kald�r�l�r.
@fixme483: dragon_soul_table.cpp dosyas�nda, DRAGON_SOUL_GRADE_MAX -> DRAGON_SOUL_STEP_MAX.
@fixme484: DragonSoul.cpp dosyas�nda, DRAGON_SOUL_STEP_MAX -> DRAGON_SOUL_GRADE_MAX.

@fixme485:
@fixme486: char_battle.cpp dosyas�nda yans�tma hatas� k�t�ye kullan�m�n� �nleme.
@fixme487: char_battle.cpp dosyas�nda yeni MANASHIELD % olarak hesapland�.
@fixme488: cmd_general.cpp dosyas�nda monar�iyi warp etmeyi engelleme.
@fixme489: char_item.cpp dosyas�nda envanter doluysa sand�k a�may� engelle.
@fixme490: char_item.cpp dosyas�nda envanteri s�ralama engellendi.
@fixme491: char_item.cpp dosyas�nda ayn� malzeme ile rafinasyon ��kme hatas� d�zeltildi.
@fixme492: New_PetSystem.cpp dosyas�nda null pointer hatas� d�zeltildi.
@fixme493: char_skill.cpp dosyas�nda SKILL_FLAG_STUN hatas� d�zeltildi (Grup Buffer nedeniyle - Yetenek s�resi/hesaplamas� genelde hatal�yd�). Test edilmeli.
@fixme494: questlua_pc.cpp dosyas�nda imparatorluk de�i�imi yap�ld���nda grup varsa �ncelikle gruptan ayr�l.
@fixme495:
@fixme496: questlua_global.cpp dosyas�nda Warp_all_to_village fonksiyonu �al��anlar� da d��ar�da b�rak�yordu.
@fixme497: questlua_global.cpp dosyas�nda Syserr hatalar�n�n LUA i�inde etkinle�tirilmesi sa�land�.
@fixme498:
@fixme499: battle.cpp dosyas�nda sald�r� mesafesi d�zeltildi.
@fixme500: char.cpp dosyas�nda d�zeltme yap�ld�.
@fixme501: cmd_gm.cpp ve cube.cpp dosyalar�nda yang hatas� d�zeltildi; uint32_t yerine int kullan�ld�.
@fixme502: char_item.cpp dosyas�nda kamp ate�i d�zeltmesi.
@fixme503: battle.cpp ve pvp.cpp dosyalar�nda bekleme hack d�zeltmesi.
@fixme504: char_battle.cpp dosyas�nda d�zeltme yap�ld�.
@fixme505: cmd_emotion.cpp dosyas�nda sald�r� veya hareket esnas�nda duygu (emotion) kullan�lamaz.
@fixme506: char_skill.cpp dosyas�nda eksik beceriler eklendi.
@fixme507: char_item.cpp dosyas�nda anti-sonland�rma efekti.
@fixme508: char.h dosyas�nda POINT_MAX 255'in �zerinde (KULLANILMIYOR).
@fixme509: questmanager.cpp dosyas�nda reload q d�zeltmesi.
@fixme510: char_battle.cpp dosyas�nda pelerin etkisi birle�tirildi.
@fixme511: char_skill.cpp dosyas�nda GDF d�zeltmesi.
@fixme512: char_skill.cpp dosyas�nda ninja g�r�nmezken sald�r�y� g�z ard� et.
@fixme513: cmd_general.cpp dosyas�nda d�zeltme yap�ld�.
@fixme514: dungeon.cpp dosyas�nda d�zeltme yap�ld�.
@fixme515: Kod genelinde (it++ -> ++it || nullptr -> nullptr) optimizasyonu.
@fixme516: item.h dosyas�nda (virtual void to void || &override).
@fixme517: char_battle.cpp dosyas�nda DeathBlow - sava��� d���ndaki �� s�n�f i�in daha fazla hasar.
@fixme518: cube.cpp dosyas�nda reload d�zeltmesi.
@fixme519: ---; uint8_t t�r�n�n uint16_t olarak rafine edilmesi d�zeltildi.
@fixme520: char.cpp dosyas�nda evcil hayvan �ift bonus hatas� d�zeltildi.
@fixme521: cube.cpp dosyas�nda �ekirdek ��kme d�zeltmesi.
@fixme522: char_battle.cpp ve char_item.cpp dosyalar�nda farkl� haritalarda Grup Exp/Yang/D���� Payla��m� d�zeltildi.
@fixme523: ClientManager.cpp ve safebox.cpp dosyalar�nda kasa bellek s�z�nt�s� d�zeltildi.
@fixme524: questlua_npc.cpp dosyas�nda nadir �ekirdek ��kme hatas� d�zeltildi.
@fixme525: shop_manager.cpp dosyas�nda bellek s�z�nt�s� d�zeltildi.
@fixme526: cmd_gm.cpp dosyas�nda ch -> tch olarak g�ncellendi.
@fixme527: item_manager.cpp dosyas�nda �ekirdek ��kmesini �nleme.
@fixme528: input_main.cpp dosyas�nda h�zl� slot d�zeltmesi.
@fixme529: cmd_gm.cpp dosyas�nda lonca yap�s� e�yalar�n�n kullan�labilirli�i sa�land�.
@fixme530: char.cpp dosyas�nda cinsiyet de�i�tirme, yeniden y�kleme olmadan m�mk�n.
@fixme531: char.cpp dosyas�nda kanal de�i�tirirken tekrar d�zeltme.
@fixme532: x; 255 bonus uzant�s�.
@fixme533: marriage.cpp ve questlua_marriage.cpp dosyalar�nda d���n d�zeltmeleri.
@fixme534: char_battle.cpp dosyas�nda diren� etkinli�i ��kme d�zeltmesi.
@fixme535: char_item.cpp dosyas�nda otomatik e�ya verme d�zeltmesi.
@fixme536: questlua_pc.cpp dosyas�nda Durum S�f�rlama - -1 Durum puan� ge�ersizdir.
@fixme537: length.h dosyas�nda SHOP_TAB_COUNT_MAX 2 olarak ayarland� -> ��nk� ShopEx 3 ile hata veriyor.
@fixme538: mining.cpp dosyas�nda maksimum EXP al�m� rafinasyonu yok sayar.
@fixme539: dungeon.cpp dosyas�nda yaln�zca canavarlar ve ta�lar silinir.
@fixme540: libthecore - utils.c dosyas�nda rastgele-fix d�zeltmesi.
@fixme541: Performans d�zenlemesi [�nek ++/-- operat�rleri, ilkel olmayan t�rler i�in tercih edilmelidir.]
@fixme542: item_attribute.cpp dosyas�nda nadir �ekirdek ��kme hatas� d�zeltmesi.
@fixme543: char_item.cpp dosyas�nda ��kme d�zeltmesi - �l� iken e�ya al�namaz!
@fixme544: input_main.cpp dosyas�nda hasar/menzil hack d�zeltmesi.

@custom001: char_affect.cpp dosyas�nda iksirler i�in g�sterim.
@custom002: polymorph.cpp, char_affect.cpp, char_item.cpp dosyalar�nda Polimorf (�ekil de�i�tirme) harita kara listesi.
@custom003: char_battle.cpp dosyas�nda Ekstra EXP Y�z��� Bonusu eklendi.
@custom004: (A��klama yok)
@custom005: char_horse.cpp dosyas�nda IS_MOUNTABLE_ZONE (Binilebilir Alan).
@custom006: char_item.cpp dosyas�nda belirli haritalarda standart evcil hayvan kullan�m� engellendi [IS_BLOCKED_PET_SUMMON_MAP].
@custom007: char_item.cpp dosyas�nda �zellikleri de�i�tirme/ekleme engellendi [Jungheld d�zeltmesi].
@custom008: char_item.cpp dosyas�nda MoveItem -> DestCell i�lemi.
@custom009: char_item.cpp dosyas�nda kemerde t�m ��elere izin verme.
@custom010: char_skill.cpp dosyas�nda PAERYONG becerisi d��man merkezinde.
@custom011: cmd_gm.cpp dosyas�nda kullan�c� koordinatlar� listelendi.
@custom012: char_item.cpp dosyas�nda ��l� Sava� s�ras�nda binek kullan�m� devre d��� b�rak�ld�.
@custom013: char_manager.cpp dosyas�nda f�s�lt� (whisper) sayac� s�f�rland�.
@custom014: char_state.cpp dosyas�nda yeni do�ma (respawn) ayarlar�.
@custom015: cmd_emotion.cpp dosyas�nda ayn� cinsiyete sahip karakterler aras�nda duygu (emotion) kullan�m�.
@custom016: cmd_emotion.cpp dosyas�nda maske olmadan duygu (emotion) kullan�m�.
@custom017: cmd_general.cpp dosyas�nda at kontrolc�s�.
@custom018: (A��klama yok)
@custom019: desc_client.cpp dosyas�nda kanal durumu g�ncelleme s�resi.
@custom020: exchange.cpp ve shop.cpp dosyalar�nda takas efekti.
@custom021: char_item.cpp ve fishing.h dosyalar�nda yeni inciler.
@custom022: input_main.cpp dosyas�nda donmu� sohbet (frozen Chat).
@custom023: input_main.cpp dosyas�nda belirli haritalarda d�kkan a�maya izin verilmedi (CanOpenShopHere).
@custom024: item_attribute.cpp dosyas�nda �ift �zellik de�i�tirme.
@custom025: questlua_pc.cpp dosyas�nda GM yetkilerinin komuta g�re s�n�rland�r�lmas� [/strip].
@custom026: char_item.cpp dosyas�nda nadir bonuslar etkinle�tirildi.
@custom027: char_item.cpp dosyas�nda Vnum[27874] �zerinde k�t� etkiler (BadAffect) kald�r�ld�.
@custom028: char_item.cpp dosyas�nda t�m "z�rh ��eleri" de�i�tirilebilir.
@custom029: char_item.cpp dosyas�nda attr_always_add => (belirtilmemi�)
@custom030: char_item.cpp dosyas�nda attr_always_5_add => (belirtilmemi�)
@custom031: char_item.cpp dosyas�nda %4 bonus.
@custom032: char_item.cpp dosyas�nda su ve harman ��eleri ayn� anda kullan�lamaz.
@custom033: input_login dosyas�nda OX-Event Giri� Yok.
@custom034: (A��klama yok)
@custom035: (A��klama yok)
@custom036: shop.cpp dosyas�nda sat�ld�ktan sonra otomatik kapanma.
@custom037: (A��klama yok)
@custom038: cmd_general.cpp dosyas�nda bekleme s�resi s�ralamas�.
@custom039: char_item.cpp dosyas�nda otomatik iksir etkisi.

@infome000: �lgin� olabilecek bir �ey.
@infome001: char_item.cpp dosyas�nda Weihnachtstruhe TEST.
*/
#endif

