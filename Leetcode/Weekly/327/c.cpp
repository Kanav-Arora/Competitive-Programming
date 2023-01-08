#include <iostream>
#include <vector>
using namespace std;

bool isItPossible(string word1, string word2)
{
    vector<int> vec1(26, 0), vec2(26, 0);

    for (auto ele : word1)
        vec1[ele - 'a']++;
    for (auto ele : word2)
        vec2[ele - 'a']++;

    int counter_val = 0;

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (vec1[i] == 0 || vec2[j] == 0)
                continue;

            vec1[i]--;
            vec2[j]--;
            vec1[j]++;
            vec2[i]++;
            counter_val = 0;

            for (int k = 0; k < 26; k++)
            {
                if (vec1[k] > 0)
                    counter_val++;
                if (vec2[k] > 0)
                    counter_val--;
            }

            if (counter_val == 0)
                return true;

            vec1[i]++;
            vec2[j]++;
            vec1[j]--;
            vec2[i]--;
        }
    }
    return false;
}

int main()
{

    return 0;
}