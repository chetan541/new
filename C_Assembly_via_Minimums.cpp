#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<ll, ll> msi;
  
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
        ll n;
        cin>>n;
        // set<ll> s;
        msi m;
        vi v;
        REP(i,0,n*(n-1)/2-1){
            ll a;
            cin>>a;
            m[a]++;
            // cout<<m[a]<<endl;
            if(m[a]==1){
                v.push_back(a);
            }
            // s.insert(a);

        }
        sort(v.begin(),v.end());
        
        // v[0]=-2;
        // for(auto it: v){
        // cout<<m[it]<<endl;}
        ll i=0;
        ll j=0;
        while(i<n-1){
            cout<<v[j]<<" "<<m[v[j]]<<endl;
            if(m[v[j]]>n-i-1){
                m[v[j]]=m[v[j]]-n+i+1;
                cout<<v[i]<<" ";
                
                
                

            }
            else{
                // cout<<v[j]<<" ";
                
                j++;
                // if(j>v.size()-1){
                //     j--;
                // }


            }i++;
        }
        cout<<v[v.size()-1]<<endl;

    }
    int main(){
    int t;
    cin>>t;
    while(t--){
        void solve();
        


    }
}