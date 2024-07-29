#include "TagBattleOnline.h"
#include <xboxmath.h>
#include "..\..\DebugLog\DebugLog.h"
#include <map>
#include <sstream>
#include <string>
#include <set>
#include "AtgInput.h"

#include <CsdObject.h>
#include <Sox/StepableThread.h>
using namespace TagBattleMain;



struct SocketBuff {
	SocketBuff(){};

	sockaddr address;

	// Define a comparison operator for SocketBuff
	bool operator<(const SocketBuff& other) const {
		return memcmp(&address, &other.address, sizeof(sockaddr)) < 0;
	}
	explicit SocketBuff(const sockaddr& addr){
		  memcpy(&address, &addr, sizeof(sockaddr));
	}

	
	// Assignment operator
	SocketBuff& operator=(const sockaddr& addr) {
		memcpy(&address, &addr, sizeof(sockaddr));
		return *this; // Return the current object
	}


	// Equal operator
	bool operator==(const SocketBuff& other) const {
		return memcmp(&address, &other.address, sizeof(sockaddr)) == 0;
	}
	// Equal operator
	bool operator==(const sockaddr& other) const {
		return memcmp(&address, &other, sizeof(sockaddr)) == 0;
	}
};

struct SocketExtra {

	bool local;
	int Player;
	std::string chr_lua;
};

struct MessageDataSpawnPlayer{
public:
	XUID xuid;
	char chr_name[0x16];
	DEFINE_MSG_DATA_ID(0x10);

};

struct MessageDataServerGetClientPlayerInfo{
public:
	DEFINE_MSG_DATA_ID(0x1);
};

struct MessageDataServerSetClientInfoToServer{
public:
	XUID xuid;
	char chr_name[0x16];
	DEFINE_MSG_DATA_ID(0x2);
};
struct MessageDataServerReplicateClientInfoToClients{
public:
	XUID xuid;
	char chr_name[0x16];
	DEFINE_MSG_DATA_ID(0x3);
};


struct MessageDataSetPlayerPosition{
public:
	XMVECTOR Position;
	XMMATRIX RFTransformMatrix0x70;
	XUID xuid;
	int AnimID;
	int AnimFL;	
	DEFINE_MSG_DATA_ID(0x11);

};

struct RemoveClientByXuid{
public:
	XUID xuid;
	DEFINE_MSG_DATA_ID(0x12);

};


struct OBJPlayerSpawnData{
	const char *player_name;
	int player_index;
	int player_controller_id;
	int player_flag0;
	int Unk0x10;
	int Unk0x14;
	int Unk0x18;
	int Unk0x1C;
	XMVECTOR player_position;
	XMVECTOR player_rotation;
	int player_unk_flag1;
	void *player_based_on;
	char player_unk_flag2;

public: OBJPlayerSpawnData();


};
OBJPlayerSpawnData::OBJPlayerSpawnData()
{
	this->player_index = -1;
	this->player_name = 0;
	this->player_controller_id = 0;
	this->Unk0x10 = 1;
	this->player_flag0 = -1;
	this->player_unk_flag1 = 0;
	this->player_based_on = 0;
	this->player_unk_flag2 = 1;

	this->player_position = XMVectorZero();
	this->player_rotation = XMVectorZero();

}



Socket _socket;
int LocalPlayer;
Sonicteam::CsdObject* Player_TAG;
Sonicteam::SoX::RefCountObject* Player_TAG_DRAWABLE;
Sonicteam::SoX::IResource* Player_TAG_SHADER;

// Define your structures



std::map<XUID, SocketExtra> Players;
std::map<SOCKET, XUID> Players_socket;
std::map<std::string,std::string> players_chr_remap;

static int GetLocalPlayer(){
	Sonicteam::DocMarathonImp* impl = 	*(Sonicteam::DocMarathonImp**)(*(UINT32*)0x82D3B348 + 0x180);
	UINT32 gameimp = *(UINT32*)(impl->DocCurrentMode + 0x6C);
	UINT32 NameActorPlayers = *(UINT32*)(gameimp + 0x1428);
	UINT32 ObjPlayer = *(UINT32*)(NameActorPlayers + 0x38);
	return ObjPlayer;
}


