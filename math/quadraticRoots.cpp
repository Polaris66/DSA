#include <bits/stdc++.h>

using namespace std;

vector<int> quadraticRoots(int a, int b, int c){
	int D = (b*b) - (4*a*c);
	if(D<0){
		return vector<int>({-1});
	}
	return vector<int>({((-b+(int)sqrt(D))/(2*a)),((-b-(int)sqrt(D))/(2*a))});
}

int main(){
	int a, b, c;
	cin>>a>>b>>c;
	vector<int> res;
	res = quadraticRoots(a,b,c);
	
	for(auto x : res){
		cout<<x<<" ";
	}
}
