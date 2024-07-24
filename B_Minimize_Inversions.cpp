#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int mergeAndCountInversions(vi &arr, int left, int mid, int right) {
    int inversions = 0;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vi leftArr(arr.begin() + left, arr.begin() + left + n1);
    vi rightArr(arr.begin() + mid + 1, arr.begin() + mid + 1 + n2);

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
            inversions += (n1 - i);
        }
    }

    while (i < n1) {
        arr[k++] = leftArr[i++];
    }

    while (j < n2) {
        arr[k++] = rightArr[j++];
    }

    return inversions;
}

int mergeSortAndCountInversions(vi &arr, int left, int right) {
    int inversions = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;

        inversions += mergeSortAndCountInversions(arr, left, mid);
        inversions += mergeSortAndCountInversions(arr, mid + 1, right);

        inversions += mergeAndCountInversions(arr, left, mid, right);
    }

    return inversions;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n;
        vi v1, v2;
        REP(i, 0, n - 1) {
            int a;
            cin >> a;
            v1.push_back(a);
        }
        REP(i, 0, n - 1) {
            int a;
            cin >> a;
            v2.push_back(a);
        }
        vi ans1(n, 0);
        vi ans2(n, 0);
        REP(i, 0, n - 1) {
            ans1[v1[i] - 1] = v2[i];
        }

        // Print sequence from 1 to n
        REP(i, 1, n) cout << i << " ";
        cout << endl;

        // Print ans1 vector
        for (auto it : ans1) cout << it << " ";
        cout << endl;
    }

    return 0;
}
