#pragma  once
#include <iostream>

namespace Sonicteam{
	namespace SoX{
		template <typename T>
		struct FrameNode{
			T* Previous;
			T* Next;
			FrameNode(){}
			FrameNode(const T& P,const T& N):Previous(P),Next(N){}
			~FrameNode(){
				this->Previous->FUNodeA_2.Next = this->Next;
				this->Next->FUNodeA_2.Previous = this->Previous;
			}
		};

		template <typename T,typename Y>
		struct NodeB {

			NodeB<T,Y>* Previous;
			NodeB<T,Y>* Next;
			T* Object;
			Y* HeadObject;

			Node(){}
			NodeB(const T& OBJ,const Y& HOBJ) : Object(OBJ),HeadObject(HOBJ),Previous(NULL),Next(NULL) {}
			~NodeB(){
				//need finish
				this->Previous->Next = this->Next;
				this->Next->Previous = this->Previous;
				this->Object = 0;
				this->HeadObject = 0;


			}
		};

		//i just leave, mb will be used in future

/*
		template <typename T>
		class LinkedListA {
		private:
			NodeA<T>* head;
			NodeA<T>* front;
		public:
			LinkedListA(): head(NULL),front(NULL){}
		};


*/




		template <typename T,typename Y>
		class LinkedListB {
		private:
			NodeB<T,Y>* head;
			NodeB<T,Y>* front;

		public:
			LinkedListB() : head(0),front(0) {}

			// Destructor to free memory when the list is destroyed
			~LinkedListB() {
				while (head != front) {
					NodeB<T,Y>* temp = head;
					head = head->Next;
					temp->~NodeB();
				}
			}
		};

	};
};




//NEW ONE


