#include<iostream>

using namespace::std;

class Queue {
	private:
		int array[5];
		int rear;
		int count;
	public:
		
		Queue() {
			rear = -1;
			count = 0;
		}
		
		int enqueue(int val) {
			if(rear >= 4) {
				cout << "Array is full! Queue overflow." << endl;
				return -1;
			}
			
			array[++rear] = val;
			return array[rear];
		
		}
		
		void dequeue() {
			if(rear < 0) {
				cout << "Array is empty! Queue underflow."<< endl;
				return;
			}
			
			array[count - (rear + 1)];
			count--;
			array[count - rear] = array[(count + 1) - rear];
			rear--;
			
		}
		
		bool isEmpty() {
			return count == 0;
		}
};

int main() {
	Queue* q = new Queue();
	
	for(int i = 0; i < 6; i++){
		cout << q->enqueue(i+1) << endl;
	}
	
	
	while(!q->isEmpty()){
		q->dequeue();
	}
		
	
	delete[] q;
	
	return 0;
}


