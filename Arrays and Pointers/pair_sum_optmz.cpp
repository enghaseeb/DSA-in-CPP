#include<iostream>

using namespace::std;

int* pairSum(int nums[], int target){
	static int ans[2];
	int i=0, j=sizeof(nums)/sizeof(nums[0]);
	while(i<j){
		int pairsum = nums[i]+nums[j];
		if(pairsum < target){
			i++;
		}
		else if(pairsum > target){
			j--;
		}
		else{
			ans[0] = i;
			ans[1] = j;
			return ans;
		}
	}
	return nullptr;
}

int main(){
	int nums[5] = {1,2,3,4,5};
	int target = 3;
	
	int* ans = pairSum(nums,target);
	if (ans != nullptr) {
        cout << ans[0] << ", " << ans[1] << endl;
    } else {
        cout << "No pair found." << endl;
    }
	
	return 0;
}

