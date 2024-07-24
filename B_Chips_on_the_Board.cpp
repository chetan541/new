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
    // int t;
    // cin>>t;
    // while(t--){
    //     int n;
    //     cin>>n;
    //     ll sum1=0,min1=INT_MAX;
    //     ll sum2=0,min2=INT_MAX;
    //     REP(i,0,n-1){
    //         ll a;
    //         cin>>a;
    //         sum1=sum1+a;
    //         if(a<min1){
    //             min1=a;
    //         }
    //     }
        
    //     REP(i,0,n-1){
    //         ll a;
    //         cin>>a;
    //         sum2=sum2+a;
    //         if(a<min2){
    //             min2=a;
    //         }
    //     }
        // cout<<sum1<<" "<<sum2<<endl;
        // cout<<min1<<" "<<min2<<endl;
    //     ll ans=min(min1*n+sum2,min2*n+sum1);
    //     cout<<ans<<endl;
    // }
    ll ans=(3*4*8*81*5)*20*19*18*17*16*15*14*13*12*11*10*9*8*7*6*120)%998244353;
    cout<<ans;
}