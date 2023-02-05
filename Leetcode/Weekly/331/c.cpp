#include <iostream>
#include <vector>
using namespace std;

/*
    This solution is combination of binary search and dynamic programming
*/

class Solution
{
public:
    int solve(vector<int> &num, int mid, int ind, vector<int> &dp)
    {
        if (ind >= num.size())
        {
            return 0;
        }
        if (dp[ind] != -1)
        {
            return dp[ind];
        }

        int nt = solve(num, mid, ind + 1, dp);

        if (num[ind] <= mid)
        {
            return dp[ind] = max(solve(num, mid, ind + 2, dp) + 1, nt);
        }
        return dp[ind] = nt;
    }

    bool func(vector<int> &num, int mid, int req_val)
    {
        vector<int> dp(num.size());
        for (int ind = 0; ind < num.size(); ind++)
        {
            dp[ind] = -1;
        }
        int maxi = solve(num, mid, 0, dp);
        return maxi >= req_val;
    }

    int minCapability(vector<int> &nums, int k)
    {
        int h_val = 0;
        int l_val = 1000000000;
        while (h_val + 1 < l_val)
        {
            int m = h_val + (l_val - h_val) / 2;
            if (func(nums, m, k))
            {
                l_val = m;
            }
            else
            {
                h_val = m;
            }
        }

        return l_val;
    }
};

int main()
{

    return 0;
}