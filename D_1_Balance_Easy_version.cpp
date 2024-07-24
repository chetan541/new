#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<pair<char,ll> > si;
typedef map<ll, ll> msi;
  
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
    msi m;
    si s;

    while(t--){
        int n;
        char ch;
        ll i;
        cin>>ch>>i;
        s.insert({i,ch});
        if(ch=='+'){
            
            m[i]=10;     
        }
        if(ch=='?'){
            // if(m[i]==10){
            // ll l=2;
            // ll r=*(s.rbegin())/i;

            // // cout<<" "<<*(s.rbegin())<<endl;
            // // cout<<m[i]<<endl;
            

            // while(m[i*j]==10 && i*j<=*(s.rbegin())){
            //     j++;
            //     // cout<<" "<<i*j<<endl;
            // }
            // cout<<i*j<<endl;}
            // else{
            //     cout<<i<<endl;
            // }
            


        }

    }
    
}