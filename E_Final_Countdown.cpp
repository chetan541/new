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

int main(){
 ios::sync_with_stdio(false), cin.tie(0);
    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        string x;cin>>x;
        ll ans=0;
        vi v;
        REP(i,0,n-1){
            v.push_back(int(x[i]-'0'));
            // cout<<int(x[i]-'0');
            ans+=int(x[i]-'0');
            // x/=10;
        }
        // cout<<ans<<endl;
        vi tmp;
        ll carry=0;
        REP(i,0,n-1){
            if(ans==v[n-1-i]){tmp.push_back(ans+carry);break;}
            tmp.push_back((ans+carry)%10);
            carry=(ans+carry)/10;
            ans-=v[n-1-i];
            // cout<<ans<<endl;
            // if(ans==0){tmp.push_back((ans+v[i]+carry)/10);break;}
        }
        int j=tmp.size()-1;
        while(tmp[j]==0)j--;
        for(int i=j;i>=0;i--){
            // if(tmp[i]==0)break;
            cout<<tmp[i];
        }
        cout<<endl;
    }
}