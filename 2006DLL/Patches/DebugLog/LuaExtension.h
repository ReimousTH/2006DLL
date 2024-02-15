#pragma once

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

#include "Head.h"
#include "MessagesUtil.h"

#include <Player/Input/IListener.h>
#include <Player/State/IMachine.h>
#include <Player/State/CommonContext.h>

namespace DebugLogV2 {
	extern "C" void DebugLabel_GlobalInstallX(lua_State* LS);

	int BitLibGlobalInstall(lua_State* L);
	int BitBaseEXY(lua_State* L, int cs);
	int BIT_ShiftLeftEXY(lua_State* L);
	int BIT_ShiftRightEXY(lua_State* L);
	int BIT_ANDEXY(lua_State* L);
	int BIT_OREXY(lua_State* L);

	int DebugLabel_GlobalInstall(lua_State* LS);
	int DebugLabel_new(lua_State* L);
	int DebugLabel_delete(lua_State* L);
	int DebugLabel_SetText(lua_State* L);
	int DebugLabel_SetPosition(lua_State* L);


	int PlayerLIB_GlobalInstall(lua_State* LS);
	extern "C" static int GetPlayerRawInput(lua_State* L);
	extern "C" int GetPlayerInput(lua_State* L);
	extern "C" int PrintNext(lua_State* L);
	extern "C" int GetPlayerPosition(lua_State* L);



	int STRLIB_GlobalInstall(lua_State* LS);
	int MemoryLIB_GlobalInstall(lua_State* LS);
}