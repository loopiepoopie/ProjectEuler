//what a terrible problem. What if the digits were not distinct?
//what then? I just assumed the worst case and tried to find something
//and just did a brute force
//afterwards I tried to build the graph and do a topological sort on it
//(because it needed to be a dag for a solution to exist) and voila,
//it worked wonders
//0.062s
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>
#include <cstring>
#define ll long long
using namespace std;

//ifstream cin("ciorna.in");
//ofstream cout("ciorna.out");

string s[100];

vector <int> g[10];

int in[10];

set <int> q;

signed main()
{
    int i;
    for (i = 1; cin >> s[i]; i++);
    for (i = 1; i <= 50; i++)
    {
        g[s[i][0] - '0'].push_back(s[i][1] - '0');
        g[s[i][1] - '0'].push_back(s[i][2] - '0');
        in[s[i][1] - '0']++;
        in[s[i][2] - '0']++;
    }
    for (i = 0; i <= 9; i++)
        if (in[i] == 0 and g[i].size() != 0)
        {
            q.insert(i);
        }
    while (!q.empty())
    {
        int f = *q.begin();
        q.erase(q.begin());
        cout << f;
        for (int x : g[f])
        {
            in[x]--;
            if (in[x] == 0)
                q.insert(x);
        }
    }
}
