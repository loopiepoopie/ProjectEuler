//just knapsack dp, my algo foundation is coming in handy
//just changed some bits from problem 76, and hoped that
//the first 1000 primes will suffice
//0.016s
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
#define ll long long
using namespace std;

//d[i] = no. of ways to create i using some values

const int NMAX = 1000;

int d[NMAX + 1];
bool viz[NMAX + 1];

vector <int> primes;

void sieve()
{
    int i, j;
    viz[1] = 1;
    for (i = 2; i <= NMAX; i++)
        if (!viz[i])
            for (j = 2 * i; j <= NMAX; j += i)
                viz[j] = 1;
    for (i = 2; i <= NMAX; i++)
        if (!viz[i])
            primes.push_back(i);
}

signed main()
{
    sieve();
    int i, j, k;
    d[0] = 1;
    for (int x : primes)
        {
            for (i = x; i <= NMAX; i++)
                d[i] += d[i - x];
        }
    for (i = 1; i <= NMAX; i++)
        if (d[i] >= 5000)
        {
            cout << i;
            return 0;
        }
}
