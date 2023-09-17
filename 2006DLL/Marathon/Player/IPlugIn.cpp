#include "IPlugIn.h"

using namespace SonicTeam::Player;

IPlugIn::IPlugIn(char* plug_name)
{
	this->PluginName.assign(plug_name);
}

IPlugIn::~IPlugIn(void)
{
	this->PluginName.clear();
}
