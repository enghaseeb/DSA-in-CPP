#include<iostream>
using namespace::std;

int main(){
	int price[6] = {7,1,5,3,6,4};
	int max_profit = 0;
	for(int i =0; i <5; i++){
		int buy = price[i];
		for(int j =i+1; j <6; j++){
			int sell = price[j];
			max_profit = max(max_profit,sell-buy);
		}
		
	}
	cout<<max_profit;
	return 0;
}
