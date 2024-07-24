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
int dp[101][1000001];

int main(){
 ios::sync_with_stdio(false), cin.tie(0);
   
        int n,sum;cin>>n>>sum;
        vi v;
        REP(i,0,n-1){
            int a;cin>>a;
            v.push_back(a);
        }
        
        memset(dp,-1,sizeof(dp));
        dp[0][0]=1;
        REP(i,1,sum)dp[0][i]=0;
        REP(i,1,n){
            REP(j,0,sum){
                int cnt=0,tmp=0;
                while(j-tmp>=0){
                    cnt+=dp[i-1][j-tmp];
                    tmp+=v[i-1];
                }
                dp[i][j]=cnt;
            }
        }

        // if(dp[n][sum]==INF)cout<<-1<<endl;
        cout<<dp[n][sum]<<endl;
        // cout<<INF;
        
    }
