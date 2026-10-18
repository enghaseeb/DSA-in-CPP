#include<iostream>

using namespace std;

void AgeDef(int* arrptr, int size){
	int count1 = 0, count2 = 0;
	
	int young[10]; 
	int old[10];
	
	for(int i = 0; i < size; i++){
		if(*(arrptr + i) < 40){
			young[count1] = *(arrptr + i);
			count1++;
		}
		else{
			old[count2] = *(arrptr + i);
			count2++;
		}
	}
	
	
	cout << "young" << endl;
	for(int i = 0; i < count1; i++){
		cout << young[i] << endl;
	}
	
	
	cout << "old" << endl;
	for(int i = 0; i < count2; i++){
		cout << old[i] << endl;
	}
}

int main(){
	int AgeList[10] = {20, 30, 40, 50, 60, 70, 80, 10, 20, 32};
	AgeDef(AgeList, 10);
	return 0;
}

