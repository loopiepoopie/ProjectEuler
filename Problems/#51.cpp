#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>
#define ll long long
using namespace std;

const int NMAX = 1e6;

bool c[NMAX + 1];
int pwr[] = {1, 10, 100, 1000, 10000, 100000, 1000000};

int ans;

void bkt(int pas, int nr, int add, bool canzero, int dig)
{
    int i;
    if (pas == dig + 1)
    {
        if (add != 0)
        {
            int cnt = 0;
            int first = -1;
            for (i = !canzero; i <= 9; i++)
                if (!c[i * add + nr])
                {
                    cnt++;
                    if (first == -1)
                        first = i * add + nr;
                }
            if (cnt == 8)
            {
                ans = min(ans, first);
            }
        }
        return ;
    }
    //we place a *
    if (pas == 1)
        canzero = 0;
    bkt(pas + 1, nr, add + pwr[dig - pas], canzero, dig);
    if (pas == 1)
        canzero = 1;
    for (i = 0; i <= 9; i++)
    {
        bkt(pas + 1, nr + i * pwr[dig - pas], add, canzero, dig);
    }
}

signed main()
{
    int i, j;
    c[1] = 1;
    for (i = 2; i <= NMAX; i++)
        if (!c[i])
            for (j = 2 * i; j <= NMAX; j += i)
                c[j] = 1;
    ans = INT_MAX;
    for (i = 1; i <= 6; i++)
        bkt(1, 0, 0, 0, i);
    cout << ans;
}
