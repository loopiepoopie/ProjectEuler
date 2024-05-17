#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>
#define ll long long
using namespace std;

const int NMAX = 1e6;

bool c[NMAX + 1];
vector <int> prime;

signed main()
{
    int i, j;
    c[1] = 1;
    for (i = 2; i <= NMAX; i++)
        if (!c[i])
            for (j = 2 * i; j <= NMAX; j += i)
                c[j] = 1;
    prime.push_back(2);
    for (i = 3; i <= NMAX; i += 2)
        if (!c[i])
            prime.push_back(i);
    int ans = 0;
    int len = 0;
    for (i = 0; i < prime.size(); i++)
    {
        int sum = 0;
        for (j = i; j < prime.size() and sum + prime[j] <= NMAX; j++)
        {
            sum += prime[j];
            if (!c[sum])
            {
                if (len < j - i + 1)
                {
                    len = j - i + 1;
                    ans = sum;
                }
            }
        }
    }
    cout << ans << " " << len;
}
