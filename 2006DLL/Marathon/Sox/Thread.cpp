#include "Thread.h"


using namespace Sonicteam::SoX;



DWORD WINAPI SonicTeamSOXThreadProcFunc( LPVOID lpParameter )
{
	if (lpParameter)
		((Sonicteam::SoX::Thread*)lpParameter)->ThreadOnStart();

	return 0;

}

Sonicteam::SoX::Thread::Thread(const char* ThreadName,int Priority,int Flag)
{
	this->m_Field1 = 0;
	this->m_Field2 = 0;
	this->instance = this;

	this->ThreadFlag1 = 0x10000000;
	this->ThreadFlag2 = 0x10000000 | (Flag << 24);
	this->m_Field4 = 0;
	this->m_Field5 = 0;
	this->m_ThreadName = ThreadName;
	this->m_Event1 = CreateEvent(0,0,0,0);
	this->m_Event2 = CreateEvent(0,0,0,0);
	

	this->m_ThreadHandle = CreateThread(0,0,SonicTeamSOXThreadProcFunc,this,4u,this->m_ThreadID);
	SetThreadPriority(this->m_ThreadHandle,Priority);





}

void Sonicteam::SoX::Thread::DestroyObject(unsigned int Flag)
{

}

void Sonicteam::SoX::Thread::ThreadOnUpdate()
{

	unsigned __int64 T1 =  Sonicteam::SoX::PerformanceFrequency::getInstance().GetTimeBase();

	
	unsigned __int64 T2 =  Sonicteam::SoX::PerformanceFrequency::getInstance().GetTimeBase();

}

void Sonicteam::SoX::Thread::ThreadOnStart()
{
	while (this->ThreadFlag1 >> 28){
		if (((this->ThreadFlag2 >> 24) & 0xF)){
			WaitForSingleObject(m_Event1,-1);
		}
		else{

		}

	}


}

void Sonicteam::SoX::Thread::ThreadOnStep()
{

}
