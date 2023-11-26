#include "LuaSystem.h"


using namespace Sonicteam;


//Complete Later
LuaSystem::LuaSystem(void):LuaNodeImp(0,0),Sonicteam::SoX::IResource2<LuaSystem,LuaSystemManager>()
{
	

}

LuaSystem::~LuaSystem(void)
{

}

float Sonicteam::LuaSystem::GetFloatValue(std::string* nm)
{

	if (this->LuaNodeUnknown0x0A((char*)nm->c_str())){

		return LuaNodeUnknown0x0D((char*)nm->c_str());

	}

	return 0.0;

}

