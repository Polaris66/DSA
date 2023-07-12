#include <bits/stdc++.h>

using namespace std;
int main(){

	string s;
	cin>>s;
	
	int count = 1;
	int maxCount = 1;
	
	int i = 1;
	
	while(i<s.size()){
		if(s[i]==s[i-1]){
			count++;
		}
		else{
			count = 1;
		}
		maxCount = max(count, maxCount);
		i++;
	}
	
	cout<<maxCount;
}
