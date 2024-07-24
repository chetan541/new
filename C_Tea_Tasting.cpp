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
        int n;cin>>n;
        vi v1,v2;
        REP(i,0,n-1){
            int a;cin>>a;
            v1.push_back(a);
        }
        REP(i,0,n-1){
            int a;cin>>a;
            v2.push_back(a);
        }
        vi pref(n+1,0);
        REP(i,1,n){
            pref[i]=pref[i-1]+v2[i-1];
        }
        vi cnt(n+1,0);
        vi add(n+1,0);
        REP(i,1,n){
            auto it=upper_bound(pref.begin()+i,pref.end(),pref[i-1]+v1[i-1]);
            int temp;
            if(it!=pref.end()) temp=it-pref.begin();
            else temp=n+1;
            cnt[i]++;
            if(temp!=n+1)cnt[temp]--;
            if(it!=pref.end())add[temp]+=v1[i-1]-pref[temp-1]+pref[i-1];
        }
        REP(i,1,n){
            cnt[i]+=cnt[i-1];
        }
        REP(i,1,n){
            cout<<1LL*v2[i-1]*cnt[i]+1LL*add[i]<<" ";
        }
        cout<<endl;
    }
}