#include <iostream>
#include <climits>
#include <vector>
#include <set>
#include <cassert>
#include <algorithm>
#define ll long long
using namespace std;

int money[] = {1, 2, 5, 10, 20, 50, 100, 200};

int ans;

void bkt(int pas, int sum)
{
    if (pas == 8)
    {
        ans += (sum == 200);
        return ;
    }
    int i;
    for (i = 0; sum + i * money[pas] <= 200; i++)
    {
        bkt(pas + 1, sum + i * money[pas]);
    }
}

signed main()
{
    bkt(0, 0);
    cout << ans;
}
