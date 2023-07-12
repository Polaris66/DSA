#define ll long long 

#include <bits/stdc++.h>

using namespace std;
int main(){
	ll int n;
	cin>>n;
	
	ll int x = 0;
	ll int d = 5;
	while(n/d){
		x+=n/d;
		d*=5;
	}
	cout<<x;
}
