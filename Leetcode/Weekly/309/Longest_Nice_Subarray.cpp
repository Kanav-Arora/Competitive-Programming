class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
int x=0,l=0,t=0;
vector<int> v;

for(int i=0;i<n;i++)
{
    int a=nums[i];
    if((t&a)!=0)
    {
        int in=i-l;
        while(in<i) 
        {
            l--;
            int b=nums[in];
            t=t^b;
            if((t&a)==0)
            {
                t=t|a;
                break;
             } 
            in++;
            
        }
        l++;
    }
    else
    {
        l++;
        t=t|a;
        v.push_back(a);
    }
    x=max(x, l);
}
return x;
    }
};