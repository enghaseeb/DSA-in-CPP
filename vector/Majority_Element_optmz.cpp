#include<iostream>
#include<vector>
#include<algorithm>

using namespace::std;

int MajorityElement(vector<int> nums){
		int n = nums.size();
		
		sort(nums.begin(), nums.end());
		
		int freq = 1, ans = nums[0];
		
		for(int i=1; i<n; i++){
			if(nums[i] == nums[i-1]){
				freq++;
			}else{
				freq = 1;
				ans = nums[i];
			}
			if(freq > n/2){
				return ans;
			}
		}
		return ans;	
}

int main() {
	vector<int> nums = {2,2,1,2,1,2,3};
	
	int ans = MajorityElement(nums);
	cout<<ans<<endl;
	
	return 0;
}
