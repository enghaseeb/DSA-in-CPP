#include<iostream>
#include<algorithm>

using namespace::std;

int main(){
	int nums[6] = {-1,0,1,2,-1,-4};
	int ans = 0;
	sort(nums, nums + 6);
	for(int i =0; i<6; i++){
		int L=i+1, R = 5;
		while(L < R){
			ans = nums[i] + nums[L] + nums[R];
			if(ans == 0){
				cout << nums[i] << ", " <<nums[L] << ", " <<nums[R] << endl;
			}
			 if(ans < 0) L++;
			else R--;
		}
	}
	return 0;
}
