#include <bits/stdc++.h>
using namespace std;

int dfs(int node, vector<int> adj[], string &s) {
    if (adj[node][0] == 0 && adj[node][1] == 0) {
        return 0; // Leaf node reached
    }

    int s1 = INT_MAX, s2 = INT_MAX;

    if (adj[node][0] != 0) {
        s1 = dfs(adj[node][0], adj, s);
        if (s[node - 1] != 'L') {
            s1++;
        }
    }

    if (adj[node][1] != 0) {
        s2 = dfs(adj[node][1], adj, s);
        if (s[node - 1] != 'R') {
            s2++;
        }
    }

    return min(s1, s2);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> adj[n + 1];

        for (int i = 1; i <= n; i++) {
            int u, v;
            cin >> u >> v;
            adj[i].push_back(u);
            adj[i].push_back(v);
        }

        cout << dfs(1, adj, s) << endl;
    }

    return 0;
}
