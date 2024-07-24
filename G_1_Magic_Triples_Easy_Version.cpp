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

// To simplify repetitions/loops
#define REP(i, a, b) for(int i = int(a); i <= int(b); i++)
#define TRvi(c, it) for(vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) for(vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) for(msi::iterator it = (c).begin(); it != (c).end(); it++)

#define INF 2000000000 // 2 billion

// Efficient computation of factorial using modular arithmetic to prevent overflow
const ll MOD = 1e9 + 7;

ll factorialMod(ll n) {
    ll result = 1;
    for (ll i = 2; i <= n; ++i) {
        result = (result * i) % MOD;
    }
    return result;
}

vector<int> factors(int n) {
    vector<int> factors;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i != n / i) {
                factors.push_back(n / i);
            }
        }
    }
    if (n > 1) {
        factors.push_back(n);
    }
    return factors;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> m;
        REP(i, 0, n - 1) {
            int a;
            cin >> a;
            m[a]++;
        }
        ll ans = 0;
        for (auto vt : m) {
            if (vt.S > 2) ans += 1LL*vt.S*(vt.S-1)*(vt.S-2);
            vector<int> tmp = factors(vt.F);
            for (auto it : tmp) {
                int sqrt_it = sqrt(it);
                if (sqrt_it * sqrt_it == it) {
                    if (m.count(vt.F / sqrt_it) > 0 && m.count(vt.F / it) > 0) {
                        ans += 1LL*vt.S * (m[vt.F / it]) * (m[vt.F / sqrt_it]);
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
