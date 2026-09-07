#include<iostream>
#include<vector>

using namespace std;

vector<int> reversed_vector(vector<int> *vec, int size){
	vector<int> vec2(5);
	for(int i = size-1,j=0;i>=0;i--,j++){
		vec2[j] = (*vec)[i];
	}
	return vec2;
}


int main(){
	vector<int> vec1 = {1,2,3,4,5};
	int size = 5;
	
	cout<<"Vector befor reversing : "<<endl;
	 for(int num : vec1){
	 	cout<<num<<endl;
	 }
	
	vector<int> reversed = reversed_vector(&vec1, size);
	cout<<"Reversed vector : "<<endl;
	 for(int num : reversed){
	 	cout<<num<<endl;
	 }
	
	return 0;
}

