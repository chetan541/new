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
bool ans(vi v,ll t){
    int count=1;
    sort(v.begin(),v.end());
    int mid=v[0]+t;
    for(int i=0;i<v.size();i++){
        int test=abs(v[i]-mid);
        // cout<<count<<" "<<mid<<" "<<test<<endl;
        if(test>t){
            count++;
            mid=v[i]+t;
        }
    }
    if(count<=3){return true;}
    else{return false;}
    // return count;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi v;
        REP(i,0,n-1){
            int a;cin>>a;
            v.push_back(a);
        }
        // cout<<ans(v,15)<<endl;
        ll l=0,r=1e9;
        while(r-l>1){
            ll m=(l+r)/2;
            // cout<<l<<" "<<ans(v,m)<<endl;
            if(ans(v,m)==true){
                r=m;
            }
            else{
                l=m+1;
            }

        }
        if(ans(v,l)==true){cout<<l<<endl;}
        else{cout<<r<<endl;}
    }
}