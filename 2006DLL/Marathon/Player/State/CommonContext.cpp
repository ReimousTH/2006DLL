#include "CommonContext.h"

using namespace SonicTeam::Player::State;

CommonContext::CommonContext(void):ICommonContext()
{
}

CommonContext::~CommonContext(void)
{
}



void CommonContext::OnVarible(SonicTeam::LuaSystem** t)
{

	(*t)->LuaNodeUnknown0x01("t");
	(*t)->Unk03(0,std::string("test"));

}

void CommonContext::ICCIF_03()
{

}

void CommonContext::ICCIF_04()
{

}

void CommonContext::ICCIF_05()
{

}

//CharacterControls
void CommonContext::ICOnPostInputTick(void)
{

}

//Character Core
void CommonContext::ICOnInputTick(float delta)
{

	ICommonContext::ICOnInputTick(delta);
	unsigned int v5; // r8
	bool v6; // r11
	int v10;
	bool v14; // xer_ca
	int v15; // r9
	char v16; // r10
	int v17;
	char v18;
	float v19;
	int v20; // r11
	int v21; // r10
	int v22; // r5
	int v23; // r11
	int v24; // r10
	int v25; // r11
	bool v26; // cr58
	int v27; // r10
	int v28; // r11
	bool v29; // cr58
	int v30; // r10
	int v31; // r11
	bool v32; // cr58
	int v33; // r10
	int v34; // r11
	int v35; // r10
	int v36; // r11
	bool v37; // cr58
	int v38; // r10
	int v39; // r8
	int v40; // r11
	int v41; // r10
	int v42; // r11
	bool v43; // cr58
	int v44; // r10
	int v45; // r11
	bool v46; // cr58
	int v47; // r10
	int v48; // r11
	bool v49; // cr58
	int v50; // r10
	int v51; // r11
	bool v52; // cr58
	int v53; // r10
	int v54; // r10
	double v55; // fp13
	char v56; // r11
	int v57; // r10
	char v58; // r11
	int v59; // r5
	int v60; // r4
	int v61; // r31
	int v62; // r30
	int v63; // r29
	int v64; // r28
	int v65; // r11
	int v66; // r27
	int v67; // r26
	int v68; // r25
	WORD v69;
	int v70;
	WORD v71;
	int v72; // r6
	int v73; // r10
	int v74; // r11
	int v75; // r10
	bool v76; // cr58
	int v77; // r11
	int v78; // r10
	bool v79; // cr58
	int v80; // r11
	float v81; // fp13
	int v82; // r8
	char v83; // r9
	bool v84; // xer_ca
	int v85; // r10
	int v86; // r11

	float result;

	v5 = (this->FreeUnknownFlagsDC >> 2) & 1;
	v6 = (this->UnkownFlagsUnk01 & 0x40000000) != 0;
	this->GroundAirDataFlags = 0;
	this->AnimationState = 0;
	this->UnknownFlags0xC8 = 1;
	this->UnknownFlags0xD0 = 0;
	this->UnknownFlags0xD4 = 0;
	this->FreeUnknownFlagsDC  = 0;
	this->UnknownFlags01 = 0;
	if (v6){
		this->IsBarrier = 1;
	}

	for (int i = 0;i<0x15;i++){

		this->UnknownFlags0x111[i] = (OtherCommonContext::StateTable0x82009AB8[i].Flag1 & this->UnknownUnUsedFlagD8) != 0;

	}
	v10 = this->UnkSomeTimer;
	if ( v10 )
		this->UnkSomeTimer = v10 - 1;

	if (this->DamageInvincibleTime > 0.0)
	{
		if ( (this->DamageInvincibleTime - delta) >= 0){
			this->DamageInvincibleTime = this->DamageInvincibleTime - delta;
		}
		else this->DamageInvincibleTime = 0.0;
	}
	if (this->InvicibilityTimerWEffect > 0.0)
	{
		if ( (this->InvicibilityTimerWEffect - delta) >= 0){
			this->InvicibilityTimerWEffect = this->InvicibilityTimerWEffect - delta;
		}
		else this->InvicibilityTimerWEffect = 0.0;
	}
	if (this->SpeedUpTime > 0.0)
	{
		if ( (this->SpeedUpTime - delta) >= 0){
			this->SpeedUpTime = this->SpeedUpTime - delta;
		}
		else this->SpeedUpTime = 0.0;
	}

	v14 = this->IsBlinkingMode == 0;
	v15 = this->IsInvulnerable;
	v16 = (this->IsSonicDied);
	__asm{
		cntlzw    v16, v16
	}
	this->ExportWeaponRequestFlag = 0;
	this->ExportPostureRequestFlag = 0;
	v17 = (v14 ? 0 : 2) | ((v16 & 0x20) == 0);
	this->ContextFlags = v17;
	if ( v15
		|| this->IsInvulnerable2
		|| this->IsUnk102
		|| this->DamageInvincibleTime > 0.0
		|| (v18 = 0, this->InvicibilityTimerWEffect > 0.0) )
	{
		v18 = 1;
	}










}
//Character OnDamage

void CommonContext::ICOnOnDamage(DWORD)
{

}




DWORD CommonContext::IEPRFExportFlag(void)
{

	return this->ExportPostureRequestFlag;

}

DWORD CommonContext::IEWRFExportFlag(void)
{

	return this->ExportWeaponRequestFlag;
}

void CommonContext::OnLink()
{

}


static OtherCommonContext::StateTableBase StateTable0x82009AB8[0x15] = {

	{1,1},
	{2,2},
	{4,3},
	{8,4},
	{0x10,5},
	{0x20,6},
	{0x40,7},
	{0x80,8},
	{0x100,9},
	{0x200,0xA},
	{0x400,0xB},
	{0x800,0xC},
	{0x1000,0xD},
	{0x2000,0xE},
	{0x4000,0xF},
	{0x8000,0x10},
	{0x10000,0x11},
	{0x20000,0x12},
	{0x40000,0x13},
	{0x80000,0x14}

};
