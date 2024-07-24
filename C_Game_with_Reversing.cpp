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
        string s,s1;
        cin>>s>>s1;
        int count=0,count1=0;
        REP(i,0,n-1){
            if(s[i]!=s1[i]){
                count++;
            }
        }
        string s2;
        // s.reserve();
        // cout<<s<<endl;
        REP(i,0,n-1){
            if(s[n-1-i]!=s1[i]){
                count1++;
            }
        }
        int ans1,ans2;
        if(count==0){
            ans1=0;
        }
        else{
            if(count%2==0){
                ans1=2*count;
            }
            else{
                ans1=2*count-1;}
        }
        if(count1==0){
            ans2=2;
        }
        else{
            if(count1%2==0){
                ans2=2*count1-1;
            }
            else{
        ans2=2*count1;}
        }
        int ans=min(ans1,ans2);
        if(ans<0){
            ans=0;
        }
        // ans=ans+ans-1;
        cout<<ans<<endl;

    }
}