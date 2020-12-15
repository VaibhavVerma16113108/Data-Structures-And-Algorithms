// Problem link: https://www.spoj.com/problems/PT07Z/
// The longest path between any two nodes of a tree is called its diameter.
// Algorithm: Run a DFS on any arbitrary node and find the farthest node from it.
// Now run a DFS from this farthest node. The path from this node to its farthest node is the diameter of the tree.
#include <iostream>
#include <vector>
using namespace std;

vector<int> ar[10001];
int vis[10001];
int maxDistance, maxNode;
void dfs(int node, int dist)
{
    vis[node] = 1;
    if (dist > maxDistance)
    {
        maxDistance = dist;
        maxNode = node;
    }
    for (int child : ar[node])
    {
        if (!vis[child])
        {
            dfs(child, dist + 1);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        ar[u].push_back(v);
        ar[v].push_back(u);
    }
    maxDistance = -1;
    dfs(1, 0);

    for (int i = 1; i <= n; i++)
        vis[i] = 0;
    maxDistance = -1;
    dfs(maxNode, 0);

    cout << maxDistance << endl;
    return 0;
}