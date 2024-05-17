#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>
#define ll long long
using namespace std;

//They made this one so easy, had they put d(1e18), maybe things would
//have been interesting. Now it's a just linear solution...

const int NMAX = 1e6;

string s;
signed main()
{
    int i, j;
    for (i = 1; i <= NMAX and s.size() <= NMAX; i++)
    {
        string aux;
        for (j = i; j; j /= 10)
            aux += '0' + j % 10;
        reverse(aux.begin(), aux.end());
        s += aux;
    }
    int ans = 1;
    for (i = 1; i <= NMAX; i *= 10)
        ans *= (s[i - 1] - '0');
    cout << ans;
}
