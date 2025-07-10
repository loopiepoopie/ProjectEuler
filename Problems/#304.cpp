/*
I didn't think of matrix exponentiation at all, some my solution is just a tad complicated
We learn about pisano periods and that for that mod, which is 3 * 7 * 13 * 67 * 107 * 630803, we 
decide to solve the problem for each prime factor, and then solve a modulus congruence equation using 
Chinese Remainder Theorem
Getting the primes is just a sieve for all primes less than sqrt(10^14), and getting the sum is just 
brute force + pisano periods, because pi(630803) = 1261608, which means at most 13 mil brute forced
fibonacci numbers, so it's doable 
It runs in aprox. 0.3s, which is just good enough, although 
*/
#include <fstream>
#include <iostream>
#include <cassert>
#include <vector>
#define ll long long
using namespace std;

const int VMAX = 1e7;

bool viz[VMAX + 1];

vector <int> primes;

void ciur()
{
    int i, j;
    for (i = 2; i <= VMAX; i++)
        if (!viz[i])
        {
            primes.push_back(i);
            for (j = i * 2; j <= VMAX; j += i)
                viz[j] = 1;
        }
}

vector <ll> ofof;

const int DELTA = 5e6;

bool ciur2[DELTA + 1];

const ll BOUND = 1e14;
const int WORST = 1261608;
const ll MOD = 1234567891011;
const ll EH = 900788112; //pisano period of MOD
//just calculated it in case it was smaller to do
//brute force, but crt is the case here unfortunately

int pisano[] = {8, 16, 28, 136, 72, 1261608};
int facts[] = {3, 7, 13, 67, 107, 630803};
int resturi[6];

ll fib[WORST];

ll pwr(ll a, ll b, ll mod)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

/*
x = a mod b
x = c mod d

x = b t + a
c = b t + a mod d
c = r t + r' mod d
c - r' = r t mod d
t = (c - r') * (r^-1) mod d
t = alfa mod d
t = Md + alfa

x = b (Md + alfa) + a
x = Mdb + b alfa + a
x = b alfa + a mod (db)

done!
*/

pair <ll, ll> crt(pair <ll, ll> a, pair <ll, ll> b)
{
    ll A = a.first;
    ll B = a.second;
    ll C = b.first;
    ll D = b.second;

    ll r = B % D;
    ll rprim = A % D;
    ll alfa = (C - rprim + D) % D * pwr(r, D - 2, D) % D;

    ll lcm = B * D;
    ll t = (alfa * B % lcm + A) % lcm;
    assert(t % B == A);
    assert(t % D == C);
    return {t, lcm};
}

int main()
{
    ll i, j;
    ciur();
    for (int x : primes)
    {
        ll first = BOUND / x * x;
        if (first < BOUND)
            first += x;
        for (i = first; i <= BOUND + DELTA; i += x)
            ciur2[i - BOUND] = 1;
    }
    for (i = BOUND; i <= BOUND + DELTA and ofof.size() < 1e5; i++)
        if (!ciur2[i - BOUND])
            ofof.push_back(i);
    /*ofstream g("grup.out");
    for finding the pisano period, just replace MOD
    with whatever you need
    and ofc search up how to calculate it
    int a, b, c;
    a = 0;
    b = 1;
    g << a << "\n" << b << "\n";
    for (int i = 3; i <= 2 * WORST; i++)
    {
        c = (a + b) % MOD;
        g << c << "\n";
        a = b;
        b = c;
    }*/
    fib[0] = 0;
    fib[1] = 1;
    for (i = 2; i < WORST; i++)
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    for (i = 0; i < 6; i++)
    {
        ll sum = 0;
        for (ll x : ofof)
            sum = (sum + fib[x % pisano[i]] % facts[i]) % facts[i];
        assert(sum < facts[i]);
        resturi[i] = sum;
    }
    pair <ll, ll> eq = {resturi[0], facts[0]};
    for (i = 1; i < 6; i++)
        eq = crt(eq, {resturi[i], facts[i]});
    cout << eq.first << " " << eq.second;
}
