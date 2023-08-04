#include <stdio.h>

int check_prime(int n){
	int f = 0;
	for(int i = 1; i <=n; i++){
		if((n%i)==0){
			f+=1;
		}
	}
	if(f==2){
		return 1;
	}
	else{
		return 0;
	};
}



int main(){
	int a, b;
	scanf("%d",&a);
	scanf("%d",&b);
	
	int ft[10];
	for(int i = 0; i < 10; i++){
		ft[i] = 0;
	}
	
	for(int i = a; i <= b; i++){
		if(check_prime(i)){
			int prime = i;
			while(prime){
				int digit = prime%10;
				ft[digit]+=1;
				prime = prime/10;
			}
		}
	}
	
	int max = ft[0];
	int idx = 0;
	for(int i = 0; i < 10; i++){
		if(ft[i]>max){
			max = ft[i];
			idx = i;
		}
	}
	printf("%d %d",idx,max);
}
