#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>
#define ll long long
using namespace std;

int f[1001];

signed main()
{
    int a, b;
    for (a = 1; a <= 1000; a++)
        for (b = 1; b <= 1000; b++)
        {
            int c = sqrt(a * a + b * b);
            if (c * c == a * a + b * b)
            {
                if (a + b + c <= 1000)
                    f[a + b + c]++;
            }
        }
    int mx = 1;
    for (a = 1; a <= 1000; a++)
        if (f[mx] < f[a])
        {
            mx =  a;
        }
    cout << mx;
}
