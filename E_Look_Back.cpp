#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<ll> vi;
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
int leadingZeros(ll n){
    return __builtin_clzll(n);
}
int main(){
 ios::sync_with_stdio(false), cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vi v;
        REP(i,0,n-1){
            int a;cin>>a;
            v.push_back(a);
        }
        if(n!=1){
        ll ans=0;    
        ll cnt=0;
        int ind=1;
        REP(i,1,n-1){
            if(v[i]<v[i-1]){
                ll tmp=abs(leadingZeros(v[i])-leadingZeros(v[i-1]));
                ll x=(v[i]<<tmp);
                cnt+=tmp;
                if(x<v[i-1]){
                    // v[i]*=2;
                    cnt++;
                }
                ind=i;
                break;
            }
        }
        // cout<<cnt<<" "<<ind<<endl;
        ans=cnt;
        REP(i,ind+1,n-1){
            if(v[i-1]>v[i]){
                ll tmp=abs(leadingZeros(v[i])-leadingZeros(v[i-1]));
                ll x=(v[i]<<tmp);
                cnt+=tmp;
                if(x<v[i-1]){
                    cnt++;
                    // tmp++;
                }
                ans+=cnt;
            }
            else if(v[i-1]<v[i]){
                ll tmp=abs(leadingZeros(v[i])-leadingZeros(v[i-1]));
                ll x=(v[i-1]<<tmp);
                cnt-=tmp;
                
                if(x>v[i]){
                    cnt++;
                    // tmp++;
                }
                cnt=max(0LL,cnt);
                // cout<<cnt<<" "<<i<<" "<<tmp<<endl;
                ans+=cnt;

            }
            else ans+=cnt;
            
        }
        cout<<ans<<endl;
        }
        else cout<<0<<endl;
        
    }
}