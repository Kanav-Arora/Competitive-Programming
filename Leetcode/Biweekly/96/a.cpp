#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int getCommon(vector<int> &nums1, vector<int> &nums2)
    {
        set<int> s(nums1.begin(), nums1.end());
        for (int i = 0; i < nums2.size(); i++)
        {
            if (s.find(nums2[i]) != s.end())
                return nums2[i];
        }
        return -1;
    }
};

int main()
{

    return 0;
}