#include<iostream>

using namespace::std;

int RotatedSortedArray(int arr[], int target, int st, int end){
	int mid = st+(end-st)/2;
	while(st <= end){
		mid = st+(end-st)/2;
		if(target == arr[mid]) {
			return mid;
		}
		
		if(arr[st] <= arr[mid]){
			if(arr[st] <= target && target <= arr[mid]){
				end = mid-1;
			}else{
				st = mid+1;
			}
		}else{
			if(arr[mid] <= target && target <= arr[end]){
				st = mid+1;
			}else{
				end = mid-1;
			}
		}
	}
	return -1;
}

int main(){
	int arr[7] = {4,5,6,7,1,2,3};
	int target = 1;
	int result = RotatedSortedArray(arr, target, 0, 6);
	
	if(result == -1){
		cout << "The target is not in the given array." << endl;
    } else{
      cout << "The target is at index " << result << ". Which is " << arr[result] << endl;	 
    }
	
	return 0;
}
