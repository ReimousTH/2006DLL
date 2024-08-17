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

struct SMDATA_PPL_CHANGE_SCENE {
	DEFINE_SOCKET_MESSAGE_DATA_ID_PROTOCOL(1, IPPROTO_TCP);
	XUID sender_xuid;
	char scene_name[128];
};
struct SMDATA_PPL_CHANGE_SCENE_REPLICATE {
	DEFINE_SOCKET_MESSAGE_DATA_ID_PROTOCOL(2, IPPROTO_TCP);
	XUID sender_xuid;
	char scene_name[128];
};

struct SMDATA_PPL_CHANGE_TRANSFORM {
	DEFINE_SOCKET_MESSAGE_DATA_ID_PROTOCOL(3, IPPROTO_UDP);
	XMMATRIX Transform;
	XMVECTOR Position;
	XUID sender_xuid;
};

struct SMDATA_PPL_CHANGE_TRANSFORM_REPLICATE {
	DEFINE_SOCKET_MESSAGE_DATA_ID_PROTOCOL(4, IPPROTO_UDP);
	XMMATRIX Transform;
	XMVECTOR Position;
	XUID sender_xuid;
};


struct SMDATA_PPL_CHANGE_ANIMATION {
	DEFINE_SOCKET_MESSAGE_DATA_ID_PROTOCOL(5, IPPROTO_UDP);
	int AnimationID;
	int AnimationState;
	XUID sender_xuid;
};

struct SMDATA_PPL_CHANGE_ANIMATION_REPLICATE {
	DEFINE_SOCKET_MESSAGE_DATA_ID_PROTOCOL(6, IPPROTO_UDP);
	int AnimationID;
	int AnimationState;
	XUID sender_xuid;
};

struct SMDATA_PPL_CHANGE_RINGS {
	DEFINE_SOCKET_MESSAGE_DATA_ID_PROTOCOL(7, IPPROTO_UDP);
	int RingsCount;
	XUID sender_xuid;
};

struct SMDATA_PPL_CHANGE_RINGS_REPLICATE {
	DEFINE_SOCKET_MESSAGE_DATA_ID_PROTOCOL(8, IPPROTO_UDP);
	int RingsCount;
	XUID sender_xuid;
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
bool GameIMP_LOADED_SCENE = false;

struct PPL_DATA{
	XMVECTOR Position_FRAME;
	XMMATRIX RFTransformMatrix0x70_FRAME;

	int Context_Animation_ID;
	int Context_Animation_STATE;
	unsigned int RingsCount;
	bool local;

	Sonicteam::CsdObject* CSD;
	Sonicteam::SoX::RefCountObject* CSD_SHADER;
	Sonicteam::SoX::RefCountObject* TechniqueCSD3D;
	Sonicteam::SoX::RefCountObject* CsdObjectDrawable;

