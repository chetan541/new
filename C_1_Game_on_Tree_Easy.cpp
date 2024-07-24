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
void dfs(int node,vi &vis,vi &height,vi adj[]){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            height[it]=1+height[node];
            dfs(it,vis,height,adj);
        }
    }
}
int main(){
 ios::sync_with_stdio(false), cin.tie(0);
    
        int n,t;cin>>n>>t;
        vi adj[n+1];
        REP(i,1,n-1){
            int a,b;cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        int ind=0;
        REP(i,1,n){
            if(adj[i].size()==1){ind=i;break;}
        }
        // cout<<ind<<endl;
        vi vis(n+1,0);
        vi height(n+1,0);
        dfs(ind,vis,height,adj);
        REP(i,1,t){
            int a;cin>>a;
            if(height[a]%2!=0 || (n-1-height[a])%2!=0){
                cout<<"Ron"<<endl;
            }
            else cout<<"Hermione"<<endl;
        }

        
    }
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
void dfs(int node,vi &vis,vi &height,vi adj[]){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            height[it]=1+height[node];
            dfs(it,vis,height,adj);
        }
    }
}
int main(){
 ios::sync_with_stdio(false), cin.tie(0);
    
        int n,t;cin>>n>>t;
        vi adj[n+1];
        REP(i,1,n-1){
            int a,b;cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        int ind=0;
        REP(i,1,n){
            if(adj[i].size()==1){ind=i;break;}
        }
        // cout<<ind<<endl;
        vi vis(n+1,0);
        vi height(n+1,0);
        dfs(ind,vis,height,adj);
        REP(i,1,t){
            int a;cin>>a;
            if(height[a]%2!=0 || (n-1-height[a])%2!=0){
                cout<<"Ron"<<endl;
            }
            else cout<<"Hermione"<<endl;
        }

        
    }
