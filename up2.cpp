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
set<int> PrimeFactors(int n) {
    set<int> primeFactors;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p <= n; p++) {
        while (n % p == 0 && prime[p]) {
            primeFactors.insert(p);
            n /= p;
        }
    }

    return primeFactors;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n,q;cin>>n>>q;
        set<int> pfac=PrimeFactors(n);
        vi fac;
        for(auto it:pfac){
            int tmp=1;
            int y=n;
            int cnt=0;
            while(y%it==0){
                cnt++;
                y=y/it;
            }
            // int x=cnt;
            // while(x%2==0){
            //     tmp++;
            //     x=x/2;
            // }
            fac.push_back(cnt);
        }
        // for(auto it:fac)cout<<it<<" ";
        ll modulo=1e9+7;
        for(int i=0;i<q;i++){
            ll ways=1;
            for(auto it:fac){
                int p;cin>>p;
                p++;
                if(it%p==0){
                    ways*=max(1,it-it/p+1);
                }
                else{
                    ways*=max(1,it-it/p);
                }
            }
            cout<<ways;
        }

    }
}