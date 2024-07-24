#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(ll a, ll b, ll n) {
    ll t1 = 1LL;
    for (int i = 0; i < b; ++i) {
        t1 *= a;
        // cout<<t1<<" ";
    }
    t1 -= 1LL;
    if(t1>1e18) return true;
    //  if(t1<0)return true;
    if (t1 / (a - 1LL) >= n) return true;
    else return false;
}

bool check1(ll a, ll b, ll n) {
    ll t1 = 1LL;
    for (int i = 0; i < b; ++i) {
        t1 *= a;
    }
    t1 -= 1LL;
    // if(t1<0)return true;
    // if(t1>1e18) return true;
    if (t1 / (a - 1LL) == n) return true;
    else return false;
}

int main() {
    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        int flag = 0;
        for (int i = 3; i <= 60; ++i) {
            ll l = 2, r = 1e3;
            while (r - l > 1) {
                ll m = l+(r - l) / 2;
                if (check(m, i, n) == true) r = m;
                else l = m + 1;
            }
            if (check1(l, i, n) == true) {
                flag = 1;
                break;
            }
            if (check1(r, i, n) == true) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
