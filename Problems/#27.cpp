#include <iostream>
#include <climits>
#include <vector>
#include <cassert>
#include <algorithm>
#define ll long long
using namespace std;

bool prime(int val)
{
    if (val % 2 == 0 and val != 2)
        return 0;
    if (val == 1)
        return 0;
    for (int d = 3; d * d <= val; d += 2)
        if (val % d == 0)
            return 0;
    return 1;
}

int solve(int i, int j)
{
    int k;
    bool ok = 1;
    int cnt = 0;
    for (k = 0; ok; k++)
    {
        int val = k * k + i * k + j;
        if (prime(abs(val)))
        {
            cnt++;
        }
        else ok = 0;
    }
    return cnt;
}

signed main()
{
    cout << solve(1, 41) << " ";
    int i, j, k;
    int prod = 0;
    int ceva = 0;
    int a, b;
    for (i = -999; i <= 999; i++)
        for (j = -1000; j <= 1000; j++)
        {
            int cnt = solve(i, j);
            if (ceva < cnt)
            {
                ceva = cnt;
                prod = i * j;
                a = i;
                b = j;
            }
        }
    cout << ceva << " " << prod << " " << a << " " << b;
}
