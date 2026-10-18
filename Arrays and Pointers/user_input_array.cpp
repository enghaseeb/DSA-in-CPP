#include<iostream>

using namespace::std;

int main(){
	int size;
	cout<<"Enter the size of array : ";
	cin>>size;
	
	int array[size];
	
	for(int i=0; i<size; i++){
		cin>>array[i];
	}
	
	int sum = 0;
	
	cout<<"You entered : "<<endl;
	for(int i=0; i<size; i++){
		cout<<array[i]<<endl;
		sum+=array[i];
	}
	cout<<"The sum of the elements of array is : "<<sum<<endl;
	
	return 0;
}
