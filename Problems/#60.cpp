//I am too lazy to try to optimise finding a clique of 5 elements
//Some thought of O(n^5), I decided to use a backtracking instead
//0.58s almost 0.6s
//The most time consuming part is the precalc, maybe that could be
//reduced, even though you kind of need the whole graph to solve the
//problem
//Haha, I don't know how I could've solved these problems when I was
//14-15 years old. No use of backtracking and graph theory :P
#include <iostream>
#include <climits>
#include <cassert>
#include <cctype>
#include <cstring>
#include <vector>
#include <unordered_set>
#include <algorithm>
#define ll long long
using namespace std;

const int NMAX = 9000;

bool prime(int x)
{
    for (int d = 3; d * d <= x; d += 2)
        if (x % d == 0)
            return false;
    return true;
}

unordered_set <int> g[NMAX + 1];

bool viz[NMAX + 1];

vector <int> primes;

vector <int> who;
int sum;

bool ok(int nou)
{
    for (int x : who)
        if (g[x].find(nou) == g[x].end())
            return false;
    return true;
}

void dfs(int x)
{
    who.push_back(x);
    sum += x;
    viz[x] = 1;
    if (who.size() == 5)
    {
        cout << sum;
        exit(0);
    }
    for (int y : g[x])
        if (!viz[y] and ok(y))
        {
            dfs(y);
        }
    who.pop_back();
    sum -= x;
    viz[x] = 0;
}

signed main()
{
    int i, j;
    for (i = 3; i <= NMAX; i += 2)
        if (prime(i))
            primes.push_back(i);
    for (i = 0; i < primes.size(); i++)
        for (j = i + 1; j < primes.size(); j++)
        {
            int p1, p2;
            p1 = p2 = 1;
            for (int x = primes[i]; x; x /= 10)
                p1 *= 10;
            for (int x = primes[j]; x; x /= 10)
                p2 *= 10;
            if (prime(primes[i] * p2 + primes[j]) and
                    prime(primes[j] * p1 + primes[i]))
            {
                g[primes[i]].insert(primes[j]);
                g[primes[j]].insert(primes[i]);
            }
        }
    for (int x : primes)
        dfs(x);
}
