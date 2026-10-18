#include<iostream>
#include<vector>

using namespace::std;

int stockBuySell(vector<int>& stock){
		int minPrice = stock[0];
		int maxPrice = 0;
		int size = stock.size();
		for(int i =1; i < size; i++){
			maxPrice = max(maxPrice,stock[i]-minPrice);
			minPrice = min (minPrice,stock[i]);
		}
		
		return maxPrice;
	}

int main(){
	vector<int> stock = {7,1,5,3,6,4};
	cout << stockBuySell(stock);
	
	return 0;
}
