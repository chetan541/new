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
   
        string s1,s2;cin>>s1>>s2;
        int n=s1.size();
        int m=s2.size();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=0;
        REP(i,1,n){
            dp[i][0]=i;
        }
        REP(i,1,m){
            dp[0][i]=i;
        }
        REP(i,1,n){
            REP(j,1,m){
                int cnt=INT_MAX;
                if(s1[i-1]==s2[j-1]){
                    cnt=min(cnt,dp[i-1][j-1]);
                    dp[i][j]=cnt;
                }
                else{
                    cnt=min(cnt,dp[i-1][j-1]+1);
                    cnt=min(cnt,dp[i-1][j]+1);
                    cnt=min(cnt,dp[i][j-1]+1);
                    dp[i][j]=cnt;
                }
                // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }

        }
        cout<<dp[n][m]<<endl;
        
        
    }
