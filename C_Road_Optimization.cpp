#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<ll> vi;
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
ll dp[505][505];
int main(){
 ios::sync_with_stdio(false), cin.tie(0);
   
        ll n,l,k;cin>>n>>l>>k;
        vi v1,v2;
        REP(i,0,n-1){
            ll a;cin>>a;
            v1.push_back(a);
        }
        v1.push_back(l);
        REP(i,0,n-1){
            ll a;cin>>a;
            v2.push_back(a);
        }
        v2.push_back(0);
        
        memset(dp,0,sizeof(dp));
        REP(i,1,n){
            REP(l,0,k){
            ll cnt=LLONG_MAX;
            for(int j=i-1;j>=0;j--){
                if(l-(i-j-1)>=0)cnt=min(cnt,dp[j][l-(i-j-1)]+v2[j]*(v1[i]-v1[j]));
            }
            // if(l==0)cnt=min(cnt,dp[i-1][l]+v2[i-1]*(v1[i]-v1[i-1]));
            dp[i][l]=cnt;
            }
        }
        cout<<dp[n][k]<<endl;
    }
