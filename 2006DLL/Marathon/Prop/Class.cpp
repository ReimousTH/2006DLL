#include "Class.h"

void Sonicteam::Prop::Class::DestroyObject(unsigned int flag)
{
	Sonicteam::Prop::Class::~Class();
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);

}
