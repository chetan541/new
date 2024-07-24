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
        int n,m,k;cin>>n>>m>>k;
        string s;s.pb('L');
        string s1;cin>>s1;
        REP(i,0,n-1)s.pb(s1[i]);
        s.pb('L');
        vi dp(n+2,0);
        vi dp1(n+2,0);
        dp[0]=1;
        
        REP(i,1,n+1){
            int j=i-1,cnt=0,tmp=0;
            if(s[i]!='C'){
            dp1[i]=INT_MAX;
            if(s[i-1]=='W' && dp[i-1]==1){
                if(s[i]=='W')dp1[i]=dp1[i-1]+1;
                else dp1[i]=dp1[i-1];
                if(dp1[i]<=k)dp[i]=1;
                else dp1[i]=INT_MAX;
            }
            while(j>=0 && cnt<m){
               
                if(i-j<=m && dp[j]==1 && s[j]=='L' ){
                    int x;
                    if(s[i]=='W')x=dp1[j]+1;
                    else x=dp1[j];
                    dp1[i]=min(dp1[i],x);
                    if(dp1[i]<=k)dp[i]=1;
                    else dp1[i]=INT_MAX;
                }
                j--;cnt++;
                
            }
            }
            }
            // REP(i,0,n+1){
            //     cout<<dp[i]<<" "<<dp1[i]<<endl;
            // }
            if (dp[n + 1] == 1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        
        
    }
