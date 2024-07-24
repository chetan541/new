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
int isSubstring(string s1, string s2)
{
    // using find method to check if s1 is
    // a substring of s2
    if (s2.find(s1) != string::npos)
        return s2.find(s1);
    return -1;
}
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string x,s;
        cin>>x>>s;
        int count=n*m;
        int flag=0;
        REP(i,0,7){
            x.append(x);
            int ans=isSubstring(s,x);
            if(ans!=)
        }
        cout<<x<<endl;
        // REP(i,0,x.size()-1){
        //     REP(j,i+1,x.size()-1){

        //     }
        // }
        int ans=isSubstring(s,x);
        cout<<ans<<endl;
        if(ans==-1){
            cout<<-1<<endl;
        }
        else{
            ans=ans+m;
            if(ans%m==0){
                cout<<ans/m<<endl;
            }
            else{
                cout<<ans/2 +1<<endl;
            }
        }
    }

}