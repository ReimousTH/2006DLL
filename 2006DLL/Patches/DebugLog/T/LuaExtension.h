#pragma once

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

#include <Head.h>
#include "MessagesUtil.h"






namespace DebugLogV2{




#pragma region BitLib

	extern "C" static int BitBaseEXY(lua_State*L,int cs);
	extern "C" static int BIT_ShiftLeftEXY(lua_State* L);
	extern "C" static int BIT_ShiftRightEXY(lua_State* L);
	extern "C" static int BIT_ANDEXY(lua_State* L);
	extern "C" static int BIT_OREXY(lua_State* L);



	static const struct luaL_reg BitLIBX [] = {
		{"AND", BIT_ANDEXY}
	};


#pragma endregion BitLib


#pragma region Clases

#pragma  region DebugLabel
	// Create & return MyObject instance to Lua


	extern "C" static int DebugLabel_GlobalInstall(lua_State* LS);

	static int DebugLabel_new(lua_State* L);

	extern "C" static int DebugLabel_delete(lua_State* L);

	extern "C" static int DebugLabel_SetText(lua_State* L);


	extern "C" static int DebugLabel_SetPosition(lua_State* L);
#pragma endregion DebugLabel




#pragma endregion Clases




}

