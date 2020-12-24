#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void closestPair(int arr1[],int arr2[],int m,int n,int X){
    int i = 0,j = n-1,diff = INT_MAX;
    int u,v;

    while(i < m && j >= 0){

        if(abs(arr1[i] + arr2[j] - X) < diff){
            diff = abs(arr1[i] + arr2[j] -X);
            u = i;
            v = j;
        }

        if(arr1[i] + arr2[j] == X){
            break;
        }

        if(arr1[i] + arr2[j] < X){
            i++;
        }else{
            j--;
        }     
    } 

    cout << "Closest Pair = " << arr1[u] << " " << arr2[v];
}

int main(){
    int arr1[] = {1, 4, 5, 7}; 
    int arr2[] = {10, 20, 30, 40}; 
    int m = sizeof(arr1)/sizeof(arr1[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]);
    int X = 25;

    closestPair(arr1,arr2,m,n,X);
    return 0;
}