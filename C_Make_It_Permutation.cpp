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
int is_prime[1000001];
vector<int> primes;
vi SieveOfEratosthenes(int n)
{
    vi v;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
    {
        if (prime[p])
            v.push_back(p);
    }
    return v;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c, d;
        cin >> n >> c >> d;
        vi v;
        set<int> s;
        REP(i, 0, n - 1)
        {
            int a;
            cin >> a;
            s.insert(a);
            v.push_back(a);
        }
        ll ans = LLONG_MAX;
        vi var;
        for(auto it:s)var.push_back(it);
        // cout << ans << endl;
        REP(i, 0, n - 1)
        {
            auto it = lower_bound(var.begin(),var.end(),v[i]);
            int tmp =it-var.begin()+1;
            // tmp++;
           
            ll tmp2 = 1LL * (n - tmp) * c + 1LL * (v[i] - tmp) * d;
            ans = min(ans, tmp2);
            //  cout<<*it<<" "<<tmp<<endl;
        }
        ans = min(ans, 1LL * n * c + 1LL*d);
        cout << ans << endl;
    }
}