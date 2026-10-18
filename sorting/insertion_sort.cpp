#include<iostream>

using namespace::std;

const int N = 5;

int main(){
	int arr[N] = {5,4,3,2,1};
	
	for(int i = 1; i < N; i++){
		
		int key = arr[i];
		int j = i - 1;
		
		while(j >= 0 && arr[j] > key){
			
			arr[j+1] = arr[j];
			j--;
			
		}
		
		arr[j+1] = key;
		
	}
	
	for(int i = 0; i < N; i++){
		
		cout<< arr[i] << "\t";
		
	}
	
	return 0;
}
