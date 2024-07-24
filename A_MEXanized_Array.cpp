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
        ll n,k,x;
        cin>>n>>k>>x;
        if(k-x>=2){
            cout<<-1<<endl;
        }
        else if(k-n>=1){
            cout<<-1<<endl;
        }
        else{
            // ll a=x*(x+1)/2;
            // ll num=x+1;
            // ll ans=0;
            // if(k<=x){
            //     a=a-k;
            //     num=x;
            //     if(k!=x){
            //     ans=(n-num)*x+a;}
            //     else{
            //         ans=(n-num)*(x-1)+a;
            //     }
            // }
            // else{
            //     num=x+1;
            //     ans=a+(n-num)*x;
            // }
            // cout<<ans<<endl;
            ll a=(k-1)*(k)/2;
            ll num=n-k;
            ll sum=0;
            if(x==k){
                sum=(x-1)*num;
            }
            else{
             sum=x*num;}
            cout<<a+sum<<endl;



        }
    }
}