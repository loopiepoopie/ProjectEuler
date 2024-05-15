#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <cassert>
#include <algorithm>
#define ll long long
using namespace std;

const int NMAX = 1000;

set <vector <pair <int, int> > > s;


vector <pair <int, int> > desc(int a, int b)
{
    vector <pair <int, int> > ans;
    int d = 2;
    while (d * d <= a)
    {
        if (a % d == 0)
        {
            int cnt = 0;
            while (a % d == 0)
            {
                cnt++;
                a /= d;
            }
            ans.push_back({d, cnt * b});
        }
        d++;
    }
    if (a > 1)
    {
        ans.push_back({a, b});
    }
    return ans;
}

signed main()
{
    int a = 100;
    int b = 100;
    int i, j;
    for (i = 2; i <= a; i++)
        for (j = 2; j <= b; j++)
            s.insert(desc(i, j));
    cout << s.size();
}
