#include <iostream>
using namespace std;

class MinStack{
	int *arr;
	int topIndex;
	int *minArr;
	int minIndex;
	public:MinStack(){
		this->arr = new int[1000];
		this->topIndex = -1;
		this->minArr = new int[1000];
		this->minIndex = -1;
	}
	public:void push(int val){
		if(topIndex==-1){
			this->minIndex = 0;
			this->minArr[minIndex] = val;	
		}
		else{
			if(val<=minArr[minIndex]){
				this->minIndex+=1;
				this->minArr[minIndex] = val;
			}
		}
		this->topIndex+=1;
		this->arr[this->topIndex] = val;
	}
	public:void pop(){
		if(this->topIndex==-1){
			printf("Stack Underflow\n");
			return;
		}
		if(this->arr[this->topIndex]==this->minArr[this->minIndex]){
			this->minIndex-=1;
		}
		this->topIndex-=1;
	}
	public:int top(){
		if(this->topIndex!=-1)
		return arr[this->topIndex];
		printf("Stack Underflow\n");
		return 0;
	}
	public:int getMin(){
		if(this->minIndex!=-1)
		return this->minArr[this->minIndex];
		printf("Stack Underflow\n");
		return 0;
	}
	public:void print(){
		for(int i = this->topIndex; i>=0; i--){
			printf("%d ", this->arr[i]);
		}	
		printf("\n");
	}	
};

int main(){
	
	MinStack s = MinStack();
	
	int n;
	scanf("%d",&n);
	
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d",&val);
		
		s.push(val);
	}		
	int m;
	scanf("%d",&m);
	while(m--)
	{
		int operation;
		scanf("%d",&operation);
		
		switch(operation){
			case(1):
			int value;
			scanf("%d",&value);
			s.push(value);
			break;
			case(2):
			s.pop();
			break;
			case(3):
			printf("%d\n",s.top());
			break;
			case(4):
			printf("%d\n",s.getMin());
			break;						
		}
	}
}


