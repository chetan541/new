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
int main(){
    
   
        ll n,m;
        ll max=998244353;
        vi v1,v2,v3,v4;
        msi m1,m2;
        cin>>n;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            v1.push_back(a);
            
        }
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            m1[v1[i]]=a;
            v2.push_back(a);
        }

        cin>>m;
        for(int i=0;i<m;i++){
            ll a;
            cin>>a;
            v3.push_back(a);
        }
        for(int i=0;i<m;i++){
            ll a;
            cin>>a;
            m2[v3[i]]=a;
            v4.push_back(a);
        }
        ll flag=0;
        for(int i=0;i<n;i++){
            if(m1[v1[i]]<m2[v1[i]]){
                flag=1;
                break;
            }
        }
        ll x=0;
        for(int i=0;i<m;i++){
            if(m1[v3[i]]-m2[v3[i]]>0){
                x++;
            }
            // cout<<m1[v3[i]]<<m2[v3[i]]<<endl;
            if(m1[v3[i]]<m2[v3[i]]){
                flag=1;
                break;
            }
        }

        ll count=1;

        for(int i=0;i<n-m+x;i++){
            count=count*2%max;


        }
        if(v1==v3 && v2==v4){
            cout<<1<<endl;
        }
        else if(flag==1){
            cout<<0<<endl;
        }
        else{
        cout<<count<<endl;}


    
}