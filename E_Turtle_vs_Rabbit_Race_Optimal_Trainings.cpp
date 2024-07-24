#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
  
// To simplify repetitions/loops, Note: define your
// loop style and stick with it!
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
     //       v.push_back(p);
    //}
   // return v;
//}

int main(){
 ios::sync_with_stdio(false), cin.tie(0);
    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vi v;
        vi pref(n+1,0);
        REP(i,0,n-1){
            ll a;cin>>a;
            v.push_back(a);
            pref[i+1]=pref[i]+a;
        }
        ll q;cin>>q;
        while(q--){
            ll l,u;cin>>l>>u;
            ll tmp=pref[l-1];
            ll x;
            x=u+tmp+1;
            auto it=lower_bound(pref.begin(),pref.end(),x);
            ll ind;
            if(it==pref.end())ind=n+1;
            else ind=it-pref.begin();
            // cout<<pref[ind]<<" "<<pref[ind-1]<<endl;
            if(x-pref[ind-1]<=pref[ind]-x+1){
                if(ind-1<l)cout<<l<<" ";
                else cout<<ind-1<<" ";
            }
            else {
                if(ind==n+1)cout<<n<<" ";
                else cout<<ind<<" ";
                }
            
        }
        cout<<endl;
        
    }
}