#include "LuaExtension_Vector.h"

#define VectorLIBName "Vector"
#define VectorLIBMeta "VectorMeta"

namespace DebugLogV2{

	


	

	const char* VectorRLIBScript = """VectorMeta = { [1] = 0, [2] = 0, [3] = 0, [4] = 0, __index = VectorMeta } \
									 VectorMeta.__index = VectorMeta \
									 function Vector(x, y, z, w)                                               \
									 local self = {}                                                       \
									 setmetatable(self, VectorMeta)                                        \
									 self[1] = x                                                           \
									 self[2] = y                                                           \
									 self[3] = z                                                           \
									 self[4] = w                                                           \
									 return self                                                           \
									 end                                                                       \
									 \
									 function VectorMeta:__add(b)                                              \
									 local result = Vector(                                                \
									 self[1] + b[1],                                                   \
									 self[2] + b[2],                                                   \
									 self[3] + b[3],                                                   \
									 self[4] + b[4]                                                    \
									 )                                                                     \
									 return result                                                         \
									 end                                                                       \
									 \
									 \
									 function VectorMeta:__sub(b)                                              \
									 local result = Vector(                                                \
									 self[1] - b[1],                                                   \
									 self[2] - b[2],                                                   \
									 self[3] - b[3],                                                   \
									 self[4] - b[4]                                                    \
									 )                                                                     \
									 return result                                                         \
									 end                                                                       \
									 function VectorMeta:__tostring() \
									 return string.format(\"X:%.2f ,Y:%.2f, Z:Y:%.2f, W:%.2f\",self[1],self[2],self[3],self[4])\
									 end                                                                  """;

	int VectorRLIB_GlobalInstall(lua_State* L)
	{

	

		lua_dostring06(L,VectorRLIBScript);


		return 0;
	}






}