	std::string scene;
	int object_player;
	PPL_DATA(){
		memset(this,0,sizeof(PPL_DATA));
		scene = "";
		object_player = 0;
		
	}

	

};

std::map<XUID,PPL_DATA> Players_DATA;


// Define your structures




static int GetLocalPlayer(){
	Sonicteam::DocMarathonImp* impl = 	*(Sonicteam::DocMarathonImp**)(*(UINT32*)0x82D3B348 + 0x180);
	UINT32 gameimp = *(UINT32*)(impl->DocCurrentMode + 0x6C);

	if (gameimp == 0 || *(UINT32*)gameimp != 0x82001AEC) return 0;


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
	data.player_index = 1;
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

void MSG_HANDLE_SERVER_XUI_JOIN(Socket* _sock, SOCKET sock, XUID xuid){


	PPL_DATA data = PPL_DATA();
	data.scene = "";
	Players_DATA[xuid] = data;
	std::stringstream stream; stream << "[Server] ADD XUID " << std::hex << xuid;
	DebugLogV2::PrintNextFixed(stream.str());
}


void MSG_HANDLE_CLIENT_XUI_JOIN(Socket* _sock, SOCKET sock, XUID xuid){
	
	PPL_DATA data = PPL_DATA();
	data.scene = "";
	Players_DATA[xuid] = data;
	std::stringstream stream; stream << "[Client] ADD XUID " << std::hex << xuid;
	DebugLogV2::PrintNextFixed(stream.str());
}

//TRY SPAWN ONLY WHEN LEVEL LOADED, AND THEN SAVE FOR LATER
void DestroyObjectPlayerByXUID(XUID xuid){

//	DebugLogV2::PrintNextFixed("DestroyObjectPlayerByXUID");
	if (GameIMP_LOADED_SCENE == false) return;
	Sonicteam::DocMarathonImp* impl = 	*(Sonicteam::DocMarathonImp**)(*(UINT32*)0x82D3B348 + 0x180);
	UINT32 gameimp = *(UINT32*)(impl->DocCurrentMode + 0x6C);
	if (gameimp != 0 && *(UINT32*)gameimp == 0x82001AEC && Players_DATA[xuid].object_player != 0){
		BranchTo(0x82195298,int,Players_DATA[xuid].object_player,1);
		Players_DATA[xuid].object_player = 0;
	}
}
void SpawnObjectPlayerByXUID(XUID xuid){

//	DebugLogV2::PrintNextFixed("SpawnObjectPlayerByXUID");
	if (GameIMP_LOADED_SCENE == false) return;
	Sonicteam::DocMarathonImp* impl = 	*(Sonicteam::DocMarathonImp**)(*(UINT32*)0x82D3B348 + 0x180);
	UINT32 gameimp = *(UINT32*)(impl->DocCurrentMode + 0x6C);
	if (gameimp != 0 && *(UINT32*)gameimp != 0x82001AEC ) return;

	if ( Players_DATA[xuid].object_player == 0){
		Players_DATA[xuid].object_player = SpawnDummyCharacter();
	}
	else{
		BranchTo(0x82195298,int,Players_DATA[xuid].object_player,1);
		Players_DATA[xuid].object_player = SpawnDummyCharacter();
	}

}

void DestroyLabelByXUID(XUID xuid){

	
	if (GameIMP_LOADED_SCENE == false) return;
	Sonicteam::DocMarathonImp* impl = 	*(Sonicteam::DocMarathonImp**)(*(UINT32*)0x82D3B348 + 0x180);
	boost::shared_ptr<unsigned int> GraphicBufferGuess =  (impl->DocDoculistAction01(7));
	if (GraphicBufferGuess.get()){

		// Use find to get an iterator to the element
		std::map<XUID,PPL_DATA>::iterator it = Players_DATA.find(xuid);
		PPL_DATA* d = &it->second; // Pointer to the PPL_DATA object
		

		if (d->CsdObjectDrawable) {d->CsdObjectDrawable->DestroyObject(1); d->CsdObjectDrawable = 0;}
		if (d->CSD) {d->CSD->DestroyObject(1); d->CSD = 0;}
		if (d->TechniqueCSD3D){d->TechniqueCSD3D->DestroyObject(1);d->TechniqueCSD3D = 0;}
		if (d->CSD_SHADER){d->CSD_SHADER->DestroyObject(1);d->CSD_SHADER = 0;}

	}

}
void SpawnPlayerLabelByXUID(XUID xuid){

	
	if (GameIMP_LOADED_SCENE == false) return;

	Sonicteam::DocMarathonImp* impl = 	*(Sonicteam::DocMarathonImp**)(*(UINT32*)0x82D3B348 + 0x180);
	boost::shared_ptr<unsigned int> GraphicBufferGuess =  (impl->DocDoculistAction01(7));
	if (GraphicBufferGuess.get()){


	// Use find to get an iterator to the element
	std::map<XUID,PPL_DATA>::iterator it = Players_DATA.find(xuid);
	PPL_DATA* d = &it->second; // Pointer to the PPL_DATA object
	if (d->CSD != 0 ) return;

   
	BranchTo(0x82371620,int,&d->CSD_SHADER,&std::string("shader/primitive/csd3D.fx"));

	int v18 = (int)d->CSD_SHADER;
	(int *)(*(int (__fastcall **)(int *, int, int))(*(_DWORD *)v18 + 0x18))((int*)&d->TechniqueCSD3D, (int)d->CSD_SHADER, (int)"TechniqueCSD3D");
	Players_DATA[xuid].TechniqueCSD3D->GetObject<int>();



	BranchTo(0x82617570,int,&d->CSD,&std::string("sprite/enemy_powergage/enemy_powergage"));

	
	d->CSD->GetObject<int>();
	d->CsdObjectDrawable =  (Sonicteam::SoX::RefCountObject*)BranchTo(0x82616C68,int,malloc06(0xA0),impl->DocGetMyGraphicDevice(),&d->CSD);

	d->CsdObjectDrawable->GetObject<int>();
	BranchTo(0x82616EB0,int,d->CsdObjectDrawable,&Players_DATA[xuid].TechniqueCSD3D);


	
	
	(*(void (__fastcall **)(_DWORD, int *))(*GraphicBufferGuess + 0x14))((_DWORD)GraphicBufferGuess.get(), (int*)&d->CsdObjectDrawable);
	Players_DATA[xuid].CSD->MarathonPlaySceneAnimation("enemy_powergage","DefaultAnim");
	int CsdObjectDrawable_INT = (int)d->CsdObjectDrawable;
	int CsdObject_INT = (int)d->CSD;
	*(_BYTE *)(CsdObjectDrawable_INT + 0x74) = 1;
	*(XMVECTOR *)(CsdObjectDrawable_INT + 0x80) = XMVectorZero();
	Players_DATA[xuid].CSD->SetFlag0x20(0x401); //SetRenderFlag


	std::string test =  _socket.XUIDToName(xuid);
	DebugLogV2::PrintNextFixed(test);

	//Back when i map all font data >:)
	//d->CSD->MarathonSetSceneNodeText("enemy_powergage","Cast",_socket.XUIDToName(xuid).c_str());
	
}

	

}



// Function to handle client messages
static void ClientMessages(Socket* socket, SOCKET client_socket, SocketMessage* message) {
	
	if (message->ID == SMDATA_PPL_CHANGE_SCENE::GetID() || message->ID == SMDATA_PPL_CHANGE_SCENE_REPLICATE::GetID()){
		SMDATA_PPL_CHANGE_SCENE* _data_ = EXTRACT_SOCKET_MESSAGE_FROM_MESSAGE_PTR(message, SMDATA_PPL_CHANGE_SCENE)
		if (_data_->sender_xuid == socket->GetXUID(0)) return;
		if (Players_DATA.find(_data_->sender_xuid) == Players_DATA.end()) return;


		Players_DATA[_data_->sender_xuid].scene = _data_->scene_name;

		
		if (Players_DATA[_data_->sender_xuid].scene == ""){
			DestroyObjectPlayerByXUID(_data_->sender_xuid);
			DestroyLabelByXUID(_data_->sender_xuid);
		}
		else{
			SpawnObjectPlayerByXUID(_data_->sender_xuid);
			SpawnPlayerLabelByXUID(_data_->sender_xuid);
		}
		


		std::stringstream stream; stream << "[Client] XUID :  " << std::hex << _data_->sender_xuid << " goto " << _data_->scene_name;
		DebugLogV2::PrintNextFixed(stream.str());

	}

	if (message->ID == SMDATA_PPL_CHANGE_TRANSFORM::GetID() || message->ID == SMDATA_PPL_CHANGE_TRANSFORM_REPLICATE::GetID()){
		SMDATA_PPL_CHANGE_TRANSFORM* _data_ = EXTRACT_SOCKET_MESSAGE_FROM_MESSAGE_PTR(message, SMDATA_PPL_CHANGE_TRANSFORM);
		if (_data_->sender_xuid == socket->GetXUID(0)) return;


	//	std::stringstream ss; ss << "SMDATA_PPL_CHANGE_TRANSFORM X : "  << _data_->Position.x << " Y:" << _data_->Position.y << " Z:" <<  _data_->Position.z; 
	//	DebugLogV2::PrintNextFixed(ss.str());
		Players_DATA[_data_->sender_xuid].RFTransformMatrix0x70_FRAME = _data_->Transform;
		Players_DATA[_data_->sender_xuid].Position_FRAME = _data_->Position;
	}

	if (message->ID == SMDATA_PPL_CHANGE_ANIMATION::GetID() || message->ID == SMDATA_PPL_CHANGE_ANIMATION_REPLICATE::GetID()){
		SMDATA_PPL_CHANGE_ANIMATION* _data_ = EXTRACT_SOCKET_MESSAGE_FROM_MESSAGE_PTR(message, SMDATA_PPL_CHANGE_ANIMATION);
		if (_data_->sender_xuid == socket->GetXUID(0)) return;


//		std::stringstream hero; hero << _data_->AnimationID << "-" << _data_->AnimationState;
//		DebugLogV2::PrintNextFixed(hero.str());

		Players_DATA[_data_->sender_xuid].Context_Animation_ID = _data_->AnimationID;
		Players_DATA[_data_->sender_xuid].Context_Animation_STATE = _data_->AnimationState;
	}

	if (message->ID == SMDATA_PPL_CHANGE_RINGS::GetID() || message->ID == SMDATA_PPL_CHANGE_RINGS_REPLICATE::GetID()){
		SMDATA_PPL_CHANGE_RINGS* _data_ = EXTRACT_SOCKET_MESSAGE_FROM_MESSAGE_PTR(message, SMDATA_PPL_CHANGE_RINGS);
		if (_data_->sender_xuid == socket->GetXUID(0)) return;


		//	std::stringstream ss; ss << "SMDATA_PPL_CHANGE_TRANSFORM X : "  << _data_->Position.x << " Y:" << _data_->Position.y << " Z:" <<  _data_->Position.z; 
		//	DebugLogV2::PrintNextFixed(ss.str());
		Players_DATA[_data_->sender_xuid].RingsCount = _data_->RingsCount;
		std::stringstream ss; ss << _data_->RingsCount;

		if (Players_DATA[_data_->sender_xuid].CSD){
			Players_DATA[_data_->sender_xuid].CSD->MarathonSetSceneNodeText("enemy_powergage","RingCastTex",ss.str().c_str());
		}
		
	
	}

	








}

// Function to handle server messages
static void ServerMessages(Socket* socket, SOCKET client_socket, SocketMessage* message) {

	bool replicate = false;
	if (message->ID == SMDATA_PPL_CHANGE_SCENE::GetID()){
		SMDATA_PPL_CHANGE_SCENE* _data_ = EXTRACT_SOCKET_MESSAGE_FROM_MESSAGE_PTR(message, SMDATA_PPL_CHANGE_SCENE);
		if (_data_->sender_xuid == socket->GetXUID(0)) return;
		if (Players_DATA.find(_data_->sender_xuid) == Players_DATA.end()) return;



		Players_DATA[_data_->sender_xuid].scene = _data_->scene_name;

		if (Players_DATA[_data_->sender_xuid].scene == ""){
			DestroyObjectPlayerByXUID(_data_->sender_xuid);
			DestroyLabelByXUID(_data_->sender_xuid);
		}
		else{
			SpawnObjectPlayerByXUID(_data_->sender_xuid);
			SpawnPlayerLabelByXUID(_data_->sender_xuid);
		}



		std::stringstream stream; stream << "[Server] XUID :  " << std::hex << _data_->sender_xuid << " goto " << _data_->scene_name;
		DebugLogV2::PrintNextFixed(stream.str());
		replicate = true;
	}

	//Send Cross Over
	if (replicate){

		for (std::map<XUID,PPL_DATA>::iterator it = Players_DATA.begin();it != Players_DATA.end();it++){
			
			SMDATA_PPL_CHANGE_SCENE_REPLICATE _data_;
			_data_.sender_xuid = it->first;
			memcpy(&_data_.scene_name,it->second.scene.c_str(),it->second.scene.length()+1);
			SocketMessage msg  =  DEFINE_SOCKET_MESSAGE_FROM_CONST_DATA(_data_);
			socket->SendTCPMessageToClients(&msg);

		}
	}

	bool replicate_transform = false;
	if (message->ID == SMDATA_PPL_CHANGE_TRANSFORM::GetID()){
		SMDATA_PPL_CHANGE_TRANSFORM* _data_ = EXTRACT_SOCKET_MESSAGE_FROM_MESSAGE_PTR(message, SMDATA_PPL_CHANGE_TRANSFORM);
		if (_data_->sender_xuid == socket->GetXUID(0)) return;

		replicate_transform = true;
	//	std::stringstream ss; ss << "SMDATA_PPL_CHANGE_TRANSFORM X : "  << _data_->Position.x << " Y:" << _data_->Position.y << " Z:" <<  _data_->Position.z; 
	//	DebugLogV2::PrintNextFixed(ss.str());
		Players_DATA[_data_->sender_xuid].RFTransformMatrix0x70_FRAME = _data_->Transform;
		Players_DATA[_data_->sender_xuid].Position_FRAME = _data_->Position;
	}

	if (replicate_transform){

		for (std::map<XUID, PPL_DATA>::iterator it = Players_DATA.begin(); it != Players_DATA.end(); ++it) {
			SMDATA_PPL_CHANGE_TRANSFORM_REPLICATE _data_;
			_data_.sender_xuid = it->first; // Get the XUID
			_data_.Position = it->second.Position_FRAME; // Get the position
			_data_.Transform = it->second.RFTransformMatrix0x70_FRAME; // Get the transform matrix


			//	std::stringstream ss; ss << "SMDATA_PPL_CHANGE_TRANSFORM X : "  << _data_->Position.x << " Y:" << _data_->Position.y << " Z:" <<  _data_->Position.z; 
			//	DebugLogV2::PrintNextFixed(ss.str());

			SocketMessage msg = DEFINE_SOCKET_MESSAGE_FROM_CONST_DATA(_data_);

			// Uncomment the line below to send the message
			socket->SendUDPMessageToClients(&msg); // Ensure socket is defined and initialized

		}

	}
	bool replicate_anim = false;

	if (message->ID == SMDATA_PPL_CHANGE_ANIMATION::GetID()){
		SMDATA_PPL_CHANGE_ANIMATION* _data_ = EXTRACT_SOCKET_MESSAGE_FROM_MESSAGE_PTR(message, SMDATA_PPL_CHANGE_ANIMATION);
		if (_data_->sender_xuid == socket->GetXUID(0)) return;
		replicate_anim = true;
	
	//	 std::stringstream hero; hero << _data_->AnimationID << "-" << _data_->AnimationState;
	//	DebugLogV2::PrintNextFixed(hero.str());

		Players_DATA[_data_->sender_xuid].Context_Animation_ID = _data_->AnimationID;
		Players_DATA[_data_->sender_xuid].Context_Animation_STATE = _data_->AnimationState;
	}
	if (replicate_anim){

		for (std::map<XUID,PPL_DATA>::iterator it = Players_DATA.begin();it != Players_DATA.end();it++){

			SMDATA_PPL_CHANGE_ANIMATION_REPLICATE _data_;
			_data_.sender_xuid = it->first;
			_data_.AnimationID = it->second.Context_Animation_ID;
			_data_.AnimationState = it->second.Context_Animation_STATE;
			SocketMessage msg  =  DEFINE_SOCKET_MESSAGE_FROM_CONST_DATA(_data_);
			socket->SendUDPMessageToClients(&msg);

		}

	}


	bool replicate_rings = false;

	if (message->ID == SMDATA_PPL_CHANGE_RINGS::GetID()){
		SMDATA_PPL_CHANGE_RINGS* _data_ = EXTRACT_SOCKET_MESSAGE_FROM_MESSAGE_PTR(message, SMDATA_PPL_CHANGE_RINGS);
		if (_data_->sender_xuid == socket->GetXUID(0)) return;
		replicate_rings = true;
		Players_DATA[_data_->sender_xuid].RingsCount = _data_->RingsCount;

		std::stringstream ss; ss << _data_->RingsCount;
		if (Players_DATA[_data_->sender_xuid].CSD){
			Players_DATA[_data_->sender_xuid].CSD->MarathonSetSceneNodeText("enemy_powergage","RingCastTex",ss.str().c_str());
		}


	}
	if (replicate_rings){

		for (std::map<XUID,PPL_DATA>::iterator it = Players_DATA.begin();it != Players_DATA.end();it++){

			SMDATA_PPL_CHANGE_RINGS_REPLICATE _data_;
			_data_.sender_xuid = it->first;
			_data_.RingsCount = it->second.RingsCount;
			SocketMessage msg  =  DEFINE_SOCKET_MESSAGE_FROM_CONST_DATA(_data_);
			socket->SendUDPMessageToClients(&msg);

		}

	}





}
// Function to handle a new client connection
static void ServerClientConnected(Socket* socket, SOCKET client_socket) {
 
	
}
static void ServerClientLost(Socket* socket, SOCKET client_socket) {

}
float trigger_menu = 0.0f;



extern "C" int EngineDocOnUpdateHE(Sonicteam::DocMarathonImp* a1, double a2) {


	for (std::map<XUID,PPL_DATA>::iterator it = Players_DATA.begin();it != Players_DATA.end();it++){

		if (it->first == _socket.GetXUID(0)) continue;

	
		PPL_DATA* data =  &it->second;
		if (data->CSD){
			data->CSD->CsdLink0x8(a2);

		}
		if (Sonicteam::SoX::RefCountObject* drawable =  data->CsdObjectDrawable){

		//	std::stringstream cantjust; cantjust <<  "XUID : " << it->first << std::hex << " X : " << data->Position_FRAME.x << " Y : " << data->Position_FRAME.y << " Z : " << data->Position_FRAME.z;
		//	DebugLogV2::PrintNextFixed(cantjust.str());
			int CsdObjectDrawable_INT = (int)data->CsdObjectDrawable;
			*(_BYTE *)(CsdObjectDrawable_INT + 0x74) = 1;
			*(XMVECTOR *)(CsdObjectDrawable_INT + 0x80) = data->Position_FRAME + XMVectorSet(0,140,0,0);
		
		}
		
	}

	

	if (_socket.IsClient()){

		if (_socket.GetConnectStatus() != 1) {
			_socket.InitClient();
		}
		else if (_socket.GetConnectStatus() == 1) {
			if (_socket.IsWorks()) _socket.UpdateClient(1.0);
		}
			
	}
	else if (_socket.IsServer()){
	//		DebugLogV2::PrintNextFixed("SERVER");
		_socket.UpdateServer(1.0);
	}

	if (LocalPlayer){
		if (_socket.IsClient()){
		
		}
		else if (_socket.IsServer()){
		
	
		}
	}




	if (ATG::GAMEPAD* gc = ATG::Input::GetMergedInput()) {


		if (gc->wLastButtons & XINPUT_GAMEPAD_BACK) {
				trigger_menu += a2;
	
		}
	

		if (trigger_menu > 1.0f){
			trigger_menu = 0;





			LPCWSTR g_pwstrButtonsX[4] = { L"Host Server",L"Join Server",L"Disable Socket",L"Test" };
			MESSAGEBOX_RESULT result;
			XOVERLAPPED m_Overlapped; 
			XShowMessageBoxUI(0,L"Server",L"Menu",4,g_pwstrButtonsX,4,XMB_ALERTICON,&result,&m_Overlapped);

			while (!( XHasOverlappedIoCompleted( &m_Overlapped ) )){				}

			if (result.dwButtonPressed == 1){

				_socket = Socket();
				
	
				_socket.InitSockets();
				_socket.SetAddress("26.175.28.206", 27017);
				_socket.SetBind();
				_socket.SetNonBlockingMode();
				_socket.SetAddress("26.175.28.206", 27016);
				_socket.InitClient();
			//	_socket.MSG_HANDLE_CLIENT_JOIN_SERVER = ServerClientConnected;
				_socket.MSG_HANDLE_CLIENT_MESSAGES = ClientMessages;
				_socket.MSG_HANDLE_CLIENT_XUI_JOIN = MSG_HANDLE_CLIENT_XUI_JOIN;

			

			
		


			


			}
			else if (result.dwButtonPressed == 0){

		
				_socket = Socket();

				_socket.InitSockets();
				_socket.SetAddress("26.175.28.206", 27016); 
				_socket.SetBind();
				_socket.SetNonBlockingMode();
				_socket.InitServer();
				_socket.MSG_HANDLE_SERVER_CLIENT_JOIN = ServerClientConnected;
				_socket.MSG_HANDLE_SERVER_MESSAGES = ServerMessages;
				_socket.MSG_HANDLE_SERVER_CLIENT_LOST_CONNECTION = ServerClientLost;
				_socket.MSG_HANDLE_SERVER_XUI_JOIN = MSG_HANDLE_SERVER_XUI_JOIN;

				PPL_DATA data =   PPL_DATA();
				data.local = true;
				Players_DATA[_socket.GetXUID(0)] =data; 

			//	SpawnPlayerLabelByXUID(_socket.GetXUID(0));



				
			
				
		
	
	

			}
			else if (result.dwButtonPressed == 3){

				
			//	SpawnPlayerLabelByXUID(_socket.GetXUID(0));

	
				 
			

				DebugLogV2::PrintNextFixed("SpawnLabel");

			}
			else {
				
			}




		}

	

	


	}
	return BranchTo(0x825EA610, int, a1, a2);
}

int RemoveCHR(int a1,int a2){

	if (a2 == 1){
		for (std::map<XUID,PPL_DATA>::iterator it = Players_DATA.begin();it != Players_DATA.end();it++){
			if (it->second.object_player == a1){
				
				if (it->second.object_player == 0){
					return 0;
				}
				else{
					it->second.object_player = 0;
				}
				
				

				break;
			}
		}

	}


	
	return BranchTo(0x82195298,int,a1,a2);

}
int __fastcall sub_8229A5D0(int a1, double a2){

	int v4; // r30
	double v6; // fp13
	float *v7; // r11
	int v12; // r3
	__int64 *v20; // r3
	__int64 *v29; // r30
	__int64 *v30; // r3
	int *v31; // r3
	int v32; // r5
	int result; // r3
	_DWORD *v34; // r3
	int v35; // r29
	__int64 *v36; // r30
	int *v37; // r3
	__int64 *v38; // r3
	int v39; // r30
	_DWORD *v40; // r3
	Sonicteam::SoX::RefCountObject* v41; // [sp+50h] [-230h] BYREF
	float v42; // [sp+54h] [-22Ch] BYREF
	int v43; // [sp+58h] [-228h] BYREF
	int v44; // [sp+5Ch] [-224h] BYREF
	int v45; // [sp+60h] [-220h] BYREF
	float v46; // [sp+64h] [-21Ch] BYREF
	float v47[4]; // [sp+70h] [-210h] BYREF
	char v48[16]; // [sp+80h] [-200h] BYREF
	char v49[4]; // [sp+90h] [-1F0h] BYREF
	int v50; // [sp+94h] [-1ECh]
	char v51[16]; // [sp+A0h] [-1E0h] BYREF
	int v52[4]; // [sp+B0h] [-1D0h] BYREF
	char v53; // [sp+C0h] [-1C0h] BYREF
	char v54[16]; // [sp+D0h] [-1B0h] BYREF
	char v55[16]; // [sp+E0h] [-1A0h] BYREF
	char v56[16]; // [sp+F0h] [-190h] BYREF
	char v57[16]; // [sp+100h] [-180h] BYREF
	char v58[16]; // [sp+110h] [-170h] BYREF
	char v59[16]; // [sp+120h] [-160h] BYREF
	char v60[64]; // [sp+130h] [-150h] BYREF
	char v61[64]; // [sp+170h] [-110h] BYREF
	char v62[64]; // [sp+1B0h] [-D0h] BYREF
	char v63[72]; // [sp+1F0h] [-90h] BYREF


	/*

	if ( (*(_DWORD *)(a1 + 0x184) & 1) != 0  && _socket.IsWorks())     // Touch Ring
	{
		v34 = (_DWORD *)BranchTo(0x823D0E88,int,(int)v49, a1);
		v35 = (*(int (__fastcall **)(_DWORD))(*(_DWORD *)*v34 + 0xC))(*v34);
		if ( v50 )
			sub_821601B8(v50);

		BranchTo(0x825D2350,int,v57,0x82B39EE0)

		v36 = (__int64 *)((int)v63, (int)v57);
		v37 = BranchTo(0x82277768,int*,&v41, a1);
		v38 = (__int64 *)BranchTo(0x82594160,int,(int)v60, (_DWORD *)*v37);
		BranchTo(0x82168C48,int,(int)v62, v38, v36);
		if ( v41 )
			v41->LoseObject();
		v39 = *(_DWORD *)(a1 + 0x180);
		v40 = (_DWORD *)(*(int (__fastcall **)(int))(*(_DWORD *)v35 + 0x24))(v35);
		sub_825FE5B0(&v43, v40, *(_DWORD *)(v39 + 0x3C), (int)v62);
		if ( v43 )
			sub_82631328(v43);
		sub_822791E8(&v45, a1, *(_DWORD *)(*(_DWORD *)(a1 + 0x180) + 0x38));
		if ( v45 )
			RefCountObjectRemoveReference(v45);
		sub_825813A0(a1);
		result = sub_8227CB18(a1);
	}
	else{
		BranchTo(0x8229A5D0 ,int,a1,a2);
	}
	*/
	return 0;
	
}

int __fastcall MainModeOnMessageRecieved(Sonicteam::SoX::MessageReceiver* _this,Sonicteam::SoX::Message* msg){


	int a1 = (int)_this;
	a1 = a1 -0x20;
	int extra_flag = *(int *)(a1 + 0x50) ;

	switch ( msg->MessageInfo )
	{
	case 0x1C001:
		std::stringstream ss;
		ss << "[MainMode][MessageReceiver]0x1C001-" << extra_flag;
		DebugLogV2::PrintNextFixed(ss.str());
		break;
	}



	return BranchTo(0x824A6758 ,int,_this,msg);
}


int __fastcall GameImpOnMessageRecieved(Sonicteam::SoX::MessageReceiver* _this,Sonicteam::SoX::Message* msg){


	int a1 = (int)_this;
	int extra_flag = *(int *)(a1 + 0x50) ;

	std::stringstream ss;
	ss << "[MainMode][MessageReceiver]" << msg->MessageInfo << "-" << msg->MessageInfo2;
	DebugLogV2::PrintNextFixed(ss.str());

	switch ( msg->MessageInfo )
	{
	case 0x1C001:

		break;
	}



	return BranchTo(0x8217BB68 ,int,_this,msg);
}

int __fastcall GameImpEngGlobalActionsRecieved(int a1,double a2){

	//0x1214 -stage/aqa/a
	//0x15B8 -stage/aqa/a
	//0x1564 - SCENE NAME GETTINGS ERASED MB?

	int case1 = *(int*)(a1 + 0x4);
	int case2 = *(int*)(a1 + 0x8);

	bool first_load = false;


	if (case1 != case2){
		std::stringstream ss;
		ss << "[GameIMP][X][GlobalActions]" << case1 << "-" << case2;
		DebugLogV2::PrintNextFixed(ss.str());
	}

	
	if (case1 != case2){
		if (case2 == 1){
			GameIMP_LOADED_SCENE = false;
			std::stringstream ss;
			ss << "[GameIMP][FirstLevelLoad]" << case1 << "-" << case2 << "-";
			DebugLogV2::PrintNextFixed(ss.str());
		}
		if (case2 == 2){

			GameIMP_LOADED_SCENE = false;
			std::stringstream ss;
			ss << "[GameIMP][StartCutScene]" << case1 << "-" << case2 << "-"; // 82185528   (AFTER END CUTSCENE HERE SECRETLY DOES)
			DebugLogV2::PrintNextFixed(ss.str());
			
		}
		if (case2 == 3){
			GameIMP_LOADED_SCENE = false;
			std::stringstream ss;
			ss << "[GameIMP][StartCutScene-Rendered]" << case1 << "-" << case2 << "-";
			DebugLogV2::PrintNextFixed(ss.str());
		}
		if (case2 ==5 ){
			GameIMP_LOADED_SCENE = false;
			std::stringstream ss;
			ss << "[GameIMP][EndCutScene]" << case1 << "-" << case2 << "-";
			DebugLogV2::PrintNextFixed(ss.str());
		}
		if (case2 == 9){


			for (std::map<XUID,PPL_DATA>::iterator it =		Players_DATA.begin();it !=Players_DATA.end();it++){
				if (it->first == _socket.GetXUID(0)) continue;
				if (it->second.scene == "") continue;
				if (it->second.local == true) continue;
			//	DestroyObjectPlayerByXUID(it->first);
			//	DestroyLabelByXUID(it->first);
			}

			GameIMP_LOADED_SCENE = false;
			std::stringstream ss;
			ss << "[GameIMP][Destory]" << case1 << "-" << case2 << "-";
			DebugLogV2::PrintNextFixed(ss.str());
		}



	}

	




	//Left (MISSION) or save 4-7
	// 7 - 5 
	// 5 - 9 //i guess destroyed

	//Town(form lvl)
	// 1 - 2  Start CutScene

	// 1 - 8 After OK 
	// 8 - 9 Destroy Me


	//Town(from menu)
	// 0 - 2 Start CutScene
	// 2 - 5 End Cutscene
	// 5 - 9 Destroy Me

	//Town(from menu)
	// 0 - 3 Start CutScene(Rendered)
	// 3 - 5 End Cutscene
	// 5 - 9 Destroy Me



	//1 - 8 Leave Normal





	int v7 =  *(int*)(a1 + 0x10);
	bool change_area = false;
	if ( ((v7 >> 8) & 1) == 0 )
	{
		if ( ((v7 >> 0x15) & 1) != 0 ) //TownChange
		{
			change_area = true;
			std::stringstream ss;
			ss << "[GameIMP][TownChange]" << case1 << "-" << case2;
			DebugLogV2::PrintNextFixed(ss.str());

		
		}
		if ( ((v7 >> 0x12) & 1) != 0 ) // ChangeArea Flag passes here 
		{
			change_area = true;
			std::stringstream ss;
			ss << "[GameIMP][ChangeArea]" << case1 << "-" << case2;
			DebugLogV2::PrintNextFixed(ss.str());
		
		}
	}

	INT RESULT =  BranchTo(0x82185D30 ,int,a1,a2);
	std::string* t01 = (std::string *)(a1 + 0x1214);


	bool action_send_level_info = false;
	bool action_not_respawn = false;

	if (case1 == 2){

		int v5 = (*(int (__fastcall **)(_DWORD, _DWORD))(**(_DWORD **)(a1 + 0xC) + 0x140))(*(_DWORD *)(a1 + 0xC), 0);
		int v7 =  BranchTo(0x825D3888,int,*(int*)0x82D36800,v5);

		if ( v7 )
		{
			if ( *(_DWORD *)(a1 + 0xC) )
			{
				if ( (*(_DWORD *)(v7 + 8) & 0x400) != 0 )
				{
					int v8 = (*(int (__fastcall **)(_DWORD))(**(_DWORD **)(a1 + 0xC) + 0x60))(*(_DWORD *)(a1 + 0xC));
					if ( v8 )
					{
						GameIMP_LOADED_SCENE = true;
						action_send_level_info = true;

						std::stringstream ss;
						ss << "[GameIMP][StartLoadBack]" << case1 << "-" << case2 << "-"; // 82185528   (AFTER END CUTSCENE HERE SECRETLY DOES)
						DebugLogV2::PrintNextFixed(ss.str());
					}
				}
			}
		}
	
	}






	if (case1 != case2){
		if (case2 == 1){
			GameIMP_LOADED_SCENE = true;
			std::stringstream ss;
			ss << "[GameIMP][FirstLevelLoad][Finish]" << case1 << "-" << case2 << "-";
			DebugLogV2::PrintNextFixed(ss.str());
			action_send_level_info = true;
		}
		if (case2 == 2){
			std::stringstream ss;
			ss << "[GameIMP][StartCutScene][Finish]" << case1 << "-" << case2 << "-";
			DebugLogV2::PrintNextFixed(ss.str());
		}
		if (case2 == 3){
			std::stringstream ss;
			ss << "[GameIMP][StartCutScene-Rendered][Finish]" << case1 << "-" << case2 << "-";
			DebugLogV2::PrintNextFixed(ss.str());
		}
		if (case2 ==5 ){
			std::stringstream ss;
			ss << "[GameIMP][EndCutScene][Finish]" << case1 << "-" << case2 << "-";
			DebugLogV2::PrintNextFixed(ss.str());
		}
		if (case2 == 9){
			std::stringstream ss;
			ss << "[GameIMP][Destory][Finish]" << case1 << "-" << case2 << "-";
			DebugLogV2::PrintNextFixed(ss.str());
			*t01 = "";
			action_send_level_info = true;
			action_not_respawn = true;



		}



	}

	if (action_send_level_info || change_area){
		GameIMP_LOADED_SCENE = true;
		std::stringstream ss;
	//	ss << "[GameIMP][Server-Client] Send : " << case1 << "-" << case2 << "-" << t01->c_str(); 
	//	DebugLogV2::PrintNextFixed(ss.str());

		const char* scene_nm = t01->c_str();

		if (_socket.IsClient() || _socket.IsServer()){

			//Send Client XUID to Host
			{
				SMDATA_PPL_CHANGE_SCENE _msg_data;
				_msg_data.sender_xuid = _socket.GetXUID(0);
				memcpy(&_msg_data.scene_name,scene_nm,strlen(scene_nm)+1);
				SocketMessage msg = DEFINE_SOCKET_MESSAGE_FROM_CONST_DATA(_msg_data);

				if (_socket.IsClient()){
					_socket.SendTCPMessageToServer(&msg);
				}
				else{
					Players_DATA[_socket.GetXUID(0)].scene = scene_nm;
					_socket.SendTCPMessageToClients(&msg);
				}

			}
			if (!action_not_respawn){
				for (std::map<XUID,PPL_DATA>::iterator it =		Players_DATA.begin();it !=Players_DATA.end();it++){
					if (it->first == _socket.GetXUID(0)) continue;
					if (it->second.scene == "") continue;
					if (it->second.local == true) continue;
					if (it->second.object_player == 0) SpawnObjectPlayerByXUID(it->first);
					if (it->second.CSD == 0) SpawnPlayerLabelByXUID(it->first);

				}
			}

		

		}


	}





	return RESULT;

}



int __fastcall GameIMP_DESTRUCTION(int a1, char a2){


	GameIMP_LOADED_SCENE = false;
	if (_socket.IsClient() || _socket.IsServer()){

		//Send Client XUID to Host
		{
			SMDATA_PPL_CHANGE_SCENE _msg_data;
			_msg_data.sender_xuid = _socket.GetXUID(0);
			memcpy(&_msg_data.scene_name,"",11);
			SocketMessage msg = DEFINE_SOCKET_MESSAGE_FROM_CONST_DATA(_msg_data);

			if (_socket.IsClient()){
				_socket.SendTCPMessageToServer(&msg);
			}
			else{
				Players_DATA[_socket.GetXUID(0)].scene = "";
				_socket.SendTCPMessageToClients(&msg);
			}


		}

		for (std::map<XUID,PPL_DATA>::iterator it =		Players_DATA.begin();it !=Players_DATA.end();it++){
			it->second.object_player  = 0;
			it->second.CSD = 0;

		}

	}


	return BranchTo(0x82180820,int,a1,a2);
}


int __fastcall ObjectUpdate(int a1, double a2){



	bool IsLocalPlayer = GetLocalPlayer() == a1;
	bool IsNetworkPlayer = false;
	PPL_DATA NetworkPlayer_DATA = PPL_DATA();


	if (_socket.IsWorks()){

		for (std::map<XUID,PPL_DATA>::iterator it = Players_DATA.begin();it != Players_DATA.end();it++){
			if (it->second.object_player == 0 ) continue;
			if (it->second.object_player != a1) continue;
			NetworkPlayer_DATA.Context_Animation_ID  = it->second.Context_Animation_ID;
			NetworkPlayer_DATA.Context_Animation_STATE  = it->second.Context_Animation_STATE;
			IsNetworkPlayer = true;
		//	std::stringstream bruhx;  bruhx << "BRUHHX"   << it->second.Context_Animation_ID << "-" << it->second.Context_Animation_STATE;
		//	DebugLogV2::PrintNextFixed(bruhx.str());

			if (Sonicteam::Player::RootFrame* PlayerFrame = *(Sonicteam::Player::RootFrame **)(it->second.object_player + 0xCC)){
				PlayerFrame->RFTransformMatrix0x70 = it->second.RFTransformMatrix0x70_FRAME;
				*(XMVECTOR*)((*(UINT32*)(it->second.object_player + 0xDC)) + 0xB0)  = it->second.Position_FRAME;
				
			//	std::stringstream bruh;  bruh << "XUID : " << "X : " << it->second.Position_FRAME.x << "Y : " << it->second.Position_FRAME.y << "Z : " << it->second.Position_FRAME.z;
			//	DebugLogV2::PrintNextFixed(bruh.str());



				
			}
		}
	}

	



	Sonicteam::SoX::Engine::Task* _this = (Sonicteam::SoX::Engine::Task*)a1;
	Sonicteam::DocMarathonImp* docmarathon =  (Sonicteam::DocMarathonImp*)_this->TaskEngineDoc;

	int CameraManPlayer =  BranchTo(0x82160658,int,a1, *(_DWORD *)(a1 + 0x90));

	int CameraManPlayer_MessageReceiver = CameraManPlayer + 0x20;
	if ( !CameraManPlayer ) CameraManPlayer_MessageReceiver = 0;
	 *(_DWORD *)(a1 + 0x94) = CameraManPlayer_MessageReceiver;// Store Camera O_O

	int LastSetupModuleIndex = *(_DWORD *)(a1 + 0x100);
	int NextSetupModuleIndex = *(_DWORD *)(a1 + 0xFC);

	 if ( NextSetupModuleIndex != LastSetupModuleIndex )
		 BranchTo(0x82195858,int,a1,docmarathon,LastSetupModuleIndex);

	 BranchTo(0x82197028,int,a1); //SuperFUNC

	 float PlayerSpeed_Delta = (float)(*(float *)(a1 + 0x17C) * (float)a2);// 0x180 - CameraYPos
	 int arg_buffer_3[3];
	 arg_buffer_3[2] = *(int*)&PlayerSpeed_Delta;
	 arg_buffer_3[1] = *(int*)&PlayerSpeed_Delta;
	 arg_buffer_3[0] = 0x82581EA8;


	 //Simplified Way
	 std::vector<boost::shared_ptr<Sonicteam::Player::IStepable>>* IStepableP1 = reinterpret_cast<std::vector<boost::shared_ptr<Sonicteam::Player::IStepable>>*>(a1 + 0x24C);  
	 for ( std::vector<boost::shared_ptr<Sonicteam::Player::IStepable>>::iterator it = IStepableP1->begin();it != IStepableP1->end();it++){
		Sonicteam::Player::IStepable*  boost_step = (*it).get();
		boost_step->OnStepable(PlayerSpeed_Delta);
	 }

	 BranchTo(0x82196C10,int,a1);
	 BranchTo(0x82196B98,int,a1);
	 BranchTo(0x821B7968,int,a1, a1 + 0x29C, 0);
	 BranchTo(0x82196AB8,int,a1);
	 BranchTo(0x82196F78,int,a1); //CheckAIFLAGS
	 BranchTo(0x82196850,int,a1); //UpgradeRunner(


//

	 if (IsNetworkPlayer){

		 Sonicteam::Player::State::ICommonContext* PlayerContext = *(Sonicteam::Player::State::ICommonContext**)((*(int*)(a1 + 0xE4)) + 0x50);
		 PlayerContext->AnimationState = NetworkPlayer_DATA.Context_Animation_STATE;
		 PlayerContext->CurrentAnimation = NetworkPlayer_DATA.Context_Animation_ID;
	 }

	 if (Sonicteam::Player::State::IMachine* PlayerMachine = *(Sonicteam::Player::State::IMachine**)(a1 + 0xE4)){
		 PlayerMachine->OnMashineTick(PlayerSpeed_Delta);
	 }

	 BranchTo(0x821966E0,int,a1);	
	 BranchTo(0x82196CF8,int,a1);

	 std::vector<boost::shared_ptr<Sonicteam::Player::IStepable>>* IStepableP2 = reinterpret_cast<std::vector<boost::shared_ptr<Sonicteam::Player::IStepable>>*>(a1 + 0x25C);

	 for ( std::vector<boost::shared_ptr<Sonicteam::Player::IStepable>>::iterator it = IStepableP2->begin();it != IStepableP2->end();it++){
		 Sonicteam::Player::IStepable*  boost_step = (*it).get();
		 boost_step->OnStepable(PlayerSpeed_Delta);
	 }
	 int PlayerPosture = *(_DWORD *)(a1 + 0xDC);
	 if ( PlayerPosture && *(_BYTE *)(a1 + 0xC9) )
	 {
		 (*(void (__fastcall **)(int, double))(*(_DWORD *)PlayerPosture + 8))(PlayerPosture, PlayerSpeed_Delta);// 82200538 (c_posture_control_func)
	 }
	 else
	 {
		 Sonicteam::Player::RootFrame* PlayerFrame = *(Sonicteam::Player::RootFrame **)(a1 + 0xCC);
		 if ( PlayerFrame)
		 {
			 PlayerFrame->FrameGetTransformMatrix2();
			 XMMATRIX matrix =  PlayerFrame->FrameGetTransformMatrix2();
			 BranchTo(0x82594698,int,*(_DWORD **)(a1 + 0xCC),&matrix);
		 }
	 }

	 BranchTo(0x82196768,int,a1);
	 std::vector<boost::shared_ptr<Sonicteam::Player::IStepable>>* IStepableP3 = reinterpret_cast<std::vector<boost::shared_ptr<Sonicteam::Player::IStepable>>*>(a1 + 0x26C);
	 for ( std::vector<boost::shared_ptr<Sonicteam::Player::IStepable>>::iterator it = IStepableP3->begin();it != IStepableP3->end();it++){
		 Sonicteam::Player::IStepable*  boost_step = (*it).get();
		 boost_step->OnStepable(PlayerSpeed_Delta);
	 }

	 std::vector<boost::shared_ptr<Sonicteam::Player::IStepable>>* IStepableP4 = reinterpret_cast<std::vector<boost::shared_ptr<Sonicteam::Player::IStepable>>*>(a1 + 0x27C);
	 for ( std::vector<boost::shared_ptr<Sonicteam::Player::IStepable>>::iterator it = IStepableP4->begin();it != IStepableP4->end();it++){
		 Sonicteam::Player::IStepable*  boost_step = (*it).get();
		 boost_step->OnStepable(PlayerSpeed_Delta);
	 }


	 int result = *(_DWORD *)(a1 + 0x2FC);
	 *(_QWORD *)(a1 + 0x200) = 0; // v2 but it == 0
	 *(_DWORD *)(a1 + 0x214) = 0;
	 if ( result )
		 BranchTo(0x82533520,int,result,PlayerSpeed_Delta);


	 if (_socket.IsWorks() && IsLocalPlayer){
		 Sonicteam::Player::RootFrame* PlayerFrame = *(Sonicteam::Player::RootFrame **)(a1 + 0xCC);
		 Sonicteam::Player::State::ICommonContext* PlayerContext = *(Sonicteam::Player::State::ICommonContext**)((*(int*)(a1 + 0xE4)) + 0x50);
		 Sonicteam::DocMarathonImp* impl = 	*(Sonicteam::DocMarathonImp**)(*(UINT32*)0x82D3B348 + 0x180);
		 UINT32 gameimp = *(UINT32*)(impl->DocCurrentMode + 0x6C);


		  SMDATA_PPL_CHANGE_TRANSFORM _data_;
		  SMDATA_PPL_CHANGE_ANIMATION _data2_;
		  SMDATA_PPL_CHANGE_RINGS _data3_;
		 {
			 _data_.sender_xuid = _socket.GetXUID(0);
			 _data_.Transform = PlayerFrame->FrameGetTransformMatrix2();
			 _data_.Position = *(XMVECTOR*)((*(UINT32*)(a1 + 0xDC)) + 0xB0) ;
		 }
		 {
			 _data2_.sender_xuid = _socket.GetXUID(0);
			 _data2_.AnimationID =   PlayerContext->CurrentAnimation;
			 _data2_.AnimationState = PlayerContext->AnimationState;
			 
			// std::stringstream hero; hero << _data2_.AnimationID << "-" << _data2_.AnimationState;
			 //DebugLogV2::PrintNextFixed(hero.str());
		 }

		 {
			 _data3_.sender_xuid = _socket.GetXUID(0);
			 _data3_.RingsCount =   *(UINT*)(gameimp + 0xE44);

		 }
		
		
		 
		 SocketMessage msg  =  DEFINE_SOCKET_MESSAGE_FROM_CONST_DATA(_data_);
		 SocketMessage msg2  =  DEFINE_SOCKET_MESSAGE_FROM_CONST_DATA(_data2_);
		 SocketMessage msg3  =  DEFINE_SOCKET_MESSAGE_FROM_CONST_DATA(_data3_);

		// std::stringstream bruh;  bruh << "X : " << _data_.Position.x << "Y : " << _data_.Position.y << "Z : " << _data_.Position.z;
		// DebugLogV2::PrintNextFixed(bruh.str());


		 if (_socket.IsClient()){
			 _socket.SendUDPMessageToServer(&msg);
			 _socket.SendUDPMessageToServer(&msg2);
			 _socket.SendUDPMessageToServer(&msg3);
		 }
		 else{
			 Players_DATA[_socket.GetXUID(0)].Context_Animation_ID = PlayerContext->CurrentAnimation;
			 Players_DATA[_socket.GetXUID(0)].Context_Animation_STATE = PlayerContext->AnimationState;
			 Players_DATA[_socket.GetXUID(0)].RFTransformMatrix0x70_FRAME =PlayerFrame->FrameGetTransformMatrix2();
			 Players_DATA[_socket.GetXUID(0)].Position_FRAME =*(XMVECTOR*)((*(UINT32*)(a1 + 0xDC)) + 0xB0) ;
			 Players_DATA[_socket.GetXUID(0)].RingsCount = *(UINT*)(gameimp + 0xE44);;

			 _socket.SendUDPMessageToClients(&msg);
			 _socket.SendUDPMessageToClients(&msg2);
			 _socket.SendUDPMessageToClients(&msg3);
		 }
		
	 }
	

	 return 0;

}
void TagBattleMain::GlobalInstall_ONLINE()
{

	WRITE_DWORD(0x8200356C,ObjectUpdate);

	WRITE_DWORD(0X82033568	,MainModeOnMessageRecieved);
	//WRITE_DWORD(0x82001AF0	,GameImpOnMessageRecieved);
	WRITE_DWORD(0x82001B3C,GameImpEngGlobalActionsRecieved);
	WRITE_DWORD(0x82001AEC,GameIMP_DESTRUCTION);

	/*

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
	*/



	WRITE_DWORD(0x82003568,RemoveCHR);
	WRITE_DWORD(0x82209E90 ,0x4E800020);
	WRITE_DWORD(0x8220BEF8 ,0x4E800020);

	WRITE_DWORD(0x82000950,EngineDocOnUpdateHE);


	//WRITE_DWORD(0x8229A5D0)
	
	

}
