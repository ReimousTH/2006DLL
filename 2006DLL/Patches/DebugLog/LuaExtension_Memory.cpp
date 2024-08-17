#include "LuaExtension_Memory.h"

namespace DebugLogV2{

	


	


	static const struct luaL_reg MEM [] = {
		{"ADD",Memory_ADD},
		{"GetPointer", Memory_GetPointer},
		{"SetPointerValue", Memory_SetPointerValue},
		{"SetBYTE", Memory_SetBYTE},
		{"GetBYTE", Memory_GetBYTE},
		{"SetDWORD", Memory_SetDWORD},
		{"GetDWORD", Memory_GetDWORD},
		{"SetFLOAT", Memory_SetFLOAT},
		{"GetFLOAT", Memory_GetFLOAT},
		{NULL, NULL}  /* sentinel */
	};



	const char* memoryScript = "\
							   Memory = { ptr = nil } \n\
							   \n\
							   function Memory:new(o) \n\
							   o = o or {} \n\
							   setmetatable(o, self) \n\
							   self.__index = self \n\
							   return o \n\
							   end \n\
							   \n\
							   function Memory:getPtr() \n\
							   return self.ptr \n\
							   end \n\
							   ";

	int MemoryLIB_GlobalInstall(lua_State* L)
	{
		luaL_openlib06(L,"memory",MEM,0);




		luaL_newmetatable06(L, "MemoryMeta");
		lua_pushstring06(L,"__index"); lua_pushvalue(L,-2); lua_settable06(L,-3); // __index = MemoryMeta
		lua_pushstring06(L,"ptr"); lua_pushlightuserdata(L,(void*)0); lua_settable06(L,-3); // __index = MemoryMeta


		lua_pushstring06(L, "__eq"); lua_pushcfunction06(L, Memory__eq); 	lua_settable06(L, -3);
		lua_pushstring06(L, "__neq"); lua_pushcfunction06(L, Memory__neq); 	lua_settable06(L, -3);
		lua_pushstring06(L, "__add"); lua_pushcfunction06(L, Memory__add); 	lua_settable06(L, -3);

		lua_pushstring06(L, "Move"); lua_pushcfunction06(L, Memory__Move); 	lua_settable06(L, -3);
		lua_pushstring06(L, "FMove"); lua_pushcfunction06(L, Memory__FMove); 	lua_settable06(L, -3);

		//later
		lua_pushstring06(L, "AND"); lua_pushcfunction06(L, Memory__AND); 	lua_settable06(L, -3);
		lua_pushstring06(L, "OR"); lua_pushcfunction06(L, Memory__OR); 	lua_settable06(L, -3);
		lua_pushstring06(L, "SBR"); lua_pushcfunction06(L, Memory__SBR); 	lua_settable06(L, -3);
		lua_pushstring06(L, "SBL"); lua_pushcfunction06(L, Memory__SBL); 	lua_settable06(L, -3);


		lua_pushstring06(L, "GetFLOAT"); lua_pushcfunction06(L, Memory__GetFLOAT); 	lua_settable06(L, -3);
		lua_pushstring06(L, "GetBYTE"); lua_pushcfunction06(L, Memory__GetBYTE); 	lua_settable06(L, -3);
		lua_pushstring06(L, "GetPointer"); lua_pushcfunction06(L, Memory__GetPointer); 	lua_settable06(L, -3);
		lua_pushstring06(L, "GetDWORD"); lua_pushcfunction06(L, Memory__GetDWORD); 	lua_settable06(L, -3);

		lua_pushstring06(L, "SetDWORD"); lua_pushcfunction06(L, Memory__SetDWORD); 	lua_settable06(L, -3);
		lua_pushstring06(L, "SetFLOAT"); lua_pushcfunction06(L, Memory__SetFLOAT); 	lua_settable06(L, -3);
		lua_pushstring06(L, "SetBYTE"); lua_pushcfunction06(L, Memory__SetBYTE); 	lua_settable06(L, -3);
		lua_pushstring06(L, "SetPointer"); lua_pushcfunction06(L, Memory__SetPointer); 	lua_settable06(L, -3);
		lua_pushstring06(L, "IsValidPTR"); lua_pushcfunction06(L, Memory__IsValidPTR); 	lua_settable06(L, -3);

		lua_pushstring06(L, "GetPTR"); lua_pushcfunction06(L, Memory__GetPTR); 	lua_settable06(L, -3);
		lua_pushstring06(L, "GetClassName"); lua_pushcfunction06(L, Memory__GetClassName); 	lua_settable06(L, -3);

		





		lua_pop(L,1);

		lua_register06(L,"Memory",Memory__NEW);


	
		







		return 0;
	}

