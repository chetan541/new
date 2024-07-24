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
        ll n,k,g;
        cin>>n>>k>>g;
        ll x=0;
        ll ans=0,c1=0,c2=0;
        if(g%2==0){
            x=g/2-1;       
        }
        else{
            x=g/2;
        }
        c1=(n-1)*x;
        c2=k*g-c1;
        if(c2<=0){
            ans=k*g;
        }else{
            if(c2%g<x+1){
                
                ans=c1+c2%g;
            }
            else{
                
                ans=c1-(g-c2%(g));
            }
        }
            
        cout<<ans<<endl;
        
    }
}