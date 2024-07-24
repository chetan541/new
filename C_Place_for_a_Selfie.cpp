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
void solve(vector<int>& v,ll a,ll b,ll c){
    if(c<=0){
        cout<<"NO"<<endl;
    }
    else{
        ll temp=sqrt(4*a*c);
        ll x=4*a*c;
        if(temp*temp!=x){
            temp++;
        }
        ll l=b-temp,r=b+temp;
        // cout<<l<<" "<<r<<endl;
        auto it=upper_bound(v.begin(),v.end(),l);
        if(it==v.end()){cout<<"NO"<<endl;}
        else{
        if(*it<r){
            cout<<"YES"<<endl;
            cout<<*it<<endl;}
        else{cout<<"NO"<<endl;}
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vi v;
        REP(i,0,n-1){
            int z;cin>>z;
            v.push_back(z);
        }
        sort(v.begin(),v.end());
        REP(i,0,m-1){
            ll a,b,c;cin>>a>>b>>c;
            solve(v,a,b,c);
        }
        cout<<endl;
    }
}