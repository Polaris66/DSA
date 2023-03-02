#include <stdio.h>

int main(){
	int n, k;
	scanf("%d",&n);
	scanf("%d",&k);
	char arr[n];
	for(int i = 0; i < n; i++){
		scanf("%c",&arr[i]);
	}
	int ft[k];
	int distinct = 0;
	for(int i = 0; i < k; i++){
		ft[i] = 0;
	}
	int ans = 0;
	int i = 0;
	int j = 0;
	while(j<n){
		if(!ft[arr[j]-97]){
			ft[arr[j]-97]+=1;
			distinct+=1;
		}
		else{
			ft[arr[j]-97]+=1;
		}
		if(distinct==k){
			while(distinct==k){
				ans+=(n-j);
				if(ft[arr[i]-97])
				ft[arr[i]-97]-=1;
				if(ft[arr[i]-97]==0){
					distinct-=1;
				}
				
				i++;
			}
			j++;
		}
		else{
			j++;
		}
	}
	printf("%d\n",ans);
}

// 'a' = 97
