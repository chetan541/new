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
    int dp[1001];
    dp[0]=0,dp[1]=0;
    REP(i,2,1000){
        dp[i]=INT_MAX;
        for(int j=i-1;j>=1;j--){
            if(j%(i-j)<j/(i-j)){
                dp[i]=min(dp[j]+1,dp[i]);
            }  
        }
        // cout<<i<<" "<<dp[i]<<endl;
    }
    while(t--){
        int n,k;cin>>n>>k;
        k=min(k,12*n);
        vi v1,v2;
        REP(i,0,n-1){
            int a;cin>>a;
            v1.push_back(a);
        }
         REP(i,0,n-1){
            int a;cin>>a;
            v2.push_back(a);
        }
        int dp1[n+1][k+1];
        memset(dp1,0,sizeof(dp1));
        // REP(i,0,n-1){
        //     if(v1[i]==1)dp1[i+1][0]=v2[i];
        // }

        REP(i,1,n){
            // cout<<i<<" "<<dp[v1[i-1]]<<" "<<v2[i-1]<<endl;
            REP(j,0,k){
                int cnt=INT_MIN;
                cnt=max(cnt,dp1[i-1][j]);
                if(j-dp[v1[i-1]]>=0)cnt=max(cnt,dp1[i-1][j-dp[v1[i-1]]]+v2[i-1]);
                dp1[i][j]=cnt;
            }
        }
        cout<<dp1[n][k]<<endl;
        
    }
}