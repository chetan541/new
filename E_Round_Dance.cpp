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
int dfs(int node,set<int> adj[],int vis[],int parent){
     vis[node]=1;
     int ans=0;
     for(auto it:adj[node]){
        // cout<<node<<" "<<it<<" "<<ans<<endl;
        if(it!=parent && vis[it]==1)ans=1;
        else if(vis[it]!=1){
            ans=dfs(it,adj,vis,node);
        }
     }
     return ans;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        set<int> adj[n+1];
        int vis[n+1] = {0}; 
        // vector<int> ls(n+1,0);

        REP(i,1,n){
            int u;
            cin>>u;
            adj[i].insert(u);
            adj[u].insert(i);
        }
        // REP(i,1,n){
        //     for(auto it:adj[i])cout<<it<<" ";
        //     cout<<endl;
        // }
        int ans=0;
        int tmp=0;
        REP(i,1,n){
            if(adj[i].size()==1)tmp++;
            if(vis[i]!=1){
                ans+=dfs(i,adj,vis,-1);
                
            }
            // cout<<ans<<" "<<i<<endl;
        }
        cout<<ans+(tmp>0)<<" "<<ans+(tmp)/2<<endl;
        

    }
}