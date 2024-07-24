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
 ios::sync_with_stdio(false), cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        
        int l1=INT_MAX,r1=INT_MIN;
        int l2,r2;
        int ans=INT_MAX;
        REP(i,0,n-1){
            int a,b,c;cin>>a>>b>>c;
            if(a<=l1 && b>=r1 && !(a==l1 && b==r1)){
                ans=c;
                l1=a;r1=b;
                l2=c,r2=c;
            }
            else if(a==l1 && b==r1){
                if(ans>c){
                    l2=c,r2=c;
                    ans=c;
                }
            }
            else{
                if(l1>a){
                    if(l2==ans)ans=c+ans;
                    else ans=c-l2+ans;
                    l2=c;
                    l1=a;
                }
                else if(l1==a){
                    if(c-l2+ans<ans && ans!=l2){
                        
                        ans=c-l2+ans;
                        l2=c;
                    }
                }

                if(r1<b){
                    if(r2==ans)ans=c+ans;
                    else ans=c-r2+ans;
                    r2=c;
                    r1=b;
                }
                else if(r1==b){
                    if(c-r2+ans<ans && ans!=r2){
                        
                        ans=c-r2+ans;
                        r2=c;
                    }
                }
            }
            // cout<<l1<<" "<<r1<<endl;
            cout<<ans<<endl;
        }
        
    }
}