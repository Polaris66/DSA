#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct Country_t{
	char name[1000];
	int g;
	int s;
	int b;
} Country;

Country *read(){
	Country *newCountry = (Country *) malloc(sizeof(Country));
	assert(newCountry!=NULL);
	char name[1000];
	int g, s, b;
	scanf("%s",name);
	scanf("%d",&g);
	scanf("%d",&s);
	scanf("%d",&b);		
	for(int j = 0; j < strlen(name); j++){
		newCountry->name[j] = name[j];
	}
		
	newCountry->g = g;
	newCountry->s = s;
	newCountry->b = b;
	
	return newCountry;	
}

void print(Country *country){
	printf("%s %d %d %d\n",country->name,country->g,country->s,country->b);
}

int isGreater(Country *c1, Country *c2){
	if((c1->g)>(c2->g)){
		return 1;
	}
	else if (((c1->g)==(c2->g))){
		if((c1->s)>(c2->s)){
			return 1;
		}	
	}	
		else if (((c1->s)==(c2->s))){
			if((c1->b)>(c2->b)){
				return 1;
			}	
		}
	return 0;
}

void sort(Country **countries, int n){
	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < n-i-1; j++){
			if(isGreater(!countries[j],countries[j])){
				Country *temp = countries[j+1]; 
				countries[j+1] = countries[j];
				countries[j] = temp; 
			}
		}
	}
}

int main(){	
	int n;
	scanf("%d",&n);
	Country *countries[n];
	for(int i = 0; i < n; i++){
		countries[i] = read();
	}
	/*for(int i = 0; i < n; i++){
		print(countries[i]);	
	}*/
	sort(countries,n);
	for(int i = 0; i < n; i++){
		printf("%s\n",countries[i]->name);
	}
}

