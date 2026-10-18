#include<iostream>

using namespace::std;

int main(){
	int height[9] = {1,8,6,2,5,4,8,3,7};
	int L = 0, R = 8;
	int max_ = 0;
	int area;
	while(L<R){
		
		area = min(height[L],height[R])*(R-L);
		max_ = max(max_,area);
		if(height[L] < height[R]){
			L++;
		}
		else{
			R--;
		}
	}
	cout << max_ <<endl;
	
	return 0;
}
