
#include "PatchData.h"



struct RCSS{
	int STATENUM;
	std::string StateVar;
};
struct RCS{
	int CHRID;
	std::vector<RCSS> _RCSS;
};
std::vector<RCS> _RCS;



//CHRID,
std::map<int, std::map<int,std::string>> my_map;






char* Testing = "asdfasgasgasg";

namespace Multiplayer4P
{

	namespace SonicStates
	{


	
		class StateWait:Marathon::PlayerState::CommonObject{
		public:
			int* StateStart() override{

		
				this->CContext->CurrentAnimation=46;

				return 0;
			}
			int* StateEnd() override{
 
			
			//	State_Common_Walk_Action_End((int*)this);
				return 0;
			}
			int* StateUpdate(double a2) override{
				

//				State_Base_Switcher()

				//if (State_Common_Wait_Action_Mid((int*)this,a2)) return 0;

				
				return 0;
			}
		    StateWait(Marathon::PlayerState::StateBaseValueP* OM):CommonObject(OM){

				}

		};
		MakeStateS(StateWait)
	

	}
	struct MapIDFunction StateTable[] = {
		{0	,FD(SonicStates::StateWait)},
		{1, 0x8219FED0},
		{2, 0x8219FF48},
		{3, 0x8219FFC0},
		{4, 0x821A0038},
		{5, 0x821A00B0},
		{6, 0x821A0128},
		{7, 0x821A01A0},
		{8, 0x821A02C8},
		{9, 0x821A0340},
		{0xA, 0x821A03B8},
		{0xB, 0x821A0340},
		{0xC, 0x821A0570},
		{0xD, 0x821A05E8},
		{0xE, 0x821A0660},
		{0xF, 0x821A06D8},
		{0x10, 0x821A0750},
		{0x11, 0x821A0840},
		{0x12, -0x7DE5F7C0},
		{0x14, -0x7DE5F748},
		{0x13, -0x7DE5F6D0},
		{0x15, -0x7DE5F658},
		{0x16, -0x7DE5F5E0},
		{0x17, -0x7DE5F3C8},
		{0x18, -0x7DE5F328},
		{0x19, -0x7DE5F2B0},
		{0x1A, -0x7DE5F238},
		{0x1B, -0x7DE5F1C0},
		{0x1E, -0x7DE5F148},
		{0x1F, -0x7DE5F0D0},
		{0x20, -0x7DE5F058},
		{0x21, -0x7DE5EFE0},
		{0x22, -0x7DE5EF68},
		{0x25, -0x7DE5EE60},
		{0x26, -0x7DE5ED30},
		{0x27, -0x7DE5EBC8},
		{0x28, -0x7DE5EB50},
		{0x29, -0x7DE5EA30},
		{0x2A, -0x7DE5E918},
		{0x2B, -0x7DE5E780},
		{0x30, -0x7DE5E600},
		{0x31, -0x7DE5E460},
		{0x24, -0x7DE5E018},
		{0x2E, -0x7DE5DDD8},
		{0x2F, -0x7DE5DC90},
		{0x41, -0x7DE5D920},
		{0x42, -0x7DE5D8A8},
		{0x43, -0x7DE5D830},
		{0x44, -0x7DE5D7B8},
		{0x45, -0x7DE5D740},
		{0x46, -0x7DE5D538},
		{0x47, -0x7DE5D4C0},
		{0x48, -0x7DE5D448},
		{0x49, -0x7DE5D298},
		{0x4A, -0x7DE5D068},
		{0x4B, -0x7DE5CEE8},
		{0x4D, -0x7DE5CD58}

	};






	void __fastcall Context_Sonic_Core(Marathon::PlayerState::CommonContext *a1, double a2){


	
		//*reinterpret_cast<void**>(test.GetOriginal<int*>())()
	//test.GetOriginal<unsigned __int8 (__fastcall *)(Marathon::PlayerState::CommonContext *, double)>()(a1,a2);

		a1->ForceNMCamPlr=1000;


	};



	char* SU="SUPER SONIC RACING";




	HOOK(int,__fastcall,sub_824EB460,0x824EB460,_DWORD *a1, int a2){

		_DWORD sv;
		__asm{
			mflr r12
		    mr sv,r12
		}

		_DWORD r31_1; // r31
		_DWORD r11_2; // r11
		_DWORD r3_2; // r3
		_DWORD r29_2; // r29
		_DWORD r30_2; // r30
		_DWORD r3_5; // r3
		_DWORD r4_5; // r4
		int result; // r3
		_DWORD r11_13; // r11
		_DWORD r5_13; // r5
		_DWORD r3_17; // r3
		int var30; // [sp+50h] [-30h]
		int var40; // [sp+50h] [-30h]
		int var2C; // [sp+54h] [-2Ch]
		int var28; // [sp+58h] [-28h]
		int var24; // [sp+5Ch] [-24h]

		switch ( *(_DWORD *)(a2 + 4) ){

			case 0:

				r11_2 = *(_DWORD *)(a2 + 8);
				r3_2 = a1[28];
				r29_2 = (unsigned __int8)r11_2 >> 4;
				r30_2 = r11_2 & 0xF;
				//ShowXenonMessage(L"MSG",(int)(r11_2 >> 4) & 0xF,"");

				if ((r11_2 >> 4) & 0xF == 2){
					var40 = a1[28];
					a1[40] = r30_2;
					if ( r3_2 )
						BranchTo(0x82659610,void,r3_2);
					r3_5 = (DWORD)&var40;
					r4_5 = (DWORD)"3p_tug";
				}
				else if ( (unsigned __int8)r11_2 >> 4 )
				{
					var2C = a1[28];
					a1[40] = r30_2;
					if ( r3_2 )
						BranchTo(0x82659610,void,r3_2);
					r3_5 = (DWORD)&var2C;
					r4_5 = (DWORD)"2p_tug";
			


				}
				else
				{
					var30 = a1[28];
					a1[39] = r30_2;
					if ( r3_2 )
						BranchTo(0x82659610,void,r3_2);
					r3_5 = (DWORD)&var30;
					r4_5 = (DWORD)"1p_tug";
				}
				BranchTo(0x824CE670,void,r3_5, (int)r4_5, 0);
				BranchTo(0x824EAED8,void,(int)a1, r29_2, r30_2, 1);
				result = 1;

				break;
			default:
				return 0;


		}

		return 0;

	};




	struct PLRS{
		int cuse;
		int PListener; // Active Gamepad (from 1 to 3) 2P 3P 4P
		int VarGlobal[3];
		int PMListener;
		int act_chr;

	};
	//Selected Character Transform
	struct CSST{
		XMVECTOR rot;
		XMVECTOR pos;
	};


	struct MPL{
		int act_chr;
		int PID;
		CSST trs;

		int PCase;
		int P2U1[2];
		int P2PListener;
		int P2Input;
		int vd;
	
		
		
	};
	PLRS P3 = {0,0,{0,0,0},0,0};


	MPL PLR[] = {

{0,0x10,{{0.13,0.13,-0.02,0.98},{235,-95,300,1}},0,{0,0},0xFFFF,0},
{0,0x20,{{0.13,-0.13,0.02,0.98},{-235,95,300,1}},0,{0,0},0xFFFF,0},
{0,0x30,{{0.13,-0.13,0.02,0.98},{235,95,300,1}},0,{0,0},0xFFFF,0}

	};



	int Pnamer[] = {
		(int)"1p_name",
		(int)"2p_name",
		(int)"3p_name",
		(int)"4p_name"
	};
	int Cursors[] = {

		(int)"1p_cursor",
		(int)"2p_cursor",
		(int)"3p_cursor",
		(int)"4p_cursor"
	};
	int Controlers[] = {

		(int)"controller_1p",
		(int)"controller_2p",
		(int)"controller_3p",
		(int)"controller_4p"
	};




	void __declspec( naked ) MainAsmHookIline(int* a1,double a2){
		__asm{
			    mflr r12
				std       r27, -0x30(r1)
				std       r28, -0x28(r1)
				std       r29, -0x20(r1)
				std       r30, -0x18(r1)
				std       r31, -0x10(r1)
				stw       r12, -0x8(r1)
				stfd      fp31, -0x38(r1)
				stwu      r1, -0xC20(r1)
				lis r11,0x824F
				ori r11,r11,0xFD08 
				mtctr r11
				bctr r11
		}
	}	

	int __declspec( naked ) sub_824D3B18H(int a1, int a2){

		__asm{

			    mflr r12
				std       r29, -0x20(r1)
				std       r30, -0x18(r1)
				std       r31, -0x10(r1)
				stw       r12, -0x8(r1)
				stwu      r1, -0xE0(r1)
				mr        r30, r3
				lis r11,0x824D
				ori r11,r11,0x3B28 
				mtctr r11
				bctr r11
		}
	}

	HOOK(int,__fastcall,sub_824D3B18,0x824D3B18,int a1, int a2){


		DWORD* v2 = (_DWORD *)a1;
		DWORD v3 = *(_DWORD *)(a1 + 84);

		switch (a2){
			case 2:

				std::string* Buff = new std::string();

				for (int i = 0;i<=0x7C;i+=4){

					std::ostringstream ss;
					ss << std::hex << *(int*)(a1+i);

					std::ostringstream ss1;
					ss1 << std::hex << i;

					Buff->append(ss.str().c_str());
					Buff->append("         ");
					Buff->append(ss1.str().c_str());
					Buff->append("\n");

				}

				
				
				ShowXenonMessage(L"MSGNext",Buff->c_str());

				break;
		}

		return sub_824D3B18H(a1,a2);
	}




	HOOK(DWORD*,__fastcall,sub_82160B98,0x82160B98,DWORD* a1,int a2){

		sub_825EB070((int)a1, a2);
		*a1 = 0x8200094C;

	
		DWORD handle1;
		DWORD handle2;
		DWORD handle3;



		byte s1[0x1C];
		byte s2[0x1C];
		byte s3[0x1C];

		BranchTo(0x821620E8,int,&s1,"DLL/cache_4P.arc");
		BranchTo(0x821620E8,int,&s2,"DLL/scripts_4P.arc");
		BranchTo(0x821620E8,int,&s3,"DLL/sprites_4P.arc");
	
		int result1 = ArcHandle(&handle1,&s1,2,2);
		int result2 = ArcHandle(&handle1,&s2,2,2);
		int result3 = ArcHandle(&handle1,&s3,2,2);


		
		sub_82582C10(*(DWORD*)result1);
		sub_82582C10(*(DWORD*)result2);
		sub_82582C10(*(DWORD*)result3);


		return a1;
	}


//	char* Die = "Die LOX";



	int * TagBattleSelectH(int a1,MPL* P3N,int a3 = 0){

		int *result; // r3
		int *v3; // r26
		int v4; // r3
		int v5; // r10
		int *v6; // r29
		int v7; // r3
		_DWORD *v8; // r4
		int v9; // r10
		int v10; // r3
		_DWORD *v11; // r3
		int v12; // r10
		int v13; // r11
		int v14; // r11
		int v15; // r11
		int v16; // r11
		int v17; // r3
		int v18; // r11fGe
		int v19; // r10
		int v20; // r3
		int v21; // r10
		int v22; // r3
		int *v23; // r29
		int* v24;

		_DWORD v25[2]; // r4
		int v26; // r4
		int v27; // r10
		int v28; // r3
		int v29; // r10
		int v30; // r3
		int v31; // r10
		int v32; // r3
		int v33; // r10
		int v34; // r3
		_DWORD *v35; // r3
		int *v36; // r30
		int v37; // r29
		int v38; // r11
		int v39; // r11
		int v40; // r11
		int v41; // r11
		int v42; // r3
		int v43; // r10
		int v44; // r3
		_DWORD v45[2]; // [sp+58h] [-B8h] BYREF
		_DWORD v46[2]; // [sp+60h] [-B0h] BYREF

		int v47[2]; // [sp+60h] [-B0h] BYREF

		//unsigned __int16 *v47; // [sp+64h] [-ACh] BYREF
		int v48[3]; // [sp+68h] [-A8h] BYREF
		int v49; // [sp+78h] [-98h] BYREF
		int v50; // [sp+7Ch] [-94h]
		int v51; // [sp+80h] [-90h]
		int v52[4]; // [sp+88h] [-88h] BYREF
		int v53[4]; // [sp+98h] [-78h] BYREF
		int v54[4]; // [sp+A8h] [-68h] BYREF
		int v55[4]; // [sp+B8h] [-58h] BYREF
		int v56[18]; // [sp+C8h] [-48h] BYREF

		int savedX;

		int some;
		result = (int *)sub_82581078(a1);
		v3 = result;
		switch (P3N->PCase){
			case  0:

				if (P3N->P2PListener != 0xFFFF){


					if (P3N->P2U1[0]){
						P3N->P2U1[0]=0;
						v11 = (_DWORD *)P3N->P2U1[1];
						P3N->P2U1[1] = 0;
						if ( v11 )
							sub_821601B8((int)v11);
					}
					
					P3N->P2PListener = 0xFFFF;
				}
				
			

				v5 = P3N->P2U1[0];
				P3N->P2PListener = 0xFFFF;
				if (!v5){
					
					v7 = (*(int (__fastcall **)(int *, _DWORD))(*v3 + 320))(v3, a3);

					v6 = (int*)malloc06(64);
					if (v6){
						v7 = (*(int (__fastcall **)(int *, _DWORD))(*v3 + 320))(v3, a3);
						v8 = (DWORD*)sub_824FCFA0(v6, (int)&P3N->P2PListener, v7, (int)v3);
					}
					else{
						v8 = 0;
					}
					v45[0] = (DWORD)v8;
					sub_824FD4F8(&v45[1], (int)v8,0);
					BoostWeakPtr(P3N->P2U1, v45);
					if ( v45[1] )
						sub_821601B8(( int)v45[1]);
					result = (int *)(*(int (__fastcall **)(int *, int, _DWORD))(*v3 + 52))(v3, P3N->P2U1[0], 0);// sub_825E9480

				}
				P3N->PCase = 1;
				P3N->P2Input = 0;
				break;
			case  1:

	
				if (P3N->P2PListener == 0xFFFF){
					return 0;
				}



				//ShowXenonMessage(L"MSG",(int)P3N->P2PListener,"");
				P3N->P2U1[0]=0;
				v11 = (_DWORD *)P3N->P2U1[1];
				P3N->P2U1[1] = 0;



				if ( v11 )
					sub_821601B8((int)v11);


				for (int i = 0;i<sizeof(PLR)/sizeof(MPL);i++){
					if (&PLR[i] == P3N){
						continue;
					}
					if (PLR[i].P2PListener == P3N->P2PListener && PLR[i].PCase != 1){
						//ShowXenonMessage(L"X",i,"");
						//ShowXenonMessage(L"X",PLR[i].PCase,"");
						P3N->PCase = 0;
						return 0;
					}
				}



				result = (int *)sub_824FD460((int)a1, (int)"main_deside");

				P3N->PCase = 2;
				P3N->P2Input = 0;

				break;
			case 2:
				//ShowXenonMessage(L"Message",P3N->vd,"");
				


				//*(BYTE*)&P3N->vd=1;
				 *((_BYTE *)a1 + 660) = 1;

				v15 = P3N->act_chr | 0xC0000 | P3N->PID;
				v48[1] = 3;                               // Cursor
				v48[2] = v15;
				v16 = *(_DWORD *)(a1 + 132);
				v48[0] = 110608;
				(*(void (__fastcall **)(int, int *))(*(_DWORD *)(v16 + 40) + 4))(v16 + 40, v48);

				v22 = *(_DWORD *)(a1 + 132) + 40;
				v48[0] = 110608;
				v48[1] = 5;
				v48[2] = 0 | P3N->PID;
				(*(void (__fastcall **)(int, int *))(*(_DWORD *)v22 + 4))(v22, v48); // Character Name

				v18 = P3N->P2PListener | 0xC0000 | P3N->PID;
				v48[1] = 8;
				v48[2] = v18;
				v17 = *(_DWORD *)(a1 + 132) + 40;
				(*(void (__fastcall **)(int, int *))(*(_DWORD *)v17 + 4))(v17, v48); //Controller Number


				//ShowXenonMessage(L"MSG",(int)&P3N->trs,"asg");
		
				if ( P3N->P2U1[0])
				{
					P3N->P2Input = 0;
					return 0;
				}

				GetSelectedCharacterLUA((int)a1, &P3N->trs.rot, P3N->act_chr);
				P3N->PCase = 3;
			

				v5 = P3N->P2U1[0];
		
				//P3N->P2PListener = 0xFFFF;
				if (!v5){

					
					
					//v6 =  (int*)BranchTo(0x82186158,int,60);
					//v6 =  (int*)malloc06(60);
					v6 = (int*)malloc06(60);
					if (v6){
						v7 = (int)sub_82581078(a1);
						v8 = (DWORD*)sub_824FC880(v6, (int)&P3N->P2Input, v7);
					}
					else{
						v8 = 0;
					}
					v45[0] = (DWORD)v8;
					sub_824FD5C0(&v45[1], (int)v8,0);
					BoostWeakPtr(P3N->P2U1, v45);
					if ( v45[1] )
						sub_821601B8(( int)v45[1]);
					result = (int *)(*(int (__fastcall **)(int *, int, _DWORD))(*v3 + 52))(v3, P3N->P2U1[0], P3N->P2PListener);// sub_825E9480

				}

			//	v23 = (int*)malloc(60);
			//	if ( v23 )
				{
			//		v24 = (int*)sub_82581078(a1);
			//		v25[1] = (DWORD)sub_824FC880(v23, (int)&P3N->P2Input, (int)v24);
				}
			//	else
				{
			//		v25[1] = 0;
				}

			//	v46[0] = (DWORD)v25[1];
			//	sub_824FD5C0(&v46[1], (DWORD)v25[1],0);
			//	BoostWeakPtr(P3N->P2U1, v46);
			//	if ( v46[1] )
			//		sub_821601B8(v46[1]);

			//	result = (int *)(*(int (__fastcall **)(int *, int, _DWORD))(*v3 + 52))(v3, P3N->P2U1[0], P3N->P2PListener);
				P3N->P2Input = 0;

				break;
			case 3:




				if ((P3N->P2Input & 0x10) != 0){
					



					v22 = *(_DWORD *)(a1 + 132) + 40;
					v48[0] = 110608;
					v48[1] = 4;
					v48[2] = P3N->act_chr | 0xC0000 | P3N->PID;
					(*(void (__fastcall **)(int, int *))(*(_DWORD *)v22 + 4))(v22, v48); // Character Name

					sub_824FD460((int)a1, (int)"main_deside");

					P3N->P2Input = 0;

					P3N->PCase = 4;

					return 0;

				}
				//Unfinished
				if ((P3N->P2Input & 0x20) != 0){

			

					v22 = *(_DWORD *)(a1 + 132) + 40;
					v48[0] = 110608;
					v48[1] = 4;
					v48[2] = P3N->act_chr | 0xC0000 | P3N->PID;
					(*(void (__fastcall **)(int, int *))(*(_DWORD *)v22 + 4))(v22, v48); // Character Name

					v48[1] = 9;
					v48[2] = P3N->P2PListener | 0xC0000 | P3N->PID;

					(*(void (__fastcall **)(int, int *))(*(_DWORD *)v22 + 4))(v22, v48); // Character Name

					v48[1] = 7;
					v48[2] = P3N->act_chr | 0xC0000 | P3N->PID;

					//(*(void (__fastcall **)(int, int *))(*(_DWORD *)v22 + 4))(v22, v48); // Character Name


					sub_824FCCD8((int)a1, P3N->act_chr);


					DWORD v355;
					

				//	P3N->P2U1[0] = 0;
				//	DWORD* v35= (_DWORD *)P3N->P2U1[1];
				//	P3N->P2U1[1] = 0;
				//	if ( v35 )
				//		sub_821601B8(v35);
					P3N->PCase = 0;
					P3N->P2Input = 0;



					some = BranchTo(0x82169F30,int);
					some = (44*P3N->P2PListener+((int)some));
					//ShowXenonMessage(L"MSG",*(int*)some,"");


				//	P3N->P2PListener = 0xFFFF;
				//	ShowXenonMessage(L"MSG",P3N->P2U1[1],"");
				
					

		
					(int *)sub_824FD460((int)a1, (int)"window_close");
			
				}


				savedX = P3N->act_chr;

				result = (int *)CharacterSelectorFunction((int)a1, P3N->P2Input, 9, &P3N->act_chr);
				//result = 0;


				if ( !(_BYTE)result )
					break;

			


				v42 = *(_DWORD *)(a1 + 132) + 40;
				v55[1] = 5;
				v55[0] = 110608;
				v55[2] = P3N->act_chr | P3N->PID;
				(*(void (__fastcall **)(int, int *))(*(_DWORD *)v42 + 4))(v42, v55);
				
				
				sub_824FCCD8((int)a1, savedX);
				GetSelectedCharacterLUA((int)a1, (int)&P3N->trs.rot, P3N->act_chr);
				P3N->P2Input = 0;






				break;
			case  4:

			
			

				if ((P3N->P2Input & 0x20) != 0){

					v22 = *(_DWORD *)(a1 + 132) + 40;
					v48[0] = 110608;
					v48[1] = 3;
					v48[2] = P3N->act_chr | 0xC0000 | P3N->PID;
					(*(void (__fastcall **)(int, int *))(*(_DWORD *)v22 + 4))(v22, v48); // Character Name
					P3N->PCase = 3;

				}

				P3N->P2Input = 0;




				break;
		}

		


		return 0;

	}

	HOOK(int ,__fastcall ,TagBattleSelect,0x824FEC98,int a1){

		




		TagBattleSelectH(a1,&PLR[0]);


		for (int i = 1;i<3;i++){
			if (!PLR[i-1].P2U1[0])continue;
			if (PLR[i-1].PCase >= 3 || PLR[i].PCase >= 3){
				 TagBattleSelectH(a1,&PLR[i]);
			}
			
		}

	

		//P3
	
		//P4
		//TagBattleSelectH(a1,&PLR[2]);
		





		


		
		return (a1);
		


	}






