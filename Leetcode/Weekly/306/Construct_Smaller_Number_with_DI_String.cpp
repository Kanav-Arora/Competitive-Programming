class Solution {
public:
    string smallestNumber(string seq) {
        string result;
    stack<int> s;
    for (int i = 0; i <= seq.length(); i++)
    {
        s.push(i + 1);          // push i+1 bcoz output is in 1 based indexing
        if (i == seq.length() || seq[i] == 'I')             // is we encounter 'I' start popping elements from stack
        {
            while (!s.empty())
            {
                result += to_string(s.top());
                s.pop();
            }
        }
    }
    return result;
    }
};