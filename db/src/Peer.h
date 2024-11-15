// vim: ts=8 sw=4
#ifndef __INC_PEER_H__
#define __INC_PEER_H__

#include "PeerBase.h"
#include "../../common/CommonDefines.h"

class CPeer : public CPeerBase
{
protected:
	virtual void OnAccept();
	virtual void OnClose();
	virtual void OnConnect();

public:
#pragma pack(1)
	typedef struct _header
	{
		uint8_t bHeader;
		uint32_t dwHandle;
		uint32_t dwSize;
	} HEADER;
#pragma pack()
	enum EState
	{
		STATE_CLOSE = 0,
		STATE_PLAYING = 1
	};

	CPeer();
	virtual ~CPeer();

	void EncodeHeader(uint8_t header, uint32_t dwHandle, uint32_t dwSize);
	bool PeekPacket(int& iBytesProceed, uint8_t& header, uint32_t& dwHandle, uint32_t& dwLength, const char** data);
	void EncodeReturn(uint8_t header, uint32_t dwHandle);

	void ProcessInput();
	int Send();

	uint32_t GetHandle();
	uint32_t GetUserCount();
	void SetUserCount(uint32_t dwCount);

	void SetPublicIP(const char* ip) { m_stPublicIP = ip; }
	const char* GetPublicIP() { return m_stPublicIP.c_str(); }

	void SetChannel(uint8_t bChannel) { m_bChannel = bChannel; }
	uint8_t GetChannel() { return m_bChannel; }

#ifdef ENABLE_MOVE_CHANNEL
	void SetAddr(const long l) { m_lAddr = l; };
	long GetAddr() const { return m_lAddr; };
	bool CheckMapIndex(const long lMapIndex) const;
#endif

	void SetListenPort(uint16_t wPort) { m_wListenPort = wPort; }
	uint16_t GetListenPort() { return m_wListenPort; }

	void SetP2PPort(uint16_t wPort);
	uint16_t GetP2PPort() { return m_wP2PPort; }

	void SetMaps(long* pl);
	long* GetMaps() { return &m_alMaps[0]; }

	bool SetItemIDRange(TItemIDRangeTable itemRange);
	bool SetSpareItemIDRange(TItemIDRangeTable itemRange);
	bool CheckItemIDRangeCollision(TItemIDRangeTable itemRange);
	void SendSpareItemIDRange();

private:
	int m_state;

	uint8_t m_bChannel;
#ifdef ENABLE_MOVE_CHANNEL
	long m_lAddr;
#endif
	uint32_t m_dwHandle;
	uint32_t m_dwUserCount;
	uint16_t m_wListenPort; // 게임서버가 클라이언트를 위해 listen 하는 포트
	uint16_t m_wP2PPort; // 게임서버가 게임서버 P2P 접속을 위해 listen 하는 포트
	long m_alMaps[MAP_ALLOW_LIMIT]; // 어떤 맵을 관장하고 있는가?

	TItemIDRangeTable m_itemRange;
	TItemIDRangeTable m_itemSpareRange;

	std::string m_stPublicIP;
};

#endif
