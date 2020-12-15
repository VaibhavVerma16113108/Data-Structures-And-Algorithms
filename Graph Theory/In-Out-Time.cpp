// Can be used to solve the problem: "Determine if one node lies in the subtree of another node".
// If one node, say A, lies in the subtree of another node, say B, then the in time of A would be greater than that of B, and the out time of A would be lesser than that of B.
#include <iostream>
#include <vector>
using namespace std;

vector<int> ar[10001];
int vis[10001];
int intime[10001];
int outtime[10001];
int timer = 1;
void dfs(int v)
{
    vis[v] = 1;
    intime[v] = timer++;

    for (int child : ar[v])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
    outtime[v] = timer++;
}

int main()
{
    return 0;
}