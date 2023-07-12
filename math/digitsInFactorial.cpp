#define ull unsigned long long 
#include <bits/stdc++.h>

using namespace std;

int digitsInFactorial(int n){
	double sum = 0;
	
	for(double i = 1; i <= n; i++){
		sum+= log10(i);
	}
	
	return floor(sum+1);
}

int main(){
	int n;
	cin>>n;
	cout<<digitsInFactorial(n);
}
