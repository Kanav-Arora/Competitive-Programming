class Solution {
public:
    bool check_val_num(long long n, int target)
    {
        int sumation = 0;
        while (n)
        {
            sumation += (n % 10);
            n /= 10;
        }
        return sumation <= target;
    }
    long long makeIntegerBeautiful(long long n, int target)
    {
        long long sumation = 0, position = 10;

        while (true)
        {
            if (check_val_num(n, target))
            {
                return sumation;
            }
            else
            {
                long long temporary = position - (n % position);
                n += temporary;
                sumation += temporary;
                position *= 10;
            }
        }
        return sumation;
    }
};