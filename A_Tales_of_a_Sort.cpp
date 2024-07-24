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













int main()
{
    int t;
    cin>>t;
    while(t--){
     
      int n;cin>>n;
     int var[n];
     int c[n];
     REP(i,0,n-1) {cin>>var[i];c[i]=var[i];}
     sort(c,c+n);
     int i;
     for( i=n-1;i>=0;i--){
        if(var[i]!=c[i]) break;
     }
     if(i==-1) cout<<0<<endl;
    else  cout<<c[i]<<endl;}



return 0;
}



 
 
