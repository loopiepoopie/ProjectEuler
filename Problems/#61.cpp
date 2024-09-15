//pretty easy one, I was happy to use graph concepts to a
//semi unrelated problem
//15ms-94ms
#include <iostream>
#include <climits>
#include <cassert>
#include <cctype>
#include <cstring>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

const int DIGS = 100;
const int NMAX = 1e5;

vector <pair <int, int> > nums[DIGS + 1];

int belong[NMAX + 1];

int nodigs(int x)
{
    int ans = 0;
    while (x)
    {
        ans++;
        x /= 10;
    }
    return ans;
}

int f(int n, int ord)
{
    switch (ord)
    {
    case 3:
        return n * (n + 1) / 2;
        break;
    case 4:
        return n * n;
        break;
    case 5:
        return n * (3 * n - 1) / 2;
        break;
    case 6:
        return n * (2 * n - 1);
        break;
    case 7:
        return n * (5 * n - 3) / 2;
        break;
    default:
        return n * (3 * n - 2);
    }
}

bool viz[NMAX + 1];
bool color[10];

vector <int> stiva;

void dfs(int nr, int dep, int col)
{
    stiva.push_back(nr);
    viz[nr] = 1;
    color[col] = 1;
    if (dep == 5 and stiva.back() % 100 == stiva.front() / 100)
    {
        int sum = 0;
        for (int x : stiva)
            sum += x;
        cout << sum;
        exit(0);
    }
    for (pair <int, int> x : nums[nr % 100])
        if (!viz[x.first] and !color[x.second])
        {
            dfs(x.first, dep + 1, x.second);
        }
    viz[nr] = 0;
    color[col] = 0;
    stiva.pop_back();
}

signed main()
{
    int i, j;
    for (j = 3; j <= 8; j++)
        for (i = 1; nodigs(f(i, j)) <= 4; i++)
        {
            int val = f(i, j);
            belong[val] |= (1 << j);
            if (nodigs(val) == 4)
            {
                nums[val / 100].push_back({val, j});
            }
        }
    for (i = 1000; i < 10000; i++)
    {
        for (j = 3; j <= 8; j++)
            if (belong[i] & (1 << j))
            {
                dfs(i, 0, j);
            }
    }
}
