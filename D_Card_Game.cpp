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
    while(t--){
        int n;cin>>n;
        char trump;cin>>trump;
        vector<string> v;
        REP(i,0,2*n-1){
            string a;cin>>a;
            v.push_back(a);
        }
        // vi vis(2*n,0);
        int t1=0,t2=0,t3=0,t4=0,tmp=0;
        REP(i,0,2*n-1){
            if(v[i][1]=='H'&& 'H'!=trump)t1++;
            if(v[i][1]=='C'&& 'C'!=trump)t2++;
            if(v[i][1]=='S'&& 'S'!=trump)t3++;
            if(v[i][1]=='D'&& 'D'!=trump)t4++;
            if(v[i][1]==trump)tmp++;
        }
        int ans=0;
        ans+=t1%2;ans+=t2%2;ans+=t3%2;ans+=t4%2;
        if(tmp>=ans && (tmp-ans)%2==0){
            vi vis(2*n,0)
        }
    }
}