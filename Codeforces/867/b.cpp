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

        vector<long long> arr;
        while (inp--)
        {
            long long val;
            cin >> val;
            arr.push_back(val);
        }
        sort(arr.begin(), arr.end());
        cout << max(arr[0] * arr[1], arr.end()[-2] * arr.end()[-1]) << endl;
    }
    return 0;
}