	extern "C" Memory__CreateMetatableFields(lua_State* L,int value,int move){

		lua_pushstring06(L,"ptr");
		lua_pushlightuserdata(L,(void*)value);
		lua_settable06(L,-3);


		// required for save check
		lua_pushstring06(L,"move");
		lua_pushlightuserdata(L,(void*)move);
		lua_settable06(L,-3);
		return 0;
	}
	extern "C" Memory__CreateMetatable(lua_State* L,int value,int move){

		lua_newtable06(L); // Create a new table for the instance // local self = {}

		// Second table for metatable set
	//	lua_newtable06(L);
	//	lua_pushstring06(L, "__index");luaL_getmetatable06(L, "MemoryMeta");lua_settable06(L, -3); // { __index = MemoryMeta }
	//	lua_setmetatable06(L, -2); // setmetatable(self, { __index = MemoryMeta })

		luaL_getmetatable06(L, "MemoryMeta");
		lua_setmetatable06(L, -2); // setmetatable(self, { __index = MemoryMeta })


	    lua_pushstring06(L, "ptr");lua_pushlightuserdata(L, (void*)value);lua_settable06(L, -3); // self.ptr = ptr
		lua_pushstring06(L, "move");lua_pushlightuserdata(L, (void*)move);lua_settable06(L, -3); // self.move = move

	

		return 1; // Return the new table

	}
	extern "C" Memory__NEW(lua_State* L){

		int value = 0;
		if (lua_isuserdata(L,1)){
			value = (int)lua_touserdata(L,1);
		}
		else if (lua_isnumber(L,1)){
			value = lua_tonumber(L,1);
		}
		else if (lua_isstring(L,1)){

			const char* s = lua_tostring(L,1);
			const TCHAR* hexString = _T(s); // Hex string to convert
			value = _tcstoul(hexString, NULL, 16); // Convert hex string to unsigned long integer
		}
		else{
			value = lua_tonumber(L,1);
		}


		Memory__CreateMetatable(L,value,0);



		return 1;

	}


	extern "C" int Memory__FMove(lua_State* L)
	{
		lua_pushstring(L,"ptr");
		lua_gettable(L,1);
		int ptr =  (int)lua_touserdata(L,-1);

		lua_pushstring(L,"move");
		lua_gettable(L,1);
		int move =  (int)lua_touserdata(L,-1);



		if (lua_isuserdata(L,2)){
			move += (int)lua_touserdata(L,2);
		}
		else if (lua_isnumber(L,2)){
			move += lua_tonumber(L,2);
		}
		else if (lua_isstring(L,2)){

			const char* s = lua_tostring(L,2);
			const TCHAR* hexString = _T(s); // Hex string to convert
			move += _tcstoul(hexString, NULL, 16); // Convert hex string to unsigned long integer
		}
		else{
			move += lua_tonumber(L,2);
		}


		Memory__CreateMetatable(L,ptr+ move,0);



		return 1;
	}

	extern "C" Memory__eq(lua_State* L){

		lua_pushstring06(L,"ptr");lua_gettable(L,1);unsigned int V1 = (unsigned int)lua_touserdata(L,-1);
		lua_pushstring06(L,"ptr");lua_gettable(L,2);unsigned int V2 = (unsigned int)lua_touserdata(L,-1);

		bool result = false;
		if (V1 == V2){
			result = true;
		}

		lua_pushboolean(L,result);
		return 1;
	

	}

