#include<iostream>

using namespace::std;

int main(){
	int arr[4] = {1,2,0,4};
	int output[4];
	int temp = 1;
	int rightProduct = 1;
	
	for(int i =0; i <4; i++){
		
		output[i] = temp;
		temp *= arr[i];		
		
	}
	
	for(int j =3; j >=0; j--){
		
		output[j] *= rightProduct;
		rightProduct *= arr[j];
		
	}
	
	for(int i =0; i <4; i++){
		
		cout<<output[i] << endl;
		
	}
	
	return 0;
}
