// #include <bits/stdc++.h>
// using namespace std;
// // Shortcuts for "common" data types in contests
// typedef long long ll;
// typedef vector<int> vi;
// typedef vector<ll> vll;
// typedef pair<int, int> pi;
// typedef vector<pi> vii;
// typedef set<int> si;
// typedef map<string, int> msi;
// #define all(x) (x).begin(), (x).end()
// #define pb push_back
// #define F first
// #define S second
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// #define multi_ordered_set tree<ll, null_type, greater_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>

// // To simplify repetitions/loops, Note: define your
// // loop style and stick with it!
// #define REP(i, a, b) \
//     for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
// #define TRvi(c, it) \
//     for (vi::iterator it = (c).begin(); it != (c).end(); it++)
// #define TRvii(c, it) \
//     for (vii::iterator it = (c).begin(); it != (c).end(); it++)
// #define TRmsi(c, it) \
//     for (msi::iterator it = (c).begin(); it != (c).end(); it++)

// #define INF 2000000000 // 2 billion

// // If you need to recall how to use memset:
// #define MEMSET_INF 127     // about 2B
// #define MEMSET_HALF_INF 63 // about 1B

// // Custom comparator for sorting v3
// bool comparator_v3(const pair<ll, ll>& a, const pair<ll, ll>& b, const vll& v2) {
//     if (a.first == b.first) {
//         return v2[a.second] < v2[b.second]; // If first elements are equal, sort by corresponding v2 value in increasing order
//     }
//     return a.first > b.first; // Sort by first element in decreasing order
// }

// // Custom comparator for sorting v4
// bool comparator_v4(const pair<ll, ll>& a, const pair<ll, ll>& b, const vll& v1) {
//     if (a.first == b.first) {
//         return v1[a.second] < v1[b.second]; // If first elements are equal, sort by corresponding v1 value in increasing order
//     }
//     return a.first > b.first; // Sort by first element in decreasing order
// }

// int main() {
//     ios::sync_with_stdio(false), cin.tie(0);
//     int t;
//     cin >> t;
//     while (t--) {
//         ll n, m;
//         cin >> n >> m;
//         vll v1(n + m + 1), v2(n + m + 1);
//         vector<pair<ll, ll>> v3, v4;

//         REP(i, 0, n + m) {
//             cin >> v1[i];
//             v3.pb({v1[i], i});
//         }
//         REP(i, 0, n + m) {
//             cin >> v2[i];
//             v4.pb({v2[i], i});
//         }

//         sort(v3.begin(), v3.end(), [&](const pair<ll, ll>& a, const pair<ll, ll>& b) {
//             return comparator_v3(a, b, v2);
//         });

//         sort(v4.begin(), v4.end(), [&](const pair<ll, ll>& a, const pair<ll, ll>& b) {
//             return comparator_v4(a, b, v1);
//         });

//         vll tmp1, tmp2;
//         vector<pair<int, int>> check(n + m + 1, {0, 0});
//         ll ans = 0;

//         REP(i, 0, n + m) {
//             if (v1[v3[i].S] >= v2[v3[i].S] && tmp1.size() < n) {
//                 tmp1.pb(v3[i].F);
//                 ans += v3[i].F;
//                 check[v3[i].S].F = 1;
//             }
//         }

//         REP(i, 0, n + m) {
//             if (v1[v4[i].S] <= v2[v4[i].S] && tmp2.size() < m && check[v4[i].S].F == 0) {
//                 tmp2.pb(v4[i].F);
//                 ans += v4[i].F;
//                 check[v4[i].S].S = 1;
//             }
//         }

