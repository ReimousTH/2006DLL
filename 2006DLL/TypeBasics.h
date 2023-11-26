#pragma  once

#ifndef _MARATHON_USE_TYPEINFO
#include <typeinfo>
#define _MARATHON_USE_TYPEINFO

#endif

#ifndef _MARATHON_FORCE_COMPILE_TYPE
#define _MARATHON_FORCE_COMPILE_TYPE
#endif


//This allow to force compile class type_info for each selected class
#define  MFTCype(Name,Class) static std::type_info const &_##Name##_ = typeid(Class)
