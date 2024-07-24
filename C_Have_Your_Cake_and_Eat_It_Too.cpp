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
void solve(vll &v1,vll &v2,vll &v3,ll tmp,ll &flag, ll tot,ll arr[3]){
    ll l=-1,sum=0,n=v1.size(),r=-1;
    REP(i,0,n-1){
        sum+=v1[i];
        if(sum>=tmp){l=i;break;}
    }
    if(sum<tmp)return;
    sum=0;
    REP(i,l+1,n-1){
        sum+=v2[i];
        if(sum>=tmp){r=i;break;}
    }

    if(sum<tmp)return;
    sum=0;
    REP(i,r+1,n-1){
        sum+=v3[i];
    }
    if(sum<tmp)return;
    flag=1;
    // cout<<l<<" "<<r<<endl;
    if(arr[0]==1)cout<<1<<" "<<l+1<<" ";
    if(arr[1]==1)cout<<l+2<<" "<<r+1<<" ";
    if(arr[2]==1)cout<<r+2<<" "<<n<<" ";

    if(arr[0]==2)cout<<1<<" "<<l+1<<" ";
    if(arr[1]==2)cout<<l+2<<" "<<r+1<<" ";
    if(arr[2]==2)cout<<r+2<<" "<<n<<" ";

    if(arr[0]==3)cout<<1<<" "<<l+1<<" ";
    if(arr[1]==3)cout<<l+2<<" "<<r+1<<" ";
    if(arr[2]==3)cout<<r+2<<" "<<n<<" ";

    cout<<endl;


    
}

int main(){
 ios::sync_with_stdio(false), cin.tie(0);
    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll v1,v2,v3;
        ll tot=0;
        REP(i,0,n-1){
            ll a;cin>>a;
            tot+=a;
            v1.push_back(a);
        }
        REP(i,0,n-1){
            ll a;cin>>a;
            v2.push_back(a);
        }
        REP(i,0,n-1){
            ll a;cin>>a;
            v3.push_back(a);
        }

        ll tmp=ceil(tot/(3.0));
        ll flag=0;
        ll arr1[3] = {1, 2, 3}; solve(v1, v2, v3, tmp, flag, tot, arr1);
        if(!flag) {ll arr2[3] = {1, 3, 2}; solve(v1, v3, v2, tmp, flag, tot, arr2);}
        if(!flag) {ll arr3[3] = {2, 1, 3}; solve(v2, v1, v3, tmp, flag, tot, arr3);}
        if(!flag) {ll arr4[3] = {2, 3, 1}; solve(v2, v3, v1, tmp, flag, tot, arr4);}
        if(!flag) {ll arr5[3] = {3, 1, 2}; solve(v3, v1, v2, tmp, flag, tot, arr5);}
        if(!flag) {ll arr6[3] = {3, 2, 1}; solve(v3, v2, v1, tmp, flag, tot, arr6);}

        if(!flag)cout<<-1<<endl;
    }
}