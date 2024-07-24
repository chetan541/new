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
        ll n;
        cin>>n;
        REP(i,0,n-1){
            
            ll a;
            cin>>a;
            if(a==0){
                cout<<0<<" ";
            }
            else{
            //     ll pos1=0;
            //     ll steps1=0;
            // for(int i=0;i<=15;i++){
            //     if((a&(1<<i))>0){
            //         pos1=i;
            //         break;
            //     }
            // }
            // steps1=15-pos1+steps1;
            // ll steps=0;
            // if(a%2!=0){
            //         a=a+1;
            //         steps=steps+1;     
            // }
            // // while(((a&15)==14) || ((a&127)==124) || ((a&4095)==4088)){
            // if((a&15)==14){
            //     a=a+2;
            //     steps=steps+2;
            // }
            // if((a&127)==124){
            //     a=a+4;
            //     steps=steps+4;
            // }
            // if((a&4095)==4088){
            //     steps=steps+8;
            //     a=a+8;
            // }
            // // }
            ll ans=16;
            REP(j,0,15){
                ll x=a;
                x=x+j;
                 ll steps=0;
                steps=steps+j;
            ll pos=0;
            for(int i=0;i<=15;i++){
                if((x&(1<<i))>0){
                    pos=i;
                    break;
                }
            }
            steps=15-pos+steps;
            if(steps<ans){
                ans=steps;
            }
            
            }
            cout<<ans<<" ";


        }

    }
}
