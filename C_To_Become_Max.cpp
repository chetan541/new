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

bool check(vi &v,ll k,ll m){
    ll flag=0,sum=INT_MAX,ex=0;
    ll tmp=m;
    REP(i,0,v.size()-1){
        flag=0;ex=0;tmp=m;
        REP(j,i,v.size()-1){
            if(tmp<=v[j]){flag=1;break;}
            else{ex+=tmp-v[j];}
            tmp--;
        }
        // cout<<ex<<endl;
        if(flag==1)sum=min(ex,sum);
    }
    // cout<<sum<<endl;
    if(sum!=INT_MIN && sum<=k)return true;
    else return false;

}
int main(){
 ios::sync_with_stdio(false), cin.tie(0);
    int t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        vi v;
        ll l=INT_MIN,r=21e8+1;
        REP(i,0,n-1){
            ll a;cin>>a;
            l=max(a,l);
            v.push_back(a);
        }
        while(r-l>1){
            ll m=(r+l)/2;
            if(check(v,k,m)==true)l=m;
            else r=m-1;
        }
        if(check(v,k,r)==true)cout<<r<<endl;
        else cout<<l<<endl;

        
    }
}