	HOOK(int, __fastcall,MainMenuTaskUIH,0x824FFCF8,int* a1,double a2){
		//		Die = "Test";
		int v432;
		int v433;
		int v434;
		int v435;
		int v436;
		int v467;


		int v7  = (int)sub_82581078((int *)a1);
		int result;
		int* v451;
		int v450;
		int v466;
		int ChrList[] = 
		{(int)"sonic_new",
		(int)"shadow",
		(int)"silver",
		(int)"tails",
		(int)"amy",
		(int)"rouge",
		(int)"knuckles",
		(int)"omega",
		(int)"blaze"};

		int v484[7];

		void (__fastcall *v468)(int, _DWORD);

		int pCount = 1;
		std::vector<int> pvector ;


		std::string v817;
		int v246;
		int v247;
		int v248;
		int v604[3];
		int v249;

		int v610[3];

		int v263;

		int v257;
		int v258;

		int v250;
		int v251;
		int v252;
		int v253;
		int *v254;


		int v606[3];

		int v256;


		int v255;


		int v542[3];






		//		int cuse = ***(int ***)(a1 + 76);
		//		ShowXenonMessage(L"MSG",cuse,"");



		switch (a1[19]){

			case 30:
			case 34:

				implOfTagBattleSelect((int)a1);
				v246 = a1[159];
				if ( (v246 & 0x10) != 0 )
				{
					v247 = a1[53];
					v248 = a1[33] + 40;
					v604[1] = 4;
					v604[0] = 110608;
					v604[2] = v247 | 0xC0000;
					(*(void (__fastcall **)(int, int *))(*(_DWORD *)v248 + 4))(v248, v604);
					v249 = 31;
					if ( a1[19] != 30 )
						v249 = 35;
					a1[19] = v249;
					result = sub_824FD460((int)a1, (int)"main_deside");
					a1[159] = 0;
					a1[156] = 0;
					a1[159] = 0;
					return 0;
				}
				if ( (v246 & 0x20) != 0 ){

					v542[2] = a1[53];
					v542[0] = 110608;
					v542[1] = 7;
					(*(void (__fastcall **)(int, int *))(*(_DWORD *)(a1[33] + 40) + 4))(a1[33] + 40, v542);
					v542[1] = 9;
					v250 = (*(int (__fastcall **)(int, _DWORD))(*(_DWORD *)v7 + 320))(v7, 0) | 0xC0000;
					v251 = a1[33] + 40;
					v542[2] = v250;
					(*(void (__fastcall **)(int, int *))(*(_DWORD *)v251 + 4))(v251, v542);


					v252 = a1[29] + 40;
					v253 = a1[53];
					if ( a1[19] == 30 )
					{
						v254 = v604;
						v255 = (16 * a1[54]) | 0xB0000;
						v604[0] = 110675;
						v604[2] = v255 | v253;
						v604[1] = 62;
					}
					else
					{
						v254 = v606;
						v606[1] = 78;
						v606[0] = 110675;
						v606[2] = (16 * a1[54]) | 0xB0000 | v253;
					}
					(*(void (__fastcall **)(int, int *))(*(_DWORD *)v252 + 4))(v252, v254);
					v256 = a1[39];
					a1[19] = 22;
					sub_824FDB20(v256);
					sub_824FD388(a1, (int)"mainmenu");
					sub_824FD460((int)a1, (int)"window_close");
					a1[156] = 0;
					a1[159] = 0;
					sub_824FCDA0(a1);
					result = (int)sub_824FDD80((int)a1);
					a1[159] = 0;
					return 0;

				}


				v258 = a1[53];
				result = CharacterSelectorFunction((int)a1, v246, 9, a1 + 53);


				if ( !(_BYTE)result )
					return 0;

				v263 = a1[33] + 40;
				v610[0] = 110608;
				v610[2] = a1[53];
				v610[1] = 5;
				(*(void (__fastcall **)(int, int *))(*(_DWORD *)v263 + 4))(v263, v610);
				sub_824FCCD8((int)a1, v258);
				result = GetSelectedCharacterLUA(a1, (int)0x82D37E80, a1[53]);
				a1[159] = 0;



				return 0;



			case 0x3B:


				if ( !a1[156] )
					return 0;
				v432 = a1[35];
				if ( v432 && (unsigned __int8)sub_82581380(v432) )
				{
					v433 = a1[35];
					if ( v433 )
						(*(void (__fastcall **)(int, int))(*(_DWORD *)v433 + 4))(v433, 1);
					a1[35] = 0;
				}
				v434 = a1[29];
				a1[29] = 0;
				if ( v434 )
					sub_82581E38(v434);
				result = (*(int (__fastcall **)(int))(*(_DWORD *)v7 + 180))(v7);
				v435 = a1[40];
				v436 = result;
				if ( v435 )
				{
					if ( v435 != 1 )
					{

						a1[159] = 0;
						a1[19] = 63;
						return 0;
					}
					std::vector<int> PF1;
					for (int i = 0 ;i<3;i++){

						PLR[i].P2U1[0] = 0;
						DWORD* v35= (_DWORD *)PLR[i].P2U1[1];
						PLR[i].P2U1[1] = 0;
						if ( v35 )
							sub_821601B8((int)v35);
						PLR[i].PCase = 0;
						PLR[i].P2Input = 0;
					//	PLR[i].P2PListener = 0;

						if (PLR[i].P2PListener == 0xFFFF){
							continue; //Null Listener
						} 
						PF1.push_back(PLR[i].P2PListener); // Listener
						PF1.push_back(PLR[i].act_chr); // Selected Character
						//Free P2PListener
						
					
					}
					int PCount = 1+(int)(PF1.size()/2);
				
					sub_821EDDB0(result, PCount); // Player Count

					byte ChrString[0x1C];
					BranchTo(0x821620E8,int,&ChrString,ChrList[a1[53]]);
					

					//sub_82186138(v436, 0, new std::string((char*)ChrList[a1[53]]));//Set P1 Character Lua
					sub_82186138(v436, 0, &ChrString);//Set P1 Character Lua

					for (int i = 0 ;i<PF1.size();i+=2){
						//Set Player Controller
						int num = (i/2)+1;
					//	(*(void (__fastcall **)(int, int, int))(*(_DWORD *)v7 + 316))(v7, num, PF1[i]);
						//Set P2,P3,P4 Character Lua

						byte ChrListZ[0x1C];
						BranchTo(0x821620E8,int,&ChrListZ,ChrList[PF1[i+1]]);
						sub_82186138(v436, num, &ChrListZ);
					//	sub_82186138(v436, num, new std::string((char*)ChrList[PF1[i+1]]));
		
					}
					DWORD handle1;
					if (PCount == 3){
						
					//	int result1 = ArcHandle(&handle1,new std::string("DLL/cache_3P.arc"),2,1);
					//	sub_82582C10(*(DWORD*)result1);
					}
					else if (PCount == 2){
					//	int result1 = ArcHandle(&handle1,new std::string("DLL/cache_2P.arc"),2,1);
					//	sub_82582C10(*(DWORD*)result1);

						//result1 = ArcHandle(&handle1,new std::string("DLL/sprites_2P.arc"),2,0);
						//sub_82582C10(*(DWORD*)result1);
					}

			

					
					
					sub_826314F8(v436, 2); //Rule 2=Battle,1 Tag
					if ( a1[42] )
					{
						sub_826314F8(v436, 2);
						v467 = 4 * a1[55];
						v468 = *(void (__fastcall **)(int, _DWORD))(*(_DWORD *)v7 + 152);
						v484[0] = (int)":scripts/mission/4000/mission_b4001.lua";
						v484[1] = (int)":scripts/mission/4000/mission_b4002.lua";
						v484[2] = (int)":scripts/mission/4000/mission_b4003.lua";
						v484[3] = (int)":scripts/mission/4000/mission_b4004.lua";
						v484[4] = (int)":scripts/mission/4000/mission_b4005.lua";
						v484[5] = (int)":scripts/mission/4000/mission_b4006.lua";
						v484[6] = (int)":scripts/mission/4000/mission_b4007.lua";
						v468(v7, *(int *)((char *)&v484 + v467));
						(*(void (__fastcall **)(int, int))(*(_DWORD *)v7 + 328))(v7, 33);
						v466 = 6;
					}
					else
					{
							sub_826314F8(v436, 1);
						(*(void (__fastcall **)(int, const char *))(*(_DWORD *)v7 + 152))(
							v7,
							"wvo/tag/a:scripts/mission/3000/mission.lua");
						(*(void (__fastcall **)(int, int))(*(_DWORD *)v7 + 328))(v7, 31);
						v466 = 5;
					}
					(*(void (__fastcall **)(_DWORD, int, _DWORD, int))(**(_DWORD **)(v7 + 20) + 12))(
						*(_DWORD *)(v7 + 20),
						12,
						0,
						v466);
					v451 = *(int **)(v7 + 20);
					v450 = *v451;
					result = (*(int (__fastcall **)(int *, int, _DWORD, _DWORD))(v450 + 12))(v451, 11, 0, 0);
					a1[159] = 0;
					a1[19] = 63;
				}

				return 0;


			default:
				MainAsmHookIline(a1,a2);





		}
	}

	struct uni{
		int v1;
		int v2;
	};
	std::vector<uni> vec;

	int __fastcall ObjectEvents(int a1, int *a2){



		bool ok = false;

		for (int i = 0;i<vec.size();i++){

			if (vec[i].v1 == *a2){
				vec[i].v2++;
				ok = true;
			}
			
		}

		if (!ok)
		{
			uni u = {*a2,1};
			vec.push_back(u);
		}

		if (ATG::Input::GetMergedInput(0)->wPressedButtons & XINPUT_GAMEPAD_Y){


			std::string* Buff = new std::string();
			for (int i = 0;i<vec.size();i++){


				std::ostringstream ss;
				ss << std::hex << vec[i].v1;

				std::ostringstream ss2;
				ss2 << std::hex << vec[i].v2;


			    Buff->append(ss.str().c_str());
				Buff->append("-");
				Buff->append(ss2.str().c_str());
				Buff->append("\n");


			}
			ShowXenonMessage(L"MsgNext",Buff->c_str());

		}

		int s2 = (int)(a2);

		if ( *a2 == 0x15030 ){

			//DWORD v5 = *(_DWORD *)(s2 + 4);
			//v6 = *(unsigned __int8 **)(a2 + 4);
			//while ( *v6++ )
			//	;
			//NewString((std::string *)(a1 + 6224), v5, (unsigned int)&v6[-*(_DWORD *)(a2 + 4) - 1]);// TOWN
			//DWORD* v8 = (_DWORD *)(a1 + 6288);
			//int* v9 = (int *)(s2 + 40);
		//	int v10 = 5;
		//	*(_DWORD *)(a1 + 6256) = *(_DWORD *)(s2 + 8);
		//	*(_DWORD *)(a1 + 6260) = *(_DWORD *)(s2 + 12);
		//	*(_DWORD *)(a1 + 6264) = *(_DWORD *)(s2 + 16);
		//	int v11;
		//	do
			//{
			//	--v10;
			//	*(v8 - 5) = *(v9 - 5);
			//	v11 = *v9++;
		//		*v8++ = v11;
		//	}
		//	while ( v10 );
			//v12 = *(unsigned __int8 **)(a2 + 64);
			//while ( *v12++ )
		//		;
		//	NewString((std::string *)(a1 + 6308), *(_DWORD *)(a2 + 64), (unsigned int)&v12[-*(_DWORD *)(a2 + 64) - 1]);// RESULT TOWN
			
			//*(_DWORD *)(a1 + 6252) = *(_DWORD *)(s2 + 60);
			*(_DWORD *)(a1 + 8) = 4; // 5 Exit Stage
			// 6 Open Window

			// 4 Goal
			//*(std::string **)(a1 + 6308) = new std::string("result_end");
			//*(std::string **)(a1 + 6224) = new std::string("TOWN");

			   //ShowXenonMessage(L"MsgNext",*(char **)(s2 + 40));
				//ShowXenonMessage(L"MsgNext",*(char **)(s2 + 64));

			// *a2 = 0x15030; 
			return 0;
		}
	



		return BranchTo(0x8217BB68 ,int,a1,a2);


	}


#pragma section(".text")
	int myvar  = 0x4E800020;





	void GlobalInstall(){


		//INSTALL_HOOK(sub_824EB460);	

		//WRITE_NOP(0x824FECB8,6);
	//	WRITE_DWORD(0x824FECB8,0x7FE3FB78);
	//	WRITE_DWORD(0x824FECD0,0x7C6903A6);



		
//		BranchTo(&myvar,void);



		

//		WRITE_DWORD(0x82001AF0 ,ObjectEvents);
		//Timed Disable Condition For Check Next
		WRITE_NOP(0x8250285C,1);

//		WRITE_DWORD(0x82039C10,(DWORD)MainMenuTaskUIH);
INSTALL_HOOK(MainMenuTaskUIH);

INSTALL_HOOK(sub_82160B98);

//INSTALL_HOOK(sub_824D3B18);

		


		INSTALL_HOOK(TagBattleSelect);
		WRITE_DWORD(0x824EAEEC,POWERPC_LIS(11,POWERPC_HI((int)Pnamer)));
		WRITE_DWORD(0x824EAF04,POWERPC_ADDI(11,11,POWERPC_LO((int)Pnamer)));

		WRITE_DWORD(0x824EAF5C,0x81010058); //lwz r8,0x58(r1)
		WRITE_DWORD(0x824EAF8C,0x81010058); //lwz r8,0x58(r1)

		WRITE_DWORD(0x824EAE44,POWERPC_LIS(11,POWERPC_HI((int)Cursors)));
		WRITE_DWORD(0x824EAE48,POWERPC_ADDI(11,11,POWERPC_LO((int)Cursors)));

		WRITE_DWORD(0x824EAE78,0x81210058); // lwz      r9, 0x58(r1)
		WRITE_DWORD(0x824EAEA4,0x81210058); // lwz      r9, 0x58(r1)

		WRITE_DWORD(0x824EAFDC,POWERPC_LIS(11,POWERPC_HI((int)Controlers)));
		WRITE_DWORD(0x824EAFF8,POWERPC_ADDI(11,11,POWERPC_LO((int)Controlers)));

		WRITE_DWORD(0x824EB050,0x81010058); // lwz      r8, 0x58(r1)
		WRITE_DWORD(0x824EB080,0x81010058); // lwz      r8, 0x58(r1)

		WRITE_DWORD(0x8203A028,(DWORD*)0x43960000); //300 Z
		WRITE_DWORD(0x8203A030,(DWORD*)0xC36B0000); //-235 X
		WRITE_DWORD(0x8203A02C,(DWORD*)0xC2BE0000); //-95 Y

		WRITE_DWORD(0x8203A024,(DWORD*)0x43720000); //242 X






	//	WRITE_DWORD((0x82B17218+0x4),StateTable);
	//	DWORD dw;


	//	DWORD zx = {0x4E800020};

	   //((void* (__fastcall *)())zx)();

     //  test = Detour( (void*)(0x82219530) , (void*)(DWORD)Context_Sonic_Core );
	  // test.Install();


//VirtualAlloc(NULL,512,MEM_RESERVE | MEM_COMMIT | ME)
 HANDLE hSection;
 

 
 LARGE_INTEGER MaxSize = { 0x100000 };


 
 
 
 
 //void* po = VirtualAlloc(NULL,512,MEM_COMMIT | MEM_RESERVE,PAGE_EXECUTE_READWRITE);

// HANDLE HC = HeapCreate(HEAP_CREATE_ENABLE_EXECUTE,512,1024);

 //HeapAlloc(HC,MEM_COMMIT |)
 
 
 //memcpy(po,(void*)0x826DE930,4);
 //*(int*)po=0x42415012;



 
  //BranchTo((int)po,void);



	 //  byte func1[4] = { 0x4E,0x80,0x00,0x20 };
	   //(reinterpret_cast<void (*)()>(&func1))(); //Convertion a function type to a pointer to function type


	   

	  // *((int*)test.FuncVoid()) =0x4E800020;

	   //ShowXenonMessage( L"T", *((int*)test.FuncVoid()),"");
	    //*test.GetOriginal<int*>() = 0x4E800020;



	

//		INSTALL_HOOK(LoadFromArc);

	}
}




namespace DebugLogRestore{

	struct tust{
		char* s1;
		DWORD a2;
		
	
	};









	
	std::vector<std::string*> log;

	struct TX06Zero{
		char* Animation;
		int Type;
		int value;
		int time;
	};

	extern "C" void PrintTable(lua_State *L,std::string* stri,int zx = 0)
	{
		lua_pushnil(L);

		while(lua_next(L, -2) != 0)
		{
			if(lua_isstring(L, -1)){
				stri->append(lua_tostring(L, -2));
			    stri->append("=");
				stri->append(lua_tostring(L, -1));
				stri->append(" ");

				}
			else if(lua_isnumber(L, -1)){
				stri->append(lua_tostring(L, -2));
			    stri->append("=");

				int a = lua_tonumber(L,-1);
				std::stringstream ss;
				ss << a;
			
			    stri->append(ss.str());
				stri->append(" ");
			}
			else if(lua_istable(L, -1))
			{
			//	stri->append(lua_tostring(L, -2));
			//	lua_tonumber(L,-1);
		
			//	lua_getfield())
			
				stri->append("={\n");
				PrintTable(L,stri,zx+1);
				stri->append("\n}\n");



			}
			else//MB
			{
				return;
			}
 
			lua_pop(L, 1);
		}

	}



	extern "C" static int XenonMessage(lua_State* L,std::string** so){


		int ltype = lua_type(L,-1);

		std::stringstream ss;
		TX06Zero zx;




		*so = new std::string("Type : ?? ");
		//so->append(std::to_string(ltype));

		switch (ltype){
			case LUA_TNIL:
				*so = new std::string("NIL");
				break;
			case LUA_TBOOLEAN:
				*so = new std::string(lua_toboolean(L,1) == true ? "true" : "false");
				break;
			case LUA_TLIGHTUSERDATA:

				//				so = new std::string("LightTable : \n{\n");
				//				PrintTable(L,so);

luabridge:
				//	so = new std::string("N");

				//				so->append("\n}");

				break;
			case LUA_TNUMBER:
			case LUA_TSTRING:
				*so = new std::string(lua_tostring(L,-1));
				break;
			case LUA_TTABLE:

				*so = new std::string("Table Not Supported");
				//		PrintTable(L,so);

				//lua_pushstring(L,"__tostring");

				//	so = new std::string("N");

				//	so->append("\n}");
				//so->insert(0," : ");

				break;
			case LUA_TFUNCTION:
				*so = new std::string("Not Supported LUA_TFUNCTION");
				break;
			case LUA_TUSERDATA:
				//	static_cast<int*>(lua_to(L, -3));
				*so = new std::string("Not Supported LUA_TUSERDATA");
				break;
			case LUA_TTHREAD:
				*so = new std::string("Not Supported LUA_TTHREAD");
				break;


		}

		

		return 0;
	}


	static int luaB_print (lua_State *L) {
	
		int n = lua_gettop(L);  /* number of arguments */
		int i;
		lua_getglobal(L, "tostring");
		for (i=1; i<=n; i++) {
			const char *s;
			lua_pushvalue(L, -1);  /* function to be called */
			lua_pushvalue(L, i);   /* value to print */
			lua_call(L, 1, 1);
			s = lua_tostring(L, -1);  /* get result */
			if (s == NULL)
				return luaL_error(L, "`tostring' must return a string to `print'");

			log.push_back(new std::string(s));

			//if (i>1) fputs("\t", stdout);
			//fputs(s, stdout);
			lua_pop(L, 1);  /* pop result */
		}
		fputs("\n", stdout);
		return 0;
	}


	
	extern "C" static int  Log(lua_State* L){

	
		
		std::string* so = new std::string();
		XenonMessage(L,&so);
		

		log.push_back(so);


			return 0;
	
	}
	


	static const luaL_reg tx2[] = {
		{"print", Log},



		{NULL, NULL}
	};



	extern "C" static int GetPlayerRawInput(lua_State* L)
	{
		int n = lua_gettop(L);  
		if (n <= 0) 

		{lua_pushnumber(L, 0); return 1;}


		UINT32 PlayerIndex = (UINT32)lua_tonumber(L,1);
		Sonicteam::DocMarathonImp* impl = 	*(Sonicteam::DocMarathonImp**)(*(UINT32*)0x82D3B348 + 0x180);
		PlayerIndex = impl->GetRealControllerID(PlayerIndex);
		Sonicteam::Player::Input::IListenerInputStruc01* Inp2 = (Sonicteam::Player::Input::IListenerInputStruc01*)impl->GetPlayerInput(PlayerIndex);

		Sonicteam::Player::Input::IListenerInputStruc01 Inp;


		if (Inp2){
			memcpy(&Inp,Inp2,sizeof(Sonicteam::Player::Input::IListenerInputStruc01));
		}


		BranchTo(0x825D5C30,int,L); //lua_newtable


		//RtlReAllocateHeap NOT same :|

		BranchTo(0x825D5918,int,L,"Buttons");
		//BranchTo(0x825D5890,int,L,Inp.wLastButtons);
		lua_pushnumber(L, Inp.wLastButtons);
		BranchTo(0x825D5D98,int,L,-3);



		BranchTo(0x825D5918,int,L,"LStickX");
		BranchTo(0x825D5890,int,L,Inp.fX1);
		BranchTo(0x825D5D98,int,L,-3);


		BranchTo(0x825D5918,int,L,"LStickY");
		BranchTo(0x825D5890,int,L,Inp.fY1);
		BranchTo(0x825D5D98,int,L,-3);

		BranchTo(0x825D5918,int,L,"RStickX");
		BranchTo(0x825D5890,int,L,Inp.fX2);
		BranchTo(0x825D5D98,int,L,-3);

		BranchTo(0x825D5918,int,L,"RStickY");
		BranchTo(0x825D5890,int,L,Inp.fY2);
		BranchTo(0x825D5D98,int,L,-3);

		
		/*

		lua_pushstring(L, "Buttons");
		lua_pushnumber(L, Inp.wLastButtons);
		lua_settable(L, -3);

		lua_pushstring(L, "LStickX");
		lua_pushnumber(L, Inp.fX1);
		lua_settable(L, -3);

		lua_pushstring(L, "LStickY");
		lua_pushnumber(L, Inp.fY1);
		lua_settable(L, -3);

		lua_pushstring(L, "RStickX");
		lua_pushnumber(L, Inp.fX2);
		lua_settable(L, -3);

		lua_pushstring(L, "RStickY");
		lua_pushnumber(L, Inp.fY2);
		lua_settable(L, -3);

	
*/




		return 1;
	}

	extern "C" static int GetPlayerInput(lua_State* L){


	
		int n = lua_gettop(L);  
		if (n <= 0) 
		{lua_pushnumber(L, 0); return 1;}


		UINT32 PlayerIndex = (UINT32)lua_tonumber(L,1);
		Sonicteam::DocMarathonImp* impl = 	*(Sonicteam::DocMarathonImp**)(*(UINT32*)0x82D3B348 + 0x180);
		PlayerIndex = impl->GetRealControllerID(PlayerIndex);
		Sonicteam::Player::Input::IListenerInputStruc01* Inp = (Sonicteam::Player::Input::IListenerInputStruc01*)impl->GetPlayerInput(PlayerIndex);
		
		if (!Inp || Inp->PtrKhronoControlInputListener == 0){
			lua_pushnumber(L, 0); return 1;
		}


		Sonicteam::SoX::RNodeF<Sonicteam::SoX::Object>* h = (Sonicteam::SoX::RNodeF<Sonicteam::SoX::Object>*) &Inp->PtrMyInputObj;
		Sonicteam::SoX::RNodeF<Sonicteam::SoX::Object>* temp = (Sonicteam::SoX::RNodeF<Sonicteam::SoX::Object>*)h->Next;


		if (h->Next != h->Previous){
			while (h != temp){

				if (temp->Next == temp->Previous) {temp =0;}

				if (temp->FObject && dynamic_cast<Sonicteam::Player::Input::IListener*>(temp->FObject) != 0){
					break;
				}
				temp = (Sonicteam::SoX::RNodeF<Sonicteam::SoX::Object>*)temp->Next;
			}
		}
		else{
			temp = 0;
		}

		if (temp && temp->FObject) {
			Sonicteam::Player::Input::IListener* il =   dynamic_cast<Sonicteam::Player::Input::IListener*>(temp->FObject);
			if (il){
				lua_pushnumber(L, il->ListenerGetResult()); 
			}
		}
		else{
			lua_pushnumber(L, 0); 
		}
		
		return 1;
	}

	extern "C" static int PrintNext(lua_State* L){

		int n = lua_gettop(L);  /* number of arguments */
		int i;
		lua_getglobal(L, "tostring");
		for (i=1; i<=n; i++) {
			const char *s;
			lua_pushvalue(L, -1);  /* function to be called */
			lua_pushvalue(L, i);   /* value to print */
			lua_call(L, 1, 1);
			s = lua_tostring(L, -1);  /* get result */
			if (s == NULL)
				return luaL_error(L, "`tostring' must return a string to `print'");
			
			std::string msg =  std::string(s);

			int length = msg.length() + 1;
			wchar_t* wcharPtr = new wchar_t[length];
			std::memset(wcharPtr, 0, length * sizeof(wchar_t));
			std::mbstowcs(wcharPtr, msg.c_str(), length);


			int MCount = DebugMessages.size();
			if (MCount > 2){
				MCount--;
				std::vector<int>::iterator it = DebugMessages.begin();
				BranchTo(0x8262BA68,int,*it,1); //Destroy from mem
				std::advance(it, 0);
				DebugMessages.erase(it);

				//Re Order Messages
				
				int cc = 0;
				for (std::vector<int>::iterator it = DebugMessages.begin(); it != DebugMessages.end(); ++it) {
					ChangeMessagePositionY( *it,(cc * 28) );
					cc++;
				}
			}

			DebugMessages.push_back( SpawnMessage(wcharPtr,(MCount * 28)));
	
			//if (i>1) fputs("\t", stdout);
			//fputs(s, stdout);
			lua_pop(L, 1);  /* pop result */
		}
		fputs("\n", stdout);
		return 0;

	}
	extern "C" static int GetPlayerPosition(lua_State* L){

		int n = lua_gettop(L);  
		if (n <= 0) 
		{lua_pushnumber(L, 0); return 1;}


		UINT32 PlayerIndex = (UINT32)lua_tonumber(L,1);
		Sonicteam::DocMarathonImp* impl = 	*(Sonicteam::DocMarathonImp**)(*(UINT32*)0x82D3B348 + 0x180);
		UINT32 vft =  *(UINT32*)impl->DocCurrentMode;
		UINT32 pstack[4] = {};
		if (vft == 0x82033534){ //GameMode

			UINT32 gameimp = *(UINT32*)(impl->DocCurrentMode + 0x6C);
			UINT32 ActorManager = *(UINT32*)(gameimp+0x11C4);
			UINT32 ActorMangerActorsCount = *(UINT32*)(ActorManager+0x80000);
			UINT32 PIX = 0;
			for (int i = 0;i<ActorMangerActorsCount;i++)
			{
				UINT32 Actor = *(UINT32*)(ActorManager+0x40000+(i*4));
				UINT32 ActorVFT = *(UINT32*)Actor;
				if (ActorVFT == 0x82003564){ //Object_Player


					Sonicteam::Player::State::IMachine* PlayerMashine = *(Sonicteam::Player::State::IMachine**)(Actor+0xE4);
					if (PlayerMashine){
						Sonicteam::Player::State::CommonContext* PCC = (Sonicteam::Player::State::CommonContext*)PlayerMashine->GetMashineContext().get();
						UINT32 PCC_AI = (UINT32)PCC->PlayerAIAmigoPlugin.get();
						UINT32 PCC_AI_FLAG = *(UINT32*)(PCC_AI + 0x24);
						if (PCC_AI_FLAG == 0) pstack[PIX++] = Actor;
					}
				}
			}
		}
		XMFLOAT4 POS;
		if (pstack[PlayerIndex] != 0){
			UINT32 ObjectPlayer = pstack[PlayerIndex];
			UINT32 PlayerPosture = *(UINT32 *)(ObjectPlayer + 0xDC);
			XMFLOAT4* PlayerPos = (XMFLOAT4*)(PlayerPosture + 0xB0);
			memcpy(&POS,PlayerPos,sizeof(XMFLOAT4));
		}

		
		BranchTo(0x825D5C30,int,L); //lua_newtable

		BranchTo(0x825D5918,int,L,"X");
		BranchTo(0x825D5890,int,L,POS.x);
		BranchTo(0x825D5D98,int,L,-3);

		BranchTo(0x825D5918,int,L,"Y");
		BranchTo(0x825D5890,int,L,POS.y);
		BranchTo(0x825D5D98,int,L,-3);

		BranchTo(0x825D5918,int,L,"Z");
		BranchTo(0x825D5890,int,L,POS.z);
		BranchTo(0x825D5D98,int,L,-3);
		




		return 1;

	}


	





