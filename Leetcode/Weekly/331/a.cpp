#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

class Solution
{
public:
    long long pickGifts(vector<int> &gifts, int k)
    {
        priority_queue<int> pq; // declaring max heap
        for (auto a : gifts)
            pq.push(a); // pushing all values in max heap

        while (k--) // pop max element; take floor of sqrt and push to pq; do this operation k times
        {
            int val = pq.top();
            pq.push(floor(sqrt(val)));
            pq.pop();
        }

        long long sum = 0; // sum of all elements in heap
        while (!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};

int main()
{

    return 0;
}