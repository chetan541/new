#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<pair<int,int>, int> msi;
  
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
int dfs(int node, vector<int> adj[],msi & m,int vis[],int intro){
    int ans=0,flag=0;
    vis[node]=1;
    for(auto it : adj[node]){
        if(!vis[it]){
            flag=0;
        if(m[make_pair(node,it)]<intro)flag=1;
        ans=max(ans,dfs(it,adj,m,vis,m[make_pair(node,it)])+flag);
        }
    }
    // ans+=flag;
    return ans;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int vis[n+1] = {0};
        vector<int> adj[n+1];
        msi m;
        // m[1]=-1;
        for(int i=0;i<=n-2;i++){
            int u,v;
            cin>>u>>v;
            m[make_pair(u,v)]=i;
            m[make_pair(v,u)]=i;
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int intro=n+1;
        cout<<dfs(1,adj,m,vis,intro)<<endl;
        
    }
}