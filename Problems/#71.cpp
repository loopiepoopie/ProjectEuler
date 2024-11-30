//huh, nice and easy
//you can look up farey sequences and there is a nice propriety
//regarding the mediant
//suppose there are two adjacent fractions (a/b and c/d)
//at some point, the next number that will appear between them
//will be (a+c)/(b+d) (i.e. the mediant)
//that number will appear when the order of the sequence reaches
//b+d, and the algorithm below does just that
//0.05s
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <map>
#define ll long long
using namespace std;

const int NMAX = 1e6;

int cute[NMAX + 1];

signed main()
{
    pair <int, int> a(2, 5), b(3, 7);
    for (int i = 9; i <= NMAX; i++)
    {
        if (cute[i] != 0)
        {
            a = {cute[i], i};
        }
        if (a.second + b.second <= NMAX)
            cute[a.second + b.second] = a.first + b.first;
    }
    cout << a.first << " " << a.second;
}

