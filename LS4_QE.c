#include <stdio.h>

int gcd(int a, int b){
	if(a==0){
		return b;
	}
	return gcd(b%a,a);
}

int main(){
	int a, b;
	scanf("%d",&a);
	scanf("%d",&b);
	int max = -1;
	for(int i = 1; i*i<=a; i++){
		if(a%i==0){
			int x = i;
			int y = a/i;
			if(gcd(x,b)==1){
				if(x>max){
					max = x;
				}
			}
			if(gcd(y,b)==1){
				if(y>max){
					max = y;
				}
			}
		}
	}
	
	printf("%d\n",max);
}
