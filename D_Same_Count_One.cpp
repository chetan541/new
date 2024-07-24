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
        int n, m;
        cin >> n >> m;
        int arr[n][m];
        int cnt = 0;
        vi tmp(n, 0);
        REP(i, 0, n - 1)
        {
            REP(j, 0, m - 1)
            {
                cin >> arr[i][j];
                if (arr[i][j] == 1)
                {
                    cnt++;
                    tmp[i]++;
                }
            }
        }
        int avg = cnt / n;
        if (cnt % n == 0)
        {
            int ans = 0;
            REP(i, 0, n - 1)
            {
                ans += abs(avg - tmp[i]);
            }
            cout << ans / 2 << endl;
            REP(i, 0, m - 1)
            {
                stack<int> s1, s2;
                REP(j, 0, n - 1)
                {
                    // cout<<tmp[j]<<" "<<arr[i][j]<<" "<<s1.size()<<" "<<s2.size()<<endl;
                    if (tmp[j]>avg && arr[j][i]==1){
                        
                        if(s2.empty())s1.push(j+1);
                        else{
                            cout<<s2.top()<<" "<<j+1<<" "<<i+1<<endl;
                            tmp[s2.top()-1]++;
                            s2.pop();
                            tmp[j]--;
                        }
                    }
                    else if(tmp[j]<avg  && arr[j][i]==0){
                        
                        if(s1.empty())s2.push(j+1);
                        else{
                            cout<<s1.top()<<" "<<j+1<<" "<<i+1<<endl;
                            tmp[s1.top()-1]--;
                            s1.pop();
                            tmp[j]++;
                        }
                    }
                }
            }
        }
        else
        {
            cout<<-1<<endl;
        }
    }
}