#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define rep(i, s, n) for(int i = s; i < n; i++)
#define f(i, a, b) for(int i = a; i < b; i++)

typedef int itn;
typedef long long int ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long int> vll;
typedef pair<int, int> pii;
typedef pair<long long int, long long int> pll;
typedef vector<pair<ll, ll>> vpll;

#define sp '\b' 
#define nl '\n' 
#define F first 
#define S second

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // int t;
    // cin >> t;
    // while(t--) {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> v;

    for (int i = 0; i < n; i++) {
        vector<int> a;
        ll s = 0;

        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            s += x;
            a.pb(s);
        }

        v.pb(a);
    }

    int c = 0;

    for (int i = 0; i < m; i++) {
        ll s = 0;

        for (int j = 0; j < n; j++) {
            s += v[j][i];
            v[j][i] = s;

            if (s <= k) {
                c++;
            }
        }
    }

    cout << c << endl;

    // }

    return 0;
}
