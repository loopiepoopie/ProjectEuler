//huh, nice and easy
//you can look up farey sequences and there is a nice propriety
//regarding the mediant
//suppose there are two adjacent fractions (a/b and c/d)
//at some point, the next number that will appear between them
//will be (a+c)/(b+d) (i.e. the mediant)
//that number will appear when the order of the sequence reaches
//b+d, therefore the algorithm below just does that
//aprox. 0.015s
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
    //5 + 7 * n <= 1000000
    //7 * n <= 999995
    //n = 999995 / 7
    //2 + 3 * n
    cout << 2 + 3 * ((1000000 - 5) / 7);
}

