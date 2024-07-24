#include <bits/stdc++.h>
using namespace std; 
void merge(std::vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<int> leftArray(n1);
    std::vector<int> rightArray(n2);

    for (int i = 0; i < n1; ++i)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArray[j] = arr[middle + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            ++i;
        } else {
            arr[k] = rightArray[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = leftArray[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = rightArray[j];
        ++j;
        ++k;
    }
}

void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

bool canCoverAllHouses(vector<int>& houses,vector<int>& heaters, int radius) {
        int numHouses = houses.size(), numHeaters = heaters.size();
        int i = 0, j = 0; 
        while (i < numHouses) {
            if (j >= numHeaters) return false;  
            int minHeaterRange = heaters[j] - radius;
            int maxHeaterRange = heaters[j] + radius;
            if (houses[i] < minHeaterRange)
                return false;  
            if (houses[i] > maxHeaterRange)
                ++j;
            else
                ++i;  
        }
        return true;
    }

int main(){
   
        int n,m;cin>>n>>m;
        vector<int> houses,heaters;
       for(int i=0;i<n;i++){
            int a;cin>>a;
            houses.push_back(a);
        }
        for(int i=0;i<m;i++){
            int b;cin>>b;
            heaters.push_back(b);
        }
        mergeSort(houses,0,n-1);
        mergeSort(heaters,0,m-1);
        int left = 0, right = 1e9;
        while (left < right) {
            int mid = (left + right) / 2;
            if (canCoverAllHouses(houses, heaters, mid))
                right = mid;  
            else
                left = mid + 1; 
        }
        cout<<left<<endl;; 
    }
