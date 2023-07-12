#include <bits/stdc++.h>

using namespace std;

int charToInt(char c){
	return ((int)c-(int)'0');
}

char intToChar(int i){
	return (char)(i+(int)'0');
}
string reverse(string s){
	string res = "";
	for(int i = s.size()-1; i > -1; i--){
	    res.push_back(s[i]);
	}
	return res;
}

string addBinary(string a, string b) {
	int carry = 0;

	int m = a.size();
	int n = b.size();

	string res = "";
	int i = 0;

	int sum;
	while((i < m) && (i < n)){
	    sum = charToInt(a[m-i-1])+ charToInt(b[n-i-1])+carry;
	    res.push_back(intToChar(sum%2));
	    carry = sum/2;
	    i++;
	}
	while(i < m){
	    sum = charToInt(a[m-i-1])+carry;
	    res.push_back(intToChar(sum%2));
	    carry = sum/2;
	    i++;
	}
	while(i < n){
	    sum = charToInt(b[n-i-1])+carry;
	    res.push_back(intToChar(sum%2));
	    carry = sum/2;
	    i++;
	}
	if(carry){
	    res.push_back(intToChar(carry));
	}

	return reverse(res);
}

int main(){
	string a, b;
	cin>>a>>b;
	cout<<addBinary(a,b);
	}
