#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void color(int t, vector<pair<int, vector<int>>> &test_cases) {
    for (int i = 0; i < t; ++i) {
        int n = test_cases[i].first;
        vector<int> a = test_cases[i].second;
        unordered_set<int> unique_elements(a.begin(), a.end());

        if (unique_elements.size() <= 1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            string color_pattern(n, 'R');
            color_pattern[1] = 'B';
            cout << color_pattern << endl;
        }
    }
}

int main() {
    int t;
    cin >> t;
    vector<pair<int, vector<int>>> test_cases(t);

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
        }
        test_cases[i] = make_pair(n, a);
    }

    color(t, test_cases);
    return 0;
}
