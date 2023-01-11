#include <iostream>
using namespace std;

int main() {
	int number_cases;
	cin>>number_cases;
	
	for(int i=0; i<number_cases; i++)
	{
	    int num;
	    cin>>num;
	    
	    int even = 0;
	    int odd = 0;
	    
	    for(int i=0; i<num; i++)
	    {
	        int val;
	        cin>>val;
	        
	        if(val%2==0)
	            even++;
	        else
	            odd++;
	    }
	    
	    if(even==0 || odd==0)
	        cout<<0<<endl;
	    else
	        cout<<even<<endl;
	   
	}
	return 0;
}
