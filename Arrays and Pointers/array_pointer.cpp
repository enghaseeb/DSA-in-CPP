#include<iostream>

using namespace::std;
int arr[3] = {1,2,2};
void CountOccurrence(int value){
	int count = 0;
	for(int i=0; i<sizeof(arr); i++){
		if(arr[i] == value){
			count++;
		}
	}
	cout<<value<<" is repeared "<<count<<" times."<<endl;
}

int main() {
	 CountOccurrence(2);
	return 0;
}
