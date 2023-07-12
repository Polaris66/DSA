#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	if(n==1){
		cout<<1;
		return 0;
	}	
	if(n<4){
		cout<<"NO SOLUTION";
		return 0;
	}
	//3 1 4 2
	deque<int> res;
	res.push_back(3);
	res.push_back(1);
	res.push_back(4);
	res.push_back(2);
	
	
	for(int i = 5; i <= n; i++){
		if(abs(res.front()-i)==1){
			res.push_back(i);
		}
		else{
			res.push_front(i);
		}
	}
	
	for(int i = 0; i < n; i++){
		cout<<res[i]<<" ";
	}
}
