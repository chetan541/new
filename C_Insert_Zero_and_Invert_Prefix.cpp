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
        string s;
        vi v;
        REP(i,0,n-1){
            ll a;
            cin>>a;
            s.push_back(a);
        }
        // cout<<s[n-1]<<endl;
        if(s[n-1]==1){
            cout<<"NO"<<endl;

        }
        else{
           ll i=n-1;
            while(i>=0){
                // cout<<"   "<<i<<endl;
                ll count=0;
                if(s[i]==0){
                    i--;
                    // cout<<"si"<<s[i]<<endl;
                    while(s[i]==1 && i>=0){
                        
                        v.push_back(0);
                        count++;
                        i--;
                    }
                    v.push_back(count);
                 


                }
            }
            cout<<"YES"<<endl;
            for(auto it:v){
                cout<<it<<" ";
            }
            cout<<endl;
        }
    }
}