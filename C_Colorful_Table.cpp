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
        int n,k;
        cin>>n>>k;
        vi v;
        REP(i,0,n-1){
            int a;
            cin>>a;
            v.push_back(a);
        }
        REP(i,1,k){
            int count=0;
            int l=0,r=0;
            while(l<n){
                if(v[l]==i)count++;
                if(v[l]>=i){
                    break;
                }
                l++;
            }
            // cout<<l<<" ";
            r=l;
            int x=l;
            while(x<n){
                if(v[x]==i)count++;
                if(v[x]>=i){
                   r=x;
                }
                x++;
            }
            // cout<<l<<" "<<r<<endl;;
            if(count==0){
                cout<<0<<" ";
            }
            else{
                cout<<2*(r-l+1)<<" ";
            }
        }
        cout<<endl;
    }
}