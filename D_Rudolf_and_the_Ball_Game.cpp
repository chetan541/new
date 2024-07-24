#include <iostream>
#include <set>

using namespace std;

#define REP(i, a, b) for(int i = int(a); i <= int(b); i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m, x;
        cin >> n >> m >> x;

        set<int> positions;
        positions.insert(x);

        REP(i, 0, m - 1) {
            int r;
            cin >> r;

            char c;
            cin >> c;

            set<int> new_positions;  // Temporary set

            for (auto it : positions) {
                int tmp = r % n;
                int ans;

                if (c == '0') {
                    int pos = n - it;
                    ans = (tmp > pos) ? (tmp - pos) : (it + tmp);
                } else if (c == '1') {
                    int pos = it;
                    ans = (tmp >= pos) ? (n - (tmp - pos)) : (it - tmp);
                } else if (c == '?') {
                    int pos = n - it;
                    ans = (tmp > pos) ? (tmp - pos) : (it + tmp);

                    int tmp1 = r % n;
                    int pos1 = it;
                    int ans1 = (tmp1 >= pos1) ? (n - (tmp1 - pos1)) : (it - tmp1);
                    
                    new_positions.insert(ans);
                    new_positions.insert(ans1);
                }

                new_positions.insert(ans);
                // cout << ans << endl;
            }

            positions.swap(new_positions);  // Swap with the temporary set
        }

        cout << positions.size() << endl;
        for(auto it:positions)cout<<it<<" ";
        cout<<endl;
    }

    return 0;
}
