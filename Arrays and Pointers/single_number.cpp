#include<iostream>
#include<vector>

using namespace::std;

int main(){
	vector<int> single_number = {1, 4, 2, 1, 2};
	int ans = 0;
	
	for(int value : single_number){
		ans ^= value;
	}
	
	cout<<"The single number is : "<<ans<<endl;
	
	return 0;
}
