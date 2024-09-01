	#include "LuaExtension_PlayerRework.h"

#define PLIB_NAME_META "PlayerMeta"
#define PLIB_NAME "Player"


namespace DebugLogV2{





	void GlobalInstall_PlayerRework(lua_State* LS)
	{
		if (LS == 0){
			WRITE_DWORD(0x82195AAC,POWERPC_ADDIS(11,0,POWERPC_HI((unsigned int)&FixedPlayerFunctionsTables)));
			WRITE_DWORD(0x82195AB4,POWERPC_ADDI(11,11,POWERPC_LO((unsigned int)&FixedPlayerFunctionsTables)));
	
			return;
		}

		
		lua_register06(LS, PLIB_NAME, Player__NEW);
		luaL_newmetatable06(LS, PLIB_NAME_META);

	
		lua_pushstring06(LS,"ID"); lua_pushnumber(LS,0); lua_settable06(LS,-3); // ID = 0
		lua_pushstring06(LS,"ActorPTR"); lua_pushlightuserdata(LS,0); lua_settable06(LS,-3); // ActorPTR = 0
		lua_pushstring06(LS,"AI"); lua_pushboolean(LS,false); lua_settable06(LS,-3); // AI = 0
		lua_pushstring06(LS,"__index"); lua_pushvalue(LS,-2); lua_settable06(LS,-3); // __index = PlayerMeta

	
		lua_newtable06(LS);lua_pushstring06(LS, "__index");luaL_getmetatable06(LS, "MemoryMeta");lua_settable06(LS, -3); lua_setmetatable06(LS, -2); //setmetatable(PlayerMeta, { __index = MemoryMeta })

		lua_pushstring06(LS, "GetName");lua_pushcfunction06(LS, PlayerR__GetName);lua_settable06(LS, -3); // Equivalent to table["GetName"] = PlayerR__GetName
		lua_pushstring06(LS, "SWAP");lua_pushcfunction06(LS, PlayerR__SWAP);lua_settable06(LS, -3); // Equivalent to table["SWAP"] = PlayerR__SWAP
		lua_pushstring06(LS, "Reload");lua_pushcfunction06(LS, PlayerR__Reload);lua_settable06(LS, -3); // Equivalent to table["Reload"] = PlayerR__Reload
		lua_pushstring06(LS, "GetPosition");lua_pushcfunction06(LS, PlayerR__GetPosition);lua_settable06(LS, -3); // Equivalent to table["GetPosition"] = PlayerR__GetPosition
		lua_pushstring06(LS, "SetPosition");lua_pushcfunction06(LS, PlayerR__SetPosition);lua_settable06(LS, -3); // Equivalent to table["SetPosition"] = PlayerR__SetPosition
		lua_pushstring06(LS, "SetActorPTR");lua_pushcfunction06(LS, PlayerR__SetActorPTR);lua_settable06(LS, -3); // Equivalent to table["SetActorPTR"] = PlayerR__SetActorPTR
		lua_pushstring06(LS, "GetStateID");lua_pushcfunction06(LS, PlayerR__GetStateID);lua_settable06(LS, -3); // Equivalent to table["GetStateID"] = PlayerR__GetStateID
		lua_pushstring06(LS, "SetStateID");lua_pushcfunction06(LS, PlayerR__SetStateID);lua_settable06(LS, -3); // Equivalent to table["SetStateID"] = PlayerR__SetStateID
		lua_pushstring06(LS, "GetMachine2");lua_pushcfunction06(LS, PlayerR__GetMachine2);lua_settable06(LS, -3); // Equivalent to table["SetStateID"] = PlayerR__SetStateID

		

		
		
		lua_pop(LS,1);
		

		return;
	

	}

