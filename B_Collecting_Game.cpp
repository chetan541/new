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
        vector<pair<int,int>> v;
        vi ans;
        // msi m;
        REP(i,0,n-1){
            int a;cin>>a;
            // m[a]=i;
            ans.push_back(a);
            v.push_back(make_pair(a,0));
        }
        
        sort(v.begin(),v.end());
        vector<pair<ll,ll>> pref(n+1);
        pref[0].first=0;
        pref[0].second=0;

        REP(i,0,n-1){
            pref[i+1].first=pref[i].first+v[i].first;
            if(i>n-2){pref[i+1].second=0;
            // pref[i+1].first=pref[i].first+v[i];}
            }
            else if(pref[i+1].first>=v[i+1].first){
                pref[i+1].second=1;
                // pref[i+1].first=pref[i].first+v[i];
            }
            else{ pref[i+1].second=0;}
            // pref[i+1].first=pref[i].first+v[i];}
        }
        // cout<<pref[4].first<<" "<<pref[4].second<<endl;
        
        int temp;
        msi m;
        for(int i=n;i>=1;i--){
            
            if(pref[i].second==1){}
            else{ temp=i-1;}
            m[v[i-1].first]=temp;
            // cout<<temp<<" ";
        }
        for(auto it: ans){cout<<m[it]<<" ";}
        cout<<endl;

        
    }
}