	static const struct luaL_reg PET [] = {
		{"GetPlayerInput", GetPlayerInput},
		{"GetPlayerRawInput", GetPlayerRawInput},
		{"GetPlayerPosition",GetPlayerPosition},
		{"print",PrintNext},
		{NULL, NULL}  /* sentinel */
	};


	extern "C" static int PlayerEXT(lua_State* l){
		luaL_openlib(l,"player",PET,0);
		return 1;
	}

	static tust tx3[] = {	

		{"math",0x825DB498},
		{"script",0x82639830},
		{"level",0x825D9660},
		//{"player2",(DWORD)PlayerEXT},
		{
			NULL,NULL
		},
	};


	 static tust tx[] = {

		{"SetPlayer",0x82462948},
		{"StartEntityByName",0x824632A0},
		{"Signal",0x82463370},
		{"PlayBGM",0x824623D8},
		{"StopBGM",0x82462430},
		{"SetGenArea",0x82462A50},
		{"LoadTerrain",0x82462460},
		///	{"LoadTerrain",0x82462460},
		{"LoadSky",0x82463CB0},
		{"LoadStageSet",0x824624E8},
		{"LoadPath",0x82462548},
		{"LoadParticle",0x824626A8},
		{"LoadSceneParams",0x82463FE0},
		{"LoadLight",0x82464070},
		{"LoadSceneEnvMap",0x82464100},
		{"LoadReflectionAreas",0x82464190},
		{"LoadSoundBank",0x82462710},
		{"LoadVoiceBank",0x82462770},
		{"LoadCameraParam",0x82463D48},
		{"LoadRenderScript",0x82463DE0},
		{"LoadKynapse",0x82463E70},
		{"LoadTownsmanInfo",0x82463F28},
		{"LoadRaderMap",0x82464210},
		{"LoadObjectPhysics",0x824642A0},
		{"LoadExplosion",0x82464330},
		{"LoadEnemy",0x824643C0},
		{"LoadShot",0x82464450},
		{"DebugCommand",0x824649E0},
		{"LoadTimeLight",0x82464948},
		{"ProcessMessage",0x824627D0},
		{"InternalMessage",0x82462810},
		{"SeparateRenderAndExecute",0x82462850},
		{"SetAreaName",0x824644E0},
		{"PlayerIndexToActorID",0x82AD0700},
		{"LoadPEBank",0x82AD0700},
		{"PreloadPlayer",0x82AD0700},
		{"LoadCameraLib",0x82AD0700},
		{"LoadCameraSet",0x82AD0700},
		{"LoadEntityLib",0x82AD0700},
		{"CreateCameraTornado",0x82AD0700},
		{"CreateObjInfo",0x82AD0700},
		{"NewActor",0x82AD0700},
		{"LoadEvent",0x82AD0700},
		{"ChangeArea",0x82AD0700},
		{"SetupWorld",0x82AD0700},
		{"DestroyWorld",0x82AD0700},
		{"StartPlaying",0x82AD0700},
		{"Retry",0x82AD0700},
		{"End",0x82AD0700},
		{"Log",(DWORD)Log},
		{
			NULL,NULL
		}
	

	};

	extern "C" static int  LogNext(lua_State* L){


		std::string* so = new std::string();
		XenonMessage(L,&so);

		ShowXenonMessage(L"LogNext",so->c_str());


		return 0;

	}
	bool Showed = false;
	extern "C" static int  FixedMessage(lua_State* L){


	//	std::string* so = new std::string();
	//	XenonMessage(L,&so);

	//	MESSAGEBOX_RESULT result;
	//	XOVERLAPPED m_Overlapped; 
	
	//	XShowMessageBoxUI(0,L"FixedMessage",convertCharArrayToLPCWSTR(so->c_str()),1,g_pwstrButtonsX,1,XMB_ALERTICON,&result,&m_Overlapped);

	
		return 0;
	}

	//For Pointer* Work
	extern "C" static int GetIntField(lua_State* L){
		
		//int narg = lua_gettop(L);
		//if (narg < 2){
		//	lua_pushnil(L);
		//	return 0;
		//}

	//	if (lua_isnumber())
		int Struct = (int)lua_tonumber(L,1);
		int Value = (int)lua_tonumber(L,2);
		int endz = *(int*)(Struct + Value);

		lua_pushnumber(L,endz);
		


		return 1;
	}

	extern "C" static int GetFloatField(lua_State* L){

		//int narg = lua_gettop(L);
		//if (narg < 2){
		//	lua_pushnil(L);
		//	return 0;
		//}

		//	if (lua_isnumber())
		int Struct = (int)lua_tonumber(L,1);
		int Value = (int)lua_tonumber(L,2);
		int endz = *(float*)(Struct + Value);

		lua_pushnumber(L,endz);



		return 1;
	}

	extern "C" static int SetIntField(lua_State* L){

		//int narg = lua_gettop(L);
		//if (narg < 2){
		//	lua_pushnil(L);
		//	return 0;
		//}

		int Struct = (int)lua_tonumber(L,1);
		int Value = (int)lua_tonumber(L,2);
		int Setter = (int)lua_tonumber(L,3);
		*(int*)(Struct + Value) = Setter;




		return 0;
	}

	extern "C" static int BuildNewState(lua_State* L){
		
	
	

		return 0;

	}
	extern "C" static int WriteVirtialDword(lua_State* L){

		return 0;
	}


	extern "C" static int StateChangeState(lua_State* L){

		int bv = (int)lua_tonumber(L,1);
		int num = (int)lua_tonumber(L,2);

		Marathon::PlayerState::StateBaseValueP* w = (Marathon::PlayerState::StateBaseValueP*)bv;
		bool res = (bool)w->StateModule->ChangeState((int*)w,num);

		lua_pushboolean(L,res);
		return 1;


	}

	//Replace Custom State

	//Suported Only Pointers,Floats,INTS


	extern "C" int ArgumentsAnalys(lua_State* L,int i,int* a){

		switch (lua_type(L,i)){
		
			case LUA_TNUMBER:
				a[i-2]=(lua_tonumber(L,i)); //ADD ARGUMENT
			//	ShowXenonMessage(L"S",a[i-1],"");
				break;
			case LUA_TUSERDATA:
				break;
			case  LUA_TNIL:
				break;
			case LUA_TSTRING:
				a[i-2]=((int)lua_tostring(L,i));
				break;
			
		}


		return 0;
	}
	extern "C"  void __declspec( naked ) _cdecl CallCPLUSFuncHELPER(){
		__asm{
			    lwz r9,24(r12)
				lwz r8,20(r12)
				lwz r7,16(r12)
				lwz r6,12(r12)
				lwz r5,8(r12)
				lwz r4,4(r12)
				lwz r3,0(r12)
				blr
		}
	}


	extern "C" static int HEX(lua_State* L){


		const char* t = lua_tostring(L,1);

		unsigned int x;
		std::stringstream ss;
		ss << std::hex << t;
		ss >> x;
		lua_pushnumber(L,x);

		return 1;

	}
	std::vector<int> malloc_buffer;
	extern "C" static int MallocX(lua_State* L){


		int size = lua_tonumber(L,1);
		DWORD x = (DWORD)malloc(size);


	
		lua_pushnumber(L,x);

		return 1;

	}
	extern "C" static int NewString(lua_State* L){


		std::string* x = new std::string(lua_tostring(L,1));

		lua_pushnumber(L,(int)x);

		return 1;

	}
	extern "C" static int FreeString(lua_State* L){


		std::string* x = (std::string*)(int*)(int)lua_tonumber(L,1);

		delete x;

		return 0;

	}
	extern "C" static int FreeX(lua_State* L){


		int x = lua_tonumber(L,1);
		free((void*)x);
		return 0;

	}


	//Arguments is r3,r4,r5,r6,r7,r8,r9 //LIMIT Bigger Count using stack  and pointers
	extern "C" static int CallCPLUSFunc(lua_State* L){

		int nargs = lua_gettop(L); //Arguments Count
		DWORD offset = lua_tonumber(L,1); //NUM
		DWORD ARGStack[10];
		DWORD result = 0;
		//PUSH ARGS
		for (int i= 0;i<10;i++){
			ARGStack[i]= 0;
		}
		for (int i = 2;i<=nargs;i++){
		
			ArgumentsAnalys(L,i,(int*)&ARGStack);
		}

		const DWORD word = (DWORD)&ARGStack; // VALUE
			__asm{
				mr r12,word 
			};
		CallCPLUSFuncHELPER();
		BranchTo(offset,int);
		_asm{
			mr result,r3
		}
		lua_pushnumber(L,result);	
		return 1;
	}

	extern "C" static int SonicTeam_EffectModule_HideEffect(lua_State* L){

		int argc = lua_gettop(L);
		//1 self
	
		int SSGroup = (int)lua_tonumber(L,2);
		DWORD v7[2];
		v7[0]=0;
		v7[1]=0;
		BranchTo(0x8221F3C8,void,SSGroup,v7);
		return 0;


	}

	

	extern "C" static int SonicTeam_EffectModule_RunEffect(lua_State* L){


		int argc = lua_gettop(L);
		//1 self
		int SSModule = (int)lua_tonumber(L,2);
		int SSGroup = (int)lua_tonumber(L,3);
		int SSParticle = (int)lua_tonumber(L,4);

		if (*(int*)(SSGroup+4) || *(int*)(SSGroup)) return 0;
		int sxz = SSModule +0x4A0; 
		sxz = SSParticle;
		DWORD _RS[3];
		int res = BranchTo(0x82225BD8,int,
			_RS,
			(__int64)(SSModule+0xC), //r3
			*((__int64*)(sxz)), // 0x2F4 (r4)
			*((__int64*)(sxz+0x8)), //  (r5)
			*((__int64*)(sxz+0x10)), //  (r6)
			(__int64)*((int*)(sxz+0x18)), //  (r7)	
			((__int64)(SSModule+0x488)) //  (r8)
			);
		BranchTo(0x8221F3C8,int,SSGroup,res);
		if ( _RS[1] )
			sub_821601B8(_RS[1]);


		return 0;
		
	}

	extern "C" static int BitBase(lua_State*L,int cs){

		int v1 = lua_tonumber(L,2);
		int v2 = lua_tonumber(L,3);
		int result = 0;
		switch (cs){

			case 0:
				result = v1 << v2;
					break;
			case 1:
				result = v1 >> v2;
					break;
			case 3:
				result = v1 & v2;
					break;
			case 4:
				result = v1 | v2;
				break; 

			default:
				lua_pushnil(L);
				return 1;
		}
		lua_pushnumber(L,result);
		return 1;
	}

	extern "C" static int BIT_ShiftLeft(lua_State* L){
		return BitBase(L,0);

	}
	extern "C" static int BIT_ShiftRight(lua_State* L){
		return BitBase(L,1);
		
	}
	extern "C" static int BIT_AND(lua_State* L){
		return BitBase(L,3);

	}
	extern "C" static int BIT_OR(lua_State* L){
		return BitBase(L,4);

	}



	std::map<int,std::vector<int>> EffectMapJoiner;
	extern "C" static int ConnectEffectModuleFunc(lua_State* L){


		int argc = lua_gettop(L);
	//	if (argc < 1 ) return 0;
		//int arg1 = lua_tonumber(L,1); // self 
		int arg1 = lua_tonumber(L,2); // arg1
		int arg2 = (int)lua_topointer(L,3); //arg 2

		// setup callback
		lua_pushvalue(L, 3);
		int ref = luaL_ref(L, LUA_REGISTRYINDEX);
		//ShowXenonMessage(L"MSG",luaL_ref(L,LUA_REGISTRYINDEX),"");


		EffectMapJoiner[arg1].push_back(ref);
		return 0;
	}
	std::map<int,std::vector<int>> ContextMapJoiner;
	extern "C" static int ConnectContextModuleFunc(lua_State* L){

		int argc = lua_gettop(L);
		//	if (argc < 1 ) return 0;
		//int arg1 = lua_tonumber(L,1); // self 
		int arg1 = (int)lua_tonumber(L,2); // arg1


		// setup callback
		lua_pushvalue(L, 3);
		int ref = luaL_ref(L, LUA_REGISTRYINDEX);
		//ShowXenonMessage(L"MSG",luaL_ref(L,LUA_REGISTRYINDEX),"");


		ContextMapJoiner[arg1].push_back(ref);
		return 0;
	}

	const char po[] = "game:\\common\\";
	const polen = sizeof(po);
	extern "C" static int LuaDoFile(lua_State* L){
		
		int argc = lua_gettop(L);
		if (argc < 1 ) return 0;
		const char* arg1 = lua_tostring(L,1);
		int len = strlen(arg1);


		std::string* bruh = new std::string();
		bruh->append(po);
		bruh->append(arg1);
		const char* n = bruh->c_str();


	//	memcpy(n+strlen(po),arg1,strlen(arg1));
		
		const char* pdata;

		//HRESULT resu  = ATG::LoadFile(n,(void**)&pdata);

		//ShowXenonMessage(L"",n);
		//lua_dostring(L,pdata);
		lua_dofile(L,n);


		//free(n);


		return 0;
	}

	//Arguments is r3,r4,r5,r6,r7,r8,r9 //LIMIT Bigger Count using stack  and pointers
	extern "C" static int CallCPLUSFuncF(lua_State* L){

		int nargs = lua_gettop(L); //Arguments Count
		DWORD offset = lua_tonumber(L,1); //NUM
		DWORD ARGStack[10];
		DWORD result = 0;
		//PUSH ARGS
		for (int i= 0;i<10;i++){
			ARGStack[i]= 0;
		}
		for (int i = 2;i<=nargs;i++){

			ArgumentsAnalys(L,i,(int*)&ARGStack);
		}

		const DWORD word = (DWORD)&ARGStack; // VALUE
		__asm{
			mr r12,word 

		};
		CallCPLUSFuncHELPER();
		BranchTo(offset,float);
		_asm{
			mr result,r3
		}
		lua_pushnumber(L,result);	
		return 1;
	}


	//Replace State (Will be Renamed soon)
	extern "C" static int AddCustomState(lua_State* L){
	

		int CHRID  = (int)lua_tonumber(L,1);
		int TSTATE  = (int)lua_tonumber(L,2);
		char* LUASTATE  = (char*)lua_tostring(L,3);


		
		RCSS rcss = {TSTATE,std::string(LUASTATE)};

	
		my_map[CHRID][TSTATE] = std::string(LUASTATE);
	

		//Debug
		//ShowXenonMessage(L"Msg",LUASTATE);

		return 0;
	}





		extern "C" static int WriteVirtialBytesRange(lua_State* L){
		int nargs = lua_gettop(L);
		if (nargs < 2) return 0;
		std::stringstream conv;
		DWORD StartOffset,EndOffset,LastOffset;
		const char* StartOffsetS = lua_tostring(L,1);
		const char* EndOffsetS = lua_tostring(L,2);
		const char* ByteArrayString = lua_tostring(L,3);
		conv << std::hex << StartOffsetS; conv >> StartOffset; conv.clear(); 	conv.str("");
		conv << std::hex << EndOffsetS; conv >> EndOffset; conv.clear(); 	conv.str("");
		std::string ByteArrayStringR = std::string(ByteArrayString);

		ByteArrayStringR.erase(std::remove( ByteArrayStringR.begin(),
			ByteArrayStringR.end(),
			' '),
			ByteArrayStringR.end());


		int len  = ByteArrayStringR.length();
		if (len % 2 != 0){ //Add Extra Zero
			ByteArrayStringR.append("0");
		}
		const char* cu = ByteArrayStringR.c_str();
		byte* bt = new byte[strlen(cu)/2];
		char buff[2] = {0,0};
		for (int i =0 ;i<strlen(cu)/2;i++){
			memcpy((void*)&buff,(void*)((unsigned int)cu + (i*2)),2);
			bt[i] = (unsigned int)(strtoul(buff,NULL,16));

		}	
		DWORD dw;

		for (int i = StartOffset; i<EndOffset;i+=strlen(cu)/2 ){
			VirtualProtectEx(GetModuleHandle(NULL),(void*)(ADDR(StartOffset)),strlen(cu)/2,1,&dw);
			memcpy((void*)ADDR(i),bt,strlen(cu)/2);
			VirtualProtectEx(GetModuleHandle(NULL),(void*)(ADDR(StartOffset)),strlen(cu)/2,dw,&dw);
		}
		free(bt);




		return 0;

	}

	extern "C" static int WriteVirtialFloat(lua_State* L){
		int nargs = lua_gettop(L);
		if (nargs < 2) return 0;
		std::stringstream conv;
		DWORD StartOffset,LastOffset;

		if (lua_type(L,-1) == LUA_TNUMBER){
			StartOffset = lua_tonumber(L,1);
		}
		//STRING
		else{
			const char* StartOffsetS = lua_tostring(L,1);
			conv << std::hex << StartOffsetS; conv >> StartOffset; conv.clear(); 	conv.str("");
		}

		float FloatValue = (float)lua_tonumber(L,2);

		DWORD dw;
		VirtualProtectEx(GetModuleHandle(NULL),(void*)(ADDR(StartOffset)),4,dw,&dw);
		memcpy((void*)ADDR(StartOffset),(byte*)&FloatValue,4);
		VirtualProtectEx(GetModuleHandle(NULL),(void*)(ADDR(StartOffset)),4,dw,&dw);


	}

	extern "C" static int WriteVirtialInt(lua_State* L){
		int nargs = lua_gettop(L);
		if (nargs < 2) return 0;
		std::stringstream conv;
		DWORD StartOffset,LastOffset;
		const char* StartOffsetS = lua_tostring(L,1);
		int FloatValue = (int)lua_tonumber(L,2);
		conv << std::hex << StartOffsetS; conv >> StartOffset; conv.clear(); 	conv.str("");
		DWORD dw;
		VirtualProtectEx(GetModuleHandle(NULL),(void*)(ADDR(StartOffset)),4,dw,&dw);
		memcpy((void*)ADDR(StartOffset),(byte*)&FloatValue,4);
		VirtualProtectEx(GetModuleHandle(NULL),(void*)(ADDR(StartOffset)),4,dw,&dw);


	}
	extern "C" static int WriteVirtialShort(lua_State* L){
		int nargs = lua_gettop(L);
		if (nargs < 2) return 0;
		std::stringstream conv;
		DWORD StartOffset,LastOffset;
		const char* StartOffsetS = lua_tostring(L,1);
		short FloatValue = (short)lua_tonumber(L,2);
		conv << std::hex << StartOffsetS; conv >> StartOffset; conv.clear(); 	conv.str("");
		DWORD dw;
		VirtualProtectEx(GetModuleHandle(NULL),(void*)(ADDR(StartOffset)),2,dw,&dw);
		memcpy((void*)ADDR(StartOffset),(byte*)&FloatValue,2);
		VirtualProtectEx(GetModuleHandle(NULL),(void*)(ADDR(StartOffset)),2,dw,&dw);


	}

	extern "C" static int WriteVirtialBytes(lua_State* L){

		int nargs = lua_gettop(L);
		if (nargs < 2) return 0;
		std::stringstream conv;
		DWORD StartOffset,LastOffset;
		const char* StartOffsetS = lua_tostring(L,1);
		const char* ByteArrayString = lua_tostring(L,2);
		conv << std::hex << StartOffsetS; conv >> StartOffset; conv.clear(); 	conv.str("");
		std::string ByteArrayStringR = std::string(ByteArrayString);
		ByteArrayStringR.erase(std::remove( ByteArrayStringR.begin(),
                                ByteArrayStringR.end(),
                                ' '),
                    ByteArrayStringR.end());
		int len  = ByteArrayStringR.length();
		if (len % 2 != 0){ //Add Extra Zero
			ByteArrayStringR.append("0");
		}
		const char* cu = ByteArrayStringR.c_str();
		byte* bt = new byte[strlen(cu)/2];
		char buff[2] = {0,0};
		for (int i =0 ;i<strlen(cu)/2;i++){
			memcpy((void*)&buff,(void*)((unsigned int)cu + (i*2)),2);
			bt[i] = (unsigned int)(strtoul(buff,NULL,16));
	
		}	
		DWORD dw;
		VirtualProtectEx(GetModuleHandle(NULL),(void*)(ADDR(StartOffset)),strlen(cu)/2,1,&dw);
		memcpy((void*)ADDR(StartOffset),bt,strlen(cu)/2);
		VirtualProtectEx(GetModuleHandle(NULL),(void*)(ADDR(StartOffset)),strlen(cu)/2,dw,&dw);


		//Free Buffer
		free(bt);




		return 0;

	/*	const char* offsetS = lua_tostring(L,1);
		std::stringstream ss;
		ss << std::hex << offsetS;
		DWORD offset = 0;
		ss >> offset;
		const char* si = lua_tostring(L,2);
		int sv = strlen(si);
		for (int i = 0;i<sv;i+=2){
			unsigned int x;
			unsigned int x1;
			ss.clear();
			ss << std::hex << si[i];
			ss >> x;
			ss.clear();
			ss << std::hex << si[i+1];
			ss >> x1;
			BYTE byte3 = x<< 4 | x1;
			Hook::WriteByte((void*)(offset+(i/2)),byte3);
		}



		return 0;
		*/
	}
	extern "C" static int WriteVirtualString(lua_State* L){

		return 0;
	}

	extern "C" static int SetFloatValue(lua_State* L){

		//int narg = lua_gettop(L);
		//if (narg < 2){
		//	lua_pushnil(L);
		//	return 0;
		//}

		int Struct = (int)lua_tonumber(L,1);
		int Value = (int)lua_tonumber(L,2);

	
		float Setter = lua_tonumber(L,3);

		*(float*)(Struct + Value) = Setter;




		return 0;
	}


	extern "C" static int Memory_GetHelper(lua_State* L,int cases){
	

		int args = lua_gettop(L);
		if (args < 2){
			lua_pushnil(L);
			return 1;
		}
		int arg1 = lua_tonumber(L,2); //Memory Address


		switch (cases){

			case 0:
				lua_pushnumber(L,(int)*(_BYTE*)arg1);
				break;
			case 1:
				lua_pushnumber(L,*(int*)arg1);
				break;

			default:
			lua_pushnil(L);

		}

		return 1;
	}
	extern "C" static int Memory_SetHelper(lua_State* L,int cases){


		int args = lua_gettop(L);
		if (args < 3){
			lua_pushboolean(L,false);
			return 1;
		}
		int arg1 = lua_tonumber(L,2); //Memory Address
		int arg2 = lua_tonumber(L,3); //value
		bool result = true;

		switch (cases){

			case 0:
			    *(byte*)arg1 = (byte)arg2;
				break;
			case 1:
				*(int*)arg1 = (int)arg2;
				break;
			default:
				lua_pushnil(L);
				result = false;

		}

		lua_pushboolean(L,result);
		return 1;
	}
	extern "C" static int Memory_WriteByte(lua_State* L){

		return Memory_SetHelper(L,0);
	}
	extern "C" static int Memory_WriteInt(lua_State* L){

		return Memory_SetHelper(L,1);
	}


	extern "C" static int Memory_GetByte(lua_State* L){

		return Memory_GetHelper(L,0);
	}
	extern "C" static int Memory_GetInt(lua_State* L){

		return Memory_GetHelper(L,1);
	}


	 
	const char* GM = "Game";
	

	
LPCWSTR g_pwstrButtonsXx[1] = { L"------------OK----------------" };
	DWORD WINAPI ThreadProc( LPVOID lpParameter )
	{
		
		DWORD dwThreadNumber = (DWORD) lpParameter;



		while (true){
	
			ATG::GAMEPAD* gc = ATG::Input::GetMergedInput(0);

			if (gc->wPressedButtons & XINPUT_GAMEPAD_DPAD_UP){
				std::string* si = new std::string();
				for (int i = 0;i<log.size();i++){
					si->append(*log[i]);
					si->append("\n");
				}

				MESSAGEBOX_RESULT result;
				XOVERLAPPED m_Overlapped; 
				XShowMessageBoxUI(0,L"Debug.Log(Result)",convertCharArrayToLPCWSTR(si->c_str()),1,g_pwstrButtonsXx,1,XMB_ALERTICON,&result,&m_Overlapped);
				
				while (result.dwButtonPressed != 0){


				}
				Sleep(1000);
				



			}
			if (gc->wPressedButtons & XINPUT_GAMEPAD_DPAD_DOWN){
				
				for (int i = 0;i<log.size();i++){
					delete log[i];
				}


				log.resize(0);
			}


		}

	
		return 0;
	}



