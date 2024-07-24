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
std::vector<int> factors(int n) {
    std::vector<int> result;
    int sqrt_n = sqrt(n);
    
    // Iterate from 1 to sqrt(n)
    for (int i = 1; i <= sqrt_n; ++i) {
        // If i is a factor of n
        if (n % i == 0) {
            // Add i to the result
            result.push_back(i);
            // If i is not equal to sqrt(n) and n/i is not equal to i, then add n/i to the result
            if(i!=n/i)result.push_back(n/i);
            
        }
    }
    // Sort the result vector
    // cout<<result.size()<<endl;
    return result;
}
int main(){
 ios::sync_with_stdio(false), cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vi v;
        REP(i,0,n-1){
            int a;cin>>a;
            v.push_back(a);
        }
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[1]=1;
        REP(i,1,n-1){
            vi tmp=factors(i+1);
            
            int cnt=INT_MIN;
            for(auto it:tmp){
                // cout<<it<<" "<<i+1<<endl;
                if(v[it-1]<v[i] && it!=i+1)cnt=max(1+dp[it],cnt);
            }
            dp[i+1]=max(cnt,1);
        }
        int ans=INT_MIN;
        REP(i,1,n){
            ans=max(ans,dp[i]);
        }
        cout<<ans<<endl;
        // cout<<dp[7]<<endl;
        
    }
}