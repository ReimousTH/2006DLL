#pragma once
#include <xtl.h>
#include <xinputdefs.h>
#include <iostream>
#include <utility>

namespace Sonicteam{
	namespace System{
		namespace Peripheral{


		
			struct XINPUT_GAMEPAD_BUTTONS_REMAP_TABLE_STRUCT {
				unsigned int From;
				unsigned int To;
			};
			
			static const XINPUT_GAMEPAD_BUTTONS_REMAP_TABLE_STRUCT XINPUT_GAMEPAD_BUTTONS_REMAP_TABLE[14] = {
				{ XINPUT_GAMEPAD_DPAD_UP,      0x40 },
				{ XINPUT_GAMEPAD_DPAD_DOWN,    0x80 },
				{ XINPUT_GAMEPAD_DPAD_LEFT,    0x100 },
				{ XINPUT_GAMEPAD_DPAD_RIGHT,   0x200 },
				{ XINPUT_GAMEPAD_START,        0x400 },
				{ XINPUT_GAMEPAD_BACK,         0x800 },
				{ XINPUT_GAMEPAD_LEFT_THUMB,   0x10000 },
				{ XINPUT_GAMEPAD_RIGHT_THUMB,  0x20000 },
				{ XINPUT_GAMEPAD_LEFT_SHOULDER, 0x1000 },
				{ XINPUT_GAMEPAD_RIGHT_SHOULDER, 0x2000 },
				{ XINPUT_GAMEPAD_A,            1 },
				{ XINPUT_GAMEPAD_B,            2 },
				{ XINPUT_GAMEPAD_X,            8 },
				{ XINPUT_GAMEPAD_Y,            0x10 }
			};



			//0x10
			#pragma pack(push, 4) 
			typedef struct {
				unsigned int bActive; // 0x0
				unsigned int wButtons; //0x4,       
				short sThumbLX;        // 0x8  0xFFFF8000  ->  0x8001; 
				short sThumbLY;        // -sThumbLY  0xA 
				short sThumbRX; // 0xC
				short sThumbRY; // 0xE //-sThumbLY 
			} XINPUT_GAMEPAD_STATE;
			#pragma pack(pop)






			//0x58
#pragma pack(push,4)
			class ManagerImpXenon
			{
			public:
				ManagerImpXenon(void);
				~ManagerImpXenon(void);

				byte IsActive;  //it works
				_XINPUT_CAPABILITIES GAMEPAD_CAPABILITIES[4];


				virtual void DestroyObject(unsigned int flag);
				virtual void ManagerUnk01();
				virtual int ManagerGetMaxInputCount();
				virtual int MangerProcessInput(XINPUT_GAMEPAD_STATE* _buffer_,int _buffer_count);
				virtual int ManagerGetThumbstickValues(unsigned int index,short* buffer);
			};
#pragma pack(pop)


		}
	}
}

