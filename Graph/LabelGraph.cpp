#include <bits/stdc++.h>
using namespace std;

struct node
{
    string name;
    vector<string> nbrs;

    node(string name)
    {
        this->name = name;
    }
};

class labelGraph
{
    int n;
    map<string, node *> m;

public:
    labelGraph(int n)
    {
        this->n = n;
    }

    void addEdge(string x, string y, bool undir = true)
    {
        if (m.find(x) == m.end())
            this->m[x] = new node(x);
        this->m[x]->nbrs.push_back(y);
    }

    void printEdgeList()
    {
        for (auto &p : m)
        {
            cout << p.first << "-->";
            for (auto &x : p.second->nbrs)
            {
                cout << x << ", ";
            }
            cout << endl;
        }
    }

    void bfs(string source)
    {
        map<string, bool> visited;
        queue<string> q;

        q.push(source);
        visited[source] = true;

        while (!q.empty())
        {
            string f = q.front();
            q.pop();

            if (m[f] == nullptr)
                continue;

            for (auto nbr : m[f]->nbrs)
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }

    void dfsHelper(string node, map<string, bool> &visited)
    {
        visited[node] = true;

        if (m[node] == nullptr)
            return;

        for (auto &nbr : m[node]->nbrs)
        {
            if (!visited[nbr])
            {
                dfsHelper(nbr, visited);
            }
        }
    }

    void dfs(string source)
    {
        map<string, bool> visited;
        dfsHelper(source, visited);
    }
};