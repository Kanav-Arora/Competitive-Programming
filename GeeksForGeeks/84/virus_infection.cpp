#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    int solve(string s, int k)
    {
        stack<int> stk;
        int prev = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
            {
                if (prev != 0)
                {
                    prev--;
                }
                else
                {
                    stk.push(i);
                }
            }

            else
            {
                while (!stk.empty() && i - k <= stk.top())
                {
                    stk.pop();
                }

                prev = k;
            }
        }

        return s.length() - stk.size();
    }
};

int main()
{

    return 0;
}