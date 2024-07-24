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
        int n,m;cin>>n>>m;
        vi v;
        msi pos,ans;
        REP(i,0,n-1){
            int a;cin>>a;
            v.push_back(a);pos[a]++;
            ans[a]=m+1;
        }
        REP(i,2,m+1){
            int a,b;cin>>a>>b;
            pos[b]++;pos[v[a-1]]--;
            if(pos[v[a-1]]==0)
            ans[v[a-1]]-=abs(m+1-i+1);
            if(pos[b]==1 && v[a-1]!=b)ans[b]+=m+1-i+1;
            v[a-1]=b;
        }
        // for(auto it:pos){
        //     if(it.second!=0){
        //         // cout<<it.first<<" "<<it.second<<endl;
        //         ans[it.first]+=abs(m+1-pos[it.first]+1);
        //     }
        // }
        ll comb=0;ll tmp=0;
        for(auto it:ans){
            tmp=1LL*(1LL*(m+1)*m)/2-(1LL*(m+1-it.second)*(m-it.second))/2;
            // cout<<it.first<<" "<<it.second<<endl;
            comb+=tmp;
        }
        cout<<comb<<endl;

        
    }
}