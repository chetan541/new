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
        ll n;
        cin>>n;
        ll max=0;
        vi v;
        vi ans;
        int temp=0;
        unordered_set<int> s;
        for (int i = 0; i < n; i++)
        {
            /* code */
            ll a;
            cin>>a;
            temp^=a;
            ans.push_back(temp);
            v.push_back(a);
            s.insert(temp);
        }
        
       int fin=0;
        for(int i=255;i>=0;i--){
            int flag=0;
            REP(j,0,n-1){
                int x=i^ans[j];
                if(s.find(x)!=s.end() || x==0){
                    flag=1;
                    break;
                }  
            }
            if(flag==1){fin=i;break;}
        }
        cout<<fin<<endl;  
    }
}