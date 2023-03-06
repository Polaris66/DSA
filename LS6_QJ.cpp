#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
	string sequence;
	cin>>sequence;	
	
	stack<char> open;
	int ans = 0;
	for(int i = 0; i < sequence.size(); i++){
		if(sequence[i]=='('){
			open.push('(');
		}
		else{
			if(!open.empty()){
				open.pop();
			}
			else{
				ans++;
			}
		}
	}
	while(!open.empty()){
		ans++;
		open.pop();
	}
	cout<<ans<<endl;
}
