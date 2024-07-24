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
        vi ans;
        msi m;
        REP(i,0,n-1){
            int a;cin>>a;
            v.push_back(a);
        }
        REP(i,0,n-1){
            if(m[v[i]]>i)ans.push_back(m[v[i]]);
            else{
                int j=i;
                while(j<=n && v[j]==v[i]){
                    j++;
                }
                m[v[i]]=j;
                ans.push_back(j);
            }
        }
        int q;cin>>q;
        REP(i,1,q){
            int l,r;cin>>l>>r;
            if(ans[l-1]==n || ans[l-1]+1>r)cout<<-1<<" "<<-1<<endl;
            else cout<<l<<" "<<ans[l-1]+1<<endl;
        }
        cout<<endl;
        
    }
}