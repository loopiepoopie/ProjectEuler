//12 seconds for O(n^2)
//0.5 seconds for O(n sqrt n)
//Just search for Euler's recurrence relation for P(n), and simply
//implement it, because it takes n sqrt n, good enough for the first
//1e5 numbers, which are apparently enough for finding the solution
//https://en.wikipedia.org/wiki/Partition_function_(number_theory)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#define ll long long
using namespace std;
//55374

const int MOD = 1e6;
const int NMAX = 100000;

int p[NMAX + 1];

signed main()
{
    int i, j;
    p[1] = 1;
    p[0] = 1;
    for (i = 2; i <= NMAX; i++)
        for (j = 1; i - 1LL * j * (3 * j - 1) / 2 >= 0; j++)
        {
            int fact;
            if (j % 2 == 1)
                fact = 1;
            else
                fact = MOD - 1;
            p[i] = (p[i] + 1LL * fact * p[i - 1LL * j * (3 * j - 1) / 2] % MOD) % MOD;
            if (i - 1LL * j * (3 * j + 1) / 2 >= 0)
                p[i] = (p[i] + 1LL * fact * p[i - 1LL * j * (3 * j + 1) / 2] % MOD) % MOD;
        }
    for (i = 1; i <= NMAX; i++)
        if (p[i] == 0)
        {
            cout << i;
            return 0;
        }
}
