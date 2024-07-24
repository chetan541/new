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
// int is_prime[1000001];
//vector<int> primes;
//vi SieveOfEratosthenes(int n) {
//    vi v;
//    bool prime[n + 1];
 //   memset(prime, true, sizeof(prime));

 //   for (int p = 2; p * p <= n; p++) {
  //      if (prime[p] == true) {
  //          for (int i = p * p; i <= n; i += p)
  //              prime[i] = false;
   //     }
   // }
    //for (int p = 2; p <= n; p++) {
     //   if (prime[p])
     //       v.push_back(p);
    //}
   // return v;
//}
ll func(ll a){
    for(int i=32;i>=0;i--){
        if((a&(1LL<<i))>0)return i;
    }
    return -1;
}
int main(){
 ios::sync_with_stdio(false), cin.tie(0);
    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll v;
        vector<pair<ll,ll>> tmp;
        REP(i,0,n-1){
            ll a;cin>>a;
            if(a!=-1)tmp.pb({a,i});
            v.push_back(a);
        }
        ll szn=tmp.size();
        // cout<<szn<<endl;
        ll flag=1;
        REP(i,0,szn-2){
            if(tmp[i+1].F<=tmp[i].F){
                ll y=func(tmp[i].F)-func(tmp[i+1].F);
                if((tmp[i].F>>y)==tmp[i+1].F){
                    ll z=tmp[i+1].S-tmp[i].S;
                    if(z>=y && (z-y)%2==0){
                        REP(j,tmp[i].S+1,tmp[i].S+y){
                            v[j]=v[j-1]/2;
                        }
                        REP(j,tmp[i].S+y+1,tmp[i+1].S){
                            if(j%2==(tmp[i+1].S)%2){
                                v[j]=tmp[i+1].F;
                            }
                            else{
                                v[j]=tmp[i+1].F*2;
                            }
                        }
                    }
                    else{
                        flag=0;break;
                    }
                }
                else{
                    flag=0;break;
                }
            }
            else{
                ll y=func(tmp[i+1].F)-func(tmp[i].F);
                ll w=tmp[i+1].F-((tmp[i].F)<<y);
                ll z=tmp[i+1].S-tmp[i].S;
                // cout<<y<<" "<<z<<" "<<w<<endl;
                if(z>=y && w<=(1LL<<y) ){
                    ll cnt=y-1;
                    REP(j,tmp[i].S+1,tmp[i].S+y){
                        if((tmp[i+1].F&(1LL<<cnt))>0)v[j]=v[j-1]*2+1;
                        else v[j]=v[j-1]*2;
                        cnt--;
                    }
                    // cout<<cnt<<endl;
                    if((z-y)%2==0){
                        REP(j,tmp[i].S+y+1,tmp[i+1].S){
                            if(j%2==(tmp[i+1].S)%2){
                                v[j]=tmp[i+1].F;
                            }
                            else{
                                v[j]=tmp[i+1].F*2;
                            }
                        }
                    }
                    else{
                    flag=0;break;
                }
                }
                else{
                    flag=0;break;
                }
            }
        }
        if(tmp.size()>0){
            for(int i=tmp[0].S-1;i>=0;i--){
                v[i]=v[i+1]*2;
            }
            REP(i,tmp[szn-1].S+1,n-1){
                v[i]=v[i-1]*2;
            }
        }
        else{
            v[0]=1;
            REP(i,1,n-1)v[i]=v[i-1]*2;
        }
        if(flag==1)REP(i,0,n-1)cout<<v[i]<<" ";
        else cout<<-1<<endl;
        cout<<endl;
        
    }
}