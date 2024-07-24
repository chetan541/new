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
        int x = n+m+1;
        vector<int> v[x];
        unordered_map<int,int> map;
        int prev=n+1;
        REP(i,0,m-1){
            int a,b,c;cin>>a>>b>>c;
            if(map[c]==0){map[c]=prev;prev++;}
            v[a].push_back(map[c]);
            v[b].push_back(map[c]);
            v[map[c]].push_back(a);
            v[map[c]].push_back(b);

        }
        int level[x];
        int vis[x];
        memset(level,0,sizeof(level));
        memset(vis,0,sizeof(vis));
        queue<int> q;
        int l,r;cin>>l>>r;
        vis[l]=1;
        q.push(l);
        while(!q.empty()){
            int y=q.front();
            q.pop();
            for(auto it:v[y]){
                if(!vis[it]){
                    vis[it]=1;
                    level[it]=level[y]+1;
                    q.push(it);
                }
            }
        }
        // REP(i,1,6)cout<<level[i]<<" "<<vis[i]<<endl;
        
        cout<<(level[r]/2)<<endl;

        
    }
}