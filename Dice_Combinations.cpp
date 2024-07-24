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
ll m=1e9+7;


int main(){
 ios::sync_with_stdio(false), cin.tie(0);
    
        int n;cin>>n;
        int dp[n+1];
        dp[0]=1;
        REP(i,1,n){
            ll cnt=0;
            if(i-1>=0){cnt+=dp[i-1];cnt=cnt%m;}
            
            if(i-2>=0){cnt+=dp[i-2];cnt=cnt%m;}
            
            if(i-3>=0){cnt+=dp[i-3];cnt=cnt%m;}
            
            if(i-4>=0){cnt+=dp[i-4];cnt=cnt%m;}
            if(i-5>=0){cnt+=dp[i-5];cnt=cnt%m;}
            
            if(i-6>=0){cnt+=dp[i-6];cnt=cnt%m;}
            dp[i]=cnt%m;
        }
        // REP(i,1,n)cout<<dp[i]<<endl;
        cout<<dp[n]%m<<endl;
        
    }
