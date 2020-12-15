// Problem Link: https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/monk-and-the-islands/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> ar[10001];
int vis[10001];
int dist[10001];

void BFS(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    dist[src] = 0;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int child : ar[curr])
        {
            if (!vis[child])
            {
                q.push(child);
                dist[child] = dist[curr] + 1;
                vis[child] = 1;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            ar[i].clear();
            vis[i] = 0;
        }
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            ar[u].push_back(v);
            ar[v].push_back(u);
        }
        BFS(1);
        cout << dist[n] << endl;
    }
    return 0;
}