	extern "C" Memory__neq(lua_State* L)
	{
		lua_pushstring06(L,"ptr");lua_gettable(L,1);unsigned int V1 = (unsigned int)lua_touserdata(L,-1);
		lua_pushstring06(L,"ptr");lua_gettable(L,2);unsigned int V2 = (unsigned int)lua_touserdata(L,-1);

		bool result = false;
		if (V1 != V2){
			result = true;
		}

		lua_pushboolean(L,result);
		return 1;
	}

	extern "C" int GetPointerOrHeximalArgument(lua_State* L,int arg){


		int emove = 0;
		if (lua_isuserdata(L,arg)){
			emove = (int)lua_touserdata(L,arg);
		}
		else if (lua_isnumber(L,arg)){
			emove = lua_tonumber(L,arg);
		}
		else if (lua_isstring(L,arg)){

			const char* s = lua_tostring(L,arg);
			const TCHAR* hexString = _T(s); // Hex string to convert
			emove = _tcstoul(hexString, NULL, 16); // Convert hex string to unsigned long integer
		}
		else{
			emove = lua_tonumber(L,2);
		}

		return emove;


	}


	extern "C" int Memory__OR(lua_State* L)
	{
		lua_pushstring(L,"ptr");
		lua_gettable(L,1);
		int ptr =  (int)lua_touserdata(L,-1);

		lua_pushstring(L,"move");
		lua_gettable(L,1);
		int move =  (int)lua_touserdata(L,-1);
		int emove =  (int)lua_touserdata(L,-1);



		if (lua_isuserdata(L,2)){
			emove = (int)lua_touserdata(L,2);
		}
		else if (lua_isnumber(L,2)){
			emove = lua_tonumber(L,2);
		}
		else if (lua_isstring(L,2)){

			const char* s = lua_tostring(L,2);
			const TCHAR* hexString = _T(s); // Hex string to convert
			emove = _tcstoul(hexString, NULL, 16); // Convert hex string to unsigned long integer
		}
		else{
			emove = lua_tonumber(L,2);
		}


		Memory__CreateMetatable(L,ptr | emove,move);



		return 1;
	}

	extern "C" int Memory__AND(lua_State* L)
	{
		lua_pushstring(L,"ptr");lua_gettable(L,1);
		int ptr =  (int)lua_touserdata(L,-1);

		lua_pushstring(L,"move");lua_gettable(L,1);
		int move =  (int)lua_touserdata(L,-1);
		int emove =  (int)GetPointerOrHeximalArgument(L,2);

		Memory__CreateMetatable(L,ptr & emove,move);
		return 1;
	}

	extern "C" int Memory__add(lua_State* L)
	{

		lua_pushstring(L,"ptr");lua_gettable(L,1);unsigned int ptr1 = (unsigned int)lua_touserdata(L,-1);
		lua_pushstring(L,"move");lua_gettable(L,1);unsigned int move1 = (unsigned int)lua_touserdata(L,-1);

		lua_pushstring(L,"ptr");lua_gettable(L,2);unsigned int ptr2 = (unsigned int)lua_touserdata(L,-1);
		lua_pushstring(L,"move");lua_gettable(L,2);unsigned int move2 = (unsigned int)lua_touserdata(L,-1);

		Memory__CreateMetatable(L,ptr1+ptr2,move1+move2);


		return 1;
	}

	extern "C" int Memory__SBL(lua_State* L)
	{
		lua_pushstring(L,"ptr");lua_gettable(L,1);
		int ptr =  (int)lua_touserdata(L,-1);

		lua_pushstring(L,"move");lua_gettable(L,1);
		int move =  (int)lua_touserdata(L,-1);
		int emove =  (int)GetPointerOrHeximalArgument(L,2);

		Memory__CreateMetatable(L,ptr << emove,move);



		return 1;	
	}

