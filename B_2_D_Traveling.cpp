#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;
typedef vector<pii> vii;
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
        ll n,k,a,b;
        cin>>n>>k>>a>>b;
        vii v;
        ll x1=0,y1=0,x2=0,y2=0;
        for (int i = 0; i < n; i++)
        {
            /* code */
            ll g;
            cin>>g;
            ll h;
            cin>>h;
            if(i==a-1){
                x1=g;
                y1=h;
            }
            if(i==b-1){
                x2=g;
                y2=h;
            }
            v.push_back(make_pair(g,h));
        }
        // cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
        ll min1=1e18+1,min2=1e18 +1;

        for (int i = 0; i <k; i++)
        {
            /* code */
            ll temp1=abs(v[i].first-x1)+abs(v[i].second-y1);
            ll temp2=abs(v[i].first-x2)+abs(v[i].second-y2);
            // cout<<" "<<temp1<<" "<<temp2<<endl;
            if(temp1<min1){min1=temp1;}
            if(temp2<min2){min2=temp2;}  
        }
        if(a<=k){min1=0;}
        if(b<=k){min2=0;}
        ll prim=abs(x1-x2)+abs(y1-y2);
        if(prim<min1+min2){
            cout<<prim<<endl;
        }
        else{
        cout<<min1+min2<<endl;}
        
        
        
    }
}