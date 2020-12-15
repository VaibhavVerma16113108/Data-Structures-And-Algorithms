// If we find a "back edge", that means that a cycle exists in the graph
#include <iostream>
#include <vector>

using namespace std;
vector<int> ar[10001];
int vis[10001];

// Function returns true if a cycle is found in the graph.
bool dfs(int node, int par)
{
    vis[node] = 1;
    for (int child : ar[node])
    {
        if (!vis[child])
        {
            if (dfs(child, node) == true)
            {
                return true;
            }
        }
        else
        {
            if (child != par)
                return true;
        }
    }
    return false;
}

int main()
{
    return 0;
}