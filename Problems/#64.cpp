//awful problem. You just had to realise that double precision is
//terrible and it fucks up your results for orders of >= 10, which is
//not ok when you are allegedly supposed to deal with periods of >= 200
//numbers (I realised that after I decided to switch method)
//Then I decided to write all partial numbers you can get as
//(a * sqrt(n) - b) / c, for a, b, c integers
//after that you just subtract some integer l from them
//and you distribute the terms accordingly and you associate the new
//a, b and c with the formulae you got from the past a, b, c
//just like complex numbers, real part and imaginary part
//works in 0.6s maximum
#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cmath>
#define int long long
using namespace std;

const int PERIOD = 250;

int perioada(int n)
{
    vector <int> vals;
    int i, j;
    int a, b, c;
    a = 1;
    b = 0;
    c = 1;
    //sus va fi mereu o scadere
    for (i = 1; i <= PERIOD; i++)
    {
        int l = (int)(1.0 * (a * sqrt(n) - b) / c);
        //cout << l << " ";
        if (i != 1)
            vals.push_back(l);
        int a1, b1, c1;
        a1 = c * a;
        b1 = -c * (b + c * l);
        c1 = a * a * n - (b + c * l) * (b + c * l);
        a = a1;
        b = b1;
        c = c1;
        int d = __gcd(a, __gcd(b, c));
        a /= d;
        b /= d;
        c /= d;
    }
    for (i = 1; i <= PERIOD; i++)
    {
        bool ok = 1;
        for (j = i; ok and j < vals.size(); j++)
            if (vals[j] != vals[j - i])
                ok = 0;
        if (ok)
            return i;
    }
    assert(0);
    return -1;
}

signed main()
{
    //cout << perioada(241);
    //return 0;
    int i;
    int ans = 0;
    int mx = 0;
    for (i = 1; i <= 10000; i++)
        {
            int val = sqrt(i);
            if (val * val != i)
            {
                ans += perioada(i) % 2;
                //mx = max(mx, perioada(i));
            }
        }
    cout << ans;
}
