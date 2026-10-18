#include<iostream>

using namespace::std;

int main(){
	int array[7] = {3, -4, 5, 4, -1, 7, -8};
	int size = 7;
	int maxSum = 0;
	
	for(int st=0; st<size; st++){
		int currentSum = 0;
		for(int end=st; end<size; end++){
			currentSum +=array[end];
			maxSum = max(currentSum,maxSum);
		}
	}
	
	cout<<"The maximum sub array sum is : "<<maxSum<<endl;
	
	return 0;
}
