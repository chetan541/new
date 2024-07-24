#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<ll> vi;
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
        ll ans;
        cin>>ans;
        vi v;
        v.push_back(ans);
        for (int i = 0; i < n-1; i++)
        {
            /* code */
            ll a;
            cin>>a;
            v.push_back(a);
            ans=ans&a;
            // cout<<ans<<endl;
        }
        if(ans!=0){
            cout<<1<<endl;
        }
        else{
            ans=v[0];
            ll i=0;
            ll count=0;
            if(ans==0){
                count++;
                if(i+1==n){
                    ans=v[i];
                }
                else{
                    ans=v[i+1];
                }
                
            }
            i++;
            while(i<n){
               ans=ans&v[i];
               if(ans==0){
                
                
                count++;
                if(i+1==n){
                    break;
                }
                else{
                    ans=v[i+1];
                }
               }
               i++;
            }
            if(count==0){
                cout<<1<<endl;
            }
            else{
            cout<<count<<endl;}

        }
        


    }
}