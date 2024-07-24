#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<ll> vi;
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
        int n;
        cin>>n;
        vi v;
        set<ll> s;
        map<ll,ll> m;

        REP(i,0,n-1){
            ll a;
            cin>>a;
            v.push_back(a);
            s.insert(a);
            m[a]++;
        }
        int mex=0;
        int x=0;
        for(auto it: m){
            // cout<<" "<<it<<endl;
            
            if(it.first-x!=0){
                mex=x;
                break;
            }
            x++;
        }
        if(mex==0 && *(s.begin())==0){
            mex=s.size();
        }
        // REP(i,0,n-1){
        //     if(v[i]==mex){
        //         mex++;
        //     }    
        // }
        // cout<<mex<<endl;
        
       if(m[mex+1]>1){
        ll l=-1;
        ll r=n;
        REP(i,0,n-1){
            if(v[i]==mex+1){
                l=i;
                // cout<<l<< " ";
                break;
                
            }

        }
         for (int i = n-1; i >l ; i--){
            if(v[i]==mex+1){
                r=i;
                // cout<<r<<" ";
                break;
                
            }

        }
       
       ll flag=0;
       for(ll j=l+1;j<=r-1;j++){
        if(v[j]<mex+1){
            m[v[j]]--;
            // cout<<m[v[j]]<<endl;
            if(m[v[j]]==0){
            flag=-1;
            // cout<<flag<<endl;
            break;
        }
        }
        
       }
        if(flag==-1){
            cout<<"no"<<endl;
        }
        else{
            cout<<"yes"<<endl;
        }
       
       }
    else if(m[mex+1]==1){
        cout<<"yes"<<endl;

       }
       else{
        if(mex==n && v.size()==n){
            cout<<"no"<<endl;
        }
        else{
            cout<<"yes"<<endl;
        }
       }

        


    }
}