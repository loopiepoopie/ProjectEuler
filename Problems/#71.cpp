//huh, nice and easy
//you can look up farey sequences and there is a nice propriety
//regarding the mediant
//suppose there are two adjacent fractions (a/b and c/d)
//at some point, the next number that will appear between them
//will be (a+c)/(b+d) (i.e. the mediant)
//that number will appear when the order of the sequence reaches
//b+d, and the algorithm below does just that
//aprox. 0.04 - 0.06s
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <map>
#define ll long long
using namespace std;

const int NMAX = 1e6;

signed main()
{
    pair <int, int> a(2, 5);
    while (a.second + 7 <= NMAX)
    {
        a = {a.first + 3, a.second + 7};
    }
    cout << a.first << " " << a.second;
}

