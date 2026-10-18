#include<iostream>

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

class LinkList{
	private:
		Node* head;
		Node* tail; 
	public:
		LinkList(){
			head = NULL;
			tail = NULL; 
		}
		
		void insertAtFront(int a){
			Node* newNode = new Node(a);
			newNode->next = head;
			
			if(head != NULL){
				head->prev = newNode; 
			} else {
				tail = newNode; 
			}
			
			head = newNode;
		}
		
		void insertAtEnd(int a){
			Node* newNode = new Node(a);
			if(head == NULL){
				head = newNode;
				tail = newNode; 
				return;
			}
			
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode; 
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
			
			Node* temp = head;
			
			
			for(int i = 1; temp != NULL && i < position - 1; i++){
				temp = temp->next;
			}
			
			if(temp == NULL){
				cout << "Position out of bounds." << endl;
				return;
			}
			
			
			if(temp == tail) {
				insertAtEnd(a);
				return;
			}
			
			Node* newNode = new Node(a);
			newNode->next = temp->next;
			newNode->prev = temp; 
			
			if(temp->next != NULL){
				temp->next->prev = newNode; 
			}
			temp->next = newNode;
		}
		
		void deleteFromFront(){
			if(head == NULL){
				cout << "List is empty. Nothing to delete." << endl;
				return;
			}
			Node* temp = head;
			head = head->next; 
			
			if(head != NULL){
				head->prev = NULL; 
			} else {
				tail = NULL; 
			}
			delete temp;       
		}
		
		void deleteFromEnd(){
			if(head == NULL){
				cout << "List is empty. Nothing to delete." << endl;
				return;
			}
			
			Node* temp = tail;
			if(head == tail){ 
				head = NULL;
				tail = NULL;
			} else {
				
				tail = tail->prev;
				tail->next = NULL;
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
			
			
			for(int i = 1; temp != NULL && i < position; i++){
				temp = temp->next;
			}
			
			if(temp == NULL){
				cout << "Position out of bounds." << endl;
				return;
			}
			

			if(temp == tail){
				deleteFromEnd();
				return;
			}
			
			temp->prev->next = temp->next;
			
			if(temp->next != NULL){
				temp->next->prev = temp->prev;
			}
			
			delete temp;           
		}
		
		
		void Display(){
			Node* temp = head;
			while(temp != NULL){
				cout << temp->data << " , ";
				temp = temp->next;
			}
			cout << "Null" << endl;
		}

		
		void DisplayBackward(){
			if(tail == NULL) {
				cout << "Null" << endl;
				return;
			}
			Node* temp = tail; 
			while(temp != NULL){
				cout << temp->data << " , ";
				temp = temp->prev;
			}
			cout << "Null" << endl;
		}
};

int main(){
	LinkList l;
	
	cout << "--- Inserting at Front ---" << endl;
	l.insertAtFront(10);
	l.insertAtFront(20);
	l.insertAtFront(30);
	l.Display(); 
	l.DisplayBackward();
	
	cout << "\n--- Inserting 15 at position 3 ---" << endl;
	l.insertAtAnyPoint(15, 3);
	l.Display(); 
	
	cout << "\n Deleting from Front " << endl;
	l.deleteFromFront();
	l.Display(); 
	
	cout << "\n Deleting from End " << endl;
	l.deleteFromEnd();
	l.Display(); 
	
	cout << "\n Deleting from Position 2 " << endl;
	l.deleteFromAnyPoint(2);
	l.Display(); 
	
	cout << "\n Verification (Backward Traversal) " << endl;
	l.DisplayBackward();

	return 0;
}

