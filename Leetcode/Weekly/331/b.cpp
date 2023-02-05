#include <iostream>
#include <vector>
using namespace std;

/*
    This function is solved using prefix sum array

    ith index of sum vector denotes the count of words in range (0,i) - inclusive which are valid.

    Now according to question, valid words are words that start and end with a vowel
*/

class Solution
{
private:
    bool valid(string s) // returns bool whether a word is valid or not
    {
        int n = s.length() - 1;
        if ((s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') && (s[n] == 'a' || s[n] == 'e' || s[n] == 'i' || s[n] == 'o' || s[n] == 'u'))
            return true;
        return false;
    }

public:
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        vector<int> sum(words.size(), 0); // initialize with zeroes
        sum[0] = valid(words[0]);
        for (int i = 1; i < words.size(); i++) // iterate of words and save the count in respective indexes in sum vector
        {
            sum[i] = sum[i - 1] + valid(words[i]);
        }
        vector<int> ans;
        for (auto i : queries)
        {
            int u = i[0];
            int v = i[1];

            if (u == 0)
                ans.push_back(sum[v]);
            else
                ans.push_back(sum[v] - sum[u - 1]);
        }
        return ans;
    }
};

int main()
{

    return 0;
}