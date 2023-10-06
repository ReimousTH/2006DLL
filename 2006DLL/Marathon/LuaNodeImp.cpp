#include "LuaNodeImp.h"


using namespace SonicTeam;

LuaNodeImp::LuaNodeImp(lua_State* l,char* f)
{
	this->Lua_State = l;
	this->TablePath.assign(f,strlen(f));
}

LuaNodeImp::~LuaNodeImp(void)
{

}
