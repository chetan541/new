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
        int n;cin>>n;
        vi v;
        msi m;
        REP(i,0,n-1){
            int a;cin>>a;
            v.push_back(a);
            m[a]++;
        }
        sort(v.begin(),v.end());
        if(n!=1){
        ll ans=v[1]-v[0];
        ll steps=0;
        vector<ll> vec;
        vec.push_back(ans);
        for(int i=1;i<n-1;i++){
            ll temp=v[i+1]-v[i];
            ans=gcd(ans,temp);
            vec.push_back(temp);
        }
        // cout<<ans<<endl;
        int cnt=1;
        for(int j=0;j<vec.size();j++){
            steps+=(vec[j]/ans)*cnt;
            cnt++;
        }
        cnt=0;
        int x=v[n-1];
        while(m[x]==1 && cnt<n){
            x=x-ans;cnt++;
            // cout<<x<<endl;
        }
        cnt=min(cnt,n);
        cout<<steps+cnt<<endl;
        }
        else{
            cout<<1<<endl;
        }
        
    }
}