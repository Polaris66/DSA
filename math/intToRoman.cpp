#include <bits/stdc++.h>

using namespace std;

string intToRoman(int num){
	map<int,char> m;
	m[1000] = 'M';
	m[500] = 'D';
	m[100] = 'C';
	m[50] = 'L';
	m[10] = 'X';
	m[5] = 'V';
	m[1] = 'I';
	string res = "";
	for(auto it = m.rbegin(); it!= m.rend(); ++it){
		if(!num){
			break;
		}
		int times = (num/(it->first));
		if(times>0){
			
			for(int i = 0; i < times; i++){
				res.push_back(it->second);
				num-=(it->first);
			}
			
		}
		int smaller_test = (it->first)/10;
		if(smaller_test && (it->first)!= 500 && (it->first)!= 50 && (it->first)!= 5){
			int smaller_times = (num/smaller_test);
			if(smaller_times == 9){
				res.push_back(m[smaller_test]);
				res.push_back(it->second);
				num-= 9*(smaller_test);
			}	
		}
		
		int smallest_test = (it->first)/5;
		if(smallest_test && ((it->first)== 500 || (it->first)== 50 || (it->first)== 5)){
			int smallest_times = (num/smallest_test);
			if(smallest_times == 4){
				res.push_back(m[smallest_test]);
				res.push_back(it->second);
				num-= 4*(smallest_test);
			}	
		}
	}
	
	return res;
}

int main(){
	int n;
	cin>>n;
	
	cout<<intToRoman(n);
}
