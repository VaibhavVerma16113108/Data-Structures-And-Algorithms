#include <iostream>
#include <vector>
using namespace std;

int arr[1000001];

void sieve()
{
    const int MAX = 1e6;

    for (int i = 1; i <= MAX; i++)
        arr[i] = -1;

    for (int i = 2; i <= MAX; i++)
    {
        if (arr[i] == -1)
        {
            for (int j = i; j <= MAX; j += i)
            {
                if (arr[j] == -1)
                    arr[j] = i;
            }
        }
    }
}
int main()
{
    return 0;
}