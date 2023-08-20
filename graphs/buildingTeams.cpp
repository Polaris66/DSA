#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define f first
#define s second
#define pb push_back
#define mp make_pair

bool dfs(vector<vector<int>> &Adj, vector<int> &Vis, int u)
{
    bool res = true;

    for (int v : Adj[u])
    {
        if (!Vis[v])
        {
            Vis[v] = -Vis[u];
            res &= dfs(Adj, Vis, v);
        }
        else
        {
            if (Vis[v] == Vis[u])
            {
                return false;
            }
        }
    }

    return res;
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

    vector<int> Vis(V, 0);

    bool res = true;
    for (int i = 0; i < V; i++)
    {
        if (!Vis[i])
        {
            Vis[i] = 1;
            res &= dfs(Adj, Vis, i);
        }
    }

    if (res)
    {
        vector<int> ans(V);
        for (int i = 0; i < V; i++)
        {
            if (Vis[i] == 1)
            {
                ans[i] = 1;
            }
            else
            {
                ans[i] = 2;
            }
        }

        return ans;
    }
    else
    {
        return {};
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

    if (!res.size())
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for (int i : res)
    {
        cout << i << ' ';
    }
    cout << endl;
}