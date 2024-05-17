#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>
#define ll long long
using namespace std;

const int NMAX = 10000;
bool c[NMAX + 1];

string str(int val)
{
    string ans = "";
    while (val)
    {
        ans += '0' + val % 10;
        val /= 10;
    }
    sort(ans.begin(), ans.end());
    return ans;
}

signed main()
{
    int i, j;
    for (i = 2; i <= NMAX; i++)
        if (!c[i])
            for (j = i * 2; j <= NMAX; j += i)
                c[j] = 1;
    for (i = 1000; i + 2 * 3330 < 10000; i++)
        if (!c[i] and !c[i + 3330] and !c[i + 2 * 3330]
                and str(i) == str(i + 3330) and str(i + 3330) == str(i + 2 * 3330))
        {
            cout << i << " " << i + 3330 << " " << i + 2 * 3330 << "\n";
        }
}
