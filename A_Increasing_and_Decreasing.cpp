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
        ll x,y,n;
        cin>>x>>y>>n;
        ll flag =(y-x-1);
        ll count=(n-2)*(n-1)/2;
        ll copy=y;
        vi v;
        for(int i=1;i<=n-2;i++){
                copy=copy-i;
                v.push_back(copy);
            }


        // ll flag=
        if(flag<count || y-count-x<=n-2){
            cout<<-1<<endl;
        }
        else{
            cout<<x<<" ";
           
            for(int i=n-3;i>=0;i--){
                // x=x+i;
                cout<<v[i]<<" ";
            }
            cout<<y<<endl;

        }
    }
}