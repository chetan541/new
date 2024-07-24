#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
  
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
int is_prime[1000001];
vector<int> primes;
vi SieveOfEratosthenes(int n) {
    vi v;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++) {
        if (prime[p])
            v.push_back(p);
    }
    return v;
}
int dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
    
        vis[node] = 1; 
         
        // traverse all its neighbours
        int cnt=0,ans=0;
        for(auto it : adj[node]) {
            cout<<it<<endl;
            
            // if the neighbour is not visited
            if(!vis[it]) {
                cnt++;
                ans+=dfs(it, adj, vis, ls); 
                // cout<<ans<<endl;
            }
            // cout<<ans<<endl;
            
        }
        if(ans==0){ls[node]=1;return 1;}
        else{ ls[node]=ans;return ans;}
}


int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> adj[n+1];
        int vis[n+1] = {0}; 
        vector<int> ls(n+1,0);
        REP(i,0,n-2){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // REP(i,1,n){
        //     for(auto it:adj[i]){
        //         cout<<it<<" ";
        //     }
        //     cout<<endl;
        // }
        int start = 0;
        // cout<<dfs(1,adj,vis,ls)<<ls[5]<<endl;
        int temp=dfs(1,adj,vis,ls);
        // create a list to store dfs
        // vector<int> ls; 
        int q;cin>>q;
        REP(i,0,q-1){
            int x,y;cin>>x>>y;
            ll ans=(ls[x]*1LL)*(ls[y])*(1LL);
            cout<<ans<<endl;
        }
        
        
    }
}