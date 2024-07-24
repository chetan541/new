#include <bits/stdc++.h>
using namespace std; 
#define REP(i, a, b) \
for(int i = int(a); i <= int(b); i++)

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int n;cin>>n;
    int arr[n];
    REP(i,0,n-1){
        int a;cin>>a;
        arr[i]=a;
    }

    std::cout << "Unsorted array: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    std::cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
