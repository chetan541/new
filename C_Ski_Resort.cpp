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
        int n,k,q;
        cin>>n>>k>>q;
        vi v;
        REP(i,0,n-1){
            int a;
            cin>>a;
            if(a>q){
                a=0;
            }
            else{
                a=1;
            }
            v.push_back(a);
        }
        ll count=0,sum=0;
        int i=0;
        while(i<n){
            if(v[i]==1){
                while(v[i]==1 && i<n){
                    count++;
                    i++;
                    if(count>=k){
                    sum=sum+count-k+1;}
                }
                // i++;
            }
            else{
                count=0;
                i++;
            }
        }
        // if(count>k){
        //             sum=count-k+1;
        //         }
        cout<<sum<<endl;
    }
}