#include<iostream>
#include<vector>

using namespace::std;

int main(){
	vector<int> single_number = {4, 1, 2, 1, 2};
	int ans = 0;
	
	for(int value : single_number){
		ans ^= value;
	}
	
	cout<<"The single number is : "<<ans<<endl;
	
	return 0;
}
