#pragma once

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

#include "Head.h"
#include "MessagesUtil.h"
#include <xtl.h>

#include <Player/Input/IListener.h>
#include <Player/State/IMachine.h>
#include <Player/State/CommonContext.h>
#include <Player/State/FastContext.h>

#define _DWORD DWORD
#define _BYTE BYTE


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



	
	int VectorLIB_GlobalInstall(lua_State* LS);
	extern "C" Vector_NEW(lua_State* L);
	extern "C" Vector__GC(lua_State* L);
	extern "C" Vector__tostring(lua_State* L);
	extern "C" Vector_GetTable(lua_State* L);


	extern "C" Vector__add(lua_State* L);
	extern "C" Vector__sub(lua_State* L);


	int GameLIB_GlobalInstall(lua_State* LS);

	int PlayerLIB_GlobalInstall(lua_State* LS);

	struct Player_NEWS{
		int* ObjectPlayer;
		int Index;
	};




	static int Player___GC(lua_State* L);
	extern "C" Player_RELOAD(lua_State* L);
	extern "C" Player_GetPTR(lua_State* L);
	extern "C" Player_NEW(lua_State* L);
	extern "C" Player_SWAP(lua_State* L);

	extern "C" Player_OpenFrame(lua_State* L);
	extern "C" Player_OpenModel(lua_State* L);
	extern "C" Player_OpenPackage(lua_State* L);
	extern "C" Player_OpenInput(lua_State* L);
	extern "C" Player_OpenPostureControl(lua_State* L);

	void GetPlayerActors(UINT32* pstack);
	UINT32 GetPlayerPosture(UINT32 ObjectPlayer);
	XMFLOAT4* GetPlayerPosition(UINT32 PlayerPosture);
	extern "C" Player_NEW(lua_State* L);
	extern "C" static int GetPlayerRawInput(lua_State* L);
	extern "C" int GetPlayerInput(lua_State* L);
	extern "C" int PrintNext(lua_State* L);
	extern "C" int GetPlayerPosition(lua_State* L);
	extern "C" int SetPlayerPosition(lua_State* L);





	int STRLIB_GlobalInstall(lua_State* LS);
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