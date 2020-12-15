// Problem link: https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/
// A connected component is a set of vertices in a graph that are linked to each other by paths.
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
    cout << connectedComponents << endl;
    return 0;
}