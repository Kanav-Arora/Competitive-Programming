#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int alternateDigitSum(int n)
    {
        string val = to_string(n);
        int tot = 0;
        for (int i = 1; i <= val.length(); i++)
        {
            if (i % 2 == 1)
            {
                tot += int(val[i - 1] - '0');
            }
            else
                tot -= int(val[i - 1] - '0');
        }
        return tot;
    }
};

int main()
{

    return 0;
}