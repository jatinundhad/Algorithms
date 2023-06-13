#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

vector<int> gr[N];
int vis[N];
bool cycle = false;

void dfs(int cur, int par)
{
    vis[cur] = 1;
    for (auto x : gr[cur])
    {
        if (!vis[x])
        {
            dfs(x, cur);
        }
        else if (x != par)
        {
            cycle = true;
        }
    }
}