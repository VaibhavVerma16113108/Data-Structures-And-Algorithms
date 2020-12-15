#include <iostream>
#include <vector>
using namespace std;

// O(sqrt(n)) algorithm to prime factorise a number.
void primeFactorise(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int count = 0;
            while (n % i == 0)
            {
                count++;
                n /= i;
            }
            cout << i << " ^ " << count << endl;
        }
        if (n > 1)
        {
            cout << n << " ^ " << 1 << endl;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    primeFactorise(n);
    return 0;
}