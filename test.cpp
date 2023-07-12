#include <bits/stdc++.h>
 
using namespace std;

int main(){
 
	int t;
	cin>>t;
	
	vector<int> res;
	while(t--){
		double n, k, g;
		cin>>n>>k>>g;
		double half = ceil(g/2);
		while(k>=-1){
			double prod = k*g;
			if(ceil(prod/n)<half){
			
				res.push_back(prod);
				break;
			}
			k--;
		}
	}
	
	for(auto x: res){
		cout<<x<<endl;
	}
 
}
