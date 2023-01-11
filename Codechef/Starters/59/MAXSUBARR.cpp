#include<bits/stdc++.h>
#define int long long
using namespace std;
int arr_1[100001],arr_2[100001],num_1,num_2;
void solve() {
   cin >> num_1;
   for(int ptr_1=1;ptr_1<=num_1;++ptr_1) cin >> arr_1[ptr_1];
   cin >> num_2;
   for(int ptr_1=1;ptr_1<=num_2;++ptr_1) cin >> arr_2[ptr_1];
   int saa_67=0;
   for(int ptr_1=1,s_1=0;ptr_1<=num_1;++ptr_1) {
      s_1+=arr_1[ptr_1];saa_67=max(saa_67,s_1);
   }
   for(int ptr_1=num_1,s_1=0;ptr_1>=0;--ptr_1) {
      s_1+=arr_1[ptr_1];saa_67=max(saa_67,s_1);
   }
   for(int ptr_1=1;ptr_1<=num_2;++ptr_1)
      if(arr_2[ptr_1]>=0) saa_67+=arr_2[ptr_1];
   cout << saa_67 << endl;
}
signed main() {
   int cases_in_test;cin >> cases_in_test;
   while(cases_in_test--) solve();
}