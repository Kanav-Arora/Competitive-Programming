#include <iostream>
using namespace std;

int main() {
	int cases;
	cin>>cases;
	
	for(int i=0; i<cases; i++)
	{
	    int rank;
	    cin>>rank;
	    
	    if(rank%25==0)
	        cout<<rank/25<<endl;
	   else
	        cout<<(rank/25)+1<<endl;
	}
	
	return 0;
}
