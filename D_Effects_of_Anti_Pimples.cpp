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
ll modulo=998244353;
ll power(ll base, ll exponent) {
    ll result = 1;
    base %= modulo; // Take modulo of base to avoid overflow
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulo;
        }
        base = (base * base) % modulo;
        exponent /= 2;
    }
    return result%modulo;
}
int main(){
    
        int n;cin>>n;
        vi v;
        REP(i,0,n-1){
            int a;cin>>a;
            v.push_back(a);
        }
        msi m;
        REP(i,0,n-1){
            ll target=INT_MIN;
            ll start=i+1,cnt=1;;
            while(start<=n){
                target=max(target,1LL*v[start-1]);
                // cout<<i<<" "<<start<<" "<<target<<endl;
                cnt++;start=(i+1)*cnt;
            }
            // cout<<target<<endl;
            m[target]++;
        }
        ll ans=0,tmp=0;
        // for(auto it:m){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        for(auto it:m){
            ans = (ans + ((((power(2, it.second) % modulo - 1 + modulo) % modulo) * power(2, tmp) % modulo) * it.first) % modulo) % modulo;

            tmp+=it.second;
        }
        cout<<ans%modulo<<endl;
        
    }
