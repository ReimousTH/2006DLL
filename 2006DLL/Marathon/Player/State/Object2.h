#pragma once



#include "IMachine.h"

#include "..\..\Sox\AI\State.h"
#include "IContext.h"
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>


namespace Sonicteam{

	namespace Player{
		namespace State{

		
			//8200BAD8
			class Object2:Sonicteam::SoX::AI::State<Sonicteam::Player::State::IContext>
			{
			public:
				Object2(IMachine*);
				virtual ~Object2(void);



				//or IMachine*
				IMachine* ObjectMashine; //State




				virtual unsigned int* StateConstant(); // idk what real name 
				virtual void OnStateStart(); //OnStateStart
				virtual void OnStateUpdate(float); //OnStateUpdate
				virtual void OnStateEnd(); //OnStateEnd
				virtual unsigned int StateUnknown(); // li r3 ,0x0 blr






				virtual void Object2Start() = 0;	
				virtual unsigned int Object2Update(float) = 0;	
				virtual void Object2End() = 0;

				virtual void Object2PreUpdateCmn(float) = 0;
				virtual void Object2PostUpdateCmn(float) = 0;



			

			};

		}

	}

}

