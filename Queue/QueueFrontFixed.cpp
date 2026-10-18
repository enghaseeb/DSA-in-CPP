#include <iostream>
using namespace std;



class Queue {
private:
    float arr[10];
    int rear;   
    const int front = 0;

public:
    Queue() {
        rear = -1;
    }

    bool isFull() {
        return rear == 9;
    }

    bool isEmpty() {
        return rear == -1;
    }

    void enqueue(float x) {
        if (isFull()) {
            cout << "Overflow! Queue is full.\n";
            return;
        }
        
        arr[rear++] = x;
        cout << x << " enqueued. front = " << front << ", rear = " << rear << "\n";
    }

    float dequeue() {
        if (isEmpty()) {
            cout << "Underflow! Queue is empty.\n";
            return -1;
        }
        float item = arr[front];          
        
        for (int i = 0; i < rear; i++) {
            arr[i] = arr[i + 1];
        }
        rear = rear - 1;  

        cout << item << " dequeued. front = " << front << ", rear = " << rear << "\n";
        return item;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue (front to rear): ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();  

    q.dequeue();   
    q.display();   

    q.enqueue(40);
    q.display();   

    return 0;
}
