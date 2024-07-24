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
        int t2=INT_MAX,t3=INT_MAX,t4=INT_MAX,t5=INT_MAX;
        int n,k;cin>>n>>k;
        int t=INT_MAX;
        vi v;
    REP(i,0,n-1){
    int a;cin>>a;
    v.push_back(a);}
    int exp=0;
    REP(i,0,n-1){
        if(v[i]%2==0){
            exp++;
        }
        int x2=k-v[i]%k;
        if(x2==k){x2=0;}
        if(x2<t){
            t=x2;
        }
    }
    // if(t==k){cout<<0<<endl;}
    // else{
        if(k==4){
            int r=0;
            if(exp>=2){r=0;}
            else if(exp==1){r=1;}
            else{r=2;}
            if(r<t){t=r;}
        }
        
    cout<<t<<endl;

    }
}