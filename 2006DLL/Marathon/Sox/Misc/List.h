#pragma  once


namespace Sonicteam{
	namespace SoX{

		
/*
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
		*/


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

		template <typename T>
		class BaseNode {
		public:
			BaseNode<T>* Previous;
			BaseNode<T>* Next;
			T* Object;

			BaseNode() : Previous(0), Next(0), Object(0) {}

			BaseNode(const T& OBJ) : Object(new T(OBJ)), Previous(0), Next(0) {}

			~BaseNode() {
				Clear();
			}

			void Clear() {
				if (Previous) Previous->Next = Next;
				if (Next) Next->Previous = Previous;
				this->Object = 0;
			}
		};


		template <typename T,typename Y>
		struct NodeB:public BaseNode<T> {
			Y* HeadObject;

			Node(){}
			NodeB(const T& OBJ,const Y& HOBJ) : Object(OBJ),HeadObject(HOBJ),Previous(NULL),Next(NULL) {}
			~NodeB(){
				Clear();
			}
			void Clear(){
				BaseNode<T>::Clear();
				this->HeadObject = 0;
			}
		};


		template <typename T,typename Y>
		class LinkedListB {
		private:
			NodeB<T,Y>* head;
			NodeB<T,Y>* front;

		public:
			LinkedListB() : head(0),front(0) {};

			// Destructor to free memory when the list is destroyed
			~LinkedListB() {
				while (head != front) {
					NodeB<T,Y>* temp = head;
					head = (NodeB<T,Y>*)head->Next;
					temp->Clear();

				}
			};
		};
	};
}




//NEW ONE