	int __declspec( naked ) sub_825ED208H(lua_State* LS){

		__asm{
			    mflr      r12
				stw       r12, -8(r1)
				std       r30, -0x18(r1)
				std       r31, -0x10(r1)

				lis r11,0x825E
				ori r11,r11,0xD218
				mtctr r11
				bctr
		}
	}


	



#define lua_register(L,n,f) \
	(lua_pushstring(L, n), \
	lua_pushcfunction(L, f), \
	lua_settable(L, LUA_GLOBALSINDEX))


#define lua_register06(L,n,f) \
	(lua_pushstring06(L, n), \
	lua_pushcfunction06(L, f), \
	lua_settable06(L, LUA_GLOBALSINDEX))



	HOOK(lua_State*,__fastcall,sub_825DAAA0,0x825DAAA0){

		return lua_open();
	}

	HOOK(DWORD,__fastcall,sub_825ED208,0x825ED208,lua_State* LS){
		





		sub_825ED208H(LS);




		return 1;

	
	}




	int __declspec( naked ) sub_825DB498H(lua_State* LS){

		__asm{
			    mflr      r12
				stw       r12, -8(r1)
				std       r31, -0x10(r1)
				
				stwu      r1, -0x60(r1)
				lis r11,0x825D
				ori r11,r11,0xB4A8
				mtctr r11
				bctr
		}
	}




	extern "C" static int BitBaseEX(lua_State*L,int cs){

		int v1 = lua_tonumber(L,1);
		int v2 = lua_tonumber(L,2);
		int result = 0;
		switch (cs){

			case 0:
				result = v1 << v2;
				break;
			case 1:
				result = v1 >> v2;
				break;
			case 3:
				result = v1 & v2;
				break;
			case 4:
				result = v1 | v2;
				break; 

			default:
				lua_pushnil(L);
				return 1;
		}
		lua_pushnumber(L,result);
		return 1;
	}

	extern "C" static int BIT_ShiftLeftEX(lua_State* L){
		return BitBaseEX(L,0);

	}
	extern "C" static int BIT_ShiftRightEX(lua_State* L){
		return BitBaseEX(L,1);

	}
	extern "C" static int BIT_ANDEX(lua_State* L){
		return BitBaseEX(L,3);

	}
	extern "C" static int BIT_OREX(lua_State* L){
		return BitBaseEX(L,4);

	}


	static const struct luaL_reg BitLIB [] = {
		{"AND", BIT_ANDEX},
		{"OR", BIT_OREX},
		{"SL", BIT_ShiftLeftEX},
		{"SR", BIT_ShiftRightEX},
		{NULL, NULL}  /* sentinel */
	};


	// Create & return MyObject instance to Lua
	static int DebugLabel_new(lua_State* L){

		const char* msg = lua_tostring(L,1);
		int PX = lua_tonumber(L,2);
		int PY = lua_tonumber(L,3);


		std::string msgt =  std::string(msg);
		int length = msgt.length() + 1;
		wchar_t* wcharPtr = new wchar_t[length];
		std::memset(wcharPtr, 0, length * sizeof(wchar_t));
		std::mbstowcs(wcharPtr, msgt.c_str(), length);
		msgt.clear();


		*reinterpret_cast<int**>(lua_newuserdata06(L, sizeof(int*))) = (int*)SpawnMessage(wcharPtr,PX,PY);

		luaL_getmetatable06(L,"DebugLabel");
		lua_setmetatable06(L, -2);

		free(wcharPtr);

		return 1;
	}


	extern "C" static int DebugLabel_delete(lua_State* L){
		
		BranchTo(0x8262BA68,int,*reinterpret_cast<int**>(lua_touserdata(L, 1)),1); //Destroy from mem
		
		return 0;
	}

	extern "C" static int DebugLabel_SetText(lua_State* L){




		int* TextEntity = (*reinterpret_cast<int**>(luaL_checkudata(L, 1, "DebugLabel")));
			
	
		UINT ud = (UINT)TextEntity;
	

		const char* msg = lua_tostring(L,2);
		std::string msgt =  std::string(msg);
		int length = msgt.length() + 1;
		wchar_t* wcharPtr = new wchar_t[length];
		std::memset(wcharPtr, 0, length * sizeof(wchar_t));
		std::mbstowcs(wcharPtr, msgt.c_str(), length);
		msgt.clear();
		EditMessage((UINT32)ud,wcharPtr);
		free(wcharPtr);
		return 0;
	}


	extern "C" static int DebugLabel_SetPosition(lua_State* L){


		int* TextEntity = (*reinterpret_cast<int**>(luaL_checkudata(L, 1, "DebugLabel")));
		UINT ud = (UINT)TextEntity;
		float x  = lua_tonumber(L,2);
		float y = lua_tonumber(L,3);
		ChangeMessagePosition(ud,x,y);

		return 0;
	}


	
	HOOKL(extern "C",int,__cdecl ,sub_825DB498,0x825DB498,lua_State* LS){

		
		BranchTo(0x825D6700,int,LS,"bit",BitLIB,0);
		BranchTo(0x825D6700,int,LS,"player",PET,0);

		lua_register06(LS,"DebugLabel",DebugLabel_new);
		luaL_newmetatable06(LS,"DebugLabel");


		// lua_setfield(L, -2, "__gc");
		lua_pushstring06(LS, "__gc"); lua_pushcfunction06(LS, DebugLabel_delete); lua_settable06(LS, -3);

		lua_pushvalue(LS, -1);  lua_pushstring06(LS, "__index"); lua_pushvalue(LS,-2);  lua_settable06(LS,-3);
		
		lua_pushstring06(LS, "SetText"); lua_pushcfunction06(LS, DebugLabel_SetText); 	lua_settable06(LS, -3);

		lua_pushstring06(LS, "SetPosition"); lua_pushcfunction06(LS, DebugLabel_SetPosition); 	lua_settable06(LS, -3);




		lua_pop(LS,1);










	
	//	luaopen_string(LS);
	

		


		return sub_825DB498H(LS);
	}


	





	int __declspec( naked ) PlayBGMH(lua_State* LS){

		__asm{
			    mflr      r12
				stw       r12, -8(r1)
				std       r30, -0x18(r1)
				std       r31, -0x10(r1)

				lis r11,0x8246
				ori r11,r11,0x23E8
				mtctr r11
				bctr

		}
	}
	HOOKL(extern "C",int,__cdecl ,PlayBGM,0x824623D8,lua_State* LS){


	
		 int dt =   (int)lua_touserdata(LS, -10002); 
		 BranchTo(0x8216B360,int,dt,lua_tostring(LS,1));

		return PlayBGMH(LS);
	}





	bool _extra_is_loaded = false;
	Sonicteam::SoX::RefCountObject* RefLoadedCSDObject;
	UINT32 TextEntityStatic = 0;





	//return TextEntity
	void ChangeMessagePosition(UINT32 TextEntity,float x,float y){
		XMVECTOR* pos = (XMVECTOR*)(TextEntity + 0x30);
		pos->x = x;
		pos->y = y;
		*(_BYTE *)(TextEntity + 0xDD) = 1;
		BranchTo(0x8262AF00,int,TextEntity,30.0);
		BranchTo(0x8262B008,int,TextEntity);

	}


	//return TextEntity
	void ChangeMessagePositionY(UINT32 TextEntity,float y){
		XMVECTOR* pos = (XMVECTOR*)(TextEntity + 0x30);
		pos->x = 0.0;
		pos->y = 480 + y;
		*(_BYTE *)(TextEntity + 0xDD) = 1;
		BranchTo(0x8262AF00,int,TextEntity,30.0);
		BranchTo(0x8262B008,int,TextEntity);

	}
	void EditMessage(UINT32 TextEntity,const wchar_t* msg){

		*(_BYTE *)(TextEntity + 0xDD) = 1;
		BranchTo(0x8262DB90,int,TextEntity,msg,0); //New Text
		BranchTo(0x8262B008,int,TextEntity);
	}
	UINT32 SpawnMessage(const wchar_t* msg,float pos_x,float pos_y){

		Sonicteam::DocMarathonImp* doc = *(Sonicteam::DocMarathonImp**)(*(UINT32*)0x82D3B348 + 0x180);
		UINT32 Resouce = doc->DocGetUnkGameResources();
		// 8 * (index + 3)
		UINT32 RequiredResouce = (8*(3)) + Resouce;

		//wchar_t or i
		//i dunno text-size???// 
		//Z-Inddex ???
		UINT32 TextEntity = BranchTo(0x8262DC60,UINT32,malloc06(0x110),RequiredResouce,msg,0,0);
		TextEntityStatic = TextEntity;

		BranchTo(0x8262AF00,int,TextEntity,30.0);

		XMVECTOR* pos = (XMVECTOR*)(TextEntity + 0x30);
		pos->x = pos_x;
		pos->y = pos_y;
		*(_BYTE *)(TextEntity + 0xDD) = 1;
		//BranchTo(0x8262DB90,int,TextEntity,L"JUCK",0); //New Text
		//ARGB(Alpha,Red,Green,Blue)
		UINT flag = ((0xFF << 24) |(0xFF << 16) | (0xFF << 8) |  0x00 );
		BranchTo(0x8262B288,int,TextEntity,&flag);
		BranchTo(0x8262B008,int,TextEntity);
		return TextEntity;

	}

	UINT32 SpawnMessage(const wchar_t* msg,float pos_y){

		Sonicteam::DocMarathonImp* doc = *(Sonicteam::DocMarathonImp**)(*(UINT32*)0x82D3B348 + 0x180);
		UINT32 Resouce = doc->DocGetUnkGameResources();
		// 8 * (index + 3)
		UINT32 RequiredResouce = (8*(3)) + Resouce;

		//wchar_t or i
		//i dunno text-size???// 
		//Z-Inddex ???
		UINT32 TextEntity = BranchTo(0x8262DC60,UINT32,malloc06(0x110),RequiredResouce,msg,0,0);
		TextEntityStatic = TextEntity;

		BranchTo(0x8262AF00,int,TextEntity,30.0);

		XMVECTOR* pos = (XMVECTOR*)(TextEntity + 0x30);
		pos->x = 0.0;
		pos->y = 480.0 + pos_y;
		*(_BYTE *)(TextEntity + 0xDD) = 1;
		//BranchTo(0x8262DB90,int,TextEntity,L"JUCK",0); //New Text
		//ARGB(Alpha,Red,Green,Blue)
		UINT flag = ((0xFF << 24) |(0xFF << 16) | (0xFF << 8) |  0x00 );
		BranchTo(0x8262B288,int,TextEntity,&flag);
		BranchTo(0x8262B008,int,TextEntity);
		return TextEntity;

	}

	void sub_825EA610(Sonicteam::DocMarathonImp* _this, double a2){

		BranchTo(0x825EA610,int,_this,a2);

	
		if (!_extra_is_loaded){
			_extra_is_loaded = true;

			Sonicteam::SoX::RefCountObject* RefSpriteObj;
			Sonicteam::SoX::RefCountObject** RefSpriteObj2 = BranchTo(0x82617570,Sonicteam::SoX::RefCountObject**,&RefSpriteObj,&std::string("sprite/debug_UI"));

			RefLoadedCSDObject = RefSpriteObj->GetObject<Sonicteam::SoX::RefCountObject>();
			RefLoadedCSDObject->LoseObject();
			//RefSpriteObj->LoseObject();

			if (RefLoadedCSDObject){
				*(int*)((int)(RefLoadedCSDObject)+0x20) &= 0xFFFFFFF7;
				BranchTo(0x8262AF00,int,(int)(RefLoadedCSDObject)+8,20.0);

				RefLoadedCSDObject = RefLoadedCSDObject->GetObject<Sonicteam::SoX::RefCountObject>();
				CellLoadSpriteWithAnim((int*)&RefLoadedCSDObject,"text_log",0);


			
			//	SpawnMessage(L"Testing",0);
			//	EditMessage(  SpawnMessage(L"TestingX2",28),L"T");
				
			

			}

		}

		if (RefLoadedCSDObject){

			int v5 = (int)RefLoadedCSDObject;
			(*(int (__fastcall **)(int, double))(*(_DWORD *)(v5 + 8) + 8))(v5 + 8, a2);

		}

		

	

		


		

	}

	

	bool once = false;

	void GlobalInstall(){


		DebugMessages = std::vector<int>();
		DebugMessagesPlace = std::vector<int>();
		ScrollPosition.x = 0;
		ScrollPosition.y = 0;


	//WRITE_DWORD(0x8203B014,sub_825126A0);

	//WRITE_DWORD(0x82033578,sub_824A7598);
	//WRITE_DWORD(0x82000950,sub_825EA610); Not needd
	WRITE_DWORD(0x82462398  ,POWERPC_LIS(11,POWERPC_HI((DWORD)&tx)));
	WRITE_DWORD(0x824623A0  ,POWERPC_ADDI(5,11,POWERPC_LO((DWORD)&tx)));

	WRITE_DWORD(0x8203B8AC,Log);
	WRITE_DWORD(0x82049094,luaB_print);




	INSTALL_HOOK(PlayBGM);
	INSTALL_HOOK(sub_825DB498); // MathLib Replace






	WRITE_DWORD(0x825ED28C   ,POWERPC_LIS(11,POWERPC_HI((DWORD)&tx3)));
	WRITE_DWORD(0x825ED294   ,POWERPC_ADDI(4,11,POWERPC_LO((DWORD)&tx3)));


	//WRITE_DWORD(0x825DB4A8  ,POWERPC_LIS(11,POWERPC_HI((DWORD)&tx2)));
	//WRITE_DWORD(0x825DB4B0   ,POWERPC_ADDI(5,11,POWERPC_LO((DWORD)&tx2)));



	//WriteSaveGame("06Test",L"Test");
	const int stackSize = 65536;
    HANDLE Thr = CreateThread( NULL, stackSize, ThreadProc, (VOID *)0, CREATE_SUSPENDED, NULL );
	ResumeThread(Thr);


	
	















	//WRITE_DWORD(0x824623AC ,POWERPC_ADDI(4,11,POWERPC_LO((DWORD)&GM)));
	}
}


namespace OmegaHoverFix{




	int NewHoverUpdate(Marathon::PlayerState::State* a1,double a2){

		*(float*)(a1->StateBase.ContextBase + 0x260)-=(1*a2);

		if (*(float*)(a1->StateBase.ContextBase + 0x260) <= (float)0){
			//ShowXenonMessage(L"M",L"M");
			*(float*)(a1->StateBase.ContextBase + 0x260)= 0;
			a1->StateBase.basevalue->StateModule->ChangeState((int*)a1->StateBase.basevalue,3);
			return 1;
		}

		return sub_821AA3D0(a1,a2);
	}
	//HALF HOOK
	HOOK(int,__fastcall,State_Omega_Fall_Action_Mid_Half,0x821A9BDC,Marathon::PlayerState::State* a1,double a2){


		
		
		
		if (*(float*)(a1->StateBase.ContextBase + 0x260) > (float)0 && (a1->StateBase.ContextBase->Input >> 1) & 1 ) 
		{
			a1->StateBase.basevalue->StateModule->ChangeState((int*)a1->StateBase.basevalue,78);
			return 1;
		}


		return 0;
	};
	int OmegaCoreUpdate(Marathon::PlayerState::CommonContext* a1,double a2){


		if ((LODWORD(a1->FallDataSome) & 1) != 0){
			*(float*)(a1 + 0x260) = (float)1;
		}

	
		return BranchTo(0x82213018,int,a1,a2);;
	}


	void GlobalInstall(){

		WRITE_DWORD(0x821B5DD4,0x38600264) ; // Get Space For Extra Hover Value
		WRITE_DWORD(0x822133A0,0xF97F025C); //std       r11, 0x25C(r31)

		WRITE_DWORD(0x82004848,NewHoverUpdate);

		WRITE_NOP(0x821A9BDC,11);
		INSTALL_HOOKR(State_Omega_Fall_Action_Mid_Half);

		WRITE_DWORD(0x8200AAE4,OmegaCoreUpdate);
	




	}
}








namespace DLLTesting{







bool ones = false;
DWORD vo =0;
bool SonicCoreUpdateMutex = false;

struct NNN{
	int ID; //Character ID 

};


class LuaCharacterState:Marathon::PlayerState::CommonObject{
public: 
	
	int num;
	int id;
	int* varibles;
	void Helper(const char * a1){

		//BaseLua.DoFile(false);
		lua_getglobal(BaseLua.L,my_map[id][num].c_str());	
		lua_pushstring(BaseLua.L, a1);
		lua_gettable(BaseLua.L, -2);
		lua_pushvalue(BaseLua.L,-2); //SELF 
		lua_call(BaseLua.L,1,0);
	//	lua_pop(BaseLua.L,1);

		
	
	}
	void Helper2(){
		BaseLua.DoFile(false);
		lua_getglobal(BaseLua.L,my_map[id][num].c_str());	
		lua_pushstring(BaseLua.L, "OnStateLua");
		lua_gettable(BaseLua.L, -2); // LStateSonicWait.CContext
		lua_pushvalue(BaseLua.L,-2);
		lua_pushnumber(BaseLua.L,(int)this);
		lua_call(BaseLua.L,2,0);
		lua_settop(BaseLua.L,0);
	}

	int* StateStart() override{

		Helper2();
		Helper("OnStart");
		
		return 0;
	}
	int* StateUpdate(double a2) override{

	     Helper2();
		 Helper("OnUpdate");
		return 0;
	}
	int* StateEnd() override{
		 Helper2();
		 Helper("OnEnd");
		return 0;
	}
	LuaCharacterState(Marathon::PlayerState::StateBaseValueP* OM):CommonObject(OM){

	}
	LuaCharacterState(Marathon::PlayerState::StateBaseValueP* OM,int statenum):CommonObject(OM){
		num = statenum;
	}
	LuaCharacterState(Marathon::PlayerState::StateBaseValueP* OM,int statenum,int chrid):CommonObject(OM){
		num = statenum;
		id = chrid;
		//ShowXenonMessage(L"MSG",my_map[id][num].c_str());

		//BaseLua.DoFile(false);
		lua_getglobal(BaseLua.L,my_map[id][num].c_str());	
		lua_pushstring(BaseLua.L, "OnStateConstructor");
		lua_gettable(BaseLua.L, -2); // LStateSonicWait.CContext
		lua_pushvalue(BaseLua.L,-2);
		lua_pushnumber(BaseLua.L,(int)this);
		lua_call(BaseLua.L,2,0);
		
		
		

	}
	~LuaCharacterState(){
		if (varibles != 0) free(varibles);
	}

};


//a3 = StateNum
boost::shared_ptr<LuaCharacterState>& LuaCharacterStateC(boost::shared_ptr<LuaCharacterState>& a1,int a2,int a3,int a4){ 
	
	boost::shared_ptr<LuaCharacterState> x(new LuaCharacterState((Marathon::PlayerState::StateBaseValueP*)a2,a3,a4));
	a1 = x;
	return a1;
}




extern "C" int OpenState(lua_State* L){


	BranchTo(0x8219C960,int,L);
	
	

	int some = *(int*)lua_topointer(L,1);
	
	int* arr = *(int**)(some + 228+4); //Value  IN  v17[1]
	int v15 = arr[3];

	int chrid = (int)lua_tonumber(L,2);

	*(int*)(v15 + 0x78) = chrid; // CHR ID

	std::stringstream ss;
	ss << chrid;

	DebugLogRestore::log.push_back(new std::string(ss.str()));

	std::vector<int>* vec = (std::vector<int>*)(v15+0x40);
	if (vec->size() > 100){

		if (my_map.find(chrid) != my_map.end())
		{
			for (std::map<int, std::string>::iterator it = my_map[chrid].begin(); it != my_map[chrid].end(); ++it)
			{
				(*vec)[it->first] = (DWORD)LuaCharacterStateC;
				// ShowXenonMessage(L"SG",it->first,"");
			}


		}
	}
	//int Context = *(int*)(v15 + 0x70);
	//std::string* con = (std::string*)(Context+4);
	//std::stringstream ss;
	//ss << chrid;
	//con->append("__");
	//con->append(ss.str());

	//ss.clear();
	



	return 0;
}


HOOK(boost::shared_ptr<Marathon::Player::State::CommonContext>&,__fastcall,test,0x821B5BB8,boost::shared_ptr<Marathon::Player::State::CommonContext>& a1)
{
	return Marathon::Player::State::Zest(a1,0);
};


 extern "C" void SonicCoreUpdate(Marathon::PlayerState::ContextPlayerSonic* a1,double a2){
	 
	 

			
			
	

		

	  //  BaseLua.DoFile(false);
	//	lua_getglobal(BaseLua.L,"SonicActionUpdate");	
	//	lua_pushnumber(BaseLua.L,(int)a1);
	//	lua_call(BaseLua.L,1,0);
		
	//	lua_settop(BaseLua.L, 0);	

		//	lua_register(BaseLua->L,"SonicActionUpdate",);
			//lua_setglobal(BaseLua->L,"SonicActionUpdate");
			//lua_pushvalue(BaseLua->L,-1); // Now This Function in Stack
			//lua_setglobal(BaseLua->L,"SonicActionUpdate");




		
		
			



		
			BranchTo(0x82219530,int,a1); // Do Original;

			
			//lua_newtable(L);
			//int top = lua_gettop(L);


			//lua_pushlstringX(L,"CurrentGem"); //Key	
			//lua_pushnumber(L,a1->CurrentGem); //Value
			//lua_settable(L, 0);
			//.//lua_loadl
		


			
		//	luaL_newmetatable()
		//	luaL_newmetatable(L,"")
			//lua_pushlightuserdata(L,(int*)a1);
		
		//	lua_toboolean(LuaDLL::LState,-1);

		//	if(lua_isfunction(LuaDLL::LState, -1) ){

		//	}


			
//
		







			return;
		}


 void __declspec( naked ) sub_8221E1E0(_DWORD *a1, int a2, int a3){


	 __asm{

		 mflr      r12
			 stw       r12, -8(r1)
			 std       r31, -0x10(r1)
			 std       r30, -0x18(r1)
			 std       r29, -0x20(r1)
			 stwu      r1, -0x70(r1)
			 mr        r31, r3
			 mr        r30, r5 //State Num
			 li        r9, 0
			 cmpwi     cr6, r5, 0
			 blt       cr6,loc_8221E260
			 lwz       r11, 0x44(r4)
			 cmplwi    cr6, r11, 0
			 bne       cr6,loc_8221E214
			 mr        r11, r9
			 b        loc_8221E220
loc_8221E214:         
		 lwz       r10, 0x48(r4)
			 subf      r11, r11, r10
			 srawi     r11, r11, 2
loc_8221E220:         
		 cmpw      cr6, r5, r11
			 bge       cr6,loc_8221E260
			 lwz       r11, 0x44(r4)
			 cmplwi    cr6, r11, 0
			 beq       cr6,loc_8221E248
			 lwz       r10, 0x48(r4)
			 subf      r10, r11, r10
			 srawi     r10, r10, 2
			 cmplw     cr6, r5, r10
			 blt       cr6,loc_8221E24C
loc_8221E248:         
//		 twui      r0, 0x16
loc_8221E24C:         
//		 
//		///     slwi      r10, r5, 2
			 lwzx      r11, r10, r11
			 cmplwi    cr6, r11, 0
			 li        r11, 1
			 bne       cr6,loc_8221E264
loc_8221E260:         

		 mr        r11, r9
loc_8221E264:         
////		 clrlwi    r11, r11, 24
			 cmplwi    cr6, r11, 0
			 beq       cr6,loc_8221E2E8
			 lwz       r11, 0x44(r4)
			 lwz       r6, 0x78(r4) // LOAD CHARACTER ID
			 cmplwi    cr6, r11, 0
			 beq       cr6,loc_8221E290
			 lwz       r10, 0x48(r4)
			 subf      r10, r11, r10
			 srawi     r10, r10, 2
			 cmplw     cr6, r5, r10
			 blt       cr6,loc_8221E294
loc_8221E290:         
//		 twui      r0, 0x16
loc_8221E294:         
///		 slwi      r10, r5, 2
			 cmplwi    cr6, r4, 0
			 addi      r4, r4, 0x20 
			 lwzx      r11, r10, r11
			 bne       cr6,loc_8221E2AC
			 mr        r4, r9
loc_8221E2AC:       
		     
		     
		     mr        r5,r30
		     addi      r3, r1, 0x50
			 mtctr     r11
			 bctrl
			 lwz       r11, 0(r3)
			 stw       r11, 0(r31)
			 lwz       r3, 4(r3)
			 cmplwi    cr6, r3, 0
			 stw       r3, 4(r31)
			 beq       cr6,loc_8221E2D4
			// bl        sub_82160140
loc_8221E2D4:         
		 lwz       r3, 0x54(r1)
			 cmplwi    cr6, r3, 0
			 beq       cr6,loc_8221E2F0
			// bl        sub_821601B8
			 b        loc_8221E2F0
loc_8221E2E8:         
		 stw       r9, 0(r31)
			 stw       r9, 4(r31)
loc_8221E2F0:         
		 mr        r3, r31
			 addi      r1, r1, 0x70
			 lwz       r12, -8(r1)
			 mtlr      r12
			 ld        r29, -0x20(r1)
			 ld        r31, -0x10(r1)
			 ld        r30, -0x18(r1)
			 blr


	 }
 };


