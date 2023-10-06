#include "CommonObject.h"

using namespace SonicTeam::Player::State;

CommonObject::~CommonObject(void)
{

}

void Object2ForceHelper(CommonContext* a1){

	/*
	if ( a1->field_130 && sub_82615D60 )
	{
		v2 = ((double (*)(void))a1->TableForce->field_14)();
		if ( -(float)((float)v2
			- (float)((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)a1->field_130 + 8))(a1->field_130)) >= a1->float1DC )
			a1->FreeUnknownFlagsDC |= 1u;
	}
	*/
}

void CommonObject::Object2PreUpdateCmn(float)
{

	unsigned long long t =  this->CObjContext->UnknownFlags0xC8;

	if ((t & 4) != 0)
		this->CObjContext->IsInvulnerable2 = 1;

	if ((t & 8) != 0)
		this->CObjContext->InvicibilityTimerWEffect = 0; // a1->StateBase.ContextBase->float1C8;

	if ((t & 0x40000 ) != 0)
		this->CObjContext->SpeedUpTime = 0; // *(float *)&a1->StateBase.ContextBase->field_1CC;


	//a1->StateBase.ContextBase->field_F3 = 0;
	//a1->StateBase.ContextBase->field_F1 = 0;
	// 
	// 
	Object2ForceHelper(this->CObjContext);
}

void CommonObject::Object2PostUpdateCmn(float)
{

}

//I have no idea what boost _ptr should be used
CommonObject::CommonObject(IMachine* a1):Object2(a1)
{

	
	boost::shared_ptr<IContext> t =  a1->GetMashineContext();
	this->ObjectMashine = a1;
	this->CObjContext = (CommonContext*)(t.get()); // also should by dynamic cast but since i cant match typeid it useles


//not sure because i cant MAKE BOOST NOT USE STUPUID LWARX



}

void CommonObject::Object2Start()
{

}

unsigned int CommonObject::Object2Update()
{

	return 0;
}

void CommonObject::Object2End()
{

}

