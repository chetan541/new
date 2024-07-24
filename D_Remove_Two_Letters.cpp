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
        cin>>s;
        int count=0,temp=0;
        int i=1;
        while(i<n-1){
            if(s[i-1]==s[i+1] && s[i]!=s[i-1]){
                 count++;
                while(i<n-1 && s[i-1]==s[i+1] && s[i]!=s[i-1]){
                    i++;
                }
                i++;
            }
            else if(s[i-1]==s[i+1] && s[i]==s[i-1]){
                count++;
                while(i<n-1 && s[i]==s[i+1]){
                    i++;
                }
                i++;
            }
            else{
                count++;
                i++;

            }

        }
        if(s[n-3]!=s[n-1] ){
            count++;
        }
        cout<<count<<endl;

    }
}