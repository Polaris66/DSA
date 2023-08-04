#include <iostream>
#include <bits/stdc++.h>

using namespace std;


int main(){
	int m, n;
	cin>>m>>n;
	
	vector<vector<int>> mat(m,vector<int> (n));
	
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin>>mat[i][j];
		}
	}
	
	int target;
	cin>>target;
	
	int x = 0;
	int y = n-1;
	
	while(x<m && y>=0){
		if(mat[x][y]==target){
			cout<<"YES"<<endl;
			return 1;
		}
		else if(mat[x][y]<target){
			x++;
		}
		else{
			y--;
		}
	}	
	cout<<"NO"<<endl;
}
