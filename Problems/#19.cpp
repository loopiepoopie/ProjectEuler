#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <cassert>
#include <algorithm>
#define ll long long
using namespace std;

int luni[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int luni2[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

signed main()
{
    int an;
    int luna;
    int zi;
    an = 1901;
    luna = 1;
    zi = 1;
    int ans = 0;
    int sap = 1;
    int i;
    //The number 36158 is just the number of days from 1 Jan 1901
    //to 31 Dec 2000.
    for (i = 0; i <= 36158; i++, sap = (sap + 1) % 7)
    {
        int *p;
        if (an % 4 == 0 and ((an % 100 != 0) or (an % 400 == 0)))
            p = luni2;
        else
            p = luni;
        if (zi == p[luna])
        {
            luna++;
            if (luna == 13)
            {
                an++;
                luna = 1;
            }
            zi = 1;
        }
        else
        {
            zi++;
        }
        if (zi == 1 and sap == 6)
            ans++;
    }
    cout << zi << " " << luna << " " << an << "\n";
    cout << ans;
}
