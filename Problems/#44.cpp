#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>
#define ll long long
using namespace std;

const int BULAN = 3000;
const int BIG = BULAN * (3 * BULAN - 1) / 2;

int invf[BIG + 1];
int f[BIG + 1];

signed main()
{
    int i, j;
    for (i = 1; i <= BULAN; i++)
    {
        invf[i * (3 * i - 1) / 2] = i;
        f[i] = i * (3 * i - 1) / 2;
    }
    int mn = INT_MAX;
    for (i = 1; i <= BULAN; i++)
        for (j = i + 1; j <= BULAN; j++)
            if (f[i] % 2 == f[j] % 2)
                {
                    int fbig = (f[i] + f[j]) / 2;
                    int fsmol = (f[j] - f[i]) / 2;
                    if (fbig <= BIG and invf[fbig] and invf[fsmol])
                    {
                        mn = min(mn, fbig - fsmol);
                    }
                }
    cout << mn;
}
