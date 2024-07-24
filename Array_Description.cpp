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
    for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define TRvi(c, it) \
    for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
    for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
    for (msi::iterator it = (c).begin(); it != (c).end(); it++)

#define INF 2000000000 // 2 billion

// If you need to recall how to use memset:
#define MEMSET_INF 127     // about 2B
#define MEMSET_HALF_INF 63 // about 1B

int dp[100001][101];
int main()
{
    int modulo=1e9+7;
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vi v;
    REP(i, 0, n - 1)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }

    memset(dp, 0, sizeof(dp));
    if (v[0] == 0)
    {
        REP(i, 1, m)
        {
            dp[1][i]=1;
        }
    }
    else dp[1][v[0]]=1;

    REP(i,2,n)
    {
        REP(j,1,m)
        {
            if(v[i-1]!=0 && j==v[i-1])
            {
                int cnt=0;
                if(v[i-1]<=m){cnt+=dp[i-1][v[i-1]];cnt%=modulo;}
                if(v[i-1]-1>=0 && v[i-1]-1<=m){cnt+=dp[i-1][v[i-1]-1];cnt%=modulo;}
                if(v[i-1]+1<=m){cnt+=dp[i-1][v[i-1]+1];cnt%=modulo;}
                dp[i][v[i-1]]=cnt;
            }
            else if(v[i-1]!=0 && j!=v[i-1])
            {
                dp[i][j]=0;
            }
            else
            {
                int cnt=0;
                if(j-1>=0 && j-1<=m){cnt+=dp[i-1][j-1];cnt%=modulo;}
                if(j<=m){cnt+=dp[i-1][j];cnt%=modulo;}
                if(j+1<=m){cnt+=dp[i-1][j+1];cnt%=modulo;}
                dp[i][j]=cnt;
            }
        }
        
    }
    int ans=0;
    REP(i,1,m){ans+=dp[n][i];ans%=modulo;}
    cout<<ans<<endl;
    // cout<<dp[1][1];
    
}
