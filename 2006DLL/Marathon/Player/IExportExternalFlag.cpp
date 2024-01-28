#include "IExportExternalFlag.h"
using namespace Sonicteam::Player;


void Sonicteam::Player::IExportExternalFlag::DestroyObject(unsigned int flag)
{
	Sonicteam::Player::IExportExternalFlag::~IExportExternalFlag();
	Sonicteam::SoX::Memory::IDestructible::DestroyObject(this,flag);
}

Sonicteam::Player::IExportExternalFlag::IExportExternalFlag(void)
{

}

Sonicteam::Player::IExportExternalFlag::~IExportExternalFlag(void)
{

}
