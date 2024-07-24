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
    int n, m;
    cin >> n >> m;
    vector<ll> weight(n + 1, 0);
    vector<ll> edge(n + 1, 0);
    // cout<<weight[1];
    REP(i, 0, m - 1)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
            weight[a]++;
        else
            weight[b]++;
        edge[a]++;
        edge[b]++;
    }
    ll cnt = 0;
    REP(i, 1, n)
    {
        if (weight[i] == edge[i])
            cnt++;
    }
    int q;
    cin >> q;
    REP(i, 0, q - 1)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            int b, c;
            cin >> b >> c;
            cnt -= (edge[c] == weight[c]);
            cnt -= (edge[b] == weight[b]);
            if (b > c)
            {
                weight[b]++;
            }
            else
            {
                weight[c]++;
            }
            edge[b]++;
            edge[c]++;
            cnt += (edge[c] == weight[c]);
            cnt += (edge[b] == weight[b]);
        }
        else if (a == 2)
        {
            int b, c;
            cin >> b >> c;
            cnt -= (edge[c] == weight[c]);
            cnt -= (edge[b] == weight[b]);
            if (b > c)
            {
                weight[b]--;
            }
            else
            {
                weight[c]--;
            }
            edge[b]--;
            edge[c]--;
            cnt += (edge[c] == weight[c]);
            cnt += (edge[b] == weight[b]);
        }
        if (a == 3)
        {
            // int cnt=0;

            cout << cnt << endl;
        }
    }
}
