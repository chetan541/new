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
bool dfs(vector<int> v[],vi &color,int n,int ind,int par){
    for(auto it:v[ind]){
        
        if(it!=par && color[it]==color[ind])return false;
        if(it!=par && color[it]==-1){
            
            color[it]=(color[ind]^1);
            if(dfs(v,color,n,it,ind)==false)return false;
        }
        
    }
    return true;
}
int main(){
 ios::sync_with_stdio(false), cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> v[2*n+1];
        vi color(2*n+1,-1);
        int flag=1;
        REP(i,0,n-1){
            int a,b;cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
            if(a==b)flag=0;
            if(v[a].size()>2 || v[b].size()>2){
                flag=0;
            }
        }
        if(flag==1){
            bool ans=true;
            // cout<<v[1].size()<<endl;
            REP(i,1,2*n){
                if(v[i].size()==0)continue;
                if(color[i]==-1){
                    // color[i]=0;
                    if(v[i].size()==2 && v[i][0]==v[i][1]){
                        continue;
                    }
                   else{color[i]=0; ans&=dfs(v,color,2*n,i,-1);}
                }
            }
            if(ans)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else cout<<"NO"<<endl;
        
        


    }
}