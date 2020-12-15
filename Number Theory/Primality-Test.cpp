#include <iostream>
#include <vector>
using namespace std;

// Checking whether a number is prime in O(sqrt(n)) time
bool isPrime(int n)
{
    if (n == 2)
        return true;
    if (n == 1 or n % 2)
        return false;
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    if (isPrime(n))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}