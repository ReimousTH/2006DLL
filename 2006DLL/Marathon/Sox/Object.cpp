#include "Object.h"


using namespace SonicTeam::SoX;

Object::~Object(void)
{

}

char* Object::GetObjectType()
{

	return "Object";
}

Object::Object(void)
{
	this->NextIObject= 0;
	this->PreviousIObject = 0;
	this->CurrentObject = this;
}
