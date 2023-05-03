#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int isWinner(vector<int> &player1, vector<int> &player2)
    {
        int n = player1.size();
        int sum1 = 0, sum2 = 0;
        sum1 += player1[0];
        sum2 += player2[0];
        if (n == 1)
            return sum1 >= sum2 ? (sum1 == sum2 ? 0 : 1) : 2;
        sum1 += player1[0] == 10 ? 2 * player1[1] : player1[1];
        sum2 += player2[0] == 10 ? 2 * player2[1] : player2[1];

        for (int i = 2; i < n; i++)
        {
            sum1 += (player1[i - 1] == 10 || player1[i - 2] == 10) ? 2 * player1[i] : player1[i];
            sum2 += (player2[i - 1] == 10 || player2[i - 2] == 10) ? 2 * player2[i] : player2[i];
            cout << sum1 << " " << sum2 << endl;
        }

        return sum1 >= sum2 ? (sum1 == sum2 ? 0 : 1) : 2;
    }
};

int main()
{

    return 0;
}