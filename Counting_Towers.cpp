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
const int MOD = 1e9 + 7;
int dp[1000001][2];

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int t; cin >> t;
    memset(dp, 0, sizeof(dp));
    dp[1][0] = 1;
    dp[1][1] = 1;
    REP(i, 2, 1e6){
        dp[i][1] = (2LL * dp[i - 1][1] + dp[i - 1][0]) % MOD;
        dp[i][0] = (dp[i - 1][1] + 4LL * dp[i - 1][0]) % MOD;
    }
    while(t--){
        int n; cin >> n;
        cout << (dp[n][0] + dp[n][1]) % MOD << endl;
    }
    return 0;
}
