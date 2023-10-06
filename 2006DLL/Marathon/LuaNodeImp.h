#pragma once

#include <string>
extern "C" {
#include "lua.h"
}


#include "LuaNode.h"

#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>

namespace SonicTeam{
 
	//Do implementation later :)
	class LuaNodeImp:public LuaNode // : LuaNode + (again hided in destructors omg)
	{
	public:
		LuaNodeImp(lua_State*,char*);	
		virtual ~LuaNodeImp(void);





		//fields



	//	lua_State* Lua_State;
	//	std::string TablePath;  //Registry/DemoCamera =  Registry.DemoCamera in short


	};

}
