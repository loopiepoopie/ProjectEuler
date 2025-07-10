/*
You may get a rectangle from any point (a, b) to any point (c, d) where
c > a -> so just n + 1 - a variants
d > b -> so just m + 1 - b variants
these are indepndent from one another, and n + 1 - a is just a seen from the back, so 
esentially is just 1 + 2 + .. + n = n (n + 1) / 2 variants for a and m (m + 1) / 2 variants for b
from here, n(n + 1) / 2 m (m + 1) / 2 as close as possible to 2 mil, so try all (n, m) with n, m less than 3000 
and it should be ok, as the bound here is sqrt(2 mil) (those functions are quadratic) 
it runs in aprox. 0.023s
*/
#include <iostream>
#include <cassert>
#define ll long long
using namespace std;

ll ncr(int a)
{
    return 1LL * a * (a + 1) / 2;
}

const int LIM = 1500;
const int EXACT = 2e6;

int main()
{
    int i, j;
    ll mx = 0;
    int a1 = 0;
    ll mn = 1e9;
    int a2 = 0;
    for (i = 1; i <= LIM; i++)
        for (j = 1; j <= LIM; j++)
        {
            ll val = ncr(i) * ncr(j);
            if (val < EXACT)
            {
                if (mx < val)
                {
                    mx = val;
                    a1 = i * j;
                }
            }
            else
            {
                if (mn > val)
                {
                    mn = val;
                    a2 = i * j;
                }
            }
        }
    if (abs(mx - EXACT) < abs(mn - EXACT))
        cout << a1;
    else
        cout << a2;
}
