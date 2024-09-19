//I just wrote the equation with a floor of the log10 and then
//decided just to do the brute force and observe that ceiling of the
//formula is always the floor + 1, unless n = 1, when I did a special
//case
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;
signed main()
{
    int i, ans = 9;
    for (i = 2; i <= 22; i++)
    {
        double who = pow(10, 1.0 * (i - 1) / i);
        if (10 > floor(who) + 1)
            ans += 10 - floor(who) - 1;
    }
    cout << ans;
}
