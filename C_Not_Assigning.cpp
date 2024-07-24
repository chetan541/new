#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<int, int> msi;
  
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
// int flag=0;
void dfs(int node,vector<int> adj[],int vis[],int &prev,map<pair<int,int>,int> &m){
    vis[node]=1;
    if(prev==5)prev=2;
    else prev=5;
    for(auto it:adj[node]){
        
        if(!vis[it]){
            
            m[make_pair(node,it)]=prev;
            m[make_pair(it,node)]=prev;
            dfs(it,adj,vis,prev,m);
             
        }
        
        
    }
    
    
}

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> adj[n+1];
        int vis[n+1] = {0}; 
        vector<pair<int,int>> vec;
        msi mp;
        REP(i,2,n){
            int u,v;
            cin>>u>>v;
            mp[u]++;mp[v]++;
            vec.push_back(make_pair(u,v));
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
         map<pair<int,int>,int> m;
         int cnt=0,prev=5;
         
         int ind=1;
         for(auto it:mp){
            if(it.second==1)ind=it.first;
            if(it.second>=3)cnt=2;
            // cout<<it.first<<" "<<it.second<<endl;
         }
         if(cnt!=2){
            dfs(ind,adj,vis,prev,m);
             REP(i,0,n-2){
                cout<<m[vec[i]]<<" ";
          }
         }
         else cout<<-1;
         cout<<endl;
         
        
        
        
    }
}