 HOOK(DWORD*,__fastcall,sub_82160B98,0x82160B98,DWORD* a1,int a2){

	 sub_825EB070((int)a1, a2);
	 *a1 = 0x8200094C;


	 BaseLua.DoFile(false);
	 lua_getglobal(BaseLua.L,"OnMarathonAwake");	
	 lua_call(BaseLua.L,0,0);
	 lua_pop(BaseLua.L,1);


	 return a1;
 }



void GlobalInstall(){
		

		WRITE_DWORD(0x8200B564 ,SonicCoreUpdate);
		WRITE_DWORD(0x820033B4, OpenState);


		WRITE_DWORD(0x8219C994,POWERPC_LI(3,0x7C)); // SAVE ONE MORE VALUE;

	
		//Hook::WriteHook((void*)0x8221E1E0,(void*)sub_8221E1E0);
	//	INSTALL_HOOK(sub_82160B98);
	
		
	
	}

}


void add(int* t){
	*t = *t+1;
}

void Test()
{


	







//	BasicsTest(0);
//	BasicsTest();
}



namespace TimeSystemRestore{




	int __declspec( naked ) sub_825F2FB0_ORI(int a1,double a2){
		
		__asm{    
		    lis       r11, 0x8204
			lfs       fp13, 0x20(r3)
			lfs       fp0, 0x3708(r11)
			fcmpu     cr6, fp13, fp0
			lis r11,0x825F
			ori r11,r11,0x2FC0
			mtctr r11
			bctr
	}
	
	
	}

	int __declspec( naked ) sub_825F30E0_ORI(int a1,double a2){
		__asm{
			mflr      r12
			stw       r12, -8(r1)
			std       r31, -0x10(r1)
			stwu      r1, -0xA0(r1)
			lis r11,0x825F
			ori r11,r11,0x30F0
			mtctr r11
			bctr
		}
	}


	HOOK(int,__fastcall,sub_825F2FB0,0x825F2FB0,int a1,double a2){

	//	DWORD zo = 0;
	//	zo++;



		BaseLua.DoFile(true);


		lua_getglobal(BaseLua.L,"TimeSystem");	
		lua_pushstring(BaseLua.L, "R");
		lua_gettable(BaseLua.L, -2);
		double f = (double)lua_tonumber(BaseLua.L,-1);

		
		lua_getglobal(BaseLua.L,"TimeSystem");	
		lua_pushstring(BaseLua.L, "G");
		lua_gettable(BaseLua.L, -2);
		double f1 = (double)lua_tonumber(BaseLua.L,-1);


		lua_getglobal(BaseLua.L,"TimeSystem");	
		lua_pushstring(BaseLua.L, "B");
		lua_gettable(BaseLua.L, -2);
		double f2 = (double)lua_tonumber(BaseLua.L,-1);

	//	lua_pushstring(BaseLua.L, "B");
	//	lua_gettable(BaseLua.L, -6);
	//	double f2 = (double)lua_tonumber(BaseLua.L,-1);
	
		


	

		if (*(float *)(a1 + 32) < 1.0 ){
			*(float *)(a1 + 32) = *(float *)(a1 + 32) + (a2/100);
		}
		else{
			DebugLogRestore::log.push_back(new std::string("Value Was Reseted"));
			*(float *)(a1 + 32) = 0;
		}

		//RGB
		float* v6 = *(float**)(a1 + 24);


		v6[0] = (float)f;
		v6[1] = (float)f1;
		v6[2] = (float)f2;






		


		return sub_825F2FB0_ORI(a1,a2);
		
	}



	int __fastcall KhronoControlInputListenerUpdate(int a1, double a2){




		std::stringstream ss;
		ss << std::hex << a1;

		if (ATG::Input::GetMergedInput(0)->wLastButtons & XINPUT_GAMEPAD_Y){
			//DebugLogRestore::log.push_back(new std::string(ss.str().c_str()));
			int Components  = *(int*)(a1+0x1C);
			int Khrono_Component  = *(int*)(Components+0x8);

			*(float*)(Khrono_Component + 0x5C) += 1.0;
		//	*(float*)(Khrono_Component + 0x58) -= 1.0;


		}
		
		return 0;

	}



	struct vector3{
		float x;
		float y;
		float z;
	};
	struct light06{
		float u0;
		float u1;
		float u2;
		vector3 v0;
	};

	light06 mo[] = {
		{

			(float)0.86,
				(float)0.6,
				(float)0.4,
			{
				(float)0.250043,
					(float)0.433186,
					(float)0.865927
			}
		},
		{

			(float)0.1,
				(float)0.1,
				(float)0.1,
			{
				(float)-0.983456,
					(float)-0.82123,
					(float)-0.422544
			}
		},
		{

			(float)0.7,
				(float)0.95,
				(float)0.8,
			{
				(float)1,
					(float)0.85,
					(float)0.95
			}
		}

	};

	int index = 0;
	float change = (float)0.001;
	//
	bool cf(float* a1,float* a2){

		if (*a1 != *a2){
			if (*a1 > *a2){
				*a1-=change;
			}
			else{
				*a1+=change;
			}
			return false;

		}
		return true;
	}


	int __declspec( naked ) sub_825F30E0H(int a1,double a2){
		__asm{
			    mflr r12
				stw       r12, -0x8(r1)
				std r31,-0x10(r1)
				stwu      r1, -0xA0(r1)
				lis r11,0x825F  
				ori r11,r11,0x30F0
				mtctr r11
				bctr r11
		}
	}	
	//OLD ONE
	HOOK(int,__fastcall,sub_825F30E0,0x825F30E0,int a1, double a2)
{



	float* v7 = *(float **)(a1 + 40);


	DWORD* v6 = *(_DWORD **)(a1 + 32);

	DWORD* v13 = *(_DWORD **)(a1 + 40);

	vector3* u0 = (vector3*)(v7 + 4);
	if (ATG::Input::GetMergedInput(0)->wPressedButtons & XINPUT_GAMEPAD_DPAD_UP){
		
		index++;

		if (index > 2){
			index = 0;
		}
	}

	 if (ATG::Input::GetMergedInput(0)->wLastButtons & XINPUT_GAMEPAD_Y){


		
		cf(&v7[0],&mo[index].u0);
		cf(&v7[1],&mo[index].u1);
		cf(&v7[2],&mo[index].u2);

	    cf(&v7[3],&mo[index].v0.x);
		cf(&v7[4],&mo[index].v0.y);
		cf(&v7[5],&mo[index].v0.z);



		

		// u0->x+=change;
		 //u0->y+=change;
		 //u0->z+=change;
		// v7[0]+=change; //R
		// v7[1]+=change; //G
		// v7[2]+=change; //B


		 //v13[0]=100;  //blue
//		 v13[1]=100;  //rose
 

	

	 }
	 




return sub_825F30E0H(a1,a2);

	

}


	struct LTI_Vector4{
		float x;
		float y;
		float z;
		float a;
	};
	struct LTI_Vector3{
		float x;
		float y;
		float z;

	};




	/*struct LightDirecton{
		LTI_Vector3 Position;
		LTI_Vector3 Target;
	};
	};*/
	struct LightDirecton{
		LTI_Vector4 Position;
	};




	struct LightTableInfo{
		float Time;
		LTI_Vector4 SunColor;
		LTI_Vector4 AmbientColor;
		LTI_Vector4 LightColor0;
		LTI_Vector4 LightColor1;
		LTI_Vector4 BRay;
		LTI_Vector4 BMie;
		float G;
		float Bloom_MinThr;
		float Bloom_MaxThr;
		float Bloom_Scale;
	};
	struct LightTableInfoEX:LightTableInfo{
		LightDirecton LightMaxInfo0;
		LightDirecton LightMaxInfo1;
	};

	struct LightTableInfoEXSort{
		float value;
		LightTableInfoEX* LightInfo;

	};


	bool compare_nocase (const LightTableInfoEXSort& first, const LightTableInfoEXSort& second)
	{
		unsigned int i=0;	
		return ( first.value < second.value );
	}

	int sub_82270AE0_GetSceneLightMainParams(DWORD SceneLightParam,DWORD LightIstanceID){
		int v12 = *(int*)(SceneLightParam + 0x68);
		int v8 = 0x10 * LightIstanceID;
		DWORD  v9 = 0x10 * LightIstanceID + v12;
		int* v10 = *(int **)(v9 + 4);
		int v11 = *v10;
		return v11;
	}
	int sub_82270AE0_GetSceneLightSubParams(DWORD SceneLightParam,DWORD LightIstanceID){



		DWORD v8 = 0x10 * LightIstanceID;
		int v12 = *(int*)(SceneLightParam + 0x68);
		_DWORD v14 = *(_DWORD *)(v12 + v8 + 4);
		return  *(_DWORD *)(v14 + 8);
	}
	
	int __fastcall sub_82270AE0(int a1, double time_delta){
		
		*(float *)(a1 + 0x5C) = time_delta;
		BranchTo(0x82270AE0,int,a1,time_delta);
		//CUSTOM CODE TIME
		byte s1[0x1C];
		Make06String(&s1,"Light");
		DocMarathonStateSO1 * SDocMarathonState = *(DocMarathonStateSO1**)(a1 + 0x3C);
		int Scene_Params_ALL =  SDocMarathonState->DocMarathonState->GetAllSceneParams(SDocMarathonState);
		DWORD SceneLightParam =  (DWORD)MarahonFindPluginByName(Scene_Params_ALL,(int)&s1);
		if (SceneLightParam){

			
			int v12 = *(int*)(SceneLightParam + 0x68);
			
			
			int LightIstanceID = 0; //Should Be cycled
			int v8 = 0x10 * LightIstanceID;
			DWORD  v9 = 0x10 * LightIstanceID + v12;
			int* v10 = *(int **)(v9 + 4);
			int v11 = *v10;
			DWORD v14 = *(_DWORD *)(v12 + v8 + 4);
			DWORD v15 = *(_DWORD *)(v14 + 8);
	

			

			float timer = *(float *)(a1 + 0x54);


			DWORD v11_s = *(int*)(sub_82270AE0_GetSceneLightMainParams(SceneLightParam,LightIstanceID) + 0x20);
			XMFLOAT4* trg = (XMFLOAT4*)(v11_s + 0x10);
			XMFLOAT4* MainColor = (XMFLOAT4*)(v11_s);


			DWORD v11_s_2 = *(int*)(sub_82270AE0_GetSceneLightSubParams(SceneLightParam,LightIstanceID) + 0x20);
			XMFLOAT4* trg_s = (XMFLOAT4*)(v11_s_2 + 0x10);
			XMFLOAT4* SubColor = (XMFLOAT4*)(v11_s_2);


		//	XMFLOAT4* trg_s = (XMFLOAT4*)(sub_82270AE0_GetSceneLightParams(SceneLightParam,0) + 0x10);
		

			LightTableInfoEX Current;
			LightTableInfoEX Next;
			std::vector<LightTableInfoEX>* pro =  (std::vector<LightTableInfoEX>*)(0x82D36CD4);
			if (pro->size() > 0 ){
				for (int i = 0;i<pro->size();i++){
					Current = (*pro)[i];
					Next =(*pro)[i+1];
					if (Current.Time <= timer &&	timer <= Next.Time){
						break;
					}
				}
			}
	
			float TM = (timer -  Current.Time) / (Next.Time - Current.Time);
			





	
			DWORD v5 = *(DWORD*)(SceneLightParam +0x58);
			DWORD AmbientSceneParam = *(_DWORD *)(8 * LightIstanceID + v5);
			XMFLOAT4* SAmbientSceneParam = *(XMFLOAT4**)(AmbientSceneParam + 0x10);

		
	


			if (pro->size() > 0)
			{
				if (trg){

					trg->x = ((1.0 - TM) *  Current.LightMaxInfo0.Position.x) + (Next.LightMaxInfo0.Position.x * TM);
					trg->y = ((1.0 - TM) *  Current.LightMaxInfo0.Position.y) + (Next.LightMaxInfo0.Position.y * TM);
					trg->z = ((1.0 - TM) *  Current.LightMaxInfo0.Position.z) + (Next.LightMaxInfo0.Position.z * TM);

				}

				if (MainColor){
					MainColor->x = ((1.0 - TM) *  Current.LightColor0.x) + (Next.LightColor0.x * TM);
					MainColor->y = ((1.0 - TM) *  Current.LightColor0.y) + (Next.LightColor0.y * TM);
					MainColor->z = ((1.0 - TM) *  Current.LightColor0.z) + (Next.LightColor0.z * TM);
				}


				if (trg_s){
					trg_s->x = ((1.0 - TM) *  Current.LightMaxInfo1.Position.x) + (Next.LightMaxInfo1.Position.x * TM);
					trg_s->y = ((1.0 - TM) *  Current.LightMaxInfo1.Position.y) + (Next.LightMaxInfo1.Position.y * TM);
					trg_s->z = ((1.0 - TM) *  Current.LightMaxInfo1.Position.z) + (Next.LightMaxInfo1.Position.z * TM);
				}
				if (SubColor){
					SubColor->x = ((1.0 - TM) *  Current.LightColor1.x) + (Next.LightColor1.x * TM);
					SubColor->y = ((1.0 - TM) *  Current.LightColor1.y) + (Next.LightColor1.y * TM);
					SubColor->z = ((1.0 - TM) *  Current.LightColor1.z) + (Next.LightColor1.z * TM);
				}

				if (SAmbientSceneParam){
					SAmbientSceneParam->x = ((1.0 - TM) *  Current.AmbientColor.x) + (Next.AmbientColor.x * TM);
					SAmbientSceneParam->y = ((1.0 - TM) *  Current.AmbientColor.y) + (Next.AmbientColor.y * TM);
					SAmbientSceneParam->z = ((1.0 - TM) *  Current.AmbientColor.z) + (Next.AmbientColor.z * TM);
				}
				
			}

		
		}
		Free06String(&s1);


		//	Free06String(&LIGHT_STR);





		return a1;
	}

	
	int KhoroControllerShadowsUpdate(int KhronoController0x20,float time_delta){
	
	
			ShowXenonMessage(L"SF","");
		

		return KhronoController0x20;
	}



#define lua_next06(LS,index) BranchTo(0x825D6160,int,LS,index)

#define lua_type06(LS,index) BranchTo(0x825D5368,int,LS,index)

#define lua_settop06(LS,index) BranchTo(0x825D51C0,int,LS,index)


#define lua_pushstring06(LS,str) BranchTo(0x825D5918,int,LS,str);

#define lua_gettable06(LS,index) BranchTo(0x825D5B30,int,LS,index);

#define lua_pushnil06(LS,index) BranchTo(0x825D5870,int,LS);





//#define lua_tovector4(svd,LS,cstr)  BranchTo(0X8226F0D0,float*,svd,LS,cstr)
#define lua_tovector4(svd,LS,cstr)  BranchTo(0X8226F0D0,int*,svd,LS,cstr)
#define lua_toDirection3dsmax(svd,LS,cstr)  BranchTo(0x825F3890,int*,svd,LS,cstr)

float __fastcall lua_tonumberfixedwithstep(lua_State* a1)
{
	float v2; // fp31
	v2 = 0.0;
	if ( lua_next(a1, -1) )
	{
		if ( lua_isnumber(a1, -1) )
			v2 = (float)lua_tonumber(a1, -1);
		lua_pop(a1,1);
	}
	return v2;
}

float* lua_tovector4new(float* place,lua_State* LS,char* str){
	*place = 0.0;
	place[1] = 0.0;
	place[2] = 0.0;
	place[3] = 1.0;
	lua_pushstring(LS,str);
	lua_gettable(LS,-2);
	if (lua_istable(LS,-1)){
		lua_pushnil(LS);
		place[0] = lua_tonumberfixedwithstep(LS);
		place[1] = lua_tonumberfixedwithstep(LS);
		place[2] = lua_tonumberfixedwithstep(LS);
		lua_pop(LS,1);
	}
	lua_pop(LS,1);
	return place;
}

extern "C" float lua06_tofloat(lua_State* LS,char* str){
	float result = 0;
	lua_pushstring(LS,str);
	lua_gettable(LS,-2);


	if (lua_isnumber(LS,-1)){
		result = (float)lua_tonumber(LS,-1);
	}
	

	lua_pop(LS,1);
	return result;
}




//only with FAST CODE OPTIMIZATION BECAUSE C++ SUCLK






HOOK_EXTERN_C(int,__fastcall,sub_8226FEB0,0x8226FEB0,_DWORD *a1, _DWORD *a2){


	
	float v50[32]; // [sp+90h] [-150h] BYREF
	char v51[16]; // [sp+110h] [-D0h] BYREF

	char v53[16]; // [sp+130h] [-B0h] BYREF
	char v54[16]; // [sp+140h] [-A0h] BYREF
	char v55[16]; // [sp+150h] [-90h] BYREF

	DWORD v4 = a1[2];
	DWORD v5 = a1[1];
		DWORD IResource[2];
		byte v49[0x1c];
		int SunColorV4[4];
		int AmbientColorV4[4];
		int LightColor0V4[4];
		int LightColor1V4[4];
		int BrayV4[4];
		int BmieV4[4];
		std::string* t =   (std::string *)(a1 + 4);
		t->assign(*(std::string*)a2);
		std::string IResourceV_16(t->c_str());
		DWORD IResourceV[2];
		LoadAndInitLuaResource((DWORD)&IResourceV, (DWORD)&IResourceV_16);
		lua_State* LS =  (lua_State*)*(DWORD*)(IResourceV[0]+0x4);
		lua_getglobal(LS,"TimeLightTable");
		lua_pushnil(LS); //For Deep Lua Searc
		float v52[32];
		memset(&v52,0,32*4);
		float v499[4];
		LightTableInfoEX test;
		memset(&test,0,sizeof(LightTableInfoEX));
		std::vector<LightTableInfoEX>* pro = (std::vector<LightTableInfoEX>*)a1;
		if (pro->size() > 0){
			pro->clear();
		}
		while (lua_next(LS,-2) != 0){
			if (lua_istable(LS,-1)){
				test.Time = lua06_tofloat(LS,"Time");
				test.G = lua06_tofloat(LS,"G");
				test.Bloom_MinThr = lua06_tofloat(LS,"Bloom_MinThr");
				test.Bloom_MaxThr = lua06_tofloat(LS,"Bloom_MaxThr");
				test.Bloom_Scale = lua06_tofloat(LS,"Bloom_Scale");
				lua_tovector4((float*)&v499, LS, "SunColor");
				memcpy(&test.SunColor,&v499,16);
				lua_tovector4((float *)v499, LS, "AmbientColor");
				memcpy(&test.AmbientColor,&v499,16);

				lua_tovector4((float *)&v499, LS, "LightColor0");
				memcpy(&test.LightColor0,&v499,16);

		     	lua_tovector4((float *)&v499, LS, "LightColor1");
			    memcpy(&test.LightColor1,&v499,16);

				lua_tovector4((float *)&v499, LS, "BRay");
				memcpy(&test.BRay,&v499,16);
				lua_tovector4((float *)&v499, LS, "BMie");
				memcpy(&test.BMie,&v499,16);



				lua_toDirection3dsmax((float*)&v499,LS,"LightColor0_Direction_3dsmax");
				memcpy(&test.LightMaxInfo0.Position,&v499,16);
				lua_toDirection3dsmax((float*)&v499,LS,"LightColor1_Direction_3dsmax");
				memcpy(&test.LightMaxInfo1.Position,&v499,16);


				//ShowXenonMessage(L"MSG",test.LightMaxInfo0.Position.x,0);
				/*
				lua_pushstring(LS,"LightColor0_Direction_3dsmax");
				lua_gettable(LS,-2);
				lua_tovector4((float *)&v499, LS, "Position");
				memcpy(&test.LightMaxInfo0.Position,&v499,12);
				lua_tovector4((float *)v499, LS, "Target");
				memcpy(&test.LightMaxInfo0.Target,&v499,12);
				lua_pop(LS,1); // Back to TimeLightTable

				lua_pushstring(LS,"LightColor1_Direction_3dsmax");
				lua_gettable(LS,-2);
				lua_tovector4((float *)&v499, LS, "Position");
				memcpy(&test.LightMaxInfo1.Position,&v499,12);
				lua_tovector4((float *)v499, LS, "Target");
				memcpy(&test.LightMaxInfo1.Target,&v499,12);
				lua_pop(LS,1); // Back to TimeLightTable
				*/

				pro->push_back(test);

	

				


		
				
			}


			lua_pop(LS,1);

		}

		 lua_pop(LS, 1); // pop table

		//I guess ?????/

		



		//Free Resource From 06Memory
		if ( IResourceV[0] )
			sub_82581E38(IResourceV[0] + 0x24);

		
	
		
		return (int)a1;


	}

	void __fastcall sub_825EA610(int a1, double a2){

	//	a2 = 1/60;

		double limit = 1.0/60.0;
		if (ATG::Input::GetMergedInput()->wLastButtons & XINPUT_GAMEPAD_Y){
			limit *=5.0;
			a2 *= 5.0;
		}

		if (  a2 > ((limit * 10.0) * 5.0) )
			a2 = limit;

		BranchTo(0x825EA610,int,a1,a2);
	}


	void GlobalInstall(){
		//INSTALL_HOOK(sub_825F30E0);
	//	INSTALL_HOOK(sub_825F2FB0);
	//	WRITE_NOP(0x825F2FE4,1); // Disable Animation Duration
		//WRITE_DWORD(0x8201079C,sub_82270AE0);
		WRITE_DWORD(0x820107AC,KhronoControlInputListenerUpdate);
		WRITE_DWORD(0x8201078C,KhoroControllerShadowsUpdate);
		WRITE_DWORD(0x8201079C,sub_82270AE0);

		INSTALL_HOOK(sub_8226FEB0);

		WRITE_DWORD(0x82000950,sub_825EA610);
		WRITE_DWORD(0x8204ACC8,sub_825EA610);

		WRITE_NOP(0x825EA65C,1);



	//	WRITE_NOP(0x825EA63C,0x1E);
		


		WRITE_WORD(0x8227059E,sizeof(LightTableInfoEX));
		WRITE_WORD(0x822705D2,sizeof(LightTableInfoEX));
		//0x78 CURRENT SIZE
	//	WRITE_DWORD(0x822704C4,0x7D6B3E70); // Fix Size For Table Fech
	//	WRITE_DWORD(0x8227051C,0x7D6B3E70); // Fix Size For Table Fech
	//	WRITE_DWORD(0x82270584,0x7D6B3E70); // Fix Size For Table Fech
	//	WRITE_DWORD(0x8227059C,0x1D6900E8); // Fix Size For Table Fech
	//	WRITE_DWORD(0x822705D0,0x3B5A00E8); // Fix Size For Table Fech

		
	}


}



namespace ArcRemover{


	int __declspec( naked ) MainAsmHookIline(_DWORD *a1, int* HandleManager, std::string* a3, std::string *a4, int* a5, int a6){
		__asm{
			    mflr r12
				std       r29, -0x20(r1)
				std       r30, -0x18(r1)
				std       r31, -0x10(r1)
				stw       r12, -0x8(r1)
				stwu      r1, -0xC0(r1)
				mr        r29, r3
				lis r11,0x8258  
				ori r11,r11,0x2658 
				mtctr r11
				bctr r11
		}
	}	
	bool TOGLE = false;

	HOOK(int,__fastcall,sub_82582648,0x82582648,_DWORD *a1, int* HandleManager, std::string* a3, std::string *a4, int* a5, int ShowErrors){


	
		DWORD test;
		__asm{
			mflr r12;
			stw r12,test
		}

		//if (TOGLE){
		
		
		//	ShowXenonMessage(L"MSG",buffer);


			// Sleep(1000);
		//}

		//std::string* po = new std::string();
		//po->append(a3->c_str());
		//po->append(" : ");
		//po->append(a4->c_str());


		//std::stringstream ss;
		//std::stringstream ss1;

		//if (a5 == 0){
		//	ss << a5;
		//}
		//else{
		//	ss << *a5;
		//}
		
	
		//ss1 << ShowErrors;

	

	//	po->append(" : ");
	//	po->append(ss.str().c_str());

	//	po->append(" : ");
	//	po->append(ss1.str().c_str());


	


		
	 



		if (a3->find("shader.pkg") != std::string::npos)
		{
		//	ShowXenonMessage(L"MSG",po->c_str());
		//	Sleep(1000);
		//	return MainAsmHookIline(a1,HandleManager,a3,a4,a5,0);


			
		}


		return MainAsmHookIline(a1,HandleManager,a3,a4,a5,ShowErrors);
		

		
	};


