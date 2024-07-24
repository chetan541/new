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
        int steps=n+1;
        int rem=k+1;
        int curr=0;
        ll final=0;
        REP(j,0,n-2){
            int num1=pow(10,v[j]);
            int num2=pow(10,v[j+1]);
            int curr=(num2-num1)/(num1);
            // cout<<num1<<" "<<num2<<curr<<rem<<endl;
            
            if(curr<=rem){
                final=final+ pow(10,v[j])*curr;
                // cout<<final<<endl;
                rem=rem-curr;
            }
            else{
                final+=pow(10,v[j])*rem;
                rem=0;
            }
            // cout<<final<<" "<<rem<<endl;
            
        }
        ll last=pow(10,v[n-1]);
        // cout<<last*rem<<endl;
        final=final+last*rem;
        cout<<final<<endl;;


    }
}