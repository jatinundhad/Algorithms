#include <bits/stdc++.h>
using namespace std;

#define N 100001
vector<int> adjList[N];
int Par[N], depth[N];

void dfs(int cur, int par)
{
    Par[cur] = par;
    depth[cur] = depth[par] + 1;

    for (auto &x : adjList[cur])
    {
        if (x != par)
        {
            dfs(x, cur);
        }
    }
}

// two pointer approach
int LCA(int u, int v)
{
    if (u == v)
        return u;

    if (depth[u] < depth[v])
        swap(u, v);
    // node u alway contains the higher depth node

    int diff = depth[u] - depth[v];
    while (diff--)
    {
        u = Par[u];
    }

    while (u != v)
    {
        u = Par[u];
        v = Par[v];
    }

    return u;
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

    // for(int i = 1; i<=n; i++){
    // 	cout << i << " " << depth[i] << endl;
    // }

    cout << LCA(8, 9) << endl;
    cout << LCA(4, 9) << endl;

    return 0;
}