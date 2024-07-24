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
int is_prime[1000001];
vector<int> primes;
vi SieveOfEratosthenes(int n) {
    vi v;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++) {
        if (prime[p])
            v.push_back(p);
    }
    return v;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n,x;cin>>n>>x;
        vi v;
        vi pref(n+1,0);
        REP(i,0,n-1){
            int a;cin>>a;
            pref[i+1]+=pref[i]+a;
            v.push_back(a);
        }
        // for(auto it:pref)cout<<it<<" ";
        cout<<endl;
        vi m(n+1,INT_MIN);
        REP(i,0,n-1){
            REP(j,i,n-1){
               m[j-i+1]=max(m[j-i+1],pref[j+1]-pref[i]);
            }
        }
        // REP(i,1,n)cout<<m[i]<<" ";   
        REP(i,0,n){
            ll ans=INT_MIN;
            REP(j,1,n){
                // cout<<m[j]<<" ";
                ans=max(1LL*m[j]+x*min(j,i),ans);
            }
            cout<<max(1LL*0,ans)<<" ";

        }
    }
}