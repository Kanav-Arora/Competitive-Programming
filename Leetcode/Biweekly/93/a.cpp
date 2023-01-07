#include <iostream>
using namespace std;

class Solution
{
public:
    int maximumValue(vector<string> &strs)
    {
        int maxi = 0;

        for (auto each : strs)
        {
            bool dig = true;

            for (int i = 0; i < each.length(); i++)
            {
                if (isdigit(each[i]))
                    continue;
                else
                    dig = false;
            }

            if (dig == true)
            {
                maxi = maxi > stoi(each) ? maxi : stoi(each);
            }
            else
                maxi = maxi > each.length() ? maxi : each.length();
        }

        return maxi;
    }
};

int main()
{

    return 0;
}