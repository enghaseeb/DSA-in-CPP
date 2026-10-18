#include<iostream>

using namespace::std;

bool palindrome(int x){
	int temp = x, rev = 0;
	
	while(x != 0){
		int last_val = x % 10;
		rev = rev*10 + last_val;
		x/=10;
	}
	
	retaurn temp == rev;
	
}

int main(){
	if(palindrome(-101)){
		cout << "The given number is palindrome" << endl;
	} else{
		cout << "The given number is not palindrome" << endl;
	}
	return 0;
}
