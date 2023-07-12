#include <bits/stdc++.h>

using namespace std;
int main(){
	long long int n;
	cin>>n;
	
	long long int a[n];
	for(long long int i = 0; i < n; i++){
		cin>>a[i];
	}
	
	long long int res = 0;
	for(long long int i = 1; i < n; i++){
		long long int dif = max(0ll, a[i-1]-a[i]);
		res += dif;
		a[i] += dif;
	}
	cout<<res;
}
