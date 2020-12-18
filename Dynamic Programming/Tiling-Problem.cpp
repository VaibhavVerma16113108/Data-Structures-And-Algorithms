// Given a grid of size 2xN, find the total number of ways to fill the grid using dominos of size 1x2 or 2x1.
#include <iostream>
#include <vector>
using namespace std;

long long dp[1000001];
int mod = 1e9 + 7;

void init()
{
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= 1000001; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod; // If the last block is vertical, we solve a subproblem of size n-1. If the last block is horizontal, we solve a subproblem of size n-2. Draw diagram for clear understanding.
    }
}
int main()
{
    init();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}