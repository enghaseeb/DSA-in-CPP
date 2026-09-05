#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace::std;

int decToBinary(int decNum){
	int ans = 0, pow = 1;
	
	while(decNum>0){
		int rem = decNum%2;
		decNum/= 2;
		
		ans += (rem * pow);
		pow *= 10;
	}
	
	return ans;
}

int main(){
	srand(time(0));
    int decimal_number = (rand() % 100) + 1;
    
   cout<< decToBinary(decimal_number)<<" is binary form of decimal number: "<<decimal_number;
	
	return 0;
}









