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
bool ans(vi v,int mid){
    int count=0,flag=1;
    if(mid!=0){
    while(flag!=0 && v.size()!=0){
        count++;
        int test=mid-count+1;
        if(test<=0){break;}
        flag=0;
        sort(v.begin(),v.end());
        for(int i=v.size()-1;i>=0;i--){
            
            if(v[i]<=test){
                flag=1;
                // cout<<test<<" "<<v[i]<<" "<<v.size()<<endl;
                v.erase(v.begin()+i);
                break;
            }
        }
        if(flag==0){count--;}
        if(v.size()==0){count=mid;break;}
        else{v[0]+=test;}
    }
    }
    if(count>=mid|| mid==0){return true;}
    else{return false;}

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi v;
        REP(i,0,n-1){
            int a;cin>>a;
            v.push_back(a);
        }
        int l=0,r=n;
        // cout<<ans(v,3)<<endl;
        while(r-l>1){
            int mid=(r+l)/2;
            if(ans(v,mid)==true){l=mid;}
            else{r=mid-1;}
            // cout<<l<<" "<<mid<<" "<<r<<endl;
        }
        if(ans(v,r)==true){cout<<r<<endl;}
        else{cout<<l<<endl;}

    }
}