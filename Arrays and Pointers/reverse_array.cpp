#include<iostream>

using namespace::std;

void reverse(int arr[] ,int size){
	
	for(int i=size-1;i>=0;i--){
			cout<<arr[i]<<"";
			}
	}
	


int main(){
	int arr[5] = {1,2,3,4,5};
	int size = 5;
	reverse(arr,size);
	return 0;
}
