#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

class BracketStack {
private:
    int top;
    char arr[MAX];

public:
    BracketStack() {
        top = -1;
    }

    bool isFull() {
        return (top == MAX - 1);
    }

    bool isEmpty() {
        return (top == -1);
    }

    void push(char ch) {
        if (isFull()) return;
        arr[++top] = ch;
    }

    char pop() {
        if (isEmpty()) return '\0';
        return arr[top--];
    }

    char peek() {
        if (isEmpty()) return '\0';
        return arr[top];
    }
};

bool isBalanced(string expr) {
    BracketStack stack;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        // Push opening brackets
        if (ch == '(' || ch == '{' || ch == '[') {
            stack.push(ch);
        }
        // Check closing brackets
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (stack.isEmpty()) return false; // Underflow means unmatched closing bracket

            char topChar = stack.pop();
            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return false; // Mismatched brackets
            }
        }
    }
    return stack.isEmpty(); // If empty, all brackets were balanced
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    getline(cin, expr);

    if (isBalanced(expr)) {
        cout << "Output: Balanced\n";
    } else {
        cout << "Output: Not Balanced\n";
    }

    return 0;
}

