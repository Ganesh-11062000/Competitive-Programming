#include<iostream>
using namespace std;

void sortArray(int arr[],int n){

    //bubble sort
    for(int i=0;i < n-1;i++){
        for(int j=0; j < n-1;j++){
            
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

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
    int k;

    cout << "Enter value of k less than " << n+1 << endl;
    cin >> k;

    cout << "Array = ";
    display(arr,n);

    sortArray(arr,n);
    cout << "After sorting = ";
    display(arr,n);

    cout << "KthMin element = " << arr[k-1] << endl;
    cout << "KthMax element = " << arr[n-k] << endl;

    return 0;
}