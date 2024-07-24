#include <bits/stdc++.h>
using namespace std;
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef vector<pi> vii;
typedef set<int> si;
typedef map<string, int> msi;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first
#define S second
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
#define multi_ordered_set tree<ll, null_type, greater_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>

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
        int n, x, y;
        cin >> n >> x >> y;
        vi v;
        vi ans;
        REP(i, 0, x - 1)
        {
            int a;
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        int start = 0;
        int curr = 1;
        // if(v[curr]-v[start]==1)curr++;
        int cnt = 0;
        if (v[curr] - v[start] == 2)
            cnt++;
        // if( v[curr]-v[start]==n-2)cnt++;
        int tmp = curr + 1;
        // cout<<tmp<<endl;
        REP(i, tmp, x - 1)
        {
            if (v[i] - v[curr] == 2)
                cnt++;
            cnt++;
            curr = i;
        }
        if (v[curr] - v[start] == n - 2)
            cnt++;
        REP(i, 0, x - 2)
        {
            // cout<<v[i]<<endl;
            ans.push_back(v[i + 1] - v[i] -1);
        }
        ans.push_back(n - v[x - 1] + v[0] -1 );
        sort(ans.begin(), ans.end());
        int m = ans.size();
        map<ll, ll> mp;
        REP(i,0,m-1){
            // cout<<ans[i]<<endl;
            if(ans[i]%2!=0 && y>0 && ans[i]>1){
                mp[i]=1;
                if(y>=ans[i]/2){
                    cnt+=2*(ans[i]/2)+1;
                    y-=ans[i]/2;
                }
                else{
                    cnt+=2*y;
                    y=0;
                }
            }
            if(y==0)break;
        }
        REP(i,0,m-1){
            if(ans[i]%2==0 && y>0 && mp[i]==0 && ans[i]>1){
                if(y>=ans[i]/2){
                    cnt+=ans[i];
                    y-=ans[i]/2;
                }
                else{
                    cnt+=2*y;
                    y=0;
                }
            }
            if(y==0)break;
        }
        cout<<cnt<<endl;
    }
}