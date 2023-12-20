#include "IContext.h"

using namespace Sonicteam::Player::State;
IContext::IContext(char* context_name):IPlugIn(context_name),IVarible(),IDynamicLink(),IFlagCommunicator()
{
}

IContext::~IContext(void){
	
}

void Sonicteam::Player::State::IContext::DestroyObject(unsigned int flag)
{
	IContext::~IContext();
	Sonicteam::SoX::Memory::IDestructible::DestroyObject(flag);
}

