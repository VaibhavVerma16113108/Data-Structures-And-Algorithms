// In how many ways can you reach the nth stair from the 0th stair if you're allowed to make a jump of either 1, 2 or 3 steps?
#include <iostream>
#include <vector>
using namespace std;

long long dp[1000001];
int mod = 1e9 + 7;

void init()
{
    dp[0] = 0;
    dp[1] = 1; // There is only one way to reach level 1
    dp[2] = 2; // There are two ways to reach level 2
    dp[3] = 4; // There are 4 ways to reach level 3. These are all base cases.
    for (int i = 4; i <= 1000001; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % mod;
    }
}
int main()
{
    int t;
    cin >> t;
    init();
    while (t--)
    {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }

    return 0;
}