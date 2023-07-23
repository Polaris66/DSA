#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	
	while(t--){
		int n, m, h;
		cin>>n>>m>>h;
		
		vector<vector<int>> a;
		
		for(int i = 0; i < n; i++){
			vector<int> b;
			for(int j = 0; j < m; j++){
				int x;
				cin>>x;
				b.push_back(x);
			}
			a.push_back(b);
		}
		
		int probs[n];
		int pens[n];
		for(int i = 0; i < n; i++){
			sort(a[i].begin(), a[i].end());
			int current_time = 0;
			int penalty = 0;
			int prob = 0;	
			for(int j = 0; j < m; i++){
				current_time += a[i][j];
				if(current_time > h) break;
				
				penalty += current_time;
				prob ++;
			}
			probs[i] = prob;
			pens[i] = penalty;
		}
		int myProb = probs[0];
		int myPen = pens[0];
		
		int peopleAbove = 0;
		
		for(int i = 1; i < n; i++){
			if(probs[i] > myProb){
				peopleAbove++;
			}
			else if(probs[i] == myProb && pens[i] < myPen){
				peopleAbove++;
			}
		}
		
		cout<<peopleAbove+1<<endl;
	}
}
