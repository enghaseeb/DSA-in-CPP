#include<iostream>
#include<string>
#include<vector>

using namespace::std;

class stack{
	private:
		int storage[5];
		int top;
	
	public:
		stack(){
			top = -1;
		}
		
		
		void push(int val){
			if(top >= 4){
				cout << "Stack Overflow!\n";
				return;
			}
			
			storage[top++] = val;
			cout << storage[top] << " is pushed.\n";
			
		}
		
		void pop(){
			if(top <= -1){
				cout << "Stack Underflow!\n";
				return;
			}
			
			cout << storage[top--] << " is poped.\n";
			
		}
		
		
		void peek(){
			cout<<storage[top++]<<endl;
			
		}
		
		bool isEmpty(){
			return top == -1;
		}
};

int main(){
	stack* s = new stack();
	
	for(int i=0; i<=5; i++){
		s->push(i*2);
	}
	

	while(!s->isEmpty()){
		s->peek();
	}
	
	while(!(s->isEmpty())){
		s->pop();
	}
    
	return 0;
}
