#include "Score.h"

using namespace Sonicteam::Player;




Score::~Score(void)
{

}

//GameModules (GameImpulse,PackageBinary)
Score::Score(int* PtrObjectPlayer,int* RootFrame,int DefaultValue,int* GameModules)
{

}

void Score::AddRings(int value)
{
	this->RingsCount+=value;
}

void Score::TakeDamage(void)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Score::TakeDamageOld()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Score::TakeDamageLittle()
{
	throw std::logic_error("The method or operation is not implemented.");
}

int Score::GetRings()
{
	return this->RingsCount;
}

void Score::SetRings(int value)
{
	this->RingsCount = value;
}

void Score::SetUnknownVector(XMFLOAT4* value)
{
	this->unkvector = *value;
}

void Score::OnVarible(void)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void Score::OnStepable(float)
{
	throw std::logic_error("The method or operation is not implemented.");
}

