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
        ll l,r;
        cin>>l>>r;
        if(l==r){
            if(l%2==0){
                if(l==2 ){
                    cout<<-1<<endl;
                }
                else{
                cout<<l/2<<" "<<l/2<<endl;}
            }
            else{
                int flag=-1;
                int val;
                REP(i,2,sqrt(l)){
                    if(l%i==0){
                        val=i;
                        flag=0;
                    }
                }
                if(flag==-1){
                    cout<<-1<<endl;
                }
                else{
                    cout<<val<<" "<<val*((l/val)-1)<<endl;
                }
            }
        }
        else{
            if(l<3){
                l=3;
            }
            while(l<=r && l%2!=0 ){
                
                l++;
            }
            if(r<4){
                cout<<-1<<endl;
            }
            else if(l%2!=0){
                cout<<-1<<endl;
            }
            else{
            cout<<l/2<<" "<<l/2<<endl;}
        }
    }
}