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
        int n,m;cin>>n>>m;
        vi v1,v2;
        v1.push_back(1);
        REP(i,0,n-2){
            int a;cin>>a;
            v1.push_back(a);
        }
        REP(i,0,n-1){
            int b;cin>>b;
            v2.push_back(b);
        }
        int flag=0;
        REP(i,0,n-1){
            if(v2[i]<=v1[i])flag=1;
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        int l1=0,r1=n-1;
        int l2=0,r2=n-1,ans=0;
        while(r1>=0){
            if(v2[r2]>v1[r1])r1--,r2--;
            else l2++,r1--,ans++;
            // cout<<r1<<" "<<r2<<" "<<v2[r2]<<endl;
        } 
        cout<<ans<<endl;  
    }
}