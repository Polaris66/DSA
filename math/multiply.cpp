#include <bits/stdc++.h>

using namespace std;

int charToInt(char c){
	return (int) c - 48;
}

char intToChar(int c){
	return (char)(c+48);
}

string reverse(string s){
	string res = "";
	for(int i = s.size()-1; i > -1; i--){
		res.push_back(s[i]);
	}
	return res;
}

string multiply(string num1, string num2){
	string res = "";
	int m = num1.size();
	int n = num2.size();
	
	unsigned long long int sum = 0;
	for(int i = n-1; i > -1; i--){
		for(int j = m - 1; j > -1; j--){
			sum += charToInt(num2[i]) * charToInt(num1[j]) * pow(10,m-j-1);
		cout<<sum;
		}
		
		res.push_back(intToChar(sum%10));
		sum/=10;
	}
	
	while(sum>0){
		res.push_back(intToChar(sum%10));
		sum/=10;
	}
	
	
	while(res.size()>1 && res[res.size()-1]=='0'){
		res.pop_back();
	}
	
	if(res==""){
		res.push_back('0');
	}
	
	return reverse(res);
}

int main(){
	string a, b;
	cin>>a>>b;
	cout<<multiply(a,b);
}
