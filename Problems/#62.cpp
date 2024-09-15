//another meh problem
//I could've used string hashing or tries, but it works fine with map
//33ms
#include <iostream>
#include <climits>
#include <cassert>
#include <cctype>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#define ll long long
#define int long long
using namespace std;

vector <int> cubes;
map <string, vector <int> > mp;

signed main()
{
    int i;
    for (i = 1; i <= 10000; i++)
    {
        cubes.push_back(i * i * i);
        int x = i * i * i;
        string str = "";
        while (x)
        {
            str += '0' + x % 10;
            x /= 10;
        }
        sort(str.begin(), str.end());
        mp[str].push_back(i * i * i);
    }
    int val = LLONG_MAX;
    for (auto it = mp.begin(); it != mp.end(); it++)
        if (it->second.size() == 5)
            val = min(val, it->second.front());
    cout << val;
}
