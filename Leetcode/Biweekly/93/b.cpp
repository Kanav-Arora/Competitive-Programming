#include <iostream>
using namespace std;

class Solution
{
public:
    int maxStarSum(vector<int> &vals, vector<vector<int>> &edges, int k)
    {
        int n = vals.size(), ans = INT_MIN;

        vector<vector<int>> vec_sum(n);

        for (int i = 0; i < edges.size(); i++)
        {
            if (vals[edges[i][1]] > 0)
                vec_sum[edges[i][0]].push_back(vals[edges[i][1]]);
            if (vals[edges[i][0]] > 0)
                vec_sum[edges[i][1]].push_back(vals[edges[i][0]]);
        }

        for (int i = 0; i < n; i++)
        {
            sort(vec_sum[i].rbegin(), vec_sum[i].rend());

            int t = vals[i];
            for (int j = 0; j < min(k, (int)vec_sum[i].size()); j++)
                t += vec_sum[i][j];
            ans = max(ans, t);
        }

        return ans;
    }
};

int main()
{

    return 0;
}