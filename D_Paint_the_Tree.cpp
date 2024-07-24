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
void dfs(int node,vi &vis,vi adj[],int par[]){
    vis[node]=1;
    for(auto it:adj[node]){
        if(vis[it]==0){
            
            par[it]=node;
            dfs(it,vis,adj,par);
        }
        
    }
}
int dfs1(int node,vi &vis,vi adj[]){
    int ans=1;
    vis[node]=1;
    for(auto it:adj[node]){
        if(vis[it]==0){
            ans=max(ans,dfs1(it,vis,adj)+1);
        }
    }
    return ans;
}

int main(){
 ios::sync_with_stdio(false), cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int a,b;cin>>a>>b;

        vi adj[n+1];
        vi vis(n+1,0);
        REP(i,1,n-1){
            int a,b;cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        int par[n+1];
        par[a]=-1;
        dfs(a,vis,adj,par);
        vi ans;
        ans.pb(b);
        int tmp=b;
        while(par[tmp]!=-1){
            ans.pb(par[tmp]);
            tmp=par[tmp];
        }
        vi v1(n+1,0);
        int tmp1=dfs1(ans[ans.size()/2],v1,adj);
        cout<<2*(n-1)-tmp1+1+ans.size()/2<<endl;
        
        
    }
}