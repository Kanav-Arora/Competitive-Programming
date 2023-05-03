#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
    int getMin(map<int, int> &mp, int x)
    {
        int smallest = 0;
        for (auto i : mp)
        {
            if (i.first < 0)
            {
                smallest += i.second;
            }
            else
            {
                return 0;
            }
            if (smallest >= x)
                return i.first;
        }
        return 0;
    }

public:
    vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x)
    {
        int n = nums.size();
        map<int, int> mp;
        for (int i = 0; i < k; i++)
        {
            mp[nums[i]]++;
        }
        vector<int> ans(n - k + 1, 0);
        ans[0] = getMin(mp, x);
        for (int i = k; i < n; i++)
        {
            mp[nums[i]]++;
            mp[nums[i - k]]--;
            if (mp[nums[i - k]] == 0)
                mp.erase(nums[i - k]);
            ans[i - k + 1] = getMin(mp, x);
        }
        return ans;
    }
};

int main()
{
    return 0;
}