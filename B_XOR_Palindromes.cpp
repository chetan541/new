#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<int, int> msi;
  
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
        msi m;
        int odd=0,even=0;
        int dis=0,same=0;
        if((n)%2==0){
            even=1;
        }
        else{
            odd=1;
        }
        
        for(int i=0;i<n/2;i++){
            if(s[i]==s[n-1-i]){
                same++;
            }
            else{
                dis++;
            }
        }
        // cout<<odd<<endl;
        // cout<<same<<" "<<dis<<endl;
        REP(j,0,same){
            int val=0;
            if(odd==1){
                val=2*j+dis+1;
                m[val]++;
            }
            val=2*j+dis;
            // cout<<val<<endl;
            m[val]++;}
            string ans;
            REP(i,0,n){
                // cout<<i<<" "<<m[i]<<endl;
                if(m[i]==1){
                    cout<<'1';
                }
                else{
                   cout<<'0';
                }
            }
            cout<<endl;


        }
    }
