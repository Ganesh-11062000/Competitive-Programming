#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool sumUptoX(int arr[],int n,int X){
    sort(arr,arr+n);

    int i = 0,j = n-1;
    while(i < j){
        if(arr[i] + arr[j] == X){
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

int main(){
    int arr[] = {1,3,5,6,2};
    int X = 9;
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Pair is present = " << sumUptoX(arr,n,X);
    return 0;
}