	extern "C" int Memory__SBR(lua_State* L)
	{
		lua_pushstring(L,"ptr");lua_gettable(L,1);
		int ptr =  (int)lua_touserdata(L,-1);

		lua_pushstring(L,"move");lua_gettable(L,1);
		int move =  (int)lua_touserdata(L,-1);
		int emove =  (int)GetPointerOrHeximalArgument(L,2);

		Memory__CreateMetatable(L,ptr >> emove,move);
		return 1;
	}

	
	extern "C" Memory__Move(lua_State* L){

		lua_pushstring06(L,"ptr");
		lua_gettable(L,1);
		int ptr =  (int)lua_touserdata(L,-1);

		lua_pushstring06(L,"move");
		lua_gettable(L,1);
		int move =  (int)lua_touserdata(L,-1);



		if (lua_isuserdata(L,2)){
			move += (int)lua_touserdata(L,2);
		}
		else if (lua_isnumber(L,2)){
			move += lua_tonumber(L,2);
		}
		else if (lua_isstring(L,2)){

			const char* s = lua_tostring(L,2);
			const TCHAR* hexString = _T(s); // Hex string to convert
			move += _tcstoul(hexString, NULL, 16); // Convert hex string to unsigned long integer
		}
		else{
			move += lua_tonumber(L,2);
		}
		

		Memory__CreateMetatable(L,ptr,move);
	


		return 1;


	}

	extern "C" Memory__SET(lua_State* L,int type){

		int args = lua_gettop(L);

		lua_pushstring06(L,"ptr");
		lua_gettable(L,1);
		int ptr =  (int)lua_touserdata(L,-1);


		lua_pushstring06(L,"move");
		lua_gettable(L,1);
		int move =  (int)lua_touserdata(L,-1);

	

		unsigned int value = 0;
		int arg_value_num = 2;

		if (args > 2){

			if (lua_isuserdata(L,2)){
				move += (int)lua_touserdata(L,2);
			}
			else if (lua_isnumber(L,2)){
				move += lua_tonumber(L,2);
			}
			else if (lua_isstring(L,2)){

				const char* s = lua_tostring(L,2);
				const TCHAR* hexString = _T(s); // Hex string to convert
				move += _tcstoul(hexString, NULL, 16); // Convert hex string to unsigned long integer
			}
			else{
				move += lua_tonumber(L,2);
			}

			arg_value_num = 3;
		}


		if (lua_isuserdata(L,arg_value_num)){
			value = (unsigned int)lua_touserdata(L,arg_value_num);
		}
		//
		else if (lua_isnumber(L,arg_value_num)){
			if (type == 1){
				float hvalue = (float)lua_tonumber(L,arg_value_num);
				value = *(unsigned int*)&hvalue;
			}
			else{
					value = (unsigned int)lua_tonumber(L,arg_value_num);
			}
		}
		
	
			switch (type){
				//DWORD 
			case  0: 
			case  1:
			case  3:
				*(unsigned int*)(ptr + move) = value;
				break;
			case  2:
				*(char*)(ptr + move) = value;

			}



	
		return 0;
	}
	extern "C" Memory__SetDWORD(lua_State* L){

		return Memory__SET(L,0);

	}

	extern "C" Memory__SetFLOAT(lua_State* L){

		return Memory__SET(L,1);

	}

	extern "C" Memory__SetBYTE(lua_State* L){

		return Memory__SET(L,2);

	}
	extern "C" Memory__SetPointer(lua_State* L){

		return Memory__SET(L,3);

	}




