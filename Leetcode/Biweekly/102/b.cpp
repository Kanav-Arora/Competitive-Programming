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

    vector<long long> findPrefixScore(vector<int> &nums)
    {
        long long sum = 0;
        int maxi = 0;
        vector<long long> ans;
        for (auto i : nums)
        {
            maxi = max(maxi, i);
            int conv = maxi + i;
            sum += conv;
            ans.push_back(sum);
        }
        return ans;
    }
};

int main()
{

    return 0;
}