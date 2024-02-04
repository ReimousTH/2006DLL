#include "PhantomEnterListener.h"


using namespace Sonicteam::Player;;

Sonicteam::Player::PhantomEnterListener::PhantomEnterListener(boost::function<int()>& fnc)
{

	this->PELOnEnter = fnc;
}

void Sonicteam::Player::PhantomEnterListener::PhLsProcessMessage2(Sonicteam::SoX::Physics::PLMessage&)
{
	this->PELOnEnter();
}
