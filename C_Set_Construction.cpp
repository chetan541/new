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
void dfs(int node,vector<int> adj[],int vis[],set<int> arr[]){
    if(vis[node])return;
    for(auto it:adj[node]){
        
            dfs(it,adj,vis,arr); 
            for(auto jt:arr[it]){
                arr[node].insert(jt);
            }
          
    }
    arr[node].insert(node);
    vis[node]=1;
    
    


}

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> adj[n+1];
        int vis[n+1] = {0};
        // int arr[n][n];
        // msi m;
        REP(i,1,n){
            REP(j,1,n){
                char a;cin>>a;
                // arr[i][j]=a;
                if(a=='1'){
                adj[j].push_back(i);}
            }
        }
        set<int> arr[n+1];
        REP(i,1,n){
           
            dfs(i,adj,vis,arr);
        }
        REP(i,1,n){
            cout<<arr[i].size()<<" ";
            for(auto it: arr[i]){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        
    }
}