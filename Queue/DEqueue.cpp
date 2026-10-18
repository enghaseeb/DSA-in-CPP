#include <iostream>
using namespace std;



class DEqueue {
private:
    int arr[5];
    int front, rear, count;

public:
    DEqueue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == 5;
    }

    void insertRear(int val) {
        if (isFull()) {
            cout << "Overflow! Deque is full.\n";
            return;
        }
        rear = (rear + 1) % 5;   
        arr[rear] = val;
        count++;
        cout << val << " Inserted at rear side of the queue. Rear=" << rear
             << " Front=" << front << "\n";
    }

    void insertFront(int val) {
        if (isFull()) {
            cout << "Overflow! Deque is full.\n";
            return;
        }
        front = (front - 1 + 5) % 5;   
        arr[front] = val;
        count++;
        cout << val << " Inserted at front side of the queue. Rear=" << rear
             << " Front=" << front << "\n";
    }

    void removeRear() {
        if (isEmpty()) {
            cout << "Underflow! Deque is empty.\n";
            return;
        }
        int val = arr[rear];
        rear = (rear - 1 + 5) % 5;
        count--;
        cout << val << " removed from rear side of the queue. Rear=" << rear
             << " Front=" << front << "\n";
    }

    void removeFront() {
        if (isEmpty()) {
            cout << "Underflow! Deque is empty.\n";
            return;
        }
        int val = arr[front];
        front = (front + 1) % 5;
        count--;
        cout << val << " removed from front side of the queue. Rear=" << rear
             << " Front=" << front << "\n";
    }

    void display() {
        cout << "Index\tValue\tPointer\n";
        for (int i = 0; i < 5; i++) {
            cout << i << "\t";
            
            bool occupied = false;
            if (!isEmpty()) {
                if (front <= rear)
                    occupied = (i >= front && i <= rear);
                else
                    occupied = (i >= front || i <= rear);
            }
            if (occupied)
                cout << arr[i];
            else
                cout << "empty";

            if (!isEmpty() && i == rear) cout << "\tRear";
            if (!isEmpty() && i == front) cout << "\tFront";
            cout << "\n";
        }
    }
};

int main() {
    DEqueue dq;
    int choice, value;

    do {
        cout << "\nPlease enter a number representing an operation in the "
                "following list (-1 to quit):\n";
        cout << "1. InsertRear()\n";
        cout << "2. InsertFront()\n";
        cout << "3. RemoveRear()\n";
        cout << "4. RemoveFront()\n";
        cout << "5. Display()\n";
        cout << "6. Exit\n";
        cout << "User enters >> ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a value that you want to insert at Rear side: ";
                cin >> value;
                dq.insertRear(value);
                break;
            case 2:
                cout << "Enter a value that you want to insert at Front side: ";
                cin >> value;
                dq.insertFront(value);
                break;
            case 3:
                dq.removeRear();
                break;
            case 4:
                dq.removeFront();
                break;
            case 5:
                dq.display();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}
