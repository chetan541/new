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
bool ans(vi v,int mid){
    int rem=0,n=v.size();
    
    REP(i,0,n-1){
        if(v[i]>mid){
            rem+=v[i]-mid;
        }
        else{
            int space=(mid-v[i])/2;
            rem=rem-space;
            if(rem<0){rem=0;}
        }
        
        // int temp=(v[v.size()-1-i]-v[i])/3;
        // m=max(v[v.size()-1-i]-temp,v[i]+2*temp);
    }
    if(rem==0){return true;}
    else{return false;}
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vi v(n,0);
        REP(i,0,m-1){
            int a;
            cin>>a;
            v[a-1]++;
        }
        sort(v.begin(),v.end(),greater<int>());
        // for(auto it:v){cout<<it<<" ";}
        // cout<<ans(v,3)<<endl;
        int l=1,r=v[0];
        while(r-l>1){
            int mid=(r+l)/2;
            if(ans(v,mid)==true){r=mid;}
            else{l=mid+1;}
        }
        if(ans(v,l)==true){cout<<l<<endl;}
        else{cout<<r<<endl;}
    }
}