#include<iostream>

using namespace::std;

int main(){
	int* ptr;
	int number = 10;
	ptr = &number;
	
	cout<<number<<endl;
	cout<<*ptr<<endl;
	cout<<&number<<endl;
	cout<<ptr<<endl;
	
	return 0;
}
