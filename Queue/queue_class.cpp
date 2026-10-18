#include<iostream>

using namespace::std;

class Queue{
	private:
		int arr[5];
		int front;
		int rear;
	
	public:
		Queue(){
			front = 0;
			rear = -1;
		}
		
		void Equeue(int value){
			if(rear >= 4){
				cout<<"Queue Overflow\n";
				return;
			}
			arr[++rear] = value;
		}
		
		void Dequeue(){
			if(front > rear || front == -1){
				cout<<"Queue Underflow\n";
				return;
			}
			front++;
		}
		
		int Peek(){
			if(front > rear){
				cout<<"Queue is empty\n";
				return -1;
			}
			return arr[front];
		}
		
		bool isEmpty() {
            return front > 4;
        }
};

int main(){
	Queue* q = new Queue();
	
	q->Equeue(1);
	q->Equeue(2);
	q->Equeue(3);
	q->Equeue(4);
	q->Equeue(5);
	q->Equeue(5);	
	
	while(!q->isEmpty()){
		cout<<q->Peek()<<endl;
	    q->Dequeue();
	}
	q->Dequeue();
	
	return 0;
}
