#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>
#define ll long long
using namespace std;

const int VMAX = 1e6;

int c[VMAX + 1];

signed main()
{
    int i, j;
    for (i = 2; i <= VMAX; i++)
        if (!c[i])
            for (j = i; j <= VMAX; j += i)
                c[j]++;
    for (i = 1; i + 4 - 1 <= VMAX; i++)
        if (c[i] == 4 and c[i + 1] == 4 and c[i + 2] == 4 and c[i + 3] == 4)
        {
            cout << i;
            return 0;
        }
}
