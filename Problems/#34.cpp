#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <cassert>
#include <algorithm>
#define ll long long
using namespace std;

int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

signed main()
{
    //x = 7 is the biggest number such that 9! * x has x digits
    //so we need to check just before 10^7.
    int j, i, n = 10000000;
    ll ans = -3;
    for (i = 1; i < n; i++)
    {
        ll sum = 0;
        for (j = i; j; j /= 10)
            sum += fact[j % 10];
        if (sum == i)
            ans += i;
    }
    cout << ans;
}
