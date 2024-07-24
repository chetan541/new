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
bool check(vi &v,int n,int ind){
    int ans=-1,prev=0;
    bool flag=true;
    for(int i=0;i<=n-1;i++){
            int curr=-1;
            if(v[i]>ind && v[i]<n-ind+1)curr=v[i];
            if(curr>=0 && curr<prev)flag=false;
            else if(curr>0)prev=v[i];
            
        }
        return flag;
}

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vi v;
        REP(i,0,n-1){
            int a;cin>>a;
            v.push_back(a);
        }
       int l=0,r=n/2;
       while(r-l>1){
        int m=(l+r)/2;
        if(check(v,n,m)==false)l=m+1;
        else r=m;
       }
       int ans;
       if(check(v,n,l)==true)ans=l;
       else ans=r;

        cout<<ans<<endl;
    }
}