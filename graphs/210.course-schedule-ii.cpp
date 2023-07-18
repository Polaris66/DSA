/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void makeAdjList(vector<vector<int>> &edges, vector<vector<int>> &Adj)
    {
        for(vector<int> edge: edges){
            int u = edge[0];
            int v = edge[1];
            Adj[v].push_back(u);
        }
    }

    void topoOrder(int vertex, vector<bool> &Visited, vector<bool> pathVisited ,vector<vector<int>> &Adj, stack<int> &S, vector<bool> &isLoop)
    {   
        Visited[vertex] = true;
        pathVisited[vertex] = true;

        for(int neighbor : Adj[vertex]){
            if(!Visited[neighbor]){
                topoOrder(neighbor, Visited, pathVisited, Adj, S, isLoop);
            }
            else{
                if(pathVisited[neighbor]){
                    isLoop[0] = true;
                    return;
                }
            }
        }
        pathVisited[vertex] = false;
        S.push(vertex);
    }

    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> Adj(n, vector<int>());
        makeAdjList(prerequisites, Adj);

        vector<bool> Visited(n, false);
        vector<bool> pathVisited(n, false);
        stack<int> S;
        vector<bool> isLoop(1, false);
        for(int i = 0; i < n; i++){
            if(!Visited[i]){
                topoOrder(i, Visited, pathVisited,Adj, S, isLoop);
                if(isLoop[0]){
                    return vector<int> ();
                }
            }
        }

        vector<int> res;
        while(!S.empty()){
            res.push_back(S.top());
            S.pop();
        }
        return res;
    }
};
// @lc code=end

