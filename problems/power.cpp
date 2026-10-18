#include <iostream>

using namespace std;


int power(int x, int n){
	int bf = n, ans = 1;
	while(bf > 0){
		if(bf % 2 == 1){
			ans *= x;
		}
		x *= x;
		bf /= 2;
	}
	
	return ans;
}

int main(){
	int x, y;
	cout << "Enter a number and its power : ";
	cin >> x;
	cin >> y;
	
	cout << "Result: " << power(x, y) << endl;
	
	return 0;
}

