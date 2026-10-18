#include <iostream>
using namespace::std;

#define MAX 5 

class Stack {
private:
    int top;
    int arr[MAX]; // Array to store stack elements

public:
    // Constructor to initialize top
    Stack() {
        top = -1; 
    }

    // Check if the stack is full
    bool isFull() {
        return (top == MAX - 1);
    }

    // Check if the stack is empty
    bool isEmpty() {
        return (top == -1);
    }

    // Add an element to the top of the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << ".\n";
            return;
        }
        arr[++top] = value;
        cout << value << " pushed into the stack.\n";
    }

    // Remove and return the top element
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop from an empty stack.\n";
            return -1; // Return a sentinel value indicating error
        }
        int poppedValue = arr[top--];
        return poppedValue;
    }

    // Display the top element without removing it
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty. No top element.\n";
            return -1;
        }
        return arr[top];
    }

    // Display all elements of the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    // Create an object of the Stack class
    Stack myStack;

    // Test isEmpty on an empty stack
    cout << "Is stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << "\n\n";

    // Test push operations
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);
    
    // Test stack overflow
    myStack.push(60); 

    // Display stack elements
    myStack.display();

    // Test peek operation
    cout << "Top element (peek): " << myStack.peek() << "\n\n";

    // Test pop operations
    cout << myStack.pop() << " popped from stack.\n";
    cout << myStack.pop() << " popped from stack.\n";

    // Display stack after popping
    myStack.display();

    // Check if full
    cout << "Is stack full? " << (myStack.isFull() ? "Yes" : "No") << "\n";

    return 0;
}

