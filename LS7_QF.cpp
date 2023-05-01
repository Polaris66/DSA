#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<vector<int>> input(n);
    vector<int> length(n);

    for(int i = 0; i < n; i++){
        cin>>length[i];
        input[i] = vector<int>(length[i]);
        for(int j = 0; j < length[i]; j++){
            cin>>input[i][j];
        }
    }

    multiset<pair<int,int>> pq;
    vector<int> pointer(n,0);
    for(int i = 0; i < n; i++){
        pq.insert({input[i][0],i});
    }

    vector<int> res;
    while(!pq.empty()){
        pair<int,int> smallest = *pq.begin();
        pq.erase(smallest);

        res.push_back(smallest.first);

        int index = smallest.second;
        pointer[index]++;

        if(pointer[index]<length[index]){
            pq.insert({input[index][pointer[index]],index});
        }

    }

    for(auto x: res){
        cout<<x<<" ";
    }

    cout<<endl;
}