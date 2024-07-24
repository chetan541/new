#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
long  long dp[200001];

int dfs(int node, int n, vector<int> adj[], vi &v) {
    if(dp[node]!=-1)return dp[node];
    long long ans=0,cnt=0;
    for(auto it:adj[node]){
        ans+=dfs(it,n,adj,v);
        cnt++;
    }
    if(cnt==0)ans=INT_MAX;
    dp[node]=min(1LL*v[node],ans);
    return dp[node];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vi v(n + 1);
        memset(dp, -1, sizeof(dp));

        for (int i = 1; i <= n; ++i) {
            cin >> v[i];
        }

        for (int i = 0; i < k; ++i) {
            int b;
            cin >> b;
            v[b] = 0;
        }

        vector<int> adj[n + 1];
        for (int i = 1; i <= n; ++i) {
            int m;
            cin >> m;
            // if(m==0)adj[i].push_back(0);
            for (int j = 0; j < m; ++j) {
                int x;cin>>x;
                adj[i].push_back(x);
            }
        }

        for (int i = 1; i <= n; ++i) {
            if(dp[i]==-1){
             dfs(i, n, adj, v);} 
        }
        for (int i = 1; i <= n; ++i) {
           cout<<dp[i]<<" ";
        }
        

        cout << endl;
    }

    return 0;
}
