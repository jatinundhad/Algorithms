#include <bits/stdc++.h>
using namespace std;

// for sorted array
// gives the -1: if key is not present
// gives index of given key
int binarySearch(vector<int> &v, int key)
{
    int s = 0, e = v.size() - 1, mid;

    while (s <= e)
    {
        mid = s - (s - e) / 2;
        if (key == v[mid])
        {
            return mid;
        }
        else if (key > v[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    return -1;
}