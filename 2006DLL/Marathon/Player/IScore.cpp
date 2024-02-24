#include "IScore.h"

using namespace Sonicteam::Player;

IScore::IScore(void):IPlugIn("score"),IVariable()
{
	
}


IScore::~IScore(void)
{

}

void Sonicteam::Player::IScore::DestroyObject(unsigned int flag)
{
	throw std::logic_error("The method or operation is not implemented.");
}