	DWORD WINAPI ThreadProc( LPVOID lpParameter )
	{
		while (1){
			if (ATG::Input::GetMergedInput(0)->wLastButtons & XINPUT_GAMEPAD_Y)
			{
				TOGLE = true;
			}

		}
	}


	int __declspec( naked ) sub_828B30A8_H(int a1){
		__asm{

			mflr      r12
			std       r29, -0x20(r1)
			std       r30, -0x18(r1)
			std       r31, -0x10(r1)
			stw       r12, -8(r1)
			stwu      r1, -0x90(r1)
			mr        r31, r3
			lis r11,0x828B
			ori r11,r11,0x30B8
			mtctr r11
			bctr

		}

	}

	int __fastcall sub_828B30A8(int a1){

		//if (TOGLE){
		//	std::string* po = ((std::string*)a1+8);
		//	ShowXenonMessage(L"MSG",po->c_str());
		//	Sleep(1000);
		//}
		return BranchTo(0x828B30A8,int,a1);
	}


	//STD::STRING WRONG 
	int __fastcall sub_825BE438(int a1, std::string* a2)
	{
	

	
		int res = 0;
		{

			HANDLE hFile = CreateFile( a2->c_str(), GENERIC_READ, 0, NULL, 
				OPEN_EXISTING, 0, NULL );

			if( INVALID_HANDLE_VALUE != hFile ){

				res = 1;
				
			}
			else{
	
			//	char buffer[1024];
			//	char* path = "xenon_root";
			//	sprintf(buffer,"%s",a2->c_str());
			//	ShowXenonMessage(L"MSG",buffer);
				res = 0;
			}
			CloseHandle(hFile);

		}
		return res;
	}



	HOOK(int,__fastcall,sub_8263B628,0x8263B628,int a1,int a2){


		lua_State* LS = *(lua_State**)(a1+0x4);

		lua_getglobal(LS,(char*)a2);

		
		DebugLogRestore::log.push_back(new std::string((char*)a2));
		

		return lua_toboolean(LS,-1);
	}


	void GlobalInstall(){


		WRITE_DWORD(0x828B30FC,0x48000010);
		//WRITE_DWORD(0x828B30EC,0x60000000);
		
//		WRITE_DWORD(0x82080424,sub_828B30A8);
		
		
		INSTALL_HOOK(sub_82582648);
		WRITE_DWORD(0x8204839C,sub_825BE438);



	
	//	INSTALL_HOOK(sub_8263B628);

	}
}

//QuickBoot
namespace TestProject{



	HOOK(DWORD,__fastcall,sub_82160B98,0x82160B98,DWORD *a1, int a2){
	


		 _DWORD *result; // r3
		BranchTo(0x825EB070,int,(int *)a1, a2);
		 result = a1;
		 *a1 = 0x8200094C;
		 BranchTo(0x825EA168,int,a1,"scripts/mission/4000/mission_4001.lua");



		return (DWORD)result;

	};


	DWORD __declspec( naked ) sub_8262A568_H(DWORD* a1,int a2){
		__asm{

			mflr      r12
				std       r29, -0x20(r1)
				std       r30, -0x18(r1)
				std       r31, -0x10(r1)
				stw       r12, -8(r1)
				stwu      r1, -0x80(r1)
				mr        r30, r3
				lis r11,0x8262
				ori r11,r11,0xA578
				mtctr r11
				bctr

		}
	}


	DWORD DocMararhonStateX;
	DWORD CurrentModeX;

	HOOK(DWORD*,__fastcall,sub_8262A568,0x8262A568,DWORD *a1, int a2){
		sub_8262A568_H(a1,a2);


		DWORD DocMarathonState = (DWORD)a1[0x60];
		DWORD MainMode = *(DWORD*)(DocMarathonState + 0x8);

		DocMararhonStateX = DocMarathonState;
		CurrentModeX =MainMode;
		
		const char* Dest = "gameshow/sonic:scripts/stage/other/gameshow_sonic_mission.lua";
		//if (QuickBootLua.GetGlobalBool("UpdateAlways") == 1){QuickBootLua.DoFile(true);}
		//if (QuickBootLua.L != NULL){Dest = QuickBootLua.GetGlobalString("level");}
		BranchTo(0x825EA168,int,DocMarathonState,Dest);
		*(DWORD*)(MainMode+0x4C)=0;
		*(DWORD*)(MainMode+0x50)=7; 
	    *(DWORD*)(MainMode+0x54)=0x20; 
		*(byte*)(MainMode+0x3B8)=1;  
		return a1;


	};

	DWORD __declspec( naked ) sub_824A6EA8_H(int a1,int a2){
		__asm{

			    mflr      r12
				std       r29, -0x20(r1)
				std       r30, -0x18(r1)
				std       r31, -0x10(r1)
				stw       r12, -8(r1)
				stwu      r1, -0x3B0(r1)
				mr        r31, r3
				lis r11,0x824A
				ori r11,r11,0x6EB8
				mtctr r11
				bctr

		}
	}

	HOOK(int,__fastcall,sub_824A6EA8,0x824A6EA8,int a1, int a2){

		DWORD DocMarathonState = *(DWORD*)(a1 + 0x3C);
		byte some = *(byte*)(DocMarathonState+0x3B8);




		if (a2 == 0x20 || a2 == 1){
		

			const char* Dest = "gameshow/sonic:scripts/stage/other/gameshow_sonic_mission.lua";
	//		if (QuickBootLua.GetGlobalBool("UseSave") == 1){return sub_824A6EA8_H(a1,5);
	//		if (QuickBootLua.GetGlobalBool("UpdateAlways") == 1){QuickBootLua.DoFile(true);}
	//	    if (QuickBootLua.L != NULL){Dest = QuickBootLua.GetGlobalString("level");}
			BranchTo(0x825EA168,int,DocMarathonState,Dest);

			*(byte*)(DocMarathonState+0x3B8) = 1;

			*(DWORD*)(a1+0x4C)=0; //Set Loading Bool

	



			return a1;


		}


		return sub_824A6EA8_H(a1,a2);
	}


	
	HOOK(int,__fastcall,LoadTerrain,0x82462460,lua_State* L){



//ShowXenonMessage(L"MSG",0,(char*)lua_tostring(L,1));
		DebugLogRestore::log.push_back(new std::string(lua_tostring(L,1)));
		return 0;
	}

	DWORD WINAPI ThreadProc( LPVOID lpParameter )
	{

		while (true){

			ATG::GAMEPAD* gc = ATG::Input::GetMergedInput(0);

			if (gc->wPressedButtons & XINPUT_GAMEPAD_DPAD_LEFT){
				


				DWORD CurrentMode = *(DWORD*)(DocMararhonStateX + 0x8);
				DWORD GameImpulse = *(DWORD*)(CurrentMode + 0x6C);

				//*(std::string**)(GameImpulse + 6224) = new std::string("TOWN");

				*(DWORD*)(GameImpulse + 0x4) = 0;
				*(DWORD*)(GameImpulse + 0x8) = 4;
				*(DWORD*)(GameImpulse + 6256) = 4;
		


		

			}

			if (gc->wPressedButtons & XINPUT_GAMEPAD_DPAD_RIGHT){

				DWORD CurrentMode = *(DWORD*)(DocMararhonStateX + 0x8);
				DWORD GameImpulse = *(DWORD*)(CurrentMode + 0x6C);

			//s	*(DWORD*)(GameImpulse + 0x4) = 0;
				*(DWORD*)(GameImpulse + 0x8) = 3;
			}

		}
		return 0;
	}



	HOOK(Marathon::PlayerState::State*,__fastcall,State_Common_Jump_Action_End,0x82209208,Marathon::PlayerState::State* result){

		Marathon::PlayerState::CommonContext *v1; // r11
		Marathon::PlayerState::CommonContext *v2; // r11
		double v3; // fp13
		Marathon::PlayerState::CommonContext *v4; // r11
		Marathon::PlayerState::CommonContext *v5; // r10

		v1 = result->StateBase.ContextBase;
		v1->CurrentAnimation = 12;
		v1->AnimationState = -2;
		result->StateBase.ContextBase->field_E9 = 1;
		result->StateBase.ContextBase->field_EA = 1;
		v2 = result->StateBase.ContextBase;
		if ( (LODWORD(v2->FallDataSome) & 0x800) != 0 )
			v3 = v2->float21C;
		else
			v3 = v2->float184;
		v2->field_3C = 0.0;



		int OObject = *(int*)((int)(result->StateBase.basevalue) - 0x20 + 0x78);


		int OObject_Posture = *(int*)(OObject + 0xDC);

		float* vec4_rot_quat = (float*)(OObject_Posture + 0x20); 



		

		

	

		v4 = result->StateBase.ContextBase;
		v5 = result[1].StateBase.ContextBase;
		v4->AnimationState = -2;
		v4->CurrentAnimation = (int)v5;
		return result;
	}


	int __declspec( naked ) sub_821F1E30H(int a1,int a2){
		__asm{
			    mflr      r12
				stw       r12, -8(r1)
				std       r31, -0x10(r1)
				stfd      fp31, -0x18(r1)
				lis r11,0x821F
				ori r11,r11,0x1E40 
				mtctr r11
				bctr r11
		}
	}	


	
	HOOK(int,__fastcall,sub_821F1E30,0x821F1E30,int a1,int a2){


		int v3; // r3
		double v4; // fp1
		int v5; // r3

		v3 = *(_DWORD *)(a1 + 92);
		if ( v3 )
		{
			v4 = ((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)v3 + 24))(v3);
			v5 = *(_DWORD *)(a1 + 92);
			*(float *)(a1 + 244) = v4;
			*(float *)(a1 + 248) = ((double (__fastcall *)(int))*(_DWORD *)(*(_DWORD *)v5 + 20))(v5);
		}

		return sub_821F1E30H(a1,a2);

	}


	extern "C" int OpenStateEX(lua_State* L){

		BranchTo(0x8219C960,int,L);
		int some = *(int*)lua_topointer(L,1);
		int* arr = *(int**)(some + 228+4); //Value  IN  v17[1]
		int v15 = arr[3];
		*(int*)(v15 + 0x78) =some ;
		return 0;

	}



	void GlobalInstall(){


		QuickBootLua.DoFile(false);

		//WRITE_DWORD(0x821FDD60,0x48000034);
	//	WRITE_DWORD(0x821F1EA8,0x60000000);
	//	WRITE_DWORD(0x8220B154,0x60000000);
		//WRITE_DWORD(0x8220B244,0x60000000);
	//	WRITE_DWORD(0x8219C994,0x3860007C); //Increasse Memory 

	//	WRITE_DWORD(0x820033B4, OpenStateEX);


		//WRITE_DWORD(0x821F1E78,0x60000000);
		//WRITE_DWORD(0x821F1E8C,0x60000000);
		//INSTALL_HOOK(sub_821F1E30);
		//INSTALL_HOOK(State_Common_Jump_Action_End);


		//INSTALL_HOOK(sub_8262A568);
		INSTALL_HOOK(sub_824A6EA8);

		//INSTALL_HOOK(LoadTerrain);

		HANDLE Thr = CreateThread( NULL, 65536, ThreadProc, (VOID *)0, CREATE_SUSPENDED, NULL );
		ResumeThread(Thr);

	}


}


namespace LuaLUpdate{

	union int64{
		int p1;
		int p2;
	};
	int some = 0;
	DWORD vtt[10];


	int StringParser(std::string* ModuleName, const char te[]){
	
		int pos = ModuleName->find(te);
		if (pos !=  std::string::npos){
			std::string val = ModuleName->substr(pos+sizeof(te)-1);
			int po = atoi(val.c_str());
			val.clear();
			return po;
		}
		return NULL;
	}

	const char sc[] = "state context";
	const char te[] = "effect";
	int __fastcall  ObjectUpdate(int a1, double a2)
	{

		BaseLua.DoFile(true);

		BranchTo(0x82195500,int,a1,a2);
	

		

		

		float v4 = (*(float*)(a1 + 380) * a2);
		int v53[2];
		 v53[0] = 0;
		int v54[2];
		int v10[2];
		*(float*)&v53[1] = v4;
		v10[1] = v53[1]; 
		*&v10[1] = *(int*)&v53;
		*&v54[1] = *(int*)&v53;







//State,Context Connecters
		int Player = *(_DWORD *)(a1 + 0xE4);
		int PlayerF = (int)(Player -0x20);
		if (Player){
			int index = *(int*)(Player +0x78-0x20);
			int Context = *(int*)(Player+0x50);
			


			//v4->Table_Core->CharacterControls(v4);
			if (Context){
				BranchTo(
					*(int*)((*(int*)Context)+4),int,Context
					);
			}	

			
			if (*(int*)(PlayerF+0x50) != *(int*)(PlayerF+0x54)){

				ShowXenonMessage(L"MSG","1");
			}




			for (int i = 0;i<DebugLogRestore::ContextMapJoiner[index].size();i++){
						lua_rawgeti(BaseLua.L,LUA_REGISTRYINDEX,DebugLogRestore::ContextMapJoiner[index][i]);
						lua_pushnumber(BaseLua.L,Context);
						lua_pushnumber(BaseLua.L,a2);
						lua_pushnumber(BaseLua.L,Player-0x20);
						lua_pcall(BaseLua.L,3,0,0);
			}




		}






		int Module[] = {
			*(int*)(a1 + 0x270),
			*(int*)(a1 + 0x274)

		};

		for (int i = Module[0];i<Module[1];i+=8){
			int SM = *(int*)i; // OpenModel , IEventer(Effects inside)
			int IEventer = SM -8;
			
			if (*(int*)SM == 0x8200BC4C){ // IF SubModule == IEventer Class
				int IEventerModule[] = {*(int*)(SM+0xC),*(int*)(SM+0x10)};
				for (int j = IEventerModule[0];j<IEventerModule[1];j+=8){
					int SSModule = *(int*)j; // GameMaster,Sound,Effects,..
				 	std::string* ModuleName = (std::string*)(SSModule -0x20+4);
					
					int pos = ModuleName->find(te);
					if (pos !=  std::string::npos){

				
						int po = *(int*)(a1+0x310); //EFFET
						

						int CurrentAnimation = *(int*)((*(int*)(IEventer+0x20))+0x58);
						std::vector<int> vec = DebugLogRestore::EffectMapJoiner[po];
						for (int i = 0;i<vec.size();i++){
						
							lua_rawgeti(BaseLua.L,LUA_REGISTRYINDEX,vec[i]);
							lua_pushnumber(BaseLua.L,SSModule);
							lua_pushnumber(BaseLua.L,CurrentAnimation);
							lua_pcall(BaseLua.L,2,0,0);
							
						}
					}
						

					
				}
			}
		}	
		


		return a1;
	}


	void __declspec( naked ) sub_82228728Tramp(int a1){
		__asm{
			    mflr r12
				std       r29, -0x20(r1)
				std       r30, -0x18(r1)
				std       r31, -0x10(r1)
				stw       r12, -0x8(r1)
				stwu      r1, -0x70(r1)
				mr        r31, r3
				lis r11,0x8222
				ori r11,r11,0x8738 
				mtctr r11
				bctr r11
		}
	}	

	HOOK(int,__fastcall,sub_82228728,0x82228728,int a1){

		sub_82228728Tramp(a1);
		return a1;
	}


	struct OpenEffectBase{
		int p0;
		int p1;
		int p2;
	};
	int __fastcall OpenEffect(lua_State* L){

		//BranchTo(0x8219D5E8,int,L);
		int p1 = *(int*)lua_topointer(L,1); //ObjectPlayer
		int p2 = (int)lua_tonumber(L,2); // num
		char* p3 = (char*)lua_tostring(L,3); // num
		
		int v46;
		int v47;
		int v44[2];
		int v48[2];
		int v9;
		BranchTo(0x8219FBB8,int,v48,p1+0x15C);
		int v10 = sub_82581078(p1);
		int* v11 = BranchTo(0x826DF418,int*,v10,0,0x82B10B14,0x82B10AF0,0);
		if (v11){
			    v9 = (*(int (__fastcall **)(int* ))(*v11 + 36))(v11);
		}
		BranchTo(0x826180A8,int,&v46,p1+0xD0,"common");
		BranchTo(0x826180A8,int,&v47,p1+0xD0,"specific");
		if (v9){
			BranchTo(0x825FE620,void,v9,&v46);
			BranchTo(0x825FE620,void,v9,&v47);
		}

	
		OpenEffectBase Effects[] = {

			{1216,0x82228F28,0x821BD380}, // 1
			{464,0x822279F0,0x821BD3F0},  // 2
			{1872,0x82227200,0x821BD460}, // 3
			{1568,0x8222AD40,0x821BD4D0}, // 4
			{1376,0x8222A510,0x821BD540}, // 5
			{1440,0x82224030,0x821BD5B0}, // 6
			{1408,0x822238C0,0x821BD620}, // 7
			{1312,0x82223C20,0x821BD690}, // 8
			{1408,0x82224908,0x821BD700}, // 9
			{1392,0x82226398,0x821BD770}, // 10
			{1664,0x822282C0,0x821BD7E0}, // 11
			{1456,0x82229F00,0x821BD850}, // 12
			{1440,0x82229550,0x821BD8C0}, // 13
			{1440,0x82229A38,0x821BD930}, // 14
			{1280,0x82226020,0x821BD9A0}, // 15

		};

		std::string str = std::string(p3);
		
		
		if (p3 &&	*(int*)(p1+0x154) && v48[0] ){

		
			v44[0]=0;
			v44[1]=0;
			switch (p2){
				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
				case 6:
				case 7:
				case 8:
				case 9:
				case 10:
				case 11:
				case 12:
				case 13:
				case 14:
				case 15:
					int idx = p2-1;
					int EffectModule = (int)malloc06(Effects[idx].p0);
					if (EffectModule){
						BranchTo(Effects[idx].p1,int,EffectModule,*(int*)(p1+0x154),p1+0xCC,&str);
					}
					BranchTo(Effects[idx].p2,int,v44,EffectModule);
					
					str.clear();
					break;

			};


			BranchTo(0x821BAA60,int,p1,v44,1);
			if ( v44[1] )
				sub_821601B8(v44[1]);


		}
		if (v47) sub_82581E38(v47);
		if (v46) sub_82581E38(v46);
		if (v48[1]) sub_82581E38(v48[1]);
		*(int*)(p1+0x310) = p2; //EffectModule
	//	ShowXenonMessage(L"MSG",*(int*)(p1+0x310),"");





return 0;













		if (p2 == 4) return 0;

		std::stringstream ss;


			int SM = (*(int*)(p1 + 0x15C)) + 8;
			int IEventer = SM -8; 
			ss << p2;
		//	ShowXenonMessage(L"MSG",ss.str().c_str());
			if (*(int*)SM == 0x8200BC4C){ // IF SubModule == IEventer Class

				int IEventerModule[] = {*(int*)(SM+0xC),*(int*)(SM+0x10)};
				for (int j = IEventerModule[0];j<IEventerModule[1];j+=8){
					int SSModule = *(int*)j; // GameMaster,Sound,Effects,..
					std::string* ModuleName = (std::string*)(SSModule -0x20+4);

					if (ModuleName->find("effect") !=  std::string::npos){
					//	ShowXenonMessage(L"MSG",ModuleName->c_str());
		
						ModuleName->append("__");
						ModuleName->append(ss.str());
					//	ShowXenonMessage(L"MSG",ModuleName->c_str());
					}
				}
			
			}
	
	
		ss.str().clear();
		ss.clear();

		return 0;
	}



	static int OPEffectP = 0x310;

	HOOK(int,__fastcall,sub_8219FAE0,0x8219FAE0,int a1,int a2){
		int v4; // r3
		int result; // r3

		if ( a1 && (v4 = (int)malloc06(0x310+8)) != 0 ){


			result = BranchTo(0x82194D88,int,(int)v4, a1, a2);
		//	if (*(int*)(result + 0x310) )
		//	*(int*)(result + 0x310) = -1;
		//	*(int*)(result + 0x314) = -1;

		}
		else
			result = 0;


		

		return result;
	}


	void GlobalInstall(){

		
	//	INSTALL_HOOK(sub_82228728);

		//310,314
		INSTALL_HOOK(sub_8219FAE0); // ObjectPlayer Rework;
		WRITE_DWORD(0x8200356C,ObjectUpdate);
		WRITE_DWORD(0x8200340C,OpenEffect);
	}
}

namespace SapphireProject{

	void GlobalInstall(){

	}
}











namespace D3DH{


	void __declspec(naked) __fastcall sub_825B1C28_H(int a1, int a2){
		__asm{
			
				mflr      r12
				std       r18, -0x78(r1)
				std       r19, -0x70(r1)
				std       r20, -0x68(r1)
				std       r21, -0x60(r1)
				std       r22, -0x58(r1)
				std       r23, -0x50(r1)
				std       r24, -0x48(r1)
				std       r25, -0x40(r1)
				std       r26, -0x38(r1)
				std       r27, -0x30(r1)
				std       r28, -0x28(r1)
				std       r29, -0x20(r1)
				std       r30, -0x18(r1)
				std       r31, -0x10(r1)
				stw       r12, -8(r1)
				stwu      r1, -0x160(r1)
				mr r31,r3
				lis r11,0x825B
				ori r11,r11,0x1C38
				mtctr r11
				bctr
		}
	}



	

	HOOK(int,__fastcall,sub_825B1C28,0x825B1C28,int a1,int a2){


		sub_825B1C28_H(a1,a2);



	//	g_pDevice = (IDirect3DDevice9*)*(_DWORD *)(a1 + 36);


		//g_pDevice->Clear( 0, NULL, D3DCLEAR_TARGET, 0, 1.0f, 0L );

	//	 InitXui();
	//	 RenderScene();


		return 0;


	}




	void GlobalInstall()
	{	
		INSTALL_HOOK(sub_825B1C28);
	}

}




namespace ImGUI{



	HXUIDC                g_hDC     = 0;                    // Xui device context
	HXUIFONT              g_hFont   = 0;                    // Handle to Xui font
	IDirect3D9           *g_pD3D    = 0;                    // D3D interface
	IDirect3DDevice9     *g_pDevice = 0;                    // D3D device interface
	D3DPRESENT_PARAMETERS g_d3dpp   = {0};                  // D3D presentation paramters
	bool                  g_fXuiRenderInitialized = false;  // Initialization flags
	bool                  g_fXuiInitialized       = false;

	ATG::Font m_Font;
	bool XUI = false;

	HRESULT InitXui()
	{


		if (XUI)return E_FAIL;


		m_Font.Create( "game:\\Media\\Fonts\\Arial_12.xpr" );
		
		if( g_pDevice == 0 )
			return E_FAIL;

		XUIInitParams initparams = {0};
		XUI_INIT_PARAMS( initparams );

		// Typeface descriptor specifies a name and file location for a font
		TypefaceDescriptor desc = {0};
		desc.szTypeface = L"Arial Unicode MS";
		desc.szLocator = L"file://game:/media/xarialuni.ttf";


	
		
		// Initialize Xui render library with our D3D device, 
		// and use a Xui-provided texture loader.
		HRESULT hr = XuiRenderInitShared( g_pDevice, &g_d3dpp, XuiD3DXTextureLoader );
		if( FAILED( hr ) )
			goto error;
		g_fXuiRenderInitialized = true;

		

		// Create a Xui device context. The Xui text renderer uses many attributes
		// from this device context (position, color, shaders, etc.).
		hr = XuiRenderCreateDC( &g_hDC );
		if( FAILED( hr ) )
			goto error;

		// Initialize the Xui runtime library.  Typeface descriptors are registered
		// by the runtime library, and consumed by the render library.
		hr = XuiInit( &initparams );
		if( FAILED( hr ) )
			goto error;
		g_fXuiInitialized = true; 

		// Register our typeface name and font location.
		hr = XuiRegisterTypeface( &desc, TRUE );
		if( FAILED( hr ) )
			goto error;

		// Instantiate an 18pt font.
		hr = XuiCreateFont( L"Arial Unicode MS", 18.0f, XUI_FONT_STYLE_NORMAL, 0, &g_hFont );
		if( FAILED( hr ) )
			goto error;

		XUI = true;
		return hr;

error:
		ShowXenonMessage(L"MSG","ERROR");

		
	//	UninitXui();
		return hr;
	}

	void DrawText( HXUIDC hdc, HXUIFONT hFont, D3DCOLOR color, float x, float y, LPCWSTR text )
	{
		// Measure the text
		XUIRect clipRect( 0, 0, g_d3dpp.BackBufferWidth-x, g_d3dpp.BackBufferHeight-y );
		XuiMeasureText( hFont, text, -1, XUI_FONT_STYLE_NORMAL, 0, &clipRect );

		// Set the text position in the device context
		D3DXMATRIX matXForm;
		D3DXMatrixIdentity( &matXForm );
		matXForm._41 = x;
		matXForm._42 = y;
		XuiRenderSetTransform( hdc, &matXForm );

		// Select the font and color into the device context
		XuiSelectFont( hdc, hFont );
		XuiSetColorFactor( hdc, (DWORD)color );

		// Draw the text
		XuiDrawText( hdc, text, XUI_FONT_STYLE_NORMAL, 0, &clipRect );
	}



