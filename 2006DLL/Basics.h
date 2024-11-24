#pragma once
#ifndef Basics_H
#define Basics_H





#define MASK_N_BITS(N) ( ( 1 << ( N ) ) - 1 )
#define POWERPC_HI(X) ( ( X >> 16 ) & 0xFFFF )
#define POWERPC_LO(X) ( X & 0xFFFF )

//
// PowerPC most significant bit is addressed as bit 0 in documentation.
//
#define POWERPC_BIT32(N) ( 31 - N )

//
// Opcode is bits 0-5. 
// Allowing for op codes ranging from 0-63.
//
#define POWERPC_OPCODE(OP)       ( OP << 26 )
#define POWERPC_OPCODE_ADDI      POWERPC_OPCODE( 14 )
#define POWERPC_OPCODE_ADDIS     POWERPC_OPCODE( 15 )
#define POWERPC_OPCODE_BC        POWERPC_OPCODE( 16 )
#define POWERPC_OPCODE_B         POWERPC_OPCODE( 18 )
#define POWERPC_OPCODE_BCCTR     POWERPC_OPCODE( 19 )
#define POWERPC_OPCODE_ORI       POWERPC_OPCODE( 24 )
#define POWERPC_OPCODE_EXTENDED  POWERPC_OPCODE( 31 ) // Use extended opcodes.
#define POWERPC_OPCODE_STW       POWERPC_OPCODE( 36 )
#define POWERPC_OPCODE_LWZ       POWERPC_OPCODE( 32 )
#define POWERPC_OPCODE_LD        POWERPC_OPCODE( 58 )
#define POWERPC_OPCODE_STD       POWERPC_OPCODE( 62 )
#define POWERPC_OPCODE_MASK      POWERPC_OPCODE( 63 )

#define POWERPC_EXOPCODE(OP)     ( OP << 1 )
#define POWERPC_EXOPCODE_BCCTR   POWERPC_EXOPCODE( 528 )
#define POWERPC_EXOPCODE_MTSPR   POWERPC_EXOPCODE( 467 )

//
// SPR field is encoded as two 5 bit bitfields.
//
#define POWERPC_SPR(SPR) (UINT32)( ( ( SPR & 0x1F ) << 5 ) | ( ( SPR >> 5 ) & 0x1F ) )

//
// Instruction helpers.
//
// rD - Destination register.
// rS - Source register.
// rA/rB - Register inputs.
// SPR - Special purpose register.
// UIMM/SIMM - Unsigned/signed immediate.
//
#define POWERPC_ADDI(rD, rA, SIMM)  (UINT32)( POWERPC_OPCODE_ADDI | ( rD << POWERPC_BIT32( 10 ) ) | ( rA << POWERPC_BIT32( 15 ) ) | SIMM )
#define POWERPC_ADDIS(rD, rA, SIMM) (UINT32)( POWERPC_OPCODE_ADDIS | ( rD << POWERPC_BIT32( 10 ) ) | ( rA << POWERPC_BIT32( 15 ) ) | SIMM )
#define POWERPC_LIS(rD, SIMM)       POWERPC_ADDIS( rD, 0, SIMM ) // Mnemonic for addis %rD, 0, SIMM
#define POWERPC_LWZ(rS, DS, rA)      (UINT32)( POWERPC_OPCODE_LWZ | ( rS << POWERPC_BIT32( 10 ) ) | ( rA << POWERPC_BIT32( 15 ) ) | ( (INT16)DS & 0xFFFF ) )
#define POWERPC_LI(rD, SIMM)        POWERPC_ADDI( rD, 0, SIMM )  // Mnemonic for addi %rD, 0, SIMM
#define POWERPC_MTSPR(SPR, rS)      (UINT32)( POWERPC_OPCODE_EXTENDED | ( rS << POWERPC_BIT32( 10 ) ) | ( POWERPC_SPR( SPR ) << POWERPC_BIT32( 20 ) ) | POWERPC_EXOPCODE_MTSPR )
#define POWERPC_MTCTR(rS)           POWERPC_MTSPR( 9, rS ) // Mnemonic for mtspr 9, rS
#define POWERPC_ORI(rS, rA, UIMM)   (UINT32)( POWERPC_OPCODE_ORI | ( rS << POWERPC_BIT32( 10 ) ) | ( rA << POWERPC_BIT32( 15 ) ) | UIMM )
#define POWERPC_BCCTR(BO, BI, LK)   (UINT32)( POWERPC_OPCODE_BCCTR | ( BO << POWERPC_BIT32( 10 ) ) | ( BI << POWERPC_BIT32( 15 ) ) | ( LK & 1 ) | POWERPC_EXOPCODE_BCCTR )
#define POWERPC_STD(rS, DS, rA)     (UINT32)( POWERPC_OPCODE_STD | ( rS << POWERPC_BIT32( 10 ) ) | ( rA << POWERPC_BIT32( 15 ) ) | ( (INT16)DS & 0xFFFF ) )
#define POWERPC_STW(rS, DS, rA)     (UINT32)( POWERPC_OPCODE_STW | ( rS << POWERPC_BIT32( 10 ) ) | ( rA << POWERPC_BIT32( 15 ) ) | ( (INT16)DS & 0xFFFF ) )
#define POWERPC_LD(rS, DS, rA)      (UINT32)( POWERPC_OPCODE_LD | ( rS << POWERPC_BIT32( 10 ) ) | ( rA << POWERPC_BIT32( 15 ) ) | ( (INT16)DS & 0xFFFF ) )

