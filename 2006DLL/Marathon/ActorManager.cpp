#include "ActorManager.h"


using namespace Sonicteam;

Sonicteam::ActorManager::~ActorManager()
{

}

Sonicteam::ActorManager::ActorManager()
{

}

void Sonicteam::ActorManager::DestroyObject(unsigned int flag)
{
	Sonicteam::ActorManager::~ActorManager();
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);
}
