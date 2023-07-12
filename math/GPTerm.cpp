#include <bits/stdc++.h>

using namespace std;

int termOfGP(int A, int B, int N){
	double r = (double)B/(double)A;
	
	return (double)A*pow(r, N-1);
}

int main(){
	int A, B, N;
	cin>>A>>B>>N;
	
	int nthTerm = termOfGP(A,B,N);
	cout<<nthTerm<<endl;
}
