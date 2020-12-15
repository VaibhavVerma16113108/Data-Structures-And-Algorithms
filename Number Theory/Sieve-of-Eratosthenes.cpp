#include <iostream>
#include <vector>
using namespace std;

int isPrime[1000001];

// for any i, if isPrime[i] = 0, then the number is not prime.
void sieve()
{
    const int MAX = 1e6;

    for (int i = 1; i <= MAX; i++)
        isPrime[i] = 1;
    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i * i <= MAX; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= MAX; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
}

int main()
{
    sieve();

    for (int i = 1; i <= 100; i++)
    {
        if (isPrime[i])
            cout << i << " ";
    }
    return 0;
}