#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>
#define ll long long
using namespace std;

const int VMAX = 1e6;

vector <int> prime;
vector <int> vec;

bool c[VMAX + 1];

signed main()
{
    int i, j;
    for (i = 2; i <= VMAX; i++)
        if (!c[i])
            for (j = 2 * i; j <= VMAX; j += i)
                c[j] = 1;
    prime.push_back(2);
    for (i = 3; i <= VMAX; i += 2)
        if (!c[i])
            prime.push_back(i);
    for (i = 0; prime[i] <= 10000; i++)
        for (j = 1; j <= 1000; j++)
            vec.push_back(prime[i] + 2 * j * j);
    sort(vec.begin(), vec.end());
    for (i = 3; i <= 100000; i += 2)
        if (c[i] and !binary_search(vec.begin(), vec.end(), i))
        {
            cout << i;
            return 0;
        }
}
