#include <iostream>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, w;
};

int parent[100];

int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unite(int u, int v)
{
    parent[find(u)] = find(v);
}

int main()
{
    int n, e;
    Edge edges[100];

    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < e; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    for (int i = 0; i < n; i++)
        parent[i] = i;

    sort(edges, edges + e, [](Edge a, Edge b)
    {
        return a.w < b.w;
    });

    int cost = 0;

    cout << "Edges in Minimum Spanning Tree:\n";

    for (int i = 0; i < e; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (find(u) != find(v))
        {
            unite(u, v);
            cout << u << " - " << v << " : " << w << endl;
            cost += w;
        }
    }

    cout << "Minimum Cost = " << cost;

    return 0;
}
