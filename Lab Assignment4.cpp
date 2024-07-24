#include<bits/stdc++.h>
using namespace std;

// 1- a; Counting the Paths to reach from the 0,0 to n,m;
int CountPaths(int n, int m)
{
    if (n==1 || m==1)
        return 1;
    int part1=CountPaths(n,m-1);
    int part2=CountPaths(n-1,m);
    return (part1+part2);
}
// 1- b;// It is nothing but calling the MergeSort function once again.
void Merge(int a[], int s, int e, int mid)
{
    int n1=mid-s+1;
    int n2=e-mid;
    int p[n1];
    int q[n2];
    for (int i=0; i<n1; i++)
    {
        p[i]=a[s+i];
    }
    for (int i=0; i<n2; i++)
    {
        q[i]=a[mid+1+i];
    }
    int i=0;
    int j=0;
    int k=s;
    while (i<n1 && j<n2)
    {
        if (p[i]<q[j])
        {
            a[k]=p[i];
            i++;
            k++;
        }
        else 
        {
            a[k]=q[j];
            j++;
            k++;
        }
    }
    while (i<n1)
    {
        a[k]=p[i];
        k++;
        i++;
    }
    while (j<n2)
    {
        a[k]=q[j];
        j++;
        k++;
    }
    return ;
}
void Merge_Sort(int a[], int s, int e)
{
    if (s>=e)
        return ;
    int mid=(s+e)/2;
    Merge_Sort(a,s,mid);
    Merge_Sort(a,s,mid);
    Merge_Sort(a,mid+1,e);
    Merge(a,s,e,mid);
    return ;
}
// 1-c
void Check(int n, int &count)
{
    if (n==0)
        return;
    for (int i=0; i<n; i++)
    {
        Check(n-1,count);
    }
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            ++count;
        }
    }
    return;
}
int main()
{
    int n=5;
    int m=4;
    cout<<CountPaths(n,m)<<endl;
    int n1=6;
    int a[n1]={5,4,3,2,1,6};
    Merge_Sort(a,0,5);
    for (int i=0; i<n1; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int count=0;
    Check(n,count);
    cout<<count<<endl;
}