#include <iostream>
using namespace std;

int main() {
	int cases;
	cin>>cases;
	
	for(int i=0; i<cases; i++)
	{
	    int target_score, scored;
	    cin>>target_score>>scored;
	    
	    cout<<target_score-scored<<endl;
	}
	return 0;
}
