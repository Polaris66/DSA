#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
	string absPath;
	cin>>absPath;

	stack<string> dirs;
	int n = absPath.size();
	string temp = "";
	for(int i = 0; i < n; i++){
		if(absPath[i]=='/'){
			if(!temp.empty()){
				dirs.push(temp);
				temp.clear();
			}
		}
		else{
			temp.push_back(absPath[i]);
		}
	}
	if(!temp.empty()){
		dirs.push(temp);
		temp.clear();
	}
	cout<<endl;
}
