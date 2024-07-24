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
// vector<int> primes;
// vi SieveOfEratosthenes(int n) {
//     vi v;
//     bool prime[n + 1];
//     memset(prime, true, sizeof(prime));

//     for (int p = 2; p * p <= n; p++) {
//         if (prime[p] == true) {
//             for (int i = p * p; i <= n; i += p)
//                 prime[i] = false;
//         }
//     }
//     for (int p = 2; p <= n; p++) {
//         if (prime[p])
//             v.push_back(p);
//     }
//     return v;
// }
int dp[200000];
int func(vi &v,int ind){
    if(ind==v.size())return 0;
    if(dp[ind]!=-1)return dp[ind];
    
    int ans=func(v,ind+1)+1;
    if(ind+v[ind]+1<=v.size())ans=min(ans,func(v,ind+v[ind]+1));
    dp[ind]=ans;
    return dp[ind];
}

int main(){
    int t;cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        int n;cin>>n;
        vi v;
        REP(i,0,n-1){
            int a;cin>>a;
            v.push_back(a);
        }
        func(v,0);
        cout<<dp[0]<<endl;
        
    }
}