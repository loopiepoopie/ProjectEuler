#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>
#define ll long long
using namespace std;

const int NMAX = 9;

int v[NMAX + 1];

bool prime(int a)
{
    if (a % 2 == 0 and a != 2)
        return false;
    if (a == 1)
        return false;
    for (int d = 3; d * d <= a; d += 2)
        if (a % d == 0)
            return false;
    return true;
}

signed main()
{
    int i, j;
    for (i = 9; i >= 1; i--)
    {
        for (j = 1; j <= i; j++)
            v[j] = i - j + 1;
        do
        {
            int nr = 0;
            for (j = 1; j <= i; j++)
                nr = nr * 10 + v[j];
            if (prime(nr))
            {
                cout << nr;
                exit(0);
            }
        }
        while (next_permutation(v + 1, v + i + 1, [](int a, int b)
                                {
                                    return a > b;
                                }));
    }
}
