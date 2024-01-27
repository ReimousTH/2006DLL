#include "Frame.h"


using namespace Sonicteam::SoX::Graphics;


void Sonicteam::SoX::Graphics::Frame::DestroyObject(unsigned int flag)
{
	Sonicteam::SoX::Graphics::Frame::~Frame();
	//this->~Frame();
	Sonicteam::SoX::Memory::IDestructible::DestroyObject(flag);
}

Sonicteam::SoX::Graphics::Frame::Frame()
{
}


Sonicteam::SoX::Graphics::Frame::~Frame()
{
	if (this->Layer4){

		Frame* v5 = this->Layer4;
		Frame* v6;
		do{
			v6 = v5->Layer2;
			//Clear Func
			v5 = v6;
		} while (v6);
	}

	Frame* v7 = this->Layer1;
	if ( v7 )
	{
		Frame* v8 = this->Layer2;
		if ( !v8 )
			v8 = v7->Layer4;                          // Frame
		v8->Layer3 = this->Layer3;
		Frame* v9 = this->Layer1;
		Frame* v10 = this->Layer2;
		if ( v9->Layer4 == this )
			v9->Layer4 = v10;
		else
			this->Layer3->Layer2 = v10;
	}




}
