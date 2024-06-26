#include "MainMenuTask.h"


using namespace Sonicteam;

int MainMenuTask::OnMessageRecieved(Sonicteam::SoX::Message*)
{
	throw std::logic_error("The method or operation is not implemented.");
}


char* MainMenuTask::GetObjectType()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void MainMenuTask::OnTaskUpdate(float)
{
	throw std::logic_error("The method or operation is not implemented.");
}

Sonicteam::DocMarathonImp* Sonicteam::MainMenuTask::GetCurrentDoc()
{
	return (DocMarathonImp*)this->TaskEngineDoc;
}

