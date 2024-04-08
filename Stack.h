 #include "LinkedList.h"


//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

//LinkedList class를 상속받음
template <class T>
class Stack : public LinkedList<T>{
	public:
		bool Delete (T &element){
			//first가 0이면 false반환
			 if (this->first == 0) {
            return false;
        }

			// LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제
				Node<T> *now = this->first; // 삭제할 노드
        element = now->data; // 삭제될 원소의 데이터를 element에 저장

				// first를 다음 노드로 이동시키고 현재 노드를 삭제
        this->first = this->first->link;
        delete now;
        this->current_size--; // 스택의 크기 감소

			return true;
			}
};

