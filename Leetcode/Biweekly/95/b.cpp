#include <iostream>
using namespace std;

class DataStream
{
    int val;
    int occ;
    int last;

public:
    DataStream(int value, int k)
    {
        val = value;
        occ = k;
        last = 0;
    }

    bool consec(int num)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if (num == val)
        {
            last++;
        }
        else
        {
            last = 0;
        }
        if (last >= occ)
        {
            return true;
        }
        return false;
    }
};

int main()
{

    return 0;
}