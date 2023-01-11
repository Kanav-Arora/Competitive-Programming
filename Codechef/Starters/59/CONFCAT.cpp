#include<bits/stdc++.h>
#define int long long
using namespace std;
int arr[100001];
void solve() {
   int num,q;bool flag=false;
   cin >> num;
   for(int i=1;i<=num;++i)
      cin >> arr[i];
   for(int i=2;i<=num;++i)
      if(arr[i]>arr[1]) {
         flag=true;
         q=i;
         break;
      }
   if(!flag) {
      puts("-1");
      return;
   }
   cout << q-1 << endl;
   for(int i=1;i<q;++i)
      cout << arr[i] << ' ';
   cout << endl << num-q+1 << endl;
   for(int i=q;i<=num;++i)
      cout << arr[i] << ' ';
   cout << endl;
}
signed main() {
   int T;cin >> T;
   while(T--) solve();
}