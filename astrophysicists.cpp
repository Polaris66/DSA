#include <iostream>
#include <math.h>

using namespace std;

int main(){
 
	int t;
	scanf("%d",&t);
	
	for(int i = 0; i < t; i++){
		int n, k, g;
		scanf("%d",&n);
		scanf("%d",&k);
		scanf("%d",&g);
		int half = ceil((float)g/2);
		while(k>=-1){
			int prod = k*g;
			if(ceil((float)prod/n)<half){
				printf("%d\n",prod);
				break;
			}
			k--;
		}
	}
}
