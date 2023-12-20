#include "IMachine.h"

using namespace Sonicteam::Player::State;
IMachine::IMachine(void):IPlugIn("state mashine")
{
}

IMachine::~IMachine(void){
	
}

void Sonicteam::Player::State::IMachine::DestroyObject(unsigned int flag)
{
	throw std::logic_error("The method or operation is not implemented.");
}
