#include<iostream>
#include<vector>

using namespace::std;

int PeekInRotatedSortedArray(vector<int> vec, int st, int end){
	while(st <= end){
		int mid = st+(end-st)/2;
		if(vec[mid]>vec[mid-1] && vec[mid] > vec[mid+1]) return mid;
		
		else if(vec[mid]<=vec[mid+1] && vec[mid] >= vec[mid-1]) st = mid+1;
		else end = mid-1;
	}
	return -1;
}

int main(){
	vector<int> vec = {4,5,6,7,1,2,3};
	int result = PeekInRotatedSortedArray(vec, 1, 5);
	if(result == -1){
		cout << "The peek is not in the given array." << endl;
    } else{
      cout << "The peek is at index " << result << ". Which is " << vec[result] << endl;	 
    }
	
	return 0;
}
