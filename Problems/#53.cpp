#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>
#define ll long long
using namespace std;
//O(n^2) with amortization
//If I don't do amortization at ONI, at least I do it when it
//doesn't matter...

const int NMAX = 100;

int d[NMAX + 1][NMAX + 1];
bool big[NMAX + 1][NMAX + 1];

signed main()
{
    int i, j;
    d[0][0] = 1;
    for (i = 0; i <= 100; i++)
        for (j = 0; j <= i; j++)
            if (!big[i][j] and !(i == 0 and j == 0))
            {
                if (i - 1 >= 0)
                    d[i][j] += d[i - 1][j];
                if (i - 1 >= 0 and j - 1 >= 0)
                    d[i][j] += d[i - 1][j - 1];
                if (d[i][j] > 1000000)
                {
                    int k, l;
                    for (k = i; k <= 100; k++)
                        for (l = j; l <= j + (k - i); l++)
                            big[k][l] = 1;
                }
            }
    int ans = 0;
    for (i = 0; i <= 100; i++)
        for (j = 0; j <= i; j++)
            ans += big[i][j];
    cout << ans;
}
