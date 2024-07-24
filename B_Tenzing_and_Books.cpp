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
        vi v1,v2,v3;
        ll x;
        cin>>x;
        // ll count=log2(x);
        ll ans=0;
        ll flag=0;
        for(int i = 0; i < n; i++)
        {
            /* code */
            ll a;
            cin>>a;
            if(((~x)&a)==0 && flag==0){
                ans=a|ans;
            }
            else {
                flag=-1;
            }
            v1.push_back(a);

        }
        flag=0;
        for(int i = 0; i < n; i++)
        {
            /* code */
            ll a;
            cin>>a;
            if(((~x)&a)==0 && flag==0){
                ans=a|ans;
            }
            else {
                flag=-1;
            }
            v2.push_back(a);

        }
        flag=0;
        for(int i = 0; i < n; i++)
        {
            /* code */
            ll a;
            cin>>a;
            if(((~x)&a)==0 && flag==0){
                ans=a|ans;
            }
            else {
               flag=-1;
            }
            v3.push_back(a);
                
            }
            if(x==ans){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
            

        }
        

        
    }
