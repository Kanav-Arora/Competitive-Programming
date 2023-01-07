#include <iostream>
using namespace std;

class Solution
{
public:
    string categorizeBox(int length, int width, int height, int mass)
    {
        bool bulky = false;
        bool heavy = false;

        long long int vol = length;
        vol = vol * width;
        vol = vol * height;

        if (length >= 1e4 || width >= 1e4 || height >= 1e4 || vol >= 1e9)
            bulky = true;
        if (mass >= 100)
            heavy = true;

        string ans = "";

        if (bulky && heavy)
            ans = "Both";
        else if (!bulky && !heavy)
            ans = "Neither";
        else if (bulky && !heavy)
            ans = "Bulky";
        else
            ans = "Heavy";

        return ans;
    }
};

int main()
{

    return 0;
}