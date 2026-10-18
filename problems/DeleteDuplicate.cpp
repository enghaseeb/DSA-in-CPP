#include<iostream>

using namespace::std;

int main(){
	int arr[8] = {1,1,2,2,3,4,4,5};
	int i = 0 ,j = 1;
	for(i =0; j <8; j++){
		if(arr[j] != arr[i]){
			i++;
			arr[i] = arr[j];
		}
	}
	
	
	for(int k =0; k <=i; k++){
		cout<<arr[k]<<endl;
	}
	
	return 0;
}
