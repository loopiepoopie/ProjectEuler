//the hardest part of the problem was reading the statement and trying
//to understand what it meant
//I don't think this deserves a 25%
//0.4s
//just label the nodes and then permute the first 10 numbers, checking if the sums are ok
//after that, just find the minimum external node, create the string and compare it 
//lexicographically
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <map>
#define ll long long
using namespace std;

int v[11];

string rep[11];

//9,4,1;10,1,3;6,3,5;7,5,2;8,2,4

bool cmp(string a, string b)
{
    if (a.size() != b.size())
        return a.size() < b.size();
    return a < b;
}

signed main()
{
    int i, j;
    string ans = "";
    for (i = 1; i <= 10; i++)
        v[i] = i;
    do
    {
        if (v[1] + v[2] + v[3] == v[6] + v[3] + v[4]
            and v[1] + v[2] + v[3] == v[5] + v[4] + v[7]
            and v[1] + v[2] + v[3] == v[8] + v[7] + v[9]
            and v[1] + v[2] + v[3] == v[10] + v[9] + v[2]
            )
        {
            for (i = 1; i <= 10; i++)
                if (v[i] <= 9)
                    rep[i] = v[i] + '0';
                else
                    rep[i] = "10";
            string path[10], ceva;
            int first[10];
            first[0] = v[1];
            path[0] = rep[1] + rep[2] + rep[3];
            first[1] = v[6];
            path[1] = rep[6] + rep[3] + rep[4];
            first[2] = v[5];
            path[2] = rep[5] + rep[4] + rep[7];
            first[3] = v[8];
            path[3] = rep[8] + rep[7] + rep[9];
            first[4] = v[10];
            path[4] = rep[10] + rep[9] + rep[2];

            int mn = 11;
            int poz = -1;
            for (i = 0; i < 5; i++)
                if (mn > first[i])
                {
                    mn = first[i];
                    poz = i;
                }
            for (i = poz; i < 5; i++)
                ceva += path[i];
            for (i = 0; i < poz; i++)
                ceva += path[i];

            if (ceva.size() == 16)
                ans = max(ans, ceva);
        }
    }
    while (next_permutation(v + 1, v + 11));
    cout << ans;
}

