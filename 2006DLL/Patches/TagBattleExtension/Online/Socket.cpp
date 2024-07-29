#include "Socket.h"
#include <iostream>

const char* Socket::IP_ADDR = "127.0.0.1";



Socket::Socket()
{
	this->MSG_HANDLE_SERVER_MESSAGES = Socket::SRecieveMessage;
	this->MSG_HANDLE_SERVER_CLIENT_LOST_CONNECTION = Socket::SLostConnectionToClient;
	this->MSG_HANDLE_SERVER_CLIENT_JOIN = Socket::SClientJoinedToServer;

	this->MSG_HANDLE_CLIENT_MESSAGES = Socket::CRecieveMessage;
	this->MSG_HANDLE_CLIENT_JOIN_SERVER = Socket::ClientJoinedToServer;
	this->MSG_HANDLE_CLIENT_LOST_CONNECTION_SERVER = Socket::CLostConnectionToServer;

	_server = false;
	_client = false;
	_socket = INVALID_SOCKET; // Initialize socket to an invalid state
}

void Socket::RunThreaded()
{
	if (_server) {
		// Uncomment and implement the threading logic for the server
		// _main_thread = SocketThread(this, Socket::StartServer, 0);
	}
	else if (_client) {
		// Uncomment and implement the threading logic for the client
		// _main_thread = SocketThread(this, Socket::StartClient, 0);
	}
}

void Socket::SetSocketBind(const char* Address = "127.0.0.1", short port = 1000, short AF_MODE = AF_INET)
{
	sockaddr_in sa;
	sa.sin_family = AF_MODE;
	sa.sin_addr.s_addr = inet_addr(Address); // No need for htonl here
	sa.sin_port = htons(port);


	_address = sa;
	if (_socket != INVALID_SOCKET) { // Check if socket is valid
		if (bind(_socket, (sockaddr*)&sa, sizeof(sa)) == SOCKET_ERROR) {
			std::cerr << "Bind failed: " << WSAGetLastError() << std::endl;
		}
	}
}

void Socket::SetSocketNonBlocking()
{
	if (_socket != INVALID_SOCKET) {
		ULONG bNonblocking = TRUE;
		if (ioctlsocket(_socket, FIONBIO, &bNonblocking) == SOCKET_ERROR) {
			std::cerr << "Failed to set non-blocking mode: " << WSAGetLastError() << std::endl;
		}
	}
}

void Socket::SendMessageTo(SOCKET socket, SocketMessage* msg)
{
	if (send(socket, (char*)msg, sizeof(SocketMessage), 0) == SOCKET_ERROR) {
		std::cerr << "Send error: " << WSAGetLastError() << std::endl;
	}
}

sockaddr Socket::GetAddress()
{
      return *reinterpret_cast<sockaddr*>(&_address);
}

sockaddr Socket::GetAddressF()
{
	sockaddr local_address;
	int address_length = sizeof(local_address);
	getsockname(_socket, (struct sockaddr*)&local_address, &address_length);
	return local_address;

}

XUID Socket::GetXUID(int index = 0)
{
	XUID xuid;
	XUserGetXUID(index,&xuid);
	return xuid;
}

void Socket::StartServer()
{
	_server = true;
	if (_socket != INVALID_SOCKET) {
		if (listen(_socket, SOMAXCONN) == SOCKET_ERROR) {
			std::cerr << "Listen failed: " << WSAGetLastError() << std::endl;

		}
	}

}

