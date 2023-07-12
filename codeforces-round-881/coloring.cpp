#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	
	while(t--){
		int n;
		scanf("%d",&n);
		
		vector<int> a;
		for(int i = 0; i < n; i++){
			int x;
			scanf("%d",&x);
			a.push_back(x);
		}
		
		sort(a.begin(),a.end());
		
		int sum_a = 0;
		int sum_b = 0;
		
		int half = n/2;
		for(int i = 0; i < half; i++){
			sum_a+=a[i];
		}
		
		for(int i = 0; i < half; i++){
			sum_b+=a[n-i-1];
		}
		
		printf("%d\n",sum_b-sum_a);
	}
}
