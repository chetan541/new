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
        int n;cin>>n;
        vi v;
        vector<pair<int,int>> vec;
        REP(i,0,2*n-1){
            int a;cin>>a;v.push_back(a);
        }
        sort(v.begin(),v.end());
        ll sum=0,temp=0;
        REP(i,0,n-2){
            sum+=v[i+1]-v[i];vec.push_back(make_pair(v[i],v[2*n-1-i]));
        }
        vec.push_back(make_pair(v[n-1],v[n]));
        REP(i,n,2*n-2){
            sum+=v[i+1]-v[i];
        }
        cout<<sum<<endl;
        for(auto it:vec){
            cout<<it.first<<" "<<it.second<<endl;
        }

    }
}