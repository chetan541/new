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
vector<int> getAllFactors(int number) {
    vector<int> factors;

    for (int i = 1; i * i <= number; ++i) {
        if (number % i == 0) {
            factors.push_back(i);

            // Avoid duplicates when the factor is not a perfect square
            if (i != number / i) {
                factors.push_back(number / i);
            }
        }
    }

    return factors;
}

int main(){
    int t;cin>>t;
    while(t--){
        int x,n;cin>>x>>n;
        
        vi fac=getAllFactors(x);
        sort(fac.begin(),fac.end());
        // for(auto it:fac)cout<<it<<" ";
        int ans=0;
        REP(i,0,fac.size()-1){
            if(x/fac[i]<n)break;
            else ans=fac[i];
        }
        cout<<ans<<endl;
        
    }
}