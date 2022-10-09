#include <iostream>
#include<unordered_map>
#include<climits>
using namespace std;

int main() {
	int test_cases;
	cin>>test_cases;
	
	for(int i=0; i<test_cases; i++)
	{
	    int num;
	    cin>>num;
	    unordered_map<int,int> mapping;
	    int maxi = INT_MIN;
	    for(int j=0; j<num; j++)
	    {
	        int val;
	        cin>>val;
	        mapping[val]++;
	        
	        maxi = max(maxi,mapping[val]);
	    }
	    cout<<num-maxi<<endl;
	}
	
	return 0;
}
