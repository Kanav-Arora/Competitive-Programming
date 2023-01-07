#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int xorBeauty(vector<int> &nums)
    {
        int m = 0;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            m ^= nums[i];
        }
        return m;
    }
};

int main()
{

    return 0;
}