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
//}'

void dfs(int node,vi adj[],pi edges[],vi &tmp,int ans[],int vis[],ll &calc1,ll &calc2){
    vis[node]=1;
    if(node!=1){
        auto it=lower_bound(tmp.begin(),tmp.end(),calc1);
        int m=tmp.size();
        // cout<<node<<" "<<calc1<<" "<<calc2<<endl;
        if(it==tmp.end()){
            ans[node]=m;
        }
        else if(*it!=calc1){
            ans[node]=it-tmp.begin();
        }
        else{
            ans[node]=it-tmp.begin()+1;
        }
    }
    for(auto vt:adj[node]){
        if(vis[vt]==0){
            calc1+=edges[vt].F;
            calc2+=edges[vt].S;
            tmp.push_back(calc2);
            dfs(vt,adj,edges,tmp,ans,vis,calc1,calc2);
        }
    }
    calc1-=edges[node].F;
    calc2-=edges[node].S;
    tmp.pop_back();
}
int main(){
 ios::sync_with_stdio(false), cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vi adj[n+1];
       pi edges[n+1];
        REP(i,2,n){
            int a,b,c;cin>>a>>b>>c;
            adj[a].push_back(i);
            edges[i]={b,c};
        }
        int vis[n+1]={0};
        int ans[n+1];
        vi tmp;
        ll calc1=0,calc2=0;
        dfs(1,adj,edges,tmp,ans,vis,calc1,calc2);
        // for(auto it:adj[1])cout<<it<<" ";
        REP(i,2,n)cout<<ans[i]<<" ";
        cout<<'\n';

        
    }
}