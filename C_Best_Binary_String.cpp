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
        // int n;
        // cin>>n;
        string s;
        cin>>s;
        int i=0;
        char pos='0';
        // cout<<s.size()<<endl;

        while(i<s.size()){
            // cout<<" "<<s[i]<<endl;
            if(s[i]=='0' || s[i]=='1'){
            pos=s[i];
            break;}
            i++;
        }
        // cout<<pos<<endl;
        i=0;
        while(i<s.size()){
            if(s[i]=='?'){
                s[i]=pos;
            }
            if(s[i]=='0' || s[i]=='1'){
                pos=s[i];
            }
            i++;
        }
        // cout<<s.size()<<endl;
        cout<<s<<endl;
    }
}