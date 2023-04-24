#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int tests;
    cin >> tests;

    while (tests--)
    {
        int n;
        cin >> n;
        int t;
        cin >> t;
        vector<int> time;
        int temp = n;
        while (temp--)
        {
            int val;
            cin >> val;
            time.push_back(val);
        }
        temp = n;
        vector<int> value;
        while (temp--)
        {
            int val;
            cin >> val;
            value.push_back(val);
        }
        pair<int, int> ans = make_pair(-1, 0);
        for (int i = 0; i < n; i++)
        {
            if (time[i] <= t && value[i] > ans.second)
            {
                ans = make_pair(i, value[i]);
            }
            t--;
        }
        if (ans.first == -1)
        {
            cout << -1 << endl;
            continue;
        }
        cout << ans.first + 1 << endl;
    }
    return 0;
}