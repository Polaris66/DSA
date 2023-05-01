#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, w;
    cin>>n>>w;

    vector<int> wt(n);
    for(auto &x: wt){
        cin>>x;
    }
    vector<int> v(n);
    for(auto &x: v){
        cin>>x;
    }
}