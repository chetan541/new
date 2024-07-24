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
        int a[n][m],b[n][m];
        REP(i,0,n-1){
            REP(j,0,m-1){
            cin>>a[i][j];
            }
        }
        if(n==1 && m==1)cout<<-1<<endl;
        else if(m>1){
        REP(i,0,n-1){
            b[i][0]=a[i][m-1];
            cout<<b[i][0]<<" ";
            REP(j,1,m-1){
                b[i][j]=a[i][j-1];
                cout<<b[i][j]<<" ";
            }
            cout<<endl;
        }
        }
        else{
            REP(i,0,m-1){
                b[0][i]=a[n-1][i];
                // cout<<b[0][i]<<endl;
            REP(j,1,n-1){
                b[j][i]=a[j-1][i];
                
            }
            REP(i,0,n-1){
            
            REP(j,0,m-1){
                
                cout<<b[i][j]<<" ";
            }
            cout<<endl;
        }
           
        }
        }
       
        
    }
}