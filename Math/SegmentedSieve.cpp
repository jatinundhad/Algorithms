#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

vector<int> primes;
void primeSieve()
{
    vector<int> sieve(N, 1);
    // Mark 1 and 0 as not prime
    sieve[0] = sieve[1] = 0;

    for (int i = 2; i <= N; i++)
    {
        if (sieve[i])
        {
            primes.push_back(i);
            for (int j = i * i; j <= N; j = j + i)
            {
                // mark j as not prime
                sieve[j] = 0;
            }
        }
    }
}

void segmented_sieve(int m, int n)
{
    vector<int> arr(n - m + 1, 1);

    for (auto &x : primes)
    {
        // we will only go till the sqrt(n) primes in prime array
        if (x * x > n)
        {
            break;
        }

        // finding the nearest possible multiple of x near to m
        int start = (m / x) * x;

        // if primes array and array are overlapping then we should start marking none prime from 2*x; before this condition
        // start set as a 0 that's why this condition place here
        if (x >= m && x <= n)
        {
            start = x * 2;
        }

        for (int i = start; i <= n; i = i + x)
        {
            // if start is less than the m then we should take it forwad by x step so that our zero based indexing doesn't misslead
            if (i < m)
            {
                continue;
            }

            // marked it as non prime
            arr[i - m] = 0;
        }
    }

    // printing all the primes between range n to m
    for (int i = m; i <= n; i++)
    {
        if (arr[i - m] == 1 && i != 1)
        {
            cout << i << endl;
        }
    }

    cout << endl;
}

void preprocess()
{
    primeSieve();
}