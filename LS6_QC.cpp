#include <iostream>
#include <stack>

using namespace std;

int main(){
	int n;
	cin>>n;
	
	int arr[n];
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	
	int ps[n];
	int ns[n];
	
	stack<int> s;
	
	for(int i = 0; i < n; i++){
		while(!s.empty() && arr[s.top()]>=arr[i]){
			s.pop();
		}
		if(s.empty()){
			ps[i] = -1;
		}
		else{
			ps[i] = s.top();
		}
		
		s.push(i);
	}
	while(!s.empty()){
		s.pop();
	}	
	for(int i = n-1; i > -1; i--){
		while(!s.empty() && arr[s.top()]>=arr[i]){
			s.pop();
		}
		if(s.empty()){
			ns[i] = n;
		}
		else{
			ns[i] = s.top();
		}
		
		s.push(i);
	}
	
	int maxArea = -1;
	
	for(int i = 0; i < n; i++){
		int area = (ns[i]-ps[i]-1)*arr[i];
		maxArea = max(area,maxArea);
	}
	cout<<maxArea<<endl;
}
