
#include "IGauge.h"


using namespace SonicTeam::Player;


IGauge::~IGauge(void)
{

}

IGauge::IGauge(char* plug):IPlugIn(plug),IVarible(),IStepable()
{

}
