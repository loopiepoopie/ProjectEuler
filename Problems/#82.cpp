//Cute oldschool approach used at other similar problems before
//It's also to generalise to multiple directions, if you are careful 
//Way easier to code than standard non-memoisation dp 
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#define ll long long
using namespace std;

const int NMAX = 80;
const int DIR = 3;
const int LEN = 1e6;
const int INF = 1e9;

int d[NMAX][NMAX][DIR];
//0 - I come from upwards
//1 - I come from downwards
//2 - I come from left
int v[NMAX][NMAX];
char s[LEN];

int dp(int a, int b, int dir);

int all_states(int a, int b)
{
    int ans = INF;
    int k;
    for (k = 0; k < DIR; k++)
        ans = min(ans, dp(a, b, k));
    return ans;
}

int dp(int a, int b, int dir)
{
    if (d[a][b][dir] != INF)
        return d[a][b][dir];
    if (b == 0)
        d[a][b][dir] = v[a][b];
    int v1 = INF;
    pair <int, int> where;
    if (dir == 0)
    {
        if (a - 1 >= 0)
            v1 = v[a][b] + min(dp(a - 1, b, 0), dp(a - 1, b, 2));
        d[a][b][dir] = min(d[a][b][dir], v1);
    }
    else if (dir == 1)
    {
        if (a + 1 < NMAX)
            v1 = v[a][b] + min(dp(a + 1, b, 2), dp(a + 1, b, 1));
        d[a][b][dir] = min(d[a][b][dir], v1);
    }
    else
    {
        if (b - 1 >= 0)
            d[a][b][dir] = min(d[a][b][dir], v[a][b] + all_states(a, b - 1));
    }
    return d[a][b][dir];
}

signed main()
{
    ifstream cin("ciorna.in");//some files I used to read input. Put the initial file they give here and it'll work.
    ofstream cout("ciorna.out"); //for the answer
    int i, j, k;
    for (i = 0; i < NMAX; i++)
    {
        cin.getline(s, sizeof(s));
        j = 0;
        for (char *p = strtok(s, ","); p; p = strtok(0, ","), j++)
        {
            for (k = 0; p[k]; k++)
                v[i][j] = v[i][j] * 10 + p[k] - '0';
        }
    }
    for (i = 0; i < NMAX; i++)
        for (j = 0; j < NMAX; j++)
            for (k = 0; k < 3; k++)
                d[i][j][k] = INF;
    for (i = 0; i < NMAX; i++)
        for (j = 0; j < NMAX; j++)
            for (k = 0; k < 3; k++)
                dp(i, j, k);
    int ans = INF;
    for (i = 0; i < NMAX; i++)
        for (j = 0; j < 3; j++)
            ans = min(ans, dp(i, NMAX - 1, j));
    cout << ans;
}
