#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, sum;
    cin >> n >> sum;
    vector<int> coins;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        coins.push_back(val);
    }
    int dp[n + 1][sum + 1];
    for (int i = 0; i <= sum; i++)
    {
        if (i % coins[0] == 0)
            dp[0][i] = i / coins[0];
        else
            dp[0][i] = 1e9;
    }

    for (int ind = 1; ind <= n; ind++)
    {
        for (int s = 0; s <= sum; s++)
        {
            int dont = dp[ind - 1][s];
            int take = 1e9;
            if (coins[ind] <= sum)
                take = 1 + dp[ind][s - coins[ind]];
            dp[ind][s] = min(dont, take);
        }
    }

    int call = dp[n - 1][sum];
    int ans = call != 1e9 ? call : -1;
    cout << ans << endl;
    return 0;
}