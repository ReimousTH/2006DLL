
#include "IGauge.h"


using namespace Sonicteam::Player;


IGauge::~IGauge(void)
{

}

IGauge::IGauge(char* plug):IPlugIn(plug),IVarible(),IStepable()
{

}

void Sonicteam::Player::IGauge::DestroyObject(unsigned int flag)
{
	IGauge::~IGauge();
	Sonicteam::SoX::Memory::IDestructible::DestroyObject(flag);

}
