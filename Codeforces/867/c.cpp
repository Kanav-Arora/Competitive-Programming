#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int tests;
    cin >> tests;

    while (tests--)
    {
        long long val;
        cin >> val;
        cout << val * val + 2 * val + 2 << endl;
    }
    return 0;
}