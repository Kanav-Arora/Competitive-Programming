#include <iostream>
#include <vector>
using namespace std;

int maximumCount(vector<int> &nums)
{
    int pos = 0;
    int neg = 0;

    for (auto a : nums)
    {
        if (a > 0)
            pos++;
        else if (a < 0)
            neg++;
    }
    return max(pos, neg);
}

int main()
{

    return 0;
}