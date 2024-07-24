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
        int n;
        cin>>n;
        vi v;
        REP(i,0,n-1){
            int a;
            cin>>a;
            v.push_back(a);
        }
        vi dif;
        // dif[0]=-1;
        REP(i,0,n-1){
            REP(j,i+1,n-1){
                int x=v[j]-v[i];
                if(x!=0){
                dif.push_back(abs(x));}
            }
        }
        int g;
        if(dif.size()>=2){
            g=dif[0];
        for(auto it:dif){
            g=__gcd(it,g);
        }
        }
        else if(dif.size()==1){
            g=dif[0];
        }
        else{g=-1;}
        cout<<g<<endl;

    }
}