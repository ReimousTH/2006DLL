#pragma once	


//Custom
namespace Sonicteam{
	namespace SoX{
		namespace Memory{
			class IDestructible {
			public:
				~IDestructible() {}
				virtual void DestroyObject(unsigned int flag) {
					if ((flag & 1) != 0) {
						delete this;
					}
				}
				template <typename T>
				static void DestroyObject(T& obj,unsigned int flag){
					if ((flag & 1) != 0) {
						delete obj;
					}
				}
			};

			static void boost_ptr_cleanup(IDestructible* obj){
				obj->DestroyObject(1);
			}



		}

	}
}




#ifndef _T1
#define _T1

#define DefineVirtualDestroyerH() virtual RefObjectDestroy(unsigned int flag)

#define DefineVirtualDestroyerCPP(ClassName) virtual RefObjectDestroy(unsigned int flag)\
	{\
	this->~#ClassName();\
		if ((flag & 1 ) != 0 ){\
	delete this;\
	}\


#endif
