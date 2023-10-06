#pragma once

#include <boost/weak_ptr.hpp>


namespace SonicTeam{
	namespace SoX{

		namespace AI{
			
			template<typename T>
			class StateMashine
			{
			public:
				StateMashine(void) {};
				virtual ~StateMashine(void) {};
			//	
				
				virtual unsigned int OnStateChange(unsigned int,T*) {return 0;}; // For now nothing
				virtual unsigned int Unk02() { return 0;}; // For now nothing
				virtual unsigned int Unk03() { return 0;}; // For now nothing
				virtual unsigned int Unk04() { return 0;}; // For now nothing
				virtual unsigned int Unk05() { return 0;}; // For now nothing
				virtual unsigned int Unk06() { return 0;}; // For now nothing

				//FIELDS
				boost::weak_ptr<T> CurrentState; //0x4
				unsigned int field0xC; //0xC
				unsigned int field0x10; //0x10
				unsigned int field0x14; //0x14
				unsigned int field0x18; //0x18
				unsigned int field0x1C; //0x1C



			};

		

		}



	
	}
}
