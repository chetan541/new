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
        int n,m;cin>>n>>m;
        vector<vector<int>> v1(n,vi(m,0));
        vector<vector<int>> v2(n,vi(m,0));
        int flag=1;
        // cout<<m<<endl;
        REP(i,0,n-1){
            REP(j,0,m-1){
            int a;cin>>a;
            v1[i][j]=a;
            }
        }

        REP(i,0,n-1){
            REP(j,0,m-1){
            int a;cin>>a;
            v2[i][j]=a;
            }
        }

        int s1=0,s2=0;
        REP(i,0,n-1){
            REP(j,0,m-1){
                // cout<<v2[i][j];
                s1+=v1[i][j];
                s2+=v2[i][j];
                // cout<<s2<<endl;
                
            }
            // cout<<s1<<" "<<s2<<endl;
            // cout<<endl;
            if((s1%3)!=(s2%3))flag=0;
            s1=0,s2=0;
        }
        s1=0,s2=0;
        REP(i,0,m-1){
            REP(j,0,n-1){
                s1+=v1[j][i];
                s2+=v2[j][i];
            }
            if((s1%3)!=(s2%3))flag=0;
            s1=0,s2=0;
        }
        if(flag)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}