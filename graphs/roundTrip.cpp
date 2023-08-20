#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define f first
#define s second
#define pb push_back
#define mp make_pair

int dfs(vector<vector<int>> &Adj, vector<bool> &Vis, int u, vector<int> &prev)
{
    Vis[u] = true;
    for (int v : Adj[u])
    {
        if (Vis[v] && (prev[u] != v))
        {
            prev[v] = u;
            return v;
        }

        if (!Vis[v])
        {
            prev[v] = u;
            int test = dfs(Adj, Vis, v, prev);
            if (test != -1)
            {
                return test;
            }
        }
    }

    return -1;
}

vector<int> solve(int &V, int &E, vector<ii> &edges)
{
    vector<vector<int>> Adj(V, vector<int>());

    for (int i = 0; i < E; i++)
    {
        int u = edges[i].f;
        int v = edges[i].s;

        Adj[u].pb(v);
        Adj[v].pb(u);
    }

    vector<bool> Vis(V, false);
    vector<int> prev(V, -1);
    int test = -1;
    for (int i = 0; i < V; i++)
    {
        if (!Vis[i])
        {
            vector<bool> pathVis(V, false);
            test = dfs(Adj, Vis, i, prev);
            if (test != -1)
            {
                break;
            }
        }
    }

    if (test == -1)
    {
        return {};
    }
    else
    {
        vector<int> res;
        res.push_back(test + 1);
        int temp = prev[test];
        while (temp != test)
        {
            res.push_back(temp + 1);
            temp = prev[temp];
        }

        res.push_back(temp + 1);
        return res;
    }
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

    vector<int> res = solve(V, E, edges);

    if (res.size())
    {
        cout << res.size() << endl;
        for (int i : res)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}