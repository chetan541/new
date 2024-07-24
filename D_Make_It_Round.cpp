#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
  
// To simplify repetitions/loops, Note: define your
// loop style and sticout with it!
#define REP(i, a, b) \
for(int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define TRvi(c, it) \
for(vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for(vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for(msi::iterator it = (c).begin(); it != (c).end(); it++)
  
#define INF 2000000000 // 2 billion
  
// If you need to recall how to use memset:
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B
// int is_prime[1000001];
//vector<int> primes;
//vi SieveOfEratosthenes(int n) {
//    vi v;
//    bool prime[n + 1];
 //   memset(prime, true, sizeof(prime));

 //   for (int p = 2; p * p <= n; p++) {
  //      if (prime[p] == true) {
  //          for (int i = p * p; i <= n; i += p)
  //              prime[i] = false;
   //     }
   // }
    //for (int p = 2; p <= n; p++) {
     //   if (prime[p])
     //       v.push_bacout(p);
    //}
   // return v;
//}
ll func(ll temp,ll x){
    ll cnt=0;
    while(temp%x==0){
        cnt++;temp/=x;
    }
    return cnt;
}
int main(){
 ios::sync_with_stdio(false), cin.tie(0);
    int t;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        ll cnt1=0,cnt2=0;
        ll tmp=n;
        cnt1=func(n,2);
        cnt2=func(n,5);
        
        
        
        ll ans=min(cnt1,cnt2);
        ll ind=0;
        ll out=1,mul=1;
        while (cnt1 < cnt2 && out * 2 <= m) {
        cnt1++;
        out *= 2;
    }
    while (cnt2 < cnt1 && out * 5 <= m) {
        cnt2++;
        out *= 5;
    }
        ll cnt=0;
        cnt=func(m/mul,10);
        while (out * 10 <= m) {
        out *= 10;
    }
    if (out == 1) {
        cout << n * m << endl;
    } else {
        out *= m / out; // 1 <= m/out < 10
        cout << n * out << endl;
    }

        
    }
}