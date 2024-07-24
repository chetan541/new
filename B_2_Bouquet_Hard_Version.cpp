#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef vector<pi> vii;
typedef set<int> si;
typedef map<string, int> msi;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first 
#define S second
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;
#define multi_ordered_set tree<ll, null_type,greater_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
  
  
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
        ll n,m;cin>>n>>m;
        vll v1,v2;
        REP(i,0,n-1){
            ll a;cin>>a;
            v1.push_back(a);
        }

        REP(i,0,n-1){
            ll a;cin>>a;
            v2.push_back(a);
        }
        vector<pair<ll,ll>> v;
        REP(i,0,n-1){
            v.pb({v1[i],v2[i]});
        }
        sort(v.begin(),v.end());
        ll ans=0;
        REP(i,0,n-1){
            if(i<n-1 && v[i+1].F-v[i].F==1){
                ll tmp=min(ll(ceil(m/(v[i+1].F*1.00))),v[i+1].S);
                // cout<<v[i].F<<" "<<tmp<<endl;
                if(tmp*v[i+1].F<=m){
                    ll x=min(v[i].S,ll(floor((m-tmp*v[i+1].F)/(v[i].F*1.00))));
                    
                    ans=max(ans,tmp*v[i+1].F+x*v[i].F);
                    if(v[i].S>x){
                        ll p=tmp*v[i+1].F+(x+1)*v[i].F-m;
                        // cout<<v[i].F<<" "<<tmp<<" "<<x<<" "<<p<<endl;
                        if(v[i].S-x-1>=p && tmp>=p)ans=m;
                    }
                }
                else{
                    ans=max(ans,v[i+1].F*(tmp-1));
                    ll y=tmp*v[i+1].F-m;
                    // cout<<v[i].F<<" "<<y<<endl;
                    if(v[i].S>=y && tmp>=y)ans=m;
                }
            }
            else{
                ll z=min(m/v[i].F,v[i].S);
                ans=max(ans,z*v[i].F);
            }
            // if(ans==3)cout<<v[i].F<<endl;
        }
        cout<<ans<<endl;
    }
}