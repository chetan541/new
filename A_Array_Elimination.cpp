#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef set<ll> si;
typedef map<string, ll> msi;
  
// To simplify repetitions/loops, Note: define your
// loop style and stick with it!
#define REP(i, a, b) \
for(ll i = ll(a); i <= ll(b); i++) // a to b, and variable i is local!
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
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vi v;
        REP(i,0,n-1){
            ll a;cin>>a;
            v.push_back(a);
        }
        vi ans;
        // ll temp=n+1;
        REP(i,0,30){
            ll cnt=0;
            REP(j,0,n-1){
                if((v[j]^(1<<i))<v[j])cnt++;
            }
            // cout<<cnt<<endl;
            ans.push_back(cnt);
            // if(cnt!=0)temp=min(temp,cnt);
        }
        // if(temp==n+1)temp=0;
         REP(i,1,n){
        ll flag=1;
        for(auto it:ans){
            if(it%i!=0)flag=0;
        }
        // if(t==1209)
        if(flag==1)cout<<i<<" ";
    }
    cout<<endl;
    }
   
}