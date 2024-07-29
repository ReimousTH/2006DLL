#include "FrameObserver.h"


using namespace Sonicteam::SoX::Graphics;



Sonicteam::SoX::Graphics::FrameObserver::FrameObserver():RNodeH(this)
{
	
}

Sonicteam::SoX::Graphics::FrameObserver::~FrameObserver(void)
{

}


void Sonicteam::SoX::Graphics::FrameObserver::DestroyObject(unsigned int flag)
{
	Sonicteam::SoX::Graphics::FrameObserver::~FrameObserver();
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);
}

void Sonicteam::SoX::Graphics::FrameObserver::OnRNodeHClear()
{
	if (this->UFOFlag0x10){
		this->RNodeH.Reset();
		this->UFOFlag0x10 = 0;
	}

}
