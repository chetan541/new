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
vector<int> getDivisors(int n) {
    vector<int> divisors;
    
    // Iterate from 1 to sqrt(n)
    for (int i = 1; i * i <= n; ++i) {
        // If i is a divisor
        if (n % i == 0) {
            divisors.push_back(i);

            // Check if the other divisor is not the same
            if (n / i != i) {
                divisors.push_back(n / i);
            }
        }
    }

    return divisors;
}


int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vi v;
        vi div=getDivisors(n);
        int flag=1;
        REP(i,0,n-1){
            int a;cin>>a;
            v.push_back(a);
        }
        int ans,cnt=0;
        for(auto it:div){
            ans=0;
            REP(i,0,it-1){
                int prev=v[i];
                
                for(int j=i+it;j<=n-1;j+=it){

                    ans=gcd(ans,abs(v[j]-prev));
                    prev=v[j];
                }
            }
            if(ans!=1)cnt++;
        }
        cout<<cnt<<endl;

        
    }
}