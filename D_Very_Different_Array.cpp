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
        vi v1,v2;
        // vector<pair<int,int>> v3;
        REP(i,0,n-1){
            int a;cin>>a;
            v1.push_back(a);
            // v3.push_back(make_pair(a,1));
        }
        REP(i,0,m-1){
            int b;cin>>b;
            v2.push_back(b);
            // v3.push_back(make_pair(b,2));
        }
        msi hash;
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        REP(i,0,n-1){
            int temp=abs(v1[i]-v2[m-1-i]);
            // cout<<temp<<" ";
            hash[i]=temp;
        }
        REP(i,0,n-1){
            int temp1=abs(v2[i]-v1[n-1-i]);
            // cout<<temp1<<" ";
            hash[n-1-i]=max(hash[n-1-i],temp1);
            
        }
        // cout<<endl;
        // for(auto it:hash){
        //     cout<<it.second<<" ";
        // }
        ll ans=0;
        for(auto it:hash){
            ans+=it.second;
        }
        cout<<ans<<endl;




        
    }
}