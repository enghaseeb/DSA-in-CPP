#include<iostream>

using namespace::std;

class Node {
	public:
		int data;
		Node* next;
		Node(int a){
			data = a;
			next = NULL;
		}
};

class LinkList{
	private:
		Node* head;
		public:
			LinkList(){
				head = NULL;
			}
			
			void insertAtFront(int a){
				Node* newNode = new Node(a);
				newNode->next = head;
				head = newNode;
			}
			
			
			void insertAtEnd(int a){
				Node* newNode = new Node(a);
				if(head == NULL){
					head = newNode;
					return;
				}
				Node* temp = head;
				while(temp->next != NULL){
					temp = temp->next;
				}
				temp->next = newNode;
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
				
				Node* newNode = new Node(a);
				Node* temp = head;
				
				
				for(int i = 1; temp != NULL && i < position - 1; i++){
					temp = temp->next;
				}
				
				
				if(temp == NULL){
					cout << "Position out of bounds." << endl;
					delete newNode;
					return;
				}
				
				newNode->next = temp->next;
				temp->next = newNode;
			}
			
			
			void deleteFromFront(){
				if(head == NULL){
					cout << "List is empty. Nothing to delete." << endl;
					return;
				}
				Node* temp = head;
				head = head->next; 
				delete temp;       
			}
			
			
			void deleteFromEnd(){
				if(head == NULL){
					cout << "List is empty. Nothing to delete." << endl;
					return;
				}
				
				
				if(head->next == NULL){
					delete head;
					head = NULL;
					return;
				}
				
			
				Node* temp = head;
				while(temp->next->next != NULL){
					temp = temp->next;
				}
				
				delete temp->next; 
				temp->next = NULL; 
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
				
				
				for(int i = 1; temp != NULL && i < position - 1; i++){
					temp = temp->next;
				}
				
				
				if(temp == NULL || temp->next == NULL){
					cout << "Position out of bounds." << endl;
					return;
				}
				
				Node* nodeToDelete = temp->next;
				temp->next = temp->next->next; 
				delete nodeToDelete;           
			}
			
			void Display(){
				Node* temp = head;
				while(temp!=NULL){
					cout<<temp->data<<" -> ";
					temp = temp->next;
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
	
	return 0;
}

