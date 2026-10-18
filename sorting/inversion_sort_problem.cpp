#include<iostream>

using namespace::std;

const int N = 5;

int main(){
	int arr[N] = {2,4,1,3,5};
	int count = 0;
	
	for(int i = 0; i < N -1; i++){
		
		for(int j = 0; j < N - i - 1; j++){
			
			if(arr[j] > arr[j+1]){
				int temp  = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				count++;
			}
		}
	}
	
	for(int i = 0; i < N; i++){
		
		cout<< arr[i] << "\t";
		
	}
	
	cout << "\nThe answer is " << count << endl;
	
	return 0;
}
