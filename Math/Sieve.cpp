#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

void primeSieve(vector<int> &sieve)
{
    sieve = vector<int>(N, 1);
    // Mark 1 and 0 as not prime
    sieve[0] = sieve[1] = 0;

    for (int i = 2; i <= N; i++)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= N; j = j + i)
            {
                // mark j as not prime
                sieve[j] = 0;
            }
        }
    }
}