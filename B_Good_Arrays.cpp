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
        int n;
        cin>>n;
        ll c1=0,c2=0;
        vi v;
        REP(i,0,n-1){
            int a;
            cin>>a;
            if(a==1){
                c1++;
            }
            else{
                c2=c2+(a-1);
                // cout<<a-1<<endl;
            }
        }
        // cout<<c1<<" "<<c2<<endl;
        if(n==1){
            cout<<"NO"<<endl;;
        }
        else{
        if((c1)>(c2)){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
        }


    }
}