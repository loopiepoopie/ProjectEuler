//a walk in the park, just use the linear sieve to solve it 
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <map>
#define ll long long
using namespace std;

const int NMAX = 1e6;

int phi[NMAX + 1];

signed main()
{
    int i, j;
    for (i = 2; i <= NMAX; i++)
        phi[i] = i;
    for (i = 2; i <= NMAX; i++)
        if (phi[i] == i)
            for (j = i; j <= NMAX; j += i)
                phi[j] = 1LL * phi[j] * (i - 1) / i;
    double mx = 0;
    int poz = -1;
    for (i = 2; i <= NMAX; i++)
        if (mx < 1.0 * i / phi[i])
        {
            mx = 1.0 * i / phi[i];
            poz = i;
        }
    cout << poz;
}

