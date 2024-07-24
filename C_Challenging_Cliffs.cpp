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
        sort(v.begin(),v.end());
        ll l=v[0],r=v[n-1];
        pair<int,int> ind;
        ll tmp=LONG_MAX;
        REP(i,0,n-2){
            if (abs(1LL*v[i]-1LL*v[i+1])<tmp){ind.first=i;ind.second=i+1;tmp=abs(1LL*v[i]-1LL*v[i+1]);}
            else if(abs(1LL*v[i]-1LL*v[i+1])==tmp){
                if(min(v[i],v[i+1])==l || max(v[i],v[l])==r){ind.first=i;ind.second=i+1;}
            }
            
        }
        // cout<<min(v[ind.first],v[ind.second])<<" ";
        // REP(i,0,n-1){
        //     if(i!=ind.first && i!=ind.second)cout<<v[i]<<" ";
        // }
        // cout<<max(v[ind.first],v[ind.second])<<endl;
        if(n!=2){
        REP(i,ind.second,n-1)cout<<v[i]<<" ";
        REP(i,0,ind.first)cout<<v[i]<<" ";
        cout<<endl;}
        else{
            cout<<v[0]<<" "<<v[n-1]<<endl;
        }
    }
}