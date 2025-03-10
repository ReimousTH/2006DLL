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
#include <tchar.h>
#include <map>
#include <string>



#include <Player/Input/IListener.h>
#include <Player/State/IMachine.h>
#include <Player/State/CommonContext.h>
#include <Player/State/FastContext.h>


#include <boost/any.hpp>


namespace DebugLogV2 {



	int Uint64LIB_GlobalInstall(lua_State* LS);



	extern "C" Uint64__NEW(lua_State* L);
	extern "C" Uint64__CreateMetatable(lua_State* L,int value,int move);




	
}