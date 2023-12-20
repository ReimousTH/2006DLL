#include "Object.h"


using namespace Sonicteam::SoX;

//have not any of this
Object::~Object(void)
{
	/*
	Sonicteam::SoX::IObjectNode *v5;
	Sonicteam::SoX::IObjectNode *v6;

	v5 = this->ObjList.Node.NextIObjStp;
	if ( v5 )
		v5->PreviousIObjStp = this->ObjList.Node.PreviousIObjStp;

	v6 = this->ObjList.Node.PreviousIObjStp;
	if ( v6 )
		v6->NextIObjStp = this->ObjList.Node.NextIObjStp;
	*/
}

char* Object::GetObjectType()
{

	return "Object";
}

Object::Object(void)
{


	
}

void Sonicteam::SoX::Object::DestroyObject(unsigned int flag)
{

	Sonicteam::SoX::Object::~Object();
	Sonicteam::SoX::Memory::IDestructible::DestroyObject(this,flag);
}

Sonicteam::SoX::ObjectRework::ObjectRework(void)
{

}

char* Sonicteam::SoX::ObjectRework::GetObjectType()
{
return "";
}

Sonicteam::SoX::ObjectRework::~ObjectRework(void)
{

}
