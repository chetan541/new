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
for(int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define TRvi(c, it) \
for(vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for(vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for(msi::iterator it = (c).begin(); it != (c).end(); it++)
  
#define INF 2000000000 // 2 billion
  
// If you need to recall how to use memset:
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B
// int is_prime[1000001];
//vector<int> primes;
//vi SieveOfEratosthenes(int n) {
//    vi v;
//    bool prime[n + 1];
 //   memset(prime, true, sizeof(prime));

 //   for (int p = 2; p * p <= n; p++) {
  //      if (prime[p] == true) {
  //          for (int i = p * p; i <= n; i += p)
  //              prime[i] = false;
   //     }
   // }
    //for (int p = 2; p <= n; p++) {
     //   if (prime[p])
     //       v.push_back(p);
    //}
   // return v;
//}



#include <iostream>

int main() {
    int t;
   cin >> t;

    for (int _ = 0; _ < t; ++_) {
        int n, U, R, D, L;
       cin >> n >> U >> R >> D >> L;

        bool valid_configuration = false;

        for (int mask = 0; mask < 16; ++mask) {
            int rU = U, rR = R, rD = D, rL = L;

            if (mask & 1) {
                rU -= 1;
                rL -= 1;
            }
            if (mask & 2) {
                rL -= 1;
                rD -= 1;
            }
            if (mask & 4) {
                rD -= 1;
                rR -= 1;
            }
            if (mask & 8) {
                rR -= 1;
                rU -= 1;
            }

            if (min({rU, rR, rD, rL}) >= 0 && max({rU, rR, rD, rL}) <= n - 2) {
               cout << "YES" <<endl;
                valid_configuration = true;
                break;
            }
        }

        if (!valid_configuration) {
           cout << "NO" <<endl;
        }
    }

    return 0;
}