void Socket::UpdateServer()
{
	SOCKET client_socket;
	sockaddr_in client_addr;
	int client_addr_len = sizeof(client_addr);

	client_socket = accept(_socket, (sockaddr*)&client_addr, &client_addr_len);
	if (client_socket != INVALID_SOCKET) {
		_clients[client_socket] = 1; // Connection established
		this->MSG_HANDLE_SERVER_CLIENT_JOIN(this,client_socket);
		std::cout << "[Server] Client Joined #" << client_socket << std::endl;
	}


	SocketMessage message;
	for (std::map<SOCKET,int>::iterator it = _clients.begin(); it != _clients.end();it++ ) {
		int mas = sizeof(message.address);
		// Check if there is data to read

		SocketMessage message;
		fd_set readfds;
		struct timeval timeout;

		// Set timeout for select
		timeout.tv_sec = 0;
		timeout.tv_usec = 0; // Non-blocking

		FD_ZERO(&readfds);
		FD_SET(it->first, &readfds);
		
		int cc = select(it->first + 1, &readfds, NULL, NULL, &timeout);
		for (int i = 0;i<cc;i++){
			int br = recvfrom(it->first, (char*)&message, sizeof(message), 0,&message.address,&mas);

			if (br < 0) {
				if (WSAGetLastError() == WSAEWOULDBLOCK) {
					continue;
				}
				break;
				std::cerr << "recv error: " << WSAGetLastError() << std::endl;
				it->second = -1; // Mark as disconnected
				this->MSG_HANDLE_SERVER_CLIENT_LOST_CONNECTION(this, it->first);
				
			}
			else if (br == 0) {
				break;
				std::cout << "Connection closed by peer." << std::endl;
				it->second = -1; // Mark as disconnected
				this->MSG_HANDLE_SERVER_CLIENT_LOST_CONNECTION(this, it->first);
			}
			else {
				std::cout << "Received " << br << " bytes." << std::endl;
				this->MSG_HANDLE_SERVER_MESSAGES(this, it->first, &message);
			}

		}
	

		int br = recvfrom(it->first, (char*)&message, sizeof(message), 0,&message.address,&mas);
		if (br < 0) {
			if (WSAGetLastError() == WSAEWOULDBLOCK) {
				continue;
			}
			std::cerr << "recv error: " << WSAGetLastError() << std::endl;
			it->second = -1; // Mark as disconnected
			this->MSG_HANDLE_SERVER_CLIENT_LOST_CONNECTION(this, it->first);
		}
		else if (br == 0) {
			std::cout << "Connection closed by peer." << std::endl;
			it->second = -1; // Mark as disconnected
			this->MSG_HANDLE_SERVER_CLIENT_LOST_CONNECTION(this, it->first);
		}
		else {
			std::cout << "Received " << br << " bytes." << std::endl;
			this->MSG_HANDLE_SERVER_MESSAGES(this, it->first, &message);
		}

		// Remove disconnected clients
		if (it->second == -1) {
			closesocket(it->first);
			_clients.erase(it);
		}
	
	}
}


int Socket::IsServer()
{
 return _server;
}

void Socket::SRecieveMessage(Socket*, SOCKET sock, SocketMessage* msg)
{

	printf("[Server][SOCKET:%d] Got Message : %d", sock, msg->ID);

}

void Socket::SLostConnectionToClient(Socket*, SOCKET sock)
{
	printf("[Server] Client Lost Connection  : #%d\n", sock);
}

void Socket::SClientJoinedToServer(Socket*, SOCKET sock)
{
    printf("[Server] Client Joined   : #%d\n", sock);
}

void Socket::SendMessageToClients(SocketMessage* msg)
{
	for (std::map<SOCKET,int>::iterator it = _clients.begin(); it != _clients.end(); ++it) {
		if (it->second != -1) {
			SendMessageTo(it->first, msg);
		}
	}
}


int Socket::StartClient()
{// Attempt to connect
	if (_connected) return _connected;
	_client = true;

	int result = connect(_socket, (const sockaddr*)&_address, sizeof(_address));
	if (result == SOCKET_ERROR) {
		int error = WSAGetLastError();
		if (error == WSAEWOULDBLOCK) {
			std::cout << "Connection in progress..." << std::endl;
			// You may want to implement a mechanism to check for connection completion
		}
		else if (error == WSAEISCONN) {
			_connected = true;
		}
		else {
			std::cerr << "Error connecting to server: " << error << std::endl;
		}
	}
	else {
		_connected = true;
		std::cout << "Connected to server." << std::endl;
		this->MSG_HANDLE_CLIENT_JOIN_SERVER(this, _socket);
		return 0;
	}
	return _connected;


}

