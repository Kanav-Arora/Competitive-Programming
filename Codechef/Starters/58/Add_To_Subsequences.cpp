#include <iostream>
#include<unordered_map>
#include<climits>
#include <cmath>
using namespace std;


int main() {
 int test_cases;
 cin>>test_cases;
 
 for(int p=0; p<test_cases; p++)
 {
     int nums;
     cin>>nums;
     
     unordered_map<int,int> mapping;
     for(int p=0; p<nums; p++)
     {
         int value_1;
         cin>>value_1;
         
         mapping[value_1]++;
     }
     
     int maxi_value_1 = 0;
     for(auto item : mapping)
     {
         maxi_value_1 = max(maxi_value_1,item.second);
     }
     
     cout<<ceil(log2(maxi_value_1))<<endl;
     
 }
 
 return 0;
}