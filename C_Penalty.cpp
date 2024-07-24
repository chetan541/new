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
        string s;
        cin >> s;
        int ans1 = 0, ans2 = 0, s1 = 0, s2 = 0, flag = 10;
        REP(i, 0, 4)
        {
            int tmp = 2 * i;
            if (s[tmp] == '1')
                s1++;
            if (s[tmp] == '?')
                s1++;
            if (s1 - s2 > (5 - i))
            {
                flag = 2 * i + 1;
                break;
            }
            if (s[tmp + 1] == '1')
                s2++;
            if (s1 - s2 > (5 - i - 1))
            {
                flag = 2 * i + 2;
                break;
            }
            //    cout<<s1<<" "<<s2<<endl;
        }
        ans1 = flag;
        ans2 = 0, flag = 10, s1 = 0, s2 = 0;
        REP(i, 0, 4)
        {
            int tmp = 2 * i;
            if (s[tmp] == '1')
                s1++;
            if (s2 - s1 > (5 - i-1 ))
            {
                flag = 2 * i + 1;
                break;
            }
            if (s[tmp + 1] == '1')
                s2++;
            if (s[tmp + 1] == '?')
                s2++;
            if (s2 - s1 > (5 - i-1))
            {
                flag = 2 * i + 2;
                break;
            }

            //    cout<<s1<<" "<<s2<<endl;
        }
        ans2 = flag;
        cout << min(ans1, ans2) << endl;
    }
}