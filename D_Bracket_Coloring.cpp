#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<char> vi;
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
        vi v,v1;
        int ans=0,count=0,ans1=0;
        int l=0,r=0;
        REP(i,0,n-1){
            char a;
            cin>>a;
            v.push_back(a);
            if(a=='('){
                if(count==0){
                    l=i;
                }
                count++;
                // l=i;
            }
            else if(a==')'){
                if(count==0){
                    l=i;
                }
                count--;
                // l=i;
            }

            if(count==0){
                r=i;
                if(v[l]=='('){
                    ans=1;
                    REP(j,l,r){
                        v1.push_back('1');
                    }
                }
                else{
                    ans1=1;
                    REP(j,l,r){
                        v1.push_back('2');
                    }
                }
            }
        }
        if(count!=0){
            cout<<-1<<endl;
        }
        else{
            cout<<ans+ans1<<endl;
            
            if(ans+ans1==1){
                REP(i,0,n-1){
                    cout<<1<<" ";
                }
            }
            else{
                REP(i,0,n-1){
                cout<<v1[i]<<" ";
            }
            }
        }
        cout<<endl;
    }
}