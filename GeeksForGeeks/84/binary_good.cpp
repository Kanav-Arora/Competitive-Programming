#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int solve(string str, int n)
    {
        vector<int> vals;
        int cnt = 0;

        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '1')
                cnt++;
            else if (str[i] == '0' && cnt > 0)
            {
                vals.push_back(cnt);
                cnt = 0;
            }
        }

        if (cnt > 0)
            vals.push_back(cnt);

        if (vals.size() == 0)
            return 0;

        sort(vals.begin(), vals.end());
        int ans = 0;
        int mid = vals[vals.size() / 2];

        for (auto a : vals)
            ans += abs(a - mid);
        return ans;
    }
};

int main()
{

    return 0;
}