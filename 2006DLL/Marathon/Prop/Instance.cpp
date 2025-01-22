#include "Instance.h"


Sonicteam::Prop::Instance::Instance()
{

}

Sonicteam::Prop::Instance::~Instance()
{

}

void Sonicteam::Prop::Instance::DestroyObject(unsigned int flag)
{

}

void Sonicteam::Prop::InstanceSetDataParams::SetTValue(bool value)
{
	this->Type = 0;
	this->Value._bool_ = value;
}

void Sonicteam::Prop::InstanceSetDataParams::SetTValue(int value)
{
	this->Type = 1;
	this->Value._int32_ = value;
}

void Sonicteam::Prop::InstanceSetDataParams::SetTValue(float value)
{
	this->Type = 2;
	this->Value._single_ = value;
}

void Sonicteam::Prop::InstanceSetDataParams::SetTValue(const char* value)
{
	this->Type = 3;
	this->Value._string_ = new char[strlen(value) + 1];
	strcpy((char*)this->Value._string_,value);
}

void Sonicteam::Prop::InstanceSetDataParams::SetTValue(XMVECTOR value)
{
	this->Type = 4;
	this->Value._vector_ = value;
}





