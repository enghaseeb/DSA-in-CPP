#include<iostream>

using namespace::std;

int main(){
	int price[6] = {7,1,5,3,6,4};
	int Buy = price[0];
	int max_profit = 0;
	for(int i =1; i <6; i++){
		max_profit = max(max_profit,price[i]-Buy);
		Buy = min(Buy,price[i]);
	}
	cout << max_profit << endl;
	return 0;
}
