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
bool check(int k,vector<pair<int,int>> &v){
    ll r1=0,r2=0;
    REP(i,0,v.size()-1){
        ll temp1=min(v[i].first,v[i].second);
        r1=r1-k;
        r1=max(0ll,r1);
        ll temp2=max(v[i].first,v[i].second);
        r2=r2+k;
        if(temp1>r2 || temp2<r1)return false;
        else{
            r1=max(r1,temp1);
            r2=min(r2,temp2);
        }
        r1=min(r1,r2);
        r2=max(r1,r2);
        // cout<<r1<<" "<<r2<<endl;
    }
    return true;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<pair<int,int>> v;
        REP(i,0,n-1){
            int a,b;cin>>a>>b;
            v.push_back(make_pair(a,b));
        }
        // cout<<check(6,v);
        int l=0,r=1e9;
        while(r-l>1){
            int mid=(r+l)/2;
            if(check(mid,v)==true)r=mid;
            else l=mid++;
        }
        if(check(l,v)==true)cout<<l<<endl;
        else cout<<r<<endl;
        
    }
}