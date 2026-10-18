#include<iostream>

using namespace::std;

const int N = 5;

int main(){
	int arr[N] = {5,4,3,2,1};
	
	for(int i = 0; i < N-1; i++){
		
		for(int j = i+1; j < N; j++){
			
			if(arr[i] > arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			
		}
		
	}
	
	for(int i = 0; i < N; i++){
		
		cout<< arr[i] << "\t";
		
	}
	
	return 0;
}
