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
typedef tree<ll, null_type, greater<ll>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;
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
        ll n,k,q;cin>>n>>k>>q;
        vll v1,v2;
        v1.pb(0),v2.pb(0);
        
        
        REP(i,0,k-1){
            ll a;cin>>a;
            v1.push_back(a);
        }
        REP(i,0,k-1){
            ll a;cin>>a;
            v2.push_back(a);
        }
        while(q--){
            ll d;cin>>d;
            auto it=lower_bound(v1.begin(),v1.end(),d);
            if((*it)==d){
                ll ind=it-v1.begin();
                
                cout<<v2[ind]<<" ";
            }
            else{
                ll ind=it-v1.begin();
                // cout<<ind<<endl;
                
                ll ind1=ind;
                ind--;
                ll ans=v2[ind];
                ll avg=((d-v1[ind])*(v2[ind1]-v2[ind]))/(v1[ind1]-v1[ind]);
                // cout<<(d-v1[ind])/avg<<endl;
                ans+=avg;
                cout<<ans<<" ";

            }
        }
        cout<<endl;
        
    }
}