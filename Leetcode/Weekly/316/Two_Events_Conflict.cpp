class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        string s1 = event1[0];
        string e1 = event1[1];
        string s2 = event2[0];
        string e2 = event2[1];
        if(s2<=e1 && e2>=s1) return true;
        return false;
    }
};