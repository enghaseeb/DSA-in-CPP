#include<iostream>

using namespace::std;

int main(){
	int arr[4] = {1,2,3,4};
	int output[4];
	
	
	
	for(int i =0; i <4; i++){
		int temp = 1;
		for(int j =0; j <4; j++){
			if(j != i){
				temp *= arr[j];
			}
		}
		output[i] = temp;
	}
	
	for(int i =0; i <4; i++){
		cout << output[i] << endl;
	}
	
	return 0;
}
