#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n){
	for(int i = 2; i <= floor(sqrt(n)); i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	cin>>n;
	
	cout<<isPrime(n);
}
