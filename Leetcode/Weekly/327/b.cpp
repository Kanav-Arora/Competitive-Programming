#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long maxKelements(vector<int> &nums, int k)
{
    priority_queue<long long> pq;

    for (auto a : nums)
        pq.push(a);

    long long val = 0;
    while (k--)
    {
        long long top = pq.top();
        pq.pop();
        val += top;
        pq.push(ceil((float)(top / 3)));
        cout << top << endl;
    }
    return val;
}

int main()
{

    return 0;
}