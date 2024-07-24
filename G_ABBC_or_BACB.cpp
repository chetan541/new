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
void ans(){
    string s;cin>>s;
    int cnt=0;int n=s.size();
    int l=0,r=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='A') ++cnt;

    }
    int mn=INT_MAX;
    int c=0;
    int gp=0;
    for(int i=0;i<n;i++){
        if(s[i]=='A') ++c;
        else {
            mn=min(mn,c);++gp;
            c=0;
        }
        if(i==(n-1)&&s[i]=='A'){
             ++gp;
             mn=min(mn,c);
        }
    }

     for(int i=0;i<s.size();i++){
        if(s[i]=='A') ++l;
        else break;

    }
     for(int i=n-1;i>=0;i--){
        if(s[i]=='A') ++r;
        else break;

    }
    if(cnt==0||cnt==n) cout<<0<<endl;
    else {
        if(gp==(n-cnt)) cout<<cnt<<endl;
        else  cout<<cnt-mn<<endl;
    }
}

int main()
{
     int t;

     cin >> t;
     
     while (t--)
     {
          ans();
      }

return 0;
}
 