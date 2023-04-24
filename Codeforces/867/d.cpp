#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int tests;
    cin >> tests;

    while (tests--)
    {
        int inp;
        cin >> inp;

        if (inp == 1)
        {
            cout << "1" << endl;
            continue;
        }

        if (inp & 1)
        {
            cout << "-1" << endl;
            continue;
        }

        vector<int> arr;

        for (int i = 0; i < inp / 2; i++)
        {
            arr.push_back(i);
            arr.push_back(inp - i - 1);
        }

        int c_val = 0;

        cout << inp << " ";

        for (int i = 0; i < inp - 1; i++)
        {
            c_val += i;
            cout << (arr[i + 1] - arr[i] + inp) % inp << " ";
        }
        cout << endl;
    }
    return 0;
}
