#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
   int n;string s;
   cin >> n >> s;
   for(int i=1;i<n;++i) 
      if(s[i]=='1') {
         cout << i << endl;
         return;
      }
   cout << n << endl;
}
signed main() {
   int T;cin >> T;
   while(T--) solve();
}