

#include "PropClass.h"
#include "SceneObject.h"
#include <xtl.h>


#ifndef Sonicteam_Prop_Instance
#define Sonicteam_Prop_Instance


namespace Sonicteam { namespace Prop {


	//from DebugLogV2 
	struct InstanceSetDataParams{
	public:
		int Type;
		union {
			unsigned int _bool_;          // 0
			int _int32_;          // 1
			float _single_;       // 2
			const char* _string_; // 3
			XMVECTOR _vector_;    // 4
			int _u5_;             // 5
			int _u6_;             // 6
		} Value;

		void SetTValue(bool value);
		void SetTValue(int value);
		void SetTValue(float value);
		void SetTValue(const char* value);
		void SetTValue(XMVECTOR value);

		//Getters, no template or .inl :)


	};

	struct InstanceSetData{

		const char* ObjectName;
		const char* ObjectTypeName;


		char ObjectUnkFloatArray[3]; // 40 00 00
		char StartInactive; //0

		float ObjectUnkFloat2; //=0
		float ObjectUnkFloat3; //=0
		float ObjectUnkFloat4; //=0
		XMFLOAT3 Position;
		float ObjectUnkFloat5; //40000
		XMFLOAT4 Rotation;

		unsigned int ParamsCount;

		InstanceSetDataParams* Params;
	};




	class Instance:Sonicteam::Prop::SceneObject{


	public:
		Instance();
		~Instance();

		virtual void DestroyObject(unsigned int flag) override;

		Sonicteam::Prop::InstanceSetData* InstanceSetData;
		Sonicteam::Prop::Class* InstanceClass;



	};

}}


#endif


