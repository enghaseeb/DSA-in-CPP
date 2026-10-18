#include<iostream>
#include <climits>
#include<vector>

using namespace::std;

int main(){
	int array[7] = {5,-2,3,-10,4,6,-1};
	int size = 7;
	int maxSum = INT_MIN;
	int currentSum = 0;
	int count = 0;
	int track[7];
	
	for(int st=0; st<size; st++){
		currentSum += array[st];
		maxSum = max(maxSum,currentSum);
		track[count] = array[st];
		count++;
		
		if(currentSum < 0){
			currentSum = 0;
			count = 0;
		}
	}
	
	cout<<"The maximum sub array sum by kadane's algorith is : "<<maxSum<<endl;
	for(int i = 0; i < count; i++){
		cout<<track[i] << " ";
	}
	
	return 0;
}
