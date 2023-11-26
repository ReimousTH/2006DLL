#pragma once


#include <list>
#include "IListener.h"
#include "../IPlugIn.h"
#include "../IVarible.h"
#include "../IStepable/IStepable.h"


namespace Sonicteam{
	namespace Player{


		namespace Input{


			//size 0x18
			class ListenerNormal:Sonicteam::Player::Input::IListener,Sonicteam::Player::IPlugIn,Sonicteam::Player::IVarible,Sonicteam::Player::IStepable
			{
			public:

				ListenerNormal(unsigned int,unsigned int);
				~ListenerNormal(void);

				virtual void ListenerOnUpdate(int,float);

				virtual XMFLOAT4* ListenerGetStickVector4();

				virtual float ListenerGetStickPower();

				virtual unsigned int ListenerGetResult();

				virtual int Listener5();

				virtual void OnVarible(LuaSystem**);

				virtual void OnStepable(float);

				unsigned int ptr0x40;
				unsigned int ptr0x44;
				unsigned int unk0x48;
				float StickPower; 
				XMFLOAT4 StickVector; //0x50 

				
				//unsigned int ptr0x60; //???// type size with 0x14 (vector(no any about vector) std::list maybe )
				//std::list<unsigned int> unkList0x60;

				byte unkgap0x60[0x14];


				float unkfloat0x74;

				IListenerInputStruc02 ILISunk0x78; // A Button
				IListenerInputStruc03 ILISunk0x88; // X Button
				unsigned int unk0x9c; //always=1 
				unsigned int unk0xA0; //always=8
				unsigned int unk0xA4; //always=0x10
				unsigned int unk0xA8; //always=0x8000 
				IListenerInputStruc02 ILISunk0xAC;	 //RT Button
				float c_input_border; //  0.1 

		
			


			


	
			};

		}
		
	}
}