void Socket::UpdateClient()
{
	SocketMessage message;
	fd_set readfds;
	struct timeval timeout;

	// Set timeout for select
	timeout.tv_sec = 0;
	timeout.tv_usec = 0; // Non-blocking
	FD_ZERO(&readfds);
	FD_SET(_socket, &readfds);

	int mas = sizeof(message.address);
	int cc = select(_socket + 1, &readfds, NULL, NULL, &timeout);
	for (int i = 0;i<cc;i++){
		int br = recvfrom(_socket, (char*)&message, sizeof(message), 0,&message.address,&mas);

		if (br < 0) {
			if (WSAGetLastError() == WSAEWOULDBLOCK) {
				std::cout << "No data available to read." << std::endl;
			}
			else {
				std::cerr << "recv error: " << WSAGetLastError() << std::endl;
				_connected = false;
				this->MSG_HANDLE_CLIENT_LOST_CONNECTION_SERVER(this, _socket);

			}
		}
		else if (br == 0) {
			std::cout << "Connection closed by peer." << std::endl;
			this->MSG_HANDLE_CLIENT_LOST_CONNECTION_SERVER(this, _socket);
		}
		else {
			std::cout << "Received " << br << " bytes." << std::endl;
			this->MSG_HANDLE_CLIENT_MESSAGES(this, _socket, &message);
		}

	}



	int br = recvfrom(_socket, (char*)&message, sizeof(message), 0,&message.address,&mas);
	if (br < 0) {
		if (WSAGetLastError() == WSAEWOULDBLOCK) {
			std::cout << "No data available to read." << std::endl;
		}
		else {
			std::cerr << "recv error: " << WSAGetLastError() << std::endl;
			_connected = false;
			this->MSG_HANDLE_CLIENT_LOST_CONNECTION_SERVER(this, _socket);

		}
	}
	else if (br == 0) {
		std::cout << "Connection closed by peer." << std::endl;
		this->MSG_HANDLE_CLIENT_LOST_CONNECTION_SERVER(this, _socket);
	}
	else {
		std::cout << "Received " << br << " bytes." << std::endl;
		this->MSG_HANDLE_CLIENT_MESSAGES(this, _socket, &message);
	}
}

int Socket::IsClient()
{
 return _client;
}

void Socket::ClientJoinedToServer(Socket*, SOCKET sock)
{
	printf("[Client] Join To Server : %d\n", sock);
}

void Socket::CRecieveMessage(Socket*, SOCKET sock, SocketMessage* msg   )
{
	printf("[Client] Got Message : %d\n", sock, msg->ID);
}

void Socket::CLostConnectionToServer(Socket*, SOCKET sock)
{
	printf("[Client] Lost Connection To server : %d\n", sock);
}

void Socket::SendMessageToServer(SocketMessage* msg)
{
	SendMessageTo(_socket, msg);
}

void Socket::InitSocket()
{
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		std::cerr << "WSAStartup failed: " << WSAGetLastError() << std::endl;
		return; // Exit if initialization fails
	}

	_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (_socket == INVALID_SOCKET) {
		std::cerr << "Socket creation failed: " << WSAGetLastError() << std::endl;
		WSACleanup(); // Clean up Winsock
		return; // Exit if socket creation fails
	}


}

void Socket::CloseSocket()
{
	closesocket(_socket);
	_client = false;
	_server = false;
	_socket = INVALID_SOCKET;
	_connected = false;
	WSACleanup();
}

SocketMessage::SocketMessage(int ID,void* buffer, size_t size)
{
	this->ID = ID;
	memcpy((void*)&this->buffer, buffer, size);
}

SocketMessage::SocketMessage()
{
	memset(&this->buffer, 0, SocketMessage_BUFFER); // Initialize buffer to zero
}