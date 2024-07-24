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
int is_prime[1000001];
vector<int> primes;
vi SieveOfEratosthenes(int n) {
   vi v;
   bool prime[n + 1];
   memset(prime, true, sizeof(prime));

   for (int p = 2; p * p <= n; p++) {
       if (prime[p] == true) {
           for (int i = p * p; i <= n; i += p)
               prime[i] = false;
       }
   }
    for (int p = 2; p <= n; p++) {
       if (prime[p])
           v.push_back(p);
    }
   return v;
}

int main(){
 ios::sync_with_stdio(false), cin.tie(0);
   
        ll n;cin>>n;
        vll v1,v2;
        vll pref1(n+1,0),pref2(n+1,0);
        REP(i,0,n-1){
            ll a;cin>>a;
            v1.push_back(a);
        }
        REP(i,0,n-1){
            ll a;cin>>a;
            v2.push_back(a);
        }

        REP(i,0,n-1){
            pref1[i+1]+=v1[i]*v2[i]+pref1[i];
        }
        ll dp[n+1][n+1]={0};
        ll ans=pref1[n];
        REP(i,1,n){
            REP(j,1,n+1-i){
                if(i==1)dp[j][j]=v1[j-1]*v2[j-1];
                else if(i==2)dp[j][j+1]=v1[j-1]*v2[j]+v1[j]*v2[j-1];
                else{
                    dp[j][j+i-1]=v1[j-1]*v2[j+i-2]+v1[j+i-2]*v2[j-1]+dp[j+1][j+i-2];
                }
            }
        }
        REP(i,1,n){
            REP(j,i,n){
                ll tmp=pref1[i-1]+dp[i][j]+pref1[n]-pref1[j];
                ans=max(ans,tmp);
            }
            cout<<endl;
        }
        cout<<ans;
        // cout<<pref1[3];
        
    }
