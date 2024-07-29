// Socket.h
#pragma once

#include <xtl.h>
#include <iostream>
#include <xmath.h>

#include <stdexcept>
#include <boost/function.hpp>
#include <boost/bind.hpp>

#include <vector>
#include "../../../Basics.h"


#define SocketMessage_BUFFER 0x256
#define DEFINE_MSG_DATA_ID(ID) static int GetID() {return ID;} 
#define DEFINE_MESSAGE_FROM_DATA_CONST(DATA) SocketMessage(DATA.GetID(),(void*)&DATA,sizeof(DATA))
#define SOCKET_SEND_MESSAGE_DATA_TO_CLIENTS(SOCKET,DATA) { \
SocketMessage _msg_ =  SocketMessage(DATA.GetID(),(void*)&DATA,sizeof(DATA)); \
	SOCKET->SendMessageToClients(&_msg_); \
} \

struct SocketMessageDataZero {
	bool flag;
	DEFINE_MSG_DATA_ID(1);
};
struct SocketMessageData{

};


#pragma pack(push, 0x10)
struct  SocketMessage {
	int ID;
	char _padding[0xC];
	sockaddr address;
	char buffer[SocketMessage_BUFFER];
public:
	SocketMessage(int ID,void* buffer,size_t size);
	SocketMessage();
};
#pragma pack(pop)


class Socket
{	
public:
	Socket();
	static const char* IP_ADDR;
protected:

	SOCKET _socket;
	sockaddr_in _address;
	bool _server;
	bool _client;
	bool _connected;
	bool _stop;

	//	SocketThread _main_thread;
	//SocketThread _main_server_join_thread;
	std::map<SOCKET, int> _clients;



	typedef void (SocketMSGCommon)(Socket*, SOCKET, SocketMessage*);
	typedef void (SocketCommonInfo)(Socket*, SOCKET);

public:
	SocketMSGCommon* MSG_HANDLE_SERVER_MESSAGES;
	SocketCommonInfo* MSG_HANDLE_SERVER_CLIENT_LOST_CONNECTION;
	SocketCommonInfo* MSG_HANDLE_SERVER_CLIENT_JOIN;


	SocketMSGCommon* MSG_HANDLE_CLIENT_MESSAGES;
	SocketCommonInfo* MSG_HANDLE_CLIENT_JOIN_SERVER;
	SocketCommonInfo* MSG_HANDLE_CLIENT_LOST_CONNECTION_SERVER;




public:

	void RunThreaded();
	void SetSocketBind(const char* Address,short port,short AF_MODE);
	void SetSocketNonBlocking(); 
	void SendMessageTo(SOCKET socket, SocketMessage* msg);
	sockaddr GetAddress();
	sockaddr GetAddressF();
	XUID GetXUID(int index);


#pragma region Server_H
	void StartServer();
	void UpdateServer();
	int IsServer();


#pragma region ServerMessages_BASE_H
	static void SRecieveMessage(Socket*, SOCKET, SocketMessage*);
	static void SLostConnectionToClient(Socket*, SOCKET);
	static void SClientJoinedToServer(Socket*, SOCKET);
#pragma endregion
	void SendMessageToClients(SocketMessage*);




#pragma endregion


#pragma region Client_H
	int StartClient();
	void UpdateClient();
	int IsClient();	

#pragma region ClientMessages_BASE_H
	static void ClientJoinedToServer(Socket*, SOCKET);
	static void CRecieveMessage(Socket*, SOCKET, SocketMessage*);
	static void CLostConnectionToServer(Socket*, SOCKET);
#pragma endregion

	void SendMessageToServer(SocketMessage*);
#pragma endregion




	void InitSocket();
	void CloseSocket();

};

