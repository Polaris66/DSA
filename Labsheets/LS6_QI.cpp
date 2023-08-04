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
			if(absPath[i] == '.'){
				if(i+1<n && absPath[i+1]=='.'){
					dirs.pop();
					i++;
				}
				else{
					temp.clear();	
				}
			}
			else{
				temp.push_back(absPath[i]);
			}
		}
	}
	if(!temp.empty()){
		dirs.push(temp);
		temp.clear();
	}
	stack<string> newdirs;
	while(!dirs.empty()){
		newdirs.push(dirs.top());
		dirs.pop();
	}
	if(newdirs.empty()){
		cout<<'/';
	}
	while(!newdirs.empty()){
		cout<<'/'<<newdirs.top();
		newdirs.pop();
	}
	cout<<endl;
}
