#include <bits/stdc++.h>
using namespace std;

int recursion(int n){
    if(n==1){
        return 2;
    }
    return 4* recursion(n-1);
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        cout<<recursion(n)<<endl;
    }
}