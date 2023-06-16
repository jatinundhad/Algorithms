#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include <debug.txt>
#endif
#define int long long int
#define endl "\n"
#define JBU ios_base::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

void merge(vector<int> &a, int s, int mid, int e)
{
    vector<int> helper;
    int i = s, j = mid + 1;

    while (i <= mid and j <= e)
    {
        if (a[i] > a[j])
        {
            helper.push_back(a[j++]);
        }
        else
        {
            helper.push_back(a[i++]);
        }
    }

    while (i <= mid)
    {
        helper.push_back(a[i++]);
    }

    while (j <= e)
    {
        helper.push_back(a[j++]);
    }

    for (i = s; i <= e; i++)
    {
        a[i] = helper[i - s];
    }
}

void mergeSort(vector<int> &a, int s, int e)
{
    if (s < e)
    {
        int mid = (s + e) / 2;
        mergeSort(a, s, mid);
        mergeSort(a, mid + 1, e);
        merge(a, s, mid, e);
    }
}

void solve()
{
    vector<int> a = {5, 4, 3, 2, 1};
    int n = 5;

    mergeSort(a, 0, n - 1);
    dg(a);
}

int32_t main()
{
    JBU;
    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}