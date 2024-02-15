#include "LuaExtension.h"

namespace DebugLogV2{

extern "C" int BitBaseEXY(lua_State*L,int cs)
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







extern "C" int BIT_ShiftLeftEXY(lua_State* L)
{
	return BitBaseEXY(L,0);
}

extern "C" int BIT_ShiftRightEXY(lua_State* L)
{
	return BitBaseEXY(L,1);
}

extern "C" int BIT_ANDEXY(lua_State* L)
{
	return BitBaseEXY(L,2);
}

extern "C" int BIT_OREXY(lua_State* L)
{
	return BitBaseEXY(L,3);
}


extern "C" int DebugLabel_GlobalInstall(lua_State* LS)
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

int DebugLabel_new(lua_State* L)
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

extern "C" int DebugLabel_delete(lua_State* L)
{

	BranchTo(0x8262BA68,int,*reinterpret_cast<int**>(lua_touserdata(L, 1)),1); //Destroy from mem

	return 0;
}

extern "C" int DebugLabel_SetText(lua_State* L)
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

extern "C" int DebugLabel_SetPosition(lua_State* L)
{


	int* TextEntity = (*reinterpret_cast<int**>(luaL_checkudata(L, 1, "DebugLabel")));
	UINT ud = (UINT)TextEntity;
	float x  = lua_tonumber(L,2);
	float y = lua_tonumber(L,3);
	ChangeMessagePosition(ud,x,y);
	return 0;
}

}