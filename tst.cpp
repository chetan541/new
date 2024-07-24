#include "bits/stdc++.h"
using namespace std;

#define MAXN 100001
vector<int> spf(MAXN + 1, 1);

// Calculating SPF (Smallest Prime Factor) for every number till MAXN.
// Time Complexity : O(nloglogn)
void sieve() {
    // stores smallest prime factor for every number

    spf[0] = 0;
    for (int i = 2; i <= MAXN; i++) {
        if (spf[i] == 1) { // if the number is prime, mark all its multiples who haven't gotten their spf yet
            for (int j = i; j <= MAXN; j += i) {
                if (spf[j] == 1) // if its smallest prime factor is 1 means its spf hasn't been found yet so change it to i
                    spf[j] = i;
            }
        }
    }
}

// A O(log n) function returning prime factorization by dividing by the smallest prime factor at every step
map<int, int> getFactorization(int x) {
    map<int, int> factors;
    while (x != 1) {
        factors[spf[x]]++;
        x = x / spf[x];
    }
    return factors;
}

// driver program for above function
int main(int argc, char const* argv[]) {
    // precalculating Smallest Prime Factor
    sieve();
    int x = 50;
    cout << "prime factorization for " << x << " : ";

    // calling getFactorization function
    map<int, int> p = getFactorization(x);

    for (const auto& factor : p) {
        cout << factor.first << "^" << factor.second << " ";
    }
    cout << endl;
    return 0;
}
