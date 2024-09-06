//I'm so stupid with some of these
//I do a brute force, which I then optimise
//And the optimisations are so simple...
//0.35s
#include <iostream>
#include <climits>
#include <cassert>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;

bool prime(int val)
{
    int d = 2;
    for (d = 2; d * d <= val; d++)
        if (val % d == 0)
            return false;
    return true;
}

int main()
{
    int lin, col;
    int i, len = 3;
    lin = col = 0;
    int cnt = 0;
    int val = 1;
    while (1)
    {
        col++;
        val++;
        /*for (i = 1; i < len - 1; i++)
        {
            lin++;
            val++;
        }*/
        val += len - 2;
        if (prime(val))
            cnt++;
        /*for (i = 1; i < len; i++)
        {
            col--;
            val++;
        }*/
        val += len - 1;
        if (prime(val))
            cnt++;
        /*for (i = 1; i < len; i++)
        {
            lin--;
            val++;
        }
        assert(lin == col);*/
        val += len - 1;
        if (prime(val))
            cnt++;
        /*for (i = 1; i < len; i++)
        {
            col++;
            val++;
        }*/
        val += len - 1;
        if (prime(val))
            cnt++;
        if (10 * cnt < 2 * len - 1)
        {
            cout << len;
            return 0;
        }
        len += 2;
    }
}
