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
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n;
        cin>>k;
        vi v;
        REP(i,0,n-1){
           ll a;
           cin>>a;
           v.push_back(a);
        }
        for(int i=30;i>=0;i--){
            ll count=0;
            REP(y,0,n-1){
            if((v[y]&(1<<i))>0){
                count++;
            }
        }
            if(k>=n-count){
                REP(j,0,n-1){
            v[j]=v[j]|(1<<i);
        }
        k=k-n+count;
        // cout<<k<<endl;
            }
        }
        ll ans=2147483647;
        REP(i,0,n-1){
            ans=(ans&v[i]);
            
        }
        cout<<ans<<endl;



    }
}