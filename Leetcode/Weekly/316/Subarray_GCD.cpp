class Solution {
public:
    int subarrayGCD(vector<int> vector_num, int target)
    {
        int resultant = 0;
        int n = vector_num.size();
        for (int i = 0; i < vector_num.size(); i++)
        {
            int curr_val_gcd = 0;

            for (int j = i; j < n; j++)
            {
                curr_val_gcd = gcd(curr_val_gcd, vector_num[j]);

                resultant += (curr_val_gcd == target) ? 1 : 0;
            }
        }
        return resultant;
    }
    static int gcd(int v1, int v2)
    {
        if (v2 == 0)
            return v1;
        return gcd(v2, v1 % v2);
    }
};