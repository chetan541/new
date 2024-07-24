#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<long long> vi;
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
        ll ans=LLONG_MAX,prev=LLONG_MAX,curr;
        REP(i,0,n-1){
            ll a;cin>>a;
            v.push_back(a);
        }
        ll even=0,odd=0;
        ll e=LLONG_MAX,o=LLONG_MAX;
        even+=v[0];e=min(e,v[0]);
        prev=v[0]*n;
        REP(i,1,n-1){
            if(i%2==0){
                ll num=(i+2)/2;
                even+=v[i];e=min(e,v[i]);
                 curr=(even-e)+(n+1-num)*e;
                ans=min(ans,prev+curr);
                prev=curr;
            }
            else{
                ll num=(i+1)/2;
                odd+=v[i];o=min(o,v[i]);
                 curr=(odd-o)+(n+1-num)*o;
                ans=min(ans,curr+prev);
                prev=curr;
            }
            // cout<<ans<<" "<<prev<<" "<<curr<<endl;
        }
        cout<<ans<<endl;
        
    }
}