static const char* GetLocalPKGPlayerName(){
	std::string* str =  (std::string*)(GetLocalPlayer() + 0x74);
	return str->c_str();
}


static int SpawnDummyCharacter(const char* name = "sonic_new.lua"){
    // Spawn dummy character
    OBJPlayerSpawnData data;
    data.player_name = name;
    data.player_unk_flag1 = 0;
    data.player_unk_flag2 = 0;
    data.player_controller_id = 1;

    Sonicteam::DocMarathonImp* impl = *(Sonicteam::DocMarathonImp**)(*(UINT32*)0x82D3B348 + 0x180);
    UINT32 gameimp = *(UINT32*)(impl->DocCurrentMode + 0x6C);
    UINT32 NameActorPlayers = *(UINT32*)(gameimp + 0x1428);
    int Player = (int)BranchTo(0x8219FAE0, int, NameActorPlayers, &data);

    Sonicteam::Player::State::IMachine* machine = *(Sonicteam::Player::State::IMachine**)(Player + 0xE4);
    machine->ChangeMashineState(0x1E);
    Sonicteam::Player::State::ICommonContext* contxt = dynamic_cast<Sonicteam::Player::State::ICommonContext*>(machine->GetMashineContext().get());
    contxt->AnimationState = 0x10;
    contxt->AnimationState = -1;
    return Player;
}

// Function to handle client messages
static void ClientMessages(Socket* socket, SOCKET client_socket, SocketMessage* message) {
	if (message->ID == MessageDataServerGetClientPlayerInfo::GetID()) {
		MessageDataServerSetClientInfoToServer _data_;
		_data_.xuid = socket->GetXUID(0);
		strcpy(_data_.chr_name,players_chr_remap[GetLocalPKGPlayerName()].c_str());
		SocketMessage msg = DEFINE_MESSAGE_FROM_DATA_CONST(_data_);
		socket->SendMessageToServer(&msg);
	}

	if (message->ID == RemoveClientByXuid::GetID()){

		DebugLogV2::PrintNextFixed("[Client] Remove Client By XUID");

		RemoveClientByXuid* _data_get = reinterpret_cast<RemoveClientByXuid*>(&message->buffer);

		if (Players.find(_data_get->xuid) != Players.end() ){
			SocketExtra* extra =  &Players[_data_get->xuid];
			if (extra->Player) BranchTo(0x82195298,int,extra->Player,1);
			Players.erase(Players.find(_data_get->xuid));

		}



	}

	if (message->ID == MessageDataServerReplicateClientInfoToClients::GetID()) {
		MessageDataServerReplicateClientInfoToClients* _data_get = reinterpret_cast<MessageDataServerReplicateClientInfoToClients*>(&message->buffer);

		// Check if the player already exists
		if (Players.find(_data_get->xuid) == Players.end()) {
			DebugLogV2::PrintNextFixed("[Client] Add Dummy Player");
			SocketExtra extra;
			extra.Player = SpawnDummyCharacter(_data_get->chr_name);
			Players[_data_get->xuid] = extra;
		}
	}

	if (message->ID == MessageDataSetPlayerPosition::GetID()) {
		MessageDataSetPlayerPosition* _data_get = reinterpret_cast<MessageDataSetPlayerPosition*>(&message->buffer);

		// Check if the player exists before updating position

		if (Players.find(_data_get->xuid) != Players.end() && _data_get->xuid != _socket.GetXUID(0)) {
			UINT32 ObjPlayer = Players[_data_get->xuid].Player;
			if (ObjPlayer) {
				UINT32 PlayerPosture = *(UINT32*)(ObjPlayer + 0xDC);
				Sonicteam::Player::RootFrame* PlayerRootFrame = *(Sonicteam::Player::RootFrame**)(ObjPlayer + 0xCC);

				// Update the transform matrix and position
				PlayerRootFrame->RFTransformMatrix0x70 = _data_get->RFTransformMatrix0x70;
				*(XMVECTOR*)(PlayerPosture + 0xB0) = _data_get->Position;

				// Update animation state
				Sonicteam::Player::State::IMachine* machine = *(Sonicteam::Player::State::IMachine**)(ObjPlayer + 0xE4);
				Sonicteam::Player::State::ICommonContext* context = dynamic_cast<Sonicteam::Player::State::ICommonContext*>(machine->GetMashineContext().get());
				if (context) {
					context->AnimationState = _data_get->AnimFL;
					context->CurrentAnimation = _data_get->AnimID;
				}
			}
		}
	}

}

