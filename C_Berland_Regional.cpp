#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<int, vi> msi;
  
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
void solve(){
    int n;
    cin>>n;
    map<int,vector<ll>>mp;
    vector<int>u(n),s(n);
    for(int i=0;i<n;i++){
        cin>>u[i];
    }
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<n;i++){
        mp[u[i]-1].push_back(s[i]);
    }
    vector<vector<ll>>az;
    for(auto i : mp){
        az.push_back(i.second);
        sort(az.back().begin(),az.back().end());
    }
    vector<ll>ans(n,0);
    vector<vector<ll>>z;
    for(auto i : az){
        vector<ll>other;
        for(int j=0;j<(int)i.size();j++){
            if(j==0) other.push_back(i[j]);
            else other.push_back(other.back() + i[j]);
        }
        z.push_back(other);
    }
    // for(auto i : z){
    //     for(int j : i){
    //         cout<<j<<" ";
    //     }
    //     cout<<"\n";
    // }
    for(auto i : z){
        for(int j=1;j<=(int)i.size();j++){
            int left=(int)i.size() % j;
            ll del=0;
            if(left>0) del=i[left-1];
            ans[j-1]+=(i.back() - del);
            // cout<<"in "<<(i.back() - del)<<"\n";
        }
    }
    for(auto i : ans) cout<<i<<" ";
    cout<<"\n";
}  
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();


    }
}