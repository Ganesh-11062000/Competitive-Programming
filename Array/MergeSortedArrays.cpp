#include<iostream>
#include<vector>
using namespace std;

// arr1[] = {10, 12}
// arr2[] = {5, 18, 20}

void merge(vector<int> &arr1,vector<int> &arr2,int m,int n){
    int i = 0,j = 0;
    while(i < m && j < n){
        if(arr1[i] > arr2[j]){
            swap(arr1[i],arr2[j]);
            i++;
        }else{
            j++;
        }
    }

    for(int x:arr2){
        arr1.push_back(x);
    }
}

int main(){
    int m,n;
    cin >> m >> n;
    vector<int> arr1(m),arr2(n);

    for(int i = 0; i< m;i++){
        cin >> arr1[i];
    }

    for(int i = 0; i< n;i++){
        cin >> arr2[i];
    }
    
    merge(arr1,arr2,m,n);

    for(int x:arr1){
        cout << x << " ";
    }
    

    return 0;
}