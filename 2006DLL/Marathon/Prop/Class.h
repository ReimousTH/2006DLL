

#include "PropClass.h"
#include <Sox/RefCountObject.h>
#include <xtl.h>

#ifndef Sonicteam_Prop_Class
#define Sonicteam_Prop_Class



namespace Sonicteam { namespace Prop {





	struct ClassPropParamInfo{
	public:
		const char ParamName[0x10];
		unsigned int ParamType;
		unsigned int ParamFlag; // Unknown Param
	};


	struct ClassPropParamData{
	public:
		const char* ClassName;
		unsigned int ClassParamInfoCount;
		ClassPropParamInfo* ClassParamInfo; //array
	};


	class Class:Sonicteam::SoX::RefCountObject{

	public:
		virtual void DestroyObject(unsigned int flag) override;
		ClassPropParamData* ClassPropData; // 0x8
		Sonicteam::Prop::AllocatedData* ClassPropAllocatedData; //0xC

	};


}};

#endif

