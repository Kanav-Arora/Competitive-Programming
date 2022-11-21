class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<char,int> mp;
        
        for(int i=0; i<s.length(); i++)
        {
            if(mp.count(s[i]))
            {
                mp[s[i]]= i-mp[s[i]]-1;
            }
            else
                mp[s[i]]= i;
        }
        
        for(int i=0; i<distance.size(); i++)
        {
            if(mp.find(i+'a') != mp.end() && mp[i+'a']!=distance[i])
                return false;
        }
        
        return true;
    }
};