#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
#define mp make_pair
#define f first
#define s second

char a[1000][1000];
bool Vis[1000][1000];
int path[1000][1000];

int dirx[] = {0, 1, -1, 0};
int diry[] = {1, 0, 0, -1};
string dir = "RDUL";

int main()
{
    int m, n;
    cin >> m >> n;

    ii A;
    ii B;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];

            if (a[i][j] == 'A')
            {
                A = mp(i, j);
            }

            if (a[i][j] == 'B')
            {
                B = mp(i, j);
            }
        }
    }

    queue<ii> Q;
    Q.push(A);
    Vis[A.f][A.s] = true;

    while (!Q.empty())
    {
        ii u = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            ii v = mp(u.f + dirx[i], u.s + diry[i]);
            if (v.f < 0 || v.s < 0 || v.f >= m || v.s >= n)
                continue;
            if (a[v.f][v.s] == '#')
                continue;
            if (Vis[v.f][v.s])
                continue;
            Vis[v.f][v.s] = true;
            Q.push(v);
            path[v.f][v.s] = i;
        }
    }

    if (Vis[B.f][B.s])
    {
        string s = "";
        while (B != A)
        {
            int i = path[B.f][B.s];
            s += dir[i];
            B = mp(B.f - dirx[i], B.s - diry[i]);
        }

        reverse(s.begin(), s.end());

        cout << "YES" << endl;
        cout << s.size() << endl;
        cout << s << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}