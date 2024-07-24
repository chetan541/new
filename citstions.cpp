#include<iostream>
using namespace std;

void merge(int* array, int const left, int const mid, int const right){
    int const length1 = mid-left+1;
    int const length2 = right-mid;
    int *LeftSubArray = new int[length1], *RightSubArray = new int[length2];
    int LeftSubArrayIndex = 0;
    int RightSubArrayIndex = 0;
    for (int i = 0; i < length1; i++)
    {
        LeftSubArray[i] = array[left+i];
    }
    for (int i = 0; i < length2; i++)
    {
        RightSubArray[i] = array[mid+1+i];
    }
    int Arrayindex = left;
    
    while (LeftSubArrayIndex<length1 && RightSubArrayIndex<length2)
    {
        if(LeftSubArray[LeftSubArrayIndex]<=RightSubArray[RightSubArrayIndex]){
            array[Arrayindex] = LeftSubArray[LeftSubArrayIndex];
            LeftSubArrayIndex++;
        }
        else{
            array[Arrayindex] = RightSubArray[RightSubArrayIndex];
            RightSubArrayIndex++;
        }
        Arrayindex++;
    }
    while (LeftSubArrayIndex<length1 )
    {
            array[Arrayindex] = LeftSubArray[LeftSubArrayIndex];
            LeftSubArrayIndex++;
            Arrayindex++;
    }
    while (RightSubArrayIndex<length2)
    {
            array[Arrayindex] = RightSubArray[RightSubArrayIndex];
            RightSubArrayIndex++;
            Arrayindex++;
    }
    delete[] LeftSubArray;
    delete[] RightSubArray;
}
void display(int* a, int n){
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
}
void mergeSort(int* array, int const begin, int const end){
    if(begin>=end){
        return;
    }
    int mid = begin + (end-begin)/2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid+1, end);
    merge(array, begin, mid, end);
}
int main(){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    cout<<"Given array is \n";
    display(a,n);
    mergeSort(a, 0, n-1);
    cout<<"\n\nSorted array is \n";
    display(a,n);
    cout<<endl;
    int h=0;
    int index=0;
    for (int i = 0; i < n; i++)
    {
        if(n-i==a[i] || n-i-1 ==a[i]){
            index = i;
            h = a[i];
        }
    }
    cout<<h;

    // n-a[i]<=a[i] && 
}