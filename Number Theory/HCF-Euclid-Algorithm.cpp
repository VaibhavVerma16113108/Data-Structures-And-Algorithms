#include <iostream>
#include <vector>
using namespace std;
#define ll long long

// Computes HCF of two numbers a and b in O(logb) time
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    ll a, b;
    cin >> a >> b;
    cout << gcd(a, b);
    return 0;
}