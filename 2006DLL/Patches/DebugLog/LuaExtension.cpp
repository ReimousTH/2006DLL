#include "LuaExtension.h"

namespace DebugLogV2{

	static const struct luaL_reg BitLIBX [] = {
		{"AND", BIT_ANDEXY},
		{"OR", BIT_OREXY},
		{"SR", BIT_ShiftRightEXY},
		{"SL", BIT_ShiftLeftEXY},
		{NULL,NULL}
	};


	int BitLibGlobalInstall(lua_State*L)
	{
		luaL_openlib06(L,"bit",BitLIBX,0);
		return 1;

	}

	int BitBaseEXY(lua_State*L,int cs)
	{

		int v1 = lua_tonumber(L,1);
		int v2 = lua_tonumber(L,2);
		int result = 0;
		switch (cs){

			case 0:
				result = v1 << v2;
				break;
			case 1:
				result = v1 >> v2;
				break;
			case 2:
				result = v1 & v2;
				break;
			case 3:
				result = v1 | v2;
				break; 

			default:
				lua_pushnil(L);
				return 1;
		}
		lua_pushnumber(L,result);
		return 1;
	}

	int BIT_ShiftLeftEXY(lua_State* L)
	{
		return BitBaseEXY(L,0);
	}

	int BIT_ShiftRightEXY(lua_State* L)
	{
		return BitBaseEXY(L,1);
	}

	int BIT_ANDEXY(lua_State* L)
	{
		return BitBaseEXY(L,2);
	}

	int BIT_OREXY(lua_State* L)
	{
		return BitBaseEXY(L,3);
	}



	int DebugLabel_GlobalInstall(lua_State* LS)
	{

		lua_register06(LS,"DebugLabel",DebugLabel_new);
		luaL_newmetatable06(LS,"DebugLabel");


		// lua_setfield(L, -2, "__gc");
		lua_pushstring06(LS, "__gc"); lua_pushcfunction06(LS, DebugLabel_delete); lua_settable06(LS, -3);

		lua_pushvalue(LS, -1);  lua_pushstring06(LS, "__index"); lua_pushvalue(LS,-2);  lua_settable06(LS,-3);

		lua_pushstring06(LS, "SetText"); lua_pushcfunction06(LS, DebugLabel_SetText); 	lua_settable06(LS, -3);

		lua_pushstring06(LS, "SetPosition"); lua_pushcfunction06(LS, DebugLabel_SetPosition); 	lua_settable06(LS, -3);

		lua_pop(LS,1);

		return 1;
	}

	DebugLabel_new(lua_State* L)
	{

		const char* msg = lua_tostring(L,1);
		int PX = lua_tonumber(L,2);
		int PY = lua_tonumber(L,3);


		std::string msgt =  std::string(msg);
		int length = msgt.length() + 1;
		wchar_t* wcharPtr = new wchar_t[length];
		std::memset(wcharPtr, 0, length * sizeof(wchar_t));
		std::mbstowcs(wcharPtr, msgt.c_str(), length);
		msgt.clear();


		*reinterpret_cast<int**>(lua_newuserdata06(L, sizeof(int*))) = (int*)SpawnMessage(wcharPtr,PX,PY);

		luaL_getmetatable06(L,"DebugLabel");
		lua_setmetatable06(L, -2);

		free(wcharPtr);

		return 1;

	}

	int DebugLabel_delete(lua_State* L)
	{

		BranchTo(0x8262BA68,int,*reinterpret_cast<int**>(lua_touserdata(L, 1)),1); //Destroy from mem

		return 0;
	}

	int DebugLabel_SetText(lua_State* L)
	{
		int* TextEntity = (*reinterpret_cast<int**>(luaL_checkudata(L, 1, "DebugLabel")));
		UINT ud = (UINT)TextEntity;

		const char* msg = lua_tostring(L,2);
		std::string msgt =  std::string(msg);
		int length = msgt.length() + 1;
		wchar_t* wcharPtr = new wchar_t[length];
		std::memset(wcharPtr, 0, length * sizeof(wchar_t));
		std::mbstowcs(wcharPtr, msgt.c_str(), length);
		msgt.clear();
		EditMessage((UINT32)ud,wcharPtr);
		free(wcharPtr);
		return 0;
	}

	int DebugLabel_SetPosition(lua_State* L)
	{
		int* TextEntity = (*reinterpret_cast<int**>(luaL_checkudata(L, 1, "DebugLabel")));
		UINT ud = (UINT)TextEntity;
		float x  = lua_tonumber(L,2);
		float y = lua_tonumber(L,3);
		ChangeMessagePosition(ud,x,y);
		return 0;
	}

