#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define big 1000000000

vector<ll> P(1000001);

void solve()
{

    ll inp;
    cin >> inp;

    vector<ll> arr(inp);

    for (int i = 0; i < inp; i++)
    {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());

    map<ll, ll> count;
    unordered_map<ll, ll> mp;
    ll val = 0;

    for (int i = 0; i < inp; i++)
    {

        count[arr[i]]++;
    }

    for (auto itr = count.rbegin(); itr != count.rend(); itr++)
    {
        auto p = *itr;
        for (ll j = 2; j <= 1000; j++)
        {
            if (j * p.first > 1e6)
                break;
            if (count.find(p.first * j) != count.end())
            {
                mp[p.first * big + j] += count[p.first * j] * p.second;
                if (mp.find(p.first * j * big + j) != mp.end())
                {
                    val += mp[p.first * j * big + j] * p.second;
                }
            }
        }
    }

    for (auto p : count)
    {
        val += p.second * (p.second - 1) * (p.second - 2);
    }

    cout << val << "\n";
}

int main()
{
    ll t, inp, a1, b1, c1;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}