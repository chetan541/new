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
  
// If you need to recall how to use memREPset:
#define MEMSET_INF 127 // about 2B
#define MEMSET_HALF_INF 63 // about 1B
bool ans(vector<pair<ll,ll>> vec,ll t){
    ll count=0,mex=0;
    for(auto it:vec){
        if(it.second<=t){
            if(mex<it.second){
                mex=it.second;
            }
        }
        else{
            count+=it.first;
        }
    }
    ll ans=max(mex,count);
    if(ans<=t){
        return true;
    }
    else{
        return false;
    }

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi v;
        vector<pair<ll,ll>> vec;
        REP(i,0,n-1){
            int a;cin>>a;
            v.push_back(a);
        }
        REP(i,0,n-1){
            int b;cin>>b;
            vec.push_back(make_pair(b,v[i]));
        }
        ll count=0,mex=0,prev=0;
        sort(vec.begin(),vec.end());
        // for(auto it:vec){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
       int l=0,r=1e9;
       while(r-l>1){
        int m=(r+l)/2;
        if(ans(vec,m)==true){
            r=m;
        }
        else{
            l=m+1;
        }
       }
       if(ans(vec,l)==true){
        cout<<l<<endl;
       }
       else{
        cout<<r<<endl;
       }
        // cout<<max(mex,count)<<endl;
        
    }
}