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

int main(){
    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        
        ll ans=0,cnt=0;
        // for(int i=1;i<=n;i+=2){
        //     ans+=i;
        //     // cout<<ans<<endl;
        //     if((n-ans)%2!=0 && ans<=n)cnt++;
        // }
        // ll temp=n;
        // if(n%2==0)temp=n-1;
        // cnt=(temp-1)/2 +1;
        
        cnt=(sqrt(n));
        ll temp=n-cnt*cnt;
        if(temp%2!=0)temp=1;
        else temp=0;
        int ext=0;
        if(cnt*cnt==n)ext=1;
        if(n%2==0){
            if(cnt%2!=0){
                cout<<(cnt+1)/2-temp+ext<<endl;
            }
            else cout<<(cnt+1)/2+ext<<endl;
        }
        else{
            if(cnt%2==0){
                cout<<cnt/2-temp+1+ext<<endl;
            }
            else cout<<(cnt)/2+1+ext<<endl;
        }
        
        
    }
}