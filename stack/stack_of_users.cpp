#include<iostream>
#include<string>

using namespace::std;

class User{
	private:
		string names[5];
		int top;
	
	public:
		User(){
			top = -1;
		}
		
		void push(string value){
			if(top == 4){
				cout<<"Stack Overflow\n";
				return;
			}
			
			names[++top] = value;
		}
		
		void pop(){
			if(top < 0){
				cout<<"Stack Underflow\n";
				return;
			}
			top--;
		}
		
		string peek(){
			if(top < 0){
				cout<<"Stack Underflow\n";
				return "";
			}
			return names[top];
		}
		
		bool isEmpty(){
			return top < 0;
		}
		
};

int main(){
	
	User* name = new User();
	
	name->push("Haseeb");
	cout<<name->peek()<<endl;
	name->push("Ahmad");
	cout<<name->peek()<<endl;
	name->push("Aslam");
	cout<<name->peek()<<endl;
	name->push("Arshad");
	cout<<name->peek()<<endl;
	name->push("Ali");
	cout<<name->peek()<<endl;
	name->pop();
	name->push("Ali");
	name->push("Ali");	
	cout<<name->peek()<<endl;
	name->pop();
	name->pop();
	name->pop();
	name->pop();
	name->pop();
	name->pop();

	
	
	
	return 0;
}
