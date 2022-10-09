#include <iostream>
using namespace std;

int main()
{
    int cases_in_test;
    cin >> cases_in_test;
    while (cases_in_test--)
    {
        int num_1;
        cin >> num_1;
        string s_ans;
        cin >> s_ans;
        string cases_in_test = "";
        int ptr_1 = 0;
        int ptr_2 = num_1 - 1;
        while (ptr_1 <= ptr_2)
        {
            if (s_ans[ptr_1] == '0')
            {
                cases_in_test = s_ans[ptr_1] + cases_in_test;
            }
            else
                cases_in_test = cases_in_test + s_ans[ptr_1];
            if (ptr_1 < ptr_2)
            {
                if (s_ans[ptr_2] == '0')
                    cases_in_test = cases_in_test + s_ans[ptr_2];
                else
                    cases_in_test = s_ans[ptr_2] + cases_in_test;
                ptr_2--;
            }
            ptr_1++;
        }
        cout << cases_in_test << endl;
    }
    return 0;
}