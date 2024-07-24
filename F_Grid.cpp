#include <bits/stdc++.h>
using namespace std;
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef vector<pi> vii;
typedef set<int> si;
typedef map<int, int> msi;
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
    int cnt=0;
    int t = 21;
    char arr[21][21];
    REP(i,0,20){
        REP(j,0,20){
            cin>>arr[i][j];
        }
    }
    msi vis;
    int one=0,z=0;
    REP(i,0,20){
        int tmp=0;
        REP(j,0,20){
            if(arr[j][i]=='1'){tmp++; one++;}
            else z++;
        }
        // cout<<tmp<<" ";
        vis[tmp]++;
    }
    cout<<abs(one-z)+1<<endl;
    // REP(i,0,20){
    //     int tmp=0;
    //     REP(j,0,20){
    //         if(arr[i][j]=='1')tmp++;
    //     }
    //     // cout<<tmp<<" ";
    //     vis[tmp]++;
    // }
    // int mx=-1;
    // int ans=0;
    // for(auto it:vis){
    //     if(it.S>=mx)
    //     {
    //         mx=it.second; ans=it.first;
    //     }
    // }
    // cout<<ans<<endl;

    // cout<<mx<<endl;
}
