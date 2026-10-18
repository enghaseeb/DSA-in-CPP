#include<iostream>

using namespace::std;

int main(){
	float array[10] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.1};
	float* arrptr = array;
	for(int i=0; i<10; i++){
		if(i%2 != 0){
			cout<<*(arrptr+i)<<" is at odd numbered position "<<i<<endl;
		}
	}
	return 0;
}