// Function to handle server messages
static void ServerMessages(Socket* socket, SOCKET client_socket, SocketMessage* message) {
	bool action_players_new = false;

	if (message->ID == MessageDataServerSetClientInfoToServer::GetID()) {
		MessageDataServerSetClientInfoToServer* _data_get = reinterpret_cast<MessageDataServerSetClientInfoToServer*>(&message->buffer);

		// Check if the player already exists
		if (Players.find(_data_get->xuid) == Players.end()) {
			DebugLogV2::PrintNextFixed("[Server] Add Dummy Player");
			SocketExtra extra;
			extra.Player = SpawnDummyCharacter(_data_get->chr_name);
			extra.chr_lua = _data_get->chr_name;
			Players[_data_get->xuid] = extra;
		
			action_players_new = true;
			Players_socket[client_socket] = _data_get->xuid;
		}
	}

	// Notify clients about new players
	if (action_players_new) {
		for (std::map<XUID, SocketExtra>::iterator player = Players.begin(); player != Players.end(); ++player) {
			MessageDataServerReplicateClientInfoToClients _data_;
			_data_.xuid = player->first;
			strcpy(_data_.chr_name,player->second.chr_lua.c_str());
			SocketMessage msg = DEFINE_MESSAGE_FROM_DATA_CONST(_data_);
			socket->SendMessageToClients(&msg);
		}
	}

	if (message->ID == MessageDataSetPlayerPosition::GetID()) {
		MessageDataSetPlayerPosition* _data_get = reinterpret_cast<MessageDataSetPlayerPosition*>(&message->buffer);

		// Check if the player exists before updating position

		if (Players.find(_data_get->xuid) != Players.end()) {
			UINT32 ObjPlayer = Players[_data_get->xuid].Player;
			if (ObjPlayer) {
				UINT32 PlayerPosture = *(UINT32*)(ObjPlayer + 0xDC);
				Sonicteam::Player::RootFrame* PlayerRootFrame = *(Sonicteam::Player::RootFrame**)(ObjPlayer + 0xCC);

				// Update the transform matrix and position
				PlayerRootFrame->RFTransformMatrix0x70 = _data_get->RFTransformMatrix0x70;
				*(XMVECTOR*)(PlayerPosture + 0xB0) = _data_get->Position;

				// Update animation state
				Sonicteam::Player::State::IMachine* machine = *(Sonicteam::Player::State::IMachine**)(ObjPlayer + 0xE4);
				Sonicteam::Player::State::ICommonContext* context = dynamic_cast<Sonicteam::Player::State::ICommonContext*>(machine->GetMashineContext().get());
				if (context) {
					context->AnimationState = _data_get->AnimFL;
					context->CurrentAnimation = _data_get->AnimID;
				}
			}
		}
	}
}
// Function to handle a new client connection
static void ServerClientConnected(Socket* socket, SOCKET client_socket) {
 
	MessageDataServerGetClientPlayerInfo _data_;
	SocketMessage msg =  DEFINE_MESSAGE_FROM_DATA_CONST(_data_);
	socket->SendMessageTo(client_socket,&msg);

}
static void ServerClientLost(Socket* socket, SOCKET client_socket) {

	BranchTo(0x82195298,int,Players[Players_socket[client_socket]].Player,1);

	RemoveClientByXuid _data_;
	_data_.xuid = Players_socket[client_socket];
	SOCKET_SEND_MESSAGE_DATA_TO_CLIENTS(socket,_data_);

	Players.erase(Players.find(Players_socket[client_socket]));



}
float trigger_menu = 0.0f;