	void Draw(){


	//	 g_pDevice->Clear( 0, NULL, D3DCLEAR_TARGET, 0, 1.0f, 0L );
		// Begin Xui rendering
		XuiRenderBegin( g_hDC, D3DCOLOR_ARGB( 255, 0, 0, 0 ) );

		// Set the view
		D3DXMATRIX matView;
		D3DXMatrixIdentity( &matView );
		XuiRenderSetViewTransform( g_hDC, &matView );

		// Draw the text somewhere
		DrawText( g_hDC, g_hFont, D3DCOLOR_ARGB( 255, 255, 255, 255 ), 200, 200, L"Some Text" );

		// Complete Xui rendering
		XuiRenderEnd( g_hDC );
		XuiRenderPresent( g_hDC, NULL, NULL, NULL );

		g_pDevice->Present( NULL, NULL, NULL, NULL );


	}


	struct Vector2D{
		Vector2D(){};
		Vector2D(float x,float y){
			this->x = x;
			this->y = y;
		}
		float x,y;
	};

	struct Vector3D{
		Vector3D() {};
		Vector3D(float x,float y,float z){
			this->x = x;
			this->y = y;
			this->z = z;
		}
		float x,y,z;
	};

	struct Vertex {
public:
	//формат вершин
	enum {VERTEX_FORMAT = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1};
	//позиция
	Vector3D pos;
	//нормаль
	Vector3D n;
	//текстурные координаты
	Vector2D texCoord;

	Vertex(){}

};

		
	int AppMarathon_DrawMb(int a1){

	
		g_pDevice = *(D3DDevice **)(a1 + 0x24);
		Direct3D* D3D;
		g_pDevice->GetDirect3D(&D3D);

		D3DPWLGAMMA gamma;
		gamma.blue->Base = 255;
		gamma.red->Base = 0;
		gamma.green->Base = 0;


		g_pDevice->SetPWLGamma(0,&gamma);



		Vertex* vertexs = new Vertex[3];

	vertexs[0].pos = Vector3D(-1.0, 1.0, 0.0);
	vertexs[0].n = Vector3D(0.0, 0.0, -1.0);
	vertexs[0].texCoord = Vector2D(0.0f, 0.0f);


	vertexs[1].pos = Vector3D(1.0, 100000.0, 0.0);
	vertexs[1].n = Vector3D(0.0, 0.0, -1.0);
	vertexs[1].texCoord = Vector2D(1.0f, 0.0f);

	vertexs[2].pos = Vector3D(-1.0, -1.0, 0.0);
	vertexs[2].n = Vector3D(0.0, 0.0, -1.0);
	vertexs[2].texCoord = Vector2D(0.0f, 1.0f);



//	g_pDevice->BeginScene();

//	g_pDevice->SetFVF(Vertex::VERTEX_FORMAT);



	//WOrks but need to put in buffer :how :)
//	g_pDevice->BeginScene();
//g_pDevice->DrawPrimitiveUP(D3DPRIMITIVETYPE::D3DPT_TRIANGLELIST,1,vertexs,sizeof(vertexs));

	//g_pDevice->Present(NULL,NULL,NULL,NULL);
	//g_pDevice->EndScene();


		BranchTo(0x825B1A28,int,a1);
	
	
	
	

		return a1;

	}
	void GlobalInstall(){

		

		WRITE_DWORD(0X8204D970,AppMarathon_DrawMb);

	}
}



namespace OmegaF{
	DWORD Omega;
	_DWORD *__fastcall sub_82219460(DWORD a1, DWORD a2){

		  BranchTo(0x82213440,int,a1,a2); //Base Plugins (Omega)
		   _BYTE *v6; // r11
		  if ( *(_DWORD *)(*(_DWORD *)a2 + 0x1C) < 0x10u )
			  v6 = (_BYTE *)(*(_DWORD *)a2 + 8);
		  else
			  v6 = *(_BYTE **)(*(_DWORD *)a2 + 8);

		  if (strcmp((char*)v6,"gauge") == 0){
			  //a1 = (Context ptr + 0x20)
			  DWORD v9[2];
			 
			  BranchTo(0x821F4FA8,int,&v9, a2, 0);
			  //0x260
			  BoostWeakPtr((_DWORD *)(a1 + Omega-0x24), v9);
			  DWORD result = v9[1];
			  if ( v9[1] )
				  result = (_DWORD )sub_821601B8(v9[1]);
			
		  }

		

		  return (DWORD*)a1;

	}

	void __declspec( naked ) sub_822132E8H(int a1){
		__asm{
			mflr r12
				mflr      r12
				stw       r12, -8(r1)
				std       r31, -0x10(r1)
				stwu      r1, -0x60(r1)
				lis r11,0x8221
				ori r11,r11,0x32F8 
				mtctr r11
				bctr r11
		}
	}	


	HOOK(int,__fastcall,sub_822132E8,0x822132E8,int a1){

		sub_822132E8H(a1);
		*(int*)(a1 + Omega)=0;
		*(int*)(a1 + Omega+4)=0;
		return a1;



	}


	int __declspec( naked ) Context_Omega_CoreH(int a1,double a2){
		__asm{
			
				mflr      r12
				stw       r12, -8(r1)
				std       r30, -0x18(r1)
				std       r31, -0x10(r1)
				lis r11,0x8221
				ori r11,r11,0x3028 
				mtctr r11
				bctr r11
		}
	}	


	HOOK(int, __fastcall, Context_Omega_Core,0x82213018,int a1, double a2){



		DWORD gauge =  *(DWORD*)  (a1 + Omega);


		if (gauge){
			if (*(float*)(a1 + Omega-0x4) < 0){
				*(float*)(gauge + 0x2C) = 0;

			}
			else{
				*(float*)(gauge + 0x2C) = *(float*)(a1 + Omega-0x4)  * *(float*)(gauge + 0x34);
			}



		}




		return Context_Omega_CoreH(a1,a2);
	}





	void GlobalInstall(){










		WRITE_DWORD(0x8200AAD4,sub_82219460); // Override Plugin to Init Gauge(local part)
		Omega = *(WORD*)(0x821B5DD6);
		




		//WRITE_DWORD(0x820036BC,0x8223DAB8);


	   INSTALL_HOOK(Context_Omega_Core);
		WRITE_WORD(0x821B5DD6,Omega+0x8);  // Increase Memory Capacity
		INSTALL_HOOK(sub_822132E8);



	}
}




namespace ChainJumpTest{


	HOOK(float*, __fastcall,sub_82208FA8,0x82208FA8,float *result, double a2, double a3, double a4){

		result[7] = a2;
		result[8] = a3;
		if (a4 == 0){
			result[9] = 1.0f;

		}
		else{
			result[9] = a4;
		}
		


		return result;

	}

	void GlobalInstall(){
		INSTALL_HOOK(sub_82208FA8);


	}
}



namespace WhiteGameRestored
{

}

namespace AmyRework{


	//AMY WEAPONS FLLAGS FOR HAMMER
	int __fastcall sub_8223F9F8(int a1, unsigned int a2){


		 int result = *(_DWORD *)(a1 + 0x34);
		_DWORD** v2 = (_DWORD **)result;
		int Flags = *(unsigned __int8 *)(result + 0xD4);

		byte a2_f = a2 >> 24;

		int IsShowHammer = a2_f & 0x40;
		int IsHammerAttack = a2_f & 0x80;

		int CIsShowHammer = Flags & 0x40;
		int CIsHammerAttack = Flags & 0x80;


		if (IsShowHammer != CIsShowHammer){

			if ((IsShowHammer & 0x40) != 0){
				
				*(unsigned __int8 *)(result + 0xD4) |= 0x40;
			}
			if ((IsShowHammer & 0x40) == 0){

				*(unsigned __int8 *)(result + 0xD4) ^= 0x40;
			}

	

			if (IsShowHammer){
				(*(void (__fastcall **)(_DWORD, int))(**(_DWORD **)(result + 0x54) + 0x14))(
					*(_DWORD *)(result + 0x54),
					result + 0xC4);
			}
			else{
				(*(void (__fastcall **)(_DWORD))(**(_DWORD **)(result + 0xC4) + 0x20))(*(_DWORD *)(result + 0xC4));

			}
		}
		if (IsHammerAttack != CIsHammerAttack){

			if ((IsHammerAttack & 0x40) != 0){

				*(unsigned __int8 *)(result + 0xD4) |= 0x80;
			}
			if ((IsHammerAttack & 0x40) == 0){

				*(unsigned __int8 *)(result + 0xD4) ^= 0x80;
			}


	
			if (IsHammerAttack){
				(*(void (__fastcall **)(_DWORD *, _DWORD **))(*v2[0x15] + 0x18))(v2[0x15], v2 + 0x32);
				result = (*(int (__fastcall **)(_DWORD *, _DWORD **))(*v2[0x30] + 0x3C))(v2[0x30], v2 + 0x14);
			}
			else{
				(*(void (__fastcall **)(_DWORD *))(*v2[0x32] + 0x20))(v2[0x32]);
				result = (*(int (__fastcall **)(_DWORD *))(*v2[0x30] + 0x40))(v2[0x30]);
			}



		}




	





		return BranchTo(0x8223F9F8,int,a1,a2);

	}

	void  Context_Amy_CoreX(Sonicteam::Player::State::AmyContext *a1, double a2){


		///((byte*)&a1->UnkownFlagsUnk01)[6] = 0;

	//	a1->IsJumped_PostureVelocityYHandle = 1;
		//a1->VelocityY = 10000;


		BranchTo(0x82206D78,int,a1,a2);
		byte IsAmyAttackX =  (char)((a1->AmyUnkFlags >> 24  ) & 0xFF); // Get First Byte (ALSO it complies as HIBYTE)
		if (IsAmyAttackX != 0){

			//ShowXenonMessage(L"MSG","");
			a1->ExportWeaponRequestFlag |= 0x80000000; //AmyAttack
			a1->ExportWeaponRequestFlag |= 0x40000000; //AmyHammer
		}
		if (a1->CurrentAnimation == 6){
			a1->ExportWeaponRequestFlag |= 0x40000000; //AmyHammer

		}





	}


	void sub_821AB7D0(Sonicteam::Player::State::BasedObject<Sonicteam::Player::State::AmyContext> *a1)
	{

	
		Sonicteam::Player::State::AmyContext* ptr = (Sonicteam::Player::State::AmyContext*)a1->CObjContext;

	

	

		BranchTo(0x821AB7D0,int,a1);

			


	ptr->VelocityY =  ptr->c_jump_double_speed;
	

	}
	
	class AmyAttack:public Sonicteam::Player::State::BasedObject<Sonicteam::Player::State::AmyContext>{
	public:int Flags0;
		   float Time;
	};



#define AmyAtk01 0x1
#define AmyAtk02 0x2
#define AmyAtk03 0x4
#define AmyAtk04 0x8
#define AmyAtk05 0x10
#define AmyAtk06 0x20
#define AmyAtk07 0x40
#define AmyAtk08 0x80
#define AmyAtk09 0x100

#define IsAttack(atk,flags) ((atk & flags) != 0)


	void AmyAttackStartNew(AmyAttack *a1){

		(*(byte*)(&a1->BOContext->AmyUnkFlags )) = 1;

		a1->Time = 0;
		a1->Flags0 = 0;
		if (a1->CObjContext->CurrentAnimation == 6){
			a1->Flags0 |= AmyAtk03; 
		}

		if ( a1->CObjContext->CurrentStickBorder == 0.0){

			a1->CObjContext->CurrentSpeed = 0;
			a1->CObjContext->VelocityY = 0;
			a1->CObjContext->VelocityX = 0;
			a1->CObjContext->IsGravityDisabled = 1;
			a1->Flags0 |= AmyAtk06;
		}
		a1->CObjContext->SetAnimation(0x45);
	}


	int AmyAttackUpdateNew(AmyAttack *a1,double delta){

		if (BranchTo(0x8220A938,int,a1,delta)){
			return 1;
		}

		if ((a1->CObjContext->GroundAirDataFlags & 1) != 0  ){

			//Cancel Hammer Jump
			if ( (a1->CObjContext->Input & 0x400u) != 0 &&  IsAttack(AmyAtk03,a1->Flags0)){
				a1->Flags0 ^= AmyAtk03;
			} 
			if ( (a1->CObjContext->AnimationState & 1) != 0 &&  IsAttack(AmyAtk03,a1->Flags0)) {

				a1->CObjContext->IsJumped_PostureVelocityYHandle=1;
				a1->CObjContext->VelocityY = a1->BOContext->c_jump_double_speed;
				a1->CObjContext->SetAnimation(0xAF);
				a1->Flags0 |= AmyAtk04;
				a1->Time = 0.035f;
			}
			else if ((a1->CObjContext->Input & 0x400u) != 0 && !IsAttack(AmyAtk03,a1->Flags0) ){

				if (!IsAttack(AmyAtk01,a1->Flags0)){
					a1->Flags0 |= AmyAtk01;
					a1->CObjContext->SetAnimation(0xB0);
					a1->Time = 0.035f;
					
				}
				else if (!IsAttack(AmyAtk02,a1->Flags0)){
					a1->Flags0 |= AmyAtk02;
					a1->CObjContext->SetAnimation(0xAE);
					a1->Time = 0.0f;
				}
				else{
				}
			}


			if (a1->CObjContext->CurrentSpeed > 0.0f){
				a1->CObjContext->CurrentSpeed -= a1->CObjContext->c_brake_acc *delta * 0.1f;

			}
		}
		//air combos
		else{
			//Enable Others Combos (by 06)
			if (IsAttack(AmyAtk06,a1->Flags0) && (a1->CObjContext->Input & 0x400u) != 0){


				if (!IsAttack(AmyAtk07,a1->Flags0)){
					a1->Flags0 |= AmyAtk07;
					a1->CObjContext->SetAnimation(0xB0);
					a1->Time = 0.019f;

				}
				else if (!IsAttack(AmyAtk08,a1->Flags0)  ){
					a1->Flags0 |= AmyAtk08;
					a1->CObjContext->SetAnimation(0x45);
					a1->Time = 0.00f;

				}
				else if (!IsAttack(AmyAtk09,a1->Flags0)  ){
					a1->Flags0 |= AmyAtk09;
					a1->CObjContext->SetAnimation(0xAF);
					a1->Time = 0.00f;
					a1->CObjContext->IsGravityDisabled = 0;

				}

			}
			if ((a1->CObjContext->Input & 0x400u) != 0  && !IsAttack(AmyAtk06,a1->Flags0) ){
				if (!IsAttack(AmyAtk05,a1->Flags0)){
					a1->Flags0 |= AmyAtk05;
					a1->CObjContext->SetAnimation(0xAF);
					a1->Time = 0.0f;
				}
			}
		}

		if (IsAttack(AmyAtk05 | AmyAtk04,a1->Flags0) == (AmyAtk04 | AmyAtk05)){

			if ((a1->CObjContext->GroundAirDataFlags & 1) != 0  ){
				
					return BranchTo(0x82209068,int,a1);
				
			}	
		}
		if ((a1->CObjContext->AnimationState & 1) != 0){
			a1->Time -= delta;
		}
	
		if ( (a1->CObjContext->AnimationState & 1) != 0 && a1->Time <= 0 ){
			return BranchTo(0x82209068,int,a1);
		}

		//0x45(attack),0xAF(AIR SPIN), 0xB0(SPIN )




	}

	void AmyAttackEndNew(AmyAttack *a1){
	(*(byte*)(&a1->BOContext->AmyUnkFlags )) = 0;
	a1->CObjContext->IsGravityDisabled = 0;



	}

	int AmyJumpUpdate(AmyAttack *a1,double delta){
		
		if ((a1->CObjContext->Input & 0x400u) != 0){

			//ShowXenonMessage(L"MSG","1");
			a1->ObjectMashine->ChangeMashineState(0x60);

			return 1;

		}

		return BranchTo(0x821AB048,int,a1,delta);

	}



	class AmyStealth:public Sonicteam::Player::State::BasedObject<Sonicteam::Player::State::AmyContext>{
	public:
		   float Time;
	};


	void AmyStealthStartNew(AmyStealth *a1){
	
		//a1->CObjContext->IsForcedMovement = 1;
		//a1->CObjContext->CurrentSpeed = 0;
		a1->CObjContext->VelocityX = 0;
		a1->CObjContext->IsInvulnerable2 = 1;
		(*(byte*)(&a1->BOContext->AmyUnkFlags )) = 1;
				a1->Time = 0;
		a1->CObjContext->SetAnimation(0xB0);
	}
	int AmyStealthUpdateNew(AmyStealth *a1,double delta){


		if ( (unsigned __int8)StateCommonGroundFlagsListenerForStates((int *)a1, delta) )
			return 1;
		BranchTo(0x8220A630,int,a1->CObjContext,delta,a1->CObjContext->c_run_acc * 0.25,a1->CObjContext->c_run_speed_max * 0.65,0.0);
		a1->Time += delta;
		if (a1->Time >= 2.0f)
		{
			a1->ObjectMashine->ChangeMashineState(9);
		}
		if (((a1->CObjContext->Input)  & 0x400 ) != 0 )
		{
			return BranchTo(0x82209068,int,a1);
		}

		return 0;
	}
	void AmyStealthEndNew(AmyStealth *a1){

		a1->CObjContext->IsInvulnerable2 = 0;
		(*(byte*)(&a1->BOContext->AmyUnkFlags )) = 0;
		a1->BOContext->IsForcedMovement = 0;
		//a1->BOContext->StealthTime = a1->BOContext->c_stealth_limit;
	}


	void GlobalInstall(){

		WRITE_DWORD(0x8200D5AC,sub_8223F9F8);
		WRITE_DWORD(0x8223FA34,0x60000000); //Disable Origin Hammer Settup

		WRITE_DWORD(0x82009658,Context_Amy_CoreX);
		

	//	WRITE_DWORD(0x821AB08C,POWERPC_ADDI(4,0,0x5F));
		WRITE_DWORD(0x821AB598,0x60000000);
		WRITE_DWORD(0x821AB5A0,0x60000000);
		WRITE_DWORD(0x821AB5B0,0x60000000);
		WRITE_DWORD(0x821AB5D4,0x60000000);

		WRITE_DWORD(0x821AB508,0x60000000);
		WRITE_DWORD(0x821AB50C,0x60000000);
		WRITE_DWORD(0x821AB510,0x60000000);
		WRITE_DWORD(0x821AB514,0x60000000);
		WRITE_DWORD(0x821AB520,0x60000000);




		WRITE_DWORD(0x821AB630,POWERPC_ADDI(3,0,0x18));
		WRITE_DWORD(0x82004AC4,AmyAttackStartNew);
		WRITE_DWORD(0x82004AC8,AmyAttackUpdateNew);
		WRITE_DWORD(0x82004ACC,AmyAttackEndNew);



		WRITE_DWORD(0x820049A4,AmyJumpUpdate);
		//WRITE_DWORD(0x82004AF4,sub_821AB7D0);


		WRITE_DWORD(0x821AB288,POWERPC_ADDI(3,0,0x14));
		WRITE_DWORD(0x82004A04,AmyStealthStartNew);
		WRITE_DWORD(0x82004A08,AmyStealthUpdateNew);
		WRITE_DWORD(0x82004A0C,AmyStealthEndNew);

	}
}



ZLua::ZLua(void)
{
	OpenLua();
	UseBaseLibs();
	executed = false;
}

ZLua::~ZLua(void)
{
	lua_close(L);
}
ZLua::ZLua(const char* a1){
	FilePath = std::string(a1);
	OpenLua();
	UseBaseLibs();
	executed = false;
	
	
}
void ZLua::UseBaseLibsEx(lua_State* L){
	
	lua_register(L,"LOG",DebugLogRestore::LogNext);
	lua_register(L,"DLOG",DebugLogRestore::Log);
	lua_register(L,"FixedMessage",DebugLogRestore::LogNext);
	lua_register(L,"GetIntField",DebugLogRestore::GetIntField);
	lua_register(L,"SetIntField",DebugLogRestore::SetIntField);
	lua_register(L,"SetFloatField",DebugLogRestore::SetFloatValue);
	lua_register(L,"GetFloatField",DebugLogRestore::GetFloatField);
	lua_register(L,"WriteVirtialBytes",DebugLogRestore::WriteVirtialBytes);
	lua_register(L,"WriteVirtualBytes",DebugLogRestore::WriteVirtialBytes);
	lua_register(L,"WriteVirtualDword",DebugLogRestore::WriteVirtialDword);
	lua_register(L,"WriteVirtualFloat",DebugLogRestore::WriteVirtialFloat);
	lua_register(L,"WriteVirtualShort",DebugLogRestore::WriteVirtialShort);
	lua_register(L,"WriteVirtualString",DebugLogRestore::WriteVirtualString);
	lua_register(L,"WriteVirtualBytesRange",DebugLogRestore::WriteVirtialBytesRange);
	lua_register(L,"StateChangeState",DebugLogRestore::StateChangeState);
	lua_register(L,"AddCustomState",DebugLogRestore::AddCustomState);
	lua_register(L,"CallCPLUSFunc",DebugLogRestore::CallCPLUSFunc);
	lua_register(L,"HEX",DebugLogRestore::HEX);
	lua_register(L,"Malloc",DebugLogRestore::MallocX);
	lua_register(L,"Free",DebugLogRestore::FreeX);
	lua_register(L,"NewString",DebugLogRestore::NewString);
	lua_register(L,"FreeString",DebugLogRestore::FreeString);
	lua_register(L,"CallCPLUSFuncF",DebugLogRestore::CallCPLUSFuncF);
	lua_register(L,"reload",DebugLogRestore::LuaDoFile);


	//SonicTeam(SetTable)
	lua_newtable(L);
	lua_setglobal(L,"SonicTeam");
	/*
	lua_getglobal(ZL->L,"SonicTeam"); // 1
	lua_pushstring(ZL->L, "Test"); //2
	lua_pushnumber(ZL->L,1);  // 3
	lua_settable(ZL->L, -3);
	*/
	
	

	// SonicTeam.EffectModule(SetTable)
	lua_getglobal(L,"SonicTeam");


	lua_pushstring(L,"EffectModule");
	lua_newtable(L);
	lua_settable(L,-3); // Stack Full Cleared Now I Need Get EffectModule OnceMore

	//SonicTeam.EffectModule(Get
	lua_pushstring(L,"EffectModule");
	lua_gettable(L,-2); //SonicTeam.EffectModule (-2 SonicTeamBackRegiter)

	lua_registerex1(L,"Connect",DebugLogRestore::ConnectEffectModuleFunc,-1);
	lua_registerex1(L,"ShowParticle",DebugLogRestore::SonicTeam_EffectModule_RunEffect,-1);
	lua_registerex1(L,"HideParticle",DebugLogRestore::SonicTeam_EffectModule_HideEffect,-1);


	lua_pop(L,1);
	lua_pushstring(L,"ContextModule");
	lua_newtable(L);
	lua_settable(L,-3); // Stack Full Cleared Now I Need Get EffectModule OnceMore


	//SonicTeam.ContextModule(Get
	lua_pushstring(L,"ContextModule");
	lua_gettable(L,-2); //SonicTeam.ContextModule (-2 SonicTeamBackRegiter)


	lua_registerex1(L,"Connect",DebugLogRestore::ConnectContextModuleFunc,-1);



	lua_pop(L,2);

	lua_newtable(L);
	lua_setglobal(L,"Bit");


	lua_getglobal(L,"Bit");
	lua_registerex1(L,"SL",DebugLogRestore::BIT_ShiftLeft,-1);
	lua_registerex1(L,"SR",DebugLogRestore::BIT_ShiftRight,-1);
	lua_registerex1(L,"AND",DebugLogRestore::BIT_AND,-1);
	lua_registerex1(L,"OR",DebugLogRestore::BIT_OR,-1);

	lua_pop(L,1);
	lua_newtable(L);
	lua_setglobal(L,"script");

	lua_getglobal(L,"script");
	lua_registerex1(L,"reload",DebugLogRestore::LuaDoFile,-1);

	lua_pop(L,1);

	lua_newtable(L);
	lua_setglobal(L,"Memory");

	lua_getglobal(L,"Memory");
	lua_registerex1(L,"WriteByte",DebugLogRestore::Memory_WriteByte,-1);
	lua_registerex1(L,"WriteInt",DebugLogRestore::Memory_WriteInt,-1);

	lua_registerex1(L,"GetByte",DebugLogRestore::Memory_GetByte,-1);
	lua_registerex1(L,"GetInt",DebugLogRestore::Memory_GetInt,-1);


	lua_pop(L,1);








	


}

void ZLua::UseBaseLibs(){

	UseBaseLibsEx(L);

}
void ZLua::OpenLua(){
	L = lua_open();


}

const char* ZLua::GetGlobalString(const char* string){

	lua_getglobal(this->L,string);
	return lua_tostring(this->L,-1);
	
}


extern "C" bool ZLua::GetGlobalBool(const char* string){


	lua_getglobal(this->L,string);
	if (lua_isboolean(this->L,-1)){
		return lua_toboolean(this->L,-1);	
	}
	lua_pop(this->L,1);
	return false;
}


