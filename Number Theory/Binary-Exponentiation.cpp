#include <iostream>
#include <vector>
using namespace std;
#define ll long long

// Computes a^n in O(logn) time
ll power(ll a, ll n)
{
    ll res = 1;
    while (n > 0)
    {
        if (n % 2)
        {
            res *= a;
            n--;
        }
        else
        {
            a *= a;
            n /= 2;
        }
    }
    return res;
}
int main()
{
    ll a, n;
    cin >> a >> n;
    cout << power(a, n);
    return 0;
}