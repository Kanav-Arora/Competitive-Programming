class Solution {
public:
    int edgeScore(vector<int>& edges) {

//      In unordered_map map the label like map[i] is the sum of labels with incoming edge to i; 

        unordered_map<unsigned int,unsigned int> mapping;       // unordered_map with T.C O(log(n))
        
        for(int i=0; i<edges.size(); i++)
        {
            mapping[edges[i]]+=i;
        }
        
        unordered_map<unsigned int,unsigned int> :: iterator it = mapping.begin();
        
        int sum = 0;
        int val = 0;

        /*
            Iterate over the map to find the label with largest sum and if multiple labels have largest 
            save the lowest label with largest sum
        */

        while(it!=mapping.end())
        {
            if(it->second>=sum)
            {
                if(it->second==sum && it->first>val)
                {
                    it++;
                    continue;
                }
                sum = it->second;
                val = it->first;
            }
            it++;
        }
        
        return val;
        
    }
};