	void GetPlayerActorsR(UINT32* pstack,bool AI){


		pstack[0] = 0;
		pstack[1] = 0;
		pstack[2] = 0;
		pstack[3] = 0;


		Sonicteam::DocMarathonImp* impl = 	*(Sonicteam::DocMarathonImp**)(*(UINT32*)0x82D3B348 + 0x180);
		UINT32 gameimp = *(UINT32*)(impl->DocCurrentMode + 0x6C);

		int LocalPlayer = 0;
		if (gameimp == 0 || *(UINT32*)gameimp != 0x82001AEC) return;
		UINT32 vft =  *(UINT32*)impl->DocCurrentMode;


		if (vft != 0x82033534)return;
		if ( *(UINT32*)(gameimp+0x11C4) == 0) return;
		INT32 ActorManager = *(UINT32*)(gameimp+0x11C4);

		for (int i = 0;i<4;i++){
				UINT32 gameimp = *(UINT32*)(impl->DocCurrentMode + 0x6C);
				int ActorID =  *(int*)(gameimp + 0xE40) + (i * 0x4C);
				if (ActorID == -1) continue;
				pstack[i] = BranchTo(0x821609D0,int,ActorManager,&ActorID);
		}

	
	}

	void GetPlayerActorsPTR(UINT32* pstack,bool AI){

		pstack[0] = 0;
		pstack[1] = 0;
		pstack[2] = 0;
		pstack[3] = 0;

		Sonicteam::DocMarathonImp* impl = 	*(Sonicteam::DocMarathonImp**)(*(UINT32*)0x82D3B348 + 0x180);
		UINT32 vft =  *(UINT32*)impl->DocCurrentMode;

		if (vft == 0x82033534){ //GameMode

			UINT32 gameimp = *(UINT32*)(impl->DocCurrentMode + 0x6C);
			UINT32 ActorManager = *(UINT32*)(gameimp+0x11C4);
			UINT32 ActorMangerActorsCount = *(UINT32*)(ActorManager+0x80000);
			UINT32 PIX = 0;
			for (int i = 0;i<ActorMangerActorsCount;i++)
			{
				UINT32 Actor = *(UINT32*)(ActorManager+0x40000+(i*4));
				UINT32 ActorVFT = *(UINT32*)Actor;
				if (ActorVFT == 0x82003564){ //Object_Player


					byte IsObjectPlayerHaveControll = *(byte*)(Actor + 0xC8);
					byte AIFLAG = *(byte*)(Actor + 0xCA);
					if (AI)
					{
						if (IsObjectPlayerHaveControll == 0 && AIFLAG){
							pstack[PIX++] = (UINT32)(ActorManager+0x40000+(i*4));
						}


					}
					else{
						if (IsObjectPlayerHaveControll){
							pstack[PIX++] = (UINT32)(ActorManager+0x40000+(i*4));
						}
					}


				}
			}
		}
	}

	extern "C" int Player__CreateMetatable(lua_State* L,int ID,bool AI){
		

		UINT32 stack1[16];
		UINT32 stack2[16];
		GetPlayerActorsR((UINT32*)&stack1, AI);
		GetPlayerActorsPTR((UINT32*)&stack2, AI);


		lua_getglobal06(L, "Memory");
		lua_pushlightuserdata(L, (void*)stack1[ID]);
		lua_pcall06(L, 1, 1, 0); // Memory(stack1[ID]) -> {}::Memory


		// Second table for metatable set
	//	lua_newtable06(L);
	//	lua_pushstring06(L, "__index");luaL_getmetatable06(L, PLIB_NAME_META);lua_settable06(L, -3); // { __index = MemoryMeta }
	//	lua_setmetatable06(L, -2); // setmetatable(self, { __index = MemoryMeta })


		luaL_getmetatable06(L, PLIB_NAME_META);
		lua_setmetatable06(L,-2);

		lua_pushstring06(L, "ID");
		lua_pushnumber(L, ID);
		lua_settable06(L, -3); // self.ptr = ptr

		lua_pushstring06(L, "ActorPTR");
		lua_pushlightuserdata(L, (void*)stack2[ID]);
		lua_settable06(L, -3); // self.ActorPTR = ptr


		lua_pushstring06(L, "AI");
		lua_pushboolean(L, AI);
		lua_settable06(L, -3); // self.move = move

		return 1;
	}
	extern "C" int Player__NEW(lua_State* L)
	{
		int arg1 = 0;
		bool arg2 = false;
		int args = lua_gettop(L);
		if (args > 0){
			if (lua_isnumber(L,1)) arg1 = lua_tonumber(L,1);
		}
		if (args > 1){
			if (lua_isboolean(L,2)) arg2 = lua_toboolean(L,2);
		}
		Player__CreateMetatable(L,arg1,arg2);
		return 1;
	}

