#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<char, int> msi;
  
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
        string s;cin>>s;
        int n=s.size();
        ll ans=INT_MAX;
        ll sum=0;
        msi m;
        REP(i,0,n-1){
            m[s[i]]++;
        }
        for(char c='a';c<='z';c++){
            if(m[c]==0)continue;
            ll tmp=INT_MAX;
            for(int i=0;i<n;i+=m[c]){
                ll cnt=0;
                REP(j,i,m[c]-1){
                    if(s[i]==c)cnt++;
                }
                tmp=min(tmp,m[c]-cnt);
            }
            // REP(i,0,n-1){
            //     f
            //     // if(s[i]==c){
            //     //     ll cnt=0;
            //     //     while(i<n && s[i]==c ){
            //     //         cnt++;i++;
            //     //     }
            //     //     if(cnt!=0)tmp=max(tmp,cnt);
            //     // }
            // }
            // if(m[c]!=0){
            //     ans=min(ans,m[c]-tmp);
            // }
            ans=min(ans,tmp);
        }
        cout<<ans<<endl;
        
        
    }
}