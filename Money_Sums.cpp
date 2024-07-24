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
bool dp[100001][101];
int main(){
 ios::sync_with_stdio(false), cin.tie(0);
   
        int n;cin>>n;
        vi v;
        int mx=0;
       
        REP(i,0,n-1){
            int a;cin>>a;
            v.push_back(a);
            mx+=a;
        }
        memset(dp,0,sizeof(dp));
        REP(i,0,n){
            dp[0][i]=true;
        }
        vector<int> ans;
        REP(i,1,mx){
            bool flag=false;
            REP(j,1,n){
                bool cnt=false;
                REP(k,1,j){
                    if(i-v[k-1]>=0)cnt|=dp[i-v[k-1]][k-1];
                    // if(i==6)cout<<dp[i-v[j-1]][j-1]<<" "<<j<<" "<<k<<endl;
                }
                // cnt|=dp[i][j-1];
                // if(i-v[j-1]>=0)cnt|=dp[i-v[j-1]][j-1];
                dp[i][j]=cnt;
                flag|=cnt;
                // if(i==15)cout<<dp[i][j]<<" "<<j<<endl;
            }
            
            if(flag==true)ans.push_back(i);
        }
        // cout<<dp[15][5]<<endl;
        cout<<ans.size()<<endl;
        for(auto it:ans)cout<<it<<" ";
        cout<<endl;
        
    }
