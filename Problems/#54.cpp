#include <fstream>
#include <climits>
#include <cstring>
#include <vector>
#include <cassert>
#include <algorithm>
#define ll long long
using namespace std;

//first digit is the number of the hand
//bigger number, better hand
//the next one is the second most important number for the hand
//in case of equality
//the other are the rest of the cards in descending order

//I think I could've factorised code a bit better yet I just wanted
//for it to be functional and readable

const int NMAX = 100;
char s[NMAX + 1];

int index(char x)
{
    if (isdigit(x))
        return x - '0';
    switch(x)
    {
    case 'T':
        return 10;
    case 'J':
        return 11;
    case 'Q':
        return 12;
    case 'K':
        return 13;
    }
    return 14;
}

vector <int> flush(int suits[], int nrs[])
{
    vector <int> ans;
    int i;
    for (i = 'A'; i <= 'Z'; i++)
        if (suits[i - 'A'] == 5)
        {
            for (i = 14; i >= 2; i--)
                if (nrs[i] != 0)
                    ans.push_back(i);
            break;
        }
    return ans;
}

int straight(int suits[], int nrs[])
{
    int i;
    for (i = 2; i + 5 - 1 <= 14; i++)
        if (nrs[i] and nrs[i + 1] and nrs[i + 2] and nrs[i + 3] and nrs[i + 4])
            return i;
    return 0;
}

vector <int> compute_hand(int suits[], int nrs[])
{
    vector <int> ax, ax2;
    //royal flush
    if (nrs[14] and nrs[13] and nrs[12] and nrs[11] and nrs[10])
        return {10};
    int i = straight(suits, nrs);
    //straight flush
    if (i and !flush(suits, nrs).empty())
        return {9, i};
    //four of a kind
    int rest;
    int who = -1;
    for (i = 2; i <= 14; i++)
        if (nrs[i] == 4)
        {
            who = i;
        }
        else if (nrs[i] == 1)
            rest = i;
    if (who != -1)
        return {8, who, rest};
    //full house
    who = -1;
    rest = -1;
    for (i = 2; i <= 14; i++)
        if (nrs[i] == 3)
            who = i;
        else if (nrs[i] == 2)
            rest = i;
    if (who != -1 and rest != -1)
        return {7, who, rest};
    //flush
    ax = flush(suits, nrs);
    if (!ax.empty())
    {
        ax.insert(ax.begin(), 6);
        return ax;
    }
    //straight
    i = straight(suits, nrs);
    if (i)
        return {5, i};
    //three of a kind
    who = -1;
    for (i = 14; i >= 2; i--)
        if (nrs[i] == 3)
            who = i;
        else if (nrs[i] != 0)
            ax.push_back(i);
    if (who != -1)
    {
        ax.insert(ax.begin(), 4);
        return ax;
    }
    ax.clear();
    //two pairs
    for (i = 14; i >= 2; i--)
        if (nrs[i] == 2)
            ax.push_back(i);
        else if (nrs[i] != 0)
            ax2.push_back(i);
    if (ax.size() == 2)
    {
        for (i = ax2.size() - 1; i > -1; i--)
            ax.push_back(ax2[i]);
        ax.insert(ax.begin(), 3);
        return ax;
    }
    //one pair
    ax.clear();
    ax2.clear();
    for (i = 14; i >= 2; i--)
        if (nrs[i] == 2)
            ax.push_back(i);
        else if (nrs[i] != 0)
            ax2.push_back(i);
    if (ax.size() == 1)
    {
        for (int x : ax2)
            ax.push_back(x);
        ax.insert(ax.begin(), 2);
        return ax;
    }
    ax2.insert(ax2.begin(), 1);
    return ax2;
}

signed main()
{
    ifstream cin("ciorna.in");
    ofstream cout("ciorna.out");
    int i;
    int ans = 0;
    while (cin.getline(s, sizeof(s)))
    {
        char *p = strtok(s, " ");
        int suits['Z' - 'A' + 1] = {0};
        int dig[20] = {0};
        for (i = 1; i <= 5 and p; p = strtok(NULL, " "), i++)
        {
            int val = index(p[0]);
            dig[val]++;
            suits[p[1] - 'A']++;
        }
        vector <int> a1 = compute_hand(suits, dig);
        memset(suits, 0, sizeof(suits));
        memset(dig, 0, sizeof(dig));
        for (i = 6; i <= 10 and p; p = strtok(NULL, " "), i++)
        {
            int val = index(p[0]);
            dig[val]++;
            suits[p[1] - 'A']++;
        }
        vector <int> a2 = compute_hand(suits, dig);
        ans += (a1 > a2);
    }
    cout << ans;
}
