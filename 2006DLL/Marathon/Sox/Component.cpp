#include "Component.h"


using namespace Sonicteam::SoX;

Component::Component(Component* component)
{

	this->ObjList.CurrentObject = component;
	this->ObjList.Node.NextIObjStp = 0;
	this->ObjList.Node.PreviousIObjStp = 0;


	this->CompList.CurrentObject = this;
	this->CompList.Node.NextIObjStp = &this->CompList.Node;
	this->CompList.Node.PreviousIObjStp = &this->CompList.Node;



	if (component){
		this->ObjList.Node.NextIObjStp =  &component->CompList.Node;
		this->ObjList.Node.PreviousIObjStp = component->CompList.Node.PreviousIObjStp;
		component->CompList.Node.PreviousIObjStp->NextIObjStp = &this->ObjList.Node;
		component->CompList.Node.PreviousIObjStp = &this->ObjList.Node;
		
	}
	
	
}


Sonicteam::SoX::Component::~Component(void)
{

	FreeComponents((Sonicteam::SoX::IComponentNode *)this->CompList.Node.PreviousIObjStp,&this->CompList.Node,0);
	FreeComponentsOffsets(&this->CompList.Node);

	
}

int Sonicteam::SoX::Component::FreeComponents(Sonicteam::SoX::IComponentNode * a1, Sonicteam::SoX::IComponentNode * a2, int a3)
{

	if (a1 != a2){


		Sonicteam::SoX::IComponentNode *v10; 
		Sonicteam::SoX::IComponentNode *v4; 
		Sonicteam::SoX::Object *v9; 
		do 
		{
			
			v9 = v4->CurrentObject;
			v10 = (Sonicteam::SoX::IComponentNode*)v4->PreviousIObjStp;
			if ( v9 )
				v9->~Object();
			v4 = (Sonicteam::SoX::IComponentNode *)v10;


		} while (v10 != a2);




	}

	return a3;

}

void Sonicteam::SoX::Component::FreeComponentsOffsets(Sonicteam::SoX::IComponentNode * _this)
{

	Sonicteam::SoX::IObjectNode *v1; // r11
	Sonicteam::SoX::IObjectNode *v2; // r10
	Sonicteam::SoX::IObjectNode *v3; // r11

	v1 = _this->PreviousIObjStp;
	if ( v1 != _this )
	{
		do
		{
			v2 = v1->PreviousIObjStp;
			v1->NextIObjStp = 0;
			v1->PreviousIObjStp = 0;
			v1 = v2;
		}
		while ( v2 != _this );
	}
	if ( _this->NextIObjStp )
		_this->NextIObjStp->PreviousIObjStp = _this->PreviousIObjStp;
	v3 = _this->PreviousIObjStp;
	if ( v3 )
		v3->NextIObjStp = _this->NextIObjStp;

}
