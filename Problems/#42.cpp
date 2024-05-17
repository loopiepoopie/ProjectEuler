#include <fstream>
#include <climits>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>
#define ll long long
using namespace std;

const int BULAN = 1000000;
const int SMAX = 1e7;

char s[SMAX + 2];

bool good[BULAN + 1];

int idx;

int parse()
{
    if (s[idx] != '"')
        return 0;
    idx++;
    int nr = 0;
    for (; isalpha(s[idx]); idx++)
        nr += s[idx] - 'A' + 1;
    assert(s[idx++] == '"');
    if (s[idx] == ',')
        idx++;
    return nr;
}

signed main()
{
    ifstream cin("ciorna.in");
    ofstream cout("ciorna.out");

    cin.getline(s, sizeof(s));
    int i;
    for (i = 1; i * (i + 1) / 2 <= BULAN; i++)
        good[i * (i + 1) / 2] = 1;
    int ans = 0;
    i = parse();
    while (i)
    {
        ans += good[i];
        i = parse();
    }
    cout << ans;
}
