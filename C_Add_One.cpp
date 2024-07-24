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
const ll max_n = 200015, modulo = 1000000007;
ll ans[max_n];
int main(){
 ios::sync_with_stdio(false), cin.tie(0);
    ll t;cin>>t;
    
    
    ans[0]=1;
    ans[10]++;
    
        REP(i,1,max_n){
            if(max_n-i>=10){ans[i+10]+=ans[i];ans[i+10]%=modulo;}
            if(max_n-i>=9){ans[i+9]+=ans[i];ans[i+9]%=modulo;}
            ans[i]+=ans[i-1];
            ans[i]%=modulo;
            
        }
        
    
    while(t--){
        ll n,m;cin>>n>>m;
        ll tmp=n;
        ll out=0;
        while(tmp){
            ll a=tmp%10;
            tmp/=10;
            out+=ans[m+a];
            out%=modulo;
        }
        cout<<out<<endl;
        
    }
}