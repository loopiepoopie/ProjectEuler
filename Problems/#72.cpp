//just do a dynamic programming
//you know d(n) -> the number of fractions with denominators <= n
//d(n) = d(n - 1) + phi(n) (you add all the fractions for which
//the numerator < n and coprime, those counted by phi function)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <map>
#define ll long long
using namespace std;

const int NMAX = 1e6;
int phi[NMAX + 1];
ll d[NMAX + 1];

signed main()
{
    int i, j;
    for (i = 2; i <= NMAX; i++)
        phi[i] = i;
    for (i = 2; i <= NMAX; i++)
        if (phi[i] == i)
            for (j = i; j <= NMAX; j += i)
                phi[j] = 1LL * phi[j] * (i - 1) / i;
    d[8] = 21;
    for (i = 9; i <= NMAX; i++)
        d[i] = d[i - 1] + phi[i];
    cout << d[NMAX];
}
