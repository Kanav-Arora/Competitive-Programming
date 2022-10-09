#include <iostream>
using namespace std;

int main() {
	int cases_test;
	
	cin>>cases_test;
	
	for(int ptr = 0; ptr<cases_test; ptr++)
	{
	    int fre_inp;
	    cin>>fre_inp;
	    
	    if(fre_inp>=67 && fre_inp<=45000)
	        cout<<"YES"<<endl;
	   else
	    cout<<"NO"<<endl;
	}
	return 0;
}