	extern "C" int PlayerR__GetName(lua_State* L)
	{
		lua_pushstring06(L,"ptr");
		lua_gettable(L,1);
		int ptr = (int)lua_touserdata(L,-1);

		std::string* c_player_name =  (std::string*)(ptr + 0x1D8);
		lua_pushstring06(L,	c_player_name->c_str());
		return 1;
	}

	extern "C" int PlayerR__Reload(lua_State*L)
	{
		lua_pushstring06(L,"ID");
		lua_gettable(L,1);
		int ID = (int)lua_tonumber(L,-1);

		lua_pushstring06(L,"AI");
		lua_gettable(L,1);
		bool AI = lua_toboolean(L,-1);



		UINT32 stack[16];
		GetPlayerActorsR((UINT32*)&stack,AI);


		lua_pushstring06(L,"ptr");
		lua_pushlightuserdata(L,(void*)stack[ID]);
		lua_settable06(L,1);



		lua_pushstring06(L,"ActorPTR");
		GetPlayerActorsPTR((UINT32*)&stack,AI);
		lua_pushlightuserdata(L,(void*)stack[ID]);
		lua_settable06(L,1);



		lua_pushvalue06(L,1); //self
		return 1;

		

	}

	extern "C" int PlayerR__SWAP(lua_State*L)
	{

		int args = lua_gettop(L);
		if (args <= 1) return 0;
		const char* chara = lua_tostring(L,2); //arg2
		
		
		
		lua_pushstring06(L,"ptr");
		lua_gettable(L,1);
		void* ObjectPlayerPTR = lua_touserdata(L,-1);
		BranchTo(0x82195D20,int,ObjectPlayerPTR,chara);
		return 0;

	}


	extern "C" int Vector__CallLUAConstructor(lua_State* L,XMVECTOR* vector){


		lua_getglobal06(L,"Vector");

		lua_pushnumber(L,vector->x);
		lua_pushnumber(L,vector->y);
		lua_pushnumber(L,vector->z);
		lua_pushnumber(L,vector->w);

		lua_pcall06(L,4,1,0);
		return 1;

	}

	UINT32 GetPlayerPostureR(UINT32 ObjectPlayer){
		return *(UINT32 *)(ObjectPlayer + 0xDC);
	}
	XMVECTOR* GetPlayerPositionR(UINT32 PlayerPosture){
		return (XMVECTOR*)(PlayerPosture + 0xB0);
	}


	extern "C" int PlayerR__GetPosition(lua_State* L)
	{
		lua_pushstring06(L,"ptr");
		lua_gettable(L,1);
		void* ObjectPlayerPTR = lua_touserdata(L,-1);
		int OBJPlayer = (int)ObjectPlayerPTR;
		XMVECTOR vector = {0};
		UINT32 PlayerPosture = GetPlayerPostureR(OBJPlayer);
		vector =  *(GetPlayerPositionR(PlayerPosture));
		Vector__CallLUAConstructor(L,&vector);

		return 1;
	}

