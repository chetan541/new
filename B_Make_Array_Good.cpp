#include<bits/stdc++.h>
using namespace std;
const int N=2e5+2;
long long int dp[N+1];
int dfs(int node,vector<int>adj[],long long int cost[]){
     long long int sum=0;
     for(auto it:adj[node]){
          if(dp[it]!=-1) sum +=dp[it];
          else {
            sum += dfs(it,adj,cost);
          }
     }
     return dp[node]=min(sum,cost[node]);
}
void solve(){
   int n,k;cin>>n>>k;
   for(int i=0;i<n+1;i++) dp[i]=-1;
  long long int c[n+1];
   for(int i=0;i<n;i++) cin>>c[i];
   int p[k+1];
   for(int i=0;i<k;i++) {
        cin>>p[i];
        dp[p[i]]=0;
   }
   int n1=n;
   vector<int>adj[n+1];
   int y=1;
   while(n1--){
       int m;cin>>m;
       while(m--){
           int s;cin>>s;
           adj[y].push_back(s);
           adj[s].push_back(y);
       }
       ++y;
   }
   

//    vector<int>vis(n+1,0);
 // cout<<i<<"-> ";
    // for(auto it:adj[i]) cout<<it<<" ";
    // cout<<endl;


   for(int i=1;i<=n;i++){
   
        if(dp[i]==-1) {
            cout<<"h"<<" ";
            dfs(i,adj,c);
        }
   }
   for(int i=1;i<=n;i++) cout<<dp[i]<<" ";
   cout<<endl;
  
}

int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}