#include <bits/stdc++.h>
using namespace std;  
// Shortcuts for "common" data types in contests
typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<ll,ll> msi;
  
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
long long int logWithBase(long long int x, long long int base) {
 
 return static_cast<long long int>(log2(x) / log2(base));   // Calculate the logarithm using the formula and round to the nearest integer
}
long long int power(ll x,ll y){
    ll ans=1;
    REP(i,1,y){
        ans=ans*x;
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vi v;
        msi m;
        REP(i,0,100){
            m[i]=1;
        }
        REP(i,0,n-1){
            ll a;
            cin>>a;
            v.push_back(a);
        }
        vi ans(n,0);
        if(k==0){
            if(ans==v){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else{
        ll sum=0,flag=0;
        REP(i,0,n-1){
            ll curr=v[i];
            ll temp=0;
            if(curr!=0){
            while(curr>0){
             temp=logWithBase(curr,k);
             if(curr<power(k,temp)){
                temp--;
             }
            //  cout<<curr<<" "<<temp<<endl;
            //  cout<<pow()
             if(m[temp]==0){
                flag=1;
                break;
             }
             else{
                curr-=power(k,temp);
                m[temp]=0;
             }
            //  cout<<power(k,temp)<<endl;
            //  cout<<curr<<" "<<temp<<endl;
             }
             }
             if(flag==1){break;}
        }
        if(flag==1){cout<<"NO"<<endl;}
        else{
            cout<<"YES"<<endl;
        }
        }
    }
}
