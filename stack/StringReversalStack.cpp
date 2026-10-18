#include <iostream>
#include <string>
using namespace std;

const int MAX = 100; // Maximum capacity of the stack

class StringStack {
private:
    int top;
    char arr[MAX]; // Character array to store characters

public:
    StringStack() {
        top = -1;
    }

    bool isFull() {
        return (top == MAX - 1);
    }

    bool isEmpty() {
        return (top == -1);
    }

    void push(char ch) {
        if (isFull()) {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = ch;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return '\0'; // Return null character on error
        }
        return arr[top--];
    }
};

int main() {
    StringStack stack;
    string inputStr;

    cout << "Enter a string: ";
    getline(cin, inputStr); // Reads the whole line, including spaces

    // Step 1: Push every character of the string onto the stack
    for (int i = 0; i < inputStr.length(); i++) {
        stack.push(inputStr[i]);
    }

    // Step 2: Pop characters one by one to form the reversed string
    string reversedStr = "";
    while (!stack.isEmpty()) {
        reversedStr += stack.pop();
    }

    // Display results
    cout << "Input:  " << inputStr << "\n";
    cout << "Output: " << reversedStr << "\n";

    return 0;
}

