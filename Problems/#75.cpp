//instantaneous, I just used generated part of the tree of
//primitive pythagorean triplets with sum less than 1.5e6
//and counted the rest by simply considering them multiples of that
//I used https://en.wikipedia.org/wiki/Tree_of_primitive_Pythagorean_triples
//0.06s, Jesus fucking Christ
//there's aprox. 300000 of primitive triplets, which is insanely low
//also, by taking a + b + c = l, and squaring the relation, you
//get that the length must be even, which speeds up the process a bit
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#define ll long long
using namespace std;

const int NMAX = 1500000;

int cnt[NMAX + 1];
int cate;

void dfs(int a, int b, int c)
{
    cate++;
    if (a + b + c > NMAX)
        return ;
    int l;
    for (l = a + b + c; l <= NMAX; l += a + b + c)
        cnt[l]++;
    dfs(a - 2 * b + 2 * c, 2 * a - b + 2 * c, 2 * a - 2 * b + 3 * c);
    dfs(a + 2 * b + 2 * c, 2 * a + b + 2 * c, 2 * a + 2 * b + 3 * c);
    dfs(-a + 2 * b + 2 * c, -2 * a + b + 2 * c, -2 * a + 2 * b + 3 * c);
}

signed main()
{
    dfs(3, 4, 5);
    int i, ans = 0;
    for (i = 2; i <= NMAX; i += 2)
        if (cnt[i] == 1)
            ans++;
    cout << ans;
}
