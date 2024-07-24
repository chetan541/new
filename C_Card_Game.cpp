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
        const int maxn=2e5+50;
long long a[maxn],rep[maxn];
        int n;cin>>n;
     for(int i=0;i<=n+2;i++){
         rep[i]=0;
     }
     for(int i=0;i<n;i++) cin>>a[i];
     for(int i=n-1;i>=0;i--){
        rep[i]=rep[i+1]+(a[i]>=0?a[i]:0);
     }
     long long ans=0;
     for(int i=0;i<n;i++){
        ans=max(ans,rep[i+1]+(i%2==0 ? a[i]:0));
     }
     cout<<ans<<endl;

    }
}