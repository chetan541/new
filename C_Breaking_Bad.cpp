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
    int m;
    cin >> m;
    string s;
    cin >> s;

    int o;
    cin >> o;
    int l = 0, d = 0;
    REP(i, 0, o - 1)
    {
        //  cout<<"current pos "<<l<<d<<endl;
        int a, b;
        cin >> a;
        if (a != 2)
            cin >> b;
        if (d == 0 && a == 2)
        {
            d = 1;
            l--;
            if (l == -1)
                l = m-1;
        }
        else if (d == 1 && a == 2)
        {
            d = 0;
            l++;
            if (l == m)
                l = 0;
        }
        if (d == 0 && a == 1)
        {
            int pos = l + m - b;
            if (pos > m - 1)
            {
                pos -= m;
            }
            l=pos;
        }
        else if (d == 1 && a == 1)
        {
            int pos = l - (m - b);
            if (pos < 0)
            {
                pos = pos + m;
            }
            l=pos;
        }
        if (d == 0 && a == 3)
        {
            int pos = l + b - 1;
            if (pos > m - 1)
            {
                pos = pos - m;
                // cout<<pos<<endl;
                
            }
            // cout<<pos<<endl;
            cout << s[pos] << endl;
        }
        else if (d == 1 && a == 3)
        {
            int pos = l - b + 1;
            if (pos < 0)
            {
                pos = pos + m;
                
                
            }
            // cout<<pos<<endl;
            cout << s[pos] << endl;
        }
       
    }
}
