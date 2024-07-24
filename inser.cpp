#include <bits/stdc++.h>
using namespace std; 
#define REP(i, a, b) \
for(int i = int(a); i <= int(b); i++)

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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

    insertionSort(arr, n);

    std::cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
