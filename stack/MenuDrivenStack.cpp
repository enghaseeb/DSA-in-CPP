#include <iostream>
using namespace std;

const int MAX = 5; // Fixed size of the stack

class Stack {
private:
    int top;
    int arr[MAX];

public:
    Stack() {
        top = -1;
    }

    bool isFull() {
        return (top == MAX - 1);
    }

    bool isEmpty() {
        return (top == -1);
    }

    void push(int value) {
        if (isFull()) {
            cout << "\n[Error] Stack Overflow! Cannot push " << value << ".\n";
            return;
        }
        arr[++top] = value;
        cout << "\nSuccess: " << value << " pushed into the stack.\n";
    }

    int pop() {
        if (isEmpty()) {
            cout << "\n[Error] Stack Underflow! Cannot pop from an empty stack.\n";
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "\n[Notice] Stack is empty. No top element.\n";
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (isEmpty()) {
            cout << "\n[Notice] Stack is empty.\n";
            return;
        }
        cout << "\nStack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    Stack myStack;
    int choice, val;

    do {
        // Display Menu
        cout << "\n===== STACK MENU =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check Empty\n";
        cout << "6. Check Full\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Process Choice
        switch (choice) {
            case 1:
                cout << "Enter integer to push: ";
                cin >> val;
                myStack.push(val);
                break;

            case 2:
                val = myStack.pop();
                if (val != -1) {
                    cout << "\nSuccess: " << val << " popped from the stack.\n";
                }
                break;

            case 3:
                val = myStack.peek();
                if (val != -1) {
                    cout << "\nTop element is: " << val << "\n";
                }
                break;

            case 4:
                myStack.display();
                break;

            case 5:
                if (myStack.isEmpty()) {
                    cout << "\nYes, the stack is empty.\n";
                } else {
                    cout << "\nNo, the stack is not empty.\n";
                }
                break;

            case 6:
                if (myStack.isFull()) {
                    cout << "\nYes, the stack is full.\n";
                } else {
                    cout << "\nNo, the stack is not full.\n";
                }
                break;

            case 7:
                cout << "\nExiting program. Goodbye!\n";
                break;

            default:
                cout << "\n[Error] Invalid choice! Please enter a number between 1 and 7.\n";
        }
    } while (choice != 7);

    return 0;
}

