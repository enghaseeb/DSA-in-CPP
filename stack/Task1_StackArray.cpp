#include <iostream>
using namespace std;

class Stack {
private:
    int arr[10];   
    int top;      

public:
    Stack() {
        top = -1;
    }

    bool isFull() {
        return top == 9;   
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int item) {
        if (isFull()) {
            cout << "Overflow! Stack is full.\n";
            return;
        }
        top = top + 1;
        arr[top] = item;
        cout << item << " inserted.\n";
    }

    int pop() {
        if (isEmpty()) {
            cout << "Underflow! Stack is empty.\n";
            return -1;
        }
        int item = arr[top];
        top = top - 1;
        return item;
    }

    
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty. Top = " << top << "\n";
            return;
        }
        cout << "Top pointer is at index: " << top << "\n";
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    Stack s;
    s.push(2);
    s.push(5);
    s.push(7);
    s.push(1);

    s.display();  

    s.pop();
    s.display();   

    return 0;
}
