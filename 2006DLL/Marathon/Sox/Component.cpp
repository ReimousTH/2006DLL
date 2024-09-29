#include "Component.h"


using namespace Sonicteam::SoX;

Component::Component(Component* component)
{	

	this->LastComponent = component;
	Sonicteam::SoX::LinkNode<Component>* link =  &this->LinkedComponent;
	this->LinkedComponent.NThread = 0;
	this->LinkedComponent.PThread = 0;
	this->LinkedComponent.TThread = this;

	this->LComponentList = Sonicteam::SoX::LinkNodeList<Component>(0);



	if (component){
		link->NThread = (Sonicteam::SoX::LinkNode<Component>*)component->LComponentList.NThread;
		link->PThread = (Sonicteam::SoX::LinkNode<Component>*)component->LComponentList.PThread;
		component->LComponentList.PThread->NThread = (Sonicteam::SoX::LinkNodeList<Component>*)link;
		component->LComponentList.PThread = (Sonicteam::SoX::LinkNodeList<Component>*)link;

	}
}


Sonicteam::SoX::Component::~Component(void)
{
	this->LComponentList.ForEach(0);
	this->LComponentList.Empty();
}



	

char* Sonicteam::SoX::Component::GetObjectType()
{
	return "Component";
}

void Sonicteam::SoX::Component::DestroyObject(unsigned int flag)
{
	Sonicteam::SoX::Component::~Component();
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);
	//Sonicteam::SoX::Object::DestroyObject(flag);
}
