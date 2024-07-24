#include <bits/stdc++.h>
using namespace std;

string stringGen(const string& s, int index) {
    if (index < 0) {
        return "";
    }

    return stringGen(s, index - 1) + to_string(s[index] - 'A' + 1);
}

void solve() {
    // Your code for solving a single test case goes here
    string s;
    cin >> s;
    string g = stringGen(s, s.size() - 1);
    cout << g << endl;
}

// Main function
int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
