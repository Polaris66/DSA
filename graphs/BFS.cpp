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

void BFS_helper(int vertex, vector<pair<int, int>> edges, vector<int> &res, unordered_map<int, set<int>> & Adj, vector<bool> &Visited)
{
    queue<int> Queue;
    if(!Visited[vertex]){
        Queue.push(vertex);
        Visited[vertex] = true;
    }

    while(!Queue.empty()){
        int current_node = Queue.front();
        Queue.pop();
        res.push_back(current_node);

        set<int> neighbors = Adj[current_node];
        for(auto neighbor : neighbors){
            if(!Visited[neighbor]){
                Visited[neighbor] = true;
                Queue.push(neighbor);
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> Adj;
    makeAdjList(edges, Adj);
    vector<bool> Visited(vertex, false);
    vector<int> res;

    for (int i = 0; i < vertex; i++)
    {
        if(!Visited[i])
        BFS_helper(i, edges, res, Adj, Visited);
    }

    return res;
}

int main(){
    int V, E;
    cin>>V>>E;

    vector<pair<int, int>> edges(E);
    int u, v;
    for(int i = 0; i < E; i++){
        cin>>u>>v;
        edges[i] = make_pair(u,v);
    }

    vector<int> res = BFS(0, edges);

    for(auto x: res){
        cout<<x<<" ";
    }
}