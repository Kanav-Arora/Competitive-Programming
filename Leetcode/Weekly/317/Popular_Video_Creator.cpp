typedef pair<string, int> pairstrint;
typedef vector<vector<string>>  pairstrstr;

class Solution {
public:
    static bool compobj(pairstrint p1, pairstrint p2 ){
          if(p1.second!=p2.second) return p1.second>p2.second; 
           return p1.first<p2.first;
    }
    pairstrstr  mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string, vector<pairstrint >>mapper;
        int n= ids.size();
        unordered_map<string, long long>mapper_ii;
        for(int i=0;i<n;i++){
            mapper[creators[i]].push_back({ids[i], views[i]});
            mapper_ii[creators[i]]+=views[i];
        }
        
        long long maxi=-1;
        for(auto it:mapper_ii){
            maxi= max(maxi, it.second);
        }
        vector<string>resultant;
        for(auto it:mapper_ii){
            if(it.second==maxi) resultant.push_back(it.first);
        }
        
        pairstrstr resultant_1;
        for(auto x:resultant){
            vector<string>v;
            auto temp= mapper[x];
            sort(temp.begin(), temp.end(), compobj);
            v.push_back(x);
            v.push_back(temp[0].first);
            resultant_1.push_back(v);
        }
        return resultant_1;   
    }
};