#include <bits/stdc++.h>

using namespace std;

int absolute(int I){
	if(I>=0){
		return I;
	}
	else{
		return -1*I;
	}
}

int main(){
	int I;
	cin>>I;
	
	cout<<absolute(I);
}
