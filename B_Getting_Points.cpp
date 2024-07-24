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

bool bin(ll n,ll curr,ll p,ll l,ll t){
    ll rem=(n+6)/7;
    ll cla=n-curr+1;
    rem=min(cla*2,rem);
    ll pts=l*cla+rem*t;
    // cout<<pts<<" "<<rem<<" "<<cla<<endl;
    if(pts>=p)return true;
    else return false;
}

int main(){
    // vi v=SieveOfEratosthenes(150);
    // for(auto it:v){
    //     cout<<it<<" ";
    // }
    
    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll p;cin>>p;
        ll l,t;cin>>l>>t;
        ll ri=n,le=1;
        while(ri-le>1){
            ll mid=(ri+le)/2;
            if(bin(n,mid,p,l,t)==true){
                le=mid;
            }
            else{
                ri=mid-1;
            }
        }
        if(bin(n,ri,p,l,t)==true){
            cout<<ri-1<<endl;
        }
        else{
            cout<<le-1<<endl;
        }
        // cout<<bin(n,14,p,l,t)<<endl;
        
    }
    
}
