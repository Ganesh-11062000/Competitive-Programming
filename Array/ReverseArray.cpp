#include<iostream>
using namespace std;

void reverseArray(int arr[], int n){
    for(int i=0;i < n/2;i++){
        int temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }
}

void display(int arr[],int n){
    for(int i=0; i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Initial Array = ";
    display(arr,n);

    reverseArray(arr,n);
    cout << "After reversing the array = ";
    display(arr,n);
    
    return 0;
}