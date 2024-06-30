#include "Load.h"

using namespace Sonicteam::Player;


void Sonicteam::Player::Load::DestroyObject(unsigned int flag)
{
	Sonicteam::Player::Load::~Load();
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);
}


Sonicteam::Player::Load::Load(Sonicteam::SoX::Engine::Doc* doc):ILoad()
{


	//later




}


Sonicteam::Player::Load::~Load(void)
{

}


Sonicteam::Player::PLoadBodyPackage::PLoadBodyPackage()
{

}

Sonicteam::Player::PLoadHeadPackage::PLoadHeadPackage()
{

}

Sonicteam::Player::PLoadHeadPackage::~PLoadHeadPackage()
{

}
