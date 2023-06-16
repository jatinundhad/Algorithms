#include <bits/stdc++.h>
using namespace std;

struct Mat
{
    int sz = 2;
    vector<vector<int>> m;
    int mod = 1e9 + 7;

    Mat(int n)
    {
        sz = n;
        m = vector<vector<int>>(sz, vector<int>(sz, 0));
    }

    void identity()
    {
        for (int i = 0; i < this->sz; i++)
        {
            m[i][i] = 1;
        }
    }
    void display()
    {
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
    }
    Mat operator*(Mat b)
    {
        Mat res(sz);
        for (int i = 0; i < this->sz; i++)
        {
            for (int j = 0; j < this->sz; j++)
            {
                for (int k = 0; k < this->sz; k++)
                {
                    res.m[i][j] += (this->m[i][k] * b.m[k][j]) % mod;
                    res.m[i][j] %= mod;
                }
            }
        }

        return res;
    }
};

Mat power(Mat a, int b, int &mod)
{
    Mat res(a.sz);
    res.identity();
    while (b)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }

    return res;
}