static void ClearSocketConInfo(){
	for (std::map<XUID,SocketExtra>::iterator it = Players.begin();it != Players.end();it++){
		if (it->first == _socket.GetXUID(0)) continue;
		BranchTo(0x82195298,int,it->second.Player,1);
	}
	LocalPlayer = 0;
	Players.clear();
	_socket.CloseSocket();
}
extern "C" int EngineDocOnUpdateHE(Sonicteam::DocMarathonImp* a1, double a2) {

	if (_socket.IsClient()){
		_socket.UpdateClient();
	}
	else if (_socket.IsServer()){
		_socket.UpdateServer();
	}

	if (LocalPlayer){
		if (_socket.IsClient()){
			Sonicteam::DocMarathonImp* impl = 	*(Sonicteam::DocMarathonImp**)(*(UINT32*)0x82D3B348 + 0x180);
			UINT32 gameimp = *(UINT32*)(impl->DocCurrentMode + 0x6C);
			UINT32 NameActorPlayers = *(UINT32*)(gameimp + 0x1428);
			UINT32 ObjPlayer = *(UINT32*)(NameActorPlayers + 0x38);
			UINT32 PlayerPosture = *(UINT32 *)(ObjPlayer + 0xDC);
			XMVECTOR P_POS =  *(XMVECTOR*)(PlayerPosture + 0xB0);
			MessageDataSetPlayerPosition s_pos;
			s_pos.xuid = _socket.GetXUID(0);
			Sonicteam::Player::RootFrame* PlayerRootFrame = *(Sonicteam::Player::RootFrame**)(ObjPlayer+ 0xCC);
			s_pos.RFTransformMatrix0x70 =  PlayerRootFrame->RFTransformMatrix0x70;
			s_pos.Position = P_POS;


			Sonicteam::Player::State::IMachine* machine  = *( Sonicteam::Player::State::IMachine**)(ObjPlayer + 0xE4);
			Sonicteam::Player::State::ICommonContext* contxt = dynamic_cast<Sonicteam::Player::State::ICommonContext*>(machine->GetMashineContext().get());
			s_pos.AnimFL = contxt->AnimationState;
			s_pos.AnimID = contxt->CurrentAnimation;


			SocketMessage msg =  DEFINE_MESSAGE_FROM_DATA_CONST(s_pos);

			_socket.SendMessageToServer(&msg);
		
		}
		else if (_socket.IsServer()){
		
			for (std::map<XUID,SocketExtra>::iterator it = Players.begin();it != Players.end();it++){
				if (it->second.Player == 0 ) continue;

				UINT32 ObjPlayer = it->second.Player;
				UINT32 PlayerPosture = *(UINT32 *)(ObjPlayer + 0xDC);
				XMVECTOR P_POS =  *(XMVECTOR*)(PlayerPosture + 0xB0);
				MessageDataSetPlayerPosition s_pos;
				s_pos.xuid = it->first;

				Sonicteam::Player::RootFrame* PlayerRootFrame = *(Sonicteam::Player::RootFrame**)(ObjPlayer+ 0xCC);
				s_pos.RFTransformMatrix0x70 =  PlayerRootFrame->RFTransformMatrix0x70;
				s_pos.Position = P_POS;


				Sonicteam::Player::State::IMachine* machine  = *( Sonicteam::Player::State::IMachine**)(ObjPlayer + 0xE4);
				Sonicteam::Player::State::ICommonContext* contxt = dynamic_cast<Sonicteam::Player::State::ICommonContext*>(machine->GetMashineContext().get());
				s_pos.AnimFL = contxt->AnimationState;
				s_pos.AnimID = contxt->CurrentAnimation;

				SocketMessage msg =  DEFINE_MESSAGE_FROM_DATA_CONST(s_pos);
				_socket.SendMessageToClients(&msg);
			}


	

		}
	}




	if (ATG::GAMEPAD* gc = ATG::Input::GetMergedInput()) {


		if (gc->wLastButtons & XINPUT_GAMEPAD_BACK) {
				trigger_menu += a2;
	
		}
	

		if (trigger_menu > 1.0f){
			trigger_menu = 0;





			LPCWSTR g_pwstrButtonsX[3] = { L"Host Server",L"Join Server",L"Disable Socket" };
			MESSAGEBOX_RESULT result;
			XOVERLAPPED m_Overlapped; 
			XShowMessageBoxUI(0,L"Server",L"Menu",3,g_pwstrButtonsX,3,XMB_ALERTICON,&result,&m_Overlapped);

			while (!( XHasOverlappedIoCompleted( &m_Overlapped ) )){				}

			if (result.dwButtonPressed == 1){

				ClearSocketConInfo();
	
				_socket.InitSocket();
				_socket.SetSocketBind(Socket::IP_ADDR, 27016, AF_INET);
				_socket.SetSocketNonBlocking();
				_socket.StartClient();
				_socket.MSG_HANDLE_SERVER_CLIENT_JOIN = ServerClientConnected;
				_socket.MSG_HANDLE_CLIENT_MESSAGES = ClientMessages;
		


				LocalPlayer = GetLocalPlayer();

				SocketBuff buff;
				SocketExtra extra;
				buff.address = _socket.GetAddressF();
				extra.local = true;
				extra.Player = LocalPlayer;
				extra.chr_lua = players_chr_remap[GetLocalPKGPlayerName()];
				XUID xuid;
				XUserGetXUID(0,&xuid);

				Players[xuid] = extra;



			}
			else if (result.dwButtonPressed == 0){

				ClearSocketConInfo();
				_socket.InitSocket();
				_socket.SetSocketBind(Socket::IP_ADDR, 27016, AF_INET);
				_socket.SetSocketNonBlocking();
				_socket.StartServer();
				_socket.MSG_HANDLE_SERVER_CLIENT_JOIN = ServerClientConnected;
				_socket.MSG_HANDLE_SERVER_MESSAGES = ServerMessages;
				_socket.MSG_HANDLE_SERVER_CLIENT_LOST_CONNECTION = ServerClientLost;

				LocalPlayer = GetLocalPlayer();
			
				SocketBuff buff;
				SocketExtra extra;
				extra.Player = LocalPlayer;
				extra.local = true;
				extra.chr_lua = players_chr_remap[GetLocalPKGPlayerName()];

				XUID xuid;
				XUserGetXUID(0,&xuid);
		
		
	
				Players[xuid] = extra;

			}
			else {
				ClearSocketConInfo();
			}




		}

	

	


	}
	return BranchTo(0x825EA610, int, a1, a2);
}

