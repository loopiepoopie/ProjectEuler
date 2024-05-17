#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>
#define ll long long
using namespace std;

const int NMAX = 10;

int v[NMAX + 1];

int prim[] = {0, 2, 3, 5, 7, 11, 13, 17};
int n;

bool propietate()
{
    bool ok = 1;
    int i;
    for (i = 1; i + 3 - 1 < 10; i++)
    {
        int nr = v[i] * 100 + v[i + 1] * 10 + v[i + 2];
        ok &= (nr % prim[i] == 0);
    }
    return ok;
}

signed main()
{
    int i;
    int n = 10;

    v[0] = 1;
    v[1] = 0;
    for (i = 2; i < n; i++)
        v[i] = i;
    ll ans = 0;
    do
    {

        ll val = 0;
        for (i = 0; i < 10; i++)
            val = val * 10 + v[i];
        if (propietate())
        {
            ans += val;
            cout << val << "\n";
        }
    }
    while (next_permutation(v, v + n));
    cout << ans;
}
