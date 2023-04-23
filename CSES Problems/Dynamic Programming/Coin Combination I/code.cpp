#include<iostream>
#include<vector>
const int MOD = 1e9 + 7;
#define ll long long
using namespace std;


int main()
{
    int n,x;
    cin>>n>>x;
    vector<int> vec;
    int temp = n;
    while(temp--)
    {
    	int val;
    	cin>>val;
    	vec.push_back(val);
    }
    vector<ll> dp(x+1,0);
    dp[0] = 1;

    for(int i=1; i<=x; i++)
    {
		for(int j=0; j<n; j++)
		{
			if(i>=vec[j])
			{
				dp[i]+= dp[i-vec[j]];
				dp[i]%=MOD;
			}
		}
    }
    cout<<dp[x];
	return 0;
}