	extern "C"  XMVECTOR Vector__GetVectorTable(lua_State* L,int idx){
		XMVECTOR vector1 = {0,0,0,1};
		if (lua_istable(L,idx))
		for (int i = 1; i <= 4; ++i) {
			lua_rawgeti06(L, idx, i); // Get value at index i

			if (lua_isnumber(L, -1)) {
				float value = lua_tonumber(L, -1);
				vector1.v[i-1] = value;
			}

			// Pop the value from the stack
			lua_pop(L, 1);
		}
		return vector1;
	}


	extern "C" int PlayerR__SetPosition(lua_State* L)
	{
		int args = lua_gettop(L)-1;
		lua_pushstring06(L,"ptr");
		lua_gettable(L,1);
		void* ObjectPlayerPTR = lua_touserdata(L,-1);


		int OBJPlayer = (int)ObjectPlayerPTR;
		XMVECTOR vector = {0};



		//Vector
		if (lua_istable(L,2)){
			vector = Vector__GetVectorTable(L,2);

		}
		else{

			if (args > 0 && lua_isnumber(L,2) ) vector.x = lua_tonumber(L,2); 
			if (args > 1 && lua_isnumber(L,3) ) vector.y = lua_tonumber(L,3); 
			if (args > 2 && lua_isnumber(L,4) ) vector.z = lua_tonumber(L,4); 
			if (args > 3 && lua_isnumber(L,5) ) vector.w = lua_tonumber(L,5); 
		}


		UINT32 PlayerPosture = GetPlayerPostureR(OBJPlayer);
		*(GetPlayerPositionR(PlayerPosture)) = vector;


		return 0;
	}


	extern "C" int PlayerR__GetActorPTR(lua_State* L){

		

		return 1;

	}

	extern "C" int PlayerR__SetActorPTR(lua_State* L)
	{
		if (lua_isuserdata(L,2)){

			lua_pushstring06(L,"ActorPTR");
			lua_gettable(L,1);
			UINT32* ActorPTR  = (UINT32*)lua_touserdata(L,-1);
			*ActorPTR = (UINT32)lua_touserdata(L,2);
		}
		return 0;
	}





	extern "C" int PlayerR__GetStateID(lua_State* L)
	{
		lua_pushstring06(L,"ptr");
		lua_gettable(L,1);
		int OBJPlayer = (int)lua_touserdata(L,-1);
		if (OBJPlayer ){
			Sonicteam::Player::State::IMachine* Mashine = *(Sonicteam::Player::State::IMachine**)(OBJPlayer + 0xE4);
			if (Mashine){
				lua_pushnumber(L,Mashine->GetCurrentMashineStateID());
			}
			else{
				lua_pushnil(L);
			}

		}
		else{
			lua_pushnil(L);
		}


		return 1;
	}

	extern "C" int PlayerR__SetStateID(lua_State* L)
	{

		lua_pushstring06(L,"ptr");
		lua_gettable(L,1);
		int OBJPlayer = (int)lua_touserdata(L,-1);
		int StateID = lua_tonumber(L,2);

		if (OBJPlayer ){
			Sonicteam::Player::State::IMachine* Mashine = *(Sonicteam::Player::State::IMachine**)(OBJPlayer + 0xE4);
			Mashine->CompleteChangeMashineState(StateID);

		}
	

		return 0;
	}

	extern "C" int PlayerR__GetMachine2(lua_State* L)
	{

		lua_pushstring06(L,"ptr");
		lua_gettable(L,1);
		int OBJPlayer = (int)lua_touserdata(L,-1);
		int StateID = lua_tonumber(L,2);

		if (OBJPlayer ){
			Sonicteam::Player::State::IMachine* Mashine = *(Sonicteam::Player::State::IMachine**)(OBJPlayer + 0xE4);
			Sonicteam::Player::State::Machine2* Machine2 = dynamic_cast<Sonicteam::Player::State::Machine2*>(Mashine);

			lua_getglobal06(L,"StateIMachine");
			lua_pushlightuserdata(L,(void*)Machine2);
			lua_pcall06(L,1,1,0);
		}

		return 1;


	}

}
