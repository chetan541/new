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
// vector<pair<int,int>> vec(5000,make_pair(0,0));
int arr[5000][2];
// int cnt=0;
pair<int,int> dfs(int node, vector<int> adj[], int vis[], string &s,int &cnt){
    
        vis[node] = 1; 
        int w=0,b=0;
        if(s[node-1]=='B')b=1;
        else w=1;
        arr[node][0]=w;
        arr[node][1]=b;
        for(auto it : adj[node]) {
            if(!vis[it]){
                pair<int,int> temp=dfs(it,adj,vis,s,cnt);
                arr[node][0]+=temp.first;
                arr[node][1]+=temp.second;
            }       
        }
        if(arr[node][0]==arr[node][1])cnt++;
        return make_pair(arr[node][0],arr[node][1]);
        
}


int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int cnt=0;
        vector<int> adj[n+1];
        int vis[n+1] = {0}; 
        // vector<int> ls(n+1,0);
        REP(i,2,n){
            int u;
            cin>>u;
            adj[u].push_back(i);
        }
        
        string s;cin>>s;
        pair<int,int> temp;
        temp=dfs(1,adj,vis,s,cnt);
        
        cout<<cnt<<endl;
        cnt=0;  
    }
}