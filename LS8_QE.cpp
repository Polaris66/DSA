#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main(){
    int n, m, k;
    cin>>n>>m>>k;
    
    vector<int> inp(n);
    map<int,int> ft;
    set<int> possible;
    for(auto &x : inp){
        cin>>x;
    }

    vector<int> res;

    for(int i = 0; i < m; i++){
        ft[inp[i]]++;
        if(ft[inp[i]]==k){
            possible.insert(inp[i]);
        }
        if(ft[inp[i]]==k+1){
            possible.erase(inp[i]);
        }
    }

    if(!possible.empty()){
        res.push_back(*possible.rbegin());
    }
    else{
        res.push_back(-1);
    }

    for(int i = m; i < n; i++){
        ft[inp[i-m]]--;
        if(ft[inp[i-m]]==k){
            possible.insert(inp[i-m]);
        }
        if(ft[inp[i-m]]==k-1){
            possible.erase(inp[i-m]);
        }

        ft[inp[i]]++;
        if(ft[inp[i]]==k){
            possible.insert(inp[i]);
        }
        if(ft[inp[i]]==k+1){
            possible.erase(inp[i]);
        }

        if(!possible.empty()){
            res.push_back(*possible.rbegin());
        }
        else{
            res.push_back(-1);
        }
    }

    for(auto i:res){
        cout<<i<<endl;
    }
}

