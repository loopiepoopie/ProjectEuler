//pretty slow, my sieve is pretty bad
//it takes aprox. 1.6s 
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <map>
#define ll long long
using namespace std;

const int NMAX = 1e7;

int phi[NMAX + 1];

bool perm(int a, int b)
{
    int f1[10] = {0}, f2[10] = {0};
    while (a)
    {
        f1[a % 10]++;
        a /= 10;
    }
    while (b)
    {
        f2[b % 10]++;
        b /= 10;
    }
    for (int i = 0; i < 10; i++)
        if (f1[i] != f2[i])
            return false;
    return true;
}

signed main()
{
    int i, j;
    for (i = 2; i <= NMAX; i++)
        phi[i] = i;
    for (i = 2; i <= NMAX; i++)
        if (phi[i] == i)
            for (j = i; j <= NMAX; j += i)
                phi[j] = 1LL * phi[j] * (i - 1) / i;
    double mn = 1e9;
    int poz = -1;
    for (i = 2; i < NMAX; i++)
    {
        if (perm(phi[i], i))
        {
            if (1.0 * i / phi[i] < mn)
            {
                mn = 1.0 * i / phi[i];
                poz = i;
            }
        }
    }
    cout << poz;
}

