#include "FrameBase.h"


using namespace Sonicteam::SoX::Graphics;




void Sonicteam::SoX::Graphics::Frame::DestroyObject(unsigned int flag)
{
	Sonicteam::SoX::Graphics::Frame::~Frame();
	//this->~Frame();
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);
}

Sonicteam::SoX::Graphics::Frame::Frame():OFrame(),BNF0x34(this),BNF0x40(this)
{
}


Sonicteam::SoX::Graphics::Frame::~Frame()
{




	if (this->Parent){

		Frame* v5 = this->Parent;
		Frame* v6;
		do{
			v6 = v5->Prev;
			//Clear Func
			v5 = v6;
		} while (v6);
	}

	Frame* v7 = this->Next;
	if ( v7 )
	{
		Frame* v8 = this->Prev;
		if ( !v8 )
			v8 = v7->Parent;                          // Frame
		v8->Active = this->Active;
		Frame* v9 = this->Next;
		Frame* v10 = this->Prev;
		if ( v9->Parent == this )
			v9->Parent = v10;
		else
			this->Active->Prev = v10;
	}




}

Sonicteam::SoX::Graphics::Frame* Sonicteam::SoX::Graphics::Frame::New()
{
	return ((Sonicteam::SoX::Graphics::Frame* (__fastcall *)(...))0x82594530)(malloc(sizeof(Sonicteam::SoX::Graphics::Frame)));

}

int Sonicteam::SoX::Graphics::Frame::FrameUnk01()
{
	return -1;
}

int Sonicteam::SoX::Graphics::Frame::FrameUnk02()
{
	return 0;
}





int Sonicteam::SoX::Graphics::Frame::FrameUnk08()
{
	return 0;
}





template <>
int Sonicteam::SoX::LinkNodeList<Sonicteam::SoX::Graphics::FrameObserver>::EachClearADV(Sonicteam::SoX::Graphics::FrameObserver* ths)
{
	if (ths->UFOFlag0x10){
		ths->RNodeH.ClearLink();
		ths->UFOFlag0x10 = 0;
	}
	return 0;
}



Sonicteam::SoX::Graphics::FrameObserver::FrameObserver():RNodeH(this)
{

}

Sonicteam::SoX::Graphics::FrameObserver::~FrameObserver(void)
{

}


void Sonicteam::SoX::Graphics::FrameObserver::DestroyObject(unsigned int flag)
{
	Sonicteam::SoX::Graphics::FrameObserver::~FrameObserver();
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);
}




Sonicteam::SoX::Graphics::FrameSynchronizer::FrameSynchronizer(unsigned int fcount)
{



}

Sonicteam::SoX::Graphics::FrameSynchronizer::FrameSynchronizer()
{

}

Sonicteam::SoX::Graphics::FrameSynchronizer::~FrameSynchronizer(void)
{

}

void Sonicteam::SoX::Graphics::FrameSynchronizer::DestroyObject(unsigned int flag)
{
	Sonicteam::SoX::Graphics::FrameSynchronizer::~FrameSynchronizer();
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);
}


/*
Sonicteam::SoX::Graphics::FrameSyncT01::FrameSyncT01(int count)
{
	this->_array = FrameSyncArray::NEW(count);
	this->FrameSyncArrayCount = new int(count);
	this->FrameSyncArrayTotal = count;

}

Sonicteam::SoX::Graphics::FrameSyncT01::FrameSyncT01()
{

}
*/
