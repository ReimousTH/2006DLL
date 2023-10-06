#pragma once

#include <string>
#include "SoX/IResource2.h"
#include "LuaSystemManager.h"
#include "LuaNodeImp.h"



#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>

namespace SonicTeam{

	
 
		//TODO (STATIC CLASS)
	   class LuaSystem:public LuaNodeImp,public SonicTeam::SoX::IResource2<LuaSystem,LuaSystemManager> // : LuaNode + (again hided in destructors omg)
		{
		public:
			LuaSystem(void);
			~LuaSystem(void);
		
			
		};

}
