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

int main(){
 ios::sync_with_stdio(false), cin.tie(0);
    int t;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        vll v1,v2;
        REP(i,0,n+m){
            ll a;cin>>a;
            v1.push_back(a);
        }

         REP(i,0,n+m){
            ll a;cin>>a;
            v2.push_back(a);
        }
        
        vector<pair<ll,ll>> tmp1,tmp2,tmp3;
        REP(i,0,n+m){
            if(v1[i]>v2[i])tmp1.pb({v1[i],i});
            else tmp2.pb({v2[i],i});
        }
        // sort(tmp1.begin(),tmp1.end(),greater<pair<int,int>>());
        // sort(tmp2.begin(),tmp2.end(),greater<pair<int,int>>());
        ll ans=0,y=0;
        ll ind1=-1,ind2=-1,ind=INT_MAX;
        vector<pair<ll,ll>> check(n+m+1,{0,0});
        if(tmp1.size()>=n+1){
            // ind=1;
            REP(i,0,n-1){
                ans+=tmp1[i].F;
                check[tmp1[i].S].F=1;
            }
            int szn=tmp1.size();
            REP(i,n,szn-1){
                y+=v2[tmp1[i].S];
                ind=min(ind,tmp1[i].S);
            }
            for(auto it:tmp2){
                y+=it.F;
                // check[it.S].S=1;
            }
        }
        else{
            // ind=2;
            REP(i,0,m-1){
                ans+=tmp2[i].F;
                check[tmp2[i].S].S=1;
            }
            int szn=tmp2.size();
            // cout<<szn<<endl;
            REP(i,m,szn-1){
                ind=min(ind,tmp2[i].S);
                y+=v1[tmp2[i].S];
            }
            for(auto it:tmp1){
                y+=it.F;
                // check[it.S].F=1;
            }
        }
        // cout<<ans<<" "<<y<<" "<<ind<<endl;
         REP(i, 0, n + m)
        {
            // cout<<i<<" "<<check[i].F<<" "<<check[i].S<<endl;
            if(check[i].F==1){
                ll z=ans-v1[i]+v1[ind]+y-v2[ind];
                cout<<z<<" ";
            }
            else if(check[i].S==1){
                ll z=ans-v2[i]+v2[ind]+y-v1[ind];
                cout<<z<<" ";
            }
            else{
                ll z;
                if(tmp1.size()>=n+1)z=ans+y-v2[i];
                else z=ans+y-v1[i];
                cout<<z<<" ";
            }
        }
        cout<<endl;
    }
}