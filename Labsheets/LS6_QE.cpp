#include <iostream>
#include <deque>
using namespace std;

int main(){
	int n, k;
	cin>>n;
	cin>>k;
	
	int arr[n];
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	
	deque<int> maxPossible;
	
	int i = 0;
	int j = 0;
	while(j<n){
		if(maxPossible.empty()){
			maxPossible.push_back(arr[j]);
		}
		else{
			while(!maxPossible.empty() && arr[j]>maxPossible.back()){
				maxPossible.pop_back();
			}
			maxPossible.push_back(arr[j]);
		}
		if((j-i+1)==k){
			cout<<maxPossible.front()<<" ";
			if(arr[i] == maxPossible.front()){
				maxPossible.pop_front();
			}			
			i++;
			j++;
		}
		else{
			j++;
		}
	}
	cout<<endl;
}
