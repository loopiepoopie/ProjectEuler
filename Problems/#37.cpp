#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <cassert>
#include <algorithm>
#define ll long long
using namespace std;

const int NMAX = 1e6;

bool ciur[NMAX + 1];
int cif[NMAX + 1];

signed main()
{
    int i, j;
    ciur[1] = 1;
    for (i = 2; i <= NMAX; i++)
        if (!ciur[i])
            for (j = 2 * i; j <= NMAX; j += i)
                ciur[j] = 1;
    cif[0] = 1;
    for (i = 1; i <= NMAX; i++)
        cif[i] = 10 * cif[i / 10];
    for (i = 1; i <= NMAX; i++)
        cif[i] /= 10;
    int ans = 0;
    int cnt = 0;
    for (i = 11; cnt <= 11 and i <= NMAX; i += 2)
    {
        bool ok = 1;
        for (j = i; j; j /= 10)
            ok &= (ciur[j] == 0);
        for (j = i; j; j %= cif[j])
            ok &= (ciur[j] == 0);
        if (ok)
        {
            ans += i;
            cout << i << "\n";
        }
        cnt += ok;
    }
    cout << ans << " " << cnt;
}
