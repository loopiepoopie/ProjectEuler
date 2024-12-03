//I've come up with just Dijkstra's, because if there were negative values, you had the chance of having 
//negative cycles, which basically rendered the problem NP 
//But here there are no negative values, so Dijkstra's works. 
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define ll long long
using namespace std;

const int NMAX = 80;
const int DIR = 4;
const int LEN = 1e6;
const int INF = 1e9;

int d[NMAX][NMAX];

int v[NMAX][NMAX];
char s[LEN];

//0 - I come from N
//1 - I come from S
//2 - I come from E
//3 - I come from W

int di[] = {-1, +1, +0, +0};
int dj[] = {+0, +0, +1, -1};
int op[] = {1, 0, 3, 2};

struct ob
{
    int i, j;
    int val;
};

bool operator <(ob a, ob b)
{
    return a.val > b.val;
}

priority_queue <ob> pq;

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
            d[i][j] = INF;
    d[0][0] = v[0][0];
    pq.push({0, 0, 0});
    while (!pq.empty())
    {
        ob f = pq.top();
        pq.pop();
        for (i = 0; i < DIR; i++)
        {
            int ni = f.i + di[i];
            int nj = f.j + dj[i];
            if (ni >= 0 and ni < NMAX and nj >= 0 and nj < NMAX)
            {
                if (d[ni][nj] > d[f.i][f.j] + v[ni][nj])
                {
                    d[ni][nj] = d[f.i][f.j] + v[ni][nj];
                    pq.push({ni, nj, d[ni][nj]});
                }
            }
        }
    }
    cout << d[NMAX - 1][NMAX - 1];
}
