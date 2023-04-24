#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<vector<ll>> vec1;
vector<ll> vec2;

void dfs(ll r_val, ll p_val)
{
    for (ll ele : vec1[r_val])
    {
        if (ele != p_val)
        {
            vec2[ele] = vec2[r_val] + 1;
            dfs(ele, r_val);
        }
    }
}

void solve()
{

    ll inp, k_val, k2_val, a_val, b_val;
    cin >> inp >> k_val >> k2_val;

    vec1.clear();
    vec2.resize(inp);

    vector<ll> vec_3;
    for (int i = 0; i < inp; i++)
    {
        vec1.push_back(vec_3);
        vec2[i] = 0;
    }

    for (int i = 0; i < inp - 1; i++)
    {
        cin >> a_val >> b_val;
        vec1[a_val - 1].push_back(b_val - 1);
        vec1[b_val - 1].push_back(a_val - 1);
    }

    dfs(0, -1);

    vector<ll> H2 = vec2;

    ll height = *max_element(vec2.begin(), vec2.end());
    ll node = max_element(vec2.begin(), vec2.end()) - vec2.begin();

    for (int i = 0; i < inp; i++)
    {
        vec2[i] = 0;
    }

    dfs(node, -1);

    ll ret_ans = 0;
    for (int i = 0; i < inp; i++)
    {
        ret_ans = max(ret_ans, vec2[i] * k_val - H2[i] * k2_val);
    }

    cout << ret_ans << "\n";
}

int main()
{
    ll tests, inp, z_var, x1_val, y1_val, x2_val, y2_val;
    cin >> tests;

    while (tests--)
    {
        solve();
    }

    return 0;
}