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
        ll l,r;cin>>l>>r;
        ll x1=sqrt(l);
        ll x2=sqrt(r);
        ll x=min((x1+1)*(x1+1),r);
        ll y=max(x2*x2,l);
        if(x==r || y==l){
            ll count=0;
            ll temp=l/x1;
        if(temp*x1!=l){temp=x1*(temp+1);}
        else{temp=l;}
        for(ll i=temp;i<r;i=i+x1){
           
            count++;}
            // cout<<x<<" "<<y<<endl;
            if(r%x2==0)count++;
            cout<<count<<endl;
        }
        else{
        ll count=(x2-x1-1)*3;
        if(count<=0){count=0;}
        
        ll temp=l/x1;
        if(temp*x1!=l){temp=x1*(temp+1);}
        else{temp=l;}
        for(ll i=temp;i<(x1+1)*(x1+1);i=i+x1){
            
            count++;}
        
       
        count+=(r-x2*x2)/x2;count++;
        
        cout<<count<<endl;}


    }
}