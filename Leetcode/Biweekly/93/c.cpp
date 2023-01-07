#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxJump(vector<int> &inp)
    {
        int ans = inp[1] - inp[0];
        for (int i = 2; i < inp.size(); i++)
        {
            int t = inp[i] - inp[i - 1] + inp[i - 1] - inp[i - 2];
            ans = max(ans, t);
        }
        return ans;
    }
};

int main()
{

    return 0;
}