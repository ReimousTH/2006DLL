#include "SonicContext.h"

using namespace Sonicteam::Player::State;

void Sonicteam::Player::State::SonicContext::DestroyObject(unsigned int flag)
{
	this->~SonicContext();
	Sonicteam::SoX::Memory::IDestructible::DestroyObject(flag);
}
