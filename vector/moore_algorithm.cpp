#include<iostream>
#include<vector>

using namespace::std;

int main(){
	vector<int> vec = {1,1,3,1,1,5,1,3,4};
	int n = vec.size();
	int ans = 0, freq = 0;
	
	for(int i = 0; i < vec.size(); i++){
		if(freq == 0){
			ans = vec[i];
		}
		
		if(ans == vec[i]){
			freq++;
		} else {
			freq--;
		}
	}
	
	int count = 0;
	for(int val: vec){
		if(val == ans){
			count++;
		}
	}
	
	if(count > n/2){
		cout << ans << " is the majority element" << endl;
	}
	else{
		cout << "No majority element exist!" << endl;
	}
	return 0;
}

