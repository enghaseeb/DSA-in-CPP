#include<iostream>
#include<vector>

using namespace::std;

int main(){
	vector<int> vec;
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);
	
	cout<<"The size of vector is : "<<vec.size()<<endl;
	cout<<"The capacity of vector is : "<<vec.capacity()<<endl;
		
	return 0;
}
