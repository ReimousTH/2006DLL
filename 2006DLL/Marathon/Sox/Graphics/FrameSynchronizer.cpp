#include "FrameSynchronizer.h"


using namespace Sonicteam::SoX::Graphics;




Sonicteam::SoX::Graphics::FrameSynchronizer::FrameSynchronizer(unsigned int)
{

}

Sonicteam::SoX::Graphics::FrameSynchronizer::FrameSynchronizer()
{

}

Sonicteam::SoX::Graphics::FrameSynchronizer::~FrameSynchronizer(void)
{

}

void Sonicteam::SoX::Graphics::FrameSynchronizer::DestroyObject(unsigned int flag)
{
	Sonicteam::SoX::Graphics::FrameSynchronizer::~FrameSynchronizer();
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);
}