//         if (tmp1.size() < n) {
//             REP(i, 0, n + m) {
//                 if (tmp1.size() < n && check[v3[i].S].S == 0 && check[v3[i].S].F == 0) {
//                     tmp1.pb(v3[i].F);
//                     ans += v3[i].F;
//                     check[v3[i].S].F = 1;
//                 }
//             }
//         } else {
//             REP(i, 0, n + m) {
//                 if (tmp2.size() < m && check[v4[i].S].F == 0 && check[v4[i].S].S == 0) {
//                     tmp2.pb(v4[i].F);
//                     ans += v4[i].F;
//                     check[v4[i].S].S = 1;
//                 }
//             }
//         }

//         int ind = 0;
//         REP(i, 0, n + m) {
//             cout<<i<<" "<<check[i].F<<" "<<check[i].S<<endl;
//             if (check[i].F == 0 && check[i].S == 0)
//                 ind = i;
//         }
//         cout<<ans<<endl;
//         REP(i, 0, n + m) {
//             if (check[i].F == 1) {
//                 cout << ans - v1[i] + v1[ind] << " ";
//             } else if (check[i].S == 1) {
//                 cout << ans - v2[i] + v2[ind] << " ";
//             } else {
//                 cout << ans << " ";
//             }
//         }
//         cout << endl;
//     }
//     return 0;
// }
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
bool comparator(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second; // If first elements are equal, sort by second element in increasing order
    }
    return a.first > b.first; // Sort by first element in decreasing order
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vll v1, v2;
        vector<pair<ll, ll>> v3, v4;
        // ll tmp1=LLONG_MAX,tmp2=LLONG_MAX;
        REP(i, 0, n + m)
        {
            ll a;
            cin >> a;
            // tmp1=min(a,tmp1);
            v1.push_back(a);
            v3.pb({a, i});
        }
        REP(i, 0, n + m)
        {
            ll a;
            cin >> a;
            // tmp2=min(a,tmp2);
            v2.push_back(a);
            v4.pb({a, i});
        }
        sort(v3.begin(), v3.end(), greater<pair<int, int>>());
        sort(v4.begin(), v4.end(), greater<pair<int, int>>());
        vll tmp1, tmp2;
        vector<pair<int, int>> check(n + m + 1, {0, 0});
        ll ans = 0;
        REP(i, 0, n + m)
        {
            if (v1[v3[i].S] >= v2[v3[i].S] && tmp1.size() < n)
            {
                tmp1.pb(v3[i].F);
                ans += v3[i].F;
                check[v3[i].S].F = 1;
            }
        }
        REP(i, 0, n + m)
        {
            if (v1[v4[i].S] <= v2[v4[i].S] && tmp2.size() < m && check[v4[i].S].F == 0)
            {
                tmp2.pb(v4[i].F);
                ans += v4[i].F;
                check[v4[i].S].S = 1;
            }
        }
        if (tmp1.size() < n)
        {
            REP(i, 0, n + m)
            {
                if (tmp1.size() < n && check[v3[i].S].S == 0 && check[v3[i].S].F==0)
                {
                    tmp1.pb(v3[i].F);
                    ans += v3[i].F;
                    check[v3[i].S].F = 1;
                }
            }
        }
        else{
            REP(i, 0, n + m)
            {
                if (tmp2.size() < m && check[v4[i].S].F == 0 && check[v4[i].S].S == 0)
                {
                    tmp2.pb(v4[i].F);
                    ans += v4[i].F;
                    check[v4[i].S].S = 1;
                }
            }
        }
        int ind = 0;
        // cout<<ans<<endl;
        REP(i, 0, n + m)
        {
            cout<<i<<" "<<check[i].F<<" "<<check[i].S<<endl;
            if (check[i].F == 0 && check[i].S == 0)
                ind = i;
        }
        // cout<<ind<<endl;
        REP(i,0,n+m){
            ll x=0;
            if(check[i].F==1){
                cout<<ans-v1[i]+v1[ind]<<" ";
            }
            else if(check[i].S==1){
                cout<<ans-v2[i]+v2[ind]<<" ";
            }
            else cout<<ans<<" ";
        }
        cout<<endl;
    }
}