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
        int a1,a2,b1,b2,c1,c2,d1,d2;
        cin>>a1>>a2;
        cin>>b1>>b2;
        cin>>c1>>c2;
        cin>>d1>>d2;
        set<int> s1;
        set<int> s2;
        s1.insert(a1);
        s1.insert(b1);
        s1.insert(c1);
        s1.insert(d1);
        // for(auto it:s1){
        //     cout<<it<<" ";
        // }
        // for(auto it:s2){
        //     cout<<it<<" ";
        // }
        int ans1;
        ans1=abs(*s1.begin()-*(s1.rbegin()));
        // cout<<ans1<<endl;
        s2.insert(a2);
        s2.insert(b2);
        s2.insert(c2);
        s2.insert(d2);
        //  for(auto it:s2){
        //     cout<<it<<" ";
        // }
        int ans2;
        ans2=abs(*s2.begin()-*(s2.rbegin()));
        cout<<ans1*ans2<<endl;
        
        
    }
}