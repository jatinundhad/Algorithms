#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

set<int> gr[N];
int vis[N];
vector<int> order;

void topologycalSort(int cur)
{
    vis[cur] = 1;
    for (auto x : gr[cur])
    {
        if (!vis[x])
            topologycalSort(x);
    }
    order.push_back(cur);
}