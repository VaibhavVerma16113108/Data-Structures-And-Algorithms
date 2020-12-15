// Problem Link: https://www.spoj.com/problems/PT07Y/
// To check whether a graph is a tree, we need to check two things:
// 1. Number of connected components = 1
// 2. Number of edges = number of vertices - 1
#include <iostream>
#include <vector>

using namespace std;

vector<int> ar[100001]; // adjacency list representation
int visited[100001];    // visited array

void dfs(int node)
{
    visited[node] = 1;
    for (int child : ar[node])
    {
        if (!visited[child])
        {
            dfs(child);
        }
    }
}

int main()
{
    int n, m; // n = number of vertices, m = number of edges
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        ar[u].push_back(v);
        ar[v].push_back(u);
    }
    int connectedComponents = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            connectedComponents++;
        }
    }
    if (connectedComponents == 1 && m == n - 1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}