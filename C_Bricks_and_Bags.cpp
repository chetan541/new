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
        set<int> s;
        vi v;
        map<int,int> m;
        REP(i,0,n-1){
            int a;cin>>a;m[a]++;
            // s.insert(a);
            v.push_back(a);
        }
        int szn=n/3;
        ll ans=0;
        // for(auto it:s)v.pb(it);
        sort(v.begin(),v.end());
        REP(i,0,n-1){
            if(i>=2){
                ans=max(ans,1LL*v[i]-v[i-1]+v[i]-v[0]);
            }
            if(i<n-2){
                ans=max(ans,1LL*v[i+1]-v[i]+v[n-1]-v[i]);
            }
        }
        
        // vi v1,v2,v3;
        // REP(i,0,szn-1){
        //     v1.pb(v[i]);
        // }
        // REP(i,szn,2*szn+n%3-1)v2.pb(v[i]);
        // REP(i,2*szn+n%3,n-1)v3.pb(v[i]);
        // for(auto it:v1)cout<<it<<" ";
        // cout<<endl;
        // for(auto it:v2)cout<<it<<" ";
        // cout<<endl;
        // for(auto it:v3)cout<<it<<" ";
        // cout<<endl;
        // ll ans=0;
        // n=v.size();
        
        // if(n>2){ans+=abs(v[n-1]-v[0]);
        // ll tmp1=0,tmp2=0;
        // // int y=v2.size();
        
        // tmp1+=abs(v[0]-v[1]);
        
        
        // tmp2+=abs(v[n-1]-v[n-2]);
        
        // cout<<ans+max(tmp2,tmp1)<<endl;}
        // else{
        //     if(n==1)cout<<0<<endl;
        //     else{
        //         cout<<2*(abs(v[0]-v[1]))<<endl;
        //         }
        //     }
        cout<<ans<<endl;
        }
    }
