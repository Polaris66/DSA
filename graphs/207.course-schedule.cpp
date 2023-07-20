/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void makeAdjList(vector<vector<int>> &Adj, vector<vector<int>> &prerequisites)
    {   
        for(vector<int> edge: prerequisites){
            int u = edge[0];
            int v = edge[1];
            Adj[u].push_back(v);
        }
    }

    bool noCycle(int vertex, vector<vector<int>> &Adj, vector<bool> &Visited, vector<bool> &pathVisited)
    {
        Visited[vertex] = true;
        pathVisited[vertex] = true;
        for(int neighbor: Adj[vertex]){
            if(!Visited[neighbor]){
                if(!noCycle(neighbor, Adj, Visited, pathVisited)){
                    return false;
                }
            }
            else{
                if(pathVisited[neighbor]){
                    return false;
                }
            }
        }

        pathVisited[vertex] = false;
        return true;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> Adj(n, vector<int>());
        makeAdjList(Adj, prerequisites); 

        vector<bool> Visited(n);
        vector<bool> pathVisited(n);
        for(int i = 0; i < n; i++){
            if(!Visited[i]){
                if(!noCycle(i, Adj, Visited, pathVisited)){
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

