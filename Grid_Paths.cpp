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
bool valid(int s,int t,int n){
    if(s>=0 && s<n && t>=0 && t<n){
        return true;
    }
    else return false;
}
int main(){
 ios::sync_with_stdio(false), cin.tie(0);
    
        int n;cin>>n;
        ll m=1e9+7;
        int arr[n][n];
        REP(i,0,n-1){
            REP(j,0,n-1){
            char c;cin>>c;
            if(c=='.')arr[i][j]=0;
            else arr[i][j]=1;
            }
        }
        int dp[n][n];
        dp[0][0]=1;
        if(arr[0][0]==1)dp[0][0]=0;
        // cout<<valid(0,1,n)<<endl;
        REP(i,0,n-1){
            REP(j,0,n-1){
                int cnt=0;
                if(i==0 && j==0)continue;
                if(valid(i-1,j,n) && arr[i-1][j]==0){
                    cnt+=dp[i-1][j];cnt%=m;
                }
                if(valid(i,j-1,n) && arr[i][j-1]==0){
                    cnt+=dp[i][j-1];cnt%=m;
                }
                if(arr[i][j]==1)dp[i][j]=0;
                else dp[i][j]=cnt;
            }
        }
        cout<<dp[n-1][n-1]<<endl;
        
    }
