#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<ll> vi;
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

ll value(vi v,ll n,ll h){
    ll count=0;
    REP(i,0,n-1){
        if(v[i]<h){
            count=count+(h-v[i]);
            // cout<<count<<endl;
        }
    }
    return count;
}
int main(){
    int t;
    cin>>t;
    while(t--){
    ll n,x;
    cin>>n>>x;
    vi v;
    REP(i,0,n-1){
        int a;
        cin>>a;
        v.push_back(a);
    }
    ll l=1,r=1e10;
    while(r-l>1){
        ll m=(l+r)/2;
        if(value(v,n,m)<=x){
            l=m;
        }
        else{
            r=m-1;
        }
    }
    // cout<<value(v,n,613566761)<<endl;
    if(value(v,n,r)<=x){
        cout<<r<<endl;
    }
    else{
        cout<<l<<endl;
    }
    }


}