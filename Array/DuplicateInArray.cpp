#include<iostream>
#include<set>
using namespace std;

int findDuplicate(int arr[],int n)
{
    set<int> s;

    for(int i = 0;i < n;i++)
    {
        if(s.find(arr[i]) != s.end())
        {
            return arr[i];
        }
        s.insert(arr[i]);
    }
    return -1;
}

int main(){
    int arr[] = {1,2,3,4,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << findDuplicate(arr,n);    
    return 0;
}