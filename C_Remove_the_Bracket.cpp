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
const int z=2e5+1;
ll dp[z][2],x1[z],x2[z];
int main(){
 ios::sync_with_stdio(false), cin.tie(0);
    int t;cin>>t;
    while(t--){
        ll n,s;cin>>n>>s;
        vi v;
        REP(i,0,n-1){
            ll a;cin>>a;
            v.push_back(a);
        }
        memset(dp,0,sizeof(dp));
        
        if(v[1]<s){
            dp[1][0]=v[0]*v[1];
            dp[1][1]=v[0]*0;
            x1[1]=v[1];
            x2[1]=0;
        }
        else{
            dp[1][0]=v[0]*max(s,v[1]-s);
            dp[1][1]=v[0]*min(s,v[1]-s);
            x1[1]=max(s,v[1]-s);
            x2[1]=min(s,v[1]-s);
        }
        
        REP(i,2,n-2){
            if(v[i]<s){
                x1[i]=v[i];x2[i]=0;
            }
            else{
                x1[i]=max(v[i]-s,s);
                x2[i]=min(v[i]-s,s);
            }
            
            ll cnt1,cnt2;
           
            cnt1=dp[i-1][0]+(v[i-1]-x1[i-1])*(x1[i]);
            cnt2=dp[i-1][1]+((v[i-1]-x2[i-1]))*(x1[i]);
            
            dp[i][0]=min(cnt1,cnt2);
            // x1[i]=v[i];
            cnt1=dp[i-1][1]+(v[i-1]-x2[i-1])*(x2[i]);
            cnt2=dp[i-1][0]+((v[i-1]-x1[i-1]))*(x2[i]);
            dp[i][1]=min(cnt1,cnt2);
            // cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
            
        }
       ll tmp1,tmp2;
       tmp1=dp[n-2][0]+v[n-1]*(v[n-2]-x1[n-2]);
       tmp2=dp[n-2][1]+v[n-1]*(v[n-2]-x2[n-2]);
       cout<<min(tmp1,tmp2)<<endl;

    }
}