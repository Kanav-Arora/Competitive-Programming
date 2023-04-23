#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
    vector<int> findColumnWidth(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> ans(m, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int val = grid[i][j];
                string s = to_string(val);
                ans[j] = max(ans[j], s.length());
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}