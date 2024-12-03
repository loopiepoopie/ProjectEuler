//Oldschool dp approach, and I had some trouble reading the input,
//simply because I attempted to understand cin.get() and found out,
//like many others, that it's just too hard to get what happens in
//between lines and whatnot.
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#define ll long long
using namespace std;

const int NMAX = 80;
const int LEN = 1e6;

int d[NMAX][NMAX];
int v[NMAX][NMAX];
char s[LEN];

signed main()
{
    ifstream cin("ciorna.in");//some files I used to read input. Put the initial file they give here and it'll work.
    ofstream cout("ciorna.out"); //and for outputting the answer
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
    d[0][0] = v[0][0];
    for (i = 0; i < NMAX; i++)
        for (j = 0; j < NMAX; j++)
        {
            if (i or j)
                d[i][j] = 1e9;
            if (j - 1 >= 0)
                d[i][j] = min(d[i][j], v[i][j] + d[i][j - 1]);
            if (i - 1 >= 0)
                d[i][j] = min(d[i][j], v[i][j] + d[i - 1][j]);
        }
    cout << d[NMAX - 1][NMAX - 1];
}
