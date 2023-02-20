// Q1. -> Given an array of elements, replace every element with nearest greater element on the
// right of that element.

#include<iostream>
using namespace std;


void replace_element(int arr[], int size){
    for(int i = 0; i < size-1; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            if(arr[j] > arr[i])
            {
                arr[i] = arr[j];
                break;
            }
        }
    }
}

int main(){

    int arr[7] = {2, 7, 3, 5, 4, 6, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    
    cout<<endl;
    
    replace_element(arr , n);

    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";

}