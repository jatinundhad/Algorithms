#include <bits/stdc++.h>
using namespace std;

// for sorted array
// gives the -1: if key is not present
// gives last index of given key
int upper_bound(vector<int> &v, int key)
{
    int n = v.size() - 1;

    int l = 0;
    int r = n;

    int ans = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;

        if (v[mid] == key)
        {
            ans = mid;
            l = mid + 1;
        }
        else if (v[mid] > key)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return ans;
}