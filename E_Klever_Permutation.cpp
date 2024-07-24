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
        int n,k;cin>>n>>k;
        int arr[n]={0};
        int prev1=1,prev2=n;
        REP(i,0,k-1){
            // arr[i]=prev+1;
            if(i%2==0){
            int j=i;
            while(j<=n-1){
                arr[j]=prev1;
                prev1++;
                j+=k;
            }
            }
            else{
                 int j=i;
            while(j<=n-1){
                arr[j]=prev2;
                prev2--;
                j+=k;
            }
        }
            }
            // cout<<prev<<endl;
        
        
        // REP(i,k/2,k-1){
        //      int j=i;
        //     while(j<=n-1){
        //         arr[j]=prev2;
        //         prev2--;
        //         j+=k;
        //     }
        // }
        REP(i,0,n-1)cout<<arr[i]<<" ";
        cout<<endl;
        
        
    }
}
