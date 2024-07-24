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
        REP(i,0,n-1){
            int a;cin>>a;
            v.push_back(a);
        }
        ll ans=0;ll tmp=0;ll x;
        vi vis(n,0);
        REP(i,1,50){
            ll ind=-1,ans=tmp;
            x=tmp;
            // cout<<tmp<<endl;
            REP(j,0,n-1){
                if(!vis[j]){
                    if(x<=(tmp|v[j])){ind=j;x=(tmp|v[j]);}
                    // cout<<v[j]<<" "<<(tmp|v[j])<<" ";
                }
            }
            // cout<<endl;
            tmp=x;
            // cout<<tmp<<endl;
            if(tmp==ans)break;
            else {
                cout<<v[ind]<<" ";
            vis[ind]=1;}
        }
        REP(i,0,n-1){
            if(!vis[i])cout<<v[i]<<" ";
        }
        cout<<endl;
        // sort(v.begin(),v.end(),greater<int>());
        // ll first=v[0];
        // ll calc=1;
        // while(first>=calc){
        //     calc=calc*2;
        // }
        // calc--;
        // ll tmp=calc-first;
        // // cout<<first<<" "<<calc<<" "<<tmp<<endl;
        // vector<pair<ll,ll>> ans;
        // REP(i,1,n-1){
        //     ll x=tmp&v[i];
        //     ans.push_back(make_pair(x,i));
        // }
        // sort(ans.begin(),ans.end(),greater<pair<ll,ll>>());
        // cout<<first<<" ";
        // REP(i,0,n-2){
        //     // cout<<ans[i].first<<" ";
        //     cout<<v[ans[i].second]<<" ";
        // }
        // cout<<endl;


    }
}