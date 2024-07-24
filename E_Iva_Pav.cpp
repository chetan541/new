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
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        msi m;
        msi m1;
        int b;
        cin>>b;

        m[1]=b;
        m1[b]=1;
        int count=a;
        REP(i,2,n){
            int a;
            cin>>a;
            count=count&a;
            m[i]=count;
            if(m[count]<i){
            m[count]=i;}

        }
        int q;
        cin>>q;
        REP(j,0,q-1){
            int l,k;
            cin>>l>>k;
            int ans=m[r]^(~m[l-1]);
        }
    }
}