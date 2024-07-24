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
        int q;
        cin>>q;
        string s;
        int count=0,last,first,flag=0,ind;
        REP(i,0,q-1){
            count++;
            int a;
            cin>>a;
            if(count==1){  
                s.append("1");
                last=a;
                first=a;
                ind=a;
            }
            else{
                
                if(a>=last && flag==0){
                    s.append("1");
                    last=a;
                    ind=a;
                }
                else if( a<=first && flag==0 && a<last ){
                    s.append("1");
                    last=a;
                    flag=1;
                }
                else if(flag==1 && a>=last && a<=first){
                    last=a;
                    s.append("1");
                }
                else{
                    s.append("0");
                }
            }
        }
        cout<<s<<endl;

    }
}