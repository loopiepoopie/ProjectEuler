#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <cassert>
#include <algorithm>
#define ll long long
using namespace std;

const int NMAX = 9;

int v[NMAX + 1];

vector <int> ceva;

signed main()
{
    int n = 9, i, j, k;
    for (i = 1; i <= n; i++)
        v[i] = i;
    ll ans = 0;
    do
    {
        int nr1 = 0;
        for (i = 1; i <= n; i++)
        {
            nr1 = nr1 * 10 + v[i];
            int nr2 = 0;
            for (j = i + 1; j <= n; j++)
            {
                nr2 = nr2 * 10 + v[j];
                int nr3 = 0;
                for (k = j + 1; k <= n; k++)
                    nr3 = nr3 * 10 + v[k];
                if (1LL * nr1 * nr2 == nr3)
                    ceva.push_back(nr3);
            }
        }
    }
    while (next_permutation(v + 1, v + n + 1));
    sort(ceva.begin(), ceva.end());
    ceva.push_back(-1);
    for (i = 0; i + 1 < ceva.size(); i++)
        if (ceva[i] != ceva[i + 1])
            ans += ceva[i];
    cout << ans;
}
