#include <bits/stdc++.h>
using namespace std;

class DSU
{
    int n;
    vector<int> parent;
    vector<int> rank;

public:
    int connected_comp;
    DSU(int n)
    {
        this->n = n;
        connected_comp = n;
        parent = vector<int>(n, 0);
        rank = vector<int>(n, 0);
        for (int i = 0; i < n; i++)
        {
            this->parent[i] = i;
        }
    }

    int find_set(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = find_set(parent[node]);
    }

    void union_set(int u, int v)
    {
        int a = find_set(u);
        int b = find_set(v);

        if (a != b)
        {
            connected_comp--;

            // b always has smaller rank than a
            if (rank[a] < rank[b])
                swap(a, b);
            this->parent[b] = a;

            if (rank[a] == rank[b])
                rank[a]++;
        }
    }

    bool connected(int x, int y)
    {
        return find_set(x) == find_set(y);
    }
};