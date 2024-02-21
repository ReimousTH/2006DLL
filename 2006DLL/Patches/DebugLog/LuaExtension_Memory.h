#pragma once


extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

#include "Head.h"
#include "MessagesUtil.h"
#include <xtl.h>

#include <iostream>
#include <map>

#include <string>


#include <Player/Input/IListener.h>
#include <Player/State/IMachine.h>
#include <Player/State/CommonContext.h>
#include <Player/State/FastContext.h>


#include <boost/any.hpp>


#define _DWORD DWORD
#define _BYTE BYTE


namespace DebugLogV2 {



	int MemoryLIB_GlobalInstall(lua_State* LS);
	extern "C" Memory_GetPointer(lua_State* L);
	extern "C" Memory_ADD(lua_State* L);
	extern "C" Memory_SetPointerValue(lua_State* L);
	extern "C" Memory_GetDWORD(lua_State* L);
	extern "C" Memory_SetDWORD(lua_State* L);
	extern "C" Memory_GetFLOAT(lua_State* L);
	extern "C" Memory_SetFLOAT(lua_State* L);
	extern "C" Memory_GetBYTE(lua_State* L);
	extern "C" Memory_SetBYTE(lua_State* L);

	
}