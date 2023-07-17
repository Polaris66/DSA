#include <bits/stdc++.h>
using namespace std;

void makeAdjList(vector<pair<int, int>> edges, unordered_map<int, set<int>> &Adj)
{
    for(auto edge: edges){
        int u = edge.first;
        int v = edge.second;
        Adj[u].insert(v);
        Adj[v].insert(u);
    }
    // Adj List Done
}

void printAdjList(unordered_map<int, set<int> > &Adj){
    for(auto record: Adj){
        cout<<record.first<<"->";
        for(auto neighbor: record.second){
            cout<<neighbor<<",";
        }
        cout<<endl;
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int> > Adj;
    makeAdjList(edges, Adj);
    printAdjList(Adj);

    return vector<int> ();
}

int main(){
    int v, e;
    cin>>v>>e;

    vector<pair<int, int>> edges(e);
    int u, v;
    for(int i = 0; i < e; i++){
        cin>>u>>v;
        edges[i] = make_pair(u,v);
    }

    vector<int> res = BFS(0, edges);
}