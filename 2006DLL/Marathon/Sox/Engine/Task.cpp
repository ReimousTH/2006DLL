#include "Task.h"


using namespace Sonicteam::SoX::Engine;

Task::Task(void):Component(0)
{

}

Task::~Task(void)
{

}

int Task::OnMessageRecieved(Sonicteam::SoX::Message*)
{
	return 0;
}

char* Sonicteam::SoX::Engine::Task::GetObjectType()
{
	return "Task";
}