//
// Branch related fields.
//
#define POWERPC_BRANCH_LINKED    1
#define POWERPC_BRANCH_ABSOLUTE  2
#define POWERPC_BRANCH_TYPE_MASK ( POWERPC_BRANCH_LINKED | POWERPC_BRANCH_ABSOLUTE )

#define POWERPC_BRANCH_OPTIONS_ALWAYS ( 20 )


#ifndef _BOOST_

#endif

#ifndef  _XTL_
#include <xtl.h>
#endif




//#include <cassert>
#include <vector>
#include <iterator>
#include <list>
#include <iostream>
#include <sstream>

#include "AtgConsole.h"
#include "AtgUtil.h"
#include "AtgInput.h"
#include "AtgSignIn.h"
#include <map>

#include <xui.h>



#include "Marathon/Player/RootFrame.h"

#include "Marathon/Player/State/CommonContext.h"
#include "Marathon/Player/State/SonicContext.h"
#include "Marathon/Player/State/TailsContext.h"
#include "Marathon/Player/State/AmyContext.h"
#include "Marathon/Combo/AttackManager.h"
#include "Marathon/Combo/ScoreManager.h"

#include "Marathon/Player/Gauge/SonicGauge.h"
#include "Marathon/Player/Gauge/GaugeStandard.h"
#include "Marathon/Player/State/Machine2.h"


#include "Marathon/Player/State/CommonObject.h"
#include "Marathon/Player/State/BasedObject.h"
#include "Marathon/Sox/Object.h"
#include "Marathon/Sox/Component.h"


#include "Marathon/DocMarathonImp.h"

#include "Marathon/Player/Input/ListenerNormal.h"

#include "Marathon/MainMenuTask.h"

#include "Marathon/Player/Effect/IParticle.h"

//#include "Marathon/MyPhysicsSystemFactory.h"




#include <boost/bind.hpp>
#include <boost/function.hpp>

#include "Marathon/Player/PhantomEnterListener.h"


#define  HK_CONFIG_SIMD HK_CONFIG_SIMD_DISABLED
//#include <Common/Base/hkBase.h>





//#include <Xboxmath.h>
//# 

#include <string>

extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}



#include "ZLua.h"




#define __ROL4__(x, y) _rotl64(x, y)       // Rotate left
#define __ROR4__(x, y) _rotr64(x, y)       // Rotate right
#define _QWORD unsigned long long





