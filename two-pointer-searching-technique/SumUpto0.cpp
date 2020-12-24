#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool sumUptoX(int arr[],int n){
    sort(arr,arr+n);

    int i = 0,j = n-1;
    while(i < j){
        if(arr[i] + arr[j] == 0){
            return true;
        }
        if(arr[i]+arr[j] < 0){
            i++;
        }else{
            j--;
        }
    }
    return false;
}

int main(){
    int arr[] = {1,2,5,6,-2};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Pair is present = " << sumUptoX(arr,n);
    return 0;
}