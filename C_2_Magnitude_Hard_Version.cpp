#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000005
#define MOD 998244353

typedef long long ll;

ll arr[MAXN], dp_max[MAXN], dp_min[MAXN], ways_dp_max[MAXN], ways_dp_min[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int queries;
    cin >> queries;
    
    while (queries--) {
        int n;
        cin >> n;
        
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }
        
        dp_max[1] = max(arr[1], abs(arr[1]));
        dp_min[1] = min(arr[1], abs(arr[1]));
        
        if (arr[1] >= 0) {
            ways_dp_max[1] = 2;
            ways_dp_min[1] = 2;
        } else {
            ways_dp_max[1] = 1;
            ways_dp_min[1] = 1;
        }

        for (int i = 2; i <= n; ++i) {
            dp_max[i] = max({
                dp_max[i - 1] + arr[i], 
                abs(dp_max[i - 1] + arr[i]), 
                dp_min[i - 1] + arr[i], 
                abs(dp_min[i - 1] + arr[i])
            });

            if (dp_max[i] == dp_max[i - 1] + arr[i])
                ways_dp_max[i] = (ways_dp_max[i] + ways_dp_max[i - 1]) % MOD;

            if (dp_max[i] == abs(dp_max[i - 1] + arr[i]))
                ways_dp_max[i] = (ways_dp_max[i] + ways_dp_max[i - 1]) % MOD;

            if (dp_max[i - 1] != dp_min[i - 1]) {
                if (dp_max[i] == dp_min[i - 1] + arr[i])
                    ways_dp_max[i] = (ways_dp_max[i] + ways_dp_min[i - 1]) % MOD;

                if (dp_max[i] == abs(dp_min[i - 1] + arr[i]))
                    ways_dp_max[i] = (ways_dp_max[i] + ways_dp_min[i - 1]) % MOD;
            }

            dp_min[i] = min({
                dp_max[i - 1] + arr[i], 
                abs(dp_max[i - 1] + arr[i]), 
                dp_min[i - 1] + arr[i], 
                abs(dp_min[i - 1] + arr[i])
            });

            if (dp_min[i] == dp_max[i - 1] + arr[i])
                ways_dp_min[i] = (ways_dp_min[i] + ways_dp_max[i - 1]) % MOD;

            if (dp_min[i] == abs(dp_max[i - 1] + arr[i]))
                ways_dp_min[i] = (ways_dp_min[i] + ways_dp_max[i - 1]) % MOD;

            if (dp_max[i - 1] != dp_min[i - 1]) {
                if (dp_min[i] == dp_min[i - 1] + arr[i])
                    ways_dp_min[i] = (ways_dp_min[i] + ways_dp_min[i - 1]) % MOD;

                if (dp_min[i] == abs(dp_min[i - 1] + arr[i]))
                    ways_dp_min[i] = (ways_dp_min[i] + ways_dp_min[i - 1]) % MOD;
            }
        }

        cout << ways_dp_max[n] << "\n";

        fill(ways_dp_max + 1, ways_dp_max + n + 1, 0);
        fill(ways_dp_min + 1, ways_dp_min + n + 1, 0);
    }
    
    return 0;
}