	static const struct luaL_reg PET [] = {
		{"GetPlayerInput", GetPlayerInput},
		{"GetPlayerRawInput", GetPlayerRawInput},
		{"GetPlayerPosition",GetPlayerPosition},
		{"print",PrintNext},
		{NULL, NULL}  /* sentinel */
	};
	int PlayerLIB_GlobalInstall(lua_State* LS)
	{
		luaL_openlib06(LS,"player",PET,0);
		return 0;
	}

	


	extern "C" static int GetPlayerRawInput(lua_State* L)
	{
		int n = lua_gettop(L);  
		if (n <= 0) 

		{lua_pushnumber(L, 0); return 1;}


		UINT32 PlayerIndex = (UINT32)lua_tonumber(L,1);
		Sonicteam::DocMarathonImp* impl = 	*(Sonicteam::DocMarathonImp**)(*(UINT32*)0x82D3B348 + 0x180);
		PlayerIndex = impl->GetRealControllerID(PlayerIndex);
		Sonicteam::Player::Input::IListenerInputStruc01* Inp2 = (Sonicteam::Player::Input::IListenerInputStruc01*)impl->GetPlayerInput(PlayerIndex);

		Sonicteam::Player::Input::IListenerInputStruc01 Inp;


		if (Inp2){
			memcpy(&Inp,Inp2,sizeof(Sonicteam::Player::Input::IListenerInputStruc01));
		}


		BranchTo(0x825D5C30,int,L); //lua_newtable


		//RtlReAllocateHeap NOT same :|

		BranchTo(0x825D5918,int,L,"Buttons");
		//BranchTo(0x825D5890,int,L,Inp.wLastButtons);
		lua_pushnumber(L, Inp.wLastButtons);
		BranchTo(0x825D5D98,int,L,-3);



		BranchTo(0x825D5918,int,L,"LStickX");
		BranchTo(0x825D5890,int,L,Inp.fX1);
		BranchTo(0x825D5D98,int,L,-3);


		BranchTo(0x825D5918,int,L,"LStickY");
		BranchTo(0x825D5890,int,L,Inp.fY1);
		BranchTo(0x825D5D98,int,L,-3);

		BranchTo(0x825D5918,int,L,"RStickX");
		BranchTo(0x825D5890,int,L,Inp.fX2);
		BranchTo(0x825D5D98,int,L,-3);

		BranchTo(0x825D5918,int,L,"RStickY");
		BranchTo(0x825D5890,int,L,Inp.fY2);
		BranchTo(0x825D5D98,int,L,-3);

		
		/*

		lua_pushstring(L, "Buttons");
		lua_pushnumber(L, Inp.wLastButtons);
		lua_settable(L, -3);

		lua_pushstring(L, "LStickX");
		lua_pushnumber(L, Inp.fX1);
		lua_settable(L, -3);

		lua_pushstring(L, "LStickY");
		lua_pushnumber(L, Inp.fY1);
		lua_settable(L, -3);

		lua_pushstring(L, "RStickX");
		lua_pushnumber(L, Inp.fX2);
		lua_settable(L, -3);

		lua_pushstring(L, "RStickY");
		lua_pushnumber(L, Inp.fY2);
		lua_settable(L, -3);

	
*/




		return 1;
	}


	extern "C" int GetPlayerInput(lua_State* L){


	
		int n = lua_gettop(L);  
		if (n <= 0) 
		{lua_pushnumber(L, 0); return 1;}


		UINT32 PlayerIndex = (UINT32)lua_tonumber(L,1);
		Sonicteam::DocMarathonImp* impl = 	*(Sonicteam::DocMarathonImp**)(*(UINT32*)0x82D3B348 + 0x180);
		PlayerIndex = impl->GetRealControllerID(PlayerIndex);
		Sonicteam::Player::Input::IListenerInputStruc01* Inp = (Sonicteam::Player::Input::IListenerInputStruc01*)impl->GetPlayerInput(PlayerIndex);
		
		if (!Inp || Inp->PtrKhronoControlInputListener == 0){
			lua_pushnumber(L, 0); return 1;
		}


		Sonicteam::SoX::RNodeF<Sonicteam::SoX::Object>* h = (Sonicteam::SoX::RNodeF<Sonicteam::SoX::Object>*) &Inp->PtrMyInputObj;
		Sonicteam::SoX::RNodeF<Sonicteam::SoX::Object>* temp = (Sonicteam::SoX::RNodeF<Sonicteam::SoX::Object>*)h->Next;


		if (h->Next != h->Previous){
			while (h != temp){

				if (temp->Next == temp->Previous) {temp =0;}

				if (temp->FObject && dynamic_cast<Sonicteam::Player::Input::IListener*>(temp->FObject) != 0){
					break;
				}
				temp = (Sonicteam::SoX::RNodeF<Sonicteam::SoX::Object>*)temp->Next;
			}
		}
		else{
			temp = 0;
		}

		if (temp && temp->FObject) {
			Sonicteam::Player::Input::IListener* il =   dynamic_cast<Sonicteam::Player::Input::IListener*>(temp->FObject);
			if (il){
				lua_pushnumber(L, il->ListenerGetResult()); 
			}
		}
		else{
			lua_pushnumber(L, 0); 
		}
		
		return 1;
	}

