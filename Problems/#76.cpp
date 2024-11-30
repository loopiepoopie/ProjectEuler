//just knapsack dp, my algo foundation is coming in handy
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#define ll long long
using namespace std;

//d[i] = no. of ways to create i

const int NMAX = 100;

int d[NMAX + 1];

signed main()
{
    int i, j, k;
    d[0] = 1;
    for (k = 1; k <= NMAX; k++)
        {
            for (i = k; i <= NMAX; i++)
                d[i] += d[i - k];
        }
    cout << d[100] - 1;
}
