#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <cassert>
#include <algorithm>
#define ll long long
using namespace std;

signed main()
{
    int i, j;
    ll ans = -1;
    for (i = 1; i < 1000000; i++)
    {
        int sum = 0;
        for (j = i; j; j /= 10)
            sum += (j % 10) * (j % 10) * (j % 10) * (j % 10) * (j % 10);
        if (sum == i)
            ans += i;
    }
    cout << ans;
}
