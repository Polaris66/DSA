#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define f first
#define s second
#define mp make_pair

vector<int> solve(int &V, int &E, vector<ii> &edges)
{
    vector<vector<int>> Adj(V, vector<int>());

    for (int i = 0; i < E; i++)
    {
        int u = edges[i].f;
        int v = edges[i].s;

        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }

    vector<bool> Vis(V, false);
    queue<int> Q;
    Q.push(0);
    Vis[0] = true;

    vector<int> prev(V);

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int v : Adj[u])
        {
            if (!Vis[v])
            {
                Vis[v] = true;
                Q.push(v);
                prev[v] = u;
            }
        }
    }

    vector<int> res;

    if (!Vis[V - 1])
    {
        return res;
    }

    int end = V - 1;
    while (end != 0)
    {
        res.push_back(end + 1);
        end = prev[end];
    }

    res.push_back(1);
    reverse(res.begin(), res.end());

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
        cout << "IMPOSSIBLE";
    }
}