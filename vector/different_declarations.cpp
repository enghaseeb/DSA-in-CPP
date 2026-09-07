#include<iostream>
#include<vector>
using namespace::std;

int main(){
	//first method of vector declaration
	/*vector<int> vec1; //its initial size is 0
	cout<<vec1[0]<<endl;*/ //it will give nothing and an error because nothing is store in it in this particular situation.
	//I have comented the first method because it generate an error due to which the next part execution will be suffering.
	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	
	//method 2: declartion + initialization
	vector<int> vec2 = {1, 2, 3}; //size is 3
	cout<<vec2[1]<<endl;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//method 3: declartion + initialization
	vector<int> vec3 (4, 0);
	for(int i : vec3){
		cout<<i<<endl;
	}
	
	return 0;
}
