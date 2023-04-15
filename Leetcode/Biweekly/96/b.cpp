#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    long long minOperations(vector<int> &n1, vector<int> &n2, int k)
    {
        long long ans = 0;
        if (k == 0)
        {
            for (int i = 0; i < n1.size(); i++)
            {
                if (n1[i] != n2[i])
                    return -1;
            }
            return 0;
        }

        long long in = 0, dc = 0;
        for (int i = 0; i < n1.size(); i++)
        {
            if (n1[i] < n2[i])
            {
                long long diff = n2[i] - n1[i];

                if (diff % k != 0)
                    return -1;

                long long q = diff / k;

                if (in >= q)
                {
                    in -= q;
                }
                else
                {
                    q -= in;
                    in = 0;
                    dc += q;
                    ans += q;
                    q = 0;
                }
            }
            else
            {
                long long diff = n1[i] - n2[i];

                if (diff % k != 0)
                    return -1;

                long long q = diff / k;

                if (dc >= q)
                {
                    dc -= q;
                }
                else
                {
                    q -= dc;
                    dc = 0;
                    in += q;
                    ans += q;
                    q = 0;
                }
            }
        }

        if (in == 0 and dc == 0)
            return ans;
        return -1;
    }
};

int main()
{

    return 0;
}