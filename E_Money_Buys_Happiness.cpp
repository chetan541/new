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
        ll m,x;cin>>m>>x;
        vector<pair<ll,ll>> v;
        ll sum=0;
        REP(i,0,m-1){
            ll a,b;cin>>a>>b;
            sum+=b;
            v.push_back({a,b});
        }
        pair<ll,ll> dp[m+1][sum+1]={make_pair(0LL,0LL)};
        dp[0][0]={0,1};

        REP(i,1,m){
            REP(j,0,sum){
                
                if(dp[i-1][j].S==1){
                    dp[i][j].S=1;
                    dp[i][j].F=dp[i-1][j].F+x;
                }
                if(j>=v[i-1].S && dp[i-1][j-v[i-1].S].S==1 && dp[i-1][j-v[i-1].S].F>=v[i-1].F){
                    dp[i][j].S=1;
                    dp[i][j].F=max(dp[i][j].F,dp[i-1][j-v[i-1].S].F-v[i-1].F+x);
                }
               
            }
        }
        ll ans=0;
        REP(i,0,sum){
            if(dp[m][i].S==1)ans=max(ans,1LL*i);
        } 
        cout<<ans<<endl;
        
    }
}