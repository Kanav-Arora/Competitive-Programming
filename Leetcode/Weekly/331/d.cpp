#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    typedef long long ll;

    long long minCost(vector<int> &vec1, vector<int> &vec2)
    {
        map<ll, ll> mp;
        int size = vec1.size();
        ll x = vec2[size - 1];

        for (int i = 0; i < size; i++)
        {
            mp[vec1[i]]++;
            mp[vec2[i]]--;
        }

        bool flag = false;
        vec1.clear();
        vec2.clear();

        ll mi = x;

        for (auto i : mp)
        {
            mi = min(mi, i.first);
            x = abs(i.second);

            if (x % 2)
                flag = true;

            x = i.second;

            if (x > 0)
            {
                x /= 2;

                while (x--)
                    vec1.push_back(i.first);
            }
            else if (x < 0)
            {
                x = abs(x) / 2;

                while (x--)
                    vec2.push_back(i.first);
            }
        }

        if (flag)
        {
            return -1;
        }

        reverse(vec2.begin(), vec2.end());

        ll ans = 0;

        for (int i = 0; i < vec1.size(); i++)
            ans += min(2 * mi, 1ll * min(vec1[i], vec2[i]));

        return ans;
    }
};

int main()
{

    return 0;
}