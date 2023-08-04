#include <stdio.h>

void print(int *arr, int n){
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int search(int *arr, int n, int val){
	int idx = 0;
	for(int i = 0; i < n; i++){
		if(val == arr[i]){
			idx = i;
			break;
		}
	}
	return idx;
}

int main(){
	int n,k;
	scanf("%d %d",&k,&n);
	int val = (k+1)/2;
	int arr[n];
	int l = 0;
	int r = 0;
	for(int i = 0; i < n; i++){
		scanf("%d",&arr[i]);
	}
	int idx = search(arr,n,val);
	for(int i = 0; i < n; i++){
		idx = search(arr,n,val);
		if((arr[i]>val) && (i<idx)){
			int target = (idx+r);
			for(int j = i; j < target; j++){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
			r+=1;
			i-=1;
		}
		else if((arr[i]<val) && (i>idx)){
			int target = (idx);
			for(int j = i; j > target; j--){
				int temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
	}
	print(arr,n);
}
