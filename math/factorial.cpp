#include <bits/stdc++.h>

using namespace std;

unsigned long long int factorial(unsigned long long int N){
	if(N==1){
		return 1;
	}
	return N*factorial(N-1);
}

int main(){
	int N;
	cin>>N;
	cout<<factorial(N);
}
