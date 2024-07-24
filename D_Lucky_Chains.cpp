#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000001
int spf[MAXN + 1]; // Corrected initialization of spf array

// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity: O(n log log n)
void sieve() {
    spf[1] = 1;
    for (int i = 2; i <= MAXN; i++) // Corrected loop condition
        spf[i] = i;

    // separately marking spf for every even
    // number as 2
    for (int i = 4; i <= MAXN; i += 2) // Corrected loop condition
        spf[i] = 2;

    for (int i = 3; i * i <= MAXN; i++) {
        // checking if i is prime
        if (spf[i] == i) {
            // marking SPF for all numbers divisible by i
            for (int j = i * i; j <= MAXN; j += i) // Corrected loop condition
                // marking spf[j] if it is not
                // previously marked
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

// A O(log n) function returning prime factorization
// by dividing by smallest prime factor at every step
vector<int> getFactorization(int x) {
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    sieve(); // Call the sieve function to precompute SPF values
    int t;
    cin >> t;
    while (t--) {
        int a1, a2;
        cin >> a1 >> a2;
        if (abs(a1 - a2) == 1)
            cout << -1 << endl;
        else {
            vector<int> tmp = getFactorization(abs(a1 - a2));
            int ans = INT_MAX;
            for (auto it : tmp) {
                if (a1 % it == 0)
                    ans = min(ans, 0);
                else {
                    ans = min(ans, it - (a1 % it));
                }
            }
            cout << ans << endl;
        }
    }
}
