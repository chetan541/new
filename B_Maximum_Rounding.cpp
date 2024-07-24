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
void solve(){
    int t;
    cin>>t;
    while(t--){
        
     
          string s;cin>>s;
    int pos=-1;int n=s.size();
    for(int i=0;i<n;i++){
        int flag=0;
        if(s[i]<'4') continue;
        if(s[i]>='5') {
            pos=i;break;
        }
        if(s[i]=='4'){
            int nxt;
            for(int j=i+1;j<n;j++){
                if(s[j]<'4') break;
                if(s[j]>='5'){
                    pos=i;
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1) break;


        }
 
// cout<<pos<<endl;
if(pos==-1){
    cout<<s<<endl;continue;
}
int f=0;
for(int i=0;i<n;i++){
    if(pos==0&&f==0) {cout<<1;++f=1;}
    if((pos-i)==1){
        int x=(int)s[i]-48;++x;
        cout<<x;continue;
    }
    if(i<pos){
        int x=(int)s[i]-48;
        cout<<x;
    }
    if(i>=pos) cout<<0;
}
cout<<endl;
      }


}
    
    int main(){
        solve();
    }
