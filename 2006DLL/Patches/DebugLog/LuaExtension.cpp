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

	
	




	int VectorLIB_GlobalInstall(lua_State* LS)
	{

		lua_register06(LS,"Vector",Vector_NEW);

		luaL_newmetatable06(LS,"Vector");
		lua_pushstring06(LS, "__gc"); lua_pushcfunction06(LS, Vector__GC); lua_settable06(LS, -3);
		lua_pushstring06(LS, "__tostring"); lua_pushcfunction06(LS, Vector__tostring); lua_settable06(LS, -3);
		lua_pushstring06(LS, "__add"); lua_pushcfunction06(LS, Vector__add); lua_settable06(LS, -3);
		lua_pushstring06(LS, "__sub"); lua_pushcfunction06(LS, Vector__sub); lua_settable06(LS, -3);

		lua_pushvalue(LS, -1);  lua_pushstring06(LS, "__index"); lua_pushvalue(LS,-2);  lua_settable06(LS,-3);
		lua_pushstring06(LS, "GetTable"); lua_pushcfunction06(LS, Vector_GetTable); 	lua_settable06(LS, -3);

		lua_pop(L,1);


		lua_register06(LS,"VectorNew",Vector_NEW);

		luaL_newmetatable06(LS,"Vector");
		lua_pushstring06(LS, "__gc"); lua_pushcfunction06(LS, Vector__GC); lua_settable06(LS, -3);
		lua_pushstring06(LS, "__tostring"); lua_pushcfunction06(LS, Vector__tostring); lua_settable06(LS, -3);
		lua_pushstring06(LS, "__add"); lua_pushcfunction06(LS, Vector__add); lua_settable06(LS, -3);
		lua_pushstring06(LS, "__sub"); lua_pushcfunction06(LS, Vector__sub); lua_settable06(LS, -3);

		lua_pushvalue(LS, -1);  lua_pushstring06(LS, "__index"); lua_pushvalue(LS,-2);  lua_settable06(LS,-3);
		lua_pushstring06(LS, "GetTable"); lua_pushcfunction06(LS, Vector_GetTable); 	lua_settable06(LS, -3);

		lua_pop(L,1);


		return 1;
	}

	extern "C" Vector__GC(lua_State* L){
		BranchTo(0x82186190,int,*reinterpret_cast<XMVECTOR**>(lua_touserdata(L, 1))); //Destroy from mem
		return 0;
	}

	extern "C" Vector_GetTable(lua_State* L){


		XMVECTOR* vector = (*reinterpret_cast<XMVECTOR**>(luaL_checkudata(L, 1, "Vector")));
	

		lua_newtable06(L);

		lua_pushstring06(L, "X");
		lua_pushnumber(L, vector->x);
		lua_settable06(L, -3);

		lua_pushstring06(L, "Y");
		lua_pushnumber(L, vector->y);
		lua_settable06(L, -3);

		lua_pushstring06(L, "Z");
		lua_pushnumber(L, vector->z);
		lua_settable06(L, -3);

		lua_pushstring06(L, "W");
		lua_pushnumber(L, vector->w);
		lua_settable06(L, -3);

	


		return 1;
	}
	extern "C" Vector__tostring(lua_State* L){

		int args = lua_gettop(L);


		XMVECTOR* vector = (*reinterpret_cast<XMVECTOR**>(luaL_checkudata(L, 1, "Vector")));
		//PE->ObjectPlayer
		const char* format = "(X = %.2f, Y = %.2f, Z = %.2f, W = %.2f)";
		if (args > 1){
			format = lua_tostring(L,2);
		}
		char buffer[100];

		std::sprintf(buffer, format,vector->x, vector->y, vector->z,vector->w);
		lua_pushstring06(L, buffer);



		return 1;
	}

	extern "C" Vector__add(lua_State* L){


		XMVECTOR vector1 = *(*reinterpret_cast<XMVECTOR**>(luaL_checkudata(L, 1, "Vector")));
		XMVECTOR vector2 = *(*reinterpret_cast<XMVECTOR**>(luaL_checkudata(L, 2, "Vector")));


		//why i dont use operators well because (they allocate memory either and i dont too)
		XMVECTOR* z = (XMVECTOR*)malloc06(sizeof(XMVECTOR));
		*z = vector1 + vector2;
		*reinterpret_cast<XMVECTOR**>(lua_newuserdata06(L, sizeof(XMVECTOR*))) = z;
		// Set the metatable for the new userdata
		luaL_getmetatable(L, "Vector");
		lua_setmetatable(L, -2);


		return 1;
	}
	extern "C" Vector__sub(lua_State* L){


		XMVECTOR vector1 = *(*reinterpret_cast<XMVECTOR**>(luaL_checkudata(L, 1, "Vector")));
		XMVECTOR vector2 = *(*reinterpret_cast<XMVECTOR**>(luaL_checkudata(L, 2, "Vector")));
		//why i dont use operators well because (they allocate memory either and i dont too)
		XMVECTOR* z = (XMVECTOR*)malloc06(sizeof(XMVECTOR));
		*z = vector1 - vector2;
		*reinterpret_cast<XMVECTOR**>(lua_newuserdata06(L, sizeof(XMVECTOR*))) = z;
		// Set the metatable for the new userdata
		luaL_getmetatable(L, "Vector");
		lua_setmetatable(L, -2);


		return 1;
	}




	extern "C" Vector_NEW(lua_State* L)
	{
		int args = lua_gettop(L);

		XMVECTOR* z = (XMVECTOR*)malloc06(sizeof(XMVECTOR));

		for (int i = 0;i<args;i++){
			z->v[i] = lua_tonumber(L,i+1);
		}
		

		*reinterpret_cast<XMVECTOR**>(lua_newuserdata06(L, sizeof(XMVECTOR*))) = z;

		luaL_getmetatable06(L,"Vector");
		lua_setmetatable06(L, -2);

		return 1;
	}

	static const struct luaL_reg PET [] = {
		{"GetPlayerInput", GetPlayerInput},
		{"GetPlayerRawInput", GetPlayerRawInput},
		{"GetPlayerPosition",GetPlayerPosition},
		{"SetPlayerPosition",SetPlayerPosition},
		{"print",PrintNext},
		{NULL, NULL}  /* sentinel */
	};


	struct ObjectSetParamData{

	};

	struct ObjectSetData{

		ObjectSetData(const char* ObjectName,const char* ObjectTypeName,XMVECTOR* Position){
			this->ObjectName = ObjectName;
			this->ObjectTypeName = ObjectTypeName;
			this->Position.x = Position->x;
			this->Position.y = Position->y;
			this->Position.z = Position->z;
			this->ObjectUnkFloat1 = 2;
			this->ObjectUnkFloat2 = 0;
			this->ObjectUnkFloat3 = 0;
			this->ObjectUnkFloat4 = 0;
			this->ObjectUnkFloat5 = 40000;


			this->Rotation.x = 0;
			this->Rotation.y = 0;
			this->Rotation.z = 0;
			this->Rotation.w = 1;

			this->ParamsCount = 0;
			
	/*

			this->ObjectUnkFloat6 = 0;
			this->ObjectUnkFloat7 = 0;
			this->ObjectUnkFloat8 = 2;
			*/

		}
	
		const char* ObjectName;
		const char* ObjectTypeName;
		//BELL INFO
		float ObjectUnkFloat1; //=2
		float ObjectUnkFloat2; //=0
		float ObjectUnkFloat3; //=0
		float ObjectUnkFloat4; //=0
		XMFLOAT3 Position;
		float ObjectUnkFloat5; //40000
		XMFLOAT4 Rotation;

		unsigned int ParamsCount;

		ObjectSetParamData* Params;

	};



	extern "C" GameLIB_NewActorRestore(lua_State* L){
		XMVECTOR Pos;

	
		int atgs = lua_gettop(L);
		if (atgs >= 4){
			for (int i = 0;i<3;i++){
				Pos.v[i] = lua_tonumber(L,i+2);
			}
		}

		XMVECTOR Rot;
		if (atgs >= (7)){
			for (int i = 0;i<4;i++){
				Rot.v[i] = lua_tonumber(L,3+(i+1));
			}
		}









		const char* OBJ_ID =  lua_tostring(L,1);

		Sonicteam::DocMarathonImp* impl = 	*(Sonicteam::DocMarathonImp**)(*(UINT32*)0x82D3B348 + 0x180);
		UINT32 gameimp = *(UINT32*)(impl->DocCurrentMode + 0x6C);
		int UnkMGR =   *(_DWORD *)(gameimp  + 0x1278);
		int PropSceneClass = *(_DWORD *)(UnkMGR + 0x44);

		int RefObjectTypePropClass;
		BranchTo(0x82456DA0,int,&RefObjectTypePropClass,PropSceneClass,&std::string(OBJ_ID)); //GetObjectTypePropClass
		int PlacementTypePTRB[2] = {0,0};
		//default,design,....
		BranchTo(0x82461848,int,&PlacementTypePTRB, *(_DWORD *)(gameimp + 0x1278), 0);
		int PlacementTypePTR = PlacementTypePTRB[0];
		ObjectSetData ObjData = ObjectSetData("dashpanel01",OBJ_ID,&Pos);
		ObjData.Params = (ObjectSetParamData*)malloc06(0x40);
		memset(ObjData.Params,0,0x40);

		int InstnceProp =  BranchTo(0x8245A080,int,malloc06(0x14),PlacementTypePTR,&ObjData,&RefObjectTypePropClass);
		
		int obj_index = 100;
		int EntityHandle = BranchTo(0x82461128,int,malloc06(0x1c),PlacementTypePTR,obj_index);

		
		int buffer[0x30] = {0};
		BranchTo(0x8245C680,int,&buffer,&InstnceProp,&EntityHandle,0,&std::string(OBJ_ID));



		int* PropManger = *(int**)PlacementTypePTR;
		int result = BranchTo(0x824619C8,int,(PropManger)[0xF], OBJ_ID, buffer);







		/*
		int buff[0x10];
		Sonicteam::DocMarathonImp* impl = 	*(Sonicteam::DocMarathonImp**)(*(UINT32*)0x82D3B348 + 0x180);
		UINT32 gameimp = *(UINT32*)(impl->DocCurrentMode + 0x6C);
		int v15[2];
		v15[0] = 0;
		v15[1] = 0;
		int UnkMGR =   *(_DWORD *)(gameimp  + 0x1278);
		int PropSceneClass = *(_DWORD *)(UnkMGR + 0x44);
		int unk_ref_3;
		int unk_ref_2 = BranchTo(0x82456DA0,int,&unk_ref_3,PropSceneClass,&std::string("dashpanel"));
		//last index
		BranchTo(0x82461848,int,&v15, *(_DWORD *)(gameimp + 0x1278), 0);
		_DWORD **PropManger  = (_DWORD**)v15[0];
		int OBJDATA[0x40];
		int OBJDATA1[0x40];
		memset(&OBJDATA1,0,0x40);
		float param_2 = 2.0;
		OBJDATA[0] = (int)"dashpanel01";
		OBJDATA[1] = (int)"dashpanel";
		OBJDATA[2] = *(int*)&param_2;
		OBJDATA[3] = 0;
		OBJDATA[4] = 0;
		OBJDATA[5] = 0;
		OBJDATA[5] = 0;
		//POS ??
		OBJDATA[6] = *(int*)&Pos.x;
		OBJDATA[7] = *(int*)&Pos.y;
		OBJDATA[8] = *(int*)&Pos.z;
		OBJDATA[9] = 0;
		//ROT
		OBJDATA[10] = Rot.x;
		OBJDATA[11] = Rot.y;
		OBJDATA[12] = Rot.z;
		OBJDATA[13] = Rot.w; // 1.0
		OBJDATA[14] = 2; //
		float flt_1800 = 1800;
		OBJDATA1[0] = 2;
		OBJDATA1[1] = *(int*)&flt_1800;
		OBJDATA[15] = (int)&OBJDATA1; //Params I guess
		int no_ref = 0; //CLASS PROP
		int InstancePROP =  BranchTo(0x8245A080,int,malloc06(0x14),PropManger,OBJDATA,&unk_ref_2);
		int obj_index = 100;
		int EntityHandle = BranchTo(0x82461128,int,malloc06(0x1c),PropManger,obj_index);
		char buffer[0x30];
		int tunux = 0;
		BranchTo(0x8245C680,int,&buffer,&InstancePROP,&EntityHandle,0,&std::string("dashpanel"));
		int result = BranchTo(0x824619C8,int,(*PropManger)[0xF], "dashpanel", buffer);

		*/



		lua_pushlightuserdata(L,(void*)0);

		return 1;
	}

	int GameLIB_GlobalInstall(lua_State* LS)
	{	
		WRITE_DWORD(0x82026A04,GameLIB_NewActorRestore);
		return 0;
	}


	int PlayerLIB_GlobalInstall(lua_State* LS)
	{
		luaL_openlib06(LS,"player",PET,0);


		lua_register06(LS,"Player",Player_NEW);
		luaL_newmetatable06(LS,"Player");


		lua_pushstring06(LS, "__gc"); lua_pushcfunction06(LS, Player___GC); lua_settable06(LS, -3);

		lua_pushvalue(LS, -1);  lua_pushstring06(LS, "__index"); lua_pushvalue(LS,-2);  lua_settable06(LS,-3);

		lua_pushstring06(LS, "GetPTR"); lua_pushcfunction06(LS, Player_GetPTR); 	lua_settable06(LS, -3);

		lua_pushstring06(LS, "Reload"); lua_pushcfunction06(LS, Player_RELOAD); 	lua_settable06(LS, -3);

		lua_pushstring06(LS, "Swap"); lua_pushcfunction06(LS, Player_SWAP); 	lua_settable06(LS, -3);

		lua_pushstring06(LS, "OpenPostureControl"); lua_pushcfunction06(LS, Player_OpenPostureControl); 	lua_settable06(LS, -3);
		lua_pushstring06(LS, "OpenInput"); lua_pushcfunction06(LS, Player_OpenInput); 	lua_settable06(LS, -3);
		lua_pushstring06(LS, "OpenPackage"); lua_pushcfunction06(LS, Player_OpenPackage); 	lua_settable06(LS, -3);
		lua_pushstring06(LS, "OpenModel"); lua_pushcfunction06(LS, Player_OpenModel); 	lua_settable06(LS, -3);
		lua_pushstring06(LS, "OpenFrame"); lua_pushcfunction06(LS, Player_OpenFrame); 	lua_settable06(LS, -3);


		lua_pop(LS,1);

		return 1;

	

		



		lua_pop(LS,1);



		return 0;
	}

	
	// Free MyObject instance by Lua garbage collection
	static int Player___GC(lua_State* L){
//		delete *reinterpret_cast<Player_NEWS**>(lua_touserdata(L, 1));
		return 0;
	}
	extern "C" Player_RELOAD(lua_State* L){
	
		Player_NEWS* PE = (*reinterpret_cast<Player_NEWS**>(luaL_checkudata(L, 1, "Player")));
		UINT32 pstack[4];
		GetPlayerActors((UINT32*)&pstack);
		PE->ObjectPlayer = (int*) pstack[PE->Index];


		return 0;
	}

	extern "C" Player_GetPTR(lua_State* L)
	{


		Player_NEWS* PE = (*reinterpret_cast<Player_NEWS**>(luaL_checkudata(L, 1, "Player")));
		lua_pushlightuserdata(L,(void*)PE->ObjectPlayer);;

		return 1;

	}



	extern "C" Player_NEW(lua_State* L)
	{


		int args = lua_gettop(L);
		
		Player_NEWS* z = (Player_NEWS*)malloc06(0x8);
		if (args > 0){
			z->Index = lua_tonumber(L,1);
		}
		

		UINT32 pstack[4];
		GetPlayerActors((UINT32*)&pstack);
		z->ObjectPlayer = (int*) pstack[z->Index];
	

	
		*reinterpret_cast<Player_NEWS**>(lua_newuserdata06(L, sizeof(Player_NEWS*))) = z;

		luaL_getmetatable06(L,"Player");
		lua_setmetatable06(L, -2);
		

		

		return 1;

	}



	extern "C" Player_SWAP(lua_State* L){

		int args = lua_gettop(L);
		if (args <= 1) return 0;

		const char* chara = lua_tostring(L,2);

		Player_NEWS* PE = (*reinterpret_cast<Player_NEWS**>(luaL_checkudata(L, 1, "Player")));
		//PE->ObjectPlayer
			
		BranchTo(0x82195D20,int,PE->ObjectPlayer,chara);
		return 0;


	}
	

	extern "C" Player_OpenFrame(lua_State* L){

		Player_NEWS* PE = (*reinterpret_cast<Player_NEWS**>(luaL_checkudata(L, 1, "Player")));
		_DWORD ObjPlayer =  (_DWORD)PE->ObjectPlayer;
		int index = 0;



	
		int v2 = ObjPlayer;
		int v3 = malloc06(0x160);
		int v5;
		if ( v3 )
		{
	
			int v4 = 	BranchTo(0x8223B458,int,v3);
			v5 = v4;
			if ( v4 )
			{
				BranchTo(0x82659610,int,v4);

				XMMATRIX matrix = XMMATRIX(1,0,0,0,
										   0,1,0,0,
										   0,0,1,0,
										   0,0,0,1);
							
				
				BranchTo(0x8223B208,int,v5,&matrix);
			
			
			}
		}
		else
		{
			v5 = 0;
		}
		if ( *(_DWORD *)(v2 + 0x154)  )
		{
			int v8 = v5;
			if ( v5 )
				BranchTo(0x82659610,int,v5);
			(*(void (__fastcall **)(_DWORD, int *))(**(_DWORD **)(v2 + 0x154) + 0xC))(*(_DWORD *)(v2 + 0x154), &v8);
			if ( v8 )
				BranchTo(0x82581E38 ,int,v8);
		}
		if ( v5 )
			BranchTo(0x82659610,int,v5);
		_DWORD v6 = *(_DWORD *)(v2 + 0xCC);
		*(_DWORD *)(v2 + 0xCC) = v5;
		if ( v6 )
			BranchTo(0x82581E38 ,int,v6);
		if ( v5 )
			BranchTo(0x82581E38 ,int,v5);
	
	
	


		return 0;
	}




	extern "C" Player_OpenModel(lua_State* L){

		Player_NEWS* PE = (*reinterpret_cast<Player_NEWS**>(luaL_checkudata(L, 1, "Player")));
		_DWORD ObjPlayer =  (_DWORD)PE->ObjectPlayer;
		int index = 0;
	
		int v25[2];
		int v31[2];
		int v8;
		v31[0] = 0;
		v31[1] = 0;


		v25[0] = 0;
		v8 = (int)malloc06(0xC8);
		int v5 = 0; //FLAG
		int v9;
		int v10;
		if ( v8 )
		{
			v25[1] = *(_DWORD *)(ObjPlayer + 0xCC);
			if ( v25[1] )
				BranchTo(0x82659610,int,v25[1]);
			v5 = 1;
		
			int AnimationTableSetup  = 0x820032C0 + (0xC * v25[0]);


			v9 = BranchTo(0x822392D8,int,v8,*(_DWORD *)(ObjPlayer + 0x154), &v25[1], AnimationTableSetup);
		}
		else
		{
			v9 = 0;
		}
		v31[0] = v9;
		BranchTo(0x821C04B0,int,&v31[1],v9,0);
		if ( (v5 & 1) != 0 && v25[1] )
			BranchTo(0x82581E38,int,v25[1]);
		BranchTo(0x821B8F28,int,ObjPlayer,v31,2u);

		*(_DWORD *)(ObjPlayer + 0xD4) = v31[0];
		BranchTo(0x821600C0,int,ObjPlayer + 0xD8,&v31[1]);

		v10 = v31[1];
		if ( v10 )
			BranchTo(0x821601B8,int,v10);

		int v51[2];
		v51[0] =0;
		v51[1] = 0;

		v51[0] = *(_DWORD *)(ObjPlayer + 0x154);
		BranchTo(0x82160248,int,&v51[1],(int *)(ObjPlayer + 0x158));
		BranchTo(0x821BFA70,int,ObjPlayer + 0x114,v51);

		if ( v51[1] )
			sub_821601B8(v51[1]);

		int v43 = *(_DWORD *)(ObjPlayer + 0xDC);
		if ( v43  )
		{
			XMMATRIX matrix;
			//BranchTo(0x821F1A18,int,v43,&matrix); POS
		
		}
		//TODO ELSE
		//BranchTo(0x82195B98,int,ObjPlayer);



		int v60[2];
		v60[0] = 0;
		v60[1] = 0;
		//BranchTo(0x8219FBB8,int,v60,(int *)(ObjPlayer + 0x144));

		if ( v60[0]  )
		{
			//(*(void (__fastcall **)(int, int))(*(_DWORD *)v60[0] + 0x18))(v60[0], *(_DWORD *)(ObjPlayer + 0x1F4));
		}

	//	if ( v61[1] )
	//		sub_821601B8(v61[1]);
		BranchTo(0x821966E0,int,ObjPlayer);
		BranchTo(0x82196CF8,int,ObjPlayer);
		BranchTo(0x82196768,int,ObjPlayer);















		
		return 0;
	}




	extern "C" Player_OpenPackage(lua_State* L){

		Player_NEWS* PE = (*reinterpret_cast<Player_NEWS**>(luaL_checkudata(L, 1, "Player")));
		_DWORD ObjPlayer =  (_DWORD)PE->ObjectPlayer;

		const char* v3 = lua_tostring(L, 2);
		if ( v3 ){


			std::string* S1 =  (std::string *)(ObjPlayer + 0x74); S1->assign(v3);
			int v6 = *(_DWORD *)(ObjPlayer + 0x154);
			if ( v6 )
			{
		
				{
					int v11[8];
					int* v7 = (int *)(*(int (__fastcall **)(int *, int, int))(*(_DWORD *)v6 + 4))(v11, v6, ObjPlayer + 0x74);
					int v8 = *v7;
		
				
					Sonicteam::SoX::RefCountObject* v9 = *(	Sonicteam::SoX::RefCountObject*  *)(ObjPlayer + 0xD0);
					*(_DWORD *)(ObjPlayer + 0xD0) = v8;
					if ( v9 )
						v9->LoseObject();
				
				}
			}
		}
		return 0;
	}




	extern "C" Player_OpenInput(lua_State* L)
	{

		Player_NEWS* PE = (*reinterpret_cast<Player_NEWS**>(luaL_checkudata(L, 1, "Player")));
		_DWORD ObjPlayer =  (_DWORD)PE->ObjectPlayer;



	

		int AllocatedInputMemDebug = (int)malloc06(0x70);
		int boostContainer[2];

		boostContainer[0]= 0;
		boostContainer[1]= 0;


		if ( AllocatedInputMemDebug )
		{
			int v12 = (int)(ObjPlayer + 8);
			if ( !ObjPlayer )
				v12 = 0;

			int AllocatedInputMemDebugT = BranchTo(0x822219F0,int,AllocatedInputMemDebug,(int)(ObjPlayer + 0x25),v12);
			BranchTo(0x821B8868,int,boostContainer,AllocatedInputMemDebugT);


			BranchTo(0x821B8A28,int,ObjPlayer,&boostContainer,0u);
			if ( boostContainer[1] ) sub_821601B8(boostContainer[1]);
	
		}






		return 0;
	}

	extern "C" Player_OpenPostureControl(lua_State* L)
	{

		Player_NEWS* PE = (*reinterpret_cast<Player_NEWS**>(luaL_checkudata(L, 1, "Player")));
		_DWORD ObjPlayer =  (_DWORD)PE->ObjectPlayer;



		int AllocatedPostureDebugMem = (int)malloc06(0x140);
		int AllocatedPostureDebugMemT;
		int v40[2];
		int BoostAllocatedPostureDebugMem[2];
		BoostAllocatedPostureDebugMem[0] = 0;
		BoostAllocatedPostureDebugMem[1] = 0;
		int flag = 8;
		int DRefCountObj1;
		int* DRefCountObj;
		if ( AllocatedPostureDebugMem )
		{
			Sonicteam::SoX::RefCountObject* DRefCountObj0 = *(Sonicteam::SoX::RefCountObject**)(ObjPlayer + 0xCC);
			if ( DRefCountObj0 )
				DRefCountObj0->GetObject<int>(); //add ref
			int* v15 = BranchTo(0x823D0E88,int*,(int)v40, ObjPlayer);
			int flag = 8;
			DRefCountObj = (int *)(*(int (__fastcall **)(int *,int))(**(_DWORD **)v15 + 0x18))(&DRefCountObj1,*v15);

	
			AllocatedPostureDebugMemT = BranchTo(0x821F75E0,int,(int)AllocatedPostureDebugMem, DRefCountObj, &DRefCountObj0);
			BranchTo(0x821B9498,int,BoostAllocatedPostureDebugMem, AllocatedPostureDebugMem);
				if ( (flag & 8) != 0 && v40[1] )
					sub_821601B8(v40[1]);

		}
		else
		{
			AllocatedPostureDebugMemT = 0;
		}



		BranchTo(0x821B95E8,int,ObjPlayer,BoostAllocatedPostureDebugMem,1u);
		*(_DWORD *)(ObjPlayer + 0xDC) = BoostAllocatedPostureDebugMem[0];
		int v28 = BoostAllocatedPostureDebugMem[1];
		if ( BoostAllocatedPostureDebugMem[1] )
			BranchTo(0x82160140,int,BoostAllocatedPostureDebugMem[1]);

		int v29 = *(_DWORD *)(ObjPlayer + 0xE0);
		if ( v29 )
			BranchTo(0x821601B8,int,v29);

		*(_DWORD *)(ObjPlayer + 0xE0) = v28;




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


	//Size 4
	void GetPlayerActors(UINT32* pstack){
	
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
					if (IsObjectPlayerHaveControll){
						pstack[PIX++] = Actor;
					}
					/*
					Sonicteam::Player::State::IMachine* PlayerMashine = *(Sonicteam::Player::State::IMachine**)(Actor+0xE4);
					if (PlayerMashine){

						Sonicteam::Player::State::IContext* context  =  PlayerMashine->GetMashineContext().get();
						Sonicteam::Player::State::CommonContext* PCC0 = dynamic_cast<Sonicteam::Player::State::CommonContext*>(context);
						Sonicteam::Player::State::FastContext* PCF0 = dynamic_cast<Sonicteam::Player::State::FastContext*>(context);
						bool flag = false;
						if (PCC0){
							Sonicteam::Player::Input::IListener* Listener =  PCC0->ListenerNormalInputPlugin.get();
							flag =  Listener->Listener5();
							
						}
						else if (PCF0){
							Sonicteam::Player::Input::IListener* Listener =  PCF0->ListenerNormalInputPlugin.get();
							flag = Listener->Listener5();
						}

						if (flag ) pstack[PIX++] = Actor;
					}
					*/


				}
			}
		}
	}

	UINT32 GetPlayerPosture(UINT32 ObjectPlayer){
		return *(UINT32 *)(ObjectPlayer + 0xDC);
	}
	XMFLOAT4* GetPlayerPosition(UINT32 PlayerPosture){
		return (XMFLOAT4*)(PlayerPosture + 0xB0);
	}



	extern "C" int GetPlayerPosition(lua_State* L){

		int n = lua_gettop(L);  
		if (n <= 0) 
		{lua_pushnumber(L, 0); return 1;}

		UINT32 PlayerIndex = (UINT32)lua_tonumber(L,1);

		UINT32 pstack[4] = {};
		GetPlayerActors((UINT32*)&pstack);

		XMFLOAT4 POS;
		if (pstack[PlayerIndex] != 0){
			UINT32 ObjectPlayer = pstack[PlayerIndex];
			UINT32 PlayerPosture = GetPlayerPosture(ObjectPlayer);
			XMFLOAT4* PlayerPos = GetPlayerPosition(PlayerPosture);
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


	





	

	extern "C" int SetPlayerPosition(lua_State* L)
	{

		int n = lua_gettop(L);  
		if (n <= 0) return 0;
		UINT32 PlayerIndex = (UINT32)lua_tonumber(L,1);
		UINT32 pstack[4] = {};



		GetPlayerActors((UINT32*)&pstack);

		XMFLOAT4 POS;
		if (pstack[PlayerIndex] != 0){
			UINT32 ObjectPlayer = pstack[PlayerIndex];
			UINT32 PlayerPosture = GetPlayerPosture(ObjectPlayer);
			XMFLOAT4* PlayerPos = GetPlayerPosition(PlayerPosture);
			PlayerPos->x = lua_tonumber(L,2);
			PlayerPos->y = lua_tonumber(L,3);
			PlayerPos->z = lua_tonumber(L,4);


		}


	





		return 0;
	}

	int STRLIB_GlobalInstall(lua_State* LS)
	{
		luaopen_string_06(LS);
		return 0;
	}



	static const struct luaL_reg MEM [] = {
		{"ADD",Memory_ADD},
		{"GetPointer", Memory_GetPointer},
		{"SetPointerValue", Memory_SetPointerValue},
		{"SetBYTE", Memory_SetBYTE},
		{"GetBYTE", Memory_GetBYTE},
		{"SetDWORD", Memory_SetDWORD},
		{"GetDWORD", Memory_GetDWORD},
		{"SetFLOAT", Memory_SetFLOAT},
		{"GetFLOAT", Memory_GetFLOAT},
		{NULL, NULL}  /* sentinel */
	};



	int MemoryLIB_GlobalInstall(lua_State* LS)
	{
		luaL_openlib06(LS,"memory",MEM,0);
		return 0;
	}


	extern "C" Memory_GetBYTE(lua_State* L){

		int args = lua_gettop(L);
		UINT ptr = 0;
		UINT mv = 0; 

		if (args < 1){ lua_pushnil(L); return 1;}

		if (lua_isuserdata(L,1)){
			ptr = (UINT)lua_touserdata(L,1);
		}

		else{
			ptr = (UINT)lua_tonumber(L,1);
		}

		if (args > 1){
			mv = (UINT)lua_tonumber(L,2);
		}

	
		if ((ptr + mv) > mv && (ptr + mv) != 0 ){
			lua_pushnumber(L,*(char*)(ptr + mv));
		}
		else{
			lua_pushnil(L);
		}
		return 1;
	}
	extern "C" Memory_SetBYTE(lua_State* L){

		int args = lua_gettop(L);
		UINT ptr = 0;
		if (args < 2) return 0;

		if (lua_isuserdata(L,1)){
			ptr = (UINT)lua_touserdata(L,1);
		}
		else{
			ptr = lua_tonumber(L,1);
		}

		*(char*)(ptr) =  lua_tonumber(L,2);

		return 0;
	}

	extern "C" Memory_GetDWORD(lua_State* L){

		int args = lua_gettop(L);
		UINT ptr = 0;
		UINT mv = 0; 

		if (args < 1){ lua_pushnil(L); return 1;}

		if (lua_isuserdata(L,1)){
			ptr = (UINT)lua_touserdata(L,1);
		}

		else{
			ptr = (UINT)lua_tonumber(L,1);
		}

		if (args > 1){
			mv = (UINT)lua_tonumber(L,2);
		}

		if ((ptr + mv) > mv && (ptr + mv) != 0 ){
			lua_pushnumber(L,*(int*)(ptr + mv));
		}
		else{
			lua_pushnil(L);
		}
		return 1;
	}
	extern "C" Memory_SetDWORD(lua_State* L){

		int args = lua_gettop(L);
		UINT ptr = 0;
		if (args < 2) return 0;

		if (lua_isuserdata(L,1)){
			ptr = (UINT)lua_touserdata(L,1);
		}
		else{
			ptr = lua_tonumber(L,1);
		}

		*(unsigned int*)(ptr) =  lua_tonumber(L,2);
		
	
		return 0;
	}
	extern "C" Memory_GetFLOAT(lua_State* L){

		int args = lua_gettop(L);
		UINT ptr = 0;
		UINT mv = 0; 

		if (args < 1){ lua_pushnil(L); return 1;}

		if (lua_isuserdata(L,1)){
			ptr = (UINT)lua_touserdata(L,1);
		}

		else{
			ptr = (UINT)lua_tonumber(L,1);
		}

		if (args > 1){
			mv = (UINT)lua_tonumber(L,2);
		}



		void* result_ptr = 0;
		if ((ptr + mv) > mv && (ptr + mv) != 0 ){
			result_ptr = *(void**)(ptr + mv);
		}

		if ((ptr + mv) > mv && (ptr + mv) != 0 ){
			lua_pushnumber(L,*(float*)(ptr + mv));
		}
		else{
			lua_pushnil(L);
		}
		return 1;
	}
	extern "C" Memory_SetFLOAT(lua_State* L){

		int args = lua_gettop(L);
		UINT ptr = 0;
		if (args < 2) return 0;

		if (lua_isuserdata(L,1)){
			ptr = (UINT)lua_touserdata(L,1);
		}
		else{
			ptr = lua_tonumber(L,1);
		}
		*(float*)(ptr) =  lua_tonumber(L,2);
		return 0;
	}




	extern "C" Memory_GetPointer(lua_State* L){

		int args = lua_gettop(L);
		UINT ptr = 0;
		UINT mv = 0; 

		if (args < 1){ lua_pushnil(L); return 1;}

		if (lua_isuserdata(L,1)){
			ptr = (UINT)lua_touserdata(L,1);
		}
	
		else{
			ptr = (UINT)lua_tonumber(L,1);
		}
		
		if (args > 1){
			mv = (UINT)lua_tonumber(L,2);
		}
		


		void* result_ptr = 0;
		if ((ptr + mv) > mv && (ptr + mv) != 0 ){
			result_ptr = *(void**)(ptr + mv);
		}
		
		if ((ptr + mv) > mv && (ptr + mv) != 0 ){
			lua_pushlightuserdata(L,*(void**)(ptr + mv));
		}
		else{
			lua_pushnil(L);
		}
		return 1;
	}
	extern "C" Memory_ADD(lua_State* L){

		int args = lua_gettop(L);
		UINT ptr = 0;
		UINT mv = 0; 

		if (args < 2){ lua_pushnil(L); return 1;}

		if (lua_isuserdata(L,1)){
			ptr = (UINT)lua_touserdata(L,1);
		}

		else{
			ptr = (UINT)lua_tonumber(L,1);
		}

		if (lua_isuserdata(L,2)){
			mv = (UINT)lua_touserdata(L,2);
		}

		else{
			mv = (UINT)lua_tonumber(L,2);
		}

		lua_pushlightuserdata(L,(void*)(ptr+mv));


		return 1;
	}
	extern "C" Memory_SetPointerValue(lua_State* L){

		int args = lua_gettop(L);
		UINT ptr = 0;

		UINT mv = 0;
		if (args < 2) return 0;

		if (lua_isuserdata(L,1)){
			ptr = (UINT)lua_touserdata(L,1);
		}
		else{
			ptr = lua_tonumber(L,1);
		}

		bool isString = false;
		if (lua_isuserdata(L,2)){
			mv = (UINT)lua_touserdata(L,2);
		}
		else if (lua_isstring(L,2)){
			mv = (UINT)lua_tostring(L,2);
			isString = true;
		}
		else{
			mv = lua_tonumber(L,2);
		}

		if (isString){
		
			strcpy((char*)ptr,(char*)mv);
		}
		else{
			*(UINT*)(ptr) = mv;
		}


		return 0;
	}





}