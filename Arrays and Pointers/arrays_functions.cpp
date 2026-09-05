#include<iostream>

using namespace::std;

void min(int arr[], int size){
    int minimum = arr[0];
    for(int i=1;i<size;i++){
        if(arsr[i]<minimum){
            minimum = arr[i];
        }
    }
    cout<<"The minimum element of array is "<<minimum<<endl;
}

void max(int arr[], int size){
    int maximum = arr[0];
    for(int i=1;i<size;i++){
        if(arr[i]>maximum){
            maximum = arr[i];
        }
    }
    cout<<"The maximum element of array is "<<maximum<<endl;
}

void sum(int arr[], int size){
    int sum = 0;
    for(int i=0;i<size;i++){
        sum+= arr[i];
    }
    
    cout<<"Sum of all the elements of array is "<<sum<<endl;
}


void avg(int arr[], int size){
    int avg = 0;
    for(int i=0;i<size;i++){
         avg+= arr[i];
    }

    cout<<"Average of all the elements of array is "<<avg/size<<endl;
}




int main(){

    int arr[5] = {10,20,30,40,50};
    int size = 5;

    min(arr,size);
    max(arr,size);
    sum(arr,size);
    avg(arr,size);

    return 0;
};
