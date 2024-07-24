#include<stdio.h>
void merge(int arr[],int p,int m,int q){
   int n1=m-p+1;
   int n2=q-m;
    int l[n1],r[n2];
    for(int i=0;i<n1;i++){
        l[i]=arr[p+i];
    }

for(int i=0;i<n2;i++){
        r[i]=arr[m+i];
    }
    int a=0;
    int b=0;
    int k=p;
    while(a<n1 && b<n2){
        if(l[a]<r[b]){
            arr[k]=l[a];
            a++;
        }
        else{
            arr[k]=r[b];
            b++;
        }
        k++;
    }
    
        while(a<n1){
            arr[k]=l[a];
            a++;
            k++;
        }
    
        
        while(b<n2){
            arr[k]=r[a];
            a++;
            k++;
        }
    
}
void mergesort(int arr[],int l,int r){
    
    if(l<r){
        int c= l+ (r-l)/2;
        mergesort(arr,l,c);
        mergesort(arr,c+1,r);
        merge(arr,l,c,r);

    }
}
int main(){
   int arr[5]={3,2,6,5,9};
   mergesort(arr,0,4);
   for(int i=0;i<5;i++){
    printf("%d",arr[i]);
   }
   return 0;

}