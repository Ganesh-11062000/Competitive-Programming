#include<iostream>
using namespace std;

void sort012(int arr[],int n){
    int c0=0,c1=0,c2=0;
    for(int i = 0;i<n;i++){
        if(arr[i] == 0) c0++;
        if(arr[i] == 1) c1++;
        if(arr[i] == 2) c2++;
    }

    int k = 0;
    while(c0--){
        arr[k++] = 0;
    }
    while(c1--){
        arr[k++] = 1;
    }
    while(c2--){
        arr[k++] = 2;
    }
}

void display(int arr[],int n){
    for(int i=0;i < n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {0,1,0,2,2,1,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Before Sorting: " << endl;
    display(arr,n);

    sort012(arr,n);

    cout << "After Sorting: " << endl;
    display(arr,n);

    return 0;
}