#include <bits/stdc++.h>
using namespace std;

const int N = 1e5, M = 20;

vector<int> adj[N];
int Par[N][M], tin[N], tout[N], timer = 0;

// O(N*M)
void dfs(int cur, int par)
{

    tin[cur] = ++timer;

    Par[cur][0] = par;
    for (int j = 1; j < M; j++)
    {
        Par[cur][j] = Par[Par[cur][j - 1]][j - 1];
    }

    for (auto x : adj[cur])
    {
        if (x != par)
        {
            dfs(x, cur);
        }
    }

    tout[cur] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

// O(M) = logN
int LCA(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;

    for (int i = M - 1; i >= 0; --i)
    {
        if (!is_ancestor(Par[u][i], v))
            u = Par[u][i];
    }

    return Par[u][0];
}

void preprocess()
{
    dfs(1, 1);
}