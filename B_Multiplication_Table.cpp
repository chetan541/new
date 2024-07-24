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
    int n;
    cin>>n;
    vector<vector<ll>> v;
    REP(i,0,n-1){
        vi vec;
        REP(j,0,n-1){
            int a;
            cin>>a;
            vec.push_back(a);
        }
        v.push_back(vec);
    }
    vi ans;
    REP(i,0,n-3){
        ll x=(v[i][i+1]*v[i][i+2])/(v[i+1][i+2]);
        ans.push_back(sqrt(x));

    }
    ll y=(v[n-2][n-1]*v[n-2][n-3])/(v[n-3][n-1]);
    ans.push_back(sqrt(y));
    y=(v[n-1][n-2]*v[n-1][n-3])/(v[n-3][n-2]);
    ans.push_back(sqrt(y));
    for(auto it:ans){
        cout<<it<<" ";
    }

}