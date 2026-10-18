#include<iostream>

using namespace::std;

int main(){
	int array[4] = {2, 7, 2, 15};
	int size = 4;
	int target_sum = 9;
	
	for(int i=0; i<size; i++){
		for(int j=i+1; j<size; j++){
			if(array[i]+array[j]==target_sum){
				cout<<"index["<<i<<"] and index["<<j<<"] = "<<target_sum<<endl;
			}
		}
	}
	return 0;
}
