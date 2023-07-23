#include <bits/stdc++.h>

using namespace std;

set<int> p(int *arr, int q){
	
	set<int> s;
	
	int a = arr[2*(q-1)];
	int b = arr[2*(q)-1];
	
	if(a!=0 && b!=0){
		for(auto x: p(arr,a)){
			s.insert(x);
		}
		
		for(auto x: p(arr,b)){
			s.insert(x);
		}
	}
	
	else if(a!=0){
		for(auto x: p(arr,a)){
			s.insert(x);
		}
	}
	
	else if(b!=0){
		for(auto x: p(arr,b)){
			s.insert(x);
		}
	}
	else{
		s.insert(q);
	
	}
	
	return s;
}

void printArray(int *arr, int n){
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;

		int arr[2*n];
		
		for(int i = 0; i < 2*n; i++){
			arr[i] = 0;
		}
		
		for(int i = 0; i < n-1; i++){
			int a, b;
			cin>>a;
			cin>>b;
			
			int smaller = min(a,b);
			int bigger = max(a,b);
			
			if(arr[2*(smaller-1)]==0){
				arr[2*(smaller-1)] = bigger;
			}
			else{
				arr[2*(smaller)-1] = bigger;
			}
		}
		
		int q;
		cin>>q;
		
		while(q--){
			int c;
			int d;
			cin>>c;
			cin>>d;
			
			cout<<(p(arr,c).size())*(p(arr,d).size())<<endl;
		}
	}
}
