#include<iostream>

using namespace::std;

int BinarySearch(int arr[], int target, int st, int end){
	int mid = st+(end-st)/2;
	while(st <= end){
		mid = st+(end-st)/2;
		if(target == arr[mid]) return mid;
		else if(target < arr[mid]) end = mid-1;
		else if(target > arr[mid]) st = mid+1;
	}
	return -1;
}

int main(){
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int target = 10;
	int result = BinarySearch(arr,target,0,9);
    if(result == -1){
		cout << "The target is not in the given array." << endl;
   } else{
      cout << "The target is at index " << result << ". Which is " << arr[result] << endl;	 
   }
	return 0;
}
