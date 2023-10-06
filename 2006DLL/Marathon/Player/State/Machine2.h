#pragma once




#include "IMachine.h"
#include "IContext.h"
#include "CommonContext.h"
#include "../../Sox/StateMachine.h"
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>


using namespace SonicTeam::SoX::AI;


namespace SonicTeam{

	namespace Player{
		namespace State{

		
			//8200BAD8
			class Machine2:StateMashine<IContext>,IMachine
			{
			public:
				Machine2(void);
				virtual ~Machine2(void);




				///IMachine
				virtual void OnMashineTick(float)  override;
				virtual boost::shared_ptr<IContext> GetMashineContext() override;
				virtual unsigned int ChangeMashineState(int) override;
				virtual unsigned int AlternativeChangeMashineState(int) override;
				virtual void ResetStateFlagsA() override;
				virtual void ResetStateFlagsB() override;
				virtual unsigned int CompleteChangeMashineState(int) override;
				virtual unsigned int GetCurrentMashineStateID() override;

		



				//Mashine Fields

				unsigned int field_0x3C;
				std::vector<unsigned int> MashineStates; //0x40
				unsigned int field_0x50; //-1 (at constuctor)
				unsigned int field_0x54;
				unsigned int field_0x58;
						 byte MashineStateFlag1; //0x58
						 byte MashineStateFlag2; //0x59
						 byte MashineStateFlag3; //0x5A
						 byte Unk0x5B; //0x5B
				unsigned int Unk0x5C; //0x5C
				unsigned int Unk0x60; //0x60
				unsigned int Unk0x64; //0x64

				//unsigned int Unk0x68; //0x68

				boost::shared_ptr<IContext> MashineContext;
				
				



			};

		}

	}

}

