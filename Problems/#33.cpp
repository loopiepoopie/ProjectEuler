#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <cassert>
#include <algorithm>
#define ll long long
using namespace std;

bool egal(int a, int b, int c, int d)
{
    if (b == 0 or d == 0)
        return 0;
    int dd = __gcd(a, b);
    a /= dd;
    b /= dd;
    dd = __gcd(c, d);
    c /= dd;
    d /= dd;
    return (a == c and b == d);
}

//16, 64
//26, 65
//

signed main()
{
    int i, j;
    for (i = 10; i <= 99; i++)
        for (j = i + 1; j <= 99; j++)
            if (i % 10 != 0 and j % 10 != 0)
            {
                int a1 = i / 10;
                int a2 = i % 10;
                int b1 = j / 10;
                int b2 = j % 10;

                if (a1 == b1)
                {
                    if (egal(i, j, a2, b2))
                        cout << i << " " << j << "\n";
                }
                else if (a1 == b2)
                {
                    if (egal(i, j, a2, b1))
                        cout << i << " " << j << "\n";
                }
                else if (a2 == b1)
                {
                    if (egal(i, j, a1, b2))
                        cout << i << " " << j << "\n";
                }
                else if (a2 == b2)
                {
                    if (egal(i, j, a1, b1))
                        cout << i << " " << j << "\n";
                }
            }
}