int RemoveCHR(int a1,int a2){

	for (std::map<XUID,SocketExtra>::iterator it = Players.begin();it != Players.end();it++){
		if (it->second.Player == a1){
			Players.erase(it);
		}
	}
	if (a1 == LocalPlayer){
		LocalPlayer = 0;
	}



	return BranchTo(0x82195298,int,a1,a2);

}



void TagBattleMain::GlobalInstall_ONLINE()
{

	players_chr_remap["player/sonic_new"] = "sonic_new.lua";
	players_chr_remap["player/shadow"] = "shadow.lua";
	players_chr_remap["player/silver"] = "silver.lua";

	players_chr_remap["player/tails"] = "tails.lua";
	players_chr_remap["player/knuckles"] = "knuckles.lua";
	players_chr_remap["player/amy"] = "amy.lua";

	players_chr_remap["player/rouge"] = "rouge.lua";
	players_chr_remap["player/omega"] = "omega.lua";


	players_chr_remap["player/blaze"] = "blaze.lua";
	players_chr_remap["player/princess"] = "princess.lua";


	players_chr_remap["player/sonic_fast"] = "sonic_fast.lua";
	players_chr_remap["player/princess"] = "princess.lua";



	WRITE_DWORD(0x82003568,RemoveCHR);
	WRITE_DWORD(0x82209E90 ,0x4E800020);
	WRITE_DWORD(0x8220BEF8 ,0x4E800020);

	WRITE_DWORD(0x82000950,EngineDocOnUpdateHE);

	
	

}
