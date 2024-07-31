#pragma once


#include <iostream>
#include <map>

#ifdef _XBOX
#include <stdexcept>
#include <xtl.h>
#include <xmath.h>
#include "../../../Basics.h"
#else
#pragma comment(lib, "Ws2_32.lib")
#include <winsock.h>
#endif // _XBOX




#define DEFINE_SOCKET_MESSAGE_DATA_ID_PROTOCOL(ID,PROTOCOL) \
	static int GetID(){ \
	return ID;\
}\
	static int GetProtocol(){\
	return PROTOCOL; \
}\

#define DEFINE_SOCKET_MESSAGE_FROM_CONST_DATA(DATA) SocketMessage(DATA.GetID(),DATA.GetProtocol(),(void*)&DATA,sizeof(DATA))

struct SocketMessage {

	int ID;
	int PROTOCOL;
	char _padding_[8];
	sockaddr address_from;
	char _message_[256];
public:
	SocketMessage(int ID, int PROTOCOL, void* from, int size);
	SocketMessage();
};

struct SocketData {
	SOCKET TCP_SOCKET;
	float UDP_TIMEOUT;
public:
	SocketData(int TCP_SOCKET);
	SocketData();
};

struct SMDataTest {
	DEFINE_SOCKET_MESSAGE_DATA_ID_PROTOCOL(0x1, IPPROTO_TCP);
};
struct SMDataTest_UDP {
	DEFINE_SOCKET_MESSAGE_DATA_ID_PROTOCOL(0x1, IPPROTO_UDP);
};

struct SockaddrComparator {
	bool operator()(const sockaddr* lhs, const sockaddr* rhs) const {
		return memcmp(lhs, rhs, sizeof(*lhs)) < 0;
	}
	bool operator()(const sockaddr& lhs, const sockaddr& rhs) const {
		return memcmp(&lhs, &rhs, sizeof(lhs)) < 0;
	}
};







class Socket {
public:
	static const char* IP_ADDR;

	Socket();               // Constructor
	~Socket();              // Destructor

	void InitSockets();     // Initialize TCP and UDP sockets
	void SetBind(); // Bind sockets to the specified IP
	void SetAddress(const char* address, short port);
	void SetNonBlockingMode(); // Bind sockets to the specified IP
	void Cleanup();         // Clean up resources
	bool IsWorks();
	bool IsClient();
	bool IsServer();
	int GetConnectStatus();

	sockaddr GetAddress();
	sockaddr GetAddressTo();


	void InitServer();
	int InitClient();

	void UpdateServer(float delta); // Handle incoming connections and data
	void UpdateClient(float delta);

	void SendTCPMessageTo(SOCKET to, SocketMessage* msg);
	void SendTCPMessageToServer(SocketMessage* msg);
	void SendTCPMessageToClients(SocketMessage* msg);


	void SendUDPMessageTo(sockaddr to, SocketMessage* msg);
	void SendUDPMessageToServer(SocketMessage* msg);
	void SendUDPMessageToClients(SocketMessage* msg);

	sockaddr MatchClientTcpToUdpAddress(sockaddr tcp_address);

#ifdef _XBOX
	XUID GetXUID(int);
#endif

private:
	SOCKET _tcpSocket;      // TCP socket
	SOCKET _udpSocket;      // UDP socket
	std::map<sockaddr, SocketData, SockaddrComparator> _clients;

	std::map<sockaddr, bool, SockaddrComparator> _udp_clients_map;

	sockaddr _address_to;
	int _connection_status;
	bool _client;
	bool _server;

	typedef void (SocketMSGCommon)(Socket*, SOCKET, SocketMessage*);
	typedef void (SocketCommonInfo)(Socket*, SOCKET);

public:
	SocketMSGCommon* MSG_HANDLE_SERVER_MESSAGES;
	SocketCommonInfo* MSG_HANDLE_SERVER_CLIENT_LOST_CONNECTION;
	SocketCommonInfo* MSG_HANDLE_SERVER_CLIENT_JOIN;


	SocketMSGCommon* MSG_HANDLE_CLIENT_MESSAGES;
	SocketCommonInfo* MSG_HANDLE_CLIENT_JOIN_SERVER;
	SocketCommonInfo* MSG_HANDLE_CLIENT_LOST_CONNECTION_SERVER;

	static void MSG_HANDLE_SERVER_MESSAGES_TEMP(Socket*, SOCKET, SocketMessage*);
	static void MSG_HANDLE_SERVER_CLIENT_LOST_CONNECTION_TEMP(Socket*, SOCKET);
	static void MSG_HANDLE_SERVER_CLIENT_JOIN_TEMP(Socket*, SOCKET);

	static void MSG_HANDLE_CLIENT_MESSAGES_TEMP(Socket*, SOCKET, SocketMessage*);
	static void MSG_HANDLE_CLIENT_JOIN_SERVER_TEMP(Socket*, SOCKET);
	static void MSG_HANDLE_CLIENT_LOST_CONNECTION_SERVER_TEMP(Socket*, SOCKET);



};

