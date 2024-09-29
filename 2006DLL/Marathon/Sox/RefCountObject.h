#pragma once				
#include <SoX/Memory/IDestructible.h>

namespace Sonicteam{
	namespace SoX{


		class RefCountObject_OLD
		{
		public:
			RefCountObject_OLD(void);
			//Fake 
			//virtual void ObjectDestroy(unsigned int flag);
			~RefCountObject_OLD(void);

			virtual void DestroyObject(unsigned int flag);

			//not sure, my custom for easier 
			template <typename T>
			T* GetObject();
			void LoseObject();

			unsigned int UnkReference;




			
		};

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

			RefCountObject& operator=(const RefCountObject& other);

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
			return (T*)this;
		}






		template <typename T>
			T* Sonicteam::SoX::RefCountObject_OLD::GetObject()
		{
			this->UnkReference++;
			return (T*)this;
		}
	

	}
}
