#include "RefCountObject.h"


using namespace Sonicteam::SoX;

Sonicteam::SoX::RefCountObject::RefCountObject(void)
{
	this->UnkReference = 0;

}

Sonicteam::SoX::RefCountObject::~RefCountObject(void)
{

}

void Sonicteam::SoX::RefCountObject::DestroyObject(unsigned int flag)
{

	this->~RefCountObject();
	Sonicteam::SoX::Memory::IDestructible::DestroyObject(flag);

}

void Sonicteam::SoX::RefCountObject::LoseObject()
{
	this->UnkReference--;
	if (UnkReference == 0){
		this->DestroyObject(1);
	}
}
