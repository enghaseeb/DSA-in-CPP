#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* prev; 
        Node(int a){
            data = a;
            next = NULL;
            prev = NULL; 
        }
};

class CircularLinkList {
    private:
        Node* head;
        Node* tail; 
    public:
        CircularLinkList(){
            head = NULL;
            tail = NULL; 
        }
        
        // 1. Insertion Functions
        void insertAtFront(int a){
            Node* newNode = new Node(a);
            if(head == NULL){
                head = newNode;
                tail = newNode;
                newNode->next = head;
                newNode->prev = head;
            } else {
                newNode->next = head;
                newNode->prev = tail;
                head->prev = newNode;
                tail->next = newNode;
                head = newNode; 
            }
            cout << "Inserted " << a << " at front." << endl;
        }
        
        void insertAtEnd(int a){
            Node* newNode = new Node(a);
            if(head == NULL){
                head = newNode;
                tail = newNode; 
                newNode->next = head;
                newNode->prev = head;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                newNode->next = head; 
                head->prev = newNode; 
                tail = newNode;       
            }
            cout << "Inserted " << a << " at end." << endl;
        } 
        
        void insertAtAnyPoint(int a, int position){
            if(position < 1){
                cout << "Position should be >= 1" << endl;
                return;
            }
            if(position == 1){
                insertAtFront(a);
                return;
            }
            if(head == NULL){
                cout << "List is empty. Can only insert at position 1." << endl;
                return;
            }
            
            Node* temp = head;
            int i = 1;
            
            while(i < position - 1) {
                temp = temp->next;
                i++;
                if(temp == head) {
                    cout << "Position out of bounds." << endl;
                    return;
                }
            }
            
            if(temp == tail) {
                insertAtEnd(a);
                return;
            }
            
            Node* newNode = new Node(a);
            newNode->next = temp->next;
            newNode->prev = temp; 
            temp->next->prev = newNode; 
            temp->next = newNode;
            cout << "Inserted " << a << " at position " << position << "." << endl;
        }
        
        // 1. Deletion Functions
        void deleteFromFront(){
            if(head == NULL){
                cout << "List is empty. Nothing to delete." << endl;
                return;
            }
            
            Node* temp = head;
            cout << "Deleted " << head->data << " from front." << endl;
            
            if(head == tail){ 
                head = NULL;
                tail = NULL;
            } else {
                head = head->next; 
                head->prev = tail;
                tail->next = head;
            }
            delete temp;       
        }
        
        void deleteFromEnd(){
            if(head == NULL){
                cout << "List is empty. Nothing to delete." << endl;
                return;
            }
            
            Node* temp = tail;
            cout << "Deleted " << tail->data << " from end." << endl;
            
            if(head == tail){ 
                head = NULL;
                tail = NULL;
            } else {
                tail = tail->prev;
                tail->next = head;
                head->prev = tail;
            }
            delete temp; 
        }
        
        void deleteFromAnyPoint(int position){
            if(head == NULL){
                cout << "List is empty." << endl;
                return;
            }
            if(position < 1){
                cout << "Position should be >= 1" << endl;
                return;
            }
            if(position == 1){
                deleteFromFront();
                return;
            }
            
            Node* temp = head;
            int i = 1;
            
            while(i < position) {
                temp = temp->next;
                i++;
                if(temp == head) {
                    cout << "Position out of bounds." << endl;
                    return;
                }
            }
            
            if(temp == tail){
                deleteFromEnd();
                return;
            }
            
            cout << "Deleted " << temp->data << " from position " << position << "." << endl;
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;           
        }
        
        // 1. Forward Display Function
        void Display(){
            if(head == NULL) {
                cout << "List is empty." << endl;
                return;
            }
            Node* temp = head;
            cout << "Forward List: ";
            do {
                cout << temp->data << " <-> ";
                temp = temp->next;
            } while(temp != head);
            cout << "(Back to Head: " << head->data << ")" << endl;
        }

        // 2. Display Size and Elements in Reverse Order
        void displaySizeAndReverse(){
            if(head == NULL){
                cout << "List Size: 0" << endl;
                cout << "Reverse List: List is empty." << endl;
                return;
            }
            
            int size = 0;
            Node* temp = tail;
            
            cout << "Reverse List: ";
            do {
                cout << temp->data << " <-> ";
                size++;
                temp = temp->prev;
            } while(temp != tail);
            cout << "(Back to Tail: " << tail->data << ")" << endl;
            
            cout << "Total List Size: " << size << " element(s)" << endl;
        }
        
        // 3. Cycle-Safe Search Function
        void Search(int value){
            if(head == NULL){
                cout << "Value " << value << " NOT found (List is empty)." << endl;
                return;
            }
            
            Node* temp = head;
            int position = 1;
            bool found = false;
            
            // Stopping mechanism: Stop once temp wraps all the way back around to head
            do {
                if(temp->data == value){
                    cout << "Value " << value << " found at position: " << position << endl;
                    found = true;
                    // Continuing instead of breaking to match all duplicate instances if they exist
                }
                temp = temp->next;
                position++;
            } while(temp != head);
            
            if(!found){
                cout << "Value " << value << " was not found in the list." << endl;
            }
        }
};

int main(){
    CircularLinkList list;
    int choice, value, position;
    
    do {
        cout << "\n==============================================" << endl;
        cout << "   DOUBLY CIRCULAR LINKED LIST MENU SYSTEM    " << endl;
        cout << "==============================================" << endl;
        cout << "1. Insert at Front" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert at Specific Position" << endl;
        cout << "4. Delete from Front" << endl;
        cout << "5. Delete from End" << endl;
        cout << "6. Delete from Specific Position" << endl;
        cout << "7. Search Value (With Cycle-Stopping Mechanism)" << endl;
        cout << "8. Display List (Forward)" << endl;
        cout << "9. Display Size & List (Reverse Order)" << endl;
        cout << "0. Exit Program" << endl;
        cout << "==============================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "----------------------------------------------" << endl;
        
        switch(choice) {
            case 1:
                cout << "Enter integer value to insert: ";
                cin >> value;
                list.insertAtFront(value);
                break;
            case 2:
                cout << "Enter integer value to insert: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter integer value to insert: ";
                cin >> value;
                cout << "Enter insertion position (>= 1): ";
                cin >> position;
                list.insertAtAnyPoint(value, position);
                break;
            case 4:
                list.deleteFromFront();
                break;
            case 5:
                list.deleteFromEnd();
                break;
            case 6:
                cout << "Enter position to delete from (>= 1): ";
                cin >> position;
                list.deleteFromAnyPoint(position);
                break;
            case 7:
                cout << "Enter value to search for: ";
                cin >> value;
                list.Search(value);
                break;
            case 8:
                list.Display();
                break;
            case 9:
                list.displaySizeAndReverse();
                break;
            case 0:
                cout << "Exiting menu system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please select an option from 0 to 9." << endl;
        }
    } while(choice != 0);
    
    return 0;
}

