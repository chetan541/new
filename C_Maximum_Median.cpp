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
bool ans(vi v,int k,int t){
    ll count=0;
    REP(i,v.size()/2,v.size()-1){
        if(t>v[i]){
            count=count+t-v[i];
        }
    }
    // cout<<count<<endl;
    if(count<=k){
        return true;
    }
    else{
        return false;
    }

}
int main(){
   
        int n,k;
        cin>>n>>k;
        vi v;
        REP(i,0,n-1){
            int a;cin>>a;
            v.push_back(a);
        }
        sort(v.begin(),v.end());
        ll l=v[n/2],r=2*1e9 +1;
        while(r-l>1){
            ll m=(r+l)/2;
            // cout<<l<<" "<<m<<endl;
            if(ans(v,k,m)==true){
                l=m;
            }
            else{
                r=m-1;
            }
        }
        // cout<<ans(v,k,6)<<endl;
        if(ans(v,k,r)==true){cout<<r<<endl;}
        else{cout<<l<<endl;}
    }
