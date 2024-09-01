#include "GameImp.h"


using namespace Sonicteam;

void Sonicteam::GameImp::DestroyObject(unsigned int flag)
{
	Sonicteam::GameImp::~GameImp();
}

int Sonicteam::GameImp::OnMessageRecieved(Sonicteam::SoX::Message*)
{
	throw std::logic_error("The method or operation is not implemented.");
}

Sonicteam::GameImp::~GameImp()
{
	

}

Sonicteam::GameImp::GameImp()
{

}
