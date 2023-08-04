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
	
	stack<int> st;
	int res[n];
	
	for(int i = 0; i < n; i++){
		while(!st.empty() && arr[st.top()]<=arr[i]){
			st.pop();
		}
		
		res[i] = st.empty() ? (i+1): (i-st.top());
		st.push(i);
	}
	
	for(int i = 0; i < n; i++){
		cout<<res[i]<<" ";
	}
	cout<<endl;
}