	extern "C" int PrintNext(lua_State* L){

		int n = lua_gettop(L);  /* number of arguments */
		int i;
		lua_getglobal(L, "tostring");
		for (i=1; i<=n; i++) {
			const char *s;
			lua_pushvalue(L, -1);  /* function to be called */
			lua_pushvalue(L, i);   /* value to print */
			lua_call(L, 1, 1);
			s = lua_tostring(L, -1);  /* get result */
			if (s == NULL)
				return luaL_error(L, "`tostring' must return a string to `print'");
			
			std::string msg =  std::string(s);

			int length = msg.length() + 1;
			wchar_t* wcharPtr = new wchar_t[length];
			std::memset(wcharPtr, 0, length * sizeof(wchar_t));
			std::mbstowcs(wcharPtr, msg.c_str(), length);


			int MCount = DebugMessages.size();
			if (MCount > 2){
				MCount--;
				std::vector<int>::iterator it = DebugMessages.begin();
				BranchTo(0x8262BA68,int,*it,1); //Destroy from mem
				std::advance(it, 0);
				DebugMessages.erase(it);

				//Re Order Messages
				
				int cc = 0;
				for (std::vector<int>::iterator it = DebugMessages.begin(); it != DebugMessages.end(); ++it) {
					ChangeMessagePositionY( *it,(cc * 28) );
					cc++;
				}
			}

			DebugMessages.push_back( SpawnMessage(wcharPtr,(MCount * 28)));
	
			//if (i>1) fputs("\t", stdout);
			//fputs(s, stdout);
			lua_pop(L, 1);  /* pop result */
		}
		fputs("\n", stdout);
		return 0;

	}
	extern "C" int GetPlayerPosition(lua_State* L){

		int n = lua_gettop(L);  
		if (n <= 0) 
		{lua_pushnumber(L, 0); return 1;}


		UINT32 PlayerIndex = (UINT32)lua_tonumber(L,1);
		Sonicteam::DocMarathonImp* impl = 	*(Sonicteam::DocMarathonImp**)(*(UINT32*)0x82D3B348 + 0x180);
		UINT32 vft =  *(UINT32*)impl->DocCurrentMode;
		UINT32 pstack[4] = {};
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


					Sonicteam::Player::State::IMachine* PlayerMashine = *(Sonicteam::Player::State::IMachine**)(Actor+0xE4);
					if (PlayerMashine){
						Sonicteam::Player::State::CommonContext* PCC = (Sonicteam::Player::State::CommonContext*)PlayerMashine->GetMashineContext().get();
						UINT32 PCC_AI = (UINT32)PCC->PlayerAIAmigoPlugin.get();
						UINT32 PCC_AI_FLAG = *(UINT32*)(PCC_AI + 0x24);
						if (PCC_AI_FLAG == 0) pstack[PIX++] = Actor;
					}
				}
			}
		}
		XMFLOAT4 POS;
		if (pstack[PlayerIndex] != 0){
			UINT32 ObjectPlayer = pstack[PlayerIndex];
			UINT32 PlayerPosture = *(UINT32 *)(ObjectPlayer + 0xDC);
			XMFLOAT4* PlayerPos = (XMFLOAT4*)(PlayerPosture + 0xB0);
			memcpy(&POS,PlayerPos,sizeof(XMFLOAT4));
		}

		
		BranchTo(0x825D5C30,int,L); //lua_newtable

		BranchTo(0x825D5918,int,L,"X");
		BranchTo(0x825D5890,int,L,POS.x);
		BranchTo(0x825D5D98,int,L,-3);

		BranchTo(0x825D5918,int,L,"Y");
		BranchTo(0x825D5890,int,L,POS.y);
		BranchTo(0x825D5D98,int,L,-3);

		BranchTo(0x825D5918,int,L,"Z");
		BranchTo(0x825D5890,int,L,POS.z);
		BranchTo(0x825D5D98,int,L,-3);
		




		return 1;

	}


	





	

	int STRLIB_GlobalInstall(lua_State* LS)
	{
		luaopen_string_06(LS);
		return 0;
	}

	static const struct luaL_reg MEM [] = {
		{"GetPlayerInput", GetPlayerInput},
		{"GetPlayerRawInput", GetPlayerRawInput},
		{"GetPlayerPosition",GetPlayerPosition},
		{"print",PrintNext},
		{NULL, NULL}  /* sentinel */
	};



	int MemoryLIB_GlobalInstall(lua_State* LS)
	{
		return 0;
	}

}