#pragma once	


//Custom
namespace Sonicteam{
	namespace SoX{
		namespace Memory{
			class IDestructible {
			public:
				~IDestructible() {}
				virtual void DestroyObject (unsigned int flag) {
					if ((flag & 1) != 0) {
						delete this;
					}
				}
				template <typename T>
				inline static void DestroyObject(T& obj,unsigned int flag){
					if ((flag & 1) != 0) {
						delete obj;
					}
				}
			};

			class IUDestructible {
			public:
				~IUDestructible() {}
				template <typename T>
				inline static void DestroyObject(T& obj,unsigned int flag){
					if ((flag & 1) != 0) {
						delete obj;
					}
				}
			};

			template <typename T>
			class BoostDestructorHelper {
			public:
				void operator()(T* obj) const {
					if (obj) obj->DestroyObject(1);

				}
			};

		



			static void boost_ptr_cleanup(IDestructible* obj){
				obj->DestroyObject(1);
			}



		}

	}
}







