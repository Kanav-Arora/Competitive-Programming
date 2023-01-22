#include <iostream>
#include <vector>
using namespace std;

int val;
bool comp(vector<int> &v1, vector<int> &v2)
{
    return v1[val] > v2[val];
}

class Solution
{
private:
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k)
    {
        val = k;
        sort(score.begin(), score.end(), comp);
        return score;
    }
};

int main()
{

    return 0;
}