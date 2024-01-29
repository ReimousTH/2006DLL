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

float Sonicteam::LuaSystem::GetFloatValue(std::string& nm)
{

	if (this->LuaNodeUnknown0x0A((char*)nm.c_str())){

		return LuaNodeUnknown0x0D((char*)nm.c_str());

	}
	return 0.0;

}


LuaSystem* Sonicteam::LuaSystem::LoadInitResource(LuaSystem*& value,std::string& path)
{
	return 	((Sonicteam::LuaSystem* (__fastcall *)(...))0x82163620)(&value,&path);
}

