#include "CommonContext.h"

using namespace SonicTeam::Player::State;

CommonContext::CommonContext(void):ICommonContext()
{
}

CommonContext::~CommonContext(void)
{
}



void CommonContext::OnVarible()
{

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
void CommonContext::ICOnInputTick(float a1)
{

}
//Character OnDamage

void CommonContext::ICOnOnDamage(DWORD)
{

}




DWORD CommonContext::IEPRFExportFlag(void)
{

	return this->PostureFlags;

}

DWORD CommonContext::IEWRFExportFlag(void)
{

	return this->WeaponFlags;
}

void CommonContext::OnLink()
{

}
