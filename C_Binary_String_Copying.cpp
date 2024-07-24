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
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        int left[n] = {-1};
        int right[n] = {n};
        REP(i, 0, n - 1)
        {
            if (i == 0 && s[i] == '0')
                left[i] = i;
            else if (i == 0)
                left[i] = -1;
            else
            {
                s[i] == '0' ? left[i] = i : left[i] = left[i - 1];
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1 && s[i] == '1')
                right[i] = i;
            else if (i == n - 1)
                right[i] = n;
            else
            {
                s[i] == '1' ? right[i] = i : right[i] = right[i + 1];
            }
        }
        set<pair<int, int>> ans;
        REP(i, 0, m - 1)
        {
            int l, r;
            cin >> l >> r;
            // cout<<right[l-1]<<" "<<left[r-1]<<endl;
            if (right[l - 1] <= left[r - 1])
                ans.insert(make_pair(right[l - 1], left[r - 1]));
            else
                ans.insert({-1, -1});
        }
        cout << ans.size() << endl;
    }
}
