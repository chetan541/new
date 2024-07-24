#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef vector<pi> vii;
typedef set<int> si;
typedef map<string, int> msi;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first 
#define S second
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;
#define multi_ordered_set tree<ll, null_type,greater_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
  
  
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
#define MAXN 100001
 

std::vector<int> sieveOfEratosthenes(int n) {
    std::vector<char> isPrime(n, 1); // Initialize all numbers as prime
    std::vector<int> primes;

    // 0 and 1 are not prime numbers
    isPrime[0] = isPrime[1] = 0;

    // Mark all multiples of primes as non-prime
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    // Collect all prime numbers
    for (int i = 2; i < n; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}
int main(){
 ios::sync_with_stdio(false), cin.tie(0);
    int t;cin>>t;
    // sieve();
    ll lim=ceil(sqrt(1e9));
    vector<int> p = sieveOfEratosthenes(lim);
    // cout<<p.size()<<endl;
    
    // cout<<endl;
    while(t--){
        int n;cin>>n;
        map<int,int> m;
        bool flag=false;
        REP(i,0,n-1){
            int a;cin>>a;
            // v.push_back(a);
            for(auto it:p)
            {
             if(a%it==0){
                // cout<<it<<endl;
                m[it]++;
                while(a%it==0){
                    a/=it;
                }
                if(m[it]>=2 ){
                    // cout<<it<<endl;
                    flag=true;
                }
             }
            
            }
            //  cout<<a<<" ";
            m[a]++;
             if(m[a]>=2 && a!=1){
                    // cout<<a<<endl;
                    flag=true;
                }
        }
        
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        
    }
}
			 		 	 	  	 		  				  		 	  	