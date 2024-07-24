#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pi;
typedef vector<pi> vii;
typedef set<int> si;
typedef map<string, int> msi;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define F first 
#define S second
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;
#define multi_ordered_set tree<ll, null_type,greater_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
  
  
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
 ios::sync_with_stdio(false), cin.tie(0);
   
        int n;cin>>n;
        vi v1,v2;
        vector<pair<int,int>> v;
        REP(i,0,n-1){
            int a;cin>>a;
            v1.push_back(a);
        }
        REP(i,0,n-1){
            int a;cin>>a;
            v2.push_back(a);
            v.pb({v1[i],v2[i]});
        }
        sort(v.begin(),v.end());
        int ans=1;
        int l=INT_MIN,r=INT_MAX;
        REP(i,0,n-1){
            if(v[i].F>=l && v[i].F<=r){
                l=max(l,v[i].F);
                r=min(r,v[i].S);
            }
            else{
                ans++;
                l=v[i].F,r=v[i].S;
            }
        }
        cout<<ans<<endl;
        
    }
