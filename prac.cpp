#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

std::vector<int> factors(int n) {
    std::vector<int> result;
    int sqrt_n = sqrt(n);
    
    // Iterate from 1 to sqrt(n)
    for (int i = 1; i <= sqrt_n; ++i) {
        // If i is a factor of n
        if (n % i == 0) {
            // Add i to the result
            result.push_back(i);
            // If i is not equal to sqrt(n) and n/i is not equal to i, then add n/i to the result
            if(i!=n/i)result.push_back(n/i);
            
        }
    }
    // Sort the result vector
    cout<<result.size()<<endl;
    return result;
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    
    std::vector<int> result = factors(n);
    
    std::cout << "Factors of " << n << " are: ";
    for (int factor : result) {
        std::cout << factor << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