void ZLua::DoFile(bool ignore){

	locked = true;
	if (ignore){
		executed =false;

	}

	if (!executed) {

		int re = luaL_loadfile(L, FilePath.c_str());
		if ( re== LUA_ERRSYNTAX || re == LUA_ERRFILE ){
			ShowXenonMessage(L"ERROR",lua_tostring(L,-1));
			lua_close(L);
			Sleep(10000);
			exit(0);
			return;
		}
		else{
			lua_pcall(L, 0,0,0);
		}

			//   ShowXenonMessage(L"DUMBY",luaL_loadfile(L, FilePath.c_str()),0);

	
		executed = true;

	}
	locked = false;
	
}
//testing
void ZLua::CallFunction(){

}



bool once = false;
#pragma warning( pop ) 
namespace TagStory{




	int __declspec( naked ) sub_824ECD30H(Sonicteam::HUDOption *a1, int a2, float *a3){

		__asm{

			mflr      r12
				std       r17, -0x80(r1)
				std       r18, -0x78(r1)	
				std       r19, -0x70(r1)
				std       r20, -0x68(r1)
				std       r21, -0x60(r1)
				std       r22, -0x58(r1)
				std       r23, -0x50(r1)
				std       r24, -0x48(r1)
				std       r25, -0x40(r1)
				std       r26, -0x38(r1)
				std       r27, -0x30(r1)
				std       r28, -0x28(r1)
				std       r29, -0x20(r1)
				std       r30, -0x18(r1)
				std       r31, -0x10(r1)
				stw       r12, -8(r1)
				stfd      fp30, -0x90(r1)
				stfd      fp31, -0x88(r1)
				lis r11,0x824E
				ori r11,r11,0xCD40
				mtctr r11
				bctr
		}
	}


	HOOK(int,__fastcall,sub_824ECD30,0x824ECD30,Sonicteam::HUDOption *a1, int a2, float *a3){

	
		sub_824ECD30H(a1,a2,a3);
		a1->CSDSpriteOption->UnkReference++;

	    Sonicteam::SoX::RefCountObject* some =LabelSpawn((void*)malloc06(0x70),a1->GetCurrentDoc(),a1->TextCard_msg_audio,a1->CSDSpriteOption,"option","text3",21.0,0.0,0.0,0,0);
		some->UnkReference++;
		LabelExecute(&a1->HMMOuint0x1E4,some);

			

		return (int)a1;
	
	}


	int MainMenuProcess(Sonicteam::MainMenuTask* a1){

		

		if (a1->MMCurrentCase == 0x33){
			a1->MMCurrentCase = 0x200;
		}

		if (a1->MMCurrentCase == 0x16){
			a1->MMCurrentCase = 0x100;
		}

		switch (a1->MMCurrentCase)
		{
		case 0x200:


			if (!BranchTo(0X824FE3B8,int,a1,a1->MMP1Input,8,&a1->MMTuint0xE0)){
				a1->MMP1Input = 0;
				return 0;
			}

			
			a1->MMHudOption->OnMessageRecieved(&Sonicteam::SoX::Message(0x1B055,5,0,0,a1->MMTuint0xE0));
			a1->MMP1Input = 0;



			break;
			//new multiplayer
		case 0x100:
			if ( !a1->MMTuint0x270 )
				return 0;
			{
				a1->MMHudMainMenu->OnMessageRecieved(&Sonicteam::SoX::Message(0x1B053,0x64,a1->MMTuint0xA8 | 0x20000)); //mst (
			}
			a1->MMCurrentCase = 0x101;
			a1->MMP1Input = 0;
			BranchTo(0x824FDBC0,int,a1->MMTuint0x9C,(int*)&a1->MMTextCard_msg_tag_c);
			a1->MMTuint0x270 = 0;
			return 0;
		case  0x101:

			//X
			if ((a1->MMP1Input & 0x10)  != 0){

					int s[] = {a1->MMHudMainMenu->HMMCSDSpriteMainMenu};
					BranchTo(0x824CE9D0,int,(int*)s,"main_menu","tagstory_select"); //PLAY
					a1->MMHudMainMenu->OnMessageRecieved(&Sonicteam::SoX::Message(0x1B053,0x66,a1->MMTuint0xAC | 0x20000)); //show select3 arrow
					a1->MMHudMainMenu->OnMessageRecieved(&Sonicteam::SoX::Message(0x1B053,0x65,a1->MMTuint0xA8 | 0x20000)); //hide select2 arrow
					BranchTo(0x824FD460,int,a1,"main_deside");
					a1->MMCurrentCase = a1->MMTuint0xA8 == 0 ? 0x102 : 0x103;
					a1->MMP1Input = 0;
					return 0;
			
			}


			if (!BranchTo(0X824FE3B8,int,a1,a1->MMP1Input,2,&a1->MMTuint0xA8)){
				a1->MMP1Input = 0;
				return 0;
			}
			a1->MMP1Input = 0;
			{

			BranchTo(0x824FDBC0,int,a1->MMTuint0x9C,a1->MMTextCard_msg_tag_c);
			a1->MMHudMainMenu->OnMessageRecieved(&Sonicteam::SoX::Message(0x1B053,0xB,a1->MMTuint0xA8 |  0x20000)); //mst 
			
			BranchTo(0x824FDBC0,int,a1->MMTuint0x9C,&a1->MMTextCard_msg_tag_c + a1->MMTuint0xA8);
			}
			
			return 0;
		case 0x102:
			//Back
			if ((a1->MMP1Input & 0x20) != 0){
				int s[] = {a1->MMHudMainMenu->HMMCSDSpriteMainMenu};
				BranchTo(0x824CE670,int,(int*)s,"main_menu","tagstory_select"); //PLAY

				a1->MMHudMainMenu->OnMessageRecieved(&Sonicteam::SoX::Message(0x1B053,0x4E,a1->MMTuint0xA8 | 0x20000)); //mst (
				a1->MMHudMainMenu->OnMessageRecieved(&Sonicteam::SoX::Message(0x1B053,0xB,a1->MMTuint0xA8 |  0x20000)); //mst (
				a1->MMHudMainMenu->OnMessageRecieved(&Sonicteam::SoX::Message(0x1B053,0x67,a1->MMTuint0xAC | 0x20000)); //Select3 Arrow Show(Position)

				BranchTo(0x824FD460,int,a1,"main_deside");
				a1->MMCurrentCase = 0x101;
				return 0;
			}
			//select
			if ((a1->MMP1Input & 0x10) != 0){

				int s[] = {a1->MMHudMainMenu->HMMCSDSpriteMainMenu};
				BranchTo(0x824CE670,int,(int*)s,"main_menu","tagstory_select"); //PLAY

				a1->MMHudMainMenu->OnMessageRecieved(&Sonicteam::SoX::Message(0x1B053,0x67,a1->MMTuint0xAC | 0x20000)); //Select3 Arrow Show(Position)
				a1->MMCurrentCase = 0x103;
				BranchTo(0x824FD460,int,a1,"main_deside");
				return 0;

			}


			if (!BranchTo(0X824FE3B8,int,a1,a1->MMP1Input,2,&a1->MMTuint0xAC)){
				a1->MMP1Input = 0;
				return 0;
			}
			a1->MMP1Input = 0;
			a1->MMHudMainMenu->OnMessageRecieved(&Sonicteam::SoX::Message(0x1B053,0x66,a1->MMTuint0xAC | 0x20000)); //Select3 Arrow Show(Position)

			return 0;
		}



		return BranchTo(0x824FFCF8,int,a1);

		
	}

	void GlobalInstall()
	{
		INSTALL_HOOK(sub_824ECD30);
		WRITE_DWORD(0x82039C10,MainMenuProcess);
		
		//WRITE_DWORD(0x82500B78,0x60000000);
		//WRITE_DWORD(0x82500BA8,0x60000000);
		//WRITE_DWORD(0x82500C00,0x60000000);


	}
}




namespace TailsGauge{

	class TailsContextEX:public Sonicteam::Player::State::TailsContext{
	public:
		boost::weak_ptr<Sonicteam::Player::GaugeStandard> GaugePlugin;
		TailsContextEX(){

		}
		~TailsContextEX(){

		}
		void FakeDestroy(unsigned int a2){
			TailsContextEX::~TailsContextEX();
			Sonicteam::SoX::Memory::IDestructible::DestroyObject(a2);
		}
		

	};


	void TailsOnLink(Sonicteam::Player::IDynamicLink* _thi,boost::shared_ptr<Sonicteam::Player::IPlugIn>& plugin){


		BranchTo(0x8220F330,int,_thi,&plugin);
		 Sonicteam::Player::State::TailsContext* _this = dynamic_cast<Sonicteam::Player::State::TailsContext*>(_thi);

		 
		 TailsContextEX* ex = (TailsContextEX*)_this;
		if (plugin->PluginName == "gauge"){
			
		//	plugin.lock().reset(new Sonicteam::Player::GaugeStandard());
			ex->GaugePlugin = boost::dynamic_pointer_cast<Sonicteam::Player::GaugeStandard>(plugin);
		}


	}
	void TailsContextOnUpdate(TailsContextEX* _this,float delta){

		BranchTo(0x8221A7D8,int,_this,delta);

		if ( Sonicteam::Player::GaugeStandard* gauge =  _this->GaugePlugin.lock().get() ){
			
		//	ShowXenonMessage(L"MSG","Ge");
			gauge->GaugeValue = _this->TCuint0x230 * gauge->c_s_max;
		}


	}

	DWORD TailsContextDestructor(TailsContextEX* _this,unsigned int a2){
		 
	
	
		// delete _this->GaugePlugin.get(); // and bo
		 BranchTo(0x82206FD8,int,_this,a2);
		 
		 _this->FakeDestroy(a2);

		 
		 //_this->DestroyObject(a2);

	
		 return (DWORD)_this;
	}


	void GlobalInstall()
	{

		WRITE_DWORD(0x8200B7F8,TailsOnLink);
		WRITE_DWORD(0x821B5FDC,POWERPC_LIS(3,0x258));
		WRITE_DWORD(0x8200B868,TailsContextOnUpdate);


		//Need to think about how to do it (
		WRITE_DWORD(0x8200B860,TailsContextDestructor);

	}
}

namespace AmyLOS{


	//AMY WEAPONS FLLAGS FOR HAMMER
	int __fastcall sub_8223F9F8(int a1, unsigned int a2){


		int result = *(_DWORD *)(a1 + 0x34);
		_DWORD** v2 = (_DWORD **)result;
		int Flags = *(unsigned __int8 *)(result + 0xD4);

		byte a2_f = a2 >> 24;

		int IsShowHammer = a2_f & 0x40;
		int IsHammerAttack = a2_f & 0x80;

		int CIsShowHammer = Flags & 0x40;
		int CIsHammerAttack = Flags & 0x80;


		if (IsShowHammer != CIsShowHammer){

			if ((IsShowHammer & 0x40) != 0){

				*(unsigned __int8 *)(result + 0xD4) |= 0x40;
			}
			if ((IsShowHammer & 0x40) == 0){

				*(unsigned __int8 *)(result + 0xD4) ^= 0x40;
			}



			if (IsShowHammer){
				(*(void (__fastcall **)(_DWORD, int))(**(_DWORD **)(result + 0x54) + 0x14))(
					*(_DWORD *)(result + 0x54),
					result + 0xC4);
			}
			else{
				(*(void (__fastcall **)(_DWORD))(**(_DWORD **)(result + 0xC4) + 0x20))(*(_DWORD *)(result + 0xC4));

			}
		}
		if (IsHammerAttack != CIsHammerAttack){

			if ((IsHammerAttack & 0x40) != 0){

				*(unsigned __int8 *)(result + 0xD4) |= 0x80;
			}
			if ((IsHammerAttack & 0x40) == 0){

				*(unsigned __int8 *)(result + 0xD4) ^= 0x80;
			}



			if (IsHammerAttack){
				(*(void (__fastcall **)(_DWORD *, _DWORD **))(*v2[0x15] + 0x18))(v2[0x15], v2 + 0x32);
				result = (*(int (__fastcall **)(_DWORD *, _DWORD **))(*v2[0x30] + 0x3C))(v2[0x30], v2 + 0x14);
			}
			else{
				(*(void (__fastcall **)(_DWORD *))(*v2[0x32] + 0x20))(v2[0x32]);
				result = (*(int (__fastcall **)(_DWORD *))(*v2[0x30] + 0x40))(v2[0x30]);
			}



		}










		return BranchTo(0x8223F9F8,int,a1,a2);

	}

	void  Context_Amy_CoreX(Sonicteam::Player::State::AmyContext *a1, double a2){


		///((byte*)&a1->UnkownFlagsUnk01)[6] = 0;

		//	a1->IsJumped_PostureVelocityYHandle = 1;
		//a1->VelocityY = 10000;


		BranchTo(0x82206D78,int,a1,a2);
		byte IsAmyAttackX =  (char)((a1->AmyUnkFlags >> 24  ) & 0xFF); // Get First Byte (ALSO it complies as HIBYTE)
		if (IsAmyAttackX != 0){

			//ShowXenonMessage(L"MSG","");
			a1->ExportWeaponRequestFlag |= 0x80000000; //AmyAttack
			a1->ExportWeaponRequestFlag |= 0x40000000; //AmyHammer
		}
		if (a1->CurrentAnimation == 6){
			a1->ExportWeaponRequestFlag |= 0x40000000; //AmyHammer

		}





	}


	void sub_821AB7D0(Sonicteam::Player::State::BasedObject<Sonicteam::Player::State::AmyContext> *a1)
	{


		Sonicteam::Player::State::AmyContext* ptr = (Sonicteam::Player::State::AmyContext*)a1->CObjContext;

		BranchTo(0x821AB7D0,int,a1);


		ptr->VelocityY =  ptr->c_jump_double_speed;


	}

	class AmyAttack:public Sonicteam::Player::State::BasedObject<Sonicteam::Player::State::AmyContext>{
	public:int Flags0;
		   float Time;
	};



#define AmyAtk01 0x1
#define AmyAtk02 0x2
#define AmyAtk03 0x4
#define AmyAtk04 0x8
#define AmyAtk05 0x10
#define AmyAtk06 0x20
#define AmyAtk07 0x40
#define AmyAtk08 0x80
#define AmyAtk09 0x100

#define IsAttack(atk,flags) ((atk & flags) != 0)


	void AmyAttackStartNew(AmyAttack *a1){

		(*(byte*)(&a1->BOContext->AmyUnkFlags )) = 1;
		a1->Time = 0;
		a1->Flags0 = 0;

		//hammerjump
		if (a1->CObjContext->CurrentAnimation == 6){
			a1->Flags0 |= AmyAtk01; 
			a1->CObjContext->SetAnimation(0x45);
		}


		if (a1->Flags0 == 0){
			a1->CObjContext->SetAnimation(0x45);
			

			if ((a1->CObjContext->GroundAirDataFlags & 1) != 0){
					a1->CObjContext->IsGravityDisabled = 0;
					a1->CObjContext->CurrentSpeed = 0;
					a1->CObjContext->VelocityY = 0;
					a1->CObjContext->VelocityX = 0;
			}
		
		}

	
	}


	int AmyAttackUpdateNew(AmyAttack *a1,double delta){

		if (BranchTo(0x8220A938,int,a1,delta)){
			return 1;
		}

		if ((a1->CObjContext->GroundAirDataFlags & 1) != 0  ){

			//Cancel Hammer Jump
			if ( (a1->CObjContext->Input & 0x400u) != 0 &&  IsAttack(AmyAtk01,a1->Flags0)){
				a1->Flags0 ^= AmyAtk01;
			} 
			if ( (a1->CObjContext->AnimationState & 1) != 0 &&  IsAttack(AmyAtk01,a1->Flags0)) {

				a1->CObjContext->IsJumped_PostureVelocityYHandle=1;
				a1->CObjContext->VelocityY = a1->BOContext->c_jump_double_speed;
				a1->CObjContext->SetAnimation(0xAF);
				a1->Flags0 |= AmyAtk02;
				a1->Time = 0.035f;
			}

			if (a1->CObjContext->CurrentSpeed > 0.0f){
				a1->CObjContext->CurrentSpeed -= a1->CObjContext->c_brake_acc *delta * 0.1f;

			}
		}
		//air combos
		else{
			if ((a1->CObjContext->Input & 0x400u) != 0 && !IsAttack(AmyAtk04,a1->Flags0)){

				//a1->CObjContext->IsJumped_PostureVelocityYHandle=1;
				//a1->CObjContext->VelocityY = a1->BOContext->c_jump_double_speed;
				a1->CObjContext->SetAnimation(0xB0);
				a1->Flags0 |= AmyAtk04;
				a1->Time = 0.035f;
			}
			//Hold
			else if ((a1->CObjContext->Input & 0x200u) != 0 && IsAttack(AmyAtk04,a1->Flags0) && !IsAttack(AmyAtk05,a1->Flags0) ){

				a1->CObjContext->SetAnimation(0xAF);
				a1->Flags0 |= AmyAtk05;
				a1->Time = 0.02f;
			}
			if (IsAttack(AmyAtk05,a1->Flags0) && (a1->CObjContext->Input & 0x200u) != 0 ){
				a1->Time = delta + 0.01;
			}

	
		}

		if ((a1->CObjContext->GroundAirDataFlags & 1) != 0  )
		{
			if (IsAttack(AmyAtk04,a1->Flags0) || IsAttack (AmyAtk05,a1->Flags0)){

				return BranchTo(0x82209068,int,a1);
			}	
			
		}

		
		if ((a1->CObjContext->AnimationState & 1) != 0){
			a1->Time -= delta;


			//Reset
			if (IsAttack(AmyAtk02,a1->Flags0)) a1->CObjContext->IsJumped_PostureVelocityYHandle = 0;
		}

		if ( (a1->CObjContext->AnimationState & 1) != 0 && a1->Time <= 0 ){
			return BranchTo(0x82209068,int,a1);
		}

		//0x45(attack),0xAF(AIR SPIN), 0xB0(SPIN )

	}

	void AmyAttackEndNew(AmyAttack *a1){
		(*(byte*)(&a1->BOContext->AmyUnkFlags )) = 0;
		
		a1->CObjContext->IsGravityDisabled = 0;



	}

	int AmyJumpUpdate(AmyAttack *a1,double delta){

		if ((a1->CObjContext->Input & 0x400u) != 0){

			//ShowXenonMessage(L"MSG","1");
			a1->ObjectMashine->ChangeMashineState(0x60);

			return 1;

		}

		return BranchTo(0x821AB048,int,a1,delta);

	}



	class AmyStealth:public Sonicteam::Player::State::BasedObject<Sonicteam::Player::State::AmyContext>{
	public:
		float Time;
	};


	void AmyStealthStartNew(AmyStealth *a1){

		//a1->CObjContext->IsForcedMovement = 1;
		//a1->CObjContext->CurrentSpeed = 0;
		a1->CObjContext->VelocityX = 0;
		a1->CObjContext->IsInvulnerable2 = 1;
		(*(byte*)(&a1->BOContext->AmyUnkFlags )) = 1;
		a1->Time = 0;
		a1->CObjContext->SetAnimation(0xB0);
	}
	int AmyStealthUpdateNew(AmyStealth *a1,double delta){


		if ( (unsigned __int8)StateCommonGroundFlagsListenerForStates((int *)a1, delta) )
			return 1;
		BranchTo(0x8220A630,int,a1->CObjContext,delta,a1->CObjContext->c_run_acc * 0.25,a1->CObjContext->c_run_speed_max * 0.65,0.0);
		a1->Time += delta;
		if (a1->Time >= ((AmyContextE*)a1->CObjContext)->c_before_dizzy_time)
		{
			a1->ObjectMashine->ChangeMashineState(9);
		}
		if (((a1->CObjContext->Input)  & 0x400 ) != 0 )
		{
			return BranchTo(0x82209068,int,a1);
		}

		return 0;
	}
	void AmyStealthEndNew(AmyStealth *a1){

		a1->CObjContext->IsInvulnerable2 = 0;
		(*(byte*)(&a1->BOContext->AmyUnkFlags )) = 0;
		a1->BOContext->IsForcedMovement = 0;
		//a1->BOContext->StealthTime = a1->BOContext->c_stealth_limit;
	}

	class AmyFalling:public Sonicteam::Player::State::BasedObject<Sonicteam::Player::State::AmyContext>{
	public:
		float Time;
	};
	//MakeStateI(AmyFallingT,AmyFalling);


	class  CommonFall:public Sonicteam::Player::State::CommonObject
	{
	public:
		float UnkTime;
		float FallStateFlags;
	};



	class CommonJump : public CommonFall
	{
	public:
		float UnkFloat01;
		int AnimNumS;
		int AnimNum;
		int UnkUint02;
	};



	void JumpAmyStart(CommonJump* _this){

		//0xD - Bruh
		//0xE - Spin


		//jump double
		//0xB1 - Spin
		//0xB2 - Air (Player Voice)

	//	int table1[] = {0xD,0xE};
	//	int table2[] = {0xB1,0xB2};


		int table1[] = {0xD,0xB2};
		int table2[] = {0xE,0xB1};

		Sonicteam::Player::State::AmyContext* _v = (Sonicteam::Player::State::AmyContext*)(_this->CObjContext);


	
		_this->AnimNum = table2[_v->AvailableJumpNum % 2];
		_this->AnimNumS = table1[_v->AvailableJumpNum % 2];

		if (_v->AvailableJumpNum <= 0){
			_this->AnimNum = table1[1];
		}
		
	



		BranchTo(0x82209208 ,int,_this);
	}


	void AmyNewParams(unsigned int _this,Sonicteam::LuaSystem*& lp){

		
		BranchTo(0x82207028,int,_this,&lp);
		AmyContextE* t = (AmyContextE*)(_this - 0x20);
		t->c_before_dizzy_time =  lp->GetFloatValue(std::string("c_before_dizzy_time"));


	}


	void GlobalInstall(){



		WRITE_DWORD(0x821B5E3C,POWERPC_LI(3,0x264));
		WRITE_DWORD(0x82009648,AmyNewParams); //OnVarible



		//jump
		WRITE_DWORD(0x820049A0,JumpAmyStart);




		WRITE_DWORD(0x8200D5AC,sub_8223F9F8);
		WRITE_DWORD(0x8223FA34,0x60000000); //Disable Origin Hammer Settup

		WRITE_DWORD(0x82009658,Context_Amy_CoreX);


		//	WRITE_DWORD(0x821AB08C,POWERPC_ADDI(4,0,0x5F));



		WRITE_DWORD(0x821AB5B8,POWERPC_LI(4,4));
		WRITE_DWORD(0x821AB520,0x60000000);
		//Jump Double fixed
		WRITE_DWORD(0x821AB598,0x60000000);
		WRITE_DWORD(0x821AB5A0,0x60000000);
		WRITE_DWORD(0x821AB5B0,0x60000000);
		WRITE_DWORD(0x821AB5D4,0x60000000);

		WRITE_DWORD(0x821AB508,0x60000000);
		WRITE_DWORD(0x821AB50C,0x60000000);
		WRITE_DWORD(0x821AB510,0x60000000);
		WRITE_DWORD(0x821AB514,0x60000000);
		WRITE_DWORD(0x821AB520,0x60000000);




		WRITE_DWORD(0x821AB630,POWERPC_ADDI(3,0,0x18));
		WRITE_DWORD(0x82004AC4,AmyAttackStartNew);
		WRITE_DWORD(0x82004AC8,AmyAttackUpdateNew);
		WRITE_DWORD(0x82004ACC,AmyAttackEndNew);



		WRITE_DWORD(0x820049A4,AmyJumpUpdate);
		//WRITE_DWORD(0x82004AF4,sub_821AB7D0);


		WRITE_DWORD(0x821AB288,POWERPC_ADDI(3,0,0x14));
		WRITE_DWORD(0x82004A04,AmyStealthStartNew);
		WRITE_DWORD(0x82004A08,AmyStealthUpdateNew);
		WRITE_DWORD(0x82004A0C,AmyStealthEndNew);


	//	WRITE_DWORD(0x82B169F0 + 0x4,)





	}
}

int addWrapper(int a, int b) {
	// Some implementation here
	return 0;
}

void CheckEmulated::GlobalInstall()
{

	 //boost::function<int()> operation = boost::bind(addWrapper, 10, 20);



	//Sonicteam::Player::PhantomEnterListener* le = new Sonicteam::Player::PhantomEnterListener(operation);


//	(new Sonicteam::SoX::Component(0))->DestroyObject(1);
//	(new Sonicteam::SoX::Graphics::Frame())->DestroyObject(1);
	



	HookV2::IsNotEmulatedHardWare = HookV2::CheckIsNotEmulatedHardWare();
}


namespace DevTitle{


	void sub_82161AB8(Sonicteam::DocMarathonImp* _this){


	

	//	BranchTo(0x82161AB8,int,_this);
		int doc = *(int*)0x82D35E50;
		_this->DocSetCurrentMode(doc);
	}

	void GlobalInstall()
	{
		WRITE_DWORD(0x82000AAC,sub_82161AB8);

	}
}

