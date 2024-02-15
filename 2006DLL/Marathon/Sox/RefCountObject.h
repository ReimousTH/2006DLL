#pragma once				
#include <SoX/Memory/IDestructible.h>

namespace Sonicteam{
	namespace SoX{
		class RefCountObject:public Sonicteam::SoX::Memory::IDestructible
		{
		public:
			RefCountObject(void);
			//Fake 
			//virtual void ObjectDestroy(unsigned int flag);
			~RefCountObject(void);

			virtual void DestroyObject(unsigned int flag) override;

			//not sure, my custom for easier 
			template <typename T>
			T* GetObject();
			void LoseObject();

			unsigned int UnkReference;


			
		};

		template <typename T>
			T* Sonicteam::SoX::RefCountObject::GetObject()
		{
			this->UnkReference++;
			return (T*)this;
		}
	

	}
}
