#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> rowc(n, 0);
        vector<int> colc(m, 0);
        unordered_map<int, pair<int, int>> mp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                mp[mat[i][j]] = {i, j};
            }
        }
        for (int i = 0; i < arr.size(); i++)
        {
            int k = mp[arr[i]].first;
            int l = mp[arr[i]].second;
            rowc[k]++;
            colc[l]++;

            if (rowc[k] == m || colc[l] == n)
                return i;
        }
        return 0;
    }
};

int main()
{

    return 0;
}