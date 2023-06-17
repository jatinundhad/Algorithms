#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

vector<int> gr[N];
int vis[N], path[N];
bool cycle = false;

// for directed graph
void dfs(int cur)
{
    vis[cur] = 1;
    path[cur] = 1;
    for (auto x : gr[cur])
    {
        if (!vis[x])
        {
            dfs(x);
        }
        else if (path[x])
        {
            cycle = true;
        }
    }

    path[cur] = 0;
}