#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int u, int v, bool undir = true)
    {
        l[u].push_back(v);
        if (undir)
        {
            l[v].push_back(u);
        }
    }

    void printEdgeList()
    {
        // interate to all nodes
        for (int i = 0; i < V; i++)
        {
            // iterate to each edge
            cout << i << "-> ";
            for (auto &node : l[i])
            {
                cout << node << ",";
            }
            cout << endl;
        }
    }

    void bfs(int source)
    {
        cout << "BFS >> ";
        vector<bool> visited(V, false);
        queue<int> q;

        q.push(source);
        visited[source] = true;

        while (!q.empty())
        {
            int f = q.front();
            q.pop();

            cout << f << " ";
            for (auto nbr : l[f])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }

        cout << endl;
    }

    void dfsHelper(int node, vector<bool> &visited)
    {
        visited[node] = true;

        cout << node << " ";
        for (auto &nbr : l[node])
        {
            if (!visited[nbr])
            {
                dfsHelper(nbr, visited);
            }
        }
    }

    void dfs(int source)
    {
        cout << "DFS >> ";
        vector<bool> visited(V, false);
        dfsHelper(source, visited);
        cout << endl;
    }
};