#include<iostream>
using namespace std;

#define N 5

class Queue{
	private:
		int arr[N];
		int rear;
		int front;
	
	public:
		Queue(){
			front = rear = -1;
		}
		
		void enqueue(int val){
			if(rear == N-1){
				cout << "Queue Overflow! Cannot enqueue " << val << endl;
				return;
			}
			
			if(rear == -1)
				front = 0;
			
			arr[++rear] = val;
			cout << val << " is enqueued." << endl;
		}
		
		void dequeue(){
			if(isEmpty()){
				cout << "Queue Underflow!" << endl;
				return;
			}
			
			cout << arr[front] << " is dequeued." << endl;
			front++;
		}
		
		bool isEmpty(){
			return front > rear || rear == -1;
		}
		
		bool isFull(){
			return rear == N-1;
		}
		
		
		int Peek(){
			if(isEmpty()){
				cout << "Queue is empty! ";
				return -1;
			}
			return arr[front];
		}
		
		
		void Display(){
			if(isEmpty()){
				cout << "Queue is empty" << endl;
				return;
			}
			cout << "Queue elements: ";
			for(int i = front; i <= rear; i++){
				cout << arr[i] << " ";
			}
			cout << endl;
		}
};

int main(){
	Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	
	q.Display(); 
	
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6); 
	
	cout << "\nDequeuing all elements:\n";
	while(!q.isEmpty()){
		q.dequeue();
	}
	
	cout << "\nPeeking after emptying: " << q.Peek() << endl;
	
	return 0;
}

