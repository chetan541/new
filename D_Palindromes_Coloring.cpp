#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<char, int> msi;
  
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
bool ans(msi m,int k,int mid){
    ll pairs=0,single=0;
    for(auto i:m){
        pairs+=i.second/2;
        single+=i.second%2;
    }
    int a1,a2=k;
    if(mid%2==0){
        a1=(pairs*2)/mid;
    }
    else{
        if(mid==1){a1=k;}
        else{a1=(pairs*2)/(mid-1);}
        a2=single+(pairs-k)*2;
        
    }
    // cout<<pairs<<" "<<single<<" "<<a1<<" "<<a2<<" "<<endl;
    if(mid%2==0){
        if(a1>=k){return true ;}
        else{return false;}
    }
    else{if(a1>=k && a2>=k){
        return true;
    }
    else{return false;}}
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;string s;cin>>s;
        msi m;
        REP(i,0,n-1){m[s[i]]++;}
        int l=1,r=n/k;
        // cout<<ans(m,k,4);
        while(r-l>1){
            int mid=(r+l)/2;
            if(ans(m,k,mid)==true){l=mid;}
            else{r=mid-1;}
            // cout<<l<<" "<<mid<<" "<<r<<endl;
        }
        if(ans(m,k,r)==true){cout<<r<<endl;}
        else{cout<<l<<endl;}
    }
    
}