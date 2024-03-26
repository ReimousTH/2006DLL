#include "LuaExtension_StateMachine2.h"



#define SM2LIB_NAME_META "StateIMachineMeta"
#define SM2LIB_NAME "StateIMachine"


#include <Player/State/IMachine.h>


namespace DebugLogV2{







	void GlobalInstall_StateMachine2(lua_State* LS)
	{

		
		lua_register06(LS, SM2LIB_NAME, StateMachine2__NEW);
		luaL_newmetatable06(LS, SM2LIB_NAME_META);

	
//		lua_pushstring06(LS,"ID"); lua_pushnumber(LS,0); lua_settable06(LS,-3); // ID = 0
//		lua_pushstring06(LS,"ActorPTR"); lua_pushlightuserdata(LS,0); lua_settable06(LS,-3); // ActorPTR = 0
//		lua_pushstring06(LS,"AI"); lua_pushboolean(LS,false); lua_settable06(LS,-3); // AI = 0

	
		lua_newtable06(LS);lua_pushstring06(LS, "__index");luaL_getmetatable06(LS, "MemoryMeta");lua_settable06(LS, -3); lua_setmetatable06(LS, -2); //setmetatable(StateMashineMeta, { __index = MemoryMeta })

		lua_pushstring06(LS, "GetIMachine");lua_pushcfunction06(LS, StateIMachine__GetIMachine);lua_settable06(LS, -3); // Equivalent to table["GetIMachine"] = StateIMachine__SetStateID
		lua_pushstring06(LS, "AddState");lua_pushcfunction06(LS, StateIMachine__AddState);lua_settable06(LS, -3); // Equivalent to table["AddState"] = StateIMachine__GetStateID
		lua_pushstring06(LS, "RemoveStateByID");lua_pushcfunction06(LS, StateIMachine__RemoveStateByID);lua_settable06(LS, -3); // Equivalent to table["RemoveStateByID"] = StateIMachine__GetStateID
		lua_pushstring06(LS, "OnStateConnect");lua_pushcfunction06(LS, StateMachine2__OnStateConnect);lua_settable06(LS, -3); // Equivalent to table["RemoveStateByID"] = StateIMachine__GetStateID
		

		
		lua_pop(LS,1);
		

		return;
	

	}


	extern "C" int StateMachine2__CreateMetatable(lua_State* L,int ptr){
		


		lua_getglobal06(L, "Memory");
		lua_pushvalue(L,1); //LuaFirstArg
		lua_pcall06(L, 1, 1, 0); // Memory(ptr) -> {}::Memory


		// Second table for metatable set
		lua_newtable06(L);
		lua_pushstring06(L, "__index");luaL_getmetatable06(L, SM2LIB_NAME_META);lua_settable06(L, -3); // { __index = MemoryMeta }
		lua_setmetatable06(L, -2); // setmetatable(self, { __index = MemoryMeta })


	


		return 1;
	}
	extern "C" int StateMachine2__NEW(lua_State* L)
	{
		StateMachine2__CreateMetatable(L,0);
		return 1;
	}

	



	extern "C" int StateIMachine__GetIMachine(lua_State* L)
	{
		lua_pushstring06(L,"ptr");
		lua_gettable(L,1);

		Sonicteam::Player::State::Machine2* ptr = (Sonicteam::Player::State::Machine2* )lua_touserdata(L,-1);
		if (Sonicteam::Player::State::IMachine* machine = dynamic_cast<Sonicteam::Player::State::IMachine*>(ptr)){

			lua_getglobal06(L, "StateIMachine");
			lua_pushlightuserdata(L,machine); //LuaFirstArg
			lua_pcall06(L, 1, 1, 0); // StateIMachine(ptr) -> {}::Memory
		}
		else{
			lua_pushnil(L);
		}

		return 1;
	}

	extern "C" int StateIMachine__AddState(lua_State* L)
	{

		lua_pushstring06(L,"ptr");
		lua_gettable(L,1);

		Sonicteam::Player::State::Machine2* ptr = (Sonicteam::Player::State::Machine2* )lua_touserdata(L,-1);
		std::vector<std::pair<int,StateConstructorEX>>* vec = (std::vector<std::pair<int,StateConstructorEX>>*)&ptr->MashineStates;
		int StateID =0;
		StateID = lua_tonumber(L,2);
		vec->push_back(std::pair<int,StateConstructorEX>(StateID,&LuaLCommonObjectBoost));
		
		lua_pushvalue06(L,3);
		int ref = luaL_ref(L,LUA_REGISTRYINDEX);
		

	
		CachedStates[dynamic_cast<Sonicteam::Player::State::IMachine*>(ptr)][StateID] = LuaLCommonObjectSave(L,ref);


		return 0;
	}

	extern "C" int StateIMachine__RemoveStateByID(lua_State* L)
	{
		return 0;
	}

	extern "C" int StateMachine2__OnStateConnect(lua_State*L)
	{
		int args = lua_gettop(L);
		const char* arg1 = lua_tostring(L,1);
		int StateID = lua_tonumber(L,2);

		int _type = 0;

		if (arg1 == "OnStart"){
			_type = 1;
		}
		else if (arg1 == "OnUpdate"){
			_type = 2;
		}
		else if (arg1 == "OnEnd"){
			_type = 3;
		}


		lua_pushstring06(L,"ptr");
		lua_gettable(L,1);
		Sonicteam::Player::State::Machine2* ptr = (Sonicteam::Player::State::Machine2* )lua_touserdata(L,-1);

		lua_pushvalue06(L,3);
		int ref = luaL_ref(L,LUA_REGISTRYINDEX);

		CachedStatesConnect[dynamic_cast<Sonicteam::Player::State::IMachine*>(ptr)][StateID][_type].push_back(LuaLCommonObjectSaveC(L,ref,_type));


		return 0;




	}

}
