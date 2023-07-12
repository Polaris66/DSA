#include <bits/stdc++.h>
using namespace std;

int recursion(int n, int i){
    if(i>n) return 0;
    if(i==n) return 1;
    return(recursion(n,i+1) + recursion(n,i+2));
}

int main(){
    int n;
    cin>>n;

    cout<<recursion(n,0)<<endl;
}