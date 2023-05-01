#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <set>

using namespace std;

int main(){
    int n, k;
    cin>>n>>k;

    vector<int> a(n);
    vector<int> b(n);

    for(int i = 0; i < n; i++){
        cin>>a[i];
    }

    for(int i = 0; i < n; i++){
        cin>>b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    priority_queue<pair<int,pair<int,int>>> max_heap;

    set<pair<int,int>> indexes;

    max_heap.push({a[n-1]+b[n-1],{n-1,n-1}});
    indexes.insert({n-1,n-1});

    vector<int> res;

    while(k--){
        auto best_pair = max_heap.top();
        res.push_back(best_pair.first);
        max_heap.pop();

        int a_index = best_pair.second.first;
        int b_index = best_pair.second.second;

        if(a_index-1>=0 && !indexes.count({a_index-1,b_index})){
            max_heap.push({a[a_index-1]+b[b_index],{a_index-1,b_index}});
            indexes.insert({a_index-1,b_index});
        }

        if(b_index-1>=0 && !indexes.count({a_index,b_index-1})){
            max_heap.push({a[a_index]+b[b_index-1],{a_index,b_index-1}});
            indexes.insert({a_index,b_index-1});
        }
    }

    for(auto it: res){
        cout<<it<<" ";
    }
}