	extern int "C" Memory__GET(lua_State* L, int type){

		int args = lua_gettop(L);
		lua_pushstring06(L,"ptr");
		lua_gettable(L,1);
		int ptr =  (int)lua_touserdata(L,-1);

		lua_pushstring06(L,"move");
		lua_gettable(L,1);
		int move =  (int)lua_touserdata(L,-1);


		if (args > 1) {

			if (lua_isuserdata(L,2)){
				move += (int)lua_touserdata(L,2);
			}
			else if (lua_isnumber(L,2)){
				move += lua_tonumber(L,2);
			}
			else if (lua_isstring(L,2)){

				const char* s = lua_tostring(L,2);
				const TCHAR* hexString = _T(s); // Hex string to convert
				move += _tcstoul(hexString, NULL, 16); // Convert hex string to unsigned long integer
			}
			else{
				move += lua_tonumber(L,2);
			}
		}
		


	
			switch (type){
				//DWORD 
			case  0 : 
				lua_pushnumber(L,*(unsigned int*)(ptr + move));
				break;
				//FLOAT
			case  1:
				lua_pushnumber(L,*(float*)(ptr + move));
				break;
				//BYTE
			case  2:
				lua_pushnumber(L,*(char*)(ptr + move));
				break;
				//pointer
			case  3:
				Memory__CreateMetatable(L,*(unsigned int*)(ptr + move),0);
				break;
			case 4:
			
				lua_pushstring06(L,"");
				break;

			}
	


		return 1;
	}


	extern "C" int Memory__GetDWORD(lua_State* L){

		return Memory__GET(L,0);

	}
	extern "C" int Memory__GetFLOAT(lua_State* L){

		return Memory__GET(L,1);

	}
	extern "C" int Memory__GetBYTE(lua_State* L){

		return Memory__GET(L,2);

	}
	extern "C" int Memory__GetPointer(lua_State* L){

		return Memory__GET(L,3);

	}


	extern "C" int Memory__GetClassName(lua_State* L)
	{
		return Memory__GET(L,4);
	}









	
	
	extern "C" int Memory__GetPTR(lua_State* L)
	{

		lua_pushstring06(L,"ptr");
		lua_gettable(L,1);
		return 1;
	}

	
	extern "C" int Memory__IsValidPTR(lua_State* L)
	{

		lua_pushstring06(L,"ptr");
		lua_gettable(L,1);
		unsigned int ptr =  (unsigned int)lua_touserdata(L,-1);


		//Save Check
		if (ptr > 0x40000000){

			lua_pushboolean(L,true);
		}
		else{
			lua_pushboolean(L,false);
		}



		return 1;

	}

	extern "C" Memory_GetBYTE(lua_State* L){

		int args = lua_gettop(L);
		UINT ptr = 0;
		UINT mv = 0; 

		if (args < 1){ lua_pushnil(L); return 1;}

		if (lua_isuserdata(L,1)){
			ptr = (UINT)lua_touserdata(L,1);
		}

		else{
			ptr = (UINT)lua_tonumber(L,1);
		}

		if (args > 1){
			mv = (UINT)lua_tonumber(L,2);
		}

	
		if ((ptr + mv) > mv && (ptr + mv) != 0 ){
			lua_pushnumber(L,*(char*)(ptr + mv));
		}
		else{
			lua_pushnil(L);
		}
		return 1;
	}
	extern "C" Memory_SetBYTE(lua_State* L){

		int args = lua_gettop(L);
		UINT ptr = 0;
		if (args < 2) return 0;

		if (lua_isuserdata(L,1)){
			ptr = (UINT)lua_touserdata(L,1);
		}
		else{
			ptr = lua_tonumber(L,1);
		}

		*(char*)(ptr) =  lua_tonumber(L,2);

		return 0;
	}

