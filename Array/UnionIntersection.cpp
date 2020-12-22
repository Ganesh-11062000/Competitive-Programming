#include<iostream>
#include<set>
using namespace std;

void unionIntersection(int a[],int b[],int m,int n){
    set<int> U,I;

    for(int i = 0;i < m;i++){
        U.insert(a[i]);
    }

    for(int i=0;i < n;i++){
        if(U.find(b[i]) == U.end()){
            U.insert(b[i]);
        }else{
            I.insert(b[i]);
        }
    }

    for(auto x = U.begin(); x != U.end(); x++){
        cout << *x << " ";
    }
    cout << endl;

    for(auto x = I.begin(); x != I.end(); x++){
        cout << *x << " ";
    }
    cout << endl;

}

int main(){
    int a[] = {85,25,1,32,54,6};
    int b[] = {85,2};

    int m = sizeof(a)/sizeof(a[0]);
    int n = sizeof(b)/sizeof(b[0]);

    unionIntersection(a,b,m,n);
    
    return 0;
}