class ZLua
{
public:
	std::string FilePath;
	lua_State* L;
	bool executed;
	bool locked;




	void OpenLua();
	void UseBaseLibs();
	void DoFile(bool);
	void CallFunction();

	const char* ZLua::GetGlobalString(const char* string);
	 bool GetGlobalBool(const char* string);
	int ZLua::GetGlobalInt(const char* string);

	static void UseBaseLibsEx(lua_State* L);


	ZLua(void);
	ZLua(const char*);
	~ZLua(void);
};








#define DataPointer(type, name, address) \
	static type &name = *(type *)address

// Function pointer declarations.
#define FunctionPointer(RETURN_TYPE, NAME, ARGS, ADDRESS) \
	static RETURN_TYPE (__cdecl *const NAME)ARGS = (RETURN_TYPE (__cdecl *)ARGS)ADDRESS
#define StdcallFunctionPointer(RETURN_TYPE, NAME, ARGS, ADDRESS) \
	static RETURN_TYPE (__stdcall *const NAME)ARGS = (RETURN_TYPE (__stdcall *)ARGS)ADDRESS
#define FastcallFunctionPointer(RETURN_TYPE, NAME, ARGS, ADDRESS) \
	static RETURN_TYPE (__fastcall *const NAME)ARGS = (RETURN_TYPE (__fastcall *)ARGS)ADDRESS
#define ThiscallFunctionPointer(RETURN_TYPE, NAME, ARGS, ADDRESS) \
	static RETURN_TYPE (__thiscall *const NAME)ARGS = (RETURN_TYPE (__thiscall *)ARGS)ADDRESS
#define VoidFunc(NAME, ADDRESS) FunctionPointer(void,NAME,(void),ADDRESS)



#define FUNCTION_PTR(returnType, callingConvention, function, location, ...) \
	static returnType (callingConvention *function)(__VA_ARGS__) = (returnType(callingConvention*)(__VA_ARGS__))(location) \





#define FUNCTION_PTRN(returnType, callingConvention, function, location, ...) \
returnType callingConvention function(__VA_ARGS__)\
{\
return ((returnType (callingConvention *)(__VA_ARGS__))location)(__VA_ARGS__))\
}\





#define MakeState(NM,TP) \
	boost::shared_ptr<TP>& NM(boost::shared_ptr<TP>& a1,int a2){ \
	\
	boost::shared_ptr<TP> x(new TP((Marathon::PlayerState::StateBaseValueP*)a2));\
	a1 = x;\
	return a1;\
}\


#define MakeStateI(NM,TP) \
	boost::shared_ptr<TP>& NM(boost::shared_ptr<TP>& a1,Sonicteam::Player::State::IMashine* a2){ \
	\
	boost::shared_ptr<TP> x(new TP(a2));\
	a1 = x;\
	return a1;\
}\



#define MakeStateS(TP) \
	boost::shared_ptr<TP>& TP##C(boost::shared_ptr<TP>& a1,int a2){ \
	\
	boost::shared_ptr<TP> x(new TP((Marathon::PlayerState::StateBaseValueP*)a2));\
	a1 = x;\
	return a1;\
}\




#define FD(NM) \
	(int)(NM##C) \





void ShowXenonMessage(LPCWSTR Title,LPCWSTR wTitle);

wchar_t *convertCharArrayToLPCWSTR(const char* charArray);
void ShowXenonMessage(LPCWSTR Title,char* wTitle);
void ShowXenonMessage(LPCWSTR Title,const char* wTitle);



void ShowXenonMessage(LPCWSTR Title,int value,char*);



void ShowXenonMessage(LPCWSTR Title,float value,char*);



template <typename T>
void PushXenonMessage(LPCWSTR Title,T value);

template <typename T>
static void PushXenonMessage(LPCWSTR Title,T value,MESSAGEBOX_RESULT* oute);



//template <typename T>
//void ShowXenonMessage(LPCWSTR Title,T value);



//Contains Original06 Function

#include "Basics.inl"  // Include the .inl file here\

#endif

