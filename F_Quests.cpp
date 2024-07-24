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
bool check(ll pref[],ll n,ll c,ll d,ll k){
    ll tmp1=0;
    if(k+1>n){
        tmp1=pref[n];
    }
    else tmp1=pref[k+1];
    int cnt=d/(k+1);
    tmp1=tmp1*max(1,cnt);
    int rem=d%(k+1);
    if(rem>n){
        tmp1+=pref[n];
    }
    else tmp1+=pref[rem];
    // cout<<tmp1<<endl;
    if(tmp1>=c)return true;
    else return false;
}

int main(){
    int t;cin>>t;
    while(t--){
        ll n,c,d;cin>>n>>c>>d;
        vi v;
        REP(i,0,n-1){
            int a;cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end(),greater<int>());
        ll pref[n+1]={0};
        REP(i,1,n){
            pref[i]=pref[i-1]+v[i-1];
        }
        ll l=0,r=d-1;
        if(check(pref,n,c,d,l)==false)cout<<"Impossible"<<endl;
        else if(check(pref,n,c,d,r)==true)cout<<"Infinity"<<endl;
        else{
            while(r-l>1){
                ll mid=(l+r)/2;
                if(check(pref,n,c,d,mid)==true)l=mid;
                else r=mid-1;
            }
           if(check(pref,n,c,d,r)==true)cout<<r<<endl;
           else cout<<l<<endl;
        }
        // cout<<check(pref,n,c,d,)<<endl;

        
    }
}