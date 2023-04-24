#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    int inp;
    cin >> inp;
    string str;
    cin >> str;

    vector<int> count_vec(26, 0), count_vec2(26, 0);

    for (int i = 0; i < inp / 2; i++)
    {
        if (str[i] == str[inp - i - 1])
            count_vec[str[i] - 'a']++;
    }

    for (int i = 0; i < inp; i++)
    {
        count_vec2[str[i] - 'a']++;
    }

    int var1 = 0, maxi = 0, maxi2 = 0;

    for (int i : count_vec)
    {
        var1 += i;
        maxi = max(maxi, i);
    }

    for (int i : count_vec2)
    {
        maxi2 = max(maxi2, i);
    }

    if (maxi2 > inp / 2 || (inp & 1))
    {
        cout << "-1\n";
        return;
    }
    else
    {
        if (maxi > var1 - maxi)
        {
            cout << maxi << "\n";
        }
        else
        {
            cout << var1 / 2 + (var1 & 1) << "\n";
        }
    }
}

int main()
{
    ll t, inp, x1, y1, x2, y2;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}