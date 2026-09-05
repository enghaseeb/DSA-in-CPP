#include<iostream>
using namespace::std;

int findmin(int arr[], int size){
    int minimum = arr[0];
    for(int i=1;i<size;i++){
        if(arr[i]<minimum){
            minimum = arr[i];
        }
    }
    return minimum;
}

int main(){
	int arr[5] = {10,20,30,40,50};
    int size = 5;

    cout<<findmin(arr,size);
    
    return 0;
}

