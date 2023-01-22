#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool makeStringsEqual(string str1, string fin_str)
    {
        if (str1 == fin_str)
            return true;

        int set_s = 0, set_fin_str = 0;

        for (int i = 0; i < str1.length(); i++)
        {
            if (str1[i] == '1')
                set_s++;
            if (fin_str[i] == '1')
                set_fin_str++;
        }

        if ((set_s >= 1 && set_fin_str == 0) || (set_s == 0 && set_fin_str >= 1))
            return false;

        return true;
    }
};

int main()
{

    return 0;
}