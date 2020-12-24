#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool sumUptoX(int arr[],int n,int start,int X){
    sort(arr,arr+n);

    int i = start,j = n-1;
    while(i < j){
        if(arr[i] + arr[j] == X){
            cout << arr[i] << " " << arr[j] << " ";
            return true;
        }
        if(arr[i]+arr[j] < X){
            i++;
        }else{
            j--;
        }
    }
    return false;
}

bool tripletSumX(int arr[],int n,int X){
    bool isPresent = false;

    for(int i = 0;i < n-2;i++){
        if(sumUptoX(arr,n,i+1,X-arr[i])){
            cout << arr[i] << endl;
            isPresent = true;
        }
    }

    if(!isPresent){
        cout << "No triplet found with sum " << X << endl;
    }
    return isPresent;
}

int main(){
    int arr[] = {12, 3, 4, 1, 6, 9};
    int X = 24;
    int n = sizeof(arr)/sizeof(arr[0]);

    sort(arr,arr+n);

    cout << tripletSumX(arr,n,X);
    return 0;
}