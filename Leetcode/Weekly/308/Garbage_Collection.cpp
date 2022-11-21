class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int lm = 0;
        int lg = 0;
        int lp =0;
        
        int m = 0;
        int g =0;
        int p = 0;
        
        for(int i=0; i<garbage.size(); i++)
        {
            for(int j=0; j<garbage[i].size();j++)
            {
                if(garbage[i][j]=='M')
                {
                    m++;
                    lm = m;
                }
                else if(garbage[i][j]=='G')
                {
                    g++;
                    lg = g;
                }
                else if(garbage[i][j]=='P')
                {
                    p++;
                    lp = p;
                }
            }
            
            if(i<travel.size())
            {
                m+=travel[i];
                p+=travel[i];
                g+=travel[i];
            }
        }
        
        if(lm!=m)
            m = lm;
        if(lg!=g)
            g = lg;
        if(lp!=p)
            p = lp;
        
        return lm+lp+lg;
    }
};