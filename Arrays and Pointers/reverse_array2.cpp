#include<iostream>

using namespace::std;

int main(){
	int array[8];
	
	cout<<"### Enter elements of array of size 8 ###"<<endl;
	for(int i=0; i<8; i++){
		cin>>array[i];
	}
	
	cout<<"### The elements of array in reverse ###"<<endl;
	for(int i=7; i>=0; i--){
		cout<<array[i]<<" ";
	}
	return 0;
}
