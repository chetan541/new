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
        ll m,k,a1,ak;
        cin>>m>>k>>a1>>ak;
        ll tmp=m%k;
        ll ans=0;
        if(a1>=tmp){
            m-=tmp;
            a1-=tmp;
            ll x=a1/k;
            m-=x*k;
            ans=m/k-ak;
            ans=max(0ll,ans);
        }
        else{
            ans+=tmp-a1;
            m-=tmp;
            ans+=max(0LL,m/k-ak);
            ans=max(0ll,ans);
        }
        cout<<ans<<endl;
        
    }
}