//just do the graph and then try it out, 60 * 1000000 is pretty quick
//you can even be quicker by memorizing the already calculated results
//that will result in only 1000000 iterations
//0.15s
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <map>
#define ll long long
using namespace std;

const int VMAX = 2500000; //9!*6 = 2177280
const int NEED = 1e6;

int nxt[VMAX];
bool viz[VMAX];
int chain[VMAX];

int facts[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

vector <int> who;

signed main()
{
    int i, j;
    for (i = 1; i <= NEED; i++)
    {
        int aux = i;
        while (aux)
        {
            nxt[i] += facts[aux % 10];
            aux /= 10;
        }
    }
    int cnt = 0;
    for (i = 1; i <= NEED; i++)
    {
        if (chain[i] == 0)
        {
            for (j = i; !viz[j] and who.size() < 60 and chain[j] == 0; j = nxt[j])
            {
                who.push_back(j);
                viz[j] = 1;
            }
            chain[i] = chain[j] + who.size();
            int ax = chain[i];
            for (int x : who)
            {
                if (x != i)
                {
                    chain[x] = --ax;
                }
                viz[x] = 0;
            }
            who.clear();
        }
        if (chain[i] == 60)
            cnt++;
    }
    cout << cnt;
}
