//stern brocot tree madness
//0.1 s
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <map>
#define ll long long
using namespace std;

const int NMAX = 12000;

int divide(int a, int b, int c, int d)
{
    if (b + d <= NMAX)
        return 1 + divide(a, b, a + c, b + d) + divide(a + c, b + d, c, d);
    return 0;
}

signed main()
{
    cout << divide(1, 2, 1, 3);
}
