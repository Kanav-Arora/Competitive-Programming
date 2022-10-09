#include <iostream>
#include <queue>
using namespace std;

int main() {
	int num_cases;
	cin>>num_cases;
	
	for(int i=0; i<num_cases; i++)
	{
	    priority_queue<pair<int,string>> q(3);
	    
	    int val;
	    cin>>val;
	    q.push({val,"Setter"});
	    cin>>val;
	    q.push({val,"Tester"});
	    cin>>val;
	    q.push({val,"Editorialist"});
	    
	    cout<<q.top().second<<endl;
	    
	}
	return 0;
}
