#include <iostream>
#include <climits>
#include <vector>
#include <cassert>
#include <algorithm>
#define ll long long
using namespace std;

const int NMAX = 1001;

int v[NMAX + 1][NMAX + 1];

signed main()
{
    int n, i, j, k;
    n = 1001;
    j = (n + 1) / 2;
    k = (n + 1) / 2;
    for (i = 1; i <= n / 2; i++)
    {
        static int cnt = 0;
        int l;
        int len = 2 * i + 1;
        v[j][k] = ++cnt;
        k++;
        for (l = 1; l < len - 1; l++)
            v[j++][k] = ++cnt;
        for (l = 1; l < len; l++)
            v[j][k--] = ++cnt;
        for (l = 1; l < len; l++)
            v[j--][k] = ++cnt;
        for (l = 1; l < len; l++)
            v[j][k++] = ++cnt;
    }
    v[j][k] = n * n;
    ll ans = 0;
    for (i = 1; i <= n; i++)
        ans += v[i][i] + v[i][n - i + 1];
    ans--;
    cout << ans;
}
