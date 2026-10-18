#include<iostream>
#include<vector>

using namespace::std;

int MajorityElement(vector<int> nums){
	
	int n = nums.size();
	int i = 0, j = n-1;
	for(int val: nums){
		int freq = 0;
		for(int el: nums){
			if(el==val){
				freq++;
			}
		}
		if(freq >= n/2){
			return val;
		}
	}
	return -1;
}

int main(){
	vector<int> nums = {2,3,1,2,1};
	
	int ans = MajorityElement(nums);
	cout<<ans<<endl;
	
	
	return 0;
}
