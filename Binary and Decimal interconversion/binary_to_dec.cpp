#include<iostream>

using namespace::std;

int binaryToDec(int binary){
	int res = 0, pow = 1;
	while(binary>0){
		int rem = binary%10;
		binary /= 10;
		res += (rem * pow);
		pow *= 2;
	}
	
	return res;
}

int main(){
	int binary;
	cout<<"Enter a binary number you want to convert into decimal number: ";
	cin>>binary;
	
	cout<<"The decimal of "<<binary<<" is "<<binaryToDec(binary)<<endl;
	
	return 0;
}
