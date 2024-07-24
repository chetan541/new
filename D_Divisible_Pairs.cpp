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
        ll n,x,y;cin>>n>>x>>y;
        vi v;map<pair<ll,ll>,ll> m;
        REP(i,0,n-1){
            int a;cin>>a;
            v.push_back(a);
            m[{a%x,a%y}]++;
        }
        ll cnt1=0,cnt2=0;
        ll ext=0;
        for(auto it:m){
            if(it.second!=0){
            // cout<<(it.first).first<<" "<<(it.first).second<<" "<<it.second<<endl;
            int tmp=x-(it.first).first;
            if(tmp==x)ext+=(1LL*(it.second)*(it.second-1))/2;
            // cout<<m[{tmp,(it.first).second}]<<endl;
            if(2*tmp!=x)cnt1+=((1LL*(it.second))*(m[{tmp,(it.first).second}]));
            else cnt2+=(1LL*(it.second)*(it.second-1))/2;}
            
        }
        
        cout<<cnt1/2+cnt2+ext<<endl;
        
        
    }
}