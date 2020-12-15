// Problem Link: https://www.spoj.com/problems/BUGLIFE/
// a bipartite graph (or bigraph) is a graph whose vertices can be divided into two disjoint and independent sets U and V such that every edge connects a vertex in U to one in V.
#include <iostream>
#include <vector>

using namespace std;

vector<int> ar[2001];
int visited[2001];
int color[2001];

bool dfs(int node, int col)
{
    visited[node] = 1;
    color[node] = col;
    for (int child : ar[node])
    {
        if (!visited[child])
        {
            bool res = dfs(child, col ^ 1);
            if (res == false)
                return false;
        }
        else
        {
            if (color[node] == color[child])
                return false;
        }
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            ar[i].clear();
            visited[i] = 0;
            color[i] = 0;
        }
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            ar[u].push_back(v);
            ar[v].push_back(u);
        }
        bool flag = true;

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                bool res = dfs(i, 0);
                if (res == false)
                    flag = false;
            }
        }
        cout << "Scenario #" << tc << ":" << endl;
        if (flag == false)
        {
            cout << "Suspicious bugs found!" << endl;
        }
        else
        {
            cout << "No suspicious bugs found!" << endl;
        }
    }
}