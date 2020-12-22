#include<iostream>
using namespace std;

void minMaxArray(int arr[],int n,int minmax[]){
    int min = arr[0], max = arr[0];

    for(int i =0;i < n;i++){
        if(arr[i] < min){
            min = arr[i];
        }
        if(arr[i] > max){
            max = arr[i];
        }
    }

    minmax[0] = min;
    minmax[1] = max;
}

void display(int arr[],int n){
    for(int i =0; i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {2,1,4,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    int minmax[2];
    minMaxArray(arr,n,minmax);

    cout << "Array = ";
    display(arr,n);

    cout << "Min element = " << minmax[0] << ", Max element = " << minmax[1];

    return 0;
}