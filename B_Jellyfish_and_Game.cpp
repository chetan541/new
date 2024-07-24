#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
  
// To simplify repetitions/loops, Note: define your
// loop style and stick with it!
#define REP(i, a, b) \
for(int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define TRvi(c, it) \
for(vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for(vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for(msi::iterator it = (c).begin(); it != (c).end(); it++)
  
#define INF 2000000000 // 2 billion
  
// If you need to recall how to use memset:
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        ll min1=INT_MAX,max1=0,sum=0,max2=0,min2=INT_MAX;
        REP(i,0,n-1){
            int a;
            cin>>a;
            sum=sum+a;
            if(a<min1){
                min1=a;
            }
            if(a>max1){
                max1=a;
            }
        }
        REP(i,0,m-1){
            int b;
            cin>>b;
            if(b>max2){
                max2=b;
            }
            if(b<min2){
                min2=b;
            }
        }
        ll umax=max(max1,max2);
        ll umin=min(min1,min2);
        if(umax==max2){
            if(k==1){
                sum=sum+umax-min1;
            }
            else if(k%2==0){  
                sum=sum-min1+umin;
            }
            else{   
               sum=sum-min1+umax;
            }
        }
        else if(umax==max1){
            if(k==1){
                if(min1<max2){
                sum=sum+max2-min1;}
                else{
                    sum=sum;
                }
            }
            else if(k%2==0){
                if(min1<max2){
                sum=sum-max1-min1+umin+max2;}
                else{
                    sum=sum-max1+min2;
                }
            }
            else{
            //     if(min1==umin){
            //    sum=sum+min2-min1;} 
            //    else{
            //     sum=sum;
            //    }
            if(min1<max2){
            sum=sum-min1+max2;}
            else{
                sum=sum;
            }
            }
        }
        cout<<sum<<endl;


    }
}