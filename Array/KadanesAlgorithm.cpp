#include<iostream>
using namespace std;

int kadane(int arr[],int n){
    int max_so_far = arr[0];
    int current_sum = arr[0];

    for(int i = 1;i < n;i++){

        if(current_sum + arr[i] <= arr[i]){
            current_sum = arr[i];
        }else{
            current_sum += arr[i];
        }

        if(current_sum > max_so_far){
            max_so_far = current_sum;
        }
    }

    return max_so_far;
}

int main(){
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Largest Sum Contigous Array = " << kadane(arr,n);
    return 0;
}