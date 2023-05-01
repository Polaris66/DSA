#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
int main(){
    int n, k;
    cin>>n>>k;

    vector<int> input(n);

    for(auto &x: input){
        cin>>x;
    }

    priority_queue<int> max_chocolates;

    for(int i = 0; i < n; i++){
        max_chocolates.push(input[i]);
    }
    int res = 0;
    while(k--){
        int max = max_chocolates.top();
        res+=ceil((float)max/2);
        max_chocolates.pop();
        max_chocolates.push(max-ceil((float)max/2));
    }
    cout<<res;
}