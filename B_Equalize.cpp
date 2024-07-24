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
        int n;cin>>n;
        vi v;
        set<int> s;
        REP(i,0,n-1){
            int a;cin>>a;
            s.insert(a);
        }
        for(auto it:s){
            v.push_back(it);
        }
        int size=v.size();
        int ans=1,cnt=1;
        for(int i=size-1;i>=0;i--){
            auto it=lower_bound(v.begin(),v.begin()+i,v[i]-n+1);
            cnt=v.begin()+i-it+1;
            // cnt=it-v.begin();
            // cout<<*it<<" "<<cnt<<endl;
            ans=max(ans,cnt);
        }
        // int prev=v[n-1]+1,ans=1,cnt=1;
        // for(int i=n-2;i>=0;i--){
        //     // cout<<v[i+1]-v[i]<<endl;
        //     if(v[i]!=v[i+1] && prev-v[i]<=n){
        //         cnt++;
        //         ans=max(ans,cnt);
        //     }
        //     else{
        //         cnt=1;prev=v[i]+1;
        //     }
        // }
        cout<<ans<<endl;
        
    }
}