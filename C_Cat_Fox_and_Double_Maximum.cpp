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
// int is_prime[1000001];
//vector<int> primes;
//vi SieveOfEratosthenes(int n) {
//    vi v;
//    bool prime[n + 1];
 //   memset(prime, true, sizeof(prime));
 
 //   for (int p = 2; p * p <= n; p++) {
  //      if (prime[p] == true) {
  //          for (int i = p * p; i <= n; i += p)
  //              prime[i] = false;
   //     }
   // }
    //for (int p = 2; p <= n; p++) {
     //   if (prime[p])
     //       v.push_back(p);
    //}
   // return v;
//}
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vi v;
        map<int,int> m;
        REP(i,0,n-1){
            int a;cin>>a;m[a]=i;
            v.pb(a);
        }
        map<int,int> ans;
        if(m[1]%2==0){
            int cnt1=n,cnt2=n;
            set<int> s1,s2;
            for(int i=1;i<n-1;i+=2){
                s1.insert(v[i]);
            }
            for(auto it:s1){
                ans[it]=cnt1;cnt1--;
            }
            // cnt2=cnt1;
            for(int i=0;i<n;i+=2){
                s2.insert(v[i]);
            }
            s2.insert(v[n-1]);
            for(auto it:s2){
                ans[it]=cnt1;cnt1--;
            }
        }
        else{
            int cnt1=n,cnt2=n;
            set<int> s1,s2;
            for(int i=2;i<n-1;i+=2){
                s1.insert(v[i]);
            }
            for(auto it:s1){
                ans[it]=cnt1;cnt1--;
            }
            // cnt2=cnt1;
            for(int i=1;i<n;i+=2){
                s2.insert(v[i]);
            }
            s2.insert(v[n-1]);
            s2.insert(v[0]);
            for(auto it:s2){
                ans[it]=cnt1;cnt1--;
            }
        }
        REP(i,0,n-1){
            cout<<ans[v[i]]<<" ";
        }
        cout<<endl;


    }
}