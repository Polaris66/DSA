#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<ll, ll>

vector<ll> solve(int V, int E, vector<vector<int>> &edges)
{
    vector<ll> res(V, LONG_LONG_MAX);
    res[0] = 0;

    vector<vector<ii>> Adj(V, vector<ii>());

    for (int i = 0; i < E; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        Adj[u].push_back({v, w});
    }

    set<ii> S;
    S.insert({0, 0});

    while (!S.empty())
    {
        ii it = *(S.begin());
        S.erase(it);

        ll val = it.first;
        ll u = it.second;

        for (auto v : Adj[u])
        {
            ll w = v.second;
            ll nei = v.first;

            if (val + w < res[nei])
            {
                if (res[nei] != LONG_LONG_MAX)
                {
                    S.erase({res[nei], nei});
                }
                res[nei] = val + w;
                S.insert({val + w, nei});
            }
        }
    }

    return res;
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(3));

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u - 1, v - 1, w};
    }

    vector<ll> res = solve(V, E, edges);

    for (ll i : res)
    {
        cout << i << ' ';
    }
    cout << endl;
}