#include <bits/stdc++.h>
using namespace std;

int a[1000001], n, i, j, r, d[1000001];
bool flag = false;
int bs(int x)
{
    int l = 0;
    int r = n - 1;
    int mid;
    if (a[n - 1] <= x)
        return n - 1;
    else if (x < a[0])
    {
        flag = true;
        return 0;
    }
    while (true)
    {
        mid = (r + l) / 2;
        if (a[mid] > x)
            r = mid;
        else
            l = mid;
        if (r - l == 1)
            return l;
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >>
            a[i];
    sort(a, a + n);
    d[0] = a[0];
    for (int i = 1; i <= n - 1; i++)
        d[i] = d[i - 1] + a[i];
    cin >> r;
    for (int i = 0; i < r; i++)
    {
        cin >> j;
        int ind = bs(j);
        if (!flag)
            cout << ind + 1 << " " << d[ind] << "\n";
        else
        {
            cout << "0 0\n";
            flag = false;
        }
    }
}