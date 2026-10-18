#include <iostream>

using namespace std;

class Queue {
    private:
        int arr[5];
        int front;
        int rear;
        int count; 
        int capacity;
    
    public:
        Queue() {
            front = 0;
            rear = -1;
            count = 0;
            capacity = 5;
        }
        
////////////////////////////////////////////////////////////////////////////////////////        
        void Equeue(int value) {
            if (count == capacity) {
                cout << "Queue Overflow! Cannot enqueue " << value << endl;
                return;
            }
           
            rear = (rear + 1) % capacity;
            arr[rear] = value;
            count++;
        }
        
////////////////////////////////////////////////////////////////////////////////////////        
        void Dequeue() {
            if (count == 0) {
                cout << "Queue Underflow! Cannot dequeue." << endl;
                return;
            }
            
            front = (front + 1) % capacity;
            count--;
        }
  
////////////////////////////////////////////////////////////////////////////////////////
        int Peek() {
            if (count == 0) {
                cout << "Queue is empty! ";
                return -1;
            }
            return arr[front];
        }


////////////////////////////////////////////////////////////////////////////////////////
        bool isEmpty() {
            return count == 0;
        }
};

int main() {
    Queue* q = new Queue();
    
   
    q->Equeue(1);
    q->Equeue(2);
    q->Equeue(3);
    q->Equeue(4);
    q->Equeue(5);
    q->Equeue(6); 
    
    
    while (!q->isEmpty()) {
        cout << q->Peek() << endl;
        q->Dequeue();
    }
    
    q->Equeue(1);
    q->Equeue(2);
    q->Equeue(3);
    q->Equeue(4);
    q->Equeue(5);
    q->Equeue(6); 
    
    
    while (!q->isEmpty()) {
        cout << q->Peek() << endl;
        q->Dequeue();
    }
    
    delete[] q;
    return 0;
}

