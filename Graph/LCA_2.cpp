#include <bits/stdc++.h>
using namespace std;

#define N 100001
#define M 20
vector<int> adjList[N];
int Par[N][M], depth[N];

void dfs(int cur, int par)
{
    depth[cur] = depth[par] + 1;

    Par[cur][0] = par;

    for (int i = 1; i < M; i++)
    {
        Par[cur][i] = Par[Par[cur][i - 1]][i - 1];
    }

    for (auto &x : adjList[cur])
    {
        if (x != par)
        {
            dfs(x, cur);
        }
    }
}

int LCA(int a, int b)
{
    if (a == b)
        return a;

    if (depth[a] < depth[b])
        swap(a, b);

    int diff = depth[a] - depth[b];
    for (int j = M - 1; j >= 0; j--)
    {
        if ((diff >> j) & 1)
        {
            a = Par[a][j];
        }
    }

    for (int j = M - 1; j >= 0; j--)
    {
        if (Par[a][j] != Par[b][j])
        {
            a = Par[a][j];
            b = Par[b][j];
        }
    }

    // Par[b][0];
    return Par[a][0];
}

int32_t main()
{
    int n;
    cin >> n;

    int x, y;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    dfs(1, 0);

    cout << LCA(8, 9) << endl;
    cout << LCA(4, 9) << endl;
    cout << LCA(11, 9) << endl;
    cout << LCA(8, 11) << endl;

    return 0;
}