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
// int is_prime[1000001];
// vector<int> primes;
// vi SieveOfEratosthenes(int n) {
//    vi v;
//    bool prime[n + 1];
//   memset(prime, true, sizeof(prime));

//   for (int p = 2; p * p <= n; p++) {
//      if (prime[p] == true) {
//          for (int i = p * p; i <= n; i += p)
//              prime[i] = false;
//     }
// }
// for (int p = 2; p <= n; p++) {
//   if (prime[p])
//       v.push_back(p);
//}
// return v;
//}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m, k, d;
        cin >> n >> m >> k >> d;
        ll arr[n][m];

        REP(i, 0, n - 1)
        {
            REP(j, 0, m - 1)
            {
                cin >> arr[i][j];
            }
        }
        
        ll dp[m + 1];
        ll ans[n];
        REP(i, 0, n - 1)
        {
            memset(dp, 0, sizeof(dp));
            multiset<ll> s;
            ll prev = 1;
            dp[0] = 0;
            dp[1] = 1;
            s.insert(prev);
            REP(j,2,m){
                dp[j]=1LL*arr[i][j-1]+*s.begin()+1LL;
                s.insert(dp[j]);
                if(s.size()>d+1){
                    auto it = s.find(dp[prev]);
                    s.erase(it);
                    prev++;
                }
            }
           ans[i]=dp[m];
        //    cout<<dp[m]<<endl;
        }
        ll tmp=0,out=LLONG_MAX;
        REP(i,0,k-1)tmp+=ans[i];
        out=min(out,tmp);
        ll r=k,l=0;
        while(r<n){
            tmp+=ans[r];
            tmp-=ans[l];
            l++;r++;
            out=min(tmp,out);
        }
        cout<<out<<endl;

    }
}