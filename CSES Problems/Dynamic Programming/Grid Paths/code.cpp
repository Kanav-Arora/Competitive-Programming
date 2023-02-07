#include <iostream>
#include <vector>
using namespace std;

long long int mod = 1e9 + 7;

int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    // #endif
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n, ' '));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char inp;
            cin >> inp;
            grid[i][j] = inp;
        }
    }
    if (grid[0][0] == '*' || grid[n - 1][n - 1] == '*')
        cout << "0";
    else
    {
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] != '*')
                {
                    if (i > 0)
                    {
                        dp[i][j] += dp[i - 1][j];
                        dp[i][j] %= mod;
                    }
                    if (j > 0)
                    {
                        dp[i][j] += dp[i][j - 1];
                        dp[i][j] %= mod;
                    }
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        cout << dp[n - 1][n - 1];
    }
    return 0;
}