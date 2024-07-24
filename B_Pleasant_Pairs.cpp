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
        ll n;
        cin>>n;
        msi m;
        vi v;
        REP(i,0,n-1){
            int a;
            cin>>a;
            v.push_back(a);
            m[a]=i+1;
        }
        int count=0;
        for(int i=2*n-1;i>=3;i--){
            REP(j,1,sqrt(i)){
                if(i%j==0){
                    if(m[j]!=0 && m[i/j]!=0 && j!=i/j){
                    if(m[j]+m[i/j]==i){
                        count++;
                    }
                    }
                }
            }
        }
        cout<<count<<endl;

}
}