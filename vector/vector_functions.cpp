#include<iostream>
#include<vector>

using namespace::std;

int main(){
	// size function
	cout<<"size function"<<endl;
	vector<char> vec1 = {'H', 'a', 's', 'e', 'e', 'b'};
	cout<<"Vector size = "<<vec1.size()<<endl;
	for(char i : vec1){
    	cout<<i;
	}
	cout<<"\n";
	
	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//push_back function
	cout<<"\npush back function"<<endl;
	vector<int> vec2;
	cout<<vec2.size()<<endl;
	vec2.push_back(20);
	vec2.push_back(30);
	cout<<vec2.size()<<endl;
//for printing values
    for(int i : vec2){
    	cout<<i<<endl;
	}
	
	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//pop_back function
	cout<<"\npop back function"<<endl;
	vector<int> vec3;
	vec3.push_back(20);
	vec3.push_back(30);
	vec3.pop_back();
	cout<<vec3.size()<<endl;
//for printing values to the console
    for(int i : vec3){
    	cout<<i<<endl;
	}
	
	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//front function
	cout<<"\nfront function"<<endl;
	vector<int> vec4;
	vec4.push_back(20);
	vec4.push_back(30);
	cout<<vec4.front()<<endl;
	
	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//back function
	cout<<"\nback function"<<endl;
	vector<int> vec5;
	vec5.push_back(20);
	vec5.push_back(30);
	cout<<vec5.back()<<endl;
	
	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//at function
	cout<<"\nat function"<<endl;
	vector<int> vec6;
	vec6.push_back(20);
	vec6.push_back(30);
	cout<<vec6.at(0)<<endl;
	cout<<vec6.at(1)<<endl;
		
	
	return 0;
}
