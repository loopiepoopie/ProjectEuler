#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>
#define ll long long
using namespace std;
//reduced time constant from comparing vectors to comparing numbers
//with them (things are all below one million)
const int NMAX = 1e6;

int has[NMAX + 1];

signed main()
{
    int i, j;
    for (i = 1; i <= NMAX; i++)
    {
        int f[10] = {0};
        for (j = i; j; j /= 10)
            f[j % 10]++;
        for (j = 0; j <= 9; j++)
            while (f[j] != 0)
            {
                has[i] = has[i] * 10 + j;
                f[j]--;
            }
    }
    for (i = 1; 6 * i <= NMAX; i++)
    {
        bool ok = 1;
        for (j = 2 * i; ok and j <= 6 * i; j += i)
            ok &= (has[i] == has[j]);
        if (ok)
        {
            cout << i;
            return 0;
        }
    }
}
