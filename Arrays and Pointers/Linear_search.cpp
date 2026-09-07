#include<iostream>
using namespace::std;

int linear_search(int arr[], int size){
	for(int i=0; i<size;i++){
		if(arr[i]==8){
			return i;
		}
		
	}
	return -1;
}

int main(){
	int arr[9] = {1,2,5,3,8,4,6,7,9};
	//find 8 and return its index if it exist? and return -1 if not exist.
	cout<<linear_search(arr,9);	
	
	return 0;
}
