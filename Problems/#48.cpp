#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>
#define ll long long
using namespace std;

const int VMAX = 1e6;
const ll MOD = 1e10;

ll mult(ll a, ll b) //multiplication in logarithmic time because of MOD too big
//never really thought I'd see the day when I'd need it outside of
//competitive programming contests
{
    ll ans = 0;
    while (b)
    {
        if (b & 1)
            ans = (ans + a) % MOD;
        a = (a + a) % MOD;
        b >>= 1;
    }
    return ans;
}

ll pwr(ll a, int b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = 1LL * mult(ans, a) % MOD;
        a = 1LL * mult(a, a) % MOD;
        b >>= 1;
    }
    return ans;
}

signed main()
{
    int i;
    ll ans = 0;
    for (i = 1; i <= 1000; i++)
        ans = (ans + pwr(i, i)) % MOD;
    cout << ans;
}
