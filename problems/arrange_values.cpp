#include<iostream>

using namespace::std;

int main(){
	int arr[5] = {0,1,0,3,12};
	
	
	int i = 0, j = 0;
	
	for(;j<5;j++){
		if(arr[j]!=0){
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
		}
	}
	
	for(int i =0; i<5; i++){
		cout << arr[i]<<endl;
	}
	return 0;
}
