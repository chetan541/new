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
        int n,m,k;cin>>n>>m>>k;
        msi m1,m2;
        REP(i,0,n-1){
            int a;cin>>a;
            m1[a]++;
        }
         REP(i,0,m-1){
            int a;cin>>a;
            m2[a]++;
        }
        int l1=0,l2=0,l3=0;
        REP(i,1,k){
            if(m1[i]>=1 && m2[i]==0)l1++;
            if(m2[i]>=1 && m1[i]==0)l2++;
            if(m1[i]>=1 && m2[i]>=1)l3++;
        }
        // cout<<l1<<" "<<l2<<" "<<l3<<endl;
        if(l1+l2+l3==k && l1<=k/2 && l2<=k/2)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}