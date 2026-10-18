#include<iostream>

using namespace::std;

int main(){
	int array[10] = {3,3,3,1,2,1,2};
	int ans = 0, freq = 0;
	
	for(int i = 0; i < 10; i++){
		if(freq == 0){
			ans = array[i];
		}
		if(ans == array[i]){
			freq++;
		} else {
			freq--;
		}
	}
	cout << ans << " is the major element" << endl;
	return 0;
}

