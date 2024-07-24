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
        int n,m,d;cin>>n>>m>>d;
        vi v;
        REP(i,0,m-1){
            int a;cin>>a;
            v.push_back(a);
        }
        v.push_back(n);
        ll org=1,prev=1;
        REP(i,0,m-1){
            if(v[i]!=1)org++;
            ll tmp=(v[i]-prev-1)/d;
            prev=v[i];
            org+=tmp;
        }
        org+=(n-v[m-1])/d;
        // cout<<org<<endl;
        map<ll,ll> mp;
        prev=1;
        // org=1;
        REP(i,0,m-2){
            ll tmp=0;
            if(v[i]==1)tmp++;
            tmp+=(v[i+1]-prev-1)/d;
            tmp-=(v[i]-prev-1)/d+1+(v[i+1]-v[i]-1)/d;
            ll x=org+tmp;
            mp[x]++;
            prev=v[i];
            
        }
        ll y=(n-prev)/d-1-(v[m-1]-prev-1)/d-(n-v[m-1])/d;
        mp[y+org]++;
        cout<<(*mp.begin()).F<<" "<<(*mp.begin()).S<<endl;


    }
}