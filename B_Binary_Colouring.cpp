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
void getBinaryRepresentation(int number, vi &tmp) {
    
    // binaryArray.resize(32);
    
    
    for(int i = 31; i >= 0; --i) {
        tmp[i] = (number & 1); 
        number >>= 1; 
    }
}
int main(){
 ios::sync_with_stdio(false), cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vi ans(32,0);
        vi tmp(32,0);
        getBinaryRepresentation(n,tmp);
    //     REP(i,0,31) {
    //    cout<<tmp[i]<<" ";
    // }
    cout<<endl;
    ans=tmp;
    for(int i=31;i>=2;i--){
        if(ans[i]==1 && ans[i-1]==1){
            int j=i-1;
            while(j>=1 && ans[i]==ans[j])j--;
            j++;
            // cout<<i<<" "<<j<<endl;
            ans[i]=-1;ans[j-1]=1;
            REP(z,j,i-1)ans[z]=0;
            i=j;
        }
        // else if(tmp[i]==1)ans[i]=1;
    }
    // if(tmp[31]==1 && ans[31]!=-1)ans[31]=1;
    cout<<32<<endl;
    for(int i=31;i>=0;i--)cout<<ans[i]<<" ";
    cout<<endl;
        

        
    }
}