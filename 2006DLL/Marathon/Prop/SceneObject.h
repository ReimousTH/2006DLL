

#include <Sox/RefCountObject.h>
#include "PropClass.h"




#ifndef Sonicteam_Prop_SceneObject
#define Sonicteam_Prop_SceneObject


namespace Sonicteam { namespace Prop {



	class SceneObject:Sonicteam::SoX::RefCountObject{


	public:
		SceneObject();
		~SceneObject();

		virtual void DestroyObject(unsigned int flag) override;

		Sonicteam::Prop::Scene* PropScene;


	};

}}

#endif

