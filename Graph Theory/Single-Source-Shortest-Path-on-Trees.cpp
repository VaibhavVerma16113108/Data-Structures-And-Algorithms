// Problem link: https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/
#include <iostream>
#include <vector>

using namespace std;

vector<int> ar[100001];
int visited[100001] = {0};
int arrdistance[100001] = {0};

void dfs(int node, int dist)
{
    visited[node] = 1;
    arrdistance[node] = dist;
    for (int child : ar[node])
    {
        if (!visited[child])
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
    dfs(1, 0);
    int q;
    cin >> q;
    int currMin = 1000000, ans = 1000000;
    while (q--)
    {
        int city_girl;
        cin >> city_girl;
        if (arrdistance[city_girl] < currMin)
        {
            currMin = min(arrdistance[city_girl], currMin);
            ans = min(city_girl, ans);
        }
    }
    cout << ans << endl;
    return 0;
}