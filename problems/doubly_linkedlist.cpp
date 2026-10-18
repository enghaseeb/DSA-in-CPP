#include <iostream>
using namespace::std;
template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(T val) : data(val), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t length;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), length(0) {}

    ~DoublyLinkedList() {
        clear();
    }

    // Push to front: O(1)
    void pushFront(T val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }

    // Push to back: O(1)
    void pushBack(T val) {
        Node* newNode = new Node(val);
        if (!tail) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    // Pop front: O(1)
    void popFront() {
        if (!head) return;
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        length--;
    }

    // Pop back: O(1)
    void popBack() {
        if (!tail) return;
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }

    // Display forward
    void displayForward() const {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " <-> ";
            temp = temp->next;
        }
        std::cout << "nullptr\n";
    }

    // Display backward
    void displayBackward() const {
        Node* temp = tail;
        while (temp) {
            std::cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        std::cout << "nullptr\n";
    }

    void clear() {
        while (head) {
            popFront();
        }
    }
};
