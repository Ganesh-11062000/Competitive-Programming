#include<iostream>
using namespace std;

void movePositiveNegative(int arr[],int n){
    int i = 0,j = n-1;
    int temp;

    while(i < j){
        if(arr[i] < 0){
            i++;
            continue;
        }
        if(arr[j] > 0){
            j--;
            continue;
        }
        
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        i++;
        j--;
    }
}

void display(int arr[],int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {-12,11,-13,-5,6,-7,5,-3,-6};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Array before moving = ";
    display(arr,n);

    movePositiveNegative(arr,n);

    cout << "Array after moving = ";
    display(arr,n);
    
    return 0;
}