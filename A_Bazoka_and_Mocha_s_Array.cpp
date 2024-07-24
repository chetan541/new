#include <iostream>
#include <vector>
#include <algorithm>


bool is_sorted(const std::vector<int>& arr) {
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}


bool can_be_sorted_by_rotation(const std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        std::vector<int> rotated(arr.begin() + i, arr.end());
        rotated.insert(rotated.end(), arr.begin(), arr.begin() + i);
        if (is_sorted(rotated)) {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i];
        }
        if (can_be_sorted_by_rotation(arr)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}
