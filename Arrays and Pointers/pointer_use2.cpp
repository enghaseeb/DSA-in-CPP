#include<iostream>

using namespace::std;

int main(){
	int number;
	cout<<"Enter a Number please : ";
	cin>>number;
	
	int* ptr = &number;
	cout<<"You entered : "<<*ptr<<endl;
	
	
	return 0;
}
