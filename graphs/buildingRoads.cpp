#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define f first
#define s second
#define mp make_pair

void dfs(vector<vector<int>> &Adj, vector<bool> &Vis, int i)
{
    Vis[i] = true;

    for (int nei : Adj[i])
    {
        if (!Vis[nei])
        {
            dfs(Adj, Vis, nei);
        }
    }
}

vector<int> solve(int V, vector<ii> &edges, int E)
{
    vector<vector<int>> Adj(V, vector<int>());

    for (int i = 0; i < E; i++)
    {
        int u = edges[i].f;
        int v = edges[i].s;

        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    vector<int> res;

    vector<bool> Vis(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!Vis[i])
        {
            res.push_back(i);
            dfs(Adj, Vis, i);
        }
    }

    return res;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<ii> edges(E);
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[i] = mp(u - 1, v - 1);
    }

    vector<int> res = solve(V, edges, E);

    cout << res.size() - 1 << endl;
    if (res.size())
    {
        for (int i = 1; i < res.size(); i++)
        {
            cout << res[i - 1] + 1 << " " << res[i] + 1 << endl;
        }
    }
}