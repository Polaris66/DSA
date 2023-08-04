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
	stack<int> elements;
	stack<int> indices;
	
	int res[n];
	
	for(int i = 0; i < n; i++){
		res[i] = -1;;
	}
	
	for(int i = 0; i < n; i++){
		while(!elements.empty() && elements.top()<arr[i]){
			res[indices.top()] = i - indices.top();
			elements.pop();
			indices.pop();
		}
		elements.push(arr[i]);
		indices.push(i);
	}
	
	for(int i = 0; i < n; i++){
		if(!elements.empty() && elements.top()<arr[i]){
			while(!elements.empty() && elements.top()<arr[i]){
				res[indices.top()] = i - indices.top()+5;
				elements.pop();
				indices.pop();
			}
		}
	}
	
	for(auto i:res){
		cout<<i<<" ";
	}
	cout<<endl;
}
