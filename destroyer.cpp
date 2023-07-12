#include <bits/stdc++.h>

using namespace std;
int main(){
	int t;
	cin>>t;
	
	vector<string> res;
	while(t--){
		int n;
		cin>>n;
		
		map<int, int> ft;
		int maximum = 0;
		for(int i = 0; i < n; i++){
			int x;
			cin>>x;
			ft[x]++;
			maximum = max(maximum,x);
		}
		
		string ans = "YES";
		for(int i = 0; i < maximum; i++){
			if(ft[i] < ft[i+1]){
				ans = "NO";
				break;
			}
		}
		
		res.push_back(ans);
		
	}
	
	for(auto x: res){
		cout<<x<<endl;
	}
}


