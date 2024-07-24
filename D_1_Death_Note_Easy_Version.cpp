#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<int, int> msi;
  
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
        int n,q;cin>>n>>q;
        string s;cin>>s;
        msi m;
        REP(i,0,n-1){
            if(m[int(s[i]-'0')]==0)m[int(s[i]-'0')]=i+1;
        }
        string t1,t2;cin>>t1>>t2;
        string ans;
        int x=t1.size();
        int prev=n+1;
        int flag=0;
        REP(i,0,x-1){
            int l=max(int(t1[i]-'0'),int(t2[i]-'0'));
            int r=min(int(t1[i]-'0'),int(t2[i]-'0'));
            int tmp=0;
            REP(k,r,l){
            REP(j,0,tmp){
                if(int(s[i]-'0')==k){tmp=j;break;}
            }
            }

        }
        
    }
}