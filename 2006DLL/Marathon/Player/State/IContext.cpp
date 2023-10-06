#include "IContext.h"

using namespace SonicTeam::Player::State;
IContext::IContext(char* context_name):IPlugIn(context_name),IVarible(),IDynamicLink(),IFlagCommunicator()
{
}

IContext::~IContext(void){
	
}

