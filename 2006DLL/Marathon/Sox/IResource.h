#pragma once

#include <string>

#include <Sox/RefCountObject.h>

namespace Sonicteam{
	namespace SoX{
		class IResource:public Sonicteam::SoX::RefCountObject
		{
		public:
			//size0x60
			IResource(void);
			~IResource();
			//virtual ~IResource(void);
			virtual void DestroyObject(unsigned int flag) override;



			//bool
			virtual int Unk01(int,int) = 0; // FileArrayPtr,FileSizeMb
			virtual int Unk02(); //return 0
			virtual std::string Unk03(int,std::string) = 0;
			virtual int Unk04(); //return 1





			//fields

			unsigned int field4;	
			unsigned int field8;

			std::string str1;
			std::string str2;
			std::string str3;

			unsigned int field60; //or int

		

			
		};
	}
}
