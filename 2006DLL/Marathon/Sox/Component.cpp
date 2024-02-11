#include "Component.h"


using namespace Sonicteam::SoX;

Component::Component(Component* component)
{

	
	
	
}


Sonicteam::SoX::Component::~Component(void)
{

	
}



	

void Sonicteam::SoX::Component::DestroyObject(unsigned int flag)
{
	Sonicteam::SoX::Component::~Component();
	Sonicteam::SoX::Object::DestroyObject(flag);
}
