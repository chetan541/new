#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<int, int> msi;
  
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
        int n;
        cin>>n;
        int count=0;
        msi m;
        msi m1;
        vi v,v1;
        REP(i,0,n-1){
            int a;
            cin>>a;
            v.push_back(a);
        }
        REP(j,0,n-1){
            int b;
            cin>>b;
            v1.push_back(b);
            m[b]=j+1;
        }
        int exp=m[v[0]];
        REP(k,1,n-1){
            if(m[v[k]]<exp){
                count++;
                m1[v[k]]++;
            }
            else{
                exp=m[v[k]];
                
            // cout<<exp<<endl;
        }
        }
        
        int l=0;
        if(count!=0){
            int count1=0;
            int x=count;
            // cout<<x<<endl;
        while(count1<x && l<n ){
           
            
            if(m1[v1[l]]==1){
                count1++;
            }
            else{
                count++;
            }
           
            //  cout<<m1[v1[l]]<<" "<<count1<<endl;
             l++;
        }
        }
        cout<<count<<endl;
    
}
}