	extern "C" Memory_GetDWORD(lua_State* L){

		int args = lua_gettop(L);
		UINT ptr = 0;
		UINT mv = 0; 

		if (args < 1){ lua_pushnil(L); return 1;}

		if (lua_isuserdata(L,1)){
			ptr = (UINT)lua_touserdata(L,1);
		}

		else{
			ptr = (UINT)lua_tonumber(L,1);
		}

		if (args > 1){
			mv = (UINT)lua_tonumber(L,2);
		}

		if ((ptr + mv) > mv && (ptr + mv) != 0 ){
			lua_pushnumber(L,*(int*)(ptr + mv));
		}
		else{
			lua_pushnil(L);
		}
		return 1;
	}
	extern "C" Memory_SetDWORD(lua_State* L){

		int args = lua_gettop(L);
		UINT ptr = 0;
		if (args < 2) return 0;

		if (lua_isuserdata(L,1)){
			ptr = (UINT)lua_touserdata(L,1);
		}
		else{
			ptr = lua_tonumber(L,1);
		}

		*(unsigned int*)(ptr) =  lua_tonumber(L,2);
		
	
		return 0;
	}
	extern "C" Memory_GetFLOAT(lua_State* L){

		int args = lua_gettop(L);
		UINT ptr = 0;
		UINT mv = 0; 

		if (args < 1){ lua_pushnil(L); return 1;}

		if (lua_isuserdata(L,1)){
			ptr = (UINT)lua_touserdata(L,1);
		}

		else{
			ptr = (UINT)lua_tonumber(L,1);
		}

		if (args > 1){
			mv = (UINT)lua_tonumber(L,2);
		}



		void* result_ptr = 0;
		if ((ptr + mv) > mv && (ptr + mv) != 0 ){
			result_ptr = *(void**)(ptr + mv);
		}

		if ((ptr + mv) > mv && (ptr + mv) != 0 ){
			lua_pushnumber(L,*(float*)(ptr + mv));
		}
		else{
			lua_pushnil(L);
		}
		return 1;
	}
	extern "C" Memory_SetFLOAT(lua_State* L){

		int args = lua_gettop(L);
		UINT ptr = 0;
		if (args < 2) return 0;

		if (lua_isuserdata(L,1)){
			ptr = (UINT)lua_touserdata(L,1);
		}
		else{
			ptr = lua_tonumber(L,1);
		}
		*(float*)(ptr) =  lua_tonumber(L,2);
		return 0;
	}




	extern "C" Memory_GetPointer(lua_State* L){

		int args = lua_gettop(L);
		UINT ptr = 0;
		UINT mv = 0; 

		if (args < 1){ lua_pushnil(L); return 1;}

		if (lua_isuserdata(L,1)){
			ptr = (UINT)lua_touserdata(L,1);
		}
	
		else{
			ptr = (UINT)lua_tonumber(L,1);
		}
		
		if (args > 1){
			mv = (UINT)lua_tonumber(L,2);
		}
		


		void* result_ptr = 0;
		if ((ptr + mv) > mv && (ptr + mv) != 0 ){
			result_ptr = *(void**)(ptr + mv);
		}
		
		if ((ptr + mv) > mv && (ptr + mv) != 0 ){
			lua_pushlightuserdata(L,*(void**)(ptr + mv));
		}
		else{
			lua_pushnil(L);
		}
		return 1;
	}
	extern "C" Memory_ADD(lua_State* L){

		int args = lua_gettop(L);
		UINT ptr = 0;
		UINT mv = 0; 

		if (args < 2){ lua_pushnil(L); return 1;}

		if (lua_isuserdata(L,1)){
			ptr = (UINT)lua_touserdata(L,1);
		}

		else{
			ptr = (UINT)lua_tonumber(L,1);
		}

		if (lua_isuserdata(L,2)){
			mv = (UINT)lua_touserdata(L,2);
		}

		else{
			mv = (UINT)lua_tonumber(L,2);
		}

		lua_pushlightuserdata(L,(void*)(ptr+mv));


		return 1;
	}
	extern "C" Memory_SetPointerValue(lua_State* L){



		int args = lua_gettop(L);
		UINT ptr = 0;
		UINT mv = 0; 





		if (args < 2){ lua_pushnil(L); return 1;}

		if (lua_isuserdata(L,1)){
			ptr = (UINT)lua_touserdata(L,1);
		}

		else{
			ptr = (UINT)lua_tonumber(L,1);
		}

		if (lua_isuserdata(L,2)){
			mv = (UINT)lua_touserdata(L,2);
		}

		else{
			mv = (UINT)lua_tonumber(L,2);
		}

		*(UINT*)ptr = mv;


		return 0;
	}





}