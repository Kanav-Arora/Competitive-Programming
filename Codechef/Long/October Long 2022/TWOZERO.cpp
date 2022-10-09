#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;
long long power(long long b,long long n) {
    long long s=1;
    while(n) {
        if(n%2==1)s=s*b%MOD;
        b=b*b%MOD;
        n/=2;
    }
    return s;
}
long long Inv(int x) {
    return power(x,MOD-2);
}
int n,m,s,a[3],b[3];
void solve(){
   cin >> n >> m;
   a[0]=(vector<int>{2,1,-1,-2,-1,1}[n%6]+power(2,n))*Inv(3)%MOD;
   a[1]=(vector<int>{-1,1,2,1,-1,-2}[n%6]+power(2,n))*Inv(3)%MOD;
   a[2]=(vector<int>{-1,-2,-1,1,2,1}[n%6]+power(2,n))*Inv(3)%MOD;
   b[0]=(vector<int>{2,1,-1,-2,-1,1}[m%6]+power(2,m))*Inv(3)%MOD;
   b[1]=(vector<int>{-1,1,2,1,-1,-2}[m%6]+power(2,m))*Inv(3)%MOD;
   b[2]=(vector<int>{-1,-2,-1,1,2,1}[m%6]+power(2,m))*Inv(3)%MOD;
   cout << ((a[0]*b[0]+a[1]*b[1]+a[2]*b[2])%MOD+MOD-1)%MOD << endl;
}
signed main() {
   int T;cin >> T;
   while(T--) solve();
}