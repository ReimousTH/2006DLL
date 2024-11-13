#pragma once				
#include <SoX/Memory/IDestructible.h>

namespace Sonicteam{
	namespace SoX{


		

		typedef class RefCountObject;

		template <typename T>
		struct RefCountObjContainer {
			T* param;

		
			RefCountObjContainer(T* other) : param(other) {other->AddReference();}
			~RefCountObjContainer(){if (param) param->Release();}
			operator T*() { return param; }
			RefCountObjContainer& operator=(const RefCountObjContainer& other);

			RefCountObjContainer(const RefCountObjContainer& other);
			RefCountObjContainer(RefCountObjContainer& other):param(other.param){}
		};

		class RefCountObject {
		public:
			RefCountObject() : referenceCount(0) {}

			~RefCountObject() {}

			void AddReference();
			void Release();
			virtual void DestroyObject(unsigned int flag);

		

			//not sure, my custom for easier 
			template <typename T>
			T* GetObject();


		private:
			RefCountObject(const RefCountObject&);


		protected:
			unsigned int referenceCount;
		};

		template <typename T>
		T* Sonicteam::SoX::RefCountObject::GetObject()
		{
			this->AddReference();
			return (T*)this;
		}

	

	}
}
