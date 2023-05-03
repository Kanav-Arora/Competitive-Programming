#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string smallestBeautifulString(string s, int k)
    {
        int n = (int)s.size();
        int pos = -1;

        for (int i = n - 1; i >= 0 && pos < 0; i--)
        {
            int cur = s[i] - 'a';
            cur++;
            while (cur < k && pos < 0)
            {
                bool isPal = false;
                if (i - 1 >= 0 && (s[i - 1] - 'a') == cur)
                    isPal = true;
                if (i - 2 >= 0 && (s[i - 2] - 'a') == cur)
                    isPal = true;
                if (!isPal)
                {
                    s[i] = (char)(cur + 'a');
                    pos = i;
                }
                cur++;
            }
        }

        if (pos < 0)
            return "";

        for (int i = pos + 1; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                bool isPal = false;
                if (i - 1 >= 0 && (s[i - 1] - 'a') == j)
                    isPal = true;
                if (i - 2 >= 0 && (s[i - 2] - 'a') == j)
                    isPal = true;
                if (!isPal)
                {
                    s[i] = (char)(j + 'a');
                    break;
                }
            }
        }

        return s;
    }
};

int main()
{

    return 0;
}