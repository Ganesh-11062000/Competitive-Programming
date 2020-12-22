#include<iostream>
using namespace std;

void cyclicRotate(int arr[],int n){
    int temp = arr[0];

    for(int i = 0;i < n-1;i++){
        arr[i] = arr[i+1];
    }

    arr[n-1] = temp;
}

void display(int arr[],int n){
    for(int i = 0;i < n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {1,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Before rotation: " << endl;
    display(arr,n);

    cyclicRotate(arr,n);
    cout << "After rotation: " << endl;
    display(